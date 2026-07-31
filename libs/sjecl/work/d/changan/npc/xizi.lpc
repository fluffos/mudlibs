// xizi.c 戏子

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("戏子", ({"xi zi", "xizi", "zi"}) );
        set("gender", "女性" );
        set("age", 20 + random(8));
        set("long", "她冲你眨了下"BLINK"左眼"NOR"，见你表情尴尬，她又眨了下"BLINK"右眼"NOR"。\n");
        set("shen_type", 0);
        set("attitude","friendly");

        set("per", 27);
        set("pur", 27);
        set("str", 26);
        set("dex", 26);
        set("con", 26);
        set("int", 26);
        set("env/wimpy", 20);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiaji", 50);
        set("combat_exp", 150000);
        set_temp("apply/attack", 35);
        set_temp("apply/defense", 15);

        set_skill("force", 100);
        set_skill("dodge", 105);
        set_skill("parry", 100);
        set_skill("cuff", 100);

        set("chat_chance", 3);
        set("chat_msg", ({
                "戏子回头看了看，抛了一个飞眼给你。\n",
                }) );
        setup();

        carry_object(ARMOR_D("qipao"))->wear();
        carry_object(ARMOR_D("ruanxue"))->wear();
        add_money("silver",20+random(10));
}
