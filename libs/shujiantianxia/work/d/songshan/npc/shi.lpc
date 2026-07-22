#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("史登达", ({ "shi dengda", "shi", "dengda" }));
        set("nickname", "千丈松");
        set("long", "这是左冷禅的徒弟，他是位身材甚高的黄衫汉子。\n");
        set("gender", "男性");
        set("age", 26);
        set("per", 20);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        
        set("max_qi", 1400);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("jiali", 20);
        set("combat_exp", 700000);
        set("shen", -7000);

    set_skill("force", 100);
    set_skill("songshan-qigong", 100);
    set_skill("dodge", 100);
    set_skill("zhongyuefeng", 100);
    set_skill("strike", 100);
    set_skill("songyang-zhang", 100);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("songshan-jian", 100);
    set_skill("literate", 50);
    map_skill("force", "songshan-qigong");
    map_skill("dodge", "zhongyuefeng");
    map_skill("strike", "songyang-zhang");
    map_skill("parry", "songshan-jian");
    map_skill("sword", "songshan-jian");
    prepare_skill("strike", "songyang-zhang");
    create_family("嵩山派", 5, "弟子");
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();  
        carry_object(BINGQI_D("changjian"))->wield();         
}

void attempt_apprentice(object ob)
{
     if(ob->query("shen") < 0 && ob->query("combat_exp") < 10000){
        command("say 你这邪魔外道，还敢来我嵩山派？快滚！");
        return;
        }
     command("say 好吧，师傅正要我多培育一些弟子来发扬嵩山派呢。");
     command("recruit " + ob->query("id"));
}
