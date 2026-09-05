// Room: /clone/misc/northgate.c
// Date: by jason(尔好啊) Tue Nov 17 15:39:52 2009
// edit by zine Aug 21 2010


#include <ansi.h>


int valid_leave(object me, string dir)
	{  
		if ( dir == "enter" )
			{
				if (me->query_temp("xiangyang/xypass"))
					{
						message_vision(HIC"$N已经熟读了襄阳兵力分布图，早已知道这里是狙击的好所在，自信地走了进去。\n"NOR, me);
					}
				else
					{	
						me->add_busy(2+random(3));
						message_vision(BLU"瓮城内漆黑一片，$N不能马上适应，不禁心里一阵慌乱。\n"NOR, me);
					}
			}
		return 1;
	}

