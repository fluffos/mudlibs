#include <ansi.h>
#include "/d/song/commands/cmd_assist.h"
void init()
{
	add_action("do_military","military");
}
int decision(string arg,object me,int the_answer,string msg)
{
	int answer;
	if (!arg||sscanf(arg,"%d",answer)!=1)
	{
		message_vision("$N看着军报，发觉自己实在不是这块料。\n",me);
		DASONG_D->delete("military_detail");
		return 1;
	}
	if (answer==the_answer)
	{
		message_vision("$N在宗卷上填写了"+HIR+"“"+chinese_number(answer)+"次”"+NOR+"，并令人张贴在枢密院的门口。\n",me);
		DASONG_D->set("military_detail",msg);
		return DASONG_D->task_finish(me,1+random(2));
	}
	else
	{
		message_vision("$N看着军报，发觉自己实在不是这块料。\n",me);
		DASONG_D->delete("military_detail");
		return 1;
	}
}
int do_military()
{
	int n,*answers=({DASONG_D->query("military_record/招募新军/total"),DASONG_D->query("military_record/部队出征/total"),DASONG_D->query("military_record/击溃敌军/total"),DASONG_D->query("military_record/宫城巡防/total")});
	string *desc=({"招募新军","军队开拔","击溃敌军","宫城巡防"});
	object me=this_player();
	string msg=HBBLU+HIR+"今岁大宋军情\n"+NOR,msg2=msg;
	string benefit="shumi",type="day";
	if (!wizardp(me)&&!DASONG_D->identification(me,({"枢密使","枢密副使","知枢密院事","同知枢密院事","签枢密院事","同签枢密院事"})))
	return 0;
	msg2+=HIW+"【招募新军】"+NOR+chinese_number(DASONG_D->query("military_record/招募新军/total"))+"支\n";
	msg2+=HIW+"【军队开拔】"+NOR+chinese_number(DASONG_D->query("military_record/部队出征/total"))+"次\n";
	msg2+=HIW+"【击溃敌军】"+NOR+chinese_number(DASONG_D->query("military_record/击溃敌军/total"))+"支\n";
	msg2+=HIW+"【宫城巡防】"+NOR+chinese_number(DASONG_D->query("military_record/宫城巡防/total"))+"次\n";
	if (wizardp(me)||DASONG_D->identification(me,({"枢密使",})))
	{
		n=random(sizeof(answers));
		write(msg2);
		song_cycle(me,type,benefit);
		if (me->query("song/"+benefit+"/times")>=1)
		return 1;
		me->add("song/"+benefit+"/times",1);
		write("今岁累计"+desc[n]+"的次数？(请用阿拉伯数字回答)");
		input_to((:decision:),me,answers[n],msg2);
		return 1;
	}
	else
	{
		write(msg2);
		return 1;
	}
}