// haitan.c

#include <ansi.h>

inherit ROOM;

void home(object ob);

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里就是神龙岛了。南边是一望无际的大海；往北则是一片灌木
林。岛上的空气似乎又热又闷, 咸湿的海风中带着一股腥臭，又夹杂
了一缕奇特的花香，闻起来十分怪异。海边泊着一艘大船(chuan)。
LONG );

	set("item_desc", ([
		"【大船】" : "这是神龙岛对外联系的大船。岛上的客人或弟子只要上船(enter)就可以回中原。\n"
		ZJOBACTS2"上船:enter chuan\n",
	]));
	set("exits",([
		"north" :__DIR__"lin1",
	]));
	set("outdoors", "shenlong");
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter ( string arg )
{
	object ob;
	string dir;

	ob = this_player();
	if (arg != "chuan")
	{
		tell_object(ob , "你要 enter 哪儿？\n");
		return 1 ;
	}

	message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
	message_vision("船夫升起帆，船就向西方航行。\n", ob);
	ob ->move(__DIR__"dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久......."NOR"\n");
	    if(ob->query("party/party_name") == "神龙教")
	call_out("home", random(3) , ob);
	else
	call_out("home", 10 , ob);
	return 1 ;
}

void home(object ob)
{
	if (! objectp(ob) || find_object(__DIR__"dahai") != environment(ob))
		return;

	tell_object(ob, "大船终于抵达了中原的一个繁华城市。你走下船来。\n");
	ob->move("/d/beijing/haigang");
}
