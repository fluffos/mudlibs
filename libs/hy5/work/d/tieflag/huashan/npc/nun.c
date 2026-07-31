 inherit NPC;
#include <ansi.h> 
void create()
{
    set_name( "小尼姑" , ({ "ni gu" }) );
    set("gender", "女性");
    set("title", "松谷庵");
    set("nickname", HIC"守身如玉"NOR);
    set("age", 18);
    set("per",45);
    set("long", "一个小尼庵里的几个尼姑,貌美如花.\n");
    set("combat_exp", 2300000);
    set("score", 200);
    set("class", "huangshan"); 
    set("resistance/kee",10);
    set("no_busy",4);
   
    set("int", 30);
    set("cor", 30);
    set("cps", 30);
    set("spi", 30); 
    set("neili", 1000);
    set("max_neili", 1000);
    set("force_factor", 30);
    set("atman", 1000);
    set("max_atman", 1000);
    set("mana", 500);
    set("max_mana", 500);
    set("mana_factor", 5); 
           set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "parry.wushuang" :),	
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
/*
        set("inquiry", ([
            "出师": (: out_master :),
        ]) );
*/
        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
         set_skill("chongling-jian", 380);
        set_skill("huashan-sword", 200);
        set_skill("yunu-sword", 380);
        set_skill("zixia-shengong", 320);
        set_skill("huashan-ken", 200);
        set_skill("feiyan-huixiang", 200);
        set_skill("zhengqijue", 200);

        map_skill("sword", "chongling-jian");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");
    setup();
    carry_object("/clone/misc/cloth")->wear(); 
}     
