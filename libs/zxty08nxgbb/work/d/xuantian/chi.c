inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "黑水池");
        set("long", @LONG
你面前突然出现一座巨大的水池，池水黑漆漆的，十分恐怖。
你不由想起不少鬼故事中主人公跳水自尽的一段...
LONG    );

        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/xuantian/room1",
                "east" : "/d/xuantian/xiaolu",
                "north" : "/d/xuantian/room7",
                "south" : "/d/xuantian/room2",
                "out" : "/d/xuantian/pomiao",
        ]));
        set("outdoors", "xuantian" );
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
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "水池" )
                return notify_fail("你想跳舞？应该到舞厅才对。\n");
        tell_object(ob, HIR"你深深吸了口气，纵身一跃，跳进了黑水池中。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了黑水池之中。。。。\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 5 ) && ((int)ob->query_skill("dodge")<300) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move("d/xuantian/dong");
        ob->unconcious();
        return 1;
}

