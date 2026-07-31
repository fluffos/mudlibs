// xiaolu3.c

inherit ROOM;
void create()
{
        set("short","村路");
        set("long",@LONG                                   
铜山村虽不很大，但背靠着云龙山，村北又有一条小河流过，
倒是一块种庄稼的好地方，听说十年倒有五年是丰收年景。这里
的人收入倒也还算好。路南有一个小小的酒馆。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu2",
               "east" : __DIR__"xiaolu4",
               "south":__DIR__"jiuguan",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
