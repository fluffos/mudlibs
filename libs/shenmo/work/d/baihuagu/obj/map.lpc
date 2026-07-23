inherit ITEM;
#include <ansi.h>

nosave string map = 0;

void create()
{
        set_name("百花阵图",({"zhen tu","tu","map"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        	set("unit", "张");
		set("long","一张残缺不全的地图。\n");
        	set("material", "paper");
        	set("no_put",1);
        	set("no_give",1);
		set("no_drop", 1);                
        	set("no_get",1);
        	set("value", 0);
        }
}

int write_map(object who)
{
	if( who && environment(who) && environment(who)->query("maze") 
	 && !map )
	{
		map = MAZE_D->query_maze_mainobj(who)->display_common_map(environment(who));
		map+= "\n走出迷宫则闯关成功！\n";
		return 1;
	}
	return 0;
}

string long()
{
	if( !map )
		return ::long();
	return map;
}			