// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "白家");
        set("long", "这里是一户人家，住着一位老爷子，据说也曾有着显赫的过去。地上堆了许\n多砖头(bricks)。\n");
        set("exits", ([
               "south" : __DIR__"eaststreet",
               
                
        ]));
        set("item_desc", ([
		"bricks" : "一大堆砖头，不知道有什么用。老白需要人帮助搬(ban)到北门外。\n", 
	    ]));
        set("objects", ([
        "/d/nanchang/npc/bai" : 1,
        ]));
        setup();
   
}

void init()
{ 
	add_action("do_ban","ban"); 
}

int valid_leave(object me,string dir)
{  
	object pl=this_player();
    if (present("qing zhuan",pl))
    {
        if (pl->query("max_neili")<1000)
        {
            return notify_fail("你的体力太弱，青砖压得你寸步难行。\n");
        }
        if (time() - pl->query_temp("ncjob/last_go_time") <= 2)
        {
            return notify_fail("你扛着青砖一步一步地向前挪动。\n");
        }
        else
        {
            pl->set_temp("ncjob/last_go_time",time());
        }
    }
	return ::valid_leave(me, dir);
}

int do_ban(string arg)
{
    object me=this_player();
    object brick;
    if (!arg)
    {
        return notify_fail("你要搬什么？\n");
    }
    if (arg!="brick" && arg!="砖" && arg!="砖头")
    {
        return notify_fail("你要搬什么？\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
        return notify_fail("你正忙着哪！\n");
    }
    if (!me->query_temp("ncjob/permit")&&!me->query_temp("jn/step6a"))
    {
        return notify_fail("在别人家里，你好歹打个招呼再搬砖吧？\n");
    }
    if (present("qing zhuan",me))
    {
        return notify_fail("你身上已经块砖了，多了实在拿不动。\n");
    }
    if (me->query_temp("ncjob/count")>1)
    {
        return notify_fail("你拿了那么多块青砖，也没有帮老白搬到北门外，还拿？\n");
    }
    else
    {
        brick=new(__DIR__"obj/brick");
        if (brick)
        {
            brick->set("owner",me->query("id"));
            brick->move(me);
            me->add_temp("ncjob/count",1);
            me->set_temp("ncjob/last_go_time",time());
            message_vision("$N抱起了一块青砖。\n",me);
            return 1;
        }
    }
}

