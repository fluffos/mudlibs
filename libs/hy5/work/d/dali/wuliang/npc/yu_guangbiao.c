// NPC :yu_guangbiao.c 郁光标
// By River 98/12
inherit NPC;
void create()
{
        set_name("郁光标", ({ "yu guangbiao", "yu", "guangbiao"}));
        set("title","无量剑东宗弟子");              
        set("gender", "男性" );
        set("age", 36);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 15);
   	set("attitude", "friendly");

        set("max_qi", 5000);
        set("max_jing", 5800);
        set("eff_jingli", 5800);
        set("neili", 5000);
	set("qi", 5000);	
        set("max_neili", 5000);      
        set("unique", 1);
        
        set("long","他是无量剑东宗的弟子。\n");
        set("combat_exp", 200000);
        set("shen", 800); 

        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("force", 180);
        set_skill("cuff", 180);
        set_skill("sword", 180);
        set_skill("kurong-changong", 180);   
        set_skill("xiaoyaoyou", 180);
        set_skill("wuliang-jianfa", 180);
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuliang-jianfa");
        map_skill("sword", "wuliang-jianfa");
        map_skill("force", "kurong-changong");         

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/changpao")->wear();
}
