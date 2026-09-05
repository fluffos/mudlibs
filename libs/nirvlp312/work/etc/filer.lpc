#include "/kernel/defs.h"

#include <libs.h> // Chameloid, 05-Sep-1996

inherit ACCESS;
inherit "/basic/create";
inherit "/basic/path";

void create() {
  set_privilege(1);
}

varargs void secure_log_file(string file,string text,status no_trunc) {
  int size;
  if (!no_trunc) {  // added this if.  Alfe 2006-Jun-23
    size = file_size(file);
    if (size == -2)
      return;
    if (file[0..4] == "/log/" && size > 20000 || size > 50000)
      rename(file,file+".old");
  }
  write_file(file,text);
}

varargs void log_file(string file,string text,status no_trunc) {
  string *path;
  string name;
  string prefix;

  if (file[0]!='/')
    prefix = "/log";
  file = normalize_path(file);
  if (prefix)
    file = prefix + file;
  path = explode(file,"/")-({ "" });
#if 0
  if ((sizeof(path)<2 || (path[0]!="log" && path[0]!="syslog")) &&
      !check_previous_privilege(SECURITY->query_protection(file,1)))
    raise_error("Wrong write permissions for "+file+".\n");
#endif
  if (path[0] == "log") // only substitute 'log' for 'syslog' (Ugh Nov-25-1996)
  {
#if 0 // Chameloid, 05-Sep-1996
    name = path[1][1..];
    if (name != lower_case(name))
#else
    name = path[1];
    if (name == upper_case(name))
#endif
      path[0] = "syslog";
  }
  file = "/"+implode(path,"/");
  // removed path[0] as third arg in next line, Coogan, 17-Nov-2006
  unguarded(1, #'secure_log_file, ({ file, text, no_trunc }) );
}

#define BUFFERSIZE 30000

int copy_file(string source,string dest) {
  int size;
  int pos;
  string buffer;
  int blocksize;

  size = file_size(source);
  if (size < 0)
    return 0;
  rm(dest);
  if (!size)
    return write_file(dest,"");
  pos = 0;
  do
  {
    if (size > BUFFERSIZE)
      blocksize = BUFFERSIZE;
    else
      blocksize = size;
    buffer = read_bytes(source,pos,blocksize);
    if (!buffer)
      return 0;
    if (!write_file(dest,buffer))
      return 0;
    pos += blocksize;
    size -= blocksize;
  } while (size);
  return 1;
}

