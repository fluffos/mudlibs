// /d/dzd/shiwu.c

#include <ansi.h>

inherit __DIR__"dzd_room";

void create()
{
	set("short","石屋");
	set("long",@LONG
这是大智岛上的一个普通的小庵，整间屋子都是用石头切成，中间供着一尊佛像。
屋子打扫的一尘不染，小庵显得安静、简朴、祥和。
LONG
	);
	set("no_fight",1);
	set("objects",([
		__DIR__"npc/shenni" : 1,
	]));
	setup();
}

void init()
{
	object me = this_player();
	
	::init();
	if(userp(me)) {
		me->clear_condition("bingcan_poison");
		me->clear_condition("haitang_poison");
		me->clear_condition("lingfu_poison");
		me->clear_condition("yufeng_poison");
		me->clear_condition("snake_poison");
		me->reincarnate();
		
	}
}
	