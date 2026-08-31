#include <std.h>
inherit MONSTER;
object tp;
object all;
void create() {
 ::create();
   set_name("Rob Zombie");
   set_short("Rob Zombie");
   set_id(({"rob zombie", "rob", "guard"}));
   set_long("This is one of the faithful guards of the Darksoul guild.");
   set_level(70);
   set_class("rogue");
   set_subclass("assassin");
   set("aggressive", 1);
   set_skill("attack", 350);
   set_skill("defense", 280);
   set_skill("double wielding", 350);
   set_skill("agility", 420);
   set_skill("murder", 420);
   set_skill("stealth", 420);
   set_spell_chance(40);
   set_skill("perception", 280);
   set_skill("knife", 350);
   set_skill("stealing", 210);
   set_gender("male" );
   set_race("raknid");
   set_heart_beat(1);
   set("guild", "darksoul");
   set_body_type("raknid");
   set_spells(({"circle", "stab"}));


new("/d/guilds/darksoul/dknife")->move(this_object());
force_me("wield dagger");

new("/d/guilds/darksoul/dknife")->move(this_object());
force_me("wield dagger");

new("/d/guilds/darksoul/dknife")->move(this_object());
force_me("wield dagger");

new("/d/guilds/darksoul/dknife")->move(this_object());
force_me("wield dagger");

}
void init() {
 ::init();
if(this_player()->query_guild()!="darksoul" && this_player()->is_player()) {
  tp = this_player();
  all = this_player();
  call_out("member", 1, tp);
  call_out("kill", 1, all);
  }
}

int member(object tp) {
this_object()->force_me("say Intruder you shall die!");
this_object()->force_me("darksoul INTRUDERS!");
}

int kill(object all) {
   int i;
   ::heart_beat();
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player())
        force_me("backstab "+all[i]->query_name());
   return 1;
   }
}
