//quest_fighter.h
//侠客任务的头文件
//seagate@pkuxkx 2010/11/07

#include <ansi.h>

string start_fighter(string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_fighter/promoter",this_object()->query("name"));
	me->set_temp("quest_fighter/start",1);
	me->set_temp("下山",1);
	
	this_object()->newbieDesc("到双井子村帮崔老汉解决麻烦。\n");
	return "山下双井子村的崔老汉似乎有点麻烦，你现在下山一趟帮他解决麻烦。";
}