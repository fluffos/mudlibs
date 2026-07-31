#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","牛家村内室");
        set("long", @LONG
       这里看起来破破烂烂 ,不过收拾的相当整洁，旁边有一小灶，
     里面还有不少吃的（chifan)，一看就知道有人来过。 。
LONG
        );

        set("exits", ([
              "south"  :__DIR__"midao",
        ]));
        set("sleep_room",1);

        setup();
}


void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
        this_player()->start_busy(5);
        write(YEL "你坐下来饱饱地大吃了一顿\n" NOR);
        write(YEL "直吃得肚肥肠满才心满意足地站起身来\n" NOR);
        this_player()->set("food",350);
        this_player()->set("water",350);
        return 1;
}
