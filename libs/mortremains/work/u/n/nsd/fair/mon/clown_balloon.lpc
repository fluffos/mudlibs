/*
** File: clown_balloon.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "a balloons clown");

    set ("long", @EndText
This one has a wig of blue and yellow curls.
He's got a pile full of empty balloons and a
tank of hellium gas. He looks so stupid.
in his hand.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"clown"}) );
    set_size(6);
    set_name("clown");
    set("gender", "male");
    set("race", "human");
    set("prevent_summon",1);
    set("alive", 0 );
    set("damage", ({5,8}) );
    set("weapon_name", "annoying smile");
    set_verbs( ({ " sicken", "madden" }) ) ;
    set("natt",1);
    set("chat_chance", 30);
    set("chat_output", ({
      "The clown smiles a dorky way, and welcomes you.\n",
      "The clown fills some balloons with hellium gas.\n",
      "The clown makes a dog with a blue balloon.\n",
      "The clown says [to you]: here kiddie, give this doggy\n"+
      "to your mommy.\n",
      "You look at the clown and the balloon animals he's offering\n"+
      "to you, and feel like a moron.\n",
      "You wonder if there's someone who can bare so much stupidity.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("wealth", 200);
    set_level(15);
    arm("?", "?");
    wear("?", "?");
}

void die() {
    say(wrap(
	"Congratulations!!!!! You have no Idea of how many kids\n"+
	"will be smiling after this death!!!!  :D\n"));
    ::die() ;
    return ;
}
/* End of File */
