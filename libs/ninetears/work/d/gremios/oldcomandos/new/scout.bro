string query_ext_destination(string dir)
{
   string *path = environment(this_player())->query_dest_dir();
   int i,j;
   for(i=0; i<sizeof(path); i++)
   {
      if(path[i]==dir)
      {
         return(path[i+1]);
      }
   }
   write("\nIllegal direction!\n\n");
}
do_scout(string str)
{
   int j;
   string look, path;
   string *dirs;
   if(!str) {  write("\nSyntax 'scout <direction>'\n"); return(1); }
   if(environment(this_player())->query_exit(str))
   {
      path = query_ext_destination(str);
      look = (string)path->long();
      write(sprintf("%-*=s",this_player()->query_cols(),look)+"\n");
      return(1);
   }
   write("\nIllegal direction.\nTry one of these young scouter:\n");
   dirs = environment(this_player())->query_direc();
   for(j=0; j<sizeof(dirs); j++)
      write(dirs[j]+"\n");
   return(1);
}
