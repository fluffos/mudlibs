// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/wenquan.c

inherit ROOM;

void create()
{
	set("short", "温泉");
	set("long", @LONG
走到这里，一股热气腾腾的白雾将你团团围住，你已经来到了温泉边。泉
中清水碧波荡漾，异常清澈，水面雾气缭绕。相传在此温泉浴后，白发变黑，
返老还童。有许多人正在里面闭目坐浴。
LONG
        );
	set("outdoors", "长安");
	set("exits", ([
		"west" : __DIR__"baishulin2",
	]));

	set("incity",1);
	setup();
}

void init()
{
	add_action("do_wash","wash");
}

int do_wash()
{
	object me=this_player();
	object weapon = me->query_temp("weapon");
	object *inv;
	int i;
        
	if(!living(me) ) return 0;
	if(me->query_temp("do_wash") > 0) return notify_fail("你已经在温泉中了！\n");
	if ( me->query("gender") == "男性" ) {
		tell_object(me, "你一个大老爷们做那些事情干什么？\n");
		return 1;
	}
	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着哪！\n");

	if((me->query_encumbrance()*20) > me->query_max_encumbrance()) 
		return notify_fail("你身上的东西太多了！\n");

	if (weapon) 
		return notify_fail("不要那么紧张啊，洗澡还拿着武器？\n");

	inv= all_inventory(me);
	i = sizeof(inv);
	while (i--)
	if( inv[i]->query("equipped") && (! inv[i]->query_autoload() && inv[i]->query("id") != "lingpai"))
		return notify_fail("身上穿着衣服怎么洗澡？\n"); 

	message_vision("只听“扑通”一声，$N已经跳进了温泉里。\n",me);
	if(me->query("jingli") < 50) {
		write("但是你感觉泉水变得滚烫，急忙从里跳了出来！\n",me);
		me->unconcious();
		return 1;
	}
	me->add("jingli", -100);
	me->set_temp("do_wash",1);
	call_out("over_wash", 10, me);     
	return 1;
}

void over_wash(object me)
{
	if(!me) return;
	if( me && environment(me) == this_object()) {
		message_vision("$N容光焕发的从温泉中走了出来！\n", me);
		if (me->query_skill("beauty", 1) > 120)
			me->improve_skill("beauty", random(me->query("con"))*2);
		me->delete_temp("do_wash",1);
	}
	return;
}
