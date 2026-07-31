
// Room: /d/snow/guestroom.c

inherit ROOM;

void create()
{
	set("coor",({-20,-55,0}));
	set("short", "客房");
	set("long",
"这里是一间布置得相当雅致的厢房，从窗子可以看到北边的天井跟南边的庭园中各式各样的\n"
"奇花异草，以及他们所带来的淡淡香气，厢房的东面墙上还挂著一幅仕女图(painting)，画\n"
"中是一位宫装美妇,北面是通往天井的出口。\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"inneryard",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "painting" : "这是幅工笔细腻的仕女图，平常人家不可能有此类
物件。
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
