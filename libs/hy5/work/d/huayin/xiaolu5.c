// xiaolu5.c

inherit ROOM;
void create()
{
        set("short","村路");
        set("long",@LONG                                   
这里差不多是铜山村的正中央了，村路到这里也变得平整得
多了。向西是打谷场，向东是村里一口公用的水井。北面一个不
小的院落就是铜山村的村长李德胜的家了。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"daguchang",
               "east" : __DIR__"shuijing",
               "north":__DIR__"cunzhang",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
