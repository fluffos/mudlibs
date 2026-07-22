// jinku.c
// this is made by leontt
// update 2000.10.04

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"密室"NOR);
	set("long",
"这里是慕容博墓内的一个密室。地上放了几个金光闪闪的"HIC"大箱子"NOR"(box)。\n"
"墙上挂满了大燕国历代皇帝的画像。正当中摆着一把"HIY"龙椅"NOR"(chair)。\n"
);
	set("exits",([
		"south" : __DIR__"fenmu",
	]));
	set("item_desc", ([
		"chair" : "这张龙椅左右扶手上各有一个雕工精细的龙头(tou)。\n",
		"box": "这是一个雕刻精美，古色古香的大箱子，里面肯定有不少宝物。\n",
	]));
	setup();
}

int init()
{
	add_action("do_sit","sit");
	add_action("do_zhuan","zhuan");
	add_action("do_open","open");
}

int do_sit(string arg)
{
	object me = this_player();
	if ( !arg || (arg != "chair") )
		return notify_fail("你要坐什么上面？\n");
	if (me->query("family/family_name") != "姑苏慕容")
		return notify_fail("你不是姑苏慕容家的人，坐在这你不觉得羞耻么？！\n");
	if (me->query_temp("mark/sit"))
		return notify_fail("你已经坐下了。\n");
        me->set_temp("mark/sit", 1);
        return notify_fail("你咳嗽一声，大摇大摆的坐在了龙椅上。\n");
}

int do_zhuan(string arg)
{
	object me = this_player();
	if ( !arg || ((arg != "left tou") && (arg != "right tou")) )
		return notify_fail("你要转什么？\n");
	if (me->query("family/family_name") != "姑苏慕容")
		return notify_fail("你要做什么 ？！\n");
        if (!me->query_temp("mark/sit"))
                return notify_fail("你要做什么 ？！\n");
	if ((int)me->query("neili") < 6000 )
                return notify_fail("你白费了半天劲，结果什么也没转动。\n");
	if (arg == "left tou"){
		me->add_temp("left/tou",1);
		tell_object(me,"你把左边的龙头转了一圈。\n");
	}
	if(arg == "right tou"){
		me->add_temp("right/tou",1);
		tell_object(me,"你把右边的龙头转了一圈。\n");
	}
	if((int)me->query_temp("left/tou") == 5
	 &&(int)me->query_temp("right/tou") == 6){
		message_vision("只见龙椅突然转到了墙后，再转出来的时候$N已经不见了。\n",me);
		me->move(__DIR__"mishi1");
		message_vision("只见墙壁翻转，$N从墙后转了出来。\n",me);
	}
	if((int)me->query_temp("left/tou") > 5
	 ||(int)me->query_temp("right/tou")> 6){
		me->delete_temp("left/tou");
		me->delete_temp("right/tou");
	}
        return 1;
}

int do_open(string arg)
{
	object me = this_player();
	if (!arg || (arg != "box"))
		return notify_fail("你要打开什么？\n");
	message_vision("只见一阵乱箭射出，$N哼都没哼，倒地而亡。\n",me);
	me->set_temp("last_damage_from", "误撞机关被乱箭射");
	me->die();
	return 1;
}
