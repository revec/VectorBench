import re
import os
import sys

class RunResults:

    def __init__(self,name):
        self.name = name
        self.kernel = ""
        self.variant = ""
        self.costSavings = 0
        self.CSECostSavings = 0
        self.optimalCost = 0
        self.time = 0

    def printResults(self):
        print "{ " + self.name + "," + self.variant + "," + str(self.costSavings) + "," + str(self.time) +  " }"

class FileResults:
    def __init__(self,name):
        self.name = name
        self.runs = []
    def get(self,name):
        for run in self.runs:
            if run.name == name:
                return run
        return None
    def add(self,run):
        self.runs += [run]
    def printResults(self):
        print "file : " + self.name
        for run in self.runs:
            run.printResults()


class BenchmarkResults:
    def __init__(self,name):
        self.name = name
        self.files = []
        self.runs = []

    def getFile(self,name):
        for file in self.files:
            if file.name == name:
                return file
        return None
    def getRun(self,name):
        for run in self.runs:
            if run.name == name:
                return run
        return None
    def addFile(self,file):
        self.files += [file]
    def addRun(self,run):
        self.runs += [run]

    def printResults(self):
        print "bench : " + self.name
        for file in self.files:
            file.printResults()


class SuiteResults:
    def __init__(self,name):
        self.name = name
        self.benchmarks = []

    def get(self,name):
        for bench in self.benchmarks:
            if bench.name == name:
                return bench
        return None

    def add(self,bench):
        self.benchmarks += [bench]

    def printResults(self):
        print "suite : " + self.name
        for bench in self.benchmarks:
            bench.printResults()

def processSpecRunFiles(filenames,suite,lastCompile):

    for filename in filenames:
        with open(filename) as f:
            
            start = False
            for line in f:
                
                found = re.search('.*Selected Results',line)
                if found:
                    start = True

                found = re.search('([0-9]+\.[a-zA-Z0-9_]*),.*,.*,.*,.*,.*,.*,([0-9]+\.[0-9]+),.*,.*,.*,.*',line)
                if found and start:
                    benchName = found.group(1)
                    benchmark = suite.get(benchName)
                    if benchmark != None:
                        run = RunResults(lastCompile.name)
                        run.variant = lastCompile.variant
                        run.time = float(found.group(2))
                        benchmark.addRun(run)
            
    

def processSpec2006(filename,suite):

    with open(filename) as f:

        startSpec = False
        currentBench = None
        currentFile = None
        currentRun = None

        #clang related variables
        cseSavings = 0
        optimalCost = 0

        #getting run results
        running = False
        runFiles = []

        for line in f:
            
            found = re.search('.*running (.*) benchmarks.*',line)
            if found:
                suiteName = found.group(1)
                if suiteName == "spec2006":
                    startSpec = True
                else:
                    startSpec = False

                #ok get the timing results
                if len(runFiles) > 0:
                    processSpecRunFiles(runFiles,suite,currentRun)

                currentBench = None
                currentFile = None
                currentRun = None
                cseSavings = 0
                optimalCost = 0
                running = False
                runFiles = []

            
            #first find the benchmark building
            found = re.search('.*Building ([a-zA-Z0-9_\.]*) .* (.*) .* .*',line)
            if found and startSpec:
                benchName = found.group(1)
                currentBench = suite.get(benchName)
                if currentBench == None:
                    currentBench = BenchmarkResults(benchName)
                    suite.add(currentBench)
                    
                    
            #we need to get compilation commands
            found = re.search('^([^ ]*) .* ([a-zA-Z0-9][a-zA-Z0-9_/-]*\.[cC][cp]?p*)$',line)
            if found and currentBench:
                compiler = found.group(1)
                fileName = found.group(2)
                currentFile = currentBench.getFile(fileName)
                if currentFile == None:
                    currentFile = FileResults(fileName)
                    currentBench.addFile(currentFile)
                #add duplicate compilers for now
                currentRun = RunResults(compiler)
                currentFile.add(currentRun)
                cseSavings = 0
                optimalCost = 0
                
            #get compiler specific build information - for clang
            found = re.search('^Cumulative (.*) cost savings : (-*[0-9]+)$',line)
            if found and currentRun:
                currentRun.variant = found.group(1)
                currentRun.costSavings = int(found.group(2))
                currentRun.CSECostSavings = -cseSavings
                currentRun.optimalCost = optimalCost

            #getting the CSE cost savings after gather optimization - clang
            found = re.search('^CSE .* : ([0-9]+)',line)
            if found and currentRun:
                cseSavings = cseSavings + int(found.group(1))

            #getting the ILP model reported cost - clang, my pass
            found = re.search('Solution status: .*,Cost:(-*[0-9]+)',line)
            if found and currentRun:
                optimalCost = optimalCost + int(found.group(1))


            #now to get run results if it exists
            found = re.search('.*Running Benchmarks.*',line)
            if found and startSpec:
                running = True

            #get actual running files
            found = re.search('.*format: CSV -> (.*).*',line)
            if found and running:
                runFiles += [found.group(1)]
       
        if len(runFiles) > 0:
            processSpecRunFiles(runFiles,suite,currentRun)
     

