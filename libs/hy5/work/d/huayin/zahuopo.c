// zahuopu.c

inherit ROOM;
void create()
{
        set("short","杂货铺");
        set("long",@LONG                                   
农家人是不太爱买东西的，这里的杂货铺也就是卖些农家自
己生产不了的小东西罢了。不过听说老板以前也是以为江湖人士，
这也经常有一些奇怪的人光顾。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "north":__DIR__"xiaolu6",
               
        ]) );

	set("objects",([
	__DIR__"npc/seller" : 1,
]));
        setup();
        replace_program(ROOM);
}
