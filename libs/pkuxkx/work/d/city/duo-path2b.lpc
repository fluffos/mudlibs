//Zine skf大清
inherit ROOM;
#include "/d/city/duo_path.h"
void create()
{
	set("short", "落石山");
	set("long", @LONG
这是一座小山，山间时有落石降下。
LONG);

	set("exits", ([
		"northwest" : __DIR__"duo-path1",
        "east" : __DIR__"pingtai-2",
	]));

	set("no_task",1);
    set("outdoors", "city");
	set("battle_dir","east");
	setup();
}

void init()
{
    int i,j;
    object me=this_player(),lord;
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
		lord=find_player(me->query("lord"));
		i=random(100);
		j=random(100);
		if (i>30)
		{
			tell_object(lord,me->query("name")+"驱驰着战马前行，瞬间山上巨大的落石降下，把"+me->query("name")+"打得遍体鳞伤。\n");
			me->receive_damage("qi",me->query("max_qi")/2);
			me->receive_wound("qi",me->query("max_qi")/2);
			me->set("been",1);
		}
		if (j>49)
		{
			tell_object(lord,me->query("name")+"驱驰着战马，瞬间山上巨大的落石降下，"+me->query("name")+"被彻底压在一堆巨石下。\n");
			me->die();
		}
	}
	return;
}
