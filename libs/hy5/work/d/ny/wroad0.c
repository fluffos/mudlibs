
// Room: /d/snow/wroad0.c

inherit ROOM;

void create()
{
	set("short", "黄土小路");
	set("long",
"你正置身于一片竹林之中，一条弯弯曲曲的小路穿行其中，竹林很茂密，遮住了天空，四周\n"
"一片寂静，不时的传来几声鸟叫。路边开放着星星点点的野花。突然，草丛中跳出一只青蛙\n"
"，对着一只蚂蚱大叫：可恶！又是你！看招！青蛙张开血盆大口向蚂蚱咬去，蚂蚱面色苍白\n"
"转身蹿入草丛，青蛙得意万分仰天狂笑：哈！哈！我才用了基本嘴法！你就。。。话音未落\n"
"，草丛中跳出无数蚂蚱，组成一个大阵，齐声喝道：丐帮有打狗阵，我们新练成杀蛙阵法，\n"
"就拿你牛刀小试！青蛙大惊失色，转身苍惶逃去，，，\n"
);
	set("exits", ([ /* sizeof() == 2 */
//  "north" : __DIR__"yamen_square",
  "southwest" : __DIR__"wroad1",
]));
	set("no_clean_up",0);
	set("objects", ([ /* sizeof() == 2 */
__DIR__"npc/dog":1,]));
	setup();
	replace_program(ROOM);
}
