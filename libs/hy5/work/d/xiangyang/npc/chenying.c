// guofu.c
inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("程英", ({"chen ying", "chen", "ying"}));
    set("gender", "女性");
    set("age", 19);
    set("long", "她是是黄药师的小徒弟，长的端重美丽。\n");

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
       
    set("combat_exp", 180000);
    set("score", 0);
       
    set_skill("force", 180);
    set_skill("bibo-shengong", 180);
    set_skill("unarmed", 180);
    set_skill("luoying-zhang", 180);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 180);
    set_skill("parry", 180);
    set_skill("sword", 180);
    set_skill("luoying-shenjian", 180);
    set_skill("qimen-wuxing", 180);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

