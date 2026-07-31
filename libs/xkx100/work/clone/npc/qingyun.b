// qingyun.c
// shilling 97.2

inherit NPC;

#include <ansi.h>
string give_prize();
string cancel_job();
string change_family();
void give_number(object who);
void create()
{
	set_name("青云", ({ "qing yun", "shizhe" }));
	set("long", 
		"他是掌门人的得意门生，一个十分厉害的神秘人物。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("no_get", "1");
	set("str", 35);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 29);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 200000);
	set("score", 50000);

	set("inquiry",([
	"奖励" :  (: give_prize :),
	"cancel": (: cancel_job :),
	]));

	set_skill("blade",100);
	set_skill("ruyi-dao",100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("lingboweibu", 100);
	set_skill("beiming-shengong",100);
	set_skill("liuyang-zhang", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");

	create_family("逍遥派", 2, "弟子");
	set("title","逍遥派护法使者");
	set("nickname","天使之侣");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"blade")->wield();

}
void init()
{
	add_action("do_answer","answer");
}

string give_prize()
{
	object who=this_player();
	object me = this_object();
	
/*	if (clonep()) 
	{
		command("xy12 "+who->query("id"));
		return "";
	}*/
	if (!who->query_temp("can_give_prize") || !who->query_temp("prize_exp"))
	 	return "为啥要给你奖励哩？给我个理由先！";
	who->delete_temp("can_give_prize");
	message_vision("$N对$n说道：可是我的奖励只给活人哩，你如果能回答我的问题，我就给你奖励。\n",me,who);
	message_vision("$N轻轻地一挥手，眼前顿时闪起七彩的莹光。\n",me);
	give_number(who);
	who->set_temp("pending/answer",1);
	return "请回答(answer)吧。";
}
int do_answer(string arg)
{
	object who = this_player();
	int exp,pot;
	string reason;
	
	if (who->is_busy()) return 0;
	if (!who->query_temp("pending/answer"))
	 return 0;
	who->delete_temp("pending/answer");
	if (getuid(who)=="melody") arg = who->query_temp("prize_answer");
	message_vision("$N答道：是不是"+arg+"。\n",who);
	if (arg != who->query_temp("prize_answer"))
	{ 
		message_vision("$N瞟了$n一眼，摇了摇头，叹了口气。\n",this_object(),who);
		who->delete_temp("prize_exp");
		who->delete_temp("prize_reason");
  	who->delete_temp("prize_pot");
  	who->start_busy(10);
		return 1;
	}
	exp = who->query_temp("prize_exp");
	pot = who->query_temp("prize_pot");
	reason = who->query_temp("prize_reason");
	if (exp > 1000) exp = 1000;
	if (pot == 0 || pot > exp*3/10 || reason=="奸细")	pot = exp*3/10;
	message_vision("$N朝着$n微笑着点了点头，伸手往$n一指，一道淡淡的金光笼住了$n。\n",this_object(),who);
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("gift/qingyun",1);
  log_file("qingyun",sprintf("[%s]%8s %8s exp:%5d pot:%5d \n",ctime(time()),who->query("id"),who->query_temp("prize_reason"),exp,pot));
	tell_object(who,HIW"你被奖励了"+to_chinese(exp)+"点经验和"+
	to_chinese(pot)+"点潜能。\n"NOR);
	who->delete_temp("prize_exp");
	who->delete_temp("prize_pot");
	who->delete_temp("prize_reason");
	return 1;
}
string ins(int num)
{
	int i;
	string str="";
	for (i=0;i<num;i++)
		str += " "; //几个数字之间用什么东西填充 这里用空格 以后考虑百分号和[
  return str;
}

