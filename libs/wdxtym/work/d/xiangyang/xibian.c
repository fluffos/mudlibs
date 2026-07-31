// Room: /d/xiangyang/xibian.c  溪边
// Date: Jan. 28 2002 by Pound

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "溪边");
	set("long", @LONG
这里是大路边数十丈处的田埂，有一条清澈的小溪（xiaoxi）蜿蜒盘
桓。此处方圆数里四下少有人烟，田地也有些荒芜。只是南边有几间茅舍
和一大片清香四溢的花圃，跟这边的冷清形成了鲜明对比。
LONG );
	set("outdoors", "xiangyang");
	set("resource/water", 1);
	set("exits", ([
	    "south" : __DIR__"huapu",
	]));
	set("item_desc", ([
	    "xiaoxi" : "这是一条小溪，溪水清澈透底，可以在这里舀水(yao shui)浇花。\n",  
	]));

	setup();
//      //replace_program(ROOM);
}

int init()
{
	add_action("do_fill", "fill");
    
}

int do_fill(string arg)
{

	object me, ob;
	me = this_player();
	ob = present("shui tong", me);
	
	if (! arg || (arg != "tong" && arg != "shuitong" && arg != "shui tong"))
	    return notify_fail("你要往什么里面装水？\n");   
	if (! ob) return
	    notify_fail("你没有带水桶，怎么装水？\n");
	if (me->is_busy())
	    return notify_fail("你正忙着呢！\n");
/*      if (ob->query("water_level") > 4)
	    return notify_fail("桶里已经盛满了水了。\n");
*/
	if (random(20) == 1)
	{ 
	    message_vision(HIR "$N" HIR "不小心一个趔趄，手上一滑,把桶掉到小溪里被冲走了。"NOR"\n", me);
	    destruct(ob);
	    return 1;
	}
	message_vision("$N弯下腰，把桶放进清澈的小溪里装满了水。\n", me);
	ob->set("water_level", 5);
	ob->set("long", HIY "这是一副特制的水桶。" NOR + HIC "里面装满了水。"NOR"\n");
	me->start_busy(3 + random(2));
	me->receive_damage("jing", (28 + random(3)));
	return 1;
}