//Room: /d/foshan/yingxionglou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","英雄楼");
	set("long",@LONG
酒楼里桌椅洁净。座中客人衣饰豪奢，十九是富商大贾。这里
可以俯瞰佛山镇全景。
LONG);
	set("objects", ([
	    __DIR__"npc/pang": 1,
	    __DIR__"npc/shou": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"yingxionglou",
	]));
	setup();
}

