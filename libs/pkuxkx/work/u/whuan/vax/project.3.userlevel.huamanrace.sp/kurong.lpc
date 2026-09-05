// kurong.c 枯荣大师
// by paladin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

string s_skill;
string ask_special_skill();
void create()
{
    set_name("枯荣大师", ({ "kurong dashi", "kurong" }));
    set("nickname", HIR "枯荣大师" NOR);
    set("start_room","/d/dali/muwu");
    set("long",
            "他左边的一半脸色红润，皮光肉滑，有如婴儿,\n"
            "右边的一半却如枯骨，除了一张焦黄的面皮\n"
            "之外全无肌肉，骨头突了出来，宛然便是半个骷髅骨头。\n");
    set("title",RED "天龙寺" NOR + GRN  "神僧" NOR);
    set("gender", "男性");
    set("age", 70);
    set("attitude", "friendly");
    set("shen_type", 1);
    set("str", 30);
    set("int", 30);
    set("dex", 30);
    set("max_qi", 3000);
    set("max_jing", 1000);
    set("neili", 2000);
    set("max_neili", 2000);
    set("jiali", 80);
    set("combat_exp", 1500000);
    set("score", 500000);
    set("chat_chance", 100);
		// 特别技能指导能力
		s_skill = "master-shaoyang";
    set("inquiry", ([
                "六脉神剑剑谱" : (: ask_me :),
                s_skill       : (: ask_special_skill :),
                ]));
    set("book_count", 1);

    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("finger", 150);
    set_skill("parry", 150);
    set_skill("literate", 150);
    set_skill("yiyang-zhi", 150);
    set_skill("kurong-shengong", 200);
    set_skill("dali-xinfa", 120);
    map_skill("force", "kurong-shengong");
    map_skill("finger", "yiyangzhi");
    prepare_skill("finger", "yiyangzhi");
    create_family("天龙寺", 1, "神僧");
    set("class", "bonze");

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
			return "你的技能已经太高，老僧已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		if (YINYANG_D->query_yinyang(user) != "少阳")
			return "你的内功并没有显现出少阳气息，恕在下无法指导。\n";
		
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
			message_vision(query("name")+"在$N耳边轻声说了几句控制少阳气息的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你感觉内功的少阳气息也随之增强了。\n");
			return "可惜我寺的六脉神剑便是少阴功夫。";
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
    if ((string)ob->query("family/family_name")!="天龙寺" ) {
        command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜本因方丈.\n");
        return;
    }

    if((int)ob->query("betrayer")>=2)
    {
        command("say "+RANK_D->query_respect(ob)+"你多次叛师，背信弃义。我怎会收你。\n");
        return;
    }

    if ((int)ob->query("score")<400){
        command("sigh"+ob->query("id"));
        command("say 你还是回去吧.我是不会收一个对不忠之人的\n");
        return;
    }

    if ((int)ob->query("shen") < 10000) {
        command("say 学武之人，德义为先");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                "是否还做得不够？");
        return;
    }

    command("chat 哈哈哈哈！！！！");
    command("chat 想不到在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
    command("recruit " + ob->query("id"));

    ob->set("title", GRN "天龙寺" NOR + YEL "第二代第子" NOR);
}

string ask_me()
{
    mapping fam;
    object ob;
    if (!(fam = this_player()->query("family")) || fam["family_name"] != "天龙寺")
        return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
    if( this_player()->query("score") < 200 )
        return "你对本派贡献太小，本派的武学典籍还不能给你。";
    if (query("book_count") < 1)
        return "你来晚了，本派的「六脉神剑剑谱」不在此处。";
    add("book_count", -1);
    ob = new("/d/dali/obj/lmsj");
    ob->move(this_player());
    return "好吧，这本「六脉神剑剑谱」你拿回去好好钻研。";
}


