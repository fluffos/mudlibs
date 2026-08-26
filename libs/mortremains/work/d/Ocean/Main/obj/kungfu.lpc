/*
*
*
*/

#include <mudlib.h>
#include "karate.h"
#include "ocean.h"

#define gen (string)this_player()->query("gender")
#define p_name (string)this_player()->query("cap_name")
#define DAM (int)this_player()->query_level()

inherit OBJECT;
inherit KROUND;

string query_long();
object ob;

void create() 
{
    ob = environment(this_object());
    seteuid(getuid());

    set("id", ({ "brand" }) );
    set("short", "The brand of Kyrnad");
    set("long", "@@query_long");
    set("extra_look", iwrap("$N has a yin yang tatoo "+
             "on "+possessive(gen)+" left arm.\n"+
capitalize(subjective(gen))+ " is a "+KARR[KLEVEL]+" in Isshinryu Karate.\n")); 
    set("prevent_get", 1);
    set("prevent_drop", 0);
    set("prevent_clean", 1);
    set("prevent_sell", 1);
}

//int query_auto_load() { return 1; }     

void init()
{
  add_action("kkick", "kkick");
  add_action("kround", "kround");
  add_action("help", "khelp");
}

string query_long()
{
    string str;

    str = "The brand of Kyrnad. This was etched into your flesh when"+
          " you first trained with Master Kyrnad."+
	      " For help type \"khelp\".";

    return(wrap(str));
}

int kround(string arg)
{
  int val;

  if(!arg)
  {
    write("You whip your leg out and do a roundhouse to the open air.\n");
    say(p_name+" whips "+gen+" leg out and does a roundhouse to the open air.\n");
    return 1;
  }
  val = (int)call_other(KROUND, "cast_kround", arg);
  return 1;
}

int kkick(string arg)
{
  object victim, venv;
  venv = environment(this_player());

   if (!arg) arg = "NONE";
   if (arg=="NONE") victim = this_player()->query_current_attacker();
   if (!victim) victim = present(arg, environment(this_player()));
   if (!victim)
   {
    write("You do a thrust kick to the open air.\n");
    say(p_name+" does a thrust kick to the open air.\n");
    return 1;
   }

  if(!living(victim))
  {
    write("You kick "+victim->query("cap_name")+ "but there isn't much point since "+victim->query("cap_name")+" is DEAD!");
    return 1;
  }
  write("You kick "+victim->query("cap_name")+" forcefully.\n");
   victim->receive_damage((DAM * 3), "crushing", this_player());
   //this_player()->kill_ob(victim);
  return 1;

}

int help()
{
  write(@ENDHELP
Moves:

  Command       Move                  Belt
  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
  kkick         A thrust kick.        
  kround        A roundhouse kick.    
  kpunch        A horse punch.        
  kblock        A block.              
  kdown         Take down.            
  kfly          A flying kick.        
  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+

Other commands:

  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
  khelp         Kung Fu help
  =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
ENDHELP
  );
  return 1;
}