def processSimd(filename,suite):

    with open(filename) as f:

        startSimd = False
        currentBench = None
        currentFile = None
        currentRun = None
        lastCompile = None
   
        #clang related variables
        cseSavings = 0
        optimalCost = 0

        for line in f:
            
            found = re.search('.*running (.*) benchmarks.*',line)
            if found:
                suiteName = found.group(1)
                if suiteName == "simd":
                    startSimd = True
                else:
                    startSimd = False

                currentBench = None
                currentFile = None
                currentRun = None
                lastCompile = None
                cseSavings = 0
                optimalCost = 0
            
            #we need to get compilation commands
            found = re.search('^([^ ]*) .* ([a-zA-Z0-9][a-zA-Z0-9_/-]*\.[cC][cp]?p*)',line)
            if found and startSimd:
                compiler = found.group(1)
                fileName = found.group(2)
                foundBench = re.search('source/(.*)\.cpp',fileName)
                if foundBench:
                    benchName = foundBench.group(1)
                    currentBench = suite.get(benchName)
                    if currentBench == None:
                        currentBench = BenchmarkResults(benchName)
                        suite.add(currentBench)
                
                    currentFile = currentBench.getFile(fileName)
                    if currentFile == None:
                        currentFile = FileResults(fileName)
                        currentBench.addFile(currentFile)

                    #add duplicate compilers for now
                    currentRun = RunResults(compiler)
                    currentFile.add(currentRun)
                    cseSavings = 0
                    optimalCost = 0
                    lastCompile = currentRun
                else:
                    currentRun = None
                
            #get compiler specific build information - for clang
            found = re.search('^Cumulative (.*) cost savings : (-*[0-9]+)$',line)
            if found and currentRun:
                currentRun.variant = found.group(1)
                currentRun.costSavings = int(found.group(2))
                currentRun.CSECostSavings = -cseSavings
                currentRun.optimalCost = optimalCost

            #getting the CSE cost savings after gather optimization - clang
            found = re.search('^CSE .* : ([0-9]+)',line)
            if found and currentRun:
                cseSavings = cseSavings + int(found.group(1))

            #getting the ILP model reported cost - clang, my pass
            found = re.search('Solution status: .*,Cost:(-*[0-9]+)',line)
            if found and currentRun:
                optimalCost = optimalCost + int(found.group(1))


            #now to get run results if it exists
            found = re.search('running .*/test_(.*)',line)
            if found and startSimd:
                benchName = found.group(1)
                currentBench = suite.get(benchName)

            #get actual running files
            found = re.search('([^ ]*) .*[0-9]+\.[0-9]+ .*([0-9]+\.[0-9]+) .*[0-9]+\.[0-9]+',line)
            if found and currentBench:
                run = RunResults(lastCompile.name)
                run.variant = lastCompile.variant
                run.kernel = found.group(1)
                run.time = float(found.group(2))
                currentBench.addRun(run)
                

