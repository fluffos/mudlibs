int main(string str) {
  string *dir = get_dir("/text/quitmsg.dir/quitmsg.*");
  int index;
  if (!str || !sscanf(str,"%d",index) || index < 0 || index >= sizeof(dir)) {
    if( str ) {
       msg("Messages are numbered from 0 to "+(sizeof(dir)-1));
	   if( index )
	      index = index % sizeof(dir);
	} else
       index = random(sizeof(dir));
  }
  string file = read_file("/text/quitmsg.dir/"+dir[abs(index)]);
  msg("~CTITQuit Message #"+abs(index)+"~CDEF\n~CLAB------------~CDEF");
  msg(file+"~CLAB------------~CDEF");
  return 1;
}
