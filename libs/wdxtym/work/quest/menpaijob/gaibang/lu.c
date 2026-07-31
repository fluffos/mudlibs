// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
#include "huajob.h"
void consider();

string ask_me();
void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌棒龙头");
	set("gender", "男性");
        set("beggarlvl",9);
	set("age", 45);
	set("long", 
		"鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	set("str", 235);
	set("int", 232);
	set("con", 235);
	set("dex", 230);

	set("qi", 56900);
	set("max_qi", 56900);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 242000);
	set("max_neili", 242000);
	set("jiali", 100);
	
	set("combat_exp", 3500000);
	set("score", 20000);
	set("book_count", 1);
			set_skill("fengmo-zhang",250);
	set_skill("liuhe-zhang",250);
	set_skill("strike",290);
	set_skill("force", 190); // 基本内功
	set_skill("huntian-qigong", 290); // 混天气功
	set_skill("unarmed", 195); // 基本拳脚
	set_skill("xianglong-zhang", 280); // 降龙十八掌
	set_skill("dodge", 250); // 基本躲闪
	set_skill("xiaoyaoyou", 250); // 逍遥游
	set_skill("parry", 250); // 基本招架
	set_skill("staff", 255); // 基本棍杖
	set_skill("begging", 250);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
       set("inquiry",([
                 "job" : (: ask_job :),
		 "叫化鸡" : (: ask_me :),
       ]));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );

	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        
	create_family("丐帮", 18, "九袋长老");
	setup();
	carry_object("kungfu/class/gaibang/obj/jiaohuaji")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
		return;
	}
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "丐帮")
		return this_player()->query("name") + "与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，叫花鸡已经给别人吃了!!";
	add("book_count", -1);
	ob = new("kungfu/class/gaibang/obj/jiaohuaji");
	ob->move(this_player());
	return "洪帮主，可是最喜欢吃这个的。你拿去给他老人家，他会很高兴的!!";
}

int hit_ob(object me, object ob, int damage)
{
if (ob!=me)
{
ob->start_busy(12);
	ob->apply_condition("qx_snake_poison", 220);
	ob->apply_condition("wugong_poison", 140);
        ob->apply_condition("chanchu_poison", 140);
        ob->apply_condition("xiezi_poison", 140);
        ob->apply_condition("snake_poison", 140);
        ob->apply_condition("zhizhu_poison", 140);
        tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
}
}