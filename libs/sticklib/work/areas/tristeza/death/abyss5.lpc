/* The Abyss */
/* Rewards and finale of the Quest */
#include <room.h>
#include <daemons.h>
#include <quests.h>
#include <areas.h>
#include <generic_items.h>

void
create_room()
{
    int i;

    set_short("Large Hall (in the Abyss)");
    set_long(
      "This sure is the hall where that enormous golem was constructed.\
 Fortunately (or unfortunately?) those who built the golem have fled\
 after its destruction. Some tools, bottles and even gold coins still\
 lie around here.");
    set_exits(([ "south" : AREA_TRISTEZA+"death/abyss4" ]));
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);

    add_object(({GENERIC_MONEY_OBJECT,
	({ "set_money", random(2500)+1000 }) }),0,1);

    for (i = 0;i<2+random(3);i++)
	add_object(GENERIC_HEAL_POTION,0,1);
}

void
init_room()
{

    call_out("check_this_out",15);
}

void
check_this_out()
{
    object *inv;
    int i;

    inv = all_inventory(this_object());

    for(i = 0; i < sizeof(inv); i++)
	if (interactive(inv[i]))
	{
	    //if(inv[i]->query_lord())
	    if(1)
	    {
		if(!inv[i]->query_quests(QUEST_GOLEM))
		{
		    inv[i]->tell_me("\n\nYou have solved a Lord Quest!\n\n"+
		      "You feel more experienced!");
		    QUEST_D->add_quest(inv[i],QUEST_GOLEM);
		    inv[i]->move_player("Vdisappears in a bright flash of light!",
		      AREA_TRISTEZA+"death/finale");
		}
		else
		if(present("deaths_item",inv[i]))
		{
		    inv[i]->tell_me(
		      "You hear a booming voice shouting: I'VE BEEN ROBBED!!!");
		    inv[i]->move_player("Vdisappears in a bright flash of light!",
		      AREA_TRISTEZA+"death/finale");
		}
		else {
		    inv[i]->tell_me("You feel you don't belong, and a bright "+
		      "flash blinds you.");
		    inv[i]->move_player("Vdissappears in a bright flash of "+
		      "light!", AREA_TRISTEZA+"death/finale");
		}
	    }
	} 
}
