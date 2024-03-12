import os
import subprocess as sb

# new comment

#curl "https://ctcsoc-jks.rtkbf.com/jenkins/buildByToken/build?job=test/test-pipelineascode-urf-triggered-ftp&token=mytriggertoken"
cmds = ['curl', '-X', 'POST', '--url', \
        'https://ctcsoc-jks.rtkbf.com/jenkins/buildByToken/buildWithParameters/build?job=test/test-pipelineascode-urf-triggered-ftp&token=mytriggertoken&RELEASE_NAME=RDC_Demo-Internal-611-2023_1019_1711&SMSURF_ID=166659', '-o', 'output.html']
cmdShell = sb.Popen(cmds, stdout=sb.PIPE)
while True:
    line = cmdShell.stdout.readline()
    try:
        print(line.decode('utf-8').strip(), flush=True)
    except:
        print(line.strip(), flush=True)
    if not line:
        break
cmdShell.communicate()
