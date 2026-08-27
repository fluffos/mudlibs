#include <spells.h>
  
object my_player;

void setup_shadow(object ob,int amount)
{
  shadow(ob,1);
  my_player=ob;
}

void destruct_barkskin_shadow()
{
  tell_object(my_player,"Your skin reverts to normal as the Barkskin wears off.\n");
  tell_room(ENV(my_player),my_player->QCN+"'s skin reverts to normal.\n",my_player);
  my_player->remove_extra_look(TO);
  if (my_player->query_tmp_dex()<0) my_player->adjust_tmp_dex(1);
  destruct(TO);
}

int check_duration()
{
  return !my_player->QP("barkskin_on");
}

int query_skin_spell()
{
  return 1;
}

int query_mirror_spell()
{
  return 1;
}

int query_armor_spell()
{
  return 1;
}

int adjust_hp(int amount, object hitter)
{
  if (amount>0) return my_player->adjust_hp(amount,hitter);
  if (hitter) tell_object(hitter,"Your attack glances off of "+my_player->QCN+"'s tough, bark-like skin.\n");
  tell_object(my_player,"The attack glances off your Barkskin.\n");
  tell_room(ENV(my_player),"The attack glances off of "+my_player->QCN+"'s tough, bark-like skin.\n",({hitter,my_player}));
  if (check_duration()) call_out("destruct_barkskin_shadow",0,0);
  return my_player->adjust_hp(amount/2,hitter);
}

int set_hp(int amount, object hitter)
{
  if (amount>=my_player->query_hp()) return my_player->set_hp(amount,hitter);
  if (hitter) tell_object(hitter,"Your attack glances off of "+my_player->QCN+"'s bark-like skin.\n");
  tell_object(my_player,"The attack glances off your Barkskin.\n");
  tell_room(ENV(my_player),"The attack glances off of "+my_player->QCN+"'s bark-like skin.\n",({hitter,my_player}));
  if (check_duration()) call_out("destruct_barkskin_shadow", 0, 0);
  return my_player->adjust_hp((my_player->query_hp()-amount)/2);
}

string extra_look()
{
  return "Has strange skin that looks like tree bark.\n";
}

void dispell_me()
{
  my_player->remove_timed_property("barkskin_on");
  tell_object(my_player,"Your skin reverts to normal as the magic is destroyed.\n");
  tell_room(ENV(my_player),my_player->QCN+"'s skin reverts to normal as the magic is destroyed.\n",my_player);
  my_player->remove_extra_look(TO);
  if (my_player->query_tmp_dex()<0) my_player->adjust_tmp_dex(1);
  destruct(TO);
}
