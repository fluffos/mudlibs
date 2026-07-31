// /feature/npcsave.c



#include <origin.h>

#include <user.h>



inherit NPC;

inherit F_AUTOLOAD;

inherit F_SAVE;



string SAVE_NAME="npc_save";

nosave int can_save=1;




string query_save_name() {return SAVE_NAME;}



void reload(string savename)

{

/*      if(clonep())

      {

        if(sizeof(filter_array(children(base_name(this_object())), 

          (: clonep :)))>1)

        {

            can_save=0;

            call_out("self_destroy",1);

            return;

        }

      }

*/

   if(clonep() && savename && can_save)

   { 

     SAVE_NAME=savename;

     if(!restore())

       log_file("npc_save",sprintf("Failed to restore %s(%s).\n",

       		this_object()->query("id"),savename));

   }

}



string query_save_file()

{

   string id;



   id = SAVE_NAME;

   if( !stringp(id) ) return 0;

   return sprintf(DATA_DIR "npc/%c/%s", id[0], id);

}



int save()

{

   int res;

   string file=query_save_file();

   string dir=DATA_DIR "npc/";

   int len=strlen(dir);

   

   if(!file || strlen(file)<=len) return 0;

      if(file[0..(len-1)]!=dir) return 0;



        if(clonep() && can_save) {

     save_autoload();

     res = ::save();

     clean_up_autoload();    

     return res;

   } else

     return 0;  

}



void setup()

{

      ::setup();

      restore_autoload();

}



void create()

{

     set_name("非使用者物件", ({ "npc object", "npc", "object" }) );

}



void self_destroy()

{
if (this_object()->query("doing")) return 0;
    if(this_object())

   destruct(this_object());

}

