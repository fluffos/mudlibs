// duangirl.c

inherit NPC;

void create()
{
	set_name("雪儿", ({ "girl" }) );
	set("title", "孙大娘的女儿");
	set("gender", "女性" );
	set("age", 18);
	set("str", 12);
	set("per", 30);
	set("long", @LONG
她是孙大娘的女儿，颇有孙大娘年轻时的美貌，而且
身才也是一流。这里的不少富家子弟都在追求她。
LONG
);
	set("combat_exp", 500);
       set("chat_chance", 1);
	set("chat_msg", ({
		"雪儿对着你婉嫣一笑。\n",
		"雪儿偷偷的向门口看了一眼。\n",
	}));

	set_skill("literate", 40);

	set("inquiry", ([
		"name" : "我就是孙雪儿。",
		"here": "这是裁缝店呀,你是来做衣服吗？",
		"过夜": "你......怎么能这么说话？",
		"孙大娘": "她是我的妈妈。",
	]) );

	setup();
	
	carry_object(__DIR__"obj/pink_cloth")->wear();
}


