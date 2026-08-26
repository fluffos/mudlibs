// Function name:	update_file()
// Description:		reads in a file, ignoring lines that begin with '#'
// Arguements:		file: a string that shows what file to read in.
// Return:		Array of nonblank lines that don't begin with '#'

string *update_file(string file) {
  string *array;
  string str;
  int i;

  seteuid(geteuid(previous_object()));
  str = read_file(file);
  if(!str)
    return ({});
  array = explode(str,"\n");
  for(i = 0; i < sizeof(array); i++)
    if(array[i][0] == '#')
      array[i] = 0;
  return array;
}

