// Petrarch
// Merentha Lib 1.0
// <mv>

varargs int command(string source) {
string dest;

  if(!source) return notify_fail("Syntax: mv <source> <dest>\n");
  sscanf(source, "%s %s", source, dest);
  if(!source || !dest) return notify_fail("Syntax: mv <source> <dest>\n");
  if(source=="" || dest=="") return notify_fail("Syntax: mv <source> <dest>\n");
  if(source[0..0]!="/") source=this_player()->query_cwd()+source;
  if(dest[0..0]!="/") dest=this_player()->query_cwd()+dest;
  if(file_size(source)<0) return notify_fail("File does not exist or is a directory.\n");

  rename(source, dest);
  return 1;
}

string help() {
return "Syntax: mv <source> <destination>\n\nThis command moves a file.  If path names are not mentioned it basically just renames the file.";
}
