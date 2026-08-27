#include <spells.h>

object my_player;

void attack_ob(object ob)
{
}

void add_protector(object ob)
{
}

void add_protecting(object ob)
{
}

void do_protect(string str)
{
  notify_fail("No puedes proteger a nadie convertido en piedra!\n");
}

void destruct_stone_shadow()
{
  destruct(TO);
}

void setup_shadow(object ob) 
{
  if (!ob->query_stone_spell())
  {
    shadow(ob,1);
    my_player = ob;
    my_player->add_static_property("pacify_on",1);
    my_player->add_static_property("nocast",1);
    my_player->add_static_property("noguild",1);
  }
  else destruct_stone_shadow();
}

varargs mixed move_player(string dir, string dest, mixed message, object followee, mixed enter)
{
  if (!my_player->QP("stoned")) call_out("dispell_stoned",0,0);
  if (!random(30))
  {
    tell_object(my_player,"Consigues moverte y con un gran esfuerzo.\n");
    return my_player->move_player(dir, dest, message, followee, enter);
  }
  tell_object(my_player,"A persar del esfuerzo no consigues moverte.\n");
  return 1;
}

string query_short()
{
  return "Una estatua de "+my_player->query_short();
}

string short()
{
  return "Una estatua de "+my_player->query_short();
}

int query_stone_shadow() { return 1; }
int query_stone_spell()
{
  return 1;
}

int unarmed_attack(object him,object me)
{
  return 0;
}

int weapon_attack(object him, object me)
{
  return 0;
}

int query_gender()
{
  return 0;
}

string long(int dark)
{
  return "Parece ser la estatua viviente de "+my_player->long(dark);
}

int adjust_hp(int hp, object doer)
{
  if (hp<0) return my_player->adjust_hp(hp/20,doer);
  else return my_player->adjust_hp(hp/5,doer);
}

void attack_by(object ob)
{
  if (ob)
  {
    ob->stop_fight(TO);
    ob->stop_fight(my_player);
    my_player->stop_fight(ob);
  }
}

void dispell_stoned()
{
  int i;
  object *olist;

  if (my_player)
  {
    my_player->remove_static_property("pacify_on");
    my_player->remove_static_property("noguild");
    my_player->remove_static_property("nocast");
    olist=find_match("piedra", my_player);
    for (i=0;i<sizeof(olist);i++)
      if (olist[i] && olist[i]->query_name()=="piedra") olist[i]->dest_me();
    tell_object(my_player,"Poco a poco tu piel revierte a su forma original de nuevo.\n");
    tell_room(ENV(my_player), my_player->QCN+" lentamente se raja y se convierte a carne.\n",my_player);
  }
  destruct(TO);
}

int give(string str, string verb, object *bing, string bing2, int blue)
{
  notify_fail("No puedes darle nada a nadie convertido en piedra.\n");
  return 0;
}

int take(string str, string verb, object *bing, string bing2, int blue)
{
   notify_fail("No puedes coger nada convertido en piedra.\n");
   return 0;
}

int drop_ob(string str)
{
   notify_fail("No puedes dejar nada convertido en piedra.\n");
   return 0;
} 
