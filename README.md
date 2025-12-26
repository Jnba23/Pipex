# Pipex

A simplified re-implementation of shell piping using processes, file descriptors, and `execve`.  
The program reproduces the behavior of:  
```bash
< infile cmd1 | cmd2 > outfile
```
## 🎯 Goals
- Understand UNIX process management
- Work with fork(), pipe(), dup2(), and execve()
- Practice handling file I/O and command execution paths
## 🧱 Mandatory Program
```bash
./pipex infile "cmd1" "cmd2" outfile
```
## 🛠️ Compilation 
```bash
#Madatory part (single command)
make man
  ||
#Bonus part (Multiple commands)
make bonus
