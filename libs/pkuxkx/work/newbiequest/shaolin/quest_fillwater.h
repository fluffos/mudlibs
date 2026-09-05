//quest_fillwater.h
//挑水任务的入口函数，非常简单，基本上就是以调用新手任务公共函数为主，当然
//你可以调用类似公共初始化函数也行。
//seagate@pkuxkx 2010/10/11

#include <ansi.h>

string start_fillwater(string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_fillwater/promoter",this_object()->query("name"));
	me->set_temp("quest_fillwater/start",1);
	me->set_temp("quest_fillwater/water",150+random(100));
	
	this_object()->newbieDesc("从山下挑些水送到厨房。\n");
	return "厨房里现在缺水，请"+me->query("name")+NOR"拿着木桶从山下挑点水上来吧！\n注意厨房后院的木桶需要提着(carry)上下山，并且挑水的时候不要走得太快！";
}

string fail_fillwater()
{
	if(!mapp(this_player()->query_temp("quest_fillwater")))
		return "你没有领挑水任务。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_fillwater");
	return "你连这点小事也干不好！\n";
}

string end_fillwater(int reward)
{
	if(!mapp(this_player()->query_temp("quest_fillwater")))
		return "你没有领挑水任务。\n";
	else if(!this_player()->query_temp("quest_fillwater/success"))
		return "快点去把水挑完，厨房正等着用水！\n";

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_fillwater");
	return "今天你帮了大忙了，厨房里的师傅们都非常欣赏你。\n";
}