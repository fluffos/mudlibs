#include <std.h>
#define STONEPATH "/wizards/daboura/test/stone"
inherit MONSTER;

void create()
{
 ::create();
 set_name("Pelgadiss");
 set_short("Pelgadiss, the apprentice of Zatrick");
 set_long("Pelgadiss is busily working at putting all of his magic powers into the stones of the shop, under the strict watch of Zatrick.");
 set_race("human");
 set_gender("male");
 set_id( ({ "pelgadiss", "apprentice" }) );
  set_body_type("human");
}

void init()

{
 ::init();
 add_action("fBuy", "buy");
 set_heart_beat(10);
}

int fBuy(string str) {
  int numba;
  if(!str) {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
  }
  if(str=="stone" || str=="magical stone") {
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Pelgadiss hands you a magical stone.");
    say ("Pelgadiss hands "+this_player()->query_cap_name()+" a magical
stone.");
    new(STONEPATH)->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {

    this_object()->force_me("say I dont have that for sale.");
    return 1;
  }
  if(str != "stones" && str != "magical stones") {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(this_player()->query_money("gold") <30*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -30*numba);
  write("Pelgadiss hands you "+(string)numba+" magical stones.");
  say("Pelgadiss hands "+this_player()->query_cap_name()+" "+(string)numba+"
magical stones.");
  while(numba--)
    new(STONEPATH)->move(this_player());
  return 1;

}
