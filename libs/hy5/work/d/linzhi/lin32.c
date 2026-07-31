// Room: /d/linzhi/lin32.c

inherit ROOM;

void create()
{
	set("short", "德兴藤网桥东");
	set("long", @LONG
你来到德兴藤网桥东面，再向西去就上桥了。据说此桥已经
有300 多年历史了。藤网桥整个呈管状悬空，横跨雅鲁藏布江，
长约400 米左右。看来没有较高的胆亮和平衡的技巧很难顺利过
江。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin31",
  "west" : __DIR__"lin33",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));

        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}
