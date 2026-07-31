// oldman.c

inherit NPC;

string ask_baobei();

void create()
{
        set_name("肖老头", ({"xiao laotou", "laotou" ,"xiao","oldman","man"}) );
        set("gender", "男性" );
        set("age", 65);
        set("long", "他脸色黑黄，满脸都是皱纹，一副饱经风霜的样子。\n");

        set_skill("unarmed", 50);
        set_skill("dodge", 30);
        set_skill("parry", 40);
        set("combat_exp", 2300);
	set("shen_type", 0);
        set("str", 20);
        set("dex", 15);
        set("con", 20);
        set("int", 20);
        set("attitude","friendly");
	set("unique", 1);

        set("inquiry", ([
                "向导" : "“老了，腿脚不中用了，你找别人吧。”\n",
                "绝顶" : "你说的是雪山绝顶？那是天神住的地方，千万不要去，天神一生气，你小命就没了。\n",
                "雪山绝顶" : "据说上面有天神的宝贝，山脚下那些骸骨，多半都是去寻宝的。\n",
                "宝贝" : (: ask_baobei :),
        ]));
        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
		"肖老头摇头晃脑的拉着胡琴，显得怡然自得。\n",
                "肖老头用沙哑低沉的声音唱了起来：“如果你要嫁人，不要嫁给别人~~~”\n",
        }) );
 carry_object("/clone/misc/cloth")->wear();
//        carry_object(ARMOR_D("pipao"))->wear();
//        carry_object(BINGQI_D("huqin"))->wield();
}

 string ask_baobei()
{
	object me=this_player();
        me->set_temp("baobei_ask",1); 
        return  "这位"+RANK_D->query_respect(me)+"也想去寻宝么？唔......这样吧，你我今日遇到也算有缘，我送你两件登山工具，你去向王三力要就行了。\n不过话说回来，出了什么事可别找我。\n" ;
}