#pragma save_binary
// Room: /u/k/karrimor/temple/temple2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({1200,4980,35}));
	set("short", "后殿");
	set("long",
"你正站在灵心观的后殿,正中央供奉著茅山派开山祖师张天师的\n"
"画像,在画像的下方摆放著当年张天师收妖伏魔时所用的宝剑。\n"
"剑的两旁陪祀著历代掌门人的牌位。走出南边的红漆木门可以看\n"
"到天井。\n"
);
    set("item_desc", ([
         "door": (: this_object(), ({ "look_door", "south"}) :),
    ]) );
	set("exits", ([ /* sizeof() == 1 */
     "south" : __DIR__"corridor5",
]));

     create_door("south", "红漆木门", "north", DOOR_CLOSED);
	setup();
}
