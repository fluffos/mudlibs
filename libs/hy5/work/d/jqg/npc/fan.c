// yiweng.c 樊一翁
inherit NPC;
void consider();
void create()
{
       set_name("樊一翁", ({ "fan yiweng","fan","yiweng" }) );
       set("gender", "男性" );
       set("title","绝情谷大管家");
       set("age", 60);
       set("long", "他是公孙谷主的大弟子，额下长须飘逸，\n"+
                   "长长地拖在地上，身材稍微矮小。\n");
       set("attitude", "peaceful");
       set("str", 38);
       set("con", 21);
       set("int", 20);
       set("dex", 35);
       set("per", 15);
       set("unique", 1);

       set("max_qi", 4000);
       set("max_jing", 4800);
       set("neili", 7000);
       set("max_neili", 7000);
       set("eff_jingli",2000);
       set("jiali", 40);
       set("shen", -500);        
       set("combat_exp", 600000);

       set_skill("force", 180);      
       set_skill("dodge", 180);
       set_skill("parry", 180);
       set_skill("guiyuan-tunafa", 180);
       set_skill("literate", 80); 
       set_skill("shuishangpiao", 180);
       set_skill("tiezhang-zhangfa", 180);
       set_skill("strike",180);
       
       map_skill("force", "guiyuan-tunafa");
       map_skill("dodge", "shuishangpiao");
       map_skill("strike", "tiezhang-zhangfa");
       map_skill("parry", "tiezhang-zhangfa");
       prepare_skill("strike", "tiezhang-zhangfa");

       setup();
       carry_object("/clone/misc/cloth")->wear();
}
