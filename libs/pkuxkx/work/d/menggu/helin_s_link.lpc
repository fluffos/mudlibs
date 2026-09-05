// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;
#include "/d/menggu/entry_migong.h",
string *norths=({__DIR__"d_menggubao4",__DIR__"d_menggubao5",});
void create()
{
	set("short", YEL+"荒原"+NOR);
	set("long", @LONG
这里降雨渐少，由草原过渡到了荒原。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"random_shaomo1_n",
		"north" : norths[random(sizeof(norths))],
	]));
	    set("entry_direction","southdown");
        set("migong","/d/menggu/shamo1");
        set("look_refuse_msg","库布齐沙漠里起了沙尘暴，你什么都看不清了。\n");
        set("enter_refuse_msg","库布齐沙漠里此时正刮起了沙尘暴，这会儿进去太危险了。\n");
        set("outdoors", "menggu_m");
	setup();
}

void init()
{
    add_action("do_look","look");
}