#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("test object");
    set("id", ({"object", "test object"}) );
    set_short("test object");
    set_long("This object is used for testing.");
}

void init() {
    ::init();
    add_action("create_monster", "monster");
    add_action("create_weapon", "weapon");
}

int create_monster(string str) {
    string *list;
    string *classes;
    string *races;
    string name, race;
    int i;

    mon = new("/std/monster");
    list = ({});
    list += ({"angel", "mage", "imp", "goblin", "blob", "wolf", "snake",
      "guardian", "ghost", "skeleton", "warrior", "watcher", "hunter", "drake",
      "sentry", "squire", "knight", "citizen", "elemental", "wizard", "troll"});
    name = list[random(sizeof(list))];
    mon->set_name(name);
    mon->set("id", name);
    mon->set_short(name);
    mon->set_long("This is a test monster.");
    mon->set_gender("male");
    races = ({});
    races += ({"archangel", "centaur", "demon", "dragon", "dwarf", "elf", "faerie", "ferrel", "giant", "gnoll", "gnome", "goblin", "gremlin", "half-elf", "halfling", "human", "illithid", "imp", "minotaur", "netherman", "nymph", "ogre", "orc", "raknid", "sauran", "weimic");
    race = list[random(sizeof(list))];
    mon->set_race(race);
    mon->set_body_type(race);
    i = random(100);
    mon->set_level(i);
    mon->move(environment(this_player()));
    return 1;
}

int create_weapon() {
    write("Done");
    return 1;
}

