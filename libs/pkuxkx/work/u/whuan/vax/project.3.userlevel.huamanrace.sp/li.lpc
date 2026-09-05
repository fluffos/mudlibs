#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void consider();
void heal();
string s_skill;
string ask_special_skill();
void create()
{
        set_name("李秋水", ({ "li qiushui", "li" }));
        set("title",MAG "天山" NOR + BLK "童老" NOR );
        set("long",
                "她脸上蒙着一块丝巾，隐隐约约可以发现有几道纵横交错的伤痕。\n"
		+"有人说她就是当年令正派人士深恶痛绝的天山童姥，但从身材上\n"
		+"看又和传说有点不符，但从来也没人敢向她询问这件事情。\n");

        set("gender", "女性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 8000);
	set("qi",8000);
        set("max_jing", 8000);
	set("jing",8000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 200);
        set("combat_exp", 11000000);
        set("score", 800000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
		// 特别技能指导能力
		s_skill = "mind-searching";
        set("inquiry", ([
            
                "丁春秋" :
                "你问他干吗，他是我的师侄",
                s_skill       : (: ask_special_skill :),
                    ]) );
        set_skill("force", 350);
        set_skill("huagong-dafa", 350);
        set_skill("dodge", 450);
        set_skill("zhaixinggong", 400);
        set_skill("strike", 350);
        set_skill("xingxiu-duzhang", 350);
        set_skill("hand", 350);
        set_skill("zhaixing-shou", 350);
     set_skill("sword",350);
     set_skill("mintian-jiushi",350);
        set_skill("parry", 380);
        set_skill("staff", 380);
        set_skill("tianshan-zhang", 380);
     	set_skill("literate", 200);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "tianshan-zhang");
 map_skill("sword","mintian-jiushi");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
	create_family("星宿派",1,"毒姑");
        set("class", "taoist");
        setup();
        carry_object("/d/xingxiu/obj/bingpozhang")->wield();
}
void init()
{
        object me;
        me=this_player();
if ((int)me->query("shen") >0 && (string)me->query("family/master_id")=="li qiushui")
        {
                command("say 你多次杀我同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ me->query("id"));
        }
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
			return "你的技能已经太高，老身已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		if (user->query("nation")!= "苗家部族")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (!SPECIAL_D->query_level(user, "master-con"))
			return "你先要修习"+to_chinese("master-con")+"(master-con)才能修练"+to_chinese(s_skill)+"。";
		
		if (cur_lvl >= user->query_skill("huagong-dafa",1)/20)
			return "你的化功大法根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("huagong-dafa") + "(huagong-dafa)吧。";
			
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
			message_vision(query("name")+"在$N耳边轻声说了几句传音搜魂的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你的通灵术有所提高。\n");
			return "我跟师姐不共戴天！";
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

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100000) {
                command("say 我越看你越象白道派来卧底的。");
                return;
        }
        if ((int)me->query("score") < 1500)
                {
                message_vision("李秋水露出一副不信任的样子. \n", me);
                command("say 你对本门尽心了吗？");
            return;
        }
	if((int)me->query_skill("tianshan-zhang",1)<120)
		{command("say 你是否应该在天山杖上多下点功夫.\n");
		return;
	}
    if((int)me->query_skill("huagong-dafa",1)<130)
		{command("say 你是否应该在化功大法上多下点功夫.\n");
		return;
}

		
  
        command("recruit " + this_player()->query("id"));
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",HIR "星宿派" NOR + GRN +"魔头" NOR);
        else
                this_player()->set("title",HIR "星宿派" NOR + GRN +"毒姑" NOR);
}
     
     

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("perform parry.handu " + target->query("id"));
             break;
            case 1:
            command("unwield zhang");
            command("perform strike.sandu " +target->query("id"));
            command("wield zhang");
             break;
             }
}
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
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
