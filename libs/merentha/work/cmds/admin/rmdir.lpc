// Petrarch
// Merentha Lib 1.0
// <rmdir>

varargs int command(string file) {

  if(!file) return notify_fail("Syntax: rmdir <dir>\n");
  if(file[0..0]!="/") file=this_player()->query_cwd()+file;
  if(file_size(file)!=-2) return notify_fail("File does not exist or is not a directory.\n");

  rmdir(file);
  return 1;
}

string help() {
return "Syntax: rmdir <directory>\n\nThis command will remove a directory from the MUD.  The directory must be empty before this is allowed.\n\nSee also: rm, mkdir.";
}
