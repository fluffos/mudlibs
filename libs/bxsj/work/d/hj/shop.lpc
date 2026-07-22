// shop.c 哈萨克小店 

inherit ROOM;

void create()
{
        set("short", "哈萨克小店");
        set("long", @LONG
这座帐篷略显破旧，似乎搭好后主人就没再修整过它。帐篷边到是挂了不
少东西，牛皮筋，铃铛等等，看来这里是个小杂品点。
LONG);
        set("exits", ([            
            "south" : __DIR__"pmchang",
            "east" : __DIR__"road1",
            "northwest" : __DIR__"sroom",
            "southeast" : __DIR__"caoyuan2",
        ]));        

        set("objects", ([
                    __DIR__"npc/dealer" : 1,
                    "/d/xingxiu/npc/shangren" : 1
        ]));

        set("outdoors", "草原");
        
        set("coor/x",-320);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
