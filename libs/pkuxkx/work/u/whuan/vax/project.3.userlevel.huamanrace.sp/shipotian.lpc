// Xiakedao NPC
// modified by aiai on 6/28/1999
// 侠客岛之 "石破天"

#include <ansi.h>

inherit NPC;

void consider();
int ask_me();
void heal();
int do_answer(string arg);


string s_skill;
string ask_special_skill();

void create()
{
        set_name(YEL"石破天"NOR, ({"shi potian", "shi", "potian"}));
        seteuid( getuid());
        set("nickname", RED"侠客岛怪杰"NOR);
        set("title",GRN "长乐帮帮主"NOR );
        set("gender", "男性");
        set("age", 30);
        set("long", @LONG
    此人出生苦命，后由于种种机缘巧合，当得长乐帮的帮主。其人
虽不通文墨，但性直老实，心肠及好。屡经磨难后，终能在侠客岛上习得
一身本领。 
LONG );
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 80);
        set("int", 80);
        set("con", 80);
        set("dex", 80);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: heal :),
        }));

       
        set("max_qi", 5000);
        set("max_jing",5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        
        set("combat_exp", 8000000);
        set("score", 500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        
	// 特别技能指导能力
	s_skill = "master-neili";
        set("inquiry", ([
                "key" : (: ask_me :),
                "钥匙" : (: ask_me :),
                "自创武功" : (: ask_me :),
                "闭关室钥匙" : (: ask_me :),
				s_skill       : (: ask_special_skill :),
        ]) );
        
        set_skill("force", 600);
        set_skill("strike", 600);
        set_skill("xiake-strike", 600);
        set_skill("dodge", 600);
        set_skill("xiake-shenfa", 600);
        set_skill("xiake-shengong",600);
        set_skill("xiake-jianfa",600);
        set_skill("sword",600);
        set_skill("throwing",600);
        map_skill("strike", "xiake-strike");
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","xiake-shengong");
        map_skill("sword","xiake-jianfa");
        map_skill("parry","xiake-jianfa");
        prepare_skill("strike", "xiake-strike");

        setup();
        carry_object("/d/xiakedao/npc/obj/xguang")->wield();
        carry_object("/d/xiakedao/npc/obj/xgjia")->wear();
}


string ask_special_skill()
{
	object user;
	int cur_lvl, strike_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，在下已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("nation")!= "游牧民族")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (cur_lvl >= SPECIAL_D->query_level(user, "master-con"))
			return "你的根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("master-con") + "(master-con)吧。";
			
		strike_lvl = user->query_skill("strike",1)/20;
		if (strike_lvl < user->query_skill("finger",1)/20)
		{
			strike_lvl = user->query_skill("finger",1)/20;
		}
		if (cur_lvl >= strike_lvl)
			return "你的根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("strike") + "(strike)或者"+ to_chinese("finger") + "(finger)吧。";
			
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
			message_vision(query("name")+"在$N耳边轻声说了几句练气口诀。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得更有活力了。\n");
			return "内力须充盈于丹田……";
		}
	}
	return "什么？";
}

int accept_object(object user, object ob)
{
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	return 0;
}


void init()
{
	add_action("do_answer", "answer");
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
            case 0:
                command("perform feijian " + target->query("id"));
                break;
            case 1:
                command("yun qiankun " + target->query("id"));
                break;
        }
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 200");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

int ask_me()
{
	object me = this_player();
	if (!me->query("createskill/long"))
	{
		command("say 进入闭关室需要先征得龙岛主的同意，否则我不能把钥匙给你。");
		return 1;
	}
	else
	{
		me->set_temp("shi/asked", 1);
                command("say 你给我1000两黄金，我就把钥匙给你，你决定了回答我。(answer)");
		return 1;
	}
}

int do_answer(string arg)
{
	object me=this_player();
	object key, mbx;
	mapping mail;

	if (!me->query_temp("shi/asked")) return 0;
	if (!arg || (arg != "yes" && arg != "好" && arg != "行"))
        	command("say 你既然不愿意给钱，那就算了。");
	else
	{
                if(me->query("balance") < 10000000)
		{
			command("say 你的存款不够了，等你有钱了再来吧。\n");
			me->delete_temp("shi/asked");
			return 1;
		}
		else 
		{
                        me->add("balance", - 10000000);
			command("say 好吧，这把钥匙你拿去。\n");
			key = new("/d/xiakedao/npc/obj/yaoshi");
			key->move(me);

			mail = ([
					"from":	"钱眼开(qian yankai)",
					"title": "转帐成功！！！",
					"to": me->query("id"),
					"time": time(),
                                        "text": "阁下的一千两黄金已经成功汇入石破天大侠的账户。\n\n" + 
							"                   扬州钱庄钱眼开(qian yankai)敬上"
				]);
			mbx = me->query_temp("mbox_ob");
			if( !mbx ) 
			{
				mbx = new(MAILBOX_OB);
				mbx->set_owner(me->query("id"));
				mbx->move(me);
			}
			mbx->receive_mail(mail);
			me->save();
			message_vision("忽然一个驿站伙计急匆匆地走过来，交给$N一个邮箱，说道：您的信！然后头也不回的走掉了。\n",me);

		}
	}
	me->delete_temp("shi/asked");
	return 1;
}
