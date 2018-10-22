import os
import re
import shutil

def getSpecFolders(installDir):
    ret = []
    for (dir,dirnames,filenames) in os.walk(installDir):
        found = re.search('^.*/([0-9]+\.[^/]*)/src$',dir);
        if found:
            ret += [(found.group(0),found.group(1))]
    return ret

def copySources(src,dest):
    for sources in src:
        (src_folder,bench) = sources
        dest_folder = os.path.join(dest,bench)
        print src_folder, dest_folder
        if os.path.exists(dest_folder):
            print 'removed'
            shutil.rmtree(dest_folder)
        shutil.copytree(src_folder,dest_folder)


if __name__ == "__main__":
    src_spec2006 = '/Users/charithm/Projects/benchmarks/vec/spec2006-install/'
    dest_spec2006 = '/Users/charithm/Projects/llvm-revec/simd_examples/spec2006/'
    src_spec2017 = '/Users/charithm/Projects/benchmarks/vec/spec2017-install/'
    dest_spec2017 = '/Users/charithm/Projects/llvm-revec/simd_examples/spec2017/'

    src = getSpecFolders(src_spec2006)
    copySources(src,dest_spec2006)
    src = getSpecFolders(src_spec2017)
    copySources(src,dest_spec2017)
   
