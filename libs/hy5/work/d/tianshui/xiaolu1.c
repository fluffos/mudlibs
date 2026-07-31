// Room: /d/tianshui/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是天水镇外通往中原的一条小路，路边有一棵大树。往
西看天水镇的东口遥遥在望，一条土路向东延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ekou",
  "northeast" : __DIR__"xiaolu2",
]));
	set("item_desc",([
	"tree" : "一棵参天的大树。\n",
	"大树" : "一棵参天的大树。\n",
]));

	set("objects",([
	"/clone/npc/man" : 4,
]));

	set("outdoors","tianshui");
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
	this_player()->move(__DIR__"tree1");
	room = find_object(__DIR__"tree1");
	tell_object(room,this_player()->name()+"从下面爬了上来。\n");
	return 1;
}
