// Paris. Jun'98

#include <spells.h>

int check_off = 0;
object my_player;

void setshadow(object ob)
{
  shadow(ob, 1);
  my_player = ob;
}

void destruct_proteccion_armas_magicas_shadow()
{
  my_player->remove_extra_look(TO);
  destruct(TO);
}

int check_duration()
{
  if (my_player->QP("propiedad_proteccion_armas_magicas")) return 0;
  if (!check_off)
  {
    if (!my_player->query_dead())
    {
      tell_object(my_player, "Eres abandonado por tu hechizo de proteccion contra armas magicas.\n");
      tell_room(ENV(my_player), my_player->QCN + " es abandonado por hechizo de proteccion contra armas magicas.\n", my_player);
    }
    tell_object(my_player, "Tu Aura %^BOLD%^RED%^Rojiza%^RESET%^ desaparece lentamente.\n");
    my_player->remove_extra_look(load_object("/std/spells/wizard/pam"));
    check_off = 1;
  }
  return 1;
}

varargs mixed move_player(string dir, string dest, mixed message, object followee, mixed enter)
{
  if (check_duration()) call_out("destruct_proteccion_armas_magicas_shadow", 0, 0);
  return my_player->move_player(dir, dest, message, followee, enter);
}

int weapon_damage(int amount, object hitter,int weapon)
{
  int i, confirmado = 0, cantidad = amount;
  object *oblist;
  object pp = previous_object();

  if(amount<0 && hitter)
  {
    if(weapon->query_enchant()>0)
    {
      cantidad=(100-my_player->QL)* amount/ 100;
      tell_room(ENV(my_player), "Tu Aura entra entra en accion y absorve parte del danyo.\n");
      tell_room(ENV(my_player), "El Aura de " + my_player->QCN + " aumenta su intensidad al absorver parte del danyo recibido.\n", my_player);
    }
  }
  if (check_duration())
    call_out("destruct_proteccion_armas_magicas_shadow", 0, 0);
  return my_player->adjust_hp(cantidad, hitter);
}

int query_proteccion_armas_magicas()
{
  return 1;
}
