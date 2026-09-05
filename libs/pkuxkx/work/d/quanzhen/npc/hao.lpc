
//hao.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("郝大通", ({ "hao datong" , "hao" }));
        set("title",HIB"全真派"NOR+GRN"真人"NOR);
        set("nickname",YEL"广宁子"NOR);
        set("long",
        "他是全真教的第二代弟子，肥胖高大，\n"
        "状貌似是个官宦模样，道袍的双袖都去了半截，至肘而止。\n");
        set("gender", "男性");
        set("apprentice_available", 50);
        set("age", 33);
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
        set("combat_exp", 250000);
        set("score", 20000);
        set_skill("daoxue-xinfa",100);
        set_skill("sword",120);
        set_skill("quanzhen-jian",120);
        set_skill("cuff",100);
        set_skill("force",100);
        set_skill("xiantian-gong",100);
        set_skill("array",100);
        set_skill("yangxin-quan",100); 
        set_skill("kongming-quan",80);
        set_skill("dodge", 100);
        set_skill("jinyan-gong", 100);
        set_skill("parry", 120);

        map_skill("sword","quanzhen-jian");
        map_skill("dodge","jinyan-gong");
        map_skill("cuff","yangxin-quan");
        map_skill("parry","quanzhen-jian");
        map_skill("array","tiangang-beidou");
        map_skill("force","xiantian-gong");

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 200);
        setup();

        create_family("全真派", 2, "真人");
        carry_object(__DIR__"obj/robe")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}                 