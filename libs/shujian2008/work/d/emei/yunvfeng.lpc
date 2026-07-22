// Room: /d/emei/yunvfeng.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "玉女峰" NOR);
	set("long", @LONG
这是归云阁边的玉女峰，峰顶有一个四尺见方的小池，深亦四尺，四季不
枯，传为天女沐浴之器。古时州刺史冯楫，曾在此结茅而居，发奋诵读《华严
经》，不食人间烟火，于是玉女下凡，为他馈赠食物。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([ 
	  "northdown" : __DIR__"guiyunge",
]));
	set("objects",([
		CLASS_D("emei") + "/fang-bilin" : 1,
]));
	setup();
}

void init()
{
	add_action("do_wash", "wash");
}

int do_wash(string arg)
{
	object me;
	int i;

	me = this_player();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");

	if( !arg || arg == "" || arg != "face" )
	return notify_fail("你要干什么？\n");

if( (int)me->query_skill("beauty", 1) < 41 )
	return notify_fail("你在池中洗脸，觉得清凉的泉水好舒服，透过倒影看自己越发漂亮了。\n");

	if( arg == "face" && (int)me->query_skill("beauty", 1) < 120 && (int)me->query_skill("beauty", 1) ) {
	message_vision("$N在池中洗脸，觉得清凉的泉水好舒服，透过倒影看自己越发漂亮了。\n", me);
	i = me->query("kar");
	me->improve_skill("beauty", random(i) * 4);
	me->receive_damage("jingli", random(i) * 2);
	return 1; }
}