def processSpec2017(filename,suite):

    with open(filename) as f:

        startSpec = False
        currentBench = None
        currentFile = None
        currentRun = None

        #clang related variables
        cseSavings = 0
        optimalCost = 0

        #getting run results
        running = False
        runFiles = []

        for line in f:
            
            found = re.search('.*running (.*) benchmarks.*',line)
            if found:
                suiteName = found.group(1)
                if suiteName == "spec2017":
                    startSpec = True
                else:
                    startSpec = False

                #ok get the timing results
                if len(runFiles) > 0:
                    processSpecRunFiles(runFiles,suite,currentRun)

                currentBench = None
                currentFile = None
                currentRun = None
                cseSavings = 0
                optimalCost = 0
                running = False
                runFiles = []

            
            #first find the benchmark building
            found = re.search('.*Building ([a-zA-Z0-9_\.]*) .*',line)
            if found and startSpec:
                benchName = found.group(1)
                currentBench = suite.get(benchName)
                if currentBench == None:
                    currentBench = BenchmarkResults(benchName)
                    suite.add(currentBench)
                    
                    
            #we need to get compilation commands
            found = re.search('^([^ ]*) .* ([a-zA-Z0-9][a-zA-Z0-9_/-]*\.[cC][cp]?p*)$',line)
            if found and currentBench:
                compiler = found.group(1)
                fileName = found.group(2)
                currentFile = currentBench.getFile(fileName)
                if currentFile == None:
                    currentFile = FileResults(fileName)
                    currentBench.addFile(currentFile)
                #add duplicate compilers for now
                currentRun = RunResults(compiler)
                currentFile.add(currentRun)
                cseSavings = 0
                optimalCost = 0
                
            #get compiler specific build information - for clang
            found = re.search('^Cumulative (.*) cost savings : (-*[0-9]+)$',line)
            if found and currentRun:
                currentRun.variant = found.group(1)
                currentRun.costSavings = int(found.group(2))
                currentRun.CSECostSavings = -cseSavings
                currentRun.optimalCost = optimalCost

            #getting the CSE cost savings after gather optimization - clang
            found = re.search('^CSE .* : ([0-9]+)',line)
            if found and currentRun:
                cseSavings = cseSavings + int(found.group(1))

            #getting the ILP model reported cost - clang, my pass
            found = re.search('Solution status: .*,Cost:(-*[0-9]+)',line)
            if found and currentRun:
                optimalCost = optimalCost + int(found.group(1))


            #now to get run results if it exists
            found = re.search('.*Running Benchmarks.*',line)
            if found and startSpec:
                running = True

            #get actual running files
            found = re.search('.*format: CSV -> (.*).*',line)
            if found and running:
                runFiles += [found.group(1)]
       
        if len(runFiles) > 0:
            processSpecRunFiles(runFiles,suite,currentRun)


def processNAS(filename,suite):
    with open(filename) as f:

        startNas = False
        currentBench = None
        currentFile = None
        currentRun = None
        cseSavings = 0
        optimalCost = 0
        lastCompile = None

        for line in f:

            found = re.search('.*running (.*) benchmarks.*',line)
            if found:
                suiteName = found.group(1)
                if suiteName == "nas":
                    startNas = True
                else:
                    startNas = False
                currentBench = None
                currentRun = None
                currentFile = None
                lastCompile = None
                cseSavings = 0
                optimalCost = 0

            found = re.search('cd ([A-Z]*); make CLASS=([A-Z]*)',line)
            if found and startNas:
                benchName = found.group(1)
                currentBench = suite.get(benchName)
                if currentBench == None:
                    currentBench = BenchmarkResults(benchName)
                    suite.add(currentBench)
                

            found = re.search('^([^ ]*) .* ([a-zA-Z0-9][a-zA-Z0-9_/-]*\.[cC][cp]?p*)$',line)
            if found and currentBench:
                compiler = found.group(1)
                fileName = found.group(2)
                if fileName == currentBench.name.lower() + '.c':
                    currentFile = currentBench.getFile(fileName)
                    if currentFile == None:
                        currentFile = FileResults(fileName)
                        currentBench.addFile(currentFile)
                    #add duplicate compilers for now
                    currentRun = RunResults(compiler)
                    lastCompile = currentRun
                    currentFile.add(currentRun)
                    cseSavings = 0
                    optimalCost = 0
                else:
                    currentFile = None
                    currentRun = None
  
                                        
            #get compiler specific build information - for clang
            found = re.search('^Cumulative (.*) cost savings : (-*[0-9]+)$',line)
            if found and currentRun:
                currentRun.variant = found.group(1)
                currentRun.costSavings = int(found.group(2))
                currentRun.CSECostSavings = -cseSavings
                currentRun.optimalCost = optimalCost

            #getting the CSE cost savings after gather optimization - clang
            found = re.search('^CSE .* : ([0-9]+)',line)
            if found and currentRun:
                cseSavings = cseSavings + int(found.group(1))

            #getting the ILP model reported cost - clang, my pass
            found = re.search('Solution status: .*,Cost:(-*[0-9]+)',line)
            if found and currentRun:
                optimalCost = optimalCost + int(found.group(1))


            #getting the run results
            found = re.search('([A-Z]+) Benchmark Completed.*',line)
            if found and startNas:
                #should have compiled the benchmark before
                currentBench = suite.get(found.group(1))

            found = re.search('.*Time in seconds = .* ([0-9]+\.[0-9]+)',line)
            if found and currentBench:
                run = RunResults(lastCompile.name)
                run.variant = lastCompile.variant
                run.time = float(found.group(1))
                currentBench.addRun(run)
                
        

