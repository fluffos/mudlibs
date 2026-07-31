// Room: /d/suzhou/shuyuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位老夫子坐在太师
椅上讲学。在他的两侧坐满了求学的学生。一张古意盎然的书案放在
他的前面，案上摆着几本翻开了的线装书籍。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"nandajie1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/jiaoxi" : 1,
	]));
//	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
