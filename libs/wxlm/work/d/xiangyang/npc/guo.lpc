// guojing.c 郭大侠



inherit NPC;
int ask_rong();
void create()
{
	set_name("郭大侠", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北侠"NOR);
	set("gender", "男性");
	set("age", 41);
	set("long", 
		"他就是人称北侠的郭大侠，既是蒙古成吉思汗的金刀驸马，又是\n"
		"江南七怪、全真派马玄钰道长、「北丐」洪九指和「老顽童」周\n"
		"伯通等人的徒弟，身兼数门武功。\n"
		"他身着一件灰色长袍，体态魁梧，敦厚的面目中透出一股威严\n"
		"令人不由得产生一股钦佩之情。\n");
 	set("attitude", "peaceful");
	
	set("str", 40);
	set("int", 20);
	set("con", 38);
	set("dex", 25);

	set("no_get", 1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"郭大侠叹了口气道：“蒙古兵久攻襄阳不下，一定会再出诡计，蓉儿又不在身边，这....\n",
		"郭大侠说道：“华筝公主近来不知可好，抽空一定要回大漠去看看她。\n",
	}));

	set("inquiry", ([
		"周博通" : "你见到我周大哥了？他现在可好？\n",
		"老顽童" : "周大哥一贯这样，没点正经！\n",
		"洪九指" : "师父除了吃，就是喜欢玩。到处玩，还是为了找吃的。\n",
		"黄岛主" : "那是我泰山大人。他云游四海，神龙见首不见尾的。\n",
		"燃灯大师" : "在下对大师好生感激。\n",
		"欧阳锋" : "这个老毒物，害死我六位师父，一待襄阳事了，决不与他干休。\n",
		"黄帮主"   : "蓉儿是我的爱妻，你问她做甚？\n",
		"郭筱芙"   : "这个女儿，又笨又不听话。\n",
		"郭筱襄"   : "襄儿生于乱世，这辈子又多艰厄。但愿她能快乐一世。\n",
		"郭灭虏" : "那是我的小儿子。\n",
		"杨改之"   : "过儿确实有出息。\n",
		"马玄钰"   : "马道长于我有半师之谊。\n",
		"丘玄机" : "邱道长义薄云天，是真豪杰。\n",
		"柯震恶" : "那是我大师父。\n",
		"朱骢"   : "那是我二师父。\n",
		"韩天驹" : "那是我三师父。\n",
		"南溪仁" : "那是我四师父。\n",
		"张阿笙" : "那是我五师父。\n",
		"全金髦" : "那是我六师父。\n",
		"韩筱莹" : "那是我七师父。\n",
		"丐帮"   : "丐帮英雄几百年了，守卫襄阳多亏了他们。\n",
		"拜师"   : "现在蒙古人围攻襄阳，我哪有心情收徒啊！\n",
	]));

	set("qi", 5200);
	set("max_qi", 5200);
	set("jing", 2600);
	set("max_jing", 2600);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 100);
	
	set("combat_exp", 2100000);
	set("score", 200000);
	 
	set_skill("force", 240);		// 基本内功
	set_skill("huntian-qigong", 240);	// 混天气功
	set_skill("strike", 260);		// 基本拳脚
	set_skill("dragon-strike", 260);	// 镇岳锁龙劲
	set_skill("dodge", 200);		// 基本躲闪
	set_skill("jinyan-gong", 200);		// 金雁功
	set_skill("parry", 260);		// 基本招架
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "dragon-strike");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "dragon-strike");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
int ask_rong()
{
    object ob;
    ob = this_player();
    if (ob->query_int()>=30)
    {
	ob->set_temp("marks/蓉儿",1);
	command("say " + ob->query("name") + "，你帮我带个口信去桃花岛吧！\n");
    }
    else
    {
	command("say " + ob->query("name") + "，你打听这干嘛？\n");
    }
    return 1;
}
