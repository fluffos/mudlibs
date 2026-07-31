// /d/wudang/wanniansong.c  万年松

#include <ansi.h>
inherit ROOM;

int do_jump(string arg);

void create()
{
        set("short",HIG"万年松"NOR);
        set("long", @LONG
这是一棵万年老松，树枝交错，松针茂密。老树盘根，深抓石壁。树上结
满了大大小小的松果。脚下雾气弥漫，不知深浅。拨开松枝，你看见石壁上有
一个天然石洞。
LONG                           
        );
        set("exits", ([
                "enter":__DIR__"lwhole",
        ]));

        set("objects",([
                __DIR__"obj/songguo" : 3,

        ]));

        setup();

}

void init()
{
        add_action("do_jump", ({"tiao", "jump"}));
}

int do_jump(string arg)
{       object me, tmp;
	object *ob;
	int i;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("你要往哪跳？\n");
        message_vision("$N两眼一闭，勇敢地跳了下去。\n"NOR, me);
        if (! present("mao tan", me))
          { 
            message_vision(RED"啊---，$N一声惨叫，直往万丈深谷落去。\n"NOR, me);
            me->die();
//            me->set_temp("last_damage_from","摔下万丈深谷跌");
//            me->die();
		if (tmp = present("corpse", this_object())) {
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
			if (me) tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
		}
		return 1;
          }
        message_vision(HIY"$N人在空中，连忙把毛毯展开，顿时象长了翅膀般轻飘飘地恍恍惚惚朝下落去。\n"NOR, me);

        me->move(__DIR__"songlin1");

	tell_room(this_object(), me->name() + "飞了过来。\n", ({ me }));
        message_vision(HIY"嘘--的一声，毛毯被树枝划破挂在树上，$N两脚一震，一屁股跌在地上。\n"NOR, me);
        destruct(present("mao tan", me));

     	write(HIY"你终于安全着陆。\n"NOR);
	return 1;
}
