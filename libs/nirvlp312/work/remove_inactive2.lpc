#include <sys/types.h>
#include <sys/file.h>
#include <stdio.h>
#include <sys/stat.h>


main(argc, argv)
   char **argv;
{
    struct stat st;
     char yn;
     char hhh[80];
     char jj[80];
		    char filenom[100];
    int i, num;
    time_t now;

    now = time(0l);
    for (i=1, num=0; i<argc; i++) {
	if (stat(argv[i], &st) == -1)
	    continue;
	if (now - st.st_mtime > 30 * 24 * 60 * 60)
        {
         printf("%s\r\n", argv[i]);
         printf("delete? ");
         scanf("%1s", &yn);
         if (yn == 'y')
         {
          remove(argv[i]);
         printf("gone....\n");
         }
         if (yn == 'm')
         {
          printf("New Name? ");
          scanf("%50s", &hhh);
         rename(argv[i], hhh);
         printf("Moved to inactive status\n");
          }
         num ++;
        }
    }
    printf("%d\n", num);
}
