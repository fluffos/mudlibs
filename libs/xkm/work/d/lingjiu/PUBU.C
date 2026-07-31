// pubu.c
// shilling 97.2

inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "瀑布");
        set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见一
条大瀑布，犹如银河倒悬，从高崖上直泻下来。下面是万丈深渊，云雾弥漫，
望不到尽头。。。。
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "southdown" : __DIR__"dadao4",
        ]));
        set("outdoors", "lingjiu" );
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob;
        int new_qi;
        ob = this_player();
        new_qi = random( ob->query("max_qi")*3 );
        if ( new_qi > ob->query("qi") ) new_qi = ob->query("qi") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
        tell_object(ob, CYN"你不加思索，纵身一跃，跳下了悬崖。。。。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了悬崖之中。。。。\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<100) )
        {
		ob->receive_wound("qi", ob->query("max_qi")+100, "跌下绝壁摔死了");

                return 1;
        }
        ob->receive_damage("qi", new_qi, "跳崖摔得粉身碎骨死了。");
        ob->move(__DIR__"yanfeng");
        return 1;
}

