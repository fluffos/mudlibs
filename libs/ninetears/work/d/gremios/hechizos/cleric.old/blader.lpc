
/* Balde barrier object, actually a "dead" invisible NPC 
 * Effects based on level and con, once cast this isn't a spell 
 * rather local air pollution
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
   tell_room(ETO,"The blades crumble into powder and blow away on the wind.\n",({ }));
   this_object()->dest_me();
   return 1;
}
void do_death(object ob) { }
void attack_by(object ob)
{
   ob->stop_fight(this_object());
   tell_room(ETO,(string)ob->query_cap_name()+
      " stupidly attacks a blade barrier.\n");
   mycaster->attack_by(ob);
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
   if(ob->query_property("dead")) return;
   if( find_living((string)ob->query_name()) )
   {
       if(IMMORTLOCK) if(ob->query_creator()) return;
       if(ob == mycaster) odds = 10 * (int)ob->query_level();
       else odds = (int) ob->query_level();
   
       switch(random(odds) )
       {
       case 0:
       case 1:
	  if(random((int)ob->query_dex()) < 8 )
	  {
	     if(member_array(ob,mycaster->query_attacker_list()) >= 0 && present(mycaster) )
	     {
            if(!interactive(ob))
		   ob->adjust_hp(-(BLADE_DAMAGE*4),mycaster);
            else ob->adjust_hp(-BLADE_DAMAGE,mycaster);
	     }
         else 
         {
           if(!interactive(ob)) ob->adjust_hp(-BLADE_DAMAGE,mycaster);
            else if(ob->query_hp() > BLADE_DAMAGE) ob->adjust_hp(-BLADE_DAMAGE,mycaster);
         }
	  }
	  tell_object(ob,"You get cut by the blade barrier!\n");
	  tell_room(ETO,(string)ob->query_cap_name()+" is cut by the blade barrier!\n",({ ob }) );
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
   set_name("blade barrier");
   set_short("blade barrier");
   set_race("monster");
   add_alias("barrier");
   set_gender(0);
   set_long("\n A hedge of shimmering swords fills the room"
   "\n");
   set_spell(this_object(),10);
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
     ::heart_beat();
}     

