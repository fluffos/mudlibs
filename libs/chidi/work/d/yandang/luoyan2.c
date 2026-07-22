// Room: /d/yandang/luoyan2.c

inherit ROOM;

void create()
{
	set("short", "落雁山庄");
	set("long", @LONG
在你面前的是一座宏伟的庄园,迎面是两扇大门,门前的白玉台阶一
尘不染,两边的两个石狮足有一人多高,门楣上有一块匾额,据说是落雁老
人晚年手书.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/menwei.c" : 2,
]));
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan3",
  "south" : __DIR__"luoyan1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "匾额" : "上面黑底白字,落雁山庄四字笔力纵横,如剑气横空.
",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	string fam;
	object npc;

	fam=(string)me->query("family/family_name");
	npc=present("men wei",this_object());
	if( fam && fam!="雁荡派" && dir=="north" && objectp(npc))
	return notify_fail("山庄门卫冲你一瞪眼道：干什么你！？\n");
	return ::valid_leave(me,dir);
}

