#include <spells.h>

object my_player;

void destruct_pacify_shadow()
{
  destruct(TO);
}

void setup_shadow(object ob)
{
  shadow(ob, 1);
  my_player = ob;
}

int check_duration()
{
  if (my_player->query_dead())
  {
    my_player->remove_extra_look(TO);
    return 1;
  }

  if (!(my_player->query_timed_property("pacify_on")))
  {
    tell_object(my_player,"Sientes como la calma y la paz desaparece, sintiendote muy violento.\n");
    tell_room(ENV(my_player),my_player->QCN+" comienza a cambiar de cara, la paz que antes irradiaba, ahora se convierte en pura agresividad.\n", my_player);
    my_player->remove_extra_look(TO);
    return 1;
  }
  return 0;
}

move(mixed dest, mixed messout, mixed messin)
{
  if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
  return my_player->move(dest, messout, messin);
}

int adjust_hp(int i, object hp_remover)
{
  int j;

  if (!previous_object()) return my_player->adjust_hp(i,hp_remover);
  if ( interactive(previous_object()) || (ENV(previous_object()) && interactive(ENV(previous_object())))) j=1;
  if (j)
  {
    tell_object(previous_object(),"No puedes atacar a una persona pacificada.\n");
    tell_object(my_player,"Estas pacificado, ningun jugador puede causarte danyo.\n");
    previous_object()->stop_fight(my_player);
    my_player->stop_fight(previous_object());
    if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
    return my_player->query_hp();
  }
  if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
  return my_player->adjust_hp(i, hp_remover);
}

int query_pacify_spell()
{
  return 1;
}

object *query_weapons_wielded()
{
  return ({TO});
}

int weapon_attack(object him, object me)
{
  object *ob;
  int i, dam;

  if (interactive(him))
  {
    tell_object(me,"Te sientes demasiado calmado y sereno para atacar a nadie.\n");
    tell_room(ENV(me),me->QCN+" duda y no te ataca.\n", me);
    if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
    return 0;
  }
  ob=my_player->query_weapons_wielded();
  if (!sizeof(ob))
  {
    if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
    return my_player->unarmed_attack(him, me);
  }
  for (i=0;i<sizeof(ob);i++) dam+=ob[i]->weapon_attack(him,me);
  if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
  return dam;
}

attack_by(object ob)
{
  if (interactive(ob))
  {
    tell_object(ob,my_player->QCN+" seems far too harmless to attack right now. You just can't bring yourself to do it.\n");
    ob->stop_fight(my_player);
    my_player->stop_fight(ob);
  }
  if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
  return 0;
}

attack_ob(object ob)
{
  if (interactive(ob))
  {
    tell_object(my_player,"No tienes ganas de atacar a nadie ahora. El combate ya no tiene sentido. Porque atacar si podemos ser amigos?.\n");
    ob->stop_fight(my_player);
    my_player->sTOp_fight(ob);
    if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
    return 0;
  }
  if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
  return my_player->attack_ob(ob);
}

int cast()
{
  tell_object(my_player, "No sientes la necesidad de formular hechizo. Porque no te dedicas a oler florecillas del bosque?\n");
  if (check_duration()) call_out("destruct_pacify_shadow", 0, 0);
  return 1;
}

string extra_look()
{
  return "Esta terriblemente distraido mirando las musaranyas.\n";
}

void dispell_me()
{
  tell_object(my_player,"Sientes como el hechizo de Pacificar que te afectaba ha sido destruido.\n");
  tell_room(ENV(my_player),my_player->QCN+" cambia de cara, y el aura de paz que le rodeaba se destruye.\n",my_player);
  my_player->remove_extra_look(TO);
  my_player->remove_timed_property("noguild");
  my_player->remove_timed_property("nocast");
  destruct(TO);
 }
 