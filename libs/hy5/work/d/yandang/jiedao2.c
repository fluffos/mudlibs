// Room: /d/yandang/jiedao2.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
街道两边的房子都是用雁荡山中开采来的大石筑成的,由于年代久
远,山石都有些剥落,有些被阴的地方,甚至长出了青苔.据说这种房子
冬暖夏凉,所以当地人很是喜爱,街道的西面有一家客栈.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaohai.c" : 2,
  "/d/hainan/npc/man1.c" : 3,
]));
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xiaolu",
  "west" : __DIR__"kezhan",
  "south" : __DIR__"jiedao",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
