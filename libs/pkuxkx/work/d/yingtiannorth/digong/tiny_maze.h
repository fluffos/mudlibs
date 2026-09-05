#include <ansi.h>
void gen_maze(int flag)
{
	int pin=random(10000)+1;
	object rm;
	string room,entry=__DIR__"level"+query("level")+"entry",exit=__DIR__"level"+query("level")+"exit";
	if (query("PreExit")&&query("PreExit")->query("pin")==query("pin")&&query("pin")!=0)
	return;
	flag=4+random(flag);
	for (int i=0;i<9;i++)
	{
		if (load_object(__DIR__"level"+query("level")+"maze"+i))
		destruct(load_object(__DIR__"level"+query("level")+"maze"+i));
		load_object(__DIR__"level"+query("level")+"maze"+i);
	}
	set("exits/enter",__DIR__"level"+query("level")+"maze"+0);
	rm=load_object(__DIR__"level"+query("level")+"maze"+flag);
	rm->set("pin",pin);
	set("PreExit",rm);
	set("pin",pin);
	room=__DIR__"level"+query("level")+"maze"+0;
	room->set("exits/out",entry);
	room=__DIR__"level"+query("level")+"maze"+flag;
	room->set("exits/out",__DIR__"level"+query("level")+"exit");
	exit->set("exits/enter",room);
}
