
#include <std.h>
#include <id4.h>

inherit MONSTER;

string find_most_hits();

void wait();

string *people = ({});
int person = 0;
int speech = -1;
int wait = 0;

string *sentences = ({
  "emote breaks out of the ice!",
  "emote roars loudly!",
  "say I thank you for freeing me.",
  "emote bows his head.",
  "say To the one who showed the most strength in breaking the ice...",
  "",
  "say I'd like to give you a gift for your help.",
  "",
  "say Come and find me in the dragon lands in a month's time.",
  "",
});

void set_people(string *p) { people = p; }
void start() { speech=0; }

void create() {
  ::create();
  set_property("passive", 1);
  set_name("red dragon");
  set_id( ({ "dragon" }) );
  set_short("a red dragon");
  set_long(
    "This small red dragon is as tall as an ogre, and twice as big."
  );
  set_gender("male");
  set_race("dragon");
  set_class("dragon");
  set_subclass("red");
  set_body_type("dragon");
  set_alignment(0);
  set_level(15);
}

void heart_beat() {
  string name;
  object pl;
  object ob;
  ::heart_beat();
  if (!this_object()) return;
  if (!environment()) return;
  name = find_most_hits();
  pl = present(name, environment());

  if (wait != 0) {
    if (pl) {
      speech = 5;
      wait = 0;
      command("say Ah! There "+pl->query_subjective()+" is!");
    }
    else if (wait < time()) {
      wait();
      return;
    }
  }
  if (speech == -1) return;
  switch (speech) {
    case 5:
    if (!pl) {
      wait();
      return;
    }
    command("say "+capitalize(name)+", you did the most to free me.");
    break;

    case 7:
    ob = new(ITEMS+"token");
    if (!ob) pl->set_property("dragon_token", "red");
    else {
      ob->set_owner(name);
      ob->set_color("red");
      if (ob->move(pl)) ob->move(environment());
      message("info", query_cap_name()+" gives "+
	indefinite_article(ob->query_short())+
	" to "+capitalize(name)+".",
	environment(), pl);
      message("info", query_cap_name()+" gives you "+
	indefinite_article(ob->query_short())+
	".", pl);
    }
    break;

    case 9:
    command("emote rears, roars, and dashes out of the tunnels.");
    remove();
	load_object(ID4D)->add_done();
    return;

    default:
    command(sentences[speech]);
  }
  speech++;
  if (speech >= sizeof(sentences)) speech = -1;
}

void wait() {
  string name = find_most_hits();
  wait = time()+200;
  speech = -1;
  command("say Where is "+capitalize(name)+"? "
	  "I must talk with my rescuer!");
}

string find_most_hits() {
  object p;
  object *tokens = children(ITEMS+"token");
  person = 0;
  while (!(p = find_player(people[person])) ||
         p->query_race() == "dragon" ||
         (sizeof(tokens) && sizeof(filter(tokens, (: $1->query_owner() == $2 :), p))) )
    person++;
  return people[person];
}

