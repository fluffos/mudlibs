//by pipip
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "地下水");
        set("long", @LONG
你眼前是一道天然的地下河流，黑暗中透着凉意，
你根本不知道这地下水的深浅，也不知道水中是否会
有怪物等着闻到血腥。
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/xuantian/room2",
                "east" : "/d/xuantian/room3",
                "north" : "/d/xuantian/room7",
                "south" : "/d/xuantian/room5",
        ]));
        set("outdoors", "xuantian" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
        add_action("do_qian","qian");
}

int do_qian(string arg)
{
        object ob;
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "地下水中" )
                return notify_fail("潜什么潜？你的防水面具带了没？\n");
        tell_object(ob, HIR"你深深吸了口气，纵身一跃，潜入冰冷的地下水中。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "扑通一声跳进了水里。\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<1300) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move("d/xuantian/xiaojin");
        ob->unconcious();
        return 1;
}

