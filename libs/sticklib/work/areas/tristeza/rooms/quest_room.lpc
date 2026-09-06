#include <room.h>
#include <areas.h>
#include <city_name.h>
#include <generic_items.h>

void
create_room()
{
    object ob;
    set(ROOM_WD, WD_INDOORS);
    set(NO_CLEANUP);
    set_light_level(LT_LIGHTS);
    set_short("Room of Quests");
    set_long(
      "This is the room of quests. Every coder can make quests, but they should \
first plan one, then talk with a (co-)admin before even trying to code it. \
When the quest has been coded, checked by (co-)admin and approved, a \
permanent quest object is created and placed in this room. It has the \
quest's name and a short description of it. To mark that a quest is solved, \
call 'set_quest(\"name\")' in the player object. The quest objects here \
must all accept the id 'quest' and the name of the coder. The objects must \
also define a function hint(), that should return a message giving a hint of \
where to start the quest. Note that players never can come here. \
set_quest(str) will return 1 if this is the first time it was solved \
by this player, otherwise 0. A new addition is the Quest Points. Every \
quest has a set quest points value. Read /bin/daemons/questd.c to see the \
points of the current quests. The quests should really be done some other \
way later, this quest object method is not good...");

    set_exits(([ "south" : AREA_TRISTEZA+"rooms/wiz_hall" ]));
    add_object( ({ GENERIC_QUEST_OBJECT,
	({ "set_quest", "zooquest" }),
	({ "set_hint",
	  "Respected citizen of " CITY_NAME ", Amos the Bold has lost his son. He needs\
 a brave adventurer to fulfill\
 a task for him. Go to Amos, and ask him about his son, and he'll tell\
 you more. Amos lives on the Dragon Street.\n\
Suitable for medium-level adventurers." }) }), 0, 1 );

    add_object( ({ GENERIC_QUEST_OBJECT,
	({ "set_quest", "kill_kitiara" }),
	({ "set_hint", 
	  "Destroy evil witch, Kitiara. She lives in Mansion of Kantele,\
 south from " CITY_NAME ". Beware, she is really nasty.\n\
Quest for group of tough characters." }) }), 0, 1 );

    add_object( ({ GENERIC_QUEST_OBJECT,
	({ "set_quest", "zillgods" }),
	({ "set_hint",
	  "The mighty Zillgod is furious, and has to be soothed.\
 Bilbo might help you on your quest. Bilbo lives in hobbit village.\n\
A tough quest for VERY tough players (level 18 and over)." }) }), 0, 1 );

    add_object( ({ GENERIC_QUEST_OBJECT,
	({ "set_quest", "quest_for_sampo" }),
	({ "set_hint",
	  "Bring the Sampo for Mistress of Pohjola and you'll\
 be rewarded. Start by going to Vainamoinen of Kalevala, and ask him to\
 tell you about Sampo.\n\
Suggested for a single medium level adventurer with lots of money." }) }), 0, 1 );

    add_object( ({ GENERIC_QUEST_OBJECT,
	({ "set_quest", "orc_slayer" }),
	({ "set_hint",
	  "Retrieve the Orc Slayer sword from evil orc shaman,\
 and give it to Leo the archwizard. Orc shaman lives in the orc vallee,\
 west from " CITY_NAME ". Leo lives in the church tower.\n\
Quest for medium level adventurers; even single adventurers can do this quest." })
      }), 0, 1 );

}

int
count(int silently)
{
    object ob;
    int i;

    i = 0;
    ob = first_inventory(this_object());
    while(ob) {
	if (call_other(ob, "id", "quest")) {
	    string str;
	    str = (string) ob -> query_quest();
	    if (!call_other(this_player(), "query_quests", str))
		i += 1;
	}
	ob = next_inventory(ob);
    }
    if (!silently) {
	if (!i)
	    this_player()->tell_me("You have solved all quests!");
	else
	    this_player()->tell_me("You have "+i+" quests unsolved.\n\
Try 'list <number>' for more information about these.");
    }

    if (i < 1) return 0;

    return i;
}

list(i)
{
    object ob;

    ob = first_inventory(this_object());
    while(ob) {
	if (call_other(ob, "id", "quest")) {
	    string str;
	    str = (string) ob->query_quest();
	    if (!call_other(this_player(), "query_quests", str))
		i -= 1;
	    if (i == 0) {
		this_player()->tell_me((string) ob -> hint());
		return;
	    }
	}
	ob = next_inventory(ob);
    }
}
