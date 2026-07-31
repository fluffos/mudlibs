//ROOM: d/suzhou/sjin.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"水井"NOR);
	set("long", @LONG
	  你来到一口水井旁。这儿可以免费喝水，你一象到这儿，不由呵呵笑了。
LONG
	);  
	set("resource/water", 1);
	set("no_sleep_room", 1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"south" : __DIR__"wroad4",
	]));
	setup();
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+70);
            message("vision", me->name()+"趴在水井的井台上用水桶舀了一桶水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中从地下流淌出来的甘泉水，简直比蜜还甜。\n");
        }
        else write("逮着不要钱的水就这么喝，至于吗?\n");

        return 1;
}





