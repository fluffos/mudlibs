#include <ansi.h>
inherit NPC;

void create()
{
        set_name("费彬", ({ "fei bin", "fei", "bin" }));
        set("nickname", "大嵩阳手");
        set("long", "这人四十来岁，中等身材，瘦削异常，上唇留了两撇鼠须，是嵩山
派掌门左冷禅的第四师弟费彬、一套大嵩阳手武林中赫赫有名。\n");
        set("gender", "男性");
        set("age", 49);
        set("per", 18);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 25);
        set("int", 23);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", -14000);

    set_skill("force", 150);
    set_skill("songshan-qigong", 150);
    set_skill("dodge", 150);
    set_skill("zhongyuefeng", 150);
    set_skill("strike", 160);
    set_skill("songyang-zhang", 160);
    set_skill("parry", 150);
    set_skill("sword", 150);
    set_skill("songshan-jian", 150);
    set_skill("literate", 100);
    map_skill("force", "songshan-qigong");
    map_skill("dodge", "zhongyuefeng");
    map_skill("strike", "songyang-zhang");
    map_skill("parry", "songshan-jian");
    map_skill("sword", "songshan-jian");
    prepare_skill("strike", "songyang-zhang");
    create_family("嵩山派", 4, "弟子");
    set("chat_chance", 25);
    set("chat_msg", ({
                (: random_move :)
        }) );
    set("chat_chance_combat", 2);
    set("chat_msg_combat", ({
                (: perform_action, "strike.junji" :),
        }));
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
}

