// /d/luoyang/npc/banhe_events.h
// Modified by Zine Nov 08 2012,重新修订
#include <ansi.h>

int random_event(object me)
{
	object maze,npc,maze_room;
	if (!maze=query("mini_maze"))
	return 0;
	if (!maze_room=load_object(maze->query("gene_rooms/"+random(sizeof(maze->query("gene_rooms"))))))
	return -1;
	switch (random(1))
	{
		case 0://迷宫找萧中慧
		npc=new(__DIR__"xiaozhonghui");
		npc->move(maze_room);
		npc->set("startline",maze_room);
		npc->set("owner",me);
		npc->set_temp("seeme",me->query("id"));
		if (npc&&living(npc))
		{
			me->set_temp("banhe/zhonghui",npc);
			command("say 听说小女中慧在某处迷路了，如能把小女带回，将有重谢。");
			tell_object(me,"霎时间，你觉得你的侠义值爆棚，这件事绝对义不容辞！\n"+HIC+"你踏上了寻找萧中慧的路途……\n\n\n"+NOR);
			me->move(maze);
			tell_object(me,"离开唐明镇，渐行渐远，直觉告诉你，萧中慧可能就在附近了。\n");
			break;
		}
		else
		return -2;
	}
	return 1;
}
int finish_bonus(object me)
{
	object obj;
	switch (random(1))
	{
		case 0://家信
		obj=new("/d/changjiang/obj/letter");
        obj->set("owner",me->query("id"));
        obj->move(me);
		command("say 这是一封"+obj->query("name")+"，请你帮忙送给那位！\n" );
		break;
	}
	return 1;
}
