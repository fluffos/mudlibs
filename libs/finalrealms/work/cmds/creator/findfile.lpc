/* Finds a filename, given a starting path. */

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
  position = 1;
}

string query_usage() {
  return "findfile [<path>] <filename>\n";
}

string query_short_help() { 
  return "Find a file in the mud's filesystem.\n"
         "examples:\n"
         "  findfile narg.c            -- it will look for narg.c "
                                          "starting with /\n"
         "  findfile /w/hamlet narg.c  -- look for narg.c starting "
                                          "with /w/hamlet\n";
}

protected int cmd(string str, object me) {
  string *args;
  string *files;
  string path;
  string fname;
  string *match;
  string *tmp;
  int i = 0,j = 0;
  int MATCHED;
  int stopper = 0;
  
  notify_fail("usage: findfile [<path>] <filename\n");
  
  if(!str)
    return 0;
    
  args = explode(str," ");
  if(sizeof(args) == 1) {
    path = "/";
    fname = args[0];
  }
  else {
    path = args[0];
    if(path[strlen(path)-1..strlen(path)-1] != "/")
      path += "/";
    fname = args[1];
  }
  
  files = me->get_files(path);
  
  if(!sizeof(files)) {
    tell_object(me, "findfile: that path was invalid.\n");
    me->set_trivial_action();
    return 1;
  }
  while(1) {
    if(sizeof(match = regexp(files[i..sizeof(files)-1],fname))) {
      MATCHED = 1;
      for(j=0; j<sizeof(match); j++)
        tell_object(me, match[j]+"\n");
    }
    
    if(i==sizeof(files))
      break;
    
    stopper = sizeof(files);
    
    for(;i<stopper;i++) {
      if(file_size(files[i]) != -2)
        continue;
      
      if(files[i][strlen(files[i])-1..strlen(files[i])-1] != "/")
        tmp = get_dir(files[i]+"/");
      else
        tmp = get_dir(files[i]);
  
      for(j=0;j<sizeof(tmp);j++)
        if(files[i] == "/")
          files += ({ "/" + tmp[j] });
        else
          files += ({ files[i] + "/" + tmp[j] });
    }
    
    if(sizeof(files) > stopper) {
      files = files[stopper..sizeof(files)];
      i = 0;
    }
  }
  
  if(!MATCHED)
    tell_object(me,"No matches found.\n");
    
  me->set_trivial_action();
  return 1;
}
