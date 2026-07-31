// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "玉虚观");
	set("long", @LONG
这里就是玉虚观内了，迎面大亭供着元始天尊的金身塑像，左手边还有一
尊略小点的太乙真人金身塑像，大厅中央站着一位中年道姑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "out" : __DIR__"yuxuguanmen",
	    "east" : __DIR__"shuifang",
            "west" : __DIR__"shufang1",
        ]));
        set("objects", ([
	__DIR__"npc/yuxu" : 1 ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
