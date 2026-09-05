// Room: /beijing/guancaidian.c
#include <ansi.h>

inherit ROOM;



void create()

{

	set("short", HIY"棺材店"NOR);

	set("long",
HIC"这是一家棺材(guancai)店，一进门，一股楠木味扑鼻而来。屋子
里很阴暗，桌子椅子都很破旧。往东是一间内室，一个三十出头的精
壮汉子挡在门口。\n"NOR
	);

	set("item_desc", ([

		"guancai" : "本店出售棺材，每个五十两黄金。\n",

	]));



	set("objects", ([

               "/d/beijing/npc/gaoyanchao" : 1,

	]));



	set("exits", ([

		"west" : __DIR__"alley1",

                "east" : __DIR__"guancai2",

	]));


	setup();

}

