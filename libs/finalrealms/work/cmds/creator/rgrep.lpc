#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



protected int cmd(string str, object me) {
  string *files;
  string s1, *s2, *s3, pattern, whichfiles;
  int i, j, k, fsize;
  int done;

  notify_fail("Usage: grep <pattern> <files>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%s %s", pattern, whichfiles) != 2)
    return 0;

  files = this_player()->get_files(whichfiles);
  if(!sizeof(files)) {
    notify_fail("File(s) " + whichfiles + " not found.\n");
    return 0;
  }
  for (i=0;i<sizeof(files);i++)
  // Fix by Wonderflug, 96.  file_length hates dirs, so filter those
  // with file_size, which doesn't mind them.
    if ( file_size(files[i]) > 0 )
    if ((fsize=file_length(files[i])) > 0) {

     done = 0;
      for (j=0;j<fsize;j+=500) {
        s1 = read_file(files[i],j,500);
        if(strlen(s1)) {
          s2 = explode(s1,"\n");
          s3 = regexp(s2, pattern);
          if (sizeof(s3) && !done)
            printf("%s\n",files[i]);
          for (k=0;k<sizeof(s3);k++)
            printf("%5d: %s\n", j+member_array(s3[k], s2), s3[k]);
        }

      }
    }
    this_player()->set_trivial_action();
  return 1;
} /* reg_ex_grep() */
 
