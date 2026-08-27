#include "library.h"
inherit "/obj/monster";
 
void setup() {
  //add_attack("hands", 0, 50, 200, 0, 10, "blunt-hands");
  //add_attack("feet", 0, 50, 200, 0, 0, "blunt-feet");
  set_name("karon");
  add_alias("splatter");
  set_main_plural("fighters");
  set_short("Karon");
  add_property("determinate", "");
  set_long(
"This is Karon the splatter.  A splatter is sort of like a bouncer, but "+
"an improved and souped up version.  He is here to stop trouble and loves "+
"breaking up opponents involved in fights.\n");
  set_race("human");
  set_gender(1);
  set_class("fighter");
  set_level(60);
  set_wimpy(0); 
  set_random_stats(6,28);
  set_str(28);
  set_con(28);
  call_out("remove_attack",0,"standard");
  set_join_fights();
  set_join_fight_mess("Karon shouts: STOP THAT FIGHT!\n");
  set_throw_out(50,70,"$mcname$ chucks you bodily out of the room.\n",
                  "$mcname$ chucks $ocname$ out of the room.\n");
  load_chat(1,({
    1, ":eyes you over.",
    1, "'No trouble please.",
    1, ":clenches his fist.",
    1, "'Let's have no fights in here."
  }));
  load_a_chat(30,({
    1, "'Stop that fight.",
    1, "'Next one to break a chair gets it.",
    1, "'You're going to be billed for this."
  }));
  clone_object("/items/weapon/club")->move(this_object());
  command("equip");
}

int heart_beat() {
  string s1, s2;
  object *atts;

  atts = query_attacker_list();
  switch(sizeof(atts)) {
    case 1:
      s1 = (string)atts[0]->query_name();
      if (s1 == "wulfgar" || s1 == "garth") {
        stop_fight(atts[0]);
        atts[0]->stop_fight(this_object());
      }
      break;
    case 2:
      s1 = (string)atts[0]->query_name();
      s2 = (string)atts[1]->query_name();
      if((s1=="wulfgar" || s1 == "garth") && (s2=="wulfgar" || s2=="garth"))
      {
        stop_fight(atts[0]);
        atts[0]->stop_fight(this_object());
        stop_fight(atts[1]);
        atts[1]->stop_fight(this_object());
      }
      break;
    default:
      break;
  }
  ::heart_beat();
}

int second_life() {
  int loop;
  object *atts;

  atts = query_attacker_list();
  for(loop = 0; loop < sizeof(atts); loop++)
    if(interactive(atts[loop]))
      LIBRARY->set_quest(atts[loop]->query_name(), "karon");
  return 0;
}

void event_death(object dier) {
  call_out("get_from_corpse", 0);
}

void get_from_corpse() {
  command("'Ahhh!  These will make good trophies for the pub.");
  command("get all from corpses");
}
