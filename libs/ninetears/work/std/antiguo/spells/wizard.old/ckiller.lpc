
/* cloud kill object, actually a "dead" invisible NPC 
 * Effects based on level and con, once cast this isn't a spell 
 * rather local lethal air pollution
 * caster gets a bonus 10:1 chance of not being affected
 */ 
#include "tweaks.h"
inherit "/obj/monster";

int hb;
object mycaster;
int mycount;
void do_spell(object ob);

int dispell_me()
{
   tell_room(ETO,"The deadly haze dissapates, leaving only a feeling of "
	"relief.\n",({ }));
   this_object()->dest_me();
   return 1;
}

void do_death(object ob) { }

void attack_by(object ob)
{
   ob->stop_fight(this_object());
   tell_room(ETO,(string)ob->query_cap_name()+
      " bravely, but futilely attacks a deadly cloud.\n");
   do_spell(ob);
}

void init()
{
   ::init();
   set_heart_beat(1);
}

void do_spell(object ob)
{
   int odds;
   if(ob == this_object()) return;
   if(IMMORTLOCK) if(ob->query_creator()) return;

   if(ob->query_property("dead")) return;

   if(find_living((string)ob->query_name()) )
   {
       if(ob == mycaster) odds = 10 * (int)ob->query_level();
       else odds = (int) ob->query_level();
       switch(random(odds) )
       {
       case 0:   
	  if((int)ob->query_level() > ((int)mycaster->query_level() + 4) )
	  {
	     tell_room(ETO,(string)ob->query_cap_name()+" is unaffected, "
		"but VERY annoyed.\n",({ }));
	     ob->attack_by(mycaster);
	     return;
	  }
	  if(ob == mycaster)
	  {
	     tell_room(ETO,(string)ob->query_cap_name()+" gasps with "
		"horror as the cloud turns on "+ob->query_objective()+
		"!\n",({ob}));
	     tell_object(ob,"You gasp with horror as the cloud roils "
		"towards you!\n");
	     mycaster->adjust_hp(-(36-(int)mycaster->query_con()) ,mycaster);   
	     return;
	  }   
	  if(interactive(ob))
	  {
	     tell_room(ETO,(string)ob->query_cap_name()+" turns blue, "
		"chokes and gets VERY annoyed.\n",({ }));
	     ob->set_wimpy(100);
	     ob->adjust_hp(-3,mycaster);
	     ob->attack_by(mycaster);
	     return;
	  }
	  if(present(mycaster))
	  {
	     mycaster->adjust_xp(ob->query_kill_xp());
	  }
	  ob->do_death();
       break;
       default:
       break;
      }
   }
}



void set_spell(object ob,int length)
{
	mycaster = ob;
	mycount = length;
}

void setup()
{
   set_name("cloud kill");
   set_short("cloud kill");
   set_race("monster");
   add_alias("cloud");
   set_long("A grayish deadly looking haze that fills the room.\n");
   set_spell(this_object(),10);
   set_move_after(10,2);
   add_property("dead",1);
}
void heart_beat()
{
     object *olist;
     object ob;
     int i;
      hb++;
     if(!mycaster) 
     {
	dispell_me();
     }
     if(hb > mycount)
     {
	dispell_me();
     } 
     olist = all_inventory(ETO);
     for(i = 0; i < sizeof(olist); i++)
     {
	do_spell(olist[i]);
     }
//   ::heart_beat();
}     

