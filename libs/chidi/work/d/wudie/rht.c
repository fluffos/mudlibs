// Room: /d/wudie/rht.c
// This is a room made by roommaker. write by Xyx.

inherit ROOM;

void create()
{
        set("short", "蕊花堂");
        set("long", @LONG
这是蝶翼山庄的花园，种有各种花卉，园正中有黄花排开来长达数
丈，密密层层，奇香扑鼻。园四周的围墙上种满掉兰，墙边种着牡丹，
皆是稀世珍品。不时不知从何处飞了蝴蝶在花间戏耍！
LONG
);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ydt",
  "west" : __DIR__"pjt",
]));
        set("sleep_room", "1");

        setup();
        replace_program(ROOM);
}
