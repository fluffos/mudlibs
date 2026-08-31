
#include <std.h>
#include <id4.h>

inherit MONSTER;

void wait();

object person;
string pname;
int speech = -1;
int wait = 0;

string *sentences = ({
  "emote looks down quitely.",
  "say You have nearly sacrificed yourself for me.",
  "emote gazes upward.",
  "emote prays.",
  "say Please, restore he who has saved me.",
  "say Regardless of the past, this selfless act deserves some recompense.",
  "emote closes his eyes and the room begins to glow.",
  "",
  "say I am sorry to have been so much trouble.",
  "say Please, take this gift from me.",
  "",
  "say If you would like, visit me in the dragon lands a month hence.",
  "emote bows deeply.",
  "",
});

void set_person(object p) { person = p; pname = person->query_cap_name(); }
void start() { speech=0; }

void create() {
  ::create();
  set_property("passive", 1);
  set_name("white dragon");
  set_id( ({ "dragon" }) );
  set_short("a white dragon");
  set_long(
    "This white dragon is rather small, with deep black eyes and a "
    "solemn look."
  );
  set_gender("male");
  set_race("dragon");
  set_class("dragon");
  set_subclass("white");
  set_body_type("dragon");
  set_alignment(0);
  set_level(15);
}

void heart_beat() {
  string name;
  object pl;
  object ob;
  object env;
  ::heart_beat();
  if (!this_object()) return;
  env = environment();
  if (!env) return;
  name = person->query_cap_name();
  pl = present(person, environment());

  if (wait != 0) {
    if (pl) {
      speech = 7;
      wait = 0;
      command("say I am glad you have returned, "+name+".");
    }
    else if (wait < time()) {
      wait();
      return;
    }
  }
  if (speech == -1) return;
  switch (speech) {
    case 7:
    if (!pl) {
      wait();
      return;
    }
    message("emote", name+" slowly gets up off the ground.", env, pl);
    pl->set_hp(pl->query_max_hp()/2);
    pl->set_paralyzed(4, "You slowly get up off the ground.");
    pl->remove_paralyzed();
    break;

    case 10:
    ob = new(ITEMS+"token");
    if (!ob) pl->set_property("dragon_token", "white");
    else {
      ob->set_owner(name);
      ob->set_color("white");
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

    case 13:
    command("emote steps quietly out of the tunnel.");
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
  wait = time()+200;
  speech = -1;
  command("say Where is "+capitalize(pname)+"? "
	  "I must talk with my rescuer!");
}


