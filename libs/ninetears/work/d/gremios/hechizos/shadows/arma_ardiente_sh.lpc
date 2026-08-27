#include "tweaks.h"
#define BURNING_WEAPON_GP 1

object my_player;
int tiempo;

void setup_shadow(object me, int duracion) 
{
  shadow(me,1);
  my_player = me;
  my_player->add_extra_look(TO);
  tiempo = duracion;
}

int query_arma_ardiente()
{
   return 1;
}

int check_duration()
{
  int multip;
  int armado=sizeof(my_player->query_weapons_wielded());
  
  if(armado<2) multip=1;
  else multip=2;
       if ( (int)my_player->query_gp() <= (BURNING_WEAPON_GP*multip) || 
       !my_player || !my_player->query_property("TIME_ARMAS_ARDIENTES"))
    return 1;
    return 0;
}

/* Esto estaba pq el anterior sistema no llamaba a weapon attack
   aki, sino en las armas. Ahora se llama a weapons_attack - Tyrael
object* query_weapons_wielded()
{
  return my_player->query_weapons_wielded()+({ this_object() });
}
*/

int query_light()
{
  int armado=sizeof(my_player->query_weapons_wielded());

  if(!armado) armado=1;
  return my_player->query_light()+armado*10;
}

int query_res(string type)
{
   if(type=="fuego") return 70;
   if(type=="agua") return -30;
   return my_player->query_res(type);
}

// weapon_attack pertenece a weapon no a un player, unarmed si :P
// el nuevo sistema que se usara tb en surge y demas llama a
// weapons_attack y shields_attack.
//int weapon_attack( object him, object me )
int weapons_attack( object him, object me, int n, object *weaps )
{
  int damage, weap_dam;
  int multip;
	string mess;

	weap_dam = me->weapons_attack(him, me, n, weaps);

  if ( check_duration() )
    {
    call_out("dispell_burning_weapon",0);
    return weap_dam;
    }
  if(n<2) { n=1; mess = " arma.\n"; }
  else { n=2; mess = "s armas.\n"; }
  my_player->adjust_gp(-BURNING_WEAPON_GP*n);

    tell_object(him,me->query_cap_name()+" te %^BOLD%^RED%^abrasa%^RESET%^ con su" + mess);
    tell_object(me,"%^BOLD%^RED%^Abrasas%^RESET%^ a "+him->query_cap_name()+" con tu" + mess);
    tell_room(ENV(me),me->query_cap_name()+" %^BOLD%^RED%^abrasa%^RESET%^ a "+him->query_cap_name()+
                      " con su" + mess,({ him, me }));
    damage=roll(n,(me->query_level()/5)+2)+((me->query_level()/10)-1);
	// atencion a los damages, para hacer danyo enviarlo
	// a spell_damage en valor positivo...
  him->spell_damage(damage,"fuego","",50,me);

  return weap_dam;
}

int unarmeds_attack(object him,object me, int n, int ws_used)
{
	int unarm_dam, damage;
	unarm_dam = me->unarmeds_attack(him, me, n, ws_used);
  if ( check_duration() )
    {
    call_out("dispell_burning_weapon",0);
    return unarm_dam;
    }
  my_player->adjust_gp(-BURNING_WEAPON_GP*1);
    tell_object(him,me->query_cap_name()+" te %^BOLD%^RED%^abrasa%^RESET%^ con sus manos.\n");
    tell_object(me,"%^BOLD%^RED%^Abrasas%^RESET%^ a "+him->query_cap_name()+" con tus manos.\n");
    tell_room(ENV(me),me->query_cap_name()+" %^BOLD%^RED%^abrasa%^RESET%^ a "+him->query_cap_name()+
                      " con sus manos.\n",({ him,me }));
    damage=roll(1,(me->query_level()/5)+2)+((me->query_level()/10)-1);

   return unarm_dam;
}

void dispell_burning_weapon()
{
   tell_object(my_player,"Tus armas vuelven a su estado normal.\n");
   tell_room(ENV(my_player),"Las armas de "+my_player->query_cap_name()+" vuelven a su estado normal.\n",my_player);
   my_player->remove_timed_property("TIME_ARMAS_ARDIENTES");
   my_player->remove_extra_look(TO);
   destruct(TO);
}

int do_say(string str)
{
   if(lower_case(str)=="no ardas") call_out("dispell_burning_weapon",1);
   return my_player->do_say(str);
}

string extra_look()
{
   return "Sus manos y armas estan envueltas en fuego.\n";
}
