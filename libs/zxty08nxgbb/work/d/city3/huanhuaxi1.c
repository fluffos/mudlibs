//bye enter

inherit ROOM;

void create()
{
        set("short", "浣花溪边");
        set("long",@LONG
你走在浣花溪边，流水清澈，河边不少女子在此洗衣，淘菜
。这条蜿蜒的小溪，顺着那府南河流出，水面上尚有几株横里伸
展的枝桠，轻拂流水，有一股淡淡的诗意。秋风萧瑟，枝摇影斜
，在静寂中，带着一丝凄清与孤独。 
LONG
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "south" : __DIR__"cdta",
                "northeast" : __DIR__"huanhuaxi2",
            ]));
        setup();
        replace_program(ROOM);       
}


