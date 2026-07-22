inherit NPC;
string *first_name = ({
"赵","钱","孙","李","周","吴","郑","王","张","陈", "刘","林" }); 
string *name_words = ({
"顺","昌","振","发","财","俊","彦","良","志","忠", "孝","雄","益","添","金",
"辉","长","盛","胜","进","安","福","同","满", "富","万","龙","隆","祥","栋","国","亿","寿","杨" });


void create()
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))]; 
	if( random(10) > 4 ) 
	name += name_words[random(sizeof(name_words))];
	set_name(name, ({"bang zhong", "bang", "zhong"}) );
	set("title", "长乐帮帮众");
	set("long", "这是一个惯于为非作歹的长乐帮众。他眼珠乱转，似乎正在想什么坏主意。\n");
	set("gender", "男性" );
	set("age", 16+random(20));
	set("attitude", "peaceful");
	set("str",15+random(13));
	set("int",20);
	set("con",15+random(12));
	set("dex",15+random(10));
	set("max_qi", 300+random(200));
	set("max_jing", 200)+random(200);
	set("neili", 250+random(200));
	set("max_neili", 250+random(200));
	set("combat_exp", random(10000)+50000);

	set_skill("force", 25+random(15));
	set_skill("shenzhao-jing", 30);
	set_skill("dodge", 25+random(15));
	set_skill("piaoyi-shenfa", 30);
	set_skill("hand", 25+random(15));
	set_skill("yingzhua-shou", 30);
	set_skill("parry", 25+random(15));
	set_skill("jinwu-daofa", 40);
	set_skill("blade", 40);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "piaoyi-shenfa");
	map_skill("parry", "yingzhua-shou");
	map_skill("hand", "yingzhua-shou");
	map_skill("blade", "jinwu-daofa");
	prepare_skill("hand", "yingzhua-shou");

	setup();
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}
