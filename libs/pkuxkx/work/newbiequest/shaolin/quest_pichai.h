//quest_pichai.h
//劈柴任务的入口函数，非常简单，基本上就是以调用新手任务公共函数为主，当然
//你可以调用类似公共初始化函数也行。
//seagate@pkuxkx 2010/10/09

#include <ansi.h>

string start_pichai(string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_pichai/promoter",this_object()->query("name"));
	me->set_temp("quest_pichai/start",1);
	
	this_object()->newbieDesc("给厨房劈些木柴。\n");
	return "厨房里的木柴不够用了，请"+me->query("name")+NOR"过去帮帮忙吧。后院里面的管事正等着派活，劈柴前先找管事要把柴刀。";
}

string fail_pichai()
{
	if(!mapp(this_player()->query_temp("quest_pichai")))
		return "你没有领劈柴任务。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_pichai");
	return "你连这点小事也干不好！\n";
}

string end_pichai(int reward)
{
	if(!mapp(this_player()->query_temp("quest_pichai")))
		return "你没有领劈柴任务。\n";
	else if(!this_player()->query_temp("quest_pichai/success"))
		return "你还没有劈完柴，厨房正等着用木柴！\n";

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_pichai");
	return "今天你帮了大忙了，厨房里的师傅们都非常欣赏你。\n";
}