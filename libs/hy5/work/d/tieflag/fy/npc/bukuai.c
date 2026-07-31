inherit NPC; 
void create()
{
        set_name("捕快", ({ "bukuai"}) );
        set("long","这是个专事破案捉盗的捕快。");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000+random(4000000));
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                                "捕快喝道：大胆刁民竟敢拒捕？反了！反了！\n",
        }) );
                set_skill("unarmed", 100+random(100));
        set_skill("xianglong-zhang", 20+random(50));
        set_skill("dodge", 100+random(100));
                set_skill("move", 100+random(100));
        set_skill("parry", 200+random(100));
        set_skill("wuxing-dun",100);
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge","wuxing-dun");
        set_temp("apply/attack", 70);
                set_temp("apply/dodge", 70);
                set_temp("apply/parry", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
