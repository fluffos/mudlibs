// 密林
// edit: by zine Aug 21 2010
#include <ansi.h>
void init()
{
	object me=this_player();
	object* all = all_inventory();
	string* ml = ({__DIR__"milin1",__DIR__"milin2",__DIR__"milin3",__DIR__"milin4",});
	object nextroom = load_object( ml[random(sizeof(ml))] );
    if (me->query("mingqi"))
    {
        return;
    }
	if (userp(me) && me->query_temp("skf/migong"))
	{
		tell_object(me,HIW "进入密林，你不敢半点放松，仔细地观察着周围。\n"NOR);
	}
	else
	{
		if (random(10)>7 )
		{
			for(int i=0;i<sizeof(all);i++)
			{
				if(!objectp(all[i])) continue;
				if(!living(all[i])) continue;
				if(all[i]->query("skfleader")==me->query("id"))
				{all[i]->move(nextroom);} 
			}
			me->move(nextroom);
			tell_object(me,HIY "你为躲避敌人的追踪，改变了行进的路线。\n"NOR);
			tell_room(environment(),"一群人匆匆避入密林。\n");
			me->set_temp("skf/migong",1);
		}
	}
	::init();
	return;	
}

