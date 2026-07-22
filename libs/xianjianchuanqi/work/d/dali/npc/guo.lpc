// guo.c 过彦之
inherit NPC;

void create()
{
        set_name("过彦之", ({ "guo yanzhi","guo","yanzhi"}) );
        set("long","一个身材高大的中年汉子，一身丧服，头戴订冠，满脸风尘之色。
他双目红肿，显是家有丧事、死了亲人。\n");
        set("title","大理臣民");
        set("nickname", "追魂鞭");
        set("gender", "男性");
        set("age", 45);
        set("shen_type", -1);
        set("str", 27);
        set("int", 18);
        set("con", 22);
        set("dex", 24);
        set("unique", 1);

        set("max_qi", 1000);
        set("max_jing", 700);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 450000);
        set("eff_jingli",700);
        set_skill("force", 100);
        set_skill("huntian-qigong", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 80);
        set_skill("whip",120);
        set_skill("parry", 100);
        map_skill("force", "huntian-qigong");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 20);
        set("chat_chance", 3);
        set("chat_msg", ({
        "过彦之惨声道：师傅给人害死，定是那姑苏慕容干的，得赶快去找大师兄共商报仇之计。\n",
               (: random_move :)
        }) );
        setup();
        carry_object("/clone/armor/armor")->wear();
        carry_object(__DIR__"obj/bian")->wield();
}
