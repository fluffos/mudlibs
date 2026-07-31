// /NPC dizi1.c
// By River 99/05/20
#include <ansi.h>

inherit NPC;

void create()
{
       set_name("绿衣弟子", ({ "luyi dizi","dizi"}));
       set("long", "他是绝情谷公孙谷主的弟子，。\n");

       set("gender", "男性");
       set("age", 25);
       set("shen_type",1);
       set("attitude", "peaceful");
  
       set("str", 34);
       set("int", 30);
       set("con", 35);
       set("dex", 30);

       set("qi", 800);
       set("max_qi", 800);
       set("jing", 500);
       set("max_jing", 500);
       set("max_neili",300);
       set("eff_jingli",300);
       set("combat_exp",50000);
	   
       set_skill("force",40);
       set_skill("strike",50);
       set_skill("dodge",40);
       set_skill("parry",40); 

       setup();
       carry_object("/clone/misc/cloth")->wear();
}