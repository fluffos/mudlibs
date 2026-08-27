//#pragma save_binary

//quests_hint.c
//Written by Echobomber@Eastern.Stories 3-2-94

#include <mudlib.h>
#include <daemons.h>
#define QUEST_MSG "/doc/quests/"

int show_all_quests()
{
    
    this_player()->more(QUEST_MSG"all_c_quests");
    return 1;
}

int show_quest(mixed num)
{
    cat(QUEST_MSG"quest_c_"+num );
    return 1;
}
