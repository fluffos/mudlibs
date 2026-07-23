// guofu.c
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("郭襄", ({"guo xiang", "guo", "xiang"}));
    set("gender", "女性");
    set("age", 15);
    set("long", "她是郭靖黄蓉的小女儿，东邪黄药师的小外孙女，长得什么可爱。\n");

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
       
    set("combat_exp", 80000);
    set("score", 0);
       
    set_skill("force", 80);
    set_skill("bibo-shengong", 80);
    set_skill("unarmed", 80);
    set_skill("luoying-zhang", 80);
    set_skill("dodge", 80);
    set_skill("anying-fuxiang", 80);
    set_skill("parry", 80);
    set_skill("sword", 80);
    set_skill("luoying-shenjian", 80);
    set_skill("qimen-wuxing", 80);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

