// Room: /d/jingzhou/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "萧湘书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师椅上讲学
，那就是当今大儒韩先生了。在他的两侧坐满了求学的学生。一张古意盎然的书案
放在朱先生的前面，案上摆着几本翻开了的线装书籍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "north" : __DIR__"dongdajie1",
  "south" : __DIR__"shuyuan1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoxiang" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
