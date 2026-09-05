// smith.c

inherit NPC;
inherit F_DEALER;

string s_skill;
string ask_special_skill();

void create()
{
	set_name("冯铁匠", ({ "feng", "smith" }) );
	set("gender", "男性" );
	set("age", 53);
	set("long", 
"冯铁匠想是常年弯腰打铁，背已驼了，双眼被烟火薰的又红又细，\n"
"左腿残废，肩窝下撑著一根拐杖。\n");
	set("combat_exp", 50000);

        set("str", 24);
        set("dex", 17);
        set("con", 28);
        set("int", 27);
	set("shen_type", 1);

        set("attitude", "friendly");
        set_skill("dodge", 70);
	set_skill("hammer", 40);
	set_skill("parry", 60);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set("vendor_goods", ({
                __DIR__"obj/hammer",
        }));
//        set("chat_chance", 50);
//	set("chat_msg_combat", (: add_hammer :));
		
		// 特别技能指导能力
		s_skill = "master-enchase";
	set("inquiry", ([
		"name": "小人姓冯，村里人都叫我冯铁匠。",
		"here": "这里是小人糊口的铺子，小人就住在後边的屋子。",
		"锄头": "锄头... 抱歉，锄头已经卖光了...",
		"铁锤": "铁锤？小人做的铁锤坚固又耐用，一把只要三百文钱。",
		"剑"  : 
"哦，那是给华山派岳掌门打的，小人用了三个月，总算没浪费那块好铁。\n"
"嗯，岳掌门前不久率门徒下山去了，不知什麽时候才会派人来取剑。",
		"取剑": "小人一定要见了岳掌门的手信才能给剑。",
		"冯默风" : "唉～，这个名字小人已经好久没有听到过了...",
		"奇门遁甲" : "那都是小时候学的，平时没事解解闷罢了。",
		
		s_skill       : (: ask_special_skill :),
	]) );
	setup();
        add_money("coin", 50);
             carry_object(__DIR__"obj/hothammer")->wield();
}
void init()
{
        ::init();
        add_action("do_buy", "buy");

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
		
		if (user->query("nation")!= "东瀛浪人")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (cur_lvl > SPECIAL_D->query_level(user, "master-con"))
			return "你的体质太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("master-con") + "(master-con)吧。";
		
		if (cur_lvl > user->query_skill("parry",1)/20)
			return "你的体质太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("parry") + "(parry)吧。";
			
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
			
		if (user->query_temp("mark/gold_"+s_skill))
		{
			return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
				+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
		}
		
		user->set_temp("mark/item_"+s_skill, 1);
		return "我可以教你，不过我真想再见师父他老人家一面。";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句打铁的要决。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你对铸造兵器略有些心得。\n");
			return "真想再看到师父一面……";
		}
	}
	return "什么？";
}

int accept_object(object who, object ob)
{
	object sword;
	object user;
	int cur_lvl;
	
	user = who;
	cur_lvl = SPECIAL_D->query_level(user, s_skill);
	
	if (user->query_temp("mark/item_"+s_skill) && ob->query("id") 
			&& ob->query("id") == "yu xiao" )
	{
		tell_object( user, "这是我师父的随身之物。师父他老人家还好吧？真是太感谢你了！～～\n好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
				+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n");
		user->delete_temp("mark/item_"+s_skill);
		user->set_temp("mark/gold_"+s_skill, 1);
        call_out("destroy", 1, ob);
		return 1;
	}
	
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	
	sword = new(__DIR__"obj/youlong");
if ((string)ob->query("name")=="手信" && (string)ob->query("id")=="letter") {
              if(!query("yl_trigger")) {
		say(
"冯铁匠说道：这把剑虽不起眼，可也是小人的心血，总算对得起岳掌门。\n"
"冯铁匠把" + sword->query("name") + "交给了" + who->query("name") + "。\n");
		sword->move(who);
                set("yl_trigger", 1);
              }
           else say("冯铁匠眼也不抬，说道：要剑自己进去拿。\n");
        call_out("destroy", 1, ob);
	return 1;
	}
	return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
// void add_hammer()
// {
//	if (this_object()->is_fighting() )
//             carry_object(__DIR__"obj/hammer")->wield();
// }

