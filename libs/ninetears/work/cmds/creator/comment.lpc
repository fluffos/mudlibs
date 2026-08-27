// Radix started and finished up by Kodiak, 1996
#include <standard.h>
#include <cmd.h>
#define OBTRACK "/obj/handlers/object_track"

inherit CMD_BASE;

void setup()
{
   position = 1;
}

string query_short_help()
{
   return "Usage: comment <object> <your comments>\n\n"
      "All items, item, containers, weapons, and armours have "
      "important stats stored in the object handler.  To add your "
      "general comments to this object, use this command.  Of "
      "course, permission is restricted to its use:  Thane of "
      "the domain in which it resides and to the Lord of Aprior.  "
      "Note, changing the comments removes the Quality Check "
      "from the object.\n\n"
      "See also:\n"
      "   qc, info, armours, weapons, containers, items\n\n";
}
int cmd(string str, object ob)
{
   object itm, *obs;
   if(!ob) 
   {
	   notify_fail("Sintaxis: comment <objecto> <comentario>\n");
	   return 0;
   }
   if(!OBTRACK->query_qc_perms(geteuid(ob))) 
   {
      notify_fail("No tienes permisos para usar QC.\n");
      return 0;
   }
   if(!str)
   {
      notify_fail("Sintaxis: qc <objeto>\n");
      return 0;
   }
   obs = this_player()->wiz_present(str,this_player());
   if(!sizeof(obs))
   {
       notify_fail("No encuentro "+str+".\n");
       return 0;
   }
   if(sizeof(obs) > 1)
      tell_object(ob,"Usando solo el primer objeto...\n");
   itm = obs[0];
   if(itm->query_item_container())
   {
      OBTRACK->qc_item_container(itm);
      return 1;
   }
   return 1;
}
