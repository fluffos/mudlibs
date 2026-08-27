// Traducido por Lummen 5-9-97

#include <spells.h>
#define	BONUS	MAX(my_player->query_sphere("necromancia"),my_player->query_sphere("necromantica"))
#define	MIN_AC	-100

int check_off=0;
object my_player;

void destruct_spirit_armour_shadow()
{
  if (!check_off)
  {
    if (!my_player->query_dead())
    {
      my_player->spell_damage(roll(2,4),"mal","",50,my_player);
      tell_object(my_player,"Tu aura vital se evapora provocandote danyos.\n");
    }
    tell_room(ENV(my_player),my_player->QCN+" es abandonado por su aura vital.\n",my_player);
    tell_object(my_player,"Tu armadura espiritual se disipa lentamente.\n");
    my_player->remove_extra_look(MAGE_ROOT+"armadura_espiritu");
  }
  destruct(TO);
}

void setshadow(object ob,int i)
{
  shadow(ob,1);
  my_player=ob;
  my_player->add_extra_look(MAGE_ROOT+"armadura_espiritu");
  my_player->ATP("spirit_armour_on",1,i);
}

void dispell_me()
{
  destruct_spirit_armour_shadow();
}

int check_duration()
{
  return (my_player->query_dead() || !my_player->QP("spirit_armour_on"));
}

varargs mixed move_player(string dir, string dest, mixed message,object followee, mixed enter )
{
  if (check_duration()) call_out("destruct_spirit_armour_shadow",1);
  return my_player->move_player(dir,dest,message,followee,enter);
}

status wear_ob(object ob)
{
  tell_object(my_player,"Tu aura vital es suficiente para protegerte.\n");
  if (check_duration()) call_out("destruct_spirit_armour_shadow",1);
}
 
int do_wear(string str)
{
  tell_object(my_player,"Tu aura vital es suficiente para protegerte.\n");
  if (check_duration()) call_out("destruct_spirit_armour_shadow",1);
  return 0;
}

int query_total_ac()
{
  int ac=100-my_player->query_body_ac()-10*BONUS-my_player->QL*BONUS-my_player->query_spell_bonus();
  if (check_duration()) call_out("destruct_spirit_armour_shadow",1);
  return ac;
}

int query_spirit_armour_spell()
{
  if (check_duration()) call_out("destruct_spirit_armour_shadow",1);
  return 1;
}
