//【蜀山派】mhxy-yushu 2001/2
#include <ansi.h>
#include "shushan.h"
inherit NPC;
string ask_me();
int ask_jiu();
void create()
{
       set_name("酒剑仙", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", HIC"醉道士"NOR);   
       set("long", "一人人送外号“酒剑仙”，行踪不定，或游历于名山大川之畔，或隐匿于街头闹市之中。\n");
       set("gender", "男性");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 80);
       set("int", 80);
       set("per", 80);
       set("con", 80);
       set("combat_exp", 100000000);
       set("max_qi", 3700000);
       set("max_jing", 1700000);
       set("neili", 4000000);
       set("max_neili", 2000000);
       set("jiali", 1200);
       set("max_mana", 2000);
       set("mana", 4000);
       set("max_jingli", 200000);
       set("max_neili", 200000);
     set("jingli", 200000);
        set("neili",3000000);
        set_skill("shushan-force", 1000);
      set_skill("yujianshu", 1000);
      set_skill("fumozhang", 1000); 
      set_skill("zuixian-steps", 1000);
        set_skill("spells", 1000);
        set_skill("xianfeng-spells", 1000);
       set_skill("sword", 1000);
       set_skill("unarmed", 1000);
       set_skill("dodge", 1000);
       set_skill("literate", 1000);
       set_skill("force", 1000);
       set_skill("parry", 1000);
       map_skill("dodge", "zuixian-steps");
      map_skill("spells", "xianfeng-spells");
	map_skill("parry", "yujian-shu");
	map_skill("sword", "yujian-shu");
       map_skill("force", "shushan-force");
       map_skill("unarmed","fumozhang");
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
		  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
       set("inquiry", ([
        "酒神" : (: ask_jiu :),
	  "仙术" : (: ask_me :),

       ]) );
       create_family("蜀山派", 2, "弟子");
set("book_count", 1);
       setup();
      carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山派") {
         if ((int)ob->query("combat_exp") < 10000000 ) {
  	command("say 你的exp还不够，" + RANK_D->query_respect(ob) + "还需多加努力才行。\n");
	return;
	}
       if( (int)ob->query_skill("force", 1) < 750 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "你看你的猴样还来找我拜师? 你还是找追云子他们练着吧!\n");
	command("sigh");
	return;
	}
       command("haha");
       command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
       command("recruit " + ob->query("id") );
	return;
	}
       command("shake");
       command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
       return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山酒剑仙弟子");

               } 
}

int ask_jiu()
{

    object ob=this_player();
    if(ob->query("family/family_name") != "蜀山派")
    {
    command("say 你又不是蜀山派的，谁管你！");
    return 1;
    }
    if(ob->query("shushan/jiushen_cast"))
    { 
    command("say 你不是问过了吗? ");
    return 1;
    }
    if(ob->query("family/master_name") == "酒剑仙" )
    {
    command("say 这一招酒神，是为师唯一能给你的，绝不比任何法术差！它应该可以帮你保命的！");
    ob->set("shushan/jiushen_cast",1);
    return 1;
    }
}


string ask_me()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) 
        || fam["family_name"] != "蜀山派")
                return RANK_D->query_respect(this_player()) + 
                "又不是蜀山派的，谁管你！";
        if (query("book_count") < 1)
                return "你来晚了";
        add("book_count", -1);
        ob = new("/d/shushan/obj/xfbook");
        ob->move(this_player());
        return "好吧，这你拿回去好好钻研。";
}


