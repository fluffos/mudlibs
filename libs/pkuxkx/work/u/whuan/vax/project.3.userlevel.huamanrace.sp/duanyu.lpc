// duanyu.c 段誉
// by paladin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

// int ask_me();

string s_skill;
string ask_special_skill();
void create()
{
        set_name("段誉", ({ "duan yu", "duan" }));
        set("nickname", HIR "风流浪子" NOR);
        set("long",
                "他就是段誉\n");
	
        set("title",RED "大理" NOR + GRN  "王子" NOR);
        set("gender", "男性");
        set("age", 18);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("dex", 30);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 100);
         set("combat_exp", 8000000 + random(4000000));
        set("score", 1000000);

        set("chat_chance", 100);

//        set("inquiry", ([
//                "六脉神剑剑谱" : (: ask_me :),
//        ]));
//        set("book_count", 1);


        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("liumai-shenjian", 250);
        set_skill("literate", 250);
        set_skill("yiyangzhi", 250);
          set_skill("beiming-shengong", 380);
        set_skill("lingbo-weibu", 250);

        map_skill("finger", "liumai-shenjian");
        map_skill("force", "beiming-shengong");
        map_skill("dodge","lingbo-weibu");
        map_skill("parry", "liumai-shenjian");
        prepare_skill("finger","liumai-shenjian");
        create_family("天龙寺", 1, "俗家第子");
//        set("class", "bonze");

		// 特别技能指导能力
		s_skill = "master-shaoyin";
        set("inquiry", ([
                s_skill       : (: ask_special_skill :),
        ]));
        setup();

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
			return "你的技能已经太高，小生已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		if (YINYANG_D->query_yinyang(user) != "少阴")
			return "你的内功并没有显现出少阴气息，恕在下无法指导。\n";
		
		if (!SPECIAL_D->query_level(user, "master-con"))
			return "你先要修习"+to_chinese("master-con")+"(master-con)才能修练"+to_chinese(s_skill)+"。";
			
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
			message_vision(query("name")+"在$N耳边轻声说了几句控制少阴气息的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你感觉内功的少阴气息也随之增强了。\n");
			return "王姑娘现在在哪里呢？";
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
        if ((string)ob->query("family/master_name")!="枯荣大师" ) {

     command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜枯荣大师.\n");
                return;
        }


        if((int)ob->query("betrayer")>=1)
        {
command("say "+RANK_D->query_respect(ob)+"你多次叛师，背信弃义。我怎会收你。\n");
                return;
        }

        if ((int)ob->query("score")<1000){
        command("sigh"+ob->query("id"));
             command("say 你还是回去吧.我是不会收一个对大理国不忠之人的\n");
             return;
       }


        if ((int)ob->query("shen") < 20000) {
        command("say 学武之人，德义为先");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                    "是否还做得不够？");
              return;
        }

        if ((int)this_player()->query_int() < 40 )
        {
   command("say 学习秘技要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够\n");
                return;
        }

        command("chat 想不到我段誉又觅得一个可塑之才，真是可喜可贺。");
        command("recruit " + ob->query("id"));

        ob->set("title", GRN "天龙寺" NOR + YEL "使者" NOR);
}

//string ask_me()
//{
//        mapping fam;
//        object ob;
//            if (!(fam = this_player()->query("family"))
//            || fam["family_name"] != "天龙寺")
//                return RANK_D->query_respect(this_player()) +
//                "与本派素无来往，不知此话从何谈起？";
//        if (query("book_count") < 1)
//                return "你来晚了，本派的「六脉神剑剑谱」不在此处。";
//        add("book_count", -1);
//        ob = new("/d/dali/obj/lmsj");
//        ob->move(this_player());
//        return "好吧，这本「六脉神剑剑谱」你拿回去好好钻研。";
//}

