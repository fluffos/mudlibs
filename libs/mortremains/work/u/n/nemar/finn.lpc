/*
** File: finn.c
** Date: 2-14-00
** Other comments: last change made
*/

#include <mudlib.h>

inherit MONSTER;

void create () {
  ::create();
  seteuid(getuid());
  enable_commands();

  set("author", "nemar");
  set("short", "Finn the Guardian");
  set("long", @EndText
This is Finn.  She is a HammaDryad.  Her green tint does not subtract the 
beauty of the woman you see before you.  She is only about 4'5" and very
lithe.  You have heard stories before about Dryad's, but never in you life
did you actually expect to see one for yourself.  She looks at you and smiles
warmly.  You do not feel afraid.
EndText
  );
  set("id", ({ "Finn", "finn", "dryad", "hammadryad", "HammaDryad" }) );
  set_size(5);
  set_name("Finn");
  set("gender", "female");
  set("race", "hammadryad");
  set("alive", 1);
  set("damage", ({5, 40}) );
  set("weapon_name", "entangle");
  set_verbs( ({ "strikes", "slashes", "entangles"}) );
  set("natt", 2);
  set("chat_chance", 20);
  set("chat_output", ({
    "Finn looks you up and down and smiles\n",
    "Finn says:  How wonderful.  A new person to visit!  The last one left suddenly.\n",
    "Finn says:  Will you stay with me?\n",
    "Finn smiles at you warmly.\n",
  }) );
  set("att_chat_output", ({
    "Finn screams at you in hatred.\n",
    "Finn screams at you:  How dare you attack me!  After all I was willing to do for you!\n",
    "Finn screams:  How dare you mare my beauty!\n",
  }) );
  set("wealth", 50);
  set("prevent_summon", 1);
  set_level(25);
}
/* End of File */
