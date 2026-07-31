// rascal.c

inherit NPC;

void create()
{
        set_name("流氓", ({ "rascal" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long", "一个满脸泥污的小流氓。\n");
        set("combat_exp", 20000);
        set("str", 27);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 5);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
		  "流氓哼道：我看见你那雪白的大腿，我就起～了～坏～心～喽。\n",
		  "流氓哼道：梦会夜月淡..溶..溶，展转牙床春..色..少。\n",
		  "流氓打个瞌睡，躺在地上睡了。\n",
        }) );
//      carry_object(__DIR__"obj/old_book");
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"想玩两手？小的奉陪就是。\n");
        return 1;
}
 
