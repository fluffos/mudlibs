// xiaolu7.c

inherit ROOM;
void create()
{
        set("short","铜山村东口");
        set("long",@LONG                                   
这里就是铜山村的东口了。东北方好像有一个土地庙。稀稀
落落地有人从那里进出。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu6",
               "northup":__DIR__"tulu4",
               "east" : __DIR__"tl5",
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
