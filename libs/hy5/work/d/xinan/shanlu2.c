inherit ROOM;


void create()
{
    set("short","山路");
    set("long",@LONG
你正走在秦岭上。北面是八百里平川的关中平原，向南一直走就可进入巴蜀。
LONG);
    set("exits",([  
       "northdown"  : __DIR__"shanlu1",
       "south"       : __DIR__"shanlu3",
    ]));
    setup();
        set("outdoors","xinan");
}
