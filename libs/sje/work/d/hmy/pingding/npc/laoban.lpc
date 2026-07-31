
inherit NPC;
inherit F_DEALER;

int ask_book();
void create()
{
        set_name("药铺老板", ({ "yaopu laoban", "laoban", "boss" }));
        set("gender", "男性");
        set("long", "一位精明的药房老板, 经营着祖传的老铺。\n");
        set("age", 65);

        set("int", 20);
        
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 300);
        set("max_jing", 300);
        set("shen_type", 1);

        set("combat_exp", 5000);
        set("attitude", "heroism");

        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 20);

        set("vendor_goods", ({
                
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 15);
}

