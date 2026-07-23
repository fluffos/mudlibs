// master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(YEL"钟灵"NOR, ({ "zhongling", "girl", "dizi" }) );
	set("title", YEL"小师妹"NOR);
	set("gender", "女性" );
	set("age", 15);
	set("str", 27);
	set("dex", 30);
	set("dex", 27);
	set("int", 24);
        
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set_skill("unarmed", 320);
	set_skill("parry", 320);
	set_skill("dodge", 320);
	set_skill("sword", 320);
	set_skill("force", 320);
	set_skill("literate", 320);	
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	
	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 3);

	set("long",
		"她是梵音师太最小的一个弟子.此刻她手中把玩着一根桃树枝.
好奇地看着你.\n");
       set("combat_exp", 500000);
	set("score", 2000);
create_family("白云庵", 4, "传人");
        set("chat_chance", 10);
        set("chat_msg", ({
        "钟灵笑嘻嘻地唱道:阿里,阿里巴巴...... ......。\n",
        "钟灵随意把玩着手中的桃树枝,嘴里不知在哼些什么。\n",
        "钟灵从石壁上采了个果子,慢慢吃起来。\n",

"钟灵喃喃自语:为什么是芝麻开门,而不是葡萄,梅子,桃子,冰梨,佛手... ....。\n",
        "钟灵一边不停地数着各种水果,一边伸出舌头添了添快流出来的口水。\n",

"钟灵对你说道:你知不知道天下有名的兵刃有哪些?\n",
        "钟灵自语道:不知道那把宝刀到底怎么样。\n",
        "钟灵看着你好奇道:为什么每天都有人从上面跳下来,真的好玩么?\n",
        "钟灵侧耳听了听外面的声音。\n",
        "钟灵双手过头,伸了个懒腰:累死了。\n",
        "师傅为什么不准我们到瀑布下玩呢?\n",
        }));






	set("inquiry", ([
		"out" : "听说啊,在很远的地方,有个叫阿里巴巴的人,他找到了一个宝库..... ...。",
		"瀑布" : "师傅不准我们随便到那去,也不知道为什么。",
		"宝刀" : "听说师傅年轻的时候,在附近的海域中得到过一把宝刀。",
		"name": "我的名字不能随便告诉别人,嘻嘻!",
		"here": "这是我无意中发现的一个小山洞,你可别跟别人说。",
	]) );

	setup();
	carry_object("/d/hainan/obj/taoshuzhi")->wield();
	carry_object("/d/hainan/obj/shaqun")->wear();
       carry_object("/d/hainan/obj/flowershoe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("age") > 20) 
	{	command("say 我自己还没出师呢,这位" + RANK_D->query_respect(ob) + ",还是请你另找高明吧!");
		return;
	}
	command("say 嘻嘻，这位" + RANK_D->query_respect(ob) + "你可不要后悔吆。\n");
	command("recruit " + ob->query("id") );
        command("say 下次要找我,只要在外面的小洞天说[芝麻开门]就行.\n");	
}


