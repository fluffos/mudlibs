// shenling.c
//Made By:pingpang
#include <ansi.h>
inherit NPC;

string s_skill;
string ask_special_skill();

void create()
{
	set_name("神灵", ({ "shen ling", "shen","ling" }) );
	set("nickname",GRN"天神"NOR+YEL"下凡"NOR);

	set("gender", "男性" );
	set("age", 63);
	set("long", 
"他身影轻巧,灵气逼人,凡人难以接近.\n"
"他是[玉皇大帝]派来的守护神。\n");
	set("combat_exp", 500000);

        set("str", 35);
        set("dex", 30);
        set("con", 39);
        set("int", 34);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 170);
	set_skill("unarmed",300);
	set_skill("parry", 160);
        set_skill("force", 140);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
	set("chat_chance_combat",100);
	
	// 特别技能指导能力
	s_skill = "resist-yinyang";
	set("inquiry", ([
		s_skill       : (: ask_special_skill :),
	]) );
	
	setup();
	set("chat_chance",4);
	set("chat_msg",({HIG"我受[玉皇大帝]之托，前来人间看守宝库。\n"NOR,}));
        carry_object("/d/city/obj/cloth")->wear();
		
}
void init()
{
	object ob;
	ob=this_player();
}
int accept_fight(object ob)
{
	command("say 竟敢袭击本神，去死吧.\n");
	ob->unconcious();
	return 1;
}


string ask_special_skill()
{
	object user;
	int cur_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，在下已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (cur_lvl < 1)
			return "阁下实属凡人，是不可能领悟天界驾驭阴阳的法门的。阁下还是请回吧。";
			
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句喃喃咒语。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你对抵抗阴阳六气的法门又有所领悟。\n");
			return "祝武曲星君在世间多行善事，功德圆满后早日回归天庭～";
		}
	}
	return "什么？";
}

int accept_object(object who, object ob)
{	
	object room, user;	
		
	user = who;
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}

	if ((string)ob->query("id")=="shouyin")
	{
		write(
RED"神灵说道：壮士，真是有缘人啊!你可以进去了。\n"NOR
RED"神灵凌空一指，变出了一个出口。\n"NOR);
		if(!(room=find_object("/d/guiyunzhuang/rukou")))
			room=load_object("/d/guiyunzhuang/rukou");
		room->set("exits/south","/d/guiyunzhuang/mihun");
		remove_call_out("close_door");
		call_out("close_door",8,room);
		call_out("dest",1,ob);		
		return 1;
	}
	return 0;
}
void close_door(object room)
{
	message("vision",YEL"\n神灵凌空一指，刚出现的出口消失了。\n"NOR,room);
	room->delete("exits/south");
}
void dest(object ob)
{
	destruct(ob);
	return;
}
void unconcious()
{
}
