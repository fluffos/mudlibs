// File		: huating.c
// Created By	: iszt@pkuxkx, 2007-01-22

#include <ansi.h>
#include <room.h>

inherit ROOM;

string look_pingfeng();
int do_watch(string arg);
int do_pick(string arg);
object max_dodge_enemy(object me);

void create()
{
	set("short", "花厅");
	set("long", @LONG
这里是一个小小的花厅，厅前立着一块屏风(pingfeng)，绘着老枝横斜的梅
花，笔意甚是老辣。北首高高悬着一柄宝剑，下面是一个牌位，前面摆着香炉和
若干供品。丈许见方的青石砖上整整齐齐的列了几张木桌椅，西边是白老爷子的
内室，东边一扇小门，通向白老爷子孙女阿绣的闺房。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"tingyuan",
		"west" : __DIR__"neishi",
		"east" : __DIR__"guifang",
	]));
	set("objects", ([
		__DIR__"npc/suwanhong" : 1,
	]));
	set("item_desc", ([
		"pingfeng" : (: look_pingfeng :),
	]));

	create_door("east", "房门", "west", DOOR_CLOSED);

	setup();
}

void init()
{
	add_action("do_watch", ({ "watch", "kan" }));
	add_action("do_pick", "pick");
}

string look_pingfeng()
{
	return "你看着屏风，隐隐觉得其中似乎隐藏着颇为高深的剑意，禁不住想仔细端详一番。\n";
}

int do_watch(string arg)
{
	object me = this_player();
	int times;

	if(!arg || (sscanf(arg, "屏风 %d", times) != 1
		&& sscanf(arg, "pingfeng %d", times) != 1
		&& arg != "pingfeng" && arg != "屏风"))
		return notify_fail("你向四周看了看，隐隐觉得屏风上似乎隐藏着颇为高深的剑意。\n");
	if(me->is_busy())
		return notify_fail("先忙完别的事再说吧。\n");
	if(!times)
		times = 1;
	if(times > 50)
		return notify_fail("学习次数不能超过五十次。\n");
	if(me->query("neili")<5*times || me->query("jing")<50*times)
		return notify_fail("你已经太累了，先休息一下吧。\n");

	message_vision("$N仔细端详着屏风上的画，只觉对雪山剑法的领悟又深了一层。\n", me);
	return 1;
}

int do_pick(string arg)
{
	object me = this_player();
	object ob;
	object target = max_dodge_enemy(me);

	if(arg!="sword")
		return notify_fail("你要取什么？\n");
	if(me->is_busy())
		return notify_fail("先忙完别的事再说吧。\n");
	if(present("su wanhong", this_object()))
		return notify_fail("苏万虹跨上一步，道：「这把剑是先师祖遗物，请不要碰它。」\n");
	if(ob = present("bai zizai", load_object(query("exits/west"))))
	{
		message_vision("$N踏上前去，纵身而起，向悬着的宝剑伸出手去。\n", me);
		message_vision("忽然，从西首的房中一个身影直扑而出，震雷般一声吼：「放下！」\n", me, ob);
		ob->move(this_object());
		ob->kill_ob(me);
		return 1;
	}
	if(me->is_fighting())
	{
		message_vision("激战中$N纵身而起，向悬着的宝剑伸出手去。\n", me);
		if(me->query_skill("dodge") > target->query_skill("dodge"))
		{
			message_vision("但是$n奋起追上，连连出招，硬逼得$N转回身来，反被逼得手忙脚乱。\n", me, target);
			me->start_busy(2);
			return 1;
		}
		if(ob = me->query_temp("weapon"))
			ob->unequip();
		ob = new(__DIR__"obj/baihongjian");
		ob->move(me);
		ob->wield();
		message_vision("$N一把将$n握在手中，顿时如虎添翼！\n", me, ob);
		return 1;
	}
	ob = new(__DIR__"obj/baihongjian");
	ob->move(me);
	message_vision("$N踏上前去，纵身而起，直将$n取了下来！\n", me, ob);
	return 1;
}

object max_dodge_enemy(object me)
{
	object *enemy = me->query_enemy();
	int max = 0, i;

	if( !enemy || !arrayp(enemy) || sizeof(enemy) < 1 )
		return 0;

	for(i=0; i<sizeof(enemy); i++)
		if(enemy[i]->query_skill("dodge") > enemy[max]->query_skill("dodge"))
			max = i;

	return enemy[max];
}