// beggar.c

inherit NPC;

void create()
{
        set_name("乞丐", ({ "beggar" }) );
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个满脸风霜之色的老乞丐。\n");
        set("combat_exp", 2000);
        set("str", 27);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 5);
        setup();
        set("chat_chance", 20);
        set("chat_msg", ({
                "乞丐说道：好心的大爷哪～ 赏我要饭的几文钱吧～\n",
                "乞丐懒洋洋地打了个哈欠。\n",
		  "乞丐伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬烂了。 \n",
                (: random_move :)
        }) );
        set("inquiry",([
	"叫化鸡" : "那可是我们乞丐的绝活。\n",
]));
        carry_object(__DIR__"obj/old_book");
	carry_object(__DIR__"obj/beggar_cloth")->wear();
}

int accept_object(object me, object obj)
{
	object ob;
	if(obj->name() == "死鸡") {
	if(!me->query_temp("xiaozhen/死鸡")) {	
		command("say 啊，可以做顿叫化鸡来吃了，好好改善一下，谢谢了。");
		me->set_temp("xiaozhen/死鸡",1);
	return 1;
		}
		command("say 您又送来一只，这怎么好意思。这样吧，请您等一下。");
		me->start_busy(3);
		write("乞丐又烧火又弄鸡，忙活了一阵。\n");
		ob = new(__DIR__"obj/jiaohuaji");
		ob->move(me);
		me->delete_temp("xiaozhen/死鸡");
		me->stop_busy();
		command("say 这只叫化鸡送给您尝尝新鲜吧。");
		return 1;
	}
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"饶命！小的这就离开！\n");
        return 0;
}