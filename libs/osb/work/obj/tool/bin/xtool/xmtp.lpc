#include "../bincmd.h"

inherit BASICXCMD;

#ifndef MASTER
#define MASTER __MASTER_OBJECT__
#endif

QueryAbrev() { return "xmt"; }

void XmtpScript(string dir, string file, string opt) {
  int s, t;
  string *files;
  
  s=sizeof(files=get_dir(dir+"/*"));
  while(s--) {
    t=strlen(files[s])-1;
    if(files[s] == ".." || files[s] == "." || files[s][t] == '~' ||
       (files[s][0] == '#' && files[s][t] == '#'))
      continue;
    if(file_size(dir+"/"+files[s])==-2) {
      write_file(file, "mkdir "+files[s]+" ; cd "+files[s]+"\n");
      XmtpScript(dir+"/"+files[s], file, opt);
      write_file(file, "cd ..\n");
    } else
      write_file(file, "mtp -r "+opt+" "+dir+"/"+files[s]+"\n");
  }
}

int main( string str ) {
  int s;
  string *strs, opt, dir, file;

  notify_fail( "xmt(p) [options] <directory> <filename>\n");
  if ( (!str)||(str=="?") ) return 0;

  s=sizeof(strs=explode(str, " "));
  if(s<2)
    return 0;
  else if(s==2)
    opt="";
  else 
    opt=implode(strs[0..s-3], " ");

  if(!(dir="/"+(string)MASTER->valid_read(strs[s-2], geteuid(),
				      "get_dir", this_object()))) {
    tell_object( cloner, "No permission to open directory for reading.\n");
    return 1;
  }
  if(!(file="/"+(string)MASTER->valid_write(strs[s-1], geteuid(),
					"write_file", this_object()))) {
    tell_object( cloner, "No permission to open script file for writing.\n" );
    return 1;
  }
  if(file_size(dir)!=-2 || file_size(file)==-2)
    return 0;

  XmtpScript(dir, file, opt);

  tell_object( cloner, "Done.\n");

  return 1;
}





