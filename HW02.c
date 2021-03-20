#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>

int main(int rgc, char** argv) {
    int i = 1, flag = 0;

    while(argv[i] != NULL) {
        char* file_name = argv[i];
        if(access(file_name, F_OK) != 0) {
            perror("not exist");
        }
        else {
            printf("file exist\n");
            if(access(file_name, R_OK) != 0) {
                perror("no permission");
            }
            else {
                printf("permission OK\n");
                flag = 1;
            }
        }

        if(flag != 0) {
            ;
        }
        else {
            goto STEP_FINAL;
        }

        struct stat file_info;
        struct stat file_info2;
        struct passwd* my_passwd;
        struct group* my_group;
        mode_t file_mode;

        if(stat(file_name, &file_info) < 0) {
            perror("stat: ");
            return -1;
        }
        file_mode = file_info.st_mode;

        int dir_cnt = 0;
	    if(S_ISDIR(file_mode)) {
            dir_cnt++;
        } 
	    

	    my_passwd = getpwuid(file_info.st_uid);
	    my_group = getgrgid(file_info.st_gid);
    	// printf("OWNER: %s\n", my_passwd->pw_name);
	    // printf("GROUP: %s\n", my_group->gr_name);

        if(chmod(argv[i], (file_info.st_mode | S_IRUSR | S_IRGRP | S_IROTH)) < 0) {
            perror("chmod: ");
        }

        stat(file_name, &file_info2);
        int cnt = 0;
        if(file_info2.st_mode & S_IXUSR) {
            cnt++;
        }
        if(file_info2.st_mode & S_IXGRP) {
            cnt++;
        }
        if(file_info2.st_mode & S_IXOTH) {
            cnt++;
        }
        
        if(cnt >= 1 && dir_cnt == 0) {
            if(chmod(file_name,file_info2.st_mode | S_IXUSR | S_IXGRP | S_IXOTH)) {
                perror("chmod: ");
            }
        }
        else if(dir_cnt != 0) {
            if(chmod(file_name,file_info2.st_mode | S_IXUSR | S_IXGRP | S_IXOTH)) {
                perror("chmod: ");
            }
        }
        STEP_FINAL:
        i++;
    }
}