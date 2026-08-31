#include <std.h>
#include <zexor.h>
inherit MONSTER;
int KillMe();

create() {
   ::create();
   set_name("elemental");
   set_short("A forest elemental");
   set_long("This is a elemental which seems to be made out "
       "of leaves, branches, thorns, and brambles.");
   set_level(30);
   set_class("mage");
   set_subclass("druid");
   set_body_type("human");
   set_race("elemental");
   set_spells(({"thornwrack"}));
   set_spell_chance(10);
   set_id(({"elemental", "forest elemental", "monster"}));
   new(WEA"staff")->move(this_object());
   command("wield staff");
   new(ARM"thorns")->move(this_object());
   set_die((: KillMe() :));
}

  int KillMe() {
     object ob;
     tell_room(environment(this_object()),
     "The elemental dies, oh wait! It was a goblin dressed up like an elemental", ({ }));
    if (present("staff", this_object())) {
        ob = present("staff", this_object());
        catch ( ob->remove() );
     }
     catch ( this_object()->remove() );
     return 1;
  }
