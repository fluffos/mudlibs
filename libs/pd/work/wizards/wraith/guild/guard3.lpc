#include <std.h>
inherit MONSTER;
int crapgo();
void create() {

    ::create();
    set_name("Rob Zombie");
    set_short("Rob Zombie");
    set_id(({"rob zombie", "rob", "guard"}));
    set_long("This is one of the faithful guards of the Darksoul guild.");
    set_level(30);
    set_class("rogue");
    set_subclass("assassin");
    set("aggressive", 1);
    set_skill("attack", 150);
    set_skill("defense", 120);
    set_skill("double wielding", 150);
    set_skill("agility", 180);
    set_skill("murder", 180);
    set_skill("stealth", 180);
    set_spell_chance(40);
    set_skill("perception", 120);
    set_skill("knife", 150);
    set_skill("stealing", 90);
    set_gender("male" );
    set_race("raknid");
    set_heart_beat(1);
    set("guild", "darksoul");
    set_body_type("raknid");
    set_spells(({"circle", "stab"}));
   set_die((:  crapgo  :));
new("/wizards/wraith/guild/guardknife")->move(this_object());
force_me("wield knife");
}
void init() {
    object *all;
    int i;
    ::heart_beat();
    all = all_inventory(environment(this_object()));
    i = sizeof(all);
    while (i--) {
      if (all[i]->query_guild() !="none" && all[i]->query_guild() !="darksoul" && all[i]->query_guild()) {
                force_me("backstab "+all[i]->query_name());
    }
}
}
int crapgo() {
object ob;
   tell_room(environment(this_object()),"%^BOLD%^%^RED%^The guard grins at you evilly.%^RESET%^", ({ }));
  if (present("knife", this_object())) {
      ob = present("knife", this_object());
      catch ( ob->remove() );
   }

this_object()->remove();
  return 0;
}

