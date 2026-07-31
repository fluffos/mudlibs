// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("陈达海", ({ "chen dahai", "chen", "dahai" }) );
       set("title", "镖师");
       set("nickname", "青蟒剑");
       set("gender", "男性" );
       set("shen", -2500);
       set("age", 43);
       set("str", 23);
       set("con", 20);
       set("int", 20);
       set("dex", 22);
       set("env/wimpy", 60);
       set("long","
一个身穿羊皮袄的高大汉子，虬髯满腮，说的哈萨克语很不纯正，
但目光炯炯，腰间挂著一柄长剑。他是霍元龙手下的镖师之一。\n" );
       set("combat_exp", 250000);
       set("attitude", "heroism");
        set("chat_chance", 10);
       set("chat_msg", ({ (: random_move :) }) );          
     set("str", 75);
	set("int", 70);
	set("con", 78);
        set("dex", 74);
	
	set("max_qi", 36000);
	set("max_jing", 36000);
	set("neili", 56000);
	set("max_neili", 56000);
	set("jiali", 200);
	set("combat_exp", 9500000);
	set("score", 500000);
set_skill("unarmed",280);
	set_skill("force", 280);
	set_skill("guiyuan-tunafa", 280);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("hammer", 280);
	set_skill("axe", 280);
	set_skill("shuishangpiao", 280);
	set_skill("strike", 350);
	set_skill("tiezhang-zhangfa", 280);
	set_skill("parry", 200);
	set_skill("cuff", 300);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",280);
	set_skill("duanyun-fu", 280);
	set_skill("tongbi-zhang", 280);
	set_skill("xuanyuan-axe", 280);
	set_skill("liumang-quan", 280);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("cuff", "liumang-quan");
	map_skill("parry", "xuanyuan-axe");
	map_skill("axe", "xuanyuan-axe");
	prepare_skill("strike", "tiezhang-zhangfa");
	prepare_skill("cuff", "liumang-quan");
        set("chat_chance_combat", 59);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.pofuchenzhou" :),
                (: perform_action, "cuff.guguoshenyou" :),
                (: perform_action, "cuff.luori" :),
                (: perform_action, "axe.kaitianpidi" :),
                (: perform_action, "axe.sanbanfu" :),
                (: perform_action, "axe.jiuqipoxiao" :),
                (: perform_action, "axe.jiuqipoxiao" :),                	
                (: perform_action, "axe.jiuqipoxiao" :),                	                	
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bigaxe") :),
		(: command("wield bigaxe") :),			
        }) );
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 80);  
       setup();
       carry_object("/d/tiezhang/npc/obj/axe")->wield();
       carry_object(__DIR__"obj/jinjian");
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 10);
}
#include "bs.h";

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
      


        me->set_temp("killltl3",1);



              ::die();
        return;
}