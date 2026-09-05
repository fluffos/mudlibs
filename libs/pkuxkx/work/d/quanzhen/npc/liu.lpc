// Created by hacky
// data: 1997.11.20
               
#include <ansi.h> 
inherit NPC; 
inherit F_MASTER;
   

void create()
{
	set_name("刘处玄", ({ "liu chuxuan" , "liu" }));
        set("title",HIB"全真派"NOR+GRN"真人"NOR);
        set("nickname",YEL"长生子"NOR);
	set("long",
	"他是全真教的第二代弟子，仙风道骨，颌下三缕长须，头戴一顶紫金冠，身穿\n"
	"一件八卦道袍，手执拂尘，看上去飘飘然宛如神仙中人，俨然是一位得道高人。\n");
	set("gender", "男性");
	set("apprentice_available", 50);
	set("age", 53);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 300);
	set("combat_exp", 25000);
	set("score", 20000);
	set_skill("daoxue-xinfa",100);
	set_skill("sword",120);
        set_skill("quanzhen-jian",120);
        set_skill("cuff",100);
	
	set_skill("array", 100);
	set_skill("dodge", 100);
	set_skill("jinyan-gong", 100);
	set_skill("unarmed", 120);
        set_skill("yangxin-quan",100);
	set_skill("parry", 120);
        map_skill("sword","quanzhen-jian");
	map_skill("dodge","jinyan-gong");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
        map_skill("cuff","yangxin-quan");
	setup();
                	
	create_family("全真派", 2, "真人");
	carry_object(__DIR__"obj/robe")->wear();
	carry_object(__DIR__"obj/sword")->wield();
}

void attempt_apprentice(object ob)
{
 command ("say 贫道现在不收徒弟.");
 command ("say "+RANK_D->query_respect(ob)+"可以去拜我的师兄丘处机");
  return;
 }
