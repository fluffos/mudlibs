// tupo.c

inherit ROOM;
void create()
{
        set("short","土坡");
        set("long",@LONG                                   
这是铜山村东边的一个小土坡，这个小土坡是铜山村地势最
高的地方。站有这里你可以看遍全村。北边是一片乱葬岗。村里
的人是决不愿向北踏足的。你站在这里可以感觉的到阵阵阴风吹
的你浑身直起鸡皮疙瘩。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "northdown":__DIR__"luanzang",
               "southdown":__DIR__"xiaolu2",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
