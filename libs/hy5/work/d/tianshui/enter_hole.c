// Room: /d/china/junying/xiaozhen/enter_hole.c

inherit ROOM;

void create()
{
	set("short", "山洞入口");
	set("long", @LONG
这里是山洞的入口，脚下野草丛生，地上有一些不知什么动
物留下的脚印，前面是一个黑乎乎的山洞，不知里面会有什么危
险。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole",
  "south" : __DIR__"xiaolu3",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
