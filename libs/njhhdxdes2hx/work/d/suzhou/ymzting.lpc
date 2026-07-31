// Room: /d/suzhou/ymzting.c
//by dwolf
//97.11.4 

#include <ansi.h>         
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"衙门正厅"NOR);
        set("long", @LONG
	  这里是衙门正厅，知府杨康正在和朋友喝酒，两扇"朱木大门"紧紧关闭着
。再往后就是后厅了，有女眷住着，你好象不方便进去。
LONG
	);

	set("exits", ([
		"south" : __DIR__"yamen",
		"north" : __DIR__"ymhting",
		"east" : __DIR__"shufang",
	]));        
	create_door("south", RED"朱木大门"NOR, "north", DOOR_CLOSED);

	set("objects", ([
		__DIR__"npc/hu" : 1,
		__DIR__"npc/chu" : 1,
	]));

	setup();
}


