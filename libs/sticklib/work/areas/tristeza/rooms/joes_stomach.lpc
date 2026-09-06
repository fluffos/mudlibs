#include <room.h>
#include <areas.h>
#include <daemons.h>
#include <quests.h>

void
create_room()
{
    set_short("Joe's Stomach");
    set_long("You are inside Joe's stomach.");

    set_light_level(LT_LIGHTS);
    set(NO_PK);
    set(IN_CITY);
    set(ROOM_WD, WD_INDOORS);
}

void
init_room()
{
    if (!this_player()
      || !living(this_player())
      || this_player()->is_npc())
	return;

    if (this_player()->query_quests(QUEST_EAT_AT_JOES)) return;
    QUEST_D->add_quest(this_player(), QUEST_EAT_AT_JOES);
    this_player()->tell_me("\nYou have completed a quest - Eat at Joe's.\n");
}
