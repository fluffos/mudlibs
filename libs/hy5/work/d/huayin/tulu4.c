// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","土路");
        set("long",@LONG                                   
这是铜山村的一条小土路，原本这里或许就没有路，只是农
人走的多了，才踏出一条黄土小路。东边是一个小小的土地庙。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"west":__DIR__"xiaolu1",
               "southdown" : __DIR__"xiaolu7",
               "east":__DIR__"xiaomiao",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
