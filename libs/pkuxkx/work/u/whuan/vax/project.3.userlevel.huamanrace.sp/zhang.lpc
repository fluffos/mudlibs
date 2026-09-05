#include <ansi.h>
// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;
void consider();
void heal();


string s_skill;
string ask_special_skill();

void create()
{
        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
       set("nickname", HIR "邋遢真人" NOR);
        set("long",
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n");
        set("title",RED "武当派" NOR + GRN "开山" NOR+ RED "祖师" NOR);
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

          set("per", 80);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 15000000);
        set("score", 500000);

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set_skill("force", 450);
        set_skill("taiji-shengong", 400);
        set_skill("yinyun-ziqi", 350);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 450);
        set_skill("cuff", 450);
        set_skill("taiji-quan", 400);
        set_skill("claw",450);
            set_skill("taiji-zhao",400);
        set_skill("parry", 450);
        set_skill("sword", 450);
        set_skill("taiji-jian", 400);
	set_skill("blade", 450);
	set_skill("taiji-dao", 400);
        set_skill("taoism", 400);
        set_skill("literate", 300);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
       map_skill("claw","taiji-zhao");
    map_skill("blade","taiji-dao");
        prepare_skill("cuff", "taiji-quan");
prepare_skill("claw","taiji-zhao");

        create_family("武当派", 1, "开山祖师");
        set("class", "taoist");

	// 特别技能指导能力
	s_skill = "master-hp";
	set("inquiry", ([
		s_skill       : (: ask_special_skill :),
	]) );
	
        setup();
        carry_object("/clone/weapon/changjian");
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
			return "你的技能已经太高，老道已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("nation")!= "中原人士")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (cur_lvl >= SPECIAL_D->query_level(user, "master-str"))
			return "你的体质太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("master-str") + "(master-str)吧。";
			
		if (cur_lvl >= user->query_skill("unarmed",1)/20)
			return "你的体质太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("unarmed") + "(unarmed)吧。";
			
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
			message_vision(query("name")+"在$N耳边轻声说了几句健身口诀。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得更有活力了。\n");
			return "多多运动，可以强健身体。";
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

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜谷虚。"); 
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
		if ((int)ob->query("shen") < 50000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，?妊ё鋈恕?);
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_int() < 30) {
                command("say 我武当派武功全从道藏悟出。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性?词前氲阋猜砘⒉坏谩?);
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可
挖，还是请回吧。");
                return;
        }
        command("chat 哈哈哈哈！！！！");
        command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。")
;
        command("recruit " + ob->query("id"));
		if ((string)ob->query("gender")!="女性")
			ob->set("title" ,RED "武当派" NOR + GRN "真人" NOR);
		else
			ob->set("title" ,RED "武当派" NOR + GRN "女真人" NOR);
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(3) )
        {
            case 0:
            command("wield jian");
            command("perform sword.chan " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("perform cuff.zhen " +target->query("id"));
             break;
            case 2:
            command("exert powerup");
             break;
        }
}
void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <5000 && (string)ob->query("family/master_id") == "zhang sanfeng")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
}		

void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 100");
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
