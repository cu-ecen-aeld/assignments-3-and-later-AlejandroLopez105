/**
 * @file writer.c
 * @author AlejandroLopez105 (alejandrolo829@gmail.com)
 * @brief This file can be used as an alternative to the "writer.sh" test script
 * @version 0.1
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023 property of AlejandroLopez105
 * This file is part of my assignments for the Linux System Programming and 
 * Introduction to Buildroot course
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>


int main(int argc, char *argv[]){

char *writeFile = argv[1];
char *writestr  = argv[2];
openlog("writer.c", 0, LOG_USER);

if(argc != 3){

    printf("You have not introduced two arguments while running this file, please enter:\n"
    "1. writefile\n"
    "2. writestr\n");
    syslog(LOG_ERR, "Usage: ./writer path/to/file stringToWrite");
    return 1;
}
FILE *fp = fopen(writeFile, "w");
if(fp == NULL){
    syslog(LOG_ERR, "The directory for %s doesn't exist",writeFile);
    return 1;
}
syslog(LOG_DEBUG,"Writing %s to %s", writestr, writeFile);
fprintf(fp, "%s",writestr);
fclose(fp);
return 0;
}