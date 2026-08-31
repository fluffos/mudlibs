#include <std.h>
inherit MONSTER;

void create() {
 string *name;
 int i;

 ::create();
 
 name = ({ "a wolf", "white wolf", "fire wolf",
           "giant wolf", "huge wolf", "arctic wolf",
           "albino wolf", "forest wolf", "devil wolf",
           "baby wolf", "mystic wolf", "forbidden wolf",
           "soul wolf", "grey wolf"});

 i = random(sizeof(name));
   set_name("wolf");
   set_short(name[i]);
   set_level(i+43);
   set("aggressive", (i+25) );
   set_class("mage");
   set_subclass("necromancer");
   set_spell_chance(40);
   set_spells(({"blast"}));
   set_race("wolf");
   set_body_type("canine");
   set_gender("male");
   set_id(({ "wolf", name[i] }));
   set_long("This wolf is one of the the members of the pack, "
"that run the forbidden forest.");
}

int query(string type, string str) {
   if (type == "skill") return query_skill(str);
   if (type == "stats") return query_stats(str);
   return ::query(type, str);
}

int query_stats(string str) {
   object env;
   env = environment(this_object());
   if (!env) return ::query_stats(str);
   if (present("wolf master", env))
     return ::query_stats(str) * 2;
   return ::query_stats(str);
}

int query_skill(string str) {
   object env;
   env = environment(this_object());
   if (!env) return ::query_skill(str);
   if (present("wolf master", env))
     return ::query_skill(str) * 2;
   return ::query_skill(str);
}

int query_skill_bonus(string str)
{
 return query_skill(str);
}
int query_base_skill(string str)
{
 return query_skill(str);
}
