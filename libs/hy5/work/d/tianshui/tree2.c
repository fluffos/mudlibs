// Room: /d/china/junying/xiaozhen/tree2.c

inherit ROOM;

void create()
{
	set("short", "大树上");
	set("long", @LONG
这里是树上，树枝上还挂着一个鸟巢。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tree1",
]));
	set("no_clean_up", 0);
	set("bird",1);
	setup();
}

void init()
{
	add_action("do_tao","tao");
}

int do_tao(string arg)
{
	object obj;
	if(!arg || arg == "") return 0;
	if(arg != "鸟巢" && arg != "nest") return 0;
	if(!query("bird")) 
	message_vision("$N伸手向鸟巢里掏了几下，里面什么也没有。\n",this_player());
	else {
	obj = new(__DIR__"npc/bird");
	obj->move(this_object());
	message_vision("$N伸手向鸟巢里掏了几下，从里面跳出一只小鸟。\n",this_player());
	set("bird",0);
	this_player()->set_temp("tao_bird",1);
	}
	return 1;
}