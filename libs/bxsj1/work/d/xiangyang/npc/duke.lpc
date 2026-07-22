// duke.c 赌客
// Lklv 2001.9.24

inherit NPC;

void create()
{
        set_name("赌客", ({"du ke", "duke", "ke" }) );
        set("gender", "男性" );
        set("age", 35+random(10));
        set("long", "这是个游手好闲的赌客。\n");
        set("attitude","heroism");
        set("combat_exp", 15000+random(5000));
        set("shen_type", 0);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("wimpy", 80);

        set_temp("apply/attack", 20+random(20));
	set_skill("cuff", 40+random(10));
	set_skill("taizu-quan", 40);
        set_skill("dodge", 50+random(15));
        set_skill("parry", 40);
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");

/*
        set("chat_chance", 2);
        set("chat_msg", ({
                "赌客掏了掏口袋，摸出几个铜板掂了掂。\n",
                "赌客嘴里哼着小曲，斜眼向你问道：“身上带银子没有？咱们玩两手？”\n",
                "赌客发狠道：“这次俺一定要买九五二七 ！那个是俺以前在里面的终身代号！”\n",
                "赌客恨恨地嘀咕道：“上次老子不小心，居然会被猪肉荣赢去十两银子。”\n",
        }) );
*/
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 5+random(5));
}
