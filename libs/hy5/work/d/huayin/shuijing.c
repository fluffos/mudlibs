// shuijing.c

inherit ROOM;
void create()
{
        set("short","水井");
        set("long",@LONG                                   
这里是一个青石铺就的井台，四块青石条搭成井字型。青石
被来打水的人的脚踏出一条深深的足迹，走在这里你一定要小心，
可不要摔到。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu5",
               "east" : __DIR__"xiaolu6",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
