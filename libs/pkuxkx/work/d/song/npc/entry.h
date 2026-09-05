#include <ansi.h>
int get_me_in()
{
	object me=this_player(),ob=this_object();
	string pro;
	mapping opposite=(["文":"武","武":"文"]);
	if (me->query("song/pro"))
	{
		command("say 大人早就是大宋一员，不要和我开这个玩笑了。");
		return 1;
	}
	if (me->query("presong/total_check")<7)
	{
		command("say 你并没有达到进入大宋官场的条件。\n");
		return 1;
	}
	pro=ob->query("profession");
	if (DASONG_D->if_pro_permit(pro)==-1)
	{
		command("say 现在我大宋"+pro+"臣人员偏多，大人是否考虑一下从"+opposite[pro]+"起步？\n");
		return 1;
	}
	command("say 从现在起，你就是我大宋"+pro+"臣一员了。");
	me->set("song/pro",pro);
	me->delete("presong");
	DASONG_D->new_sanjie(me);
	DASONG_D->position_me(me);
	return 1;
}

