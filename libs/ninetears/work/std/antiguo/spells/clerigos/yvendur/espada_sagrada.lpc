/* Blade barrier object, actually a "dead" invisible NPC 
 * Effects based on level and con, once cast this isn't a spell 
 * rather local air pollution
 * caster gets a bonus 10:1 chance of not being affected
 */ 
#include "tweaks.h"
inherit "/obj/weapon";

int hb;
object mycaster;
int mycount;

void do_spell(object ob);

int dispell_me()
{
  tell_room(ETO,
    "Tu espada sagrada sucumbe bajo el poder del viento.\n",({ }));
  this_object()->dest_me();
  return 1;
}

void do_death(object ob) { }

void attack_by(object ob)
{
  ob->stop_fight(this_object());
  tell_room(ETO,(string)ob->query_cap_name()+
    "de repente ataca sin parar.\n", ob);
  tell_object(ob, "Tu ataque es menos que satisfactorio.\n");
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
   
  reset_get();
  if(ob == this_object() || ob->query_dead() || !living(ob) ||
     ((IMMORTLOCK) && ob->query_creator()) )
    return;

  if(ob == mycaster) 
    odds = 10 * (int)ob->query_level();
  else 
    odds = (int) ob->query_level();
   
  switch(random(odds) )
  {
    case 0:
    case 1:
      if(random((int)ob->query_dex()) < 8 )
      {
        if ( member_array(ob,mycaster->query_attacker_list()) >= 0 && 
             present(mycaster) )
        {
          if(!interactive(ob))
            ob->adjust_hp(-(BLADE_DAMAGE*4),mycaster);
          else 
            ob->adjust_hp(-BLADE_DAMAGE,mycaster);
        }
        else 
        {
          if(!interactive(ob)) 
            ob->adjust_hp(-BLADE_DAMAGE,mycaster);
          else if(ob->query_hp() > BLADE_DAMAGE) 
            ob->adjust_hp(-BLADE_DAMAGE,mycaster);
        }
      }
      tell_object(ob,"Consigues un enorme corte con tu Espada Sagrada!\n");
      tell_room(ETO,(string)ob->query_cap_name()+
        " corta la piel a tiras con su espada sagrada!\n",({ ob }) );
      break;
  }

}


void set_spell(object ob,int length)
{
  mycaster = ob;
  mycount = length;
}

void setup()
{
  set_base_weapon("long sword");
  set_name("espada sagrada");
  set_short("Espada Sagrada");
  set_main_plural("Espadas Sagradas");
  add_plural("espadas");
  add_alias("espada");
  add_alias("sagrada");
  set_long("\nEs la espada sagrada del gremio de Clerigos de Yvendur con mango tricolor.\n");
  set_spell(this_object(),10);
  TO->add_property("faith","Clerigo de Yvendur");
}

void heart_beat()
{
  object *olist;
  object ob;
  int i;

  if(!mycaster || ++hb > mycount)
  {
    dispell_me();
    return;
  } 

  olist = all_inventory(ETO);
  for(i = 0; i < sizeof(olist); i++)
    do_spell(olist[i]);
}     

