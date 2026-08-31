/*
  TMI virtual object server 
  original by Whiplash@TMI  
  sscanf code generalized by Truilkan@TMI - 92/04/29
*/

#define VSERVER_NAME "virtual"
#define DEFAULT_VSERVER "/adm/obj/server"

nomask object compile_object(string file)
{
   string name, server;
   string *tmp;

   if (file_size(file) != -1) return 0;

   tmp = path_file(file);
   server = tmp[0] + "/" + VSERVER_NAME;
   if (file_size(server + ".c") == -1)
      server = DEFAULT_VSERVER;
   return (object)call_other(server,"compile_object",file);
}

void clean_up()
{
   destruct(this_object());
}
