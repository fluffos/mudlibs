#include <std.h>
#include <arlon2.h>

inherit MONSTER;

void create() {
::create();
    set_name("sealion");
    set_short("a large, leathery sea lion");
    set_long("This sea lion is truly quite large, he seems to have some giant blood in him.  His entire body is covered in a leathery black skin.  He looks a bit like a blob with a head, 4 flippers, and a tail.  He has very sharp looking teeth.");
    set_id(({"sea lion", "sealion", "lion", "large sea lion"}));
    set_level(6+random(3));
    set_race("sealion");
    set_body_type("seamonster");
    set_gender("male");
    set_class("animal");
    set_subclass("strong");
    add_money("gold", 5+random(50));
    set_spell_chance(10);   
    set_spells(({"jab"}));   
    set_emotes(1,({ "The sea lion makes a disturbing loud noise." }),0);
}


