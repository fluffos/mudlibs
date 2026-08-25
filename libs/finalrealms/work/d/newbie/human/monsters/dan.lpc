#include "path.h"

#include "standard.h";
inherit "/obj/monster";

void setup()
{
    set_name("pirate dan");
    set_short("Pirate Dan");
   add_alias("dan");
   add_alias("pirate");
    set_gender(1);
    set_level(12+random(4));
    set_random_stats(15,5);
    set_str(22);
    set_long("The first thing you notice is the eyepatch, then the scars "
    "then you notice that he seems crooked, as though his entire skeleton "
    "has been jumped up and down on heavilly. He still looks strong though "
    "and it would be unwise to challenge him. He seems to be staring out "
    "somewhere...., it could be the horizon, then again it could be the past "
    "thats he's looking at. "
    "\n");
    load_chat(75, ({
        1,({
        "'Well $lcname$, you look as happy here as I. ",
        "'I wouldn't mind getting to Hoerk one day. ",
        ":winks",
        "'Only brew pisswater beer here, and I miss Drakkars Tavern. ",
        "'Drakkars Tavern, thats where I started the adventures that ended me career. ",
        "'Many an adventure has started at Drakkars, need to be high level though. ",
        }),
        1,"'Nothing like a bit 'baccy ter spit over the side when the sharks get close.",
        1,({
        "'I could build a raft I guess, but these broken old bones aren't up to all the clamberin round now. ",
        ":sighs",
        "'A few barrels, and something to lash o'er the top would do it. ",
        "'Had a raft once, tide takes you there and back ",
        ":grins",
        "'O.K. well the last time I had to swim back, the sharks weren't too bad, but the sea serpent was a pain. "
        }),
        1,({
        "'How did I get like this $lcname$ ?",
        "'Decided to raid Rakhmar's keep way north of Hoerk. ",
        "'Bastard demon broke all my bones then left me to rot in his dungeon.",
        "'By the time Trish and Kel got me out, I was beyond helping.",
        "'Can't complain though, they saved my life, brought me here. ",
        "'It was good to see them when they decided to retire here as well.",
        "'You stay away from Rakhmar you hear, he was mean when I was a level 28 fighter with hit points from hell.",
        ":sighs"
        }),
        1,({
        "'Being a fighter was good, apart from thieves like Kel o'course. ",
        ":winks",
        "'We had our differences now and then, but we saved one anothers hides more often. ",
        "'It's always good to have friends youngster, it's one thing to be a hell of a fighter ",
        "'Bearhug Berserk and Disarm are mighty fine and you can kick butt for a long time alone. ",
        "'But you need friends as well, sooner or later you'll run into something too tough to take alone. ",
        "'Always need friends, nothing like a Taniwha or Hokemj priest when the bugs bite."
        }),
        1,({
        ":looks out to sea",
        "'Why am I called Pirate Dan ?",
        ":laughs",
        "'This eyepatch, I lost this to Scorch in the Banefall tunnels",
        ":grins",
        "'mind you he lost more",
        "'Whatever you hear, you can get into Banefall, gotta move fast and quiet in those tunnels tho ",
        "'There's Umber Hulks and Hell hounds down there that'll kill you quick. ",
        "'Not a trip for newbies tho, and certainly not when there's a lot of Drow round. ",
        ":spits"
        }),
    }),
    );
    new("/baseobs/armours/studded")->move(this_object());
   new(OBJ+"boots")->move(this_object());
    new("/baseobs/weapons/short_sword")->move(this_object());
    new("/baseobs/weapons/long_sword")->move(this_object());
    adjust_money(2+random(2),"gold");
   init_equip();
}
