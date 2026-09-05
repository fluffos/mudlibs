

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "华容道");
	set("long", @LONG
三国时期，曹操中了诸葛亮火烧赤壁之计，狼狈败走华容
道，却被关羽所放。这里两旁都是树林，很适合埋伏。南面就
是长江渡口了。
LONG );
	set("outdoors", "xiangyangnan");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : "/d/changjiangnorth/cjb21",
		"northwest" : __DIR__"guandao1",
	]));
	setup();
	
}

void init()
{
    object sz;
    object me=this_player();
    if (me->query_temp("huarongdao/start"))
    {
        me->add_busy(2);
        me->delete_temp("huarongdao/start");
        sz=new(__DIR__"npc/shanzei");
        sz->set("owner",me->query("id"));
        sz->move(this_object());
        message_vision("一个山贼跳了出来，阴恻恻地对$N道：此山是我开，此树是我栽，要想过此路，留下买路财。\n",me);
    }
    return;
}

int valid_leave(object me,string dir)
{  
    object sz;
    if (present("shan zei",environment(me)))
    {
        sz=present("shan zei",environment(me));
        if (sz->query("owner")==me->query("id"))
        {
            return notify_fail("山贼拦住了你的去路。\n");
        }
        
    }
	if (dir=="south")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}