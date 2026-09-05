// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "礼部侍郎值房");
	set("long", @LONG
这里是礼部侍郎的值房。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","libu2");
	set("exits", ([
		"southwest" : __DIR__+query("yamen")+"court",
	
	]));
	set("objects", ([
          __DIR__"npc/li2_shilang" : 1,
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
	if (me->query_temp("songtasks/libu2/task")!=4)
	{
		return 0;
	}
	if (me->query_temp("songtasks/libu2/fengchan_partner"))
	{
		return notify_fail("你已经指定了这次封禅的助手是"+me->query_temp("songtasks/libu2/fengchan_partner_name")+"了。\n");
	}
	if (!arg)
	{
		return notify_fail("你要指定谁作为这次封禅的助手？\n");
	}
	if (!pl=find_player(arg))
	{
		return notify_fail(arg+"并不在线！\n");
	}
	if (!pl->query("song/pro"))
	{
		return notify_fail(arg+"不是大宋官员。\n");
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
	me->set_temp("songtasks/libu2/fengchan_partner",pl);
	me->set_temp("songtasks/libu2/fengchan_partner_name",pl->query("name"));
	pl->set_temp("songtasks_libu2_fengchan",me);
	pl->set_temp("songtasks/libu2/task",4);
	pl->set_temp("songtasks/libu2/start",1);
	message_vision("$N指定了$n作为此次封禅泰山的助手。\n",me,pl);
	tell_object(pl,me->query("name")+"选择了你作为大宋封禅泰山的助手。\n");
	tell_object(me,"到达泰山封禅台后封禅(fengshan)即可完成任务。\n");
	tell_object(pl,"到达泰山封禅台后封禅(fengshan)即可完成任务。\n");
	return 1;
}
int do_xiushi()
{
	object me=this_player();
	string *msg=({
"唐高祖李渊，神尧大圣大光孝皇帝",
"唐太宗李世民，文武大圣大广孝皇帝",
"唐高宗李治，天皇大圣大弘孝皇帝", 
"唐中宗李显，大和大圣大昭孝皇帝",
"唐睿宗李旦，玄真大圣大兴孝皇帝",
"唐玄宗李隆基，至道大圣大明孝皇帝",
"唐肃宗李亨，文明武德大圣大宣孝皇帝 ", 
"唐代宗李豫，睿文孝武皇帝", 
"唐德宗李适，神武孝文皇帝", 
"唐顺宗李诵，至德大圣大安孝皇帝",
"唐景宗李柷，昭宣光烈哀孝皇帝 ",
	});
	if (me->query_temp("songtasks/libu2/2/finish"))
	{
		tell_object(me,"修唐史已经告一段落，回去复命吧。\n");
		return 1;
	}
	if (me->query_temp("songtasks/libu2/task")!=2)
	{
		tell_object(me,"谁让你来乱搞的？别弄乱了礼部的资料。\n");
		return 1;
	}
	if (me->is_busy())
	{
		tell_object(me,"你修史过于疲劳，等一下再继续吧。\n");
		return 1;
	}
	if (me->query_temp("songtasks/libu2/xiushi_degree")>5)
	{
		me->set_temp("songtasks/libu2/2/finish",1);
		tell_object(me,"今天的修史工作似乎可以告一段落了，你可以回去复命了。\n");
		return 1;
	}
	me->add_temp("songtasks/libu2/xiushi_degree",1);
	me->add_busy(3+random(3));
	message_vision("$N从故纸堆中找出了前朝的一些记录……\n",me);
	message_vision(HIC+"$N在草稿上誊抄着"+msg[random(sizeof(msg))]+"，其人……\n"+NOR,me);
	return 1;
}