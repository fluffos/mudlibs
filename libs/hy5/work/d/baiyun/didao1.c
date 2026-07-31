 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
地道中虽然也很阴森，但相比那如同地狱般的水道而言，却已无异到了天堂。
地道的尽头，是道铁门。门上居然没有锁。似乎推开就可以进去。
LONG
           );
        set("exits", 
           ([ 
       "out" : __DIR__"shuidao2",
       "south" : __DIR__"shishi",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
