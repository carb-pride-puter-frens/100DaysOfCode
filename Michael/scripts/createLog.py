import shutil
from os import listdir, rename
from os.path import isfile, join, abspath
import re
import fileinput
import datetime

# "globals"
# Links to the absolute paths of the logs folder and the template markdown file
LOGS_FOLDER_PATH = abspath('logs')
TEMPLATE_FILE_PATH = abspath('template.md')

# Natural sorting for the files
# Somewhat shamefully stolen from https://blog.codinghorror.com/sorting-for-humans-natural-sort-order/
def natsort(strings):
    def convert(string): 
        return int(string) if string.isdigit() else string
    
    def keys(key): 
        return [convert(c) for c in re.split('([0-9]+)', key)]
    
    strings.sort(key=keys)

# Out of the list of files, find the next file name and the number of it
def filename(files):
    if len(files) > 0: 
        natsort(files) 
    latestLog = files[-1] if len(files) > 0 else '0.md'
    num = int(re.compile(r'(\d+)').match(latestLog).group()) + 1
    return str(num) + '.md', num

# Grab newest file name and file number
latestFileName, latestFileNumber = filename([f for f in listdir(LOGS_FOLDER_PATH) if isfile(join(LOGS_FOLDER_PATH, f)) and f.endswith('.md')])

# Make a copy of the template file under the logs folder
shutil.copy(TEMPLATE_FILE_PATH, LOGS_FOLDER_PATH)

# Create the new file path
newFilePath = join(LOGS_FOLDER_PATH, latestFileName)

# Rename the copied template to the new file name
rename(join(LOGS_FOLDER_PATH, 'template.md'), newFilePath)

# Change the first line of the new log to show what number day it is as well as the current date
# Stolen from: https://stackoverflow.com/a/14947384
with open(newFilePath, 'r') as fromFile:
    line = fromFile.readline();
    line = line.replace('N', str(latestFileNumber))
    print(line)
    line = line.replace('(Current Date)', datetime.datetime.now().strftime('%x'))
    print(line)

    with open(newFilePath, 'w') as toFile:
        toFile.write(line)
        shutil.copyfileobj(fromFile, toFile)

print('Log created successfully for day ' + str(latestFileNumber))
