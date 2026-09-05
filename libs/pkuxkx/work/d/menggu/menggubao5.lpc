// Room: menggubao5.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB+"郭靖的帐篷"+NOR);
	set("long", @LONG
这是里郭靖和李萍在大漠的家。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"menggubao",
		"northwest" : __DIR__"menggubao7",
		//"south" : __DIR__"menggubao5",
		"northeast" : __DIR__"menggubao1",
		"enter" : __DIR__"guojingjia",
	]));
		set("sleep_room", "1");
	set("objects", ([
        	__DIR__"npc/muyangren" : random(2),
	]));
	set("no_robber",1);
	set("outdoors", "menggu_e");
    setup();
}

void init()
{
    object ob=this_object();
    object me=this_player();
    object zhebie;
	add_action("do_zhao", ({ "zhao", }));
	if (me->query("shediaoquest/dmfy/endtime")&&time()-me->query("shediaoquest/dmfy/endtime")>3600&&!me->query("shediaoquest/zhebie")&&!me->query_temp("shediao/meetzhebie")&&!ob->query("using"))
	{
		tell_object(me,"你正玩的高兴，忽听得东边马蹄声响，一骑匹马慢慢踱来，马背一人俯首伏在鞍上。\n");
        tell_object(me,"你被吓了一跳，却发现那人满脸血污，正是前日所见的黑袍将军。\n");
        me->set_temp("shediao/meetzhebie",1);
        ob->set("using",1);
        zhebie=new(__DIR__"npc/zhebie");
        zhebie->set("owner",me);
        zhebie->move(ob);
        zhebie->start_1(me);
		return;
	}
}

int found(object me)
{
	object ob = new(__DIR__"obj/yangbian");
	if (ob) 
		{	
			if(me->is_busy())
				{
					return notify_fail("你正忙着呢。\n");
				}
			if(random(10)>5)
				{
					ob->move(me);
					me->add_busy(random(2));
					message_vision(HIG"$N很快就找到了郭靖的小羊鞭。\n"NOR, me);
					me->set_temp("guojing/yangbian", 1);
				}
			else
				{
					me->add_busy(random(2));
					message_vision(HIW"$N沮丧地发现，自己似乎比郭靖还笨，半天都找不到羊鞭。\n"NOR, me);
				}
		}
	return 1;
}

int do_zhao()
{
	object me = this_player();
	if( (int)me->query_temp("guojing/yangbian") ) 
		{ 
			return notify_fail("你已经找到郭靖的牧羊鞭了，还要找什么？\n");
		}
    else 
		{ 
			if ((int)me->query_temp("guojing/yangbianask"))
				{
					message_vision("$N在角落里寻找着什么。\n", me);
					found(me);
				}
			else
				{	
					tell_object(me,"你是小偷吗？在人家家门口乱翻什么？\n");
				}
        }
	return 1; 
}

int valid_leave(object me,string dir)
{
    if (time()-(int)me->query_temp("shediao/meetzhebie7")<8)
    {
        return notify_fail("这时候离开似乎不大好啊！\n");
    }
    return ::valid_leave(me,dir);
}

