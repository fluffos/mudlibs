// 湖底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>

void create()
{
	set("short", BLU"湖底"NOR);
	set("long", @LONG
这里是湖底，幽蓝的湖水让人不寒而栗。你可以游(swim)向深处。
LONG
	);
    set("normaldesc", @LONG
这里是湖底，幽蓝的湖水让人不寒而栗。你可以游(swim)向深处。
LONG
	);
	set("exits", ([ 
    ]));
	set("objects", ([(__DIR__"npc/croc") : 1,
    ]));
	setup();
	::create();
}

void init()
{
	add_action("do_swim", ({ "swim" }));
	::init();
}

int do_swim()
{
    
	object me = this_player();
	object zhang=present("mu zhang",me);
    if (time()-(me->query("xxnewbiejob/qiantime"))>300)
    {
        me->move(__DIR__"xiaohu");
        me->add_busy(4);
        tell_object(me,"你在水下时间太长，无法控制气息，只好回到岸边。\n");
        return 1;

    }
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着呐！\n");
        }
    if (!(me->query_temp("xxnewbiejob/quest1")))
    {
        if (random(100)>95)
        {
            me->move(__DIR__"hudi2");
            tell_object(me,"你向前游去，似乎这里是鳄鱼的巢穴。\n");
            me->add_busy(random(4));
            return 1;
        }
        else
        {
            me->move(__DIR__"hudi1");
            tell_object(me,"你向前游去，却被漩涡冲回原地。\n");
            me->add_busy(random(4));
            return 1;
        }
    }
    else
    {
        if (random(10)>2)
        {
            me->move(__DIR__"hudi2");
            tell_object(me,"你向前游去，似乎这里是鳄鱼的巢穴。\n");
            me->add_busy(random(4));
            return 1;
        }
        else
        {
            me->move(__DIR__"hudi1");
            tell_object(me,"你向前游去，却被漩涡冲回原地。\n");
            me->add_busy(random(4));
            return 1;
        }
    }
   
	
}