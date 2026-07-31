// woodcutter.c

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("老樵夫", ({ "qiao fu" }) );
        set("gender", "男性" );
        set("age", 56);
        set("long", "这是一位满头白发的老樵夫，身上衣着普普通通。\n");

	set("combat_exp", 5000);

	set("str", 30);

	set("inquiry",([
	"紫灵芝" : "岭上就长紫灵芝，不过一般边上都有『毒蜈蚣』，谁也不敢采！\n",
	"灵芝" : "岭上就长紫灵芝，不过一般边上都有『毒蜈蚣』，谁也不敢采！\n",
	"蜈蚣" : (: ask_me :),
	"毒蜈蚣" : (: ask_me :),
]));

	set("chat_chance", 15);
        set("chat_msg", ({
		"老樵夫说道：前面岭上有一只大蜈蚣，真吓人！\n",
		"老樵夫说道：前几天有个砍柴的小伙子被蜈蚣毒死了。\n",
	}) );

        setup();
	carry_object(__DIR__"obj/lumber_axe")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	if(who->query("class") == "shaolin"
	&& who->query("quest/shaolin_quest/name") == "紫灵芝"
	&& !who->query("quest/shaolin_quest/asked"))
	{
		who->add("quest/shaolin_quest/hint",sprintf("\n      %s\n",
			"听说大同府的张霸天家有一种『辟毒珠』专门能克制蜈蚣毒。") );
		who->set("quest/shaolin_quest/asked",1);
	}
	return "那毒蜈蚣的毒可是厉害！！要是被咬了那就算大罗金仙也救不了你。
\t不过听说大同府的张霸天家有一种『辟毒珠』专门能克制蜈蚣毒。";
}