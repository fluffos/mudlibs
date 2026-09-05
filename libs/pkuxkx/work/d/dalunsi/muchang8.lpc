// Room: muchang8.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "牧场");
        set("long", @LONG
这里是一片茫茫无际的牧场，一眼望不到边的草原，远处能看到高耸的雪
山。附近能看到藏民们正在放牧牛马，小孩子们在奔跑玩耍。

LONG
        );

        set("exits", ([
                "north" : __DIR__"muchang9",
                "southwest" : __DIR__"muchang5",
        ]));
        set("outdoors", "雪山");

   setup();
}



int valid_leave(object me,string dir)
{
	object pl = this_player();
    object sz;
    if (present("du lang",environment(me)))
    {
        sz=present("du lang",environment(me));
        if (sz->query("is_xinan_block_lang")&&sz->query("owner")==me->query("id"))
        {
            sz->kill_ob(me);
            return notify_fail("野狼一闪身拦住了你的去路，扑上就咬。\n");
        }
        
    }
        if(time() - pl->query_temp("muchang/last_go_time") <= 5+random(5) && random(100)>39)
        {
            return notify_fail("青海湖畔美不胜收，你不由停下脚步，欣赏起了风景。\n");
        }
        else
        {
            pl->set_temp("muchang/last_go_time",time());
        }
	
	return ::valid_leave(me, dir);
}

void init()
{
    object sz;
    object me=this_player();
    if (me->query_temp("xinan_block/start"))
    {
        me->add_busy(2);
        me->delete_temp("xinan_block/start");
        sz=new(__DIR__"npc/shanzei");
        sz->set("owner",me->query("id"));
        sz->move(this_object());
        sz->kill_ob(me);
        message_vision("一条野狼神出鬼没地出现了，龇牙咧嘴地看着你。\n",me);
    }
    return;
}