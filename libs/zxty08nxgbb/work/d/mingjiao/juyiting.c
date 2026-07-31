// Room: juyiting.c

inherit ROOM;

void create()
{
        set("short", "聚议厅");
        set("long", @LONG
这里是明教聚议厅，是教中议事的地方。尤其近年来明教各分舵
反元抗暴的起义此起彼伏。时时可以见到教主同教中各位长老在此共
商大计，有时甚至通宵达旦、数日不眠。教中帮众皆尽叹服。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shenghuo-tang",
  "west" : __DIR__"zoulang4",
  "south" : __DIR__"shiwangdian",
  "east" : __DIR__"zoulang3",
]));
        set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fanyao" : 1,
__DIR__"npc/xunluo" : 3,
  __DIR__"npc/youzong" : 3,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

