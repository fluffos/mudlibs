// huayinchun by pian
//#include <ansi.h>

inherit ROOM;
void create()
{
        set("short","村路");
        set("long",@LONG                                   
村路到这里又开始变的有点难走了，路的南边有一个小杂货
铺。如果你再向东走，就是小村的东口了。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"shuijing",
               "east" : __DIR__"xiaolu7",
               "south":__DIR__"zahuopo",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
