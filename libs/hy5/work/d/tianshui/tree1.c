// Room: /d/china/junying/xiaozhen/tree1.c

inherit ROOM;

void create()
{
	set("short", "大树上");
	set("long", @LONG
这里是树上
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object room;
	if(!arg || arg == "") return 0;
	if(arg != "tree" && arg != "大树") return 0;
	message_vision("$N往大树上爬去。\n",this_player());
	this_player()->move(__DIR__"tree2");
	room = find_object(__DIR__"tree2");
	tell_object(room,this_player()->name()+"从下面爬了上来。\n");
	return 1;
}