// npc: /d/xingxiu/shangren.c

inherit NPC;
void create()
{
        set_name("波斯商人", ({ "bosi shangren", "shangren", "trader" }));
        set("gender", "男性");
        set("age", 40 + random(10));
        set("long", "一个高鼻蓝眼的波斯商人。他看着你脸上露出狡猾的笑容。\n");
        set("attitude", "friendly");
        set("combat_exp", 6000);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("blade", 40);
        set_skill("parry", 30);
        set_skill("dodge", 40);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
		"波斯商人对你挤了一下眼睛\n",
		"波斯商人对你说：阿拉阿可巴，穆罕默德瑞素阿拉。 你没听懂。\n",
                (: random_move :)
        }));
        carry_object(BINGQI_D("wandao"))->wield();
        carry_object(ARMOR_D("changpao"))->wear();
}
