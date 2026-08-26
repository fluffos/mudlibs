// I hate MSDOS.  It leaves annoying ^M's in the files.
// This should remove them for me.
// (05-24-00) Chronos.
#include <mudlib.h>

inherit DAEMON;

int cmd_dosconvert(string str) {
  string work, x, y ;
int i;
  if (!str) {
    write("Usage: dosconvert <filename>\n") ;
    return 1;
  }
  if (!file_exists(str)) {
     str = TP->query("cwd") + "/"+ str ;   // guess we're using relative
    if (!file_exists(str)) {
    write("[DOSConverter] That filename does not exist.\n") ;
    write("DEBUG: filename = "+str+"\n") ;
    return 1;
  }
  }
  work = read_file(str) ;
  write("[DOSConverter] Opening file \""+str+"\" ... ") ;
/*
  while(sscanf(work, "%s^M%s", x, y)) {
*/
  while(sscanf(work, "%s^%s", x, y)) {
   work = x + y[1..<1] ;
    i++ ;
  }
  work = replace_string(work, "^M", " ") ;
  rm(str) ;
  write_file(str, work+"\n") ;
  write("finished.\n\tAll traces of MSDOS have been eliminated.\n") ;
  write("\t   ("+i+" ^M's..)\n") ;
  return 1;
}

string help() {
  return @ENDHELP
Usage: dosconvert <filename>

This command will remove all the extra carriage returns from
MSDOS files.
ENDHELP
;
}
