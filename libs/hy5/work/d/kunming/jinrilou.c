// /d/kunming/jinrilou
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "近日古楼" );
        set("long", @LONG
近日楼地处昆明市中心，南来北往的人都从这里通过，二楼悬
有一巨钟，北边是平西王府，一般人很少去那里，西边是金马枋，
南边热闹非凡，熙熙攘攘，人来人往。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"jinmafang", 
                "east"  :__DIR__"bijifang",
                "south" :__DIR__"nandajie1",
                "north" :__DIR__"beidajie",
                "up"    :__DIR__"zhonglou",                           
        ]));

        setup();
        replace_program(ROOM);
}
