// teller.c

inherit NPC;

string tell_fortune();

int do_forge();
int do_ask();

string s_skill;
string ask_special_skill();

void create()
{
	set_name("李铁嘴", ({ "fortune teller", "teller" }) );
	set("gender", "男性" );
	set("age", 48);
	set("long", 
"李铁嘴是个买卜算卦的江湖术士，兼代客写书信、调幅。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
	set("shen_type", -1);

        set_skill("unarmed", 30);
	set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

		// 特别技能指导能力
		s_skill = "master-combine";
	set("attitude", "peaceful");
        set("inquiry", ([
		"算命" : (: tell_fortune :),
		"写信" : "李铁嘴说道：代客写信，每页五十文。\n",
		"写调幅" : "李铁嘴说道：可以用各家字迹写调幅，每幅五两白银。\n",
		"伪造" : (: do_forge :),
		"四宝" : (: do_ask :),
        
		s_skill       : (: ask_special_skill :),
        ]) );

	setup();
	add_money("silver", 5);
}

int do_ask()
{
	object me = this_player();
	message_vision("李铁嘴对$N「嘿嘿」笑了几声，说道：「打听事情不要钱啊？怎么也得意思意思吧？五两金子，言不二价！」\n",me);
	me->set_temp("riyue/ask李",1);
	return 1;
}

int do_forge()
{
	say("李铁嘴两只眼睛四下扫了扫，「嘿嘿嘿」的干笑了几声...\n");
	write(
"李铁嘴轻声跟你说道：不是我吹牛，保证蓦的跟原来字体一模一样，每封信\n"
"	            五十两白银，不二价。\n");
	this_player()->set_temp("marks/李", 1);
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
		
		if (user->query("nation")!= "天竺部族")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (cur_lvl >= SPECIAL_D->query_level(user, "master-str"))
			return "你的体质太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("master-str") + "(master-str)吧。";
			
		if (cur_lvl > user->query_skill("force",1)/20)
			return "你的体质太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("force") + "(force)吧。";
			
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill)*5)+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句炼丹道术。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你对精炼宝石略有些心得。\n");
			return "合成出了优质的宝石，可以便宜卖给我么？嘿嘿～";
		}
	}
	return "什么？";
}

int accept_object(object who, object ob)
{
	object letter,user;
	
	user = who;
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 50000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	
	if (ob->query("money_id") && ob->value() >= 50000 && who->query_temp("riyue/ask李")) 
	{
		letter = new("/d/riyuejiao/obj/note");
		letter->move(who);
		who->set_temp("riyue/getnote",1);
		who->delete_temp("riyue/ask李");
		message_vision("李铁嘴拿起一支笔在纸上划了几个字，递给了$N。\n",who);
		return 1;
	}		

	letter = new(__DIR__"obj/letter");

	if ((string)ob->query("name")=="信纸") {
	        if( who->query_temp("marks/李") ) {
			this_player()->set_temp("marks/李3", 1);
			write(
"李铁嘴对你说道：造封信容易，先拿五十两银子来。\n");
			this_player()->set_temp("marks/李", 0);
                call_out("destroy", 1, ob);
			return 1;
		} else if( who->query_temp("marks/李2") ) {
                        write(
"李铁嘴皮笑肉不笑的对你说道：伪造这封信可是关系重大啊，得多收五十两。\n");
                        this_player()->set_temp("marks/李4", 1);
			this_player()->set_temp("marks/李2", 0);
                call_out("destroy", 1, ob);
                        return 1;
                }
//              say("李铁嘴说：这是写好了的信，给我干什么?\n");
                return 0;
	}
       
	if( ob->value() >= 5000 ) {
		 if( who->query_temp("marks/李4") ) {
			write(
"李铁嘴对你说道：这封信是造好了，但" + RANK_D->query_respect(who) + 
"要是出了事，千万别把我说出来呀。\n");
			say("李铁嘴给了" + who->query("name") + "一封手信。\n");
			this_player()->set_temp("marks/李4", 0);
			letter->move(who);
			return 1;
		}
		if( who->query_temp("marks/李3") ) {
			write(
"李铁嘴皮笑肉不笑的对你说道：伪造这封信可是关系重大啊，得多收五十两。\n");
			this_player()->set_temp("marks/李4", 1);
			this_player()->set_temp("marks/李3", 0);
			return 1;
		} 
		if( who->query_temp("marks/李") ) {
			write(
"李铁嘴对你说道：你想伪造什么啊? 总得拿个样子来吧。\n");
		this_player()->set_temp("marks/李2", 1);
		this_player()->set_temp("marks/李", 0);
		return 1;
		}
                say(
"李铁嘴一面急忙把钱收起来，一面笑嘻嘻说道：" + RANK_D->query_respect(ob) + 
"，这怎么敢当。\n");
		return 1;
	}
        if( ob->value() >= 500 ) {
		say(
"李铁嘴笑嘻嘻说道：调幅写好了，请您收起来吧，多谢关照。\n");
		return 1;
	}
	if( ob->value() >= 50 ) {
		say(
"李铁嘴笑嘻嘻说道：信写完了，您收好了，多谢关照。\n");
		return 1;
	}
	return 0;
}

string tell_fortune()
{

return "李铁嘴说：老夫早已不给人算命了，你可以去归云庄找我的徒弟去算算命。\n";

}

void destroy (object ob)
{
        destruct(ob);
        return;
}
