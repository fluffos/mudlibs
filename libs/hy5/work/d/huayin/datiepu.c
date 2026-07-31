// datiepu.c

inherit ROOM;
void create()
{
        set("short","打铁铺");
        set("long",@LONG                                   
这里四周摆着各式的农具，中央一个火炉燃着。由于地处华
山脚下，武林人士来往不断，也作一些修补兵器的事情。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "north":__DIR__"xiaolu4",
        ]) );

	set("objects",([
	__DIR__"npc/smith" : 1,
]));
        setup();
        replace_program(ROOM);
}
