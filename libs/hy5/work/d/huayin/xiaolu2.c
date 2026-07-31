// xiaolu2.c

inherit ROOM;
void create()
{
        set("short","村路");
        set("long",@LONG                                   
这是铜山村里的唯一可以通车马的道路，黄土垫出来的一条
小街。小街并不长，向东可以远远看到东头的村口。路上有三三
两两的农人说着什么，你一来他们却沉默了。向北你可以看见一
个小土坡。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu1",
               "east" : __DIR__"xiaolu3",
               "northup":__DIR__"tupo",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