mixed display(string num)
{
	mapping all = ([
	"0" : ({ 
	({
"  ___  ",
" / _ \\ ",
"| | | |",
"| |_| |",
" \\___/ ",
}),
({
"╭───╮",
"│╭─╮│",
"││  ││",
"││  ││",
"││  ││",
"│╰─╯│",
"╰───╯",
	}),
}), // end 0	
	"1" : ({ ({
"  ┌─┐  ",
"┌┘  │  ",
"└┐  │  ",
"  │  │  ",
"┌┘  └┐",
"│      │",
"└───┘",
		}),
		({
"   _   ",
"  / |  ",
"  | |  ",
"  | |  ",
"  |_|  ",
}),
	}), // end 1
	"2" : ({ 
	({
"╭───╮",
"│╭─╮│",
"╰╯  ││",
"╭──╯│",
"│╭──╯",
"│╰──╮",
"╰───╯",
}),
({
" ____  ",
"|___ \\ ",
"  __) |",
" / __/ ",
"|_____|",
}) 
	}),// end 2
	"3" : ({ 
	({
"╭───╮",
"│╭─╮│",
"╰╯╭╯/ ",
"    │ │ ",
"╭╮╰╮\\ ",
"│╰─╯│",
"╰───╯",
	}),
	({
" _____ ",
"|___ / ",
"  |_ \\ ",
" ___) |",
"|____/ ",
	}),
	}), // end 3
	"4" : ({
	({
"┌─┐─┐",
"│  │  │",
"│  │  │",
"│      │",
"└─┐  │",
"    │  │",
"    └─┘",
	}),
	({
" _  _   ",
"| || |  ",
"| || |_ ",
"|__   _|",
"   |_|  ",
	}),
	}), // end 4
	"5" : ({
	({
"╭───╮",
"│╭──╯",
"│╰──╮",
"╰──╮│",
"╭╮  ││",
"│╰─╯│",
"╰───╯",
	}),
	({
" ____  ",
"| ___| ",
"|___ \\ ",
" ___) |",
"|____/ ",
	}),
	}), // end 5
	"6" : ({
	({
"╭───╮",
"│╭──╯",
"│╰──╮",
"│╭─╮│",
"││  ││",
"│╰─╯│",
"╰───╯",
	}),
	({
"  __   ",
" / /_  ",
"| '_ \\ ",
"| (_) |",
" \\___/ ",
	}),
	}), // end 6
	"7" : ({
/*	({
"┌───┐",
"│      │",
"└─┐  │",
"    │  │",
"    │  │",
"    │  │",
"    └─┘",
	}),*/
	({
" _____ ",
"|___  |",
"   / / ",
"  / /  ",
" /_/   ",
	}),
	}), // end 7
	"8" : ({
	({
"╭───╮",
"│╭─╮│",
"│╰─╯│",
"│╭─╮│",
"││  ││",
"│╰─╯│",
"╰───╯",
	}),
	({
"  ___  ",
" ( _ ) ",
" / _ \\ ",
"| (_) |",
" \\___/ ",
	}),
	}), // end 8
	"9" : ({
	({
"╭───╮",
"│╭─╮│",
"││  ││",
"│╰─╯│",
"╰──╮│",
"╭──╯│",
"╰───╯",
	}),
	({
"  ___  ",
" / _ \\ ",
"| (_) |",
" \\__, |",
"   /_/ ",
	}),
	}), // end 9
	]);// end all

  string str;
  string* res;
  int a,b,s,i;
	res = all[num][random(sizeof(all[num]))];
	s = sizeof(res);
	if (s < 8)   //八行为准 不够补上
	{
		a = random(8-s+1);
		for(i=0;i<a;i++)
			res =  ({ ins(strlen(res[0])) }) + res; //前面补一些
		for(i=0;i<(8-s-a);i++)
			res += ({ ins(strlen(res[0])) }); //后面补一些
	}
	return res;
}

//int display_item(int i1,int i2,int i3,int i4)
void give_number(object who)
{
	string str;
	string *str1,*str2,*str3,*str4;
	string dis;
	int i,len;
	string i1,i2,i3,i4;
	string a,b,c,d,e;
	int f,g;
	string *all=({"1","2","3","4","5","6","7","8","9","0",});
	
	i1 = all[random(sizeof(all))];
	i2 = all[random(sizeof(all))];
	i3 = all[random(sizeof(all))];
	i4 = all[random(sizeof(all))];
	
	str  = "";	
  a = ins(random(2));
  b = ins(random(2));
  c = ins(random(2));
  d = ins(random(2));
  e = ins(random(2));

	str1  = display(i1);
	str2  = display(i2);
	str3  = display(i3);
	str4  = display(i4);

	for (i=0;i<sizeof(str1);i++)
	{
		str += a;
		str += str1[i]; str += b;
		str += str2[i]; str += c;
		str += str3[i]; str += d;
		str += str4[i]; str += e;
		str += "\n";
	}
	len =  0;
	if (arrayp(str1))
	{
  		len += strlen(str1[0]);
  		len += strlen(str2[0]);
  		len += strlen(str3[0]);
  		len += strlen(str4[0]);
  	}
  	len = len + strlen (a + b + c + d + e);
	
	f = random(2); g = random(2);
	for(i=0;i<f;i++)
	str =  ins(len) + "\n" + str; 
	for(i=0;i<g;i++)
	str += ins(len) + "\n";  //第一行和最后一行补上随机行标识
	
	tell_object(who,str);
	who->set_temp("prize_answer",sprintf("%s%s%s%s",i1,i2,i3,i4));
  return 0;
}
string cancel_job()
{
	object me = this_object();
	object who = this_player();
	
	if (clonep()) 
	{
		command("xy11 "+who->query("id"));
		return "";
	}
	if (!who->query("quest/kill")) return "你没有领任务，有什么好取消的";
	if (time() < who->query("quest/kill/time")) 
	return "你的任务时间还没到，快去做吧。";
	who->delete("quest/kill");
	return "好吧，测试时期免费帮你清除任务记录。";
}
