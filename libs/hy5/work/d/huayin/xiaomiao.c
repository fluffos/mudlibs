// xiaomiao.c

inherit ROOM;
void create()
{
        set("short","小庙");
        set("long",@LONG                                   
你面前的神桌上供奉著一尊土地像。庙虽老旧，但是神案四
周已被香火薰成乌黑的颜色。这里想必相当受到信徒的敬仰。
LONG
        ); 
	set("objects",([
	"/clone/npc/npc" : 1,
]));
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"tulu4",
               
        ]) );

        setup();
        replace_program(ROOM);
}
