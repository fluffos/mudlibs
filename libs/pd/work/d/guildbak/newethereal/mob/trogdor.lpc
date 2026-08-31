#include <std.h>
#include <daemons.h>
#include <money.h>
#include <guild.h>
#include "ether.h"
inherit MONSTER;

void init() {
    ::init();
    add_action("cmd_buy", "buy");
    add_action("cmd_list", "list");
}
void create() {
 ::create();
   set_name("Trogdor");
   set_id(({ "trogdor","dragon" }));
   set_short("%^RESET%^%^GREEN%^T%^BOLD%^r%^RESET%^%^GREEN%^o%^BOLD%^g%^RESET%^%^GREEN%^d%^BOLD%^o%^RESET%^%^GREEN%^r%^RESET%^");
   set_long( "%^GREEN%^This is Trogdor, the mighty dragon. For some strange reason, the Ethereal chose him to be their petshop keeper. Be careful, or you will be %^BOLD%^burninated%^RESET%^%^GREEN%^. Look at the sign for instructions!%^RESET%^" );
   set_race("dragon");
   set_body_type("dragon");
}
int cmd_list() {
  write("You need to look at the sign for pricing.\n");
  return 1;
}
int cmd_buy(string str) {
  if (!str) return 0;
    switch (str) {
//      pos = GUILD_D->query_actual_position(this_player()->query_name());
      case "panda":
//	if (!pos || pos != "leader") {
//	    this_object()->force_me("say You are not a leader of Ethereal.");
//	    return 1;
//	}
        if(this_player()->query_money("gold") < 1000) {
            this_object()->force_me("say You don't have that much money!");
            return 1;
        }
	this_player()->add_money("gold", -1000);
	write("Trogdor releases an Elite Panda.\n");
	new(MOB"panda")->move(environment(this_player()));
	this_player()->force_me("follow allow "+this_player()->query_name());
	return 1;
      case "cat":
//	if (!pos || pos != "council" || pos != "leader") {
//	    this_object()->force_me("say You are not a council member of Ethereal.");
//	   return 1;
//	}
        if(this_player()->query_money("gold") < 900) {
            this_object()->force_me("say You don't have that much money!");
            return 1;
        }
	this_player()->add_money("gold", -900);
	write("Trogdor releases a Council Cat.\n");
	new(MOB"cat")->move(environment(this_player()));
	this_player()->force_me("follow allow "+this_player()->query_name());
	return 1;
      case "rabbit":
//	if (!pos || pos != "member" || pos != "leader") {
//	    this_object()->force_me("say You are not a full member Ethereal.");
//	    return 1;
//	}
        if(this_player()->query_money("gold") < 800) {
            this_object()->force_me("say You don't have that much money!");
            return 1;
        }
	this_player()->add_money("gold", -800);
	write("Trogdor releases a Bunny Rabbit.\n");
	new(MOB"rabbit")->move(environment(this_player()));
	this_player()->force_me("follow allow "+this_player()->query_name());
	return 1;
      case "cow":
//	if (!pos || pos != "squire" || pos != "leader") {
//	    this_object()->force_me("say You are not a squire of Ethereal.");
//	    return 1;
//	}
        if(this_player()->query_money("gold") < 700) {
            this_object()->force_me("say You don't have that much money!");
            return 1;
        }
	this_player()->add_money("gold", -700);
	write("Trogdor releases a Baby Cow.\n");
	new(MOB"cow")->move(environment(this_player()));
	this_player()->force_me("follow allow "+this_player()->query_name());
	return 1;
  }
  this_object()->force_me("say I dont have that for sale!");
  return 1;
}
