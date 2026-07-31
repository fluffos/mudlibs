// shulin.c

inherit ROOM;
void create()
{
        set("short","小树林");
        set("long",@LONG                                   
这里是一小片白桦林，轻风吹过，桦树沙沙作响。据说桦树
的叶子是可以用来写字的，也不知道是不是真的。东边是一大片
庄稼地。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "east":__DIR__"miaopu4",
               "north":__DIR__"tulu3",
               
        ]) );

	set("NONPC",1);

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
