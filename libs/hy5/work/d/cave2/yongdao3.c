 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "甬道");
        set("long", @LONG
地势至此略微平坦一些，壁上多了几盏油灯。地上堆了几块大
石，把通道堆得只容一人可以侧身挤过。大石后站着几个穿黑色衣
靠的人，脸隐在阴影之中。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao4",
                "southup" : __DIR__"yongdao2",
                "westup" : __DIR__"yongdao3a",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
