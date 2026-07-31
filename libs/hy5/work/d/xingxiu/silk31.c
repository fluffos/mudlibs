// /d/xingxiu/silk1.c
// June 97
// by pishou

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。迎面而来的是一个个沙包，星罗棋布於荒原之
上。一阵风沙吹过，象刀割一样撕裂着你的脸。东南过仇池山通往嘉峪关，西
面则是颂摩崖。
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "westup" : __DIR__"silk32",
                "south" : __DIR__"silk3",
        ]));


        setup();
//        replace_program(ROOM);
}

