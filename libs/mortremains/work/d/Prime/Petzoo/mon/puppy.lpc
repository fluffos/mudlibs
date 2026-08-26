#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a soft puppy");
    set("long", "This is a cute little puppy.\n");
    set("id", ({ "#PUPPY#", "#BLAH#", "puppy" }) );
    set("race", "dog");
    set_name("puppy");
    set_level(1);
    set_alignment("cg") ;
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "teeth");
    set("chat_chance", 6) ;
    set("chat_output", ({
      "The puppy barks playfully!\n",
      "The puppy jumps on your leg, but you kick it off.\n",
      "The puppy wets the ground.\n",
      "The puppy relieves himself.\n",
      "The puppy chases his tail.\n",
    }) );
    set("att_chat_output", ({ 
      "The puppy barks angrily!\n",
      "The puppy growls!\n",
    }) );
    set_verbs( ({ "chomp at", "attack", "bite at" }) );
    credit(query_level() * 20); 
}

