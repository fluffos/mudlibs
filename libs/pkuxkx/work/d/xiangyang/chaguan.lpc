#include <ansi.h>
//#include <room.h>
inherit ROOM;
void create()
{
	set("short",GRN"太平茶馆"NOR);
	set("long",
GRN"这是一家简陋的茶馆,几张木桌,坐着几个路人,在这里歇歇脚.墙边有一个大水缸
装满了清水，水面上漂着一个水瓢，你可以喝(drink)点水,也可以灌(fill).
桌边坐着一个姑娘,穿着不凡,一看便知是大户人家的小姐.\n"NOR
	);
	set("resource/water", 1);

	set("exits", ([
		"north" : __DIR__"xyeast3",
	]));

	set("objects", ([
                __DIR__"npc/huoji1" : 1,
		__DIR__"npc/guofu" : 1,
	]));

	setup();
//	replace_program(ROOM);
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
            me->set("water", current_water+30);
            message("vision", me->name()+"拿起水瓢，舀了一瓢水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口水缸中的水，真解渴呀。\n");
        }
        else write("人家的水是用来泡茶的，你给人家留点行不行？\n");

        return 1;
}

