
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;



    if((dp=opendir(dir))==NULL){
        fprintf(stderr,"cannot open directory:%s\n",dir);
        return;
    }

    chdir(dir);

    while((entry=readdir(dp))!=NULL){
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0)
                continue;
            else{
                count++;
                printdir(entry->d_name);
            }

        }    }
    if(count>max)
        max=count;
    chdir("..");
    closedir(dp);
    count=0;
