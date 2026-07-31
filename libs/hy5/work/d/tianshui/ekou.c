

inherit ROOM;

void create()
{
	set("short", "天水镇东口");
	set("long", @LONG
这里是天水镇的东口。天水镇虽说只是一个有着几十户人家
的小镇子，但由于地处要冲，所以天下闻名。东面是一条蜿蜒的
小路向远方伸展。
LONG
	);
	set("exits", ([

  "west" : __DIR__"eroad3",
  "east" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();


	replace_program(ROOM);
}
