/*
** File: clown_jack.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("prevent_summon" , 1);
    set("author" , "herself");
    set("short" , "Mermaid");

    set ("long", @EndText
The mermaid was made of stone, but she
has come to life. Her long brown hair
curls down over her shoulders. The blue
cut glass on her tail has turned into
shimmering blue scales. She looks a little
bit sad. 
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"mermaid"}) );
    set_size(9);
    set_name("mermaid");
    set("gender" , "female");
    set("race" , "fish");
    set("undead", 1);
    set("damage", ({8,16}) );
    set("weapon_name" , "tail");
    set("damage_type", "bludgeoning");
    set_verbs( ({"hit" , "slap" , "smack at" , "whip"}) );
    set("natt" , 1);
    set("chat_chance", 0);
    set("chat_output", ({
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Mermaid says [to you]: What did i do to deserve this? \n",
      "Mermaid emits a horrible high-pitched squeal. \n",
    }) );
    set("stat/strength", 16);
    set("wealth" , 620);
    set_level(20);
    arm("?", "?");
    wear("?", "?");
}
void die() {
    say(wrap(
	"The life source drains from the mermaid's body... She lets out \n"+
	"one last horrible scream... then flops on the ground, dead.\n"));
    ::die() ;
    return 1;
}
/* End of File */
