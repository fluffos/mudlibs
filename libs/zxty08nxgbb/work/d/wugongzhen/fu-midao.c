// fu-midao.c 密道
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "密道");
        set("long", @LONG
这里是侯员外卧室下的密道，听说许多佃户由于缴不起租，被侯
员外的爪牙抓到这里来拷打。四周好象有一些浅褐色干的血渍，空气
中夹杂着一种令人毛骨悚然的腥气。你不由地有些害怕起来，心想还
是赶快离开这里吧。
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"fu-mishi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

