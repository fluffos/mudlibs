int cmd_grep(string str)
{
 string ln, filename, strang, x;
 int    i;

 i = 1;
 if(!str || sscanf(str, "%s %s", strang, filename) < 2)
 {
  write("Usage: 'grep <string> <filename>'\n");
  return 1;
 }
 write("Processing...\n");
 filename = resolv_path(filename);

 ln = read_file(filename, i);

 while(ln)
 {
  if(sscanf(ln, "%s"+strang+"%s",x,x))
   write(ln);
  i ++;
  ln = read_file(filename, i);
 }
 return 1;
}

