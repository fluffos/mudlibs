// Room: /city/kedian.c
// YZC 1995/12/04 
#include <title.h>
#include <ansi.h>
inherit ROOM;
int monitor_sys();
void create()
{
        set("short", "客店");
	set("long",
"这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，你可\n"
"以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调\n"
"的客人。客店的主人从不露面，他究竟是谁，有各种各样的猜测。墙上挂着一个\n"
"牌子" + RED "(paizi)" NOR "。\n");

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
                "paizi" : "楼上雅房，免费体验中。。。\n",
	]));

	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
              __DIR__"npc/gbeg" : 1,
        "/d/riyuejiao/npc/ry-welcomer" : 1,
//		"/clone/gift/06815/dashi" : 1,
	    "/clone/npc/suicong":1,
	//	"/clone/npc/gongsun":1,
	]));

	set("exits", ([
		"west" : __DIR__"beidajie1",
		"up" : __DIR__"kedian2",
	]));

	setup();

	call_out("monitor_sys",600);

//	call_out("clear_camel",15);
	"/clone/board/kd_b"->foo();
}
int monitor_sys()
{
	write_file("/log/monitor_sys.log",(string)mud_status(1),0);
	remove_call_out("monitor_sys");
	call_out("monitor_sys",600);
	return 1;
}
/*
int clear_camel()//清除系统中的毫毛，不在每个camel身上加call_out了,zine
{
	object *camel=children("/clone/npc/camel1");
	remove_call_out("clear_camel");
	call_out("clear_camel",15);
	for (int i=0;i<sizeof(camel);i++)
	{
		if (camel[i]->destroy()==2)
		{
			return 1;
		}
		if (camel[i]->destroyme()==2)
		{
			return 1;
		}
	}
}

*/

/*
int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
*/

void init()
{
//	add_action("do_finish","finish");
	add_action("do_none", "dz");  
	add_action("do_none", "dazuo");    
	add_action("do_none", "study");    
	add_action("do_none", "du");  
	add_action("do_none", "lian");
	add_action("do_none", "practice"); 
	add_action("do_none", "exercise"); 
	add_action("do_none", "tuna");
	add_action("do_none", "respirate");
	add_action("do_none", "xiulian");  	
}
/*
int do_finish()
{
	object me=this_player(),ob;
	int i;
	if (!me->query("olympic_london_finish"))
	{
		return notify_fail("你并没有完成为奥运加油任务或已经参加过抽奖。\n");
	}
	me->delete("olympic_london_finish");
	if (me->query("combat_exp")>49999999)
	{
		for (i=0;i<8;i++)
		{
			ob=new("/d/changjiang/obj/o_lotto_high");
			ob->set("owner",me->query("id"));
			ob->move(me);
		}
	}
	else
	{
		for (i=0;i<8;i++)
		{
			ob=new("/d/changjiang/obj/o_lotto_low");
			ob->set("owner",me->query("id"));
			ob->move(me);
		}
	}
	tell_object(me,"你获得了8张奥运奖券。可以使用choujiang命令来抽奖。\n");
	return 1;
}
*/
int do_none()
{  
   return 1; 
}  