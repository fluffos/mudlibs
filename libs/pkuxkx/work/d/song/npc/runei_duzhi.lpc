#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/config/tasks.h"
void create()
{
	call_out("npc_to_player",1,"入内内侍省都都知",50,-1);
	::create();
}

int transfer_taijian(object me)
{
	object ob=load_object("/d/song/record/positions");
	mapping * titles;
	if (!ob)
	return -1;
	if (ob->query("give_mediate_titles"))
	titles=ob->query("give_mediate_titles");
	else
	return -2;
	if (me->query("gender")!="无性")
	return -3;
	if (me->query("song/pro")!="宦")
	return -4;
	for (int i=0;i<sizeof(titles);i++)
	{
		if (me->get_title(TITLE_SONG1)==titles[i]["title"]&&titles[i]["can_transfer"])
		{
			titles[i]["vacancy"]+=1;
			ob->set("give_mediate_titles",titles);
			ob->save();
			me->set("song/pro","武");
			tell_object(me,HBRED+HIM+"你由内侍转为了大宋武臣的一员。\n"+NOR);
			DASONG_D->init_sanjie(me);
			DASONG_D->position_me(me);
			return 1;
		}
	}
	return -5;//
}