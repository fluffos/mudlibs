// Room: /d/jinghai/moon31.c

inherit ROOM;

void create()
{
	set("short", "牢房甬道");
	set("long", @LONG
这里是一条狭窄的过道，它是通向各个牢房得通道。四壁用
大块的青石砌成。甬道内只有墙壁上的小油灯，格外昏暗。偶尔
会听见还有滴答滴答的流水声音。甬道北侧有一扇[死牢]门。里
面不时传来大声得喊叫。令人毛骨悚然。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"moon36",
  "west" : __DIR__"moon30",
  "south" : __DIR__"moon33",
]));

	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;

	me= this_player();

	if( !arg && arg != "死牢" && arg != "silao")
		return notify_fail("要打开什么？\n");

	if( !(key = present("si key", me)) ) 
		return notify_fail("不用钥匙，您老想踹开它？\n");

	if( !(nroom = find_object(__DIR__"moon32")) )
		nroom= load_object(__DIR__"moon32");

	set("exits/enter", __DIR__"moon32");
	message("vision", "只听喀嚓一声，死牢门漫漫升起。\n",this_object() );

	me->set_temp("used_key3", 1);
	call_out("close",10,me);
	return 1;
}

int close()
{
	message("vision", "只听喀啦喀啦几声巨响死牢门迅速关上了。\n", this_object() );
        delete("exits/enter");
}
