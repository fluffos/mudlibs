//Zine skf大清 

inherit ROOM;
#include "/d/city/duo_path.h"
void create()
{
	set("short", "大河");
	set("long", @LONG
这是一条河流，水中漂浮着很多尸体，各处都渗透着诡异。
LONG);

	set("exits", ([
		"southwest" : __DIR__"duo-path1",
        "northeast" : __DIR__"zhulin-2",
	]));

	set("no_task",1);
    set("outdoors", "city");
	set("battle_dir","northeast");
	setup();
}

void init()
{
    object lord,me=this_player();
    int i,j;
	set("no_die",1);
	this_player()->listen_to_die(this_object());
    if (!wizardp(me)&&userp(me) && time()-me->query_temp("skf/qingstart")>600)
    {
        tell_object(me,"多尔衮已经不耐烦了，你还是赶紧回去吧！\n");
        me->move(__DIR__"qingjunying");
        return;
    }
    if (me->query("been")&&!userp(me))
    {
        message_vision("$N身体状况极度恶化，决定回营休息。\n",me);
        destruct(me);
        return;
    }
    if (me->query("lord")&&!userp(me))
    {
		i=random(100);
		j=random(100);
		lord=find_player(me->query("lord"));
		if (i>30)
		{
			tell_object(lord,me->query("name")+"驱驰着战马，准备渡过大河，突然发现自己越陷越深，河水中卷杂着大石，把"+me->query("name")+"打得遍体鳞伤。\n");
			me->receive_damage("qi",me->query("max_qi")/2);
			me->receive_wound("qi",me->query("max_qi")/2);
			me->set("been",1);
		}
		if (j>79)
		{
			tell_object(lord,me->query("name")+"驱驰着战马，准备渡过大河，突然发现自己越陷越深，刹那之间，河水已莫过头顶。\n");
			me->die();
		}         
    }
    return;
}
