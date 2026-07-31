// guofu.c
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("郭芙", ({"guo fu", "guo", "fu"}));
    set("gender", "女性");
    set("age", 19);
    set("long", "她是郭靖黄蓉的大女儿，东邪黄药师的大外孙女，长得如花似玉。\n");

    set("attitude", "peaceful");
       
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 0);
       
    set("combat_exp", 150000);
    set("score", 0);
       
    set_skill("force", 160);
    set_skill("bibo-shengong", 160);
    set_skill("unarmed", 160);
    set_skill("luoying-zhang", 160);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 160);
    set_skill("parry", 160);
    set_skill("sword", 160);
    set_skill("luoying-shenjian", 160);
    set_skill("qimen-wuxing", 160);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

