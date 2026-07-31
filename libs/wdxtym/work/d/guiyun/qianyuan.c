// Room: /guiyun/qianyuan.c
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这里是归云庄的前院，相当宽敞。左右靠墙各建有几间低矮的
平房，像是家人的住处。正前方几棵树木，湖中清风吹来，落叶萧
萧而下。树木再往后是一间大厅。右首有一对白雕(diao)。原来这
里是桃花岛为方便弟子回岛的。
LONG );
	set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("item_desc", ([
		"diao" : "一对白雕正展翅欲飞。如果是桃花岛的弟子，\n"
		"骑上(ride)就可以飞回桃花岛。\n",
	]));

	set("exits", ([
		"out"   : __DIR__"damen",
		"north" : __DIR__"dating",
	]));
	setup();
}

void init()
{
	add_action("do_ride", "ride");
}
int do_ride()
{
	mapping myfam;
	object ob = this_player();

	myfam = (mapping)ob->query("family");
	if (! myfam || myfam["family_name"] != "桃花岛")
	{
		message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然猛然一颠...\n"
		HIR "结果$N" HIR "摔了个鼻青脸肿！"NOR"\n"
		"看来白雕对$N并不感兴趣，它只认识桃花岛的弟子。\n", ob);
		ob->receive_damage("qi", 50);
		ob->receive_wound("qi", 50);
		return 1;
	}

	if (objectp(query_temp("sb_ride"))) 
	{
		message_vision("现在白雕正忙着,请过一会再乘坐！\n", ob);
		return 1 ;
	}
	set_temp("sb_ride", ob);
	message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n"
		       "但看一雕一人身形渐渐缩小，终至不见。\n", ob);
	ob->move("/d/taohua/lantian");
	tell_object(ob, CYN "\n你不断地飞呀飞，万水千山身下飘过......"NOR"\n");
	call_out("taohua", 1, ob, environment(ob));
	return 1;
}

void taohua(object ob, object env)
{
	if (! objectp(ob))
		return;

	if (query_temp("sb_ride") == ob)
    		delete_temp("sb_ride");

	if (environment(ob) != env)
		return;

	tell_object(ob, "你终于飞到了桃花山庄，白雕落了下来。\n\n");
	ob->move("/d/taohua/damen");
}

