// Room: some place in 西牛贺洲
// uptree.c

inherit ROOM;

void create()
{
  set ("short", "大松树顶");
  set ("long", @LONG
站在大松树的顶端，山风阵阵，空气清新．向山顶仰望，隐约看到一片
房屋在一股淡淡的紫气笼罩之下．
LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"songlin"
]));
set("objects", ([
        __DIR__"obj/guo": 1]));
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


