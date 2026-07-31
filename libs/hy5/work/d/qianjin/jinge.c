inherit ROOM;
void create()
{
        set("short", "不眠阁");
        set("long", @LONG
此阁无顶。每当深夜，微风袭袭，繁星点点；一轮明月，悬于正央。放眼眺望，
北京城尽收眼底。苍穹暗淡，唯阁烛一盏；万物尽淡，唯英雄美人。。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"secfloor",
]));
        set("objects", ([
        __DIR__"npc/lin" : 1,
	__DIR__"npc/afei" : 1,
                        ]) );

	set("outdoors","qianjin");
        set("coor/x",-150);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
