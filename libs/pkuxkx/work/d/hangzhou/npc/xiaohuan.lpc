// npc: /d/hangzhou/npc/xiaohuan.c
// by hubo

inherit NPC;

void create()
{
        set_name("小欢", ({ "xiao huan", "huan", "xiao" }) );
        set("gender", "女性" );
	set("title", "怡红馆老板娘");
     set("start_room","/d/hangzhou/jiyuan");
  	set("nickname", "床上淫娃");
        set("age", 42);
        set("long", 
            "小欢是妓院的老板娘，但可是有后台的"
	    "一般人可不敢惹她\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "老娘我就是小欢。",
            "无欢" : "问我们大老板干什么，小心杀了你档",
       ]) );

        setup();
        setup();
        
        carry_object("/d/city/obj/flower_shoe")->wear();

        carry_object("/d/city/obj/pink_cloth")->wear();
}
/*
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
*/
