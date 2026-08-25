// Radix, info command - July 1996
#include <standard.h>
#include <cmd.h>
#define OBTRACK "/obj/handlers/item_info"

inherit CMD_BASE;

void setup()
{
   position = 1;
}

string query_short_help()
{
   return "Usage: info <object>\n\n"
      "All items and NPCs can be info'ed.  Different "
      "information is of course obtained for the different "
      "objects.  Info is stored in /obj/handlers/object_track.c "
      "for items and death.c for NPCs.\n\n"
      "Item info is checked everytime it is cloned, and "
      "updated.  If the old data is no longer valid, the object "
      "loses its QC status and must be re-QCed by the "
      "appropriate immortal(s).  "
      "\n\n"
      "NPC data is updated everytime an NPC is killed or kills "
      "another player.  The NPC's query_kill_xp is the main "
      "stat of concern here, when it is either adjusted up or "
      "down for various reasons determined by stored data.  " 
      "\n\n"
      "See also:\n"
      "  stat, qc\n\n";
}
protected int cmd(string str, object ob)
{
   object itm, *obs;
   string *tmp;
   if(!ob) return 0;
   if(!str)
   {
      notify_fail("Syntax: info <object>\n");
      return 0;
   }
  ob->set_trivial_action();
   if(str[0..1] == "-d")
   {
      str = str[3..10000];
      tmp = explode(str," ");
      if(sizeof(tmp) != 2)
      {
         notify_fail("Syntax: info -d domain/sub-dir <weapons | "
            "armours | items | containers>\n");
         return 0;
      }
      switch(tmp[1])
      {
         case "weapons" :
         case "weapon" :
         case "w" :
            OBTRACK->domain_weapons(tmp[0]);
            return 1;
            break;
         case "armours" :
         case "armour" :
         case "armors" :
         case "armor" :
         case "a" :
            OBTRACK->domain_armours(tmp[0]);
            return 1;
            break;
         case "containers" :
         case "container" :
         case "c" :
            OBTRACK->domain_item_containers(tmp[0]);
            return 1;
            break;
         case "items" :
         case "item" :
         case "i" :
            OBTRACK->domain_items(tmp[0]);
            return 1;
            break;
         default :
            notify_fail("Syntax: info -d domain/sub-dir <weapons | "
               "armours | items | containers>\n");
            return 0;
            break;
      }
   }
   obs = this_player()->wiz_present(str,this_player());
   if(!sizeof(obs))
   {
       notify_fail("Could not find "+str+".\n");
       return 0;
   }
   if(sizeof(obs) > 1)
      tell_object(ob,"Only doing the first object...\n");
   itm = obs[0];
   if(!OBTRACK->query_info_perms(geteuid(ob),itm)) 
   {
      notify_fail("You do not have permission to info this item.\n");
      return 0;
   }
   if(itm->query_item_container())
   {
      OBTRACK->info_item_container(itm);
      return 1;
   }
   if(itm->query_weapon())
   {
      OBTRACK->info_weapon(itm);
      return 1;
   }
   if(itm->query_armour())
   {
      OBTRACK->info_armour(itm);
      return 1;
   }
   return 1;
}
