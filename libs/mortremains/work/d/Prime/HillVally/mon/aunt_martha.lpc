/*
** Aunt Martha, need I say more?
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nightmask");
    set("prevent_summon", 1);
    set("short", "Aunt Martha");
    set ("long", @EndText
This is Aunt Martha, she is a kindly old woman who owns this bakery.
She smiles and greets you, she reminds you of your grandmother more
than your aunt.
EndText
    );
    set("id", ({ "aunt martha", "aunt", "martha", "woman" }) );
    set_size(4);
    set_name("aunt martha");
    set("race", "human");
    set("gender", "female");
    set("damage", ({ 1,4 }) );
    set("weapon_name", "hands");
    set_verbs( ({ "swing", "slap", "punch" }) );
    set_verbs2( ({ "swings at", "slaps", "punches" }) );
    set("natt", 1);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
      "Aunt Martha yells: Why you little whipper snapper.\n",
      "Aunt Martha yells: You need a good spanking!\n",
    }) );
    set_level(15);
}
