// Room: /d/huashan/dashu.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  HIW "山崖" NOR);
	set("long", @LONG
这里是一个数丈高的山崖，你抬头一看，发现山崖上生长着一些不知名的
草药。似乎可以采下来吃掉。你不住的往上看，竟然没注意到这里没有任何出
路。
LONG
);

	set("no_clean_up", 0);

	set("outdoors", "华山" );
	setup();
}

void init()
{
        add_action("do_tiao", "tiao");
//        add_action("do_cai", "cai");
}

int do_cai(string arg)
{
	object ob;
        object me = this_player();

	if (arg != "lingzhi")
                return notify_fail("你要采什么？\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

	if(me->query("family/family_name") !="华山派")
                return notify_fail("一个声音自空中响起，“这里是华山禁地，你还是赶快离开吧！”\n");

        if ( (int)me->query("jingli")<400)
        	{
             	write("你现在太累了，休息一下吧！\n");
		return 1;
		}
        if(random(20)!=3)
        	{
        	me->add("jingli",-random(300));
        	return notify_fail("你四下找了半天，什么也没找到。\n"); 
         	}

	if (present("lingzhi", me))
                return notify_fail("你身上已经有灵芝草了，莫要贪得无厌！\n");
        message_vision("$N伸手采下一棵灵芝草。\n", me);
        ob = new(__DIR__"obj/lingzhi");
        ob->move(me);
	return 1;
}

int do_tiao(string arg)
{
        object me = this_player();
	if (arg != "xiaoxi")
                return notify_fail("你要往哪里跳？\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
	if ((int)me->query("max_neili") < 401)
		return notify_fail("你尝试着跳过小溪。却发现自己跳不过去。\n");
	message_vision("$N一个纵身，向对岸跳过去。\n", me);
	tell_object(me, "你发现自己跳回了刚才来的地方。\n");

        me->receive_damage("jing", 30);
	me->move(__DIR__"xiaoxi");
	message_vision("$N从小溪那边跳了过来。\n", me);

        me->start_busy(random(2));
        return 1;
}

