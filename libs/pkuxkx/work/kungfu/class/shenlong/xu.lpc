// xu.c
#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("许雪亭", ( { "xu xueting", "xu" }) );
        set("title", MAG"神龙教"HIC"青龙使"NOR);
	set("nickname", HIR "热血神龙" NOR);
	set("gender", "男性" );
	set("age", 55);
	set("long",
	      "这是个五十来岁的高瘦汉子，着一袭青衣，昂然挺立。\n"
	     );

	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	
	set("qi",3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 150);
	set("combat_exp", 500000);
	set("score", 250000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", 60);
        set_skill("hand", 100);
        set_skill("strike", 100);
        set_skill("staff", 100);
        set_skill("yixingbu", 100);
        set_skill("shenlong-bashi", 100);
        set_skill("huagu-mianzhang", 100);
        set_skill("shenlong-xinfa", 100);
        set_skill("shedao-qigong", 100);
 
        map_skill("force", "shenlong-xinfa");
        map_skill("hand", "shenlong-bashi");
        map_skill("strike", "huagu-mianzhang");
        map_skill("dodge", "yixingbu");
        map_skill("staff", "shedao-qigong");
        prepare_skill("hand", "shenlong-bashi");
        prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教",2,"弟子");

	set("inquiry", ([
	    "百花腹蛇膏" : (: ask_gao :),
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao).\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
	]));
		set("chat_chance", 3);
        set("chat_msg", ({
		"许雪亭忽然一怕脑袋，说：对了，可以用百花腹蛇膏！\n",
		"许雪亭怒道：唉，偌大一个神龙教，都毁在一个娘们手里了！\n",
		"许雪亭叹口气，说道：唉，不杀了洪安通，谁也活不了。\n",
        }) );
	set("shen_type",-1);
set("score",500);
setup();
        carry_object("/d/city/obj/duanjian")->wield();
}

int ask_gao()
{
	say(
	"\n许雪亭悄声对你说：这可是本教禁物啊。它一遇鲜血，便生浓香，\n"
	"我们住在这灵蛇岛上，人人都服惯了雄黄酒，以避毒蛇，这股香气\n"
	"一碰到雄黄酒，便使人筋骨酥软，不能动弹。对了，你怎么也知道？\n"
		);
	return 1;
}

/* int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("name") != "腹蛇胆"
		&& (string)ob->query("name") != HIG "百香花" NOR )
		    return notify_fail("许雪亭摇头道：如果杀不了洪安通，给我什么也没用啊。。。\n");
	if ( (string)ob->query("name") == "腹蛇胆" )
		{
		  if(query_temp("baixianghua"))
		  {
		  message_vision("\n许雪亭见是腹蛇胆，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!\n",who);
		  obn=new("/d/shenlong/obj/baihua");
                  obn->move(who);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
 	           return 1;		 
		  } 		
		  else	
		  {	
		  if(query_temp("fushedan"))
                  {
		  message_vision("\n许雪亭见是腹蛇胆，对$N摇头道：腹蛇胆我有了，就差百香花了。\n",who);
			   return 0;
		  }
		  else	  
                  {
		  message("vision","许雪亭看见腹蛇胆，大喜道：有了腹蛇胆，只差百香花了。\n",environment(who));
		  set_temp("fushedan",1);	
	          return 1;
		  }
		}
	}
	if ( (string)ob->query("name") == HIG "百香花" NOR)
		{
		  if(query_temp("fushedan"))
		  {
		  message_vision("\n许雪亭见是百香花，大喜道：腹蛇胆百香花都有了,百花腹蛇膏练成了!\n",who);
		  obn=new("/d/shenlong/obj/baihua");
                  obn->move(who);
		  delete_temp("fushedan");
		  delete_temp("baixianghua");
 	          return 1;		 
		  } 		
		  else	
		  {	
		  if(query_temp("baixianghua"))
                  {
		  message_vision("\n许雪亭见是百香花，对$N摇头道：百香花我有了，就差腹蛇胆了。\n",who);
			   return 0;
		  }
		  else	  
                  {
		  message("vision","许雪亭看见百香花，大喜道：有了百香花，只差腹蛇胆了。\n",environment(who));
		  set_temp("baixianghua",1);	
	          return 1;
		  }
		 }	
	}
}   */

void attempt_apprentice(object ob)
{
	command("say 我不收徒! ");
	return;
}
