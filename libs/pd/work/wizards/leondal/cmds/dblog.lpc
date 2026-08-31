/****************************************
 * 
 * dblog.c
 *
 * Leondal - 09/2009
 *
 * A simple file that lets me see the tail
 * end of any of the log files in
 * /log/errors.
 *
 *****************************************/

#include <std.h>

status main(string str) {

  string file, text;

  if(!str || !stringp(str)) file = "/log/debug.log";
  else file = sprintf("/log/errors/%s",str);

  text = read_file(file,1,15);

  if(!text) {

    printf("No log file (%s).\n",file);
    return 1;

  }

  printf("%s\n",text);
  return 1;

}
