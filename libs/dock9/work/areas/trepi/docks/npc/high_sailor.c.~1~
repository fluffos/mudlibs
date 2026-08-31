/* /areas/trepi/npc/high_sailor.c

 Emsenn@Dock 9
 091207
 The first wandering NPC!

*/

inherit NPC;

void setup()
{
    ::setup();
    set_living_name("sailor");
    set_name("sailor");
    set_id(({"junky","man"}));
    set_short("an unsteady sailor");
    set_domains("trepi",({"docks"}));
    set_long("This sailor has obviously just come in somewhere on Nulens.  Pupils dilated, eyelids drooped, he has obviously been enjoying the lax law enforcement in most of the new world.");
    set_chats(({
        "say Man... I don't even know.",
        "emote leans 20 degrees to the right, before correcting 50 degrees to the left and almost falling over.",
        "say There's this crazy little place that I know in Calliet... dude...",
    }));
    set_wander(15);
}


string help(){
    return("There's, unfortunately, nothing you can do for this poor sailor.  And there's nothing much he can do for you.  He's simply here to demonstrate that NPCs can wander around within their subdomain.");
}
