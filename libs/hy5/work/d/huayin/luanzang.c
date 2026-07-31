// luanzang.c

inherit ROOM;
void create()
{
        set("short","土坡");
        set("long",@LONG                                   
这是一片望不见边的乱葬岗，坟莹杂陈，一阵阴风吹来，地
上刮起几个小小的旋涡，带着陈年的纸钱飞舞了起来...。你心里
一阵发紧，还是尽快离开这里吧。
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"north":__DIR__"luanzang", 这里到兰若寺，0:00-3:00可以通过。
               "southup":__DIR__"tupo",
              // "east" : __DIR__"xiaolu7",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
