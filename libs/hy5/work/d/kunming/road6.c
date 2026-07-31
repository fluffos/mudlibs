// /d/kunming/road6
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "长江南岸" NOR);
        set("long", @LONG
你来到了长江北岸，只见波涛滚滚，滔滔江水向东流去。岸边立
有一块碑(bei),前面不远处有座独木桥。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"road7", 
                "north"  :__DIR__"qiao",
                
        ]));
         set("item_desc", ([
                "bei" : "一块石碑，上面写着：\n\n\n" +
                        "**************** \n" +
                        "* 河   天   通 * \n" +
                        "**************** \n\n\n\n" ,
                 ]));

        setup();
        
}

int valid_leave(object me, string dir)
{
	if ( dir == "south" || dir == "north" )
            { me->delete_temp("dirs");me->delete_temp("dirs2");}
        if (dir == "north") me->set_temp("dirs1",1);

	return ::valid_leave(me, dir);
}