// Room: /d/linzhi/wenquan05.c

inherit ROOM;

void create()
{
	set("short", "林芝温泉群区");
	set("long", @LONG
这里是林芝地区的布加沟温泉群区。上泉名“尼姑泉”，海
拔4200米，中泉名“喇嘛泉”，下泉为布加泉。如果你身体有什
么不适，赶快来这里泡泡吧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wenquan06",
  "west" : __DIR__"wenquan04",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/man" : 2,

]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
