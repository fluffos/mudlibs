// shufang.c
// Created by Numa 19991022
// Modify By River@SJ 2003.1.9

#include <ansi.h>
inherit ROOM;

mapping *book = ({
	(["name":	"制作毒药",
	  "color":	HIR,
	  "show":	"红铜色",]),
	(["name":	"能够长生不老",
	  "color":	HIC,
	  "show":	"青铜色",]),
	(["name":	"返老还童",
	  "color":	HIY,
	  "show":	"黄铜色",]),
	(["name":	"提炼仙丹",
	  "color":	HIG,
	  "show":	"绿铜色",]),
	(["name":	"解毒",
	  "color":	HIM,
	  "show":	"紫铜色",]),
});

string do_have();
string do_see();

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是杨莲亭的书房，书案上面摆着几摞书。墙边立着一个书架，里面层
层叠叠的摆放着一摞一摞的书。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"changlang3",
	]));
	set("item_desc",([
		"书架":		(: do_have :),
		"shujia":	(: do_have :),
		"书籍":		(: do_see  :),
		"shuji":	(: do_see  :),
	]));
	setup();
}

void init()
{
	add_action("do_get",({"na", "qu"}));
	add_action("do_fankan",({"fan", "fankan"}));
	add_action("do_open","open");
}
	
string do_have()
{
	object me = this_player();
	
	me->set_temp("shufang/have",1);
	return "一个十分宽大的书架，上面放着不少书籍。\n";
}

string do_see()
{
	object me = this_player();
	
	if (!me->query_temp("shufang/have"))
		return "你顺手翻看了几本书，没发现有什么异样。\n";
	me->delete_temp("shufang/have");
	me->set_temp("shufang/see",1);
	return "你仔细看了看这些书籍，发现有一套五本古籍似乎很显眼，你禁不住想要取下来翻看。\n";
}

int do_get(string arg)
{
	object me = this_player();
	string tar;
	int i;

	if ( me->query_temp("shufang/getkey"))
		return notify_fail("你已经发现这本书有不同了，还是研究下吧。\n");
	
	if (!me->query_temp("shufang/see"))
		return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("shufang/shu"))
		return notify_fail("你已经取下一本书了，还是先翻看下吧。\n");

	if (!arg || sscanf(arg,"%s %d from %s",arg,i,tar)!=3)
		return notify_fail("你要从哪里取第几本书啊？\n");

	if (arg != "shu" && arg != "书")
		return notify_fail("你要取什么？\n");

	if (i > 5 || i < 1)
		return notify_fail("你要取第几本书？\n");

	if (tar != "jia" && arg != "书架")
		return notify_fail("你从哪里取？\n");
	
	me->set_temp("shufang/shu",i);
	message_vision("$N从书架上面抽出第" + CHINESE_D->chinese_number(i) + "本书拿下来翻看。\n",me);
	return 1;
}

int do_key(object me)
{
	tell_object(me,"你突然发现这本古籍似乎重量和别的有些不同，好像有什么东西藏在这本书中。\n");
	me->set_temp("shufang/getkey",1);
}

int do_fankan(string arg)
{
	object me = this_player();
	mapping book_info;
	int i;

	if ( me->query_temp("shufang/getkey"))
		return notify_fail("你已经发现这本书有不同了，还是研究下吧。\n");

	if (!me->query_temp("shufang/shu") && !wizardp(me)) return 0;

	if (!arg)
		return notify_fail("你要翻看什么？\n");

	if (arg != "shu" && arg != "书")
		return notify_fail("你要翻看什么？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	i = me->query_temp("shufang/shu");
	i = random(i) + 1;
	book_info = book[i];
	tell_object(me,book_info["color"]+"这是一本讲述如何"+ book_info["name"] +"的古籍，封面呈"+ book_info["show"] +"，书页已经泛黄且残缺了几页。\n"NOR);
	if ( random(5)) {
		me->delete_temp("shufang/shu");
		tell_object(me,"你翻看了几页，并没有什么特别之处，于是又放了回去。\n");
	}
	else {
		me->delete_temp("shufang/shu");
		do_key(me);
		me->start_busy(1);
	}
	return 1;
}

int do_open(string arg)
{
	object me = this_player();
	object obj, ob;
	
	if (!me->query_temp("shufang/getkey")) return 0;

	if (!arg)
		return notify_fail("你要打开什么？\n");

	if (arg != "shu" && arg != "书")
		return notify_fail("你要打开什么？\n");
	
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	tell_object(me,"你打开书的封页，发现里面是一个夹层。\n");
	ob = unew(__DIR__"obj/key");
	if ( !random(3) || !clonep(ob)) {
		if( clonep(ob)) 
			destruct(ob);
		message_vision("$N正要打开手中的古籍，突然，一位日月神教长老冲了进来。\n",me);
		me->delete_temp("shufang/getkey");
		obj = new(__DIR__"npc/zhanglao");
		obj->set_temp("target",me->query("id"));
		obj->move(environment(me));
		me->start_busy(random(2));
		return 1;
	}
	message_vision("$N缓缓打开手中古籍的夹层，取出了钥匙。\n",me);
	me->delete_temp("shufang");
	ob->set_temp("owner",me->query("id"));
	ob->move(me);
	return 1;
}
