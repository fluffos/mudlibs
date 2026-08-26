// Petrarch
// Merentha Lib 1.0
// <mkdir>

varargs int command(string file) {

  if(!file) return notify_fail("Syntax: mkdir <file>\n");
  if(file[0..0]!="/") file=this_player()->query_cwd()+file;
  if(file_size(file)!=-1) return notify_fail("File exist or is a directory already.\n");

  mkdir(file);
  return 1;
}

string help() {
return "Syntax: mkdir <directory>\n\nMakes a new directory (foulder) called <directory>.\n\nSee also: rmdir";
}
