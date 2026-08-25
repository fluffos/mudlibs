// Stuff required as a result of MudOS upgrades..
// Will proliferate into other simul_efuns later
// 6 Oct 1993 Chrisy

varargs int cat(string file, int start, int num)
{
  string s;
  if(!"secure/master"->valid_read(file, geteuid(previous_object()), 
      "read_file") || file_length(file) <= 0)
    return 0;

  s = read_file(file, start, num);
  if(!s)
    return 0;
  write(s+"\n");
  return 1;

/*  if( (!start && !num) || !num)
    write(read_file(file));
  else
  {
    string *f;
    f = explode(read_file(file), "\n");
    if(sizeof(f)<(start+num) || start>=sizeof(f))
      return 0;
    write(implode(f[start..start+num], "\n")+"\n");
  }
  return 1;
*/
}

varargs string e_extract(string str, int from, int to)
{
  if(!to)
    to = strlen(str)-1;
  return str[from..to];
}
