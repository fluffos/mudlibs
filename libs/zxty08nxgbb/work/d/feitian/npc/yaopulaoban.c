// npc: 药铺老板

inherit NPC;

void create()
{
        set_name("药铺老板", ({ "lao ban", "lao", "boss" }) );
        set("gender", "男性" );
	set("title", "大理名医");
        set("age", 50);
        set("long",
	    "他正盯着一本药谱在看。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 20);
	set_skill("force", 20);
        set_skill("dodge", 35);

        set("combat_exp", 25000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");
        set("inquiry", ([
            "行医" : "老夫一生，医人无数，也算行了件大善事。",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();

}

void init()
{
        object ob;

        add_action("do_ai", "ai");
        add_action("do_undress", "undress");
        add_action("do_mo", "mo");
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
    command("look " + me->query("id"));

    if (me->query("gender")=="无性") {
       command("say 你没那本事，跑这来让人耻笑吗？");
       command("kick " + me->query("id"));
       message("vision", me->name() +"被女郎一脚踢出门外。\n",
                environment(me), ({me}));
       me->move("/d/city/wumiao");
       message("vision", me->name() +"被人踢了出来，栽倒在地上，磕掉两颗门牙。\n", 
                environment(me), ({me}));

    }
    else {
    if (me->query("class") =="bonze") {
       command("say 呦，" + RANK_D->query_respect(me) 
                +"也来光顾我们这啊。");
       command("say 想当年我接过一个少林和尚叫玄觉，他上床前一定要念经，一面念经一面摸。");
    }
    if (me->query("gender")=="女性") {
       command("say 哎呀，这年月大姑娘也逛窑子，成何体同。");
       command("sigh");
       command("say 可惜花痴一点鸿不在，不然让他伺候你。");
    }
	}
    return ;
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 20000)  {
/*		if (who->query_temp("thd_temp") < 2) 
			tell_object(who, "美妞乐了，说道：您老是有钱没处花么？\n");
		else {*/
			write("您想做什么就尽管上吧。\n");
			who->set_temp("bbb/niu_paid",1);
		return 1;
	}
	return 0;
}

int do_ai(string arg)
{
	object me = this_player();

//	if (!me->query_temp("bbb/niu_paid")) return notify_fail("没给钱就想干？！\n");
      message_vision("$N把美妞放倒在地，迫不及待地发起了进攻，两人登时缠绵起来。\n", me);
	return 1;
}

int do_undress(string arg)
{
	object me = this_player();

//	if (!me->query_temp("bbb/niu_paid")) return notify_fail("没给钱就想干？！\n");
        message_vision("$N把美妞的衣服解开，再褪下露背装前胸的部份。露出那天然诱人的曲线。\n" , me);
        return 1; 
}

int do_mo(string arg)
{
	object me = this_player();

//	if (!me->query_temp("bbb/niu_paid")) return notify_fail("没给钱就想干？！\n");
      message_vision("$N的手不安份地由美妞的肩滑过，右手掌进逼那发育良好的山丘。\n", me);
	return 1;
}
