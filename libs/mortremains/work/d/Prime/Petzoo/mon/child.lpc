#include <mudlib.h>

#define RACES ({ "human", "eld", "half-elf", "gnome", "dwarf" })
inherit MONSTER;

void create(){
    ::create();
    set("author", "Chronos");
    switch(random(7)) {
    case 1: set("short", "a plump child"); 
	set("id", ({ "child", "plump child" }) );
	break;
    case 2: set("short", "a tall child");
	set("id", ({ "child", "tall child" }) );
	break;
    case 3: set("short", "a short child");
	set("id", ({ "child", "short child" }) );
	break;
    case 4: set("short", "a small child");
	set("id", ({ "child", "small child"}) );
	break;
    case 5: set("short", "an ugly child");
	set("id", ({ "child", "ugly child" }) );
	break;
    case 6: set("short", "a happy child" );
	set("id", ({ "child", "happy child" }) );
	break;
    default: set("short", "a child");
	set("id", ({ "child" }) );
	break;
    }
    set("long", capitalize(query("short")) +
      " who lives in the town.\n");
    set("race", RACES[random(sizeof(RACES))] );
    if (random(100)<51) set("gender", "male");
    else set("gender", "female");
    set_name("child");
    set_level(1);
    credit(query_level() * 20); 
    set_alignment("cg") ;
    set("damage", ({ 1, 4 }) );
    set("weapon_name", "fists");   // And the weapon name.
    set_verbs( ({ "swing at", "punch at", "attack", "jab at" }) );
    set("wimpy", random(100));
    set_verbs2(({ "swings at", "punches at", "attacks", "jabs at" }) );
    set("chat_chance", 9) ;
    set("chat_output", ({
      "The child complains.\n",
      "The child whines.\n",
      "The child smiles at you.\n",
      "The child laughs.\n",
      "The child sings a happy song.\n",
    }) );
    set("att_chat_output", ({
      "The child cries out in pain!\n",
      "The child cries for help!\n",
      "The child screams in anguish!\n",
      "The child sobs uncontrollably!\n",
      "The child looks pitiful.\n",
    }) );
}
