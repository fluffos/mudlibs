/* Extended filefixer... now you can give wildcards as arguments */

inherit "/std/thing";
#include <properties.h>
#include <secure/wizlevels.h>

string X,Y;

create() {
  (::create());
  seteuid(getuid());
  SetShort("filefixer");
  SetLong("\The File-Fixer of Ireland.\n\
Concept and ideas of Pumuckel.\n\
Updatet and improved by Mutabor.\n\
\n\
Use: fix <object_name>:  Fixes the string X into Y\n\
     stringX <string>: Enter the string you want to change\n\
     stringY <string>: Enter the new string\n\
");
  SetIds(({"filefixer","fixer","file_fixer"}));
  Set(P_AUTOOBJECT,1);
  Set(P_NOGIVE,1);
  Set(P_NOSELL,1);
  Set(P_NODROP,1);
}

init() {
  (::init());
  if (environment() != this_player()) return;
  if (getuid(this_player()) == getuid()) {
    if (!(IS_IMMORTAL(this_player())))
      return dest_me();
    add_action("fix","fix");
    add_action("stringX","stringX");
    add_action("stringY","stringY");
  }
  else return dest_me();
}

dest_me()
{
  this_object()->remove();
}

stringX(string str) {
  if (geteuid(this_interactive()) != geteuid()) return;
  if (!str) {
    write("Please enter the string you want to change\n\
The old string was: "+X+".\n");
    return 1; 
  }
  X = str;
  write("You set the X string to:\n\
- "+X+".\n");
  return 1;
}

stringY(string str) {
  if (geteuid(this_interactive()) != geteuid()) return;
  if (!str) {
    write("Please enter the new string\n\
The old string was: "+Y+".\n");
    return 1; 
  }
  Y = str;
  write("You set the Y string to:\n\
- "+Y+".\n");
  return 1;
}

string *get_filenames(string str)
{
  string *files;
  string path, basepath;

  if (geteuid(this_interactive()) != geteuid()) return ({});
  path = this_player()->get_path(str);
  basepath = "/" + implode((explode(path,"/")-({""}))[0..<2]+({""}),"/");
  files = get_dir(path)-({".",".."});
  return files?map(files,lambda(({'arg1,'arg2}),({#'+,'arg2,'arg1})),
                         basepath):0;
}

xfix(string file) {
  if (geteuid(this_interactive()) != geteuid()) return; 
  if(file_size(file) == -2) {
    write(file + " is a directory.\n");
    return 0;
  }
  if (file_size(file+"~")!=-1) {
    write("Do you really want to overwrite the old tmp file ? ");
    input_to("tmp_filetest",0,file);
  }
  else xfix2(file);
}

xfix2(string file)
{
  string filetext;
  string *exp;
  int size;

  if (geteuid(this_interactive()) != geteuid()) return;
  write("file = " + file + "\n");
  filetext = read_file(file);
  if (!write_file(file+"~",filetext)) {
    write("Couldn't write " + file + "~.\n");
    return 0;
  }
  write("Wrote "+file+"~.\n");
  exp = explode(filetext,X);
  size = sizeof(exp)-1;
  filetext=implode(exp,Y);
  write("Changed "+size+" words.\n");
  if (!rm(file)) {
    write("Couldn't remove old " + file + ".\n");
    return 0;
  }
  if (!write_file(file,filetext)) {
    write("Couldn't write " + file + ".\n");
    return 0;
  }
  write("Wrote new "+file+".\n");
  return 1;
}

tmp_filetest(string test, string file) {
  if (geteuid(this_interactive()) != geteuid()) return;
  write("file = " + file + "\n");
  if (test != "y" && test != "yes") return 0;
  else {
    rm(file+"~"); /* delete old tmp file */
    xfix2(file);
  }
}

fix(string str)
{
  string *files;
  mixed tmp;
  int i;

  if (geteuid(this_interactive()) != geteuid()) return;
  if(!str) {
    notify_fail("Usage: fix <filelist>\n");
    return 0;
  }
  tmp = map(explode(str," ")-({""}),#'get_filenames)-({0});
  files = ({});
  for(i = sizeof(tmp);i--;) files += tmp[i];
  if(sizeof(filter(files,#'xfix)-({1}))) {
    notify_fail("Some errors occured while execution.\n");
    return 0;
  }
  return 1;
}




