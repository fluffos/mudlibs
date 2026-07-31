// daguchang.c

inherit ROOM;
void create()
{
        set("short","打谷场");
        set("long",@LONG                                   
这里是方园几十丈的一大片空场，秋收的时候这里便是农人
们晾晒谷物的地方，四周有几垛两人高的麦桔，看来是农人们这
一年生火作饭用的。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu4",
               "east" : __DIR__"xiaolu5",
               "northup":__DIR__"tulu1",
               "south":__DIR__"tulu3",
               
        ]) );
	set("objects",([
	"/clone/npc/man" : 3,
]));

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
