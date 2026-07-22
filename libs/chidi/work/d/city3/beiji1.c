//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "北大街");
        set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。
南边显得很繁华热闹。东边是一座两层的楼阁，挂着“陈麻婆豆腐”
的招帘，门额上悬挂一方横匾，“麻到为止”四字擦得闪闪发亮，乃
是陈麻婆老公--苏轼的手笔。阵阵辣椒香味扑鼻而来,让你垂涎欲滴。
西边是一座古朴的祠堂，香火缭绕，游人络绎不绝,那就是川人所共
同敬仰的武侯祠。
LONG
        );

        set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"beidajie2",
                "west" : __DIR__"wuhou",
                "east" : __DIR__"chenmapo",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


