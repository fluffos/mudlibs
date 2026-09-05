//quest_pichai.h
//采气任务的入口函数，也基本上包含了新手任务相关的全部内容
//seagate@pkuxkx 2010/10/09

#include <ansi.h>

string start_caiqi(string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_caiqi/promoter",this_object()->query("name"));
	if(!me->query("caiqi/times"))
		me->set_temp("quest_caiqi/start",0);
	else
		me->set_temp("quest_caiqi/start",me->query("caiqi/times"));
	
	this_object()->newbieDesc("到天柱峰采气一次。\n");
	command("say 道家炼气最讲究时辰和地点了，现在正是采气的最佳时间。");
	command("say 武当的天柱峰汇天地灵气，正是采气的最佳地点，山脚下最适合新入门弟子采气。");
	command("say 练过一阵子功夫以后可以尝试登上半山腰的巨石上采气，当然采气最佳的地点还是天柱峰顶上。");
	return "到天柱峰脚下采气（caiqi）一次后回来向我汇报心得体会。";
}

string fail_caiqi()
{
	if(!mapp(this_player()->query_temp("quest_caiqi")))
		return "你没有领采气任务。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_caiqi");
	return "你连这点小事也干不好！\n";
}

string end_caiqi(int reward)
{
	if(!mapp(this_player()->query_temp("quest_caiqi")))
		return "你没有领采气任务。\n";
	else if(this_player()->query("caiqi/times")<=this_player()->query_temp("quest_caiqi/start"))
		return "你还没有进行采气，哪有什么心得体会可言！\n";

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_caiqi");
	return "看来在天柱峰采气让你对道家的炼气有了更深的体会。\n";
}