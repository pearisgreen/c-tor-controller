#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tor_controller.h"

int main(int argc, char **argv)
{
#define COMMAND_LEN     256
    char command[COMMAND_LEN];

    do
    {
        memset(command, 0, COMMAND_LEN);

        fgets(command, COMMAND_LEN - 1, stdin);

        //remove controll tokens from command
        for(char *ptr = command; *ptr != 0; ptr++)
            if(*ptr == '\t' || *ptr == '\n' || *ptr == '\r')
                *ptr = 0;

        printf("command: %s\n", command);

        if(!strcmp(command, "start"))
        {
            tor_start("..", argv);
        }
        else if(!strcmp(command, "running"))
        {
            if(tor_is_running())
                printf("running\n");
            else
                printf("killed\n");
        }
        else if(!strcmp(command, "kill"))
        {
            if(tor_stop())
                printf("killed tor process\n");
        }

        

    } while(strcmp(command, "quit"));
}