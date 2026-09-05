#include <ansi.h>
inherit NPC;
string ask_me();
string ask_wan();
string ask_ji();
int ask_mudi();
void create()
{
	set_name("黄蓉",({"huang rong","huang","rong"}));
	set("nickname",GRN"桃花"NOR+YEL"仙子"NOR);
	set("title",HIC"郭夫人"NOR);
	set("long","她是一位美若天仙的女子,眉清目秀,笑容可掬.\n");
	set("gender","女性");
	set("age",32);
	set("shen_type",1);
	set("str",24);
	set("int",32);
	set("con",24);
	set("dex",24);
	set("max_qi",3000);
	set("max_jing",3000);
	set("neili",1800);
	set("max_neili",1800);
	set("jiali",100);
	set("combat_exp",1500000);
	set_skill("force",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("finger",150);	
	set_skill("staff",150);
	set_skill("bihai-shengong",150);
	set_skill("luoying-shenfa",150);
	set_skill("dagou-bang",150);
	set_skill("tanzhi-shengong",90);
	map_skill("dodge","luoying-shenfa");
	map_skill("staff","dagou-bang");
	map_skill("force","bihai-shengong");
	map_skill("finger","tanzhi-shengong");
      set_temp("jia_count",1);
	prepare_skill("finger","tanzhi-shengong");
	set("chat_chance_combat",100);
	set("inquiry",(["软猬甲":
	(: ask_me :),
	"叫化鸡":
	(: ask_ji :),
	"黄药师":"你问我爹啊,他就在桃红岛的大厅!",
	"郭靖":"他就在这儿啊!",
        
	"郭襄":"她是我女儿啊,她是个精灵，整天跑来跑去的,我这些天来很少见她.\n",
	"洪七公":"他是我师傅呀,他老人家是丐帮帮主,你找他有事吗?\n",
	]));
	setup();
	set("chat_chance",5);
	set("chat_msg",({"黄蓉笑道:我身上这件[软猬甲]可是天下第一的防御武器啊.\n",
	"黄蓉扭转身去与郭靖耳语道:靖哥哥.......\n",
	"黄蓉叹了口气,说道:洪七师傅把打狗棒传给我，让我以此来统领丐帮.\n",
	"黄蓉轻声说道:洪七师傅最爱吃我做的叫化鸡了，可惜我好久没见到他老人家啦...\n",
	"我那个丫头[郭襄]又不知道跑哪儿去了,真是个[鬼精灵].\n",}));
	carry_object("/d/city/obj/cloth")->wear();
	
}
string ask_me()
{
	mapping fam;
	object ob;
    int sc;
	if(!(fam=this_player()->query("family"))||fam["family_name"]!="桃花岛")
	return RANK_D->query_respect(this_player())+"你与我派素无往来,又从何谈起我派之宝呢?\n";
      if ( sc = this_player()->query("score") < 800 )
          return "这个镇派之宝怎么能随便给人呢？你还是先为本派做点什么吧。\n";
    if( query_temp("jia_count")<1 )
	return"你来晚了,真是可惜啊!";
    add_temp("jia_count",-1);
	ob=new(__DIR__"obj/ruanwei-jia");
	ob->move(this_player());
	return"这件东西可不能乱给人啊!";
}
string ask_ji()
{
	mapping fam;
	object ob;
    int sc;
	if(!(fam=this_player()->query("family"))||fam["family_name"]!="桃花岛")
	return RANK_D->query_respect(this_player())+"你与我派素无往来,我凭什么为你下厨呢?\n";
      if ( sc = this_player()->query("score") < 400 )
          return "这叫化鸡可是我的拿手好菜。你初来乍到，还是等些时日吧。\n";
        if (query_temp("ji_count") > 0)
                return "我身子有些疲惫，不能下厨了。";
        add_temp("ji_count", 1);
	ob=new("/kungfu/class/gaibang/jiaohuaji");
	ob->move(this_player());
	message_vision("\n黄蓉转身走进厨房，片刻间飘然而回，手里捧着盘热腾腾的叫化鸡递给$N。\n\n", this_player());

	return "你为本派出了这许多力，这叫化鸡算犒劳你的吧！";
}
string ask_wan()
{
	mapping fam;
	object ob;
	if(!(fam=this_player()->query("family"))||fam["family_name"]!="桃花岛")
	return RANK_D->query_respect(this_player())+"你与我派素无往来,又从何谈起我派之宝呢?\n";
	if(query("book_count")<1)
	return"你来晚了,真是可惜啊!";
	add("book_count",-1);
	ob=new(__DIR__"obj/dilong-wan");
	ob->move(this_player());
	return"你拿去吧，不过要好好保管，不到中毒时不要用它。\n";
}
int ask_mudi()
{
	mapping fam;
	object ob;
	if(!(fam=this_player()->query("family"))||fam["family_name"]!="桃花岛")
	return notify_fail("你与我派素无往来,又从何谈起我派之宝呢?\n");
	else
	{
	write("我娘就在里面，但爹爹从不让我进去。\n");
	this_player()->set_temp("marks/墓",1);
	}
}
		
