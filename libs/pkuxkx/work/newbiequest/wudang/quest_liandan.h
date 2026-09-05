//quest_liandan.h
//炼丹任务的入口函数
//seagate@pkuxkx 2010/10/09

#include <ansi.h>

string start_liandan(string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_liandan/promoter",this_object()->query("name"));
	me->set_temp("quest_liandan/start",1);
	
	this_object()->newbieDesc("到俞岱岩哪里帮他看守一次丹炉。\n");
	return "武当三侠最近迷上了炼丹，需要一个道童帮他看守丹炉，你到俞岱岩那里帮他看看炉火吧。";
}
