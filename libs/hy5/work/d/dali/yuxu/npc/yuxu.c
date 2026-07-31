// Modify By River 98/12
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("玉虚散人", ({ "yuxu sanren", "yuxu", "sanren" }));
        set("title", "玉虚观主持");
        set("long", "这是一个中年道姑，但容颜俏丽，略带些哀愁。\n");
        set("gender", "女性");
        set("rank_info/respect", "道姑");
        set("age", 37);
        set("attitude","friendly");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("unique", 1);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
                (: perform_action, "whip.sanwu" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );

        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        
        set_skill("xue-dao", 150+random(180));
        set_skill("unarmed",150+random(180));
        set_skill("xianglong-zhang",150+random(180));
        set_skill("dodge", 150+random(180));
        set_skill("blade", 150+random(180));
        set_skill("parry", 150+random(180));
        set_skill("dashou-yin", 150+random(180));
        set_skill("shenkong-xing", 150+random(180));
        set_skill("longxiang", 150+random(180));
        set_skill("huntian-qigong", 150+random(180));
        set_skill("whip", 150+random(180));
        set_skill("chilian-shenzhang", 150+random(180));
        set_skill("jueqing-bian", 150+random(180));
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("unarmed","xianglong-zhang");
        map_skill("strike","chilian-shenzhang");
        map_skill("whip","jueqing-bian");
        prepare_skill("strike", "chilian-shenzhang");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 100);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}
        
        set("combat_exp", 150000);
        set("max_qi", 900);
        set("max_jing", 400);
        set("neili", 900);
        set("eff_jingli",400);
        set("max_neili", 900);
        setup();
        carry_object(__DIR__"obj/fuchen")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();

}
