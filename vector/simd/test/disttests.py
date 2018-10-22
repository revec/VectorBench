import os
import glob
import re


class TestFunction:
 name = ""
 func = ""
 arch = []
 file = ""
 

def collectTestFunctions():
 functions = [];
 for filename in glob.glob("Old/Test*.cpp"):
  with open(filename,'r+') as file:
   lines = file.readlines()
   nolines = len(lines)
   for i in range(0,nolines):
    line = lines[i]
    found = re.search(r"bool[ ]*(.*)AutoTest\(\).*",line)
    if found:
     func_ob = TestFunction()
     func_ob.name = found.group(1)
     func_ob.file = re.sub(r'Old/(.*)\.cpp',r'Test/\1.h',filename)
     #we need to collect the function and its variants
     j = i + 1
     func = ""
     while True:
      line = lines[j]
      arch = re.search(r"#if.*SIMD_(.*)_ENABLE.*",line)
      if arch:
       func_ob.arch = func_ob.arch + [arch.group(1)]
      j = j + 1
      func = func + line
      if re.search(r".*}.*",line):
       func_ob.func = func
       functions = functions + [func_ob]
       i = j
       break
    
 return functions

def insertLines(regex,lines,insert):
 sz = len(lines)
 for i in range(0,sz):
  found = re.match(regex,lines[i])
  if found:
   lines.insert(i,insert)
   return lines

def getArchString(archs, active, lines):
 arch_def = ""
 for arch in archs:
  string = "#undef SIMD_" + arch.upper() + "_ENABLE"
  if not isStringPresent(lines,string):
   arch_def += string + "\n"
 string = "#define SIMD_" + active.upper() + "_ENABLE"
 if not isStringPresent(lines,string):
  arch_def += string + "\n"
 return arch_def

def printLines(lines):
 for line in lines:
  print(line)

def getSourceFileName(arch,testName):
 print(arch,testName)
 files = []
 
 if arch == 'SSE' or arch == 'AVX':
  arch += '1'

 for filename in glob.glob("../source/" + arch.lower() + "_*.cpp"):
  name = '../source/(.*)\.cpp'
  name_found = re.search(name,filename)
  if name_found:
   with open(filename,'r') as file:
    for line in file:
     search_string = ' ' + testName + '\(';
     test_found = re.search(search_string,line)
     if test_found:
      files += [name_found.group(1)]
      break
 return files[0]
     
def getNumTest(lines):
 sz = len(lines)
 for i in range(0,sz):
  test = re.search(r'//_TESTS_([0-9]*)',lines[i])
  if test:
   value = int(test.group(1)) + 1
   lines[i] = '//_TESTS_' + str(value) + '\n'
   return (lines,value)
 assert False

def getExecString(number):
 return     (
    "TEST_LOG_SS(Info,  \"AutoTest" + number + " is started :\");\n" 
    "bool result" + number + " = Test::AutoTest" + number + "();\n"
    "TEST_LOG_SS(Info, \"AutoTest" + number + " is finished \" << (result" + number + " ? \"successfully.\" : \"with errors!\") << std::endl);\n"
    "if(!result" + number + ")\n" 
    "{\n"
    "  return 1;\n"
    "}\n"
)

def isStringPresent(lines,string):
 for line in lines:
  found = re.match(string,line)
  if found:
   return True
 return False


def distTestFunctions(funcs):
 for func in funcs:
  for arch in func.arch:
   name = getSourceFileName(arch,func.name)
   name = "test_" + name + ".cpp"
   lines = None
   exist = False
   if os.path.exists(name):
    exist = True
    with open(name,'r') as canonical:
     lines = canonical.readlines()
   else:
    with open('canonical.in','r') as canonical:
     lines = canonical.readlines()

   #get the number of tests already in the file
   (lines, test_no) = getNumTest(lines)

   archs = getArchString(func.arch,arch,lines)
   lines = insertLines(r'^//_INSERT_HEADERS_',lines,archs)

   if not isStringPresent(lines,'#include "' + func.file):
    lines = insertLines(r'^//_INSERT_HEADERS_',lines,'#include "' + func.file + '"\n') 

   lines = insertLines(r'^//_AUTO_TEST_',lines,'bool AutoTest' + str(test_no) + '()' + func.func)
   lines = insertLines(r'^//_RUN_CODE_',lines,getExecString(str(test_no)))

   with open(name,'w') as test_file:
    test_file.writelines(lines)

def main():
 #print(getExecString('1'))
 funcs = collectTestFunctions()
 distTestFunctions(funcs)
 # for func in funcs:
 #  print(func.name)
 #  for arch in func.arch:
 #   print(arch)
 #  print(func.func)
 # getSourceFileName('sse2','val')

if __name__ == "__main__":
 main()