def printCostSavings(filename,suites):

    with open(filename,"w+") as f:
        for suite in suites:
            f.write(suite.name + "\n")
            for bench in suite.benchmarks:
                f.write(bench.name + "\n")
                for file in bench.files:
                    slpCostSavings = 0
                    sslpCostSavings = 0
                    slpCSESavings = 0
                    sslpCSESavings = 0
                    totalSLP = 0
                    totalSSLP = 0
                    optimalCost = 0
                    for run in file.runs:
                        if run.variant == "SSLP":
                            sslpCostSavings = run.costSavings
                            sslpCSESavings = run.CSECostSavings
                            totalSSLP = sslpCostSavings + sslpCSESavings
                            optimalCost = run.optimalCost
                        elif run.variant == "SLP":
                            slpCostSavings = run.costSavings
                            slpCSESavings = run.CSECostSavings
                            totalSLP = slpCostSavings + slpCSESavings
                    f.write(file.name + "," + str(slpCostSavings) + "," + str(slpCSESavings) + "," + str(totalSLP) + "," + str(sslpCostSavings) + "," + str(sslpCSESavings) + "," + str(totalSSLP) + "," + str(optimalCost) +"\n") 

def getHeadings(suite):
    #only a benchmark can have runs which are timed
    ret = ""
    
    bench1 = None
    run1 = None
    for bench in suite.benchmarks:
        if len(bench.runs) > 0:
            bench1 = bench
            run1 = bench.runs[0]
            break

    if bench1 == None:
        return ret

    if run1.kernel == "": #no individual kernels are timed for this benchmark
        for run in bench1.runs:
            if run.variant != "":
                ret = ret + run.variant + ","
            else:
                ret = ret + run.name + ","
    else:
        kernel = run1.kernel
        for run in bench1.runs:
            if run.kernel == kernel:
                 if run.variant != "":
                     ret = ret + run.variant + ","
                 else:
                     ret = ret + run.name + ","
    return ret + "\n"

def collectRunTimings(runs):
    hasKernel = (runs[0].kernel != "")
    ret = ""

    if hasKernel:
        kernels = {}
        for run in runs:
            if run.kernel in kernels.keys():
                kernels[run.kernel] += [run]
            else:
                kernels[run.kernel] = [run]
        for kernel in kernels.keys():
            ret = ret + kernel + ","
            for run in kernels[kernel]:
                ret = ret + str(run.time) + ","
            ret = ret + "\n"    
    else:
        for run in runs:
            ret = ret + str(run.time) + ","
        ret = ret + "\n"

    if ret == "":
        ret += "\n"
    return ret


def printTimings(filename,suites):
    
    with open(filename,"w+") as f:
        for suite in suites:
            f.write(suite.name + "\n")
            if len(suite.benchmarks) == 0:
                continue
                            
            f.write("benchmark,")
            f.write(getHeadings(suite))

            for bench in suite.benchmarks:
                if len(bench.runs) == 0:
                    continue
                hasKernel = (bench.runs[0].kernel != "")
                if hasKernel:
                    f.write(bench.name + "\n")
                else:
                    f.write(bench.name + ",")
                f.write(collectRunTimings(bench.runs))
                                
                                
if __name__ == "__main__":

    suites = [];

    if len(sys.argv) < 2:
        print "not enough arguments"
        exit(-1)

    #process command line arguments
    inputFile = sys.argv[1]

    #process spec2006 results
    spec2006 = SuiteResults('spec2006')
    processSpec2006(inputFile,spec2006)
    suites += [spec2006]
    print "done spec2006"

    #process nas results
    nas = SuiteResults('nas')
    processNAS(inputFile,nas)
    suites += [nas]
    print "done nas"

    #process spec2017 results
    spec2017 = SuiteResults('spec2017')
    processSpec2017(inputFile,spec2017)
    suites += [spec2017]
    print "done spec2017"

    #process simd results
    simd = SuiteResults('simd')
    processSimd(inputFile,simd)
    suites += [simd]
    print "done simd"

    printCostSavings("outputs/savings.csv",suites)
    printTimings("outputs/time.csv",suites)
