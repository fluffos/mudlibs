//questdefault.h
//seagate@pkuxkx 2010/10/15

//入门任务特定任务开始时候默认的关于任务发布、成功、失败的处理函数，如果你对这些过程没有特殊
//要求的话，可以直接调用这三个处理函数，但是注意的是只要你调用其中一个处理函数你在任务处理的
//时候就要按照规范来处理。默认处理函数规定你的任务处理流程特殊的东西都记录在"quest_"+questid
//下面，成功判定标志就是"quest_"+questid+"/success"属性为1，起始判断标志就是
//"quest_"+questid+"/start"为1。

//特定任务默认发布处理函数，任务描述由desc传入，也就是说比自己写的发布处理函数将会多一个参数。
//请在写函数指针的时候把这个问题给消化了。
string start_public_proc(string desc,string name,string questid)
{
	object me;
	
	me=this_player();
	this_object()->newbieStart(name,questid);
	me->set_temp("quest_"+questid+"/promoter",this_object()->query("name"));
	me->set_temp("quest_"+questid+"/start",1);
	
	this_object()->newbieDesc(desc);
	return name+"需要"+me->query("name")+desc;
}

//特定任务默认失败处理函数
string fail_public_proc()
{
	mapping newbieMap;
	string questid,questname;
	
	newbieMap=this_player()->query_temp("newbie_quest");
	questid=newbieMap["id"];
	questname=newbieMap["name"];
	
	if(!mapp(this_player()->query_temp("quest_"+questid)))
		return "你没有领"+questname+"。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_"+questid);
	return "已经帮你取消了"+questname+"。\n";
}

//特定任务默认成功处理函数
string end_public_proc(int reward)
{
	mapping newbieMap;
	string questid,questname;
	
	newbieMap=this_player()->query_temp("newbie_quest");
	questid=newbieMap["id"];
	questname=newbieMap["name"];
	
	if(!mapp(this_player()->query_temp("quest_"+questid)))
		return "你没有领"+newbieMap["name"]+"。\n";
	else if(!this_player()->query_temp("quest_"+questid+"/success"))
		return "你的"+questname+"需要你"+newbieMap["desc"];

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_"+questid);
	return "你非常出色地完成了"+questname+"。\n";
}