#include <ansi.h>
inherit NPC;
string ask_me();
string ask_wan();
string ask_ji();
string ask_mudi();
string ask_lyz();
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
  set("per",30);
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
	set_skill("literate",340);
  set_skill("disguise",350);
  set_skill("anti-disguise",250);
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
	set("inquiry",([
	        "软猬甲":	(: ask_me :),
	        "叫化鸡":	(: ask_ji :),
                "落英神剑掌":     (: ask_lyz :),
          "墓地":   (: ask_mudi :),
	        "黄药师" : "你问我爹？他就在桃花岛上啊。",
	        "郭靖" : "靖哥哥，你看这人，嘻嘻。",       
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
        object me = this_player();
        if( !(fam = me->query("family")) || fam["family_name"] != "桃花岛" )
		return RANK_D->query_respect(this_player())+"你与我派素无往来,又从何谈起我派之宝呢?\n";
	if(me->query("score") < 800)
		return "爹爹给我的软猬甲怎能如此随意就给了你？你还是先为本派做些贡献吧。\n";
	if( query_temp("jia_count")<1 )
		return ("软猬甲已经交给你的"+(random(2)?("师兄"):("师姐"))+"了，你找他要吧。");
	add_temp("jia_count", -1);
	ob=new(__DIR__"obj/ruanwei-jia");
	ob->move(me);
        message_vision(WHT"黄蓉走到内室，脱下"YEL"软猬甲"WHT"，交给了$N"WHT"。\n"NOR, me);
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
string ask_mudi()
{
	mapping fam;
	object ob;
	if(!(fam=this_player()->query("family"))||fam["family_name"]!="桃花岛")
        return "你与我派素无往来,又从何谈起我派之宝呢?\n";
	else
	this_player()->set_temp("marks/墓",1);
        return "我娘就在里面，但爹爹从不让我进去。\n";
}
string ask_lyz()
{
        mapping fam;
        if(!(fam=this_player()->query("family")) || fam["family_name"]!="桃花岛")
                        return "你与我派素无往来,问这干啥？\n";
                        
        if(this_player()->query("thd/lyz") == 1){
                        this_player()->set("thd/lyz", 2);
                        return "你要学打蜡烛的功夫？不过我要陪靖哥哥。。。。你去找个铁八卦自己练吧。\n";
        }
        return "我自己功夫太差，教不了你落英神剑掌。\n";
}

int recognize_apprentice(object ob)
{
//      if (ob->query("family/family_name")=="桃花岛")
//      	return notify_fail("我爹的学识远胜于我，你还是去请教他吧。\n");
      if ( ob->query("family/family_name")!="桃花岛" &&
      	   ob->query("family/family_name")!="丐帮" )
        return notify_fail("我和你并不熟识，请教二字从何讲起。\n");
      return 1;
}
		
int prevent_learn(object me, string skill)
{
	if ( me->query("family/family_name")!="桃花岛" &&
		   me->query("family/family_name")!="丐帮" )
	  return 1;

	if( skill=="anti-disguise" ) 
	{
	  if ( me->query("score")<=3000 )
	  {
	  	tell_object(me, "你没有做出足够的贡献无法学习火眼金睛术。\n");
	  	return 1;
	  }
	  else if ( me->query("betrayer") ||
	  	me->query("chushi/done") )
	  {
	  	tell_object(me, "火眼金睛术只有忠心于" + me->query("family/family_name") + "的才能传授。\n");
	  	return 1;
	  }
	  
	  tell_object(me, "黄蓉想起你以往对师门做出的贡献，决定传授你一点火眼金睛术的心得。\n");
	  if ( random(2) )
	    me->add("score", -(1+random(2)) );
	  return 0;
	}
	else if( skill=="disguise" ) 
	{
	  if ( me->query("score")<=3000 )
	  {
	  	tell_object(me, "你没有做出足够的贡献无法学习易容术。\n");
	  	return 1;
	  }
	  else if ( me->query("betrayer") ||
	  	me->query("chushi/done") )
	  {
	  	tell_object(me, "易容术只有忠心于" + me->query("family/family_name") + "的才能传授。\n");
	  	return 1;
	  }
	  else if ( me->query_skill("anti-disguise", 1)<250 )
	  {
	  	tell_object(me, "想学易容术必须先学习足够的火眼金睛术才行。\n");
	  	return 1;
	  }
	  
	  tell_object(me, "黄蓉想起你以往对师门做出的贡献，决定传授你一点易容术的心得。\n");
	  if ( random(50) )
	    me->add("score", -(2+random(2)) );
	  return 0;
	}
  else if (skill != "literate") 
  {
          command("heng");
          command("say 对不起，我只能教授你读书写字。");
          return 1;
  }
  
  return 0;
}
