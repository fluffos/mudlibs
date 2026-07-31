//mapphere.c
//by llm*谁与争锋 1999/11/
/*说明：该文件调用我们在室外房间里一个备用的参数("outdoors","$*")，在/doc/下设立
map目录，下面设与各区域目录同名的地图文本文件。然后调用这个文件，再将与这地图同
名的文字更换颜色。这一方案实现得相当简单，也有不足。则是要求区域房间文件写得相当
规范，而且一个区域下最好不要有重复名称的地名。但这个文件也许正好可以促进这种规范吧！*/

#include "ansi.h"
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me)
{
	int i;
	string file,map,name, *search;

	seteuid(getuid());
    
	if( !file = environment(me)->query("outdoors"))
		return notify_fail("这里似乎不能查看地图，请到室外。\n");
	name = environment(me)->query("short");
    if( file_size("/doc/map/" + file)>0 ) 
    {
		if(stringp(map = read_file("/doc/map/" + file)))
		{
		    map = replace_string(map, name, HIR+name+NOR);
		    me->start_more(map);
		    return 1;
		}
	}
	return notify_fail("暂时还没有开放这里的地图查询。\n");
}

int help(object me)
{
	write(@HELP
指令格式：map 
这个指令提供你在室外查询所在地的地图。亮红色表示你所处之地。
（此命令正在不断完善中）
HELP
	);
	return 1;
}

