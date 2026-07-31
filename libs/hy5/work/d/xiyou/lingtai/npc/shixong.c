// worker.c

inherit NPC;
string try_me(object me);

void create()
{
        set_name("皤不分", ({"bo bufen", "bo"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个胖乎乎的道士，正傻呵呵的不知笑什么．\n");
	set("class", "taoist");
        set("combat_exp", 5000);
	set("daoxing", 10000);

        set("attitude", "friendly");


        setup();

}
string try_me(object me)
{	me = this_player();
        command ("say 试试也好．．．");

message_vision("皤不分双手往$N头上一按，念了句咒语．$N迷糊之中好象飞了出去．．．\n",
me);
	me->move("/d/xiyou/lingtai/hill");
	return "怪了，人怎么不见了？";
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );
}