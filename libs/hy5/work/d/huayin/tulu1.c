// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","土路");
        set("long",@LONG                                   
这是铜山村的一条小土路，原本这里或许就没有路，只是农
人走的多了，才踏出一条黄土小路。向南是打谷场，北边可以远
远望见一条小河。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"west":__DIR__"xiaolu1",
               "north" : __DIR__"tulu2",
               "southdown":__DIR__"daguchang",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
