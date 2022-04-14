# Basic commands

1. pwd  
To find the current directory. This is an acronym for "Print Working Directory"

2. ls
List all the files and folder of the directory passed as arguemnt if no argument is given then the current directory is listed. (List storage)
'''
$ ls Downloads
Magnetite-118736-edit.jpg   Mercator_north_pole_1595.jpg   PtolemyWorldMap-edit-final.png   PtolemyWorldMap.jpg        'Sustainable Module_3.pdf'  'Sustainable Modules.zip'
 Magnetite-118736-edit.xcf  'Operating system'              PtolemyWorldMap-edit.png        'Sustainable Module_1.pdf'  'Sustainable Module_4.pdf'   test.ino
 Magnetite-118736.jpg        PtolemyWorldMap-edit2.png      PtolemyWorldMap-edit.xcf 
'''

3. cd
To Change Directory, which is passed as the argument. Passing '..' will move to the previous directory. ``` cd - ``` will also move to the previous directory.

4. cat  
Short hand for concatinate, it contcatinates the file and prints the output to the standard output  
```
$ cat file.txt file2.txt > new.txt
```
Here the contents of file.txt and file2.txt will be merged and put into a new file called new.txt. The ```>``` is the symbol for redirection which puts the output on the terminal to the file specified

It can also be used to create a new file (but using touch command is recomended, if you just want to create a file) as follows

```
$ cat > hello.txt
hello 
this is a 
new file
```
the file would contain the enterd text.

5. cp  
Basically copies files example ```cp file.txt Douments/file.txt```

6. mv  
Move the file to some sother folder instead of creating copies
``` 
mv path/of/file new/path/of/file 
```

7. mkdir  
Short hand for make directroy, Creates a directory

8. rmdir  
Removes an empty directory.
Otherwise it will show an error

9. rm  
Remove command, passing -r will cause it to recursively remove directories

rm path/to/file

rm -r path/to/directory


