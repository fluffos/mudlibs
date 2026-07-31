// xiaolu4.c

inherit ROOM;
void create()
{
        set("short","村路");
        set("long",@LONG                                   
你进了铜山村以后总是感觉到四周好像有一点神秘，南边有
传来紧一声慢一声的打铁声。路北有一个小小小的院落。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"xiaolu3",
               "east" : __DIR__"daguchang",
               "south":__DIR__"datiepu",
               "north":__DIR__"minju",
               
        ]) );
	set("objects",([
	"/clone/npc/npc" : 3,
]));

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
