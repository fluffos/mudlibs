inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是书房，靠墙一排大书架，摆放着很多的书籍，昆仑三圣何足道以
琴棋而号称以“圣”，故昆仑派一直引以为荣，鼓励弟子学琴棋艺。一眼
望过去，似乎有关于不少琴棋方面的书。
LONG
	);
	set("exits", ([
		"west"  : __DIR__"shilu1",
	]));
/*	
set("objects", ([
		"/d/village/obj/zhujian" : 2,
	]));
*/
	
	setup();
	replace_program(ROOM);
}
