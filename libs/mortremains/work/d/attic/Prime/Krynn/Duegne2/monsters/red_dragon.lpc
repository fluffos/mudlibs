#include <mudlib.h>
inherit MONSTER;

void create(){
::create();
set("short", "A Red dragon");
set("long", @Endtext
Shuruga is a massive and wise old dragon. he has seen many things
during his lifetime and been in countless battles. It will take
a mighty warrior and a lot of luck to bring him down.
Endtext
);
set("id", ({ "dragon", "draconis", "red dragon" }));
set("race", "dragon");
set_name("Shuruga");
set("gender", "male");
set_level(49);
set("size", 25);
credit(1000+random(10000));
set("damage", ({ 50, 200 }));
set("weapon_name", "claws");
set_verbs(({ "swipe", "tear", "claw", "rip", "slash", "dismemeber" }));
spell_cast("dragon",25);
}
