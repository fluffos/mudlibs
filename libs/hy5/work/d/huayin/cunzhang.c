// cunzhang.c

inherit ROOM;
void create()
{
        set("short","地保家");
        set("long",@LONG                                   
这里就是铜山村地保莫提谦，青石围成一个院落里是四间大
瓦房。俗话说县官不如现管，虽说叫“莫提钱”，但是要找他办
事，没钱还真不行。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "south":__DIR__"xiaolu5",
        ]) );

	set("objects",([
	__DIR__"npc/dibao" : 1,
]));

        setup();
        replace_program(ROOM);
}
