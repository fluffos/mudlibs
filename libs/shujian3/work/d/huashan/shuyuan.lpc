// Room: /d/huashan/celang4.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "书院");
        set("long", @LONG
这里是华山派的书院，平时华山派弟子在习武之余，都遵从师命到此学习
武功秘籍，来提高自己的修为，特别是华山心法。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"celang4",
		"north" : __DIR__"wuqiku",
	]));

	set("objects",([
		__DIR__"obj/zhengqijue" : 1,
//        __DIR__"obj/ziyin_book" : 1,
	]));

	set("no_clean_up", 0);
	set("indoors", "华山" );

	set("coor/x",100);
  set("coor/y",-30);
   set("coor/z",80);
   setup();
}
