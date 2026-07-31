 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "孙记铁铺");
        set("long", @LONG
一个门面乌黑的小店，一尺多高的门槛似乎已经被客人
们蹋平了。门口立着一块招牌，上面写着：
                孙 记
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"dengfeng",
]));
        set("objects", ([
                __DIR__"npc/tie_waiter" : 1,
       ]) );
        set("coor/x",-210);
        set("coor/y",90);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
