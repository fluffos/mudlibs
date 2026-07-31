 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "荷塘");
        set("long", @LONG
荷塘四面，长着许多树，蓊蓊郁郁的。曲曲折折的荷塘上面，弥望的是田田的
叶子。叶子底下是脉脉的流水，不能见一些颜色，而叶子却更见风致了。层层的叶
子中间，零星地点缀着些白花，袅袅挪娜地开着。微风过处，送来缕缕清香，一切
神秘而幽寂。
LONG
           );
        set("exits", 
           ([ 
       "up" : __DIR__"9bridge",
       "down" : __DIR__"shishi",
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
