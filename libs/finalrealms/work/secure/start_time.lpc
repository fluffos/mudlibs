// Radix 1996
// Used by various handlers for player id

int start_time;

int query_start_time(string name)
{
   string file = "/players/"+name[0..0]+"/"+name;
   seteuid("Root");
   start_time = 0;
   if(file_size(file+".o") > 0)
      restore_object(file);
   return start_time;
}
