// NPC :ge_guangpei.c 葛光佩
// By River 98/12
inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("葛光佩", ({ "ge guangpei", "ge", "guangpei"}));
        set("title","无量剑西宗弟子");              
        set("gender", "女性" );
        set("age", 36);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 20);
        set("no_get","葛光佩对你来说太重了。\n");
   	set("attitude", "aggressive");

        set("max_qi", 5000);
        set("max_jing", 5800);
        set("eff_jingli", 5800);
        set("neili", 5000);
	set("qi", 5000);	
        set("max_neili", 5000);      
        set("unique", 1);
        
        set("long","她是无量剑西宗的弟子。\n");
        set("combat_exp", 200000);
        set("shen", -800); 

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
        carry_object(__DIR__"obj/greyrobe")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object ob)
{
        command("say 既然被你撞见了，"+RANK_D->query_rude(ob)+"，拿命来吧！");
}
