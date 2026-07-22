// Room: /d/emei/baoguoshi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "报国寺" NOR);
	set("long",@LONG
报国寺是峨眉山最大寺院之一。寺庙倚山建造，弥勒殿、大雄殿、七佛殿
逐级升高，规模宏大。殿内佛像金光闪闪，气宇轩昂。寺内芳草迷径，花开不
绝。这里有一座华严塔(ta)。寺门上面高悬一块九尺见长的牌匾，上书五个斗
大字“天下第一派”。这里向西，约二里可达伏虎寺。
LONG);
	set("item_desc", ([ 
		"ta" : HIC"    这是一座十五层的紫铜铸华严塔。塔高七米，塔身周匝共有小佛四千七百\n"+
			"尊之多，并铸有《华严经》全文两万多字，其冶炼工艺与雕工技巧，已造至极\n"+
			"至美之境。\n"NOR,
	]));
	set("objects",([
		__DIR__"npc/xiangke" : 2,
	]));

	set("exits", ([ 
		"southwest" : __DIR__"milin",
		"enter" : __DIR__"daxiongdian",
		"west" : __DIR__"baoguosixq",
		"east" : __DIR__"baoguosm",
	]));

	setup();
}

void init()
{
	add_action("do_du", "read");
}

int do_du(string arg)
{
	object me;
	me = this_player();
	
        if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	if ((int)me->query("jing") < 30 )
		return notify_fail("你太累了，无法继续学习了！\n");

	if ((int)me->query_skill("dacheng-fofa", 1) < 100 )
		return notify_fail("看来华严塔上佛法对你来说太难了。\n");

	if ((int)me->query_skill("dacheng-fofa", 1) > 120 )
		return notify_fail("你已经尽数领悟了华严塔上佛法的意义。\n");

	if( !arg || arg != "ta" || arg == "")
		return notify_fail("你要读什么？\n");

	if ((int)me->query_skill("literate", 1) < 100 )
		return notify_fail("你看了华严塔上的经文，只觉得头晕脑涨，跟看天书一样。\n");
	
	if( arg == "ta") {
		me->receive_damage("jing", 20+random(10));
		me->improve_skill("dacheng-fofa", me->query("int"));
		message_vision("$N正在专心研读华严塔上的华严经文。\n", me); 	
		return 1;
	}
}
