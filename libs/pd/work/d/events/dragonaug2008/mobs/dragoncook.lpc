
#include <std.h>

inherit MONSTER;

int do_cook(string);

void create() {
  ::create();
  set_name("dragon cook");
  set_id( ({ "dragon", "red dragon" }) );
  set_short("a large red dragon");
  set_long(
    "He is huge and red. He spends his time selling his greatest asset: "
    "his fire breath. He can <cook food> for you, for a fee."
  );
  set_gender("male");
  set_level(70);
  set_race("dragon");
  set_body_type("dragon");
  set_class("dragon");
  set_subclass("red");
  set_skill("breath", 400);
  set_spells( ({ "fireshot", "fireshot", "pyrestrike", "claw", "dragonfury", }) );
  set_spell_chance(35);
}

void init() {
  add_action("do_cook", "cook");
}

int do_cook(string str) {
  object tp = this_player();
  string cap = tp->query_cap_name();
  object ob;
  int price;
  if (sizeof(query_attackers()))
    command("emote roars in fury!");
  else if (!str)
    command("say What shall I cook, "+cap+"?");
  else if (!(ob = present(str, tp)))
    command("say You don't have that, "+cap+".");
  else if (!ob->is_food())
    command("say That is not food, "+cap+".");
  else if (ob->query_property("cooked"))
    command("say That has already been cooked, "+cap+".");
  else if (tp->query_money("platinum") < (price = ob->query_strength()/3))
    command("say That costs "+price+" platinum coins, "+cap+".");
  else {
    command("emote takes "+definite_article(strip_color(ob->query_short()))+
      " and breathes a blast of %^BOLD%^%^RED%^fire%^RESET%^ at it, cooking it!");
    tp->add_money("platinum", -price);
    ob->set_strength(ob->query_strength()*160/100);
    ob->set_short(ob->query_short() + " (cooked)");
    ob->set_id( ob->query_id() + ({ "cooked food", "cooked "+ob->query_name() }) );
    ob->set_property("cooked", 1);
  }
  return 1;
}
