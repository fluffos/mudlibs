// d/fuzhou/chaboshi.c 茶博士
// Lklv 2001.9.25

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("茶博士", ({ "cha boshi", "boshi" }));
	set("title", "茶馆老板");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 47);
	set("long",
		"他看起来脸色红润，面色和蔼。\n");
	set("combat_exp", 100000+random(50000));
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 5);
        set("chat_msg", ({
                "茶博士对你点了点头，微微地笑了笑。\n",
        }) );
	set("inquiry", ([
		"襄阳" : "襄阳城里就属我们这家茶楼最大，地处交通要道，生意真是不错。\n",
		"郭靖" : "他以前经常和黄女侠来我这里喝茶。。\n",
		"茶" : "我们这儿的茶叶是从福建运来的，全都是茶中极品，您该多尝一些。\n",
		"猪肉荣" : "这个小子，我前几天还在赌场见过他……\n",
		"李二嫂" : "这娘们，年轻的时候可真迷死不少小伙子。\n",
		"官兵" : "嘘……不要说这个，小心拿你当蒙古间谍抓了去。\n",
		"here" : "这里是襄阳有名的城北茶楼，门前是北街，出门右拐再左拐有个擂台。\n",
		"rumors" : "听说最近城里来了不少北方口音的汉子，看起来都是江湖上混的。\n",
		"rumor" : "您想让我帮你造谣？我哪有那闲工夫啊，我看您还是歇会吧。\n",
		"job" : "您可找错人了吧？？\n",
		"cha boshi" : "茶博士就是我啊。\n",
		"laoban" : "这里的老板就是我。\n",
		"喝茶" : "您想喝茶我帮倒，记得交钱就行了，白开水随便喝。\n",
		"茶叶" : "嘿……您是要买茶叶还是要添茶？我们的茶叶不好嘛？\n",
		"tea" : "你以为说洋文我就不懂啦，不就是茶嘛，你这个假洋鬼子！\n",
		"茶楼" : "这个茶楼是我祖辈留下来的，邻居们经常来喝茶。\n",
		"武当" : "出北门，一直走，然后往西边的岔路，过汉水……\n",
		"少林" : "出北门，一直走，然后走东北方向奔南阳，然后……\n",
		"华山" : "说起华山，去年我在华山村遇见一位铁匠，他价钱公道，童叟无欺……\n",
		"name" : "在下姓白名摸，不过大家都习惯叫我茶博士。\n",
		"白摸" : "啊？找我啊，你有话就说嘛，你不说我怎么知道呢。\n",
	]));

	set("vendor_goods", ({
		(["name":FOOD_D("peanut"),"number":10]),
		(["name":FOOD_D("tea"),"number":20]),
	}));

	setup();
	add_money("silver", 20+random(10));
        carry_object(ARMOR_D("changshan2"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
        say("茶博士笑眯眯地说道：来来来，这位" + RANK_D->query_respect(ob) +
                        "，来喝杯茶。\n");
                break;
        case 1 :
        say("茶博士说道：哟！这位" + RANK_D->query_respect(ob) +
                        "您来了啊！里边请！里边请！\n");
                break;
        }
}
