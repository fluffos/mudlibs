inherit ROOM; 
#include <ansi.h>
string look_shamo();
string look_valley();
#include "/d/menggu/climb_to_valley.h"
void create() 
{ 
        set("short", "山崖");
        set("long", @LONG
这里是一处山崖，可以俯视东面的山谷(valley)和南面的库布齐沙漠(shamo)。
LONG
        );
	
        set("exits", ([ 
                        "northup" : __DIR__"buerhan-6",
                        "southeast" : __DIR__"buerhan-4",
                        //"northup": __DIR__"buerhan",
]));
		set("item_desc",
        ([
			"shamo":(:look_shamo:),
			"valley":(:look_valley:),
        ]));
        set("outdoors", "menggu_e");
		setup();
}

string look_shamo()
{
	object shamo,env;
	object me=this_player();
	string str,*items;
	int i;
	if (time()-me->query_temp("menggu_look_shamo")<4)
	{
		return "库布齐沙漠老看也就是这样了。\n";
	}
	shamo=load_object(__DIR__"shamo1");
	env=load_object(shamo->query("gene_rooms/"+random(sizeof(shamo->query("gene_rooms")))));
	if (env->isroom())
	{
			str = sprintf( "%s\n\n%s%s",
			HIC+"从此处向南望去，你可以看到的景色是："+NOR,
            env->query_temp("mixed_long"),
            env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
			if(env->query("item_desc") && sizeof(env->query("item_desc")) > 0)
			{
				items = keys(env->query("item_desc"));
				str += "    你可以看看(look):";
				for(i=0;i<sizeof(items)-1;i++)
				{
					str += items[i]+",";
				}

				str += items[i];

				str += "\n";
			}
			me->set_temp("menggu_look_shamo",time());
			return str;
	}
	else
	{
		return "这时库布齐沙漠什么也看不清楚。\n";
	}
}

string look_valley()
{
	object me=this_player();
	if (time()-me->query_temp("menggu_look_valley")<4)
	{
		return "东面的山谷被云雾笼罩，什么都看不清楚。\n";
	}
	if (me->query("mengguquest/yinzhe"))
	{
		return "又想下去找隐者聊聊天了？\n";
	}
	if (me->query_temp("mengguquest/yinzhe/clue"))
	{
		return "下面幽深处一定有高人隐居，也许就在南麓的山崖某处能找到下去的路。\n";
	}
	if (random(100)>30)
	{
		me->set_temp("mengguquest/yinzhe/clue",1);
		return "山下幽深处似有人迹，也许就在南麓的山崖某处能找到下去的路。试试爬(climb)下去。\n";
	}
	else
	{
		return "东面的山谷被云雾笼罩，什么都看不清楚。\n";
	}
}