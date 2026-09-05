//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include <net/dns.h>
void create()
{
        set("short", "礼部大厅");
        set("long", 
"这里礼部衙门的大厅，许多官员正在这里办事。\n"

        );
        set("exits", ([
                
              
                
                
                
                "out" : __DIR__"li2_room2",
                
                
                
        ]));
        
        set("objects", ([
        __DIR__"npc/daming_npcf" : 1,
	    ]));
        setup();
   
}

void init()
{
	add_action("do_xiushi","xiushi");
	add_action("do_zhiding","zhiding");
}
int do_zhiding(string arg)
{
	object me=this_player(),pl;
	if (me->query_temp("mingtasks/libu2/fengchan")!=1)
	{
		return 0;
	}
	if (me->query_temp("mingtasks/libu2/fengchan_partner"))
	{
		return notify_fail("你已经指定了这次封禅的助手是"+me->query_temp("mingtasks/libu2/fengchan_partner_name")+"了。\n");
	}
	if (!arg)
	{
		return notify_fail("你要指定谁作为这次封禅的助手？\n");
	}
	if (!pl=find_player(arg))
	{
		return notify_fail(arg+"并不在线！\n");
	}
	if (!pl->query("mingpin"))
	{
		return notify_fail(arg+"不是大明官员。\n");
	}
	if (!living(pl))
	{
		return notify_fail(arg+"此刻不省人事，恐怕无法理会你的请求。\n");
	}
	if (query_ip_number(me)==query_ip_number(pl))
	{
		return notify_fail(arg+"因为种种原因，不符合作为你副手的条件，换个人吧。\n");
	}
	if (time()-pl->query_temp("log/time")<120)
	{
		return notify_fail(arg+"刚刚登陆，暂时无法作为你的副手。\n");
	}
	me->set_temp("mingtasks/libu2/fengchan_partner",pl);
	me->set_temp("mingtasks/libu2/fengchan_partner_name",pl->query("name"));
	pl->set_temp("mingtasks_libu2_fengchan",me);
	pl->set_temp("mingtasks/libu2/task",4);
	pl->set_temp("mingtasks/libu2/start",1);
	if (pl->query("mingpin")>=me->query("mingpin"))
	{
		message_vision("$N指定了$n作为此次封禅泰山的助手。\n",me,pl);
		tell_object(pl,me->query("name")+"选择了你作为大明封禅泰山的助手。\n");
	}
	else
	{
		message_vision("$N选择了$n同去泰山封禅，因为$n的官位在$N之上，$N不得不暂居副手。\n",me,pl);
		tell_object(pl,me->query("name")+"请求你同去泰山封禅。\n");
	}
	tell_object(me,"到达泰山封禅台后封禅(fengchan)即可完成任务。\n");
	tell_object(pl,"到达泰山封禅台后封禅(fengchan)即可完成任务。\n");
	return 1;
}
int do_xiushi()
{
	object me=this_player();
	string *msg=({
"元世祖奇幄温.孛儿只斤.忽必烈",
"元成宗奇幄温.孛儿只斤.铁穆耳",
"元武宗奇幄温.孛儿只斤.海山", 
"元英宗奇幄温.孛儿只斤.硕德八剌",
"泰定帝奇幄温.孛儿只斤.也孙铁木耳",
"天顺帝奇幄温.孛儿只斤.阿速吉八",
"元文宗奇幄温.孛儿只斤.图帖睦耳", 
"元明宗奇幄温.孛儿只斤.世涑", 
"元宁宗奇幄温.孛儿只斤.懿磷质班", 
"元慧宗奇幄温.孛儿只斤.妥灌铁木儿",
	});
	if (me->query_temp("mingtasks/libu2/xiushi")=="finish")
	{
		tell_object(me,"修元史已经告一段落，回去复命吧。\n");
		return 1;
	}
	if (me->query_temp("mingtasks/libu2/xiushi")!=1)
	{
		tell_object(me,"谁让你来乱搞的？别弄乱了礼部的资料。\n");
		return 1;
	}
	if (me->is_busy())
	{
		tell_object(me,"你修史过于疲劳，等一下再继续吧。\n");
		return 1;
	}
	if (me->query_temp("mingtasks/libu2/xiushi_degree")>5)
	{
		me->set_temp("mingtasks/libu2/xiushi","finish");
		tell_object(me,"今天的修史工作似乎可以告一段落了，你可以回去复命了。\n");
		return 1;
	}
	me->add_temp("mingtasks/libu2/xiushi_degree",1);
	me->add_busy(3+random(3));
	message_vision("$N从故纸堆中找出了前朝的一些记录……\n",me);
	message_vision(HIC+"$N在草稿上誊抄着"+msg[random(sizeof(msg))]+"，其人……\n"+NOR,me);
	return 1;
}