#include <std.h>
#include <hermes.h>
inherit MONSTER;
void create() 
{
        ::create();
        set_name("ilithyd");
        set("short", "Ilithyd: The Demon Hunter (Mark 2)");
        set("long", "The Archangel has perhaps found peace in death. Taken
back to the land of the mortals by Hermes, he now guards his domain. He is
content in his new life of peace and solitude that lets him reflect and
attone for his past sins.");
        set("id", 
                ({"monster","demon hunter","archangel","angel","ilithyd"})
        );
        set("race", "archangel");
        set_body_type("archangel");
        set_gender("male");
                set_class("wanderer");
        set_subclass("swashbuckler");
        set_spell_chance(40);
        set_spells( ({"bladedance", "trip", "disarm"}) );
       
new("/wizards/hermes/distopia/weapon/warblade")->move(this_object());
       
new("/wizards/hermes/distopia/weapon/warblade")->move(this_object());
        this_object()->force_me("wield warblade");
        this_object()->force_me("wield warblade 2");
        set_level(200);
                set_exp(0);
} 
void init()
{
 ::init();
 add_action("fBuy", "buy");
}
int fBuy(string str) {
  int numba;
  object oil;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
 
  if(str=="ambrosia") {
    if(this_player()->query_money("gold") < 0 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", 0);
    write("Ilithyd gives you a vial of ambrosia");
    say("Ilithyd hands "+this_player()->query_cap_name()+" a vial of
ambrosia.");
    new("/wizards/hermes/ambrosia")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "ambrosia") {
    write("Buy what?\n");
    return 1;
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(numba > 1000) {
    this_object()->force_me("say I dont have that many right now!");
    return 1;
  }
  if(this_player()->query_money("gold") < 0*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", 0*numba);
  write("Ilithyd hands you "+(string)numba+" vials of ambrosia.");
  say("Ilithyd hands "+this_player()->query_cap_name()+" "+(string)numba+"
vials of ambrosia.");
  while(numba > 0) {
    oil = new("/wizards/hermes/ambrosia");
    if(numba >= 15)
      oil->set_uses(15);
    else
      oil->set_uses(numba);
    numba -= 15;
    oil->move(this_player());
  } 
  return 1;
}
