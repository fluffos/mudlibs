// longwang.c 紫杉龙王
#include <ansi.h>
inherit NPC;

object ob = this_object();
void create()
{
        set_name("黛绮丝",({"dai qisi","dai","longwang"}));
        set("title","明教护教法王");
        set("long", 
                "她就是明教的四大护教法王的大姐姐。\n"
                "她一身深紫色罗裙，枭动生姿，青丝及腰，玉颊生春。虽然人到中年，仍然风味犹存。\n");
        set("age", 43);
        set("nickname",MAG"紫杉龙王"NOR);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 32);
        set("con", 20);
        set("dex", 30);
        set("per", 24);
        
        set("max_qi",2000);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 60);
        set("combat_exp", 4000000);
    

        set_skill("sword",260);
        set_skill("dodge",280);
        set_skill("unarmed",260); 
        set_skill("literate",260);
        set_skill("force",260);
        set_skill("shenghuo-shengong",260);
        set_skill("qingyunwu", 260);
        set_skill("liehuo-jian",360);
        set_skill("blade",260);
        set_skill("shenghuo-quan",260);  

        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        map_skill("unarmed","shenghuo-quan");

        create_family("明教",34,"弟子");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        
}

