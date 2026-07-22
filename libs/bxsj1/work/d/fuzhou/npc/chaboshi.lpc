// d/fuzhou/chaboshi.c 茶博士
// Lklv 2001.9.8

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
	set("inquiry", ([
		"林家" : "他们家的镖局生意不错，局里的镖师、趟子手经常来我这里喝茶。\n",
		"福州" : "福州哪里都好，就是不要去城东，那里的化子很凶。\n",
		"茶" : "我们福建的茶叶是茶中上品，您该多尝一些才是。\n",
		"辟邪剑法" : "这个……这个我可不知道。\n",
		"林平之" : "这孩子年轻气盛，爱打抱不平。\n",
		"林镇南" : "林老镖头最近可是很少来了，好象他家里有什么事。\n",
		"here" : "这里是福州有名的城西茶楼，门前的巷子就是城西巷，出巷右拐就到城中心了。\n",
		"rumors" : "听说最近城里来了不少北方口音的汉子，看起来都是江湖上混的。\n",
		"rumor" : "您想让我帮你造谣？我哪有那闲工夫啊，我看您还是歇会吧。\n",
		"job" : "您可找错人了吧？？\n",
		"cha boshi" : "茶博士就是我啊。\n",
		"laoban" : "这里的老板就是我。\n",
		"喝茶" : "您想喝茶我帮倒，记得交钱就行了，白开水随便喝。\n",
		"林老镖头" : "提起林老镖头，在这城可以说是无人不知无人不晓。\n",
		"镖局" : "出门往左拐，再往右拐两次，就到了。\n",
		"杂货铺" : "你是说原来在这隔壁的杂货铺啊，搬家了，搬到了巷子北边。\n",
		"茶楼" : "这个茶楼是我祖辈留下来的，邻居们经常来喝茶。\n",
		"佛山" : "出南门，一直走，然后往西边的岔路。\n",
		"茶叶" : "对不起，小店不卖茶叶，您要喝，还是在这里喝吧。\n",
		"少镖头" : "平之这孩子年轻气盛，爱打抱不平。\n",
		"福威镖局" : "林家传了三代的镖局，在福建一带名头一直很响的。\n",
		"name" : "在下姓费名进，不过大家都习惯叫我茶博士，我们家可是这里的老户。\n",
		"..." : "你有话就痛快说嘛\n",

	]));

	set("vendor_goods", ({
		(["name":FOOD_D("peanut"),"number":10]),
		(["name":FOOD_D("tea"),"number":20]),
	}));

	setup();
	add_money("silver", 20+random(10));
        carry_object(ARMOR_D("cloth"))->wear();
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
                        "您来了啊！好久不见，最近怎么不过来喝茶了？\n");
                break;
        }
}
