// 药铺
// yaopu1.c
// augx@sj 2/28/2002

// Modified by mxzhao 2004/03/06 
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",GRN"药店"NOR);
	set("long",
"这是家古色古香的药店，是附近百里有名的老字号。前来买药的人终日络
绎不绝，应接不暇，还有不少游方郎中就在大厅中问诊、开药，好不热闹。在
屋角还放这一座炼丹铜炉，终日炉火不息，这是给大夫炼制丹药而准备的。
");

	set("objects",([
		__DIR__"npc/yaodian-zhanggui" : 1,
//		__DIR__"obj/yaolu" : 1,
	]));

	set("exits",([
		"east" : "/d/chengdu/beidajie2",
	]));

	set("indoors", "成都城");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
