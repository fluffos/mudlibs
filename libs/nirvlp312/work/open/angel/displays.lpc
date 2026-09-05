int display_file(string my_file)
{
   int x;
   string *all;
   
   if(file_size(my_file) < 1) return 0;
   my_file = read_bytes(my_file, 0, file_size(my_file));
   all = explode(my_file,"\n");
   for(x = 0; x < sizeof(all); x++)
tell_room(environment(this_player()),all[x]+"\n");
   return 1;
}
