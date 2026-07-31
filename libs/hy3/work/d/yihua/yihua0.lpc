#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
        set("short", "花径");
        set("long",@LONG
这是一片谷底的小路。四周一望无际，全是盛开的鲜花。微风拂过，
蜜蜂到飞舞。香气逼人。往北是一片玫瑰花，往南则是一片紫罗兰。
LONG
        );
  
	set("outdoors", "yihua");
	set("exits", ([
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));             
        setup();

}
void init()
{
    this_player()->receive_damage("qi", 15);
    this_player()->receive_wound("qi",  15);
    message_vision(HIR"突然一阵奇香向$N袭来,$N不由得开始奇想！\n"NOR, this_player());
}

int valid_leave(object me, string dir)
{
       
        int  total_steps ;
        mapping myfam;
        total_steps = ( 100 - (int)this_player()->query_skill("qimen-wuxing",1) ) / 10 ;
        if ( total_steps <= 0 ) total_steps = 1 ;  
        myfam = (mapping) this_player()->query("family");
        if(myfam && myfam["family_name"] == "移花宫") total_steps = 1 ; 
	if ( dir == "north")
            me->add_temp("yihua/steps",1);
	if ( dir == "south")
            me->add_temp("yihua/steps",-1);

	if (me->query_temp("yihua/steps") == total_steps)
         {
     	    me->move(__DIR__"xiaojin");
            me->delete_temp("yihua/steps");
             return notify_fail("你走了半天，终于走出了花径。\n");
         }  

     if (me->query_temp("yihua/steps") == - total_steps )
	    {  
	     me->move(__DIR__"yihua_out");
             me->delete_temp("yihua/steps");
             return notify_fail("你走了半天，终于走出了花径。\n");
     	}

        return ::valid_leave(me,dir);
}
