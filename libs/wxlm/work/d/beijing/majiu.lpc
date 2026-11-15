//Room: majiu1.c 马厩
#include <room.h>
inherit TRANS_ROOM;

void create()
{
	set("short", "马厩");
	set("long", @LONG
这是北京城的马厩，常年供应新鲜草料。北京自古天子脚下，啥都有
规矩，客店也特会伺候人，马夫们会把马牵到马厩好生照看，将它们喂饱
饮足，再洗刷得干乾净净，一直伺候到客人上路。马厩雨檐下的烂木柱上
钉着一块破木牌。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "beijing");
	set("no_fight", 1);
	set("objects", ([
		"/clone/horse/zaohongma": 1,
		"/clone/horse/huangbiaoma": 1,
		"/clone/horse/ziliuma": 1,
		"/clone/npc/mafu": 1,
	       
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"      : __DIR__"niaoshi",
	]));

	setup();
	//replace_program(TRANS_ROOM);
}
