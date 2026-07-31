// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","土路");
        set("long",@LONG                                   
这是铜山村的一条小土路，原本这里或许就没有路，只是农
人走的多了，才踏出一条黄土小路。向南远远可以望见打谷场，
向北边是一条小河。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"west":__DIR__"xiaolu1",
               "south" : __DIR__"tulu1",
               "northdown":__DIR__"xiaohe1",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
