// jxiang-ke.c 进香客

inherit NPC;

void create()
{
        set_name("进香客", ({ "jingxiang ke", "ke" }));
        set("gender", random(2)==1 ? "男性":"女性");
        set("age", 24 + random(50));

        set("combat_exp", 500 + random(1000));
        set("shen_type", random(50));
      	set("chat_chance", 10);
        set("chat_msg", ({ (: random_move :),}) );
        setup();
        add_money("silver", 1 + random(10));
}
