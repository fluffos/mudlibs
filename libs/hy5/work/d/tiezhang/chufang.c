// Room: /u/zqb/tiezhang/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
    这里是铁掌帮的厨房。正面是一个大炉灶，几乎占去了一半的房
间。灶上留有很多火眼，可同时做很多种菜。几位帮中高薪聘来的厨子正在 
来回忙碌着。整间屋内弥漫着各种饭菜的香味，闻了让人垂涎欲滴。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoulang-3",
]));
	set("objects", ([ 
               __DIR__"obj/hsnr" : 1,
               __DIR__"obj/ruzhu" : 1,
               __DIR__"obj/fan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
