
#include <std.h>
#include <id4.h>

inherit MONSTER;

string person;
string *people;
int speech = -1;
int wait = 0;
void wait();


string *sentences = ({
  "emote breathes a blast of ice to dispell the remaining flame!",
  "emote looks around.",
  "say Thank you so much for all your help.",
  "say The ogres sent their mages after us while we slept, so we could not "
    "defend ourselves.",
  "say Their leader said he would ransom us back to our den... eventually.",
  "emote shivers.",
  "say I have a special gift for the one who broke the spell over me.",
  "",
  "",
  "say I wish that I had more gifts, but the least I can do is heal "
    "all of those who helped.",
  "",
  "say Come and visit me in the dragon lands in a month's time and I may "
    "be able to do more for you all!",
  "",
});

void set_person(string p) { person = p; }
void set_people(string *p) { people = p; }
void start() { speech=0; }

void create() {
  ::create();
  set_property("passive", 1);
  set_name("blue dragon");
  set_id( ({ "dragon" }) );
  set_short("a blue dragon");
  set_long(
    "This adolescent blue dragon is truly massive. She is shorter than "
    "a grown man, but twice as wide and four times the weight. She flutters "
    "her tiny wings as she talks."
  );
  set_gender("female");
  set_race("dragon");
  set_class("dragon");
  set_subclass("blue");
  set_body_type("dragon");
  set_alignment(500);
  set_level(15);
}

void heart_beat() {
  string name;
  object pl;
  object ob;
  ::heart_beat();
  if (!this_object()) return;
  if (!environment()) return;
  name = person;
  pl = present(name, environment());

  if (wait != 0) {
    if (pl) {
      speech = 7;
      wait = 0;
      command("say Oh! "+capitalize(pl->query_subjective())+" has returned!");
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
    command("say "+capitalize(name)+", you showed true courage and fortitude.");
    break;

    case 8:
    ob = new(ITEMS+"token");
    if (!ob) pl->set_property("dragon_token", "blue");
    else {
      ob->set_owner(name);
      ob->set_color("blue");
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

    case 10:
    foreach (string pname in people) {
      object who;
      if (who = find_player(pname)) {
	who->set_hp(who->query_max_hp());
	foreach (string l in who->query_limbs())
	  who->heal_limb(l, 5000);
	message("magic", "%^BOLD%^%^WHITE%^A healing glow surrounds you "
	                 "and heals your injuries.%^RESET%^", who);
      }
    }
    break;

    case 12:
    command("emote bows her head and sets off down the tunnel.");
	load_object(ID4D)->add_done();
    remove();
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
  command("say Where is "+capitalize(person)+"? "
	  "I must talk with my rescuer!");
}


