// majiu.c 马厩
inherit ROOM;
void create()
{
        set("short", "马棚");
        set("long", @LONG
这是个大马棚，支起来的帐篷有十多丈长，里面拴着几百匹骏马。马虽多，
却是安安分分的，偶尔有几声嘶叫声，看来草原族的驯马之术的确高明。一堆
人正在旁边和马棚主人商讨价钱，看他们的服饰好象是从遥远的波斯而来。
LONG);
        set("resource/water", 1);
        set("exits", ([
            "north" : __DIR__"caoyuan1",
            "east" : __DIR__"hsk", 
            "west" :__DIR__"caoyuan7",           
        ]));
        
        set("objects", ([
                    __DIR__"npc/xiaoxiang" : 1,
                    "/d/xingxiu/npc/shangren" : 2
        ])); 
        set("outdoors", "草原");        
        set("coor/x",-340);
  set("coor/y",80);
   set("coor/z",0);
   setup();
}
