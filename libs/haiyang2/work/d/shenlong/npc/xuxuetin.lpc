// xuxuetin.c
#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("许雪亭", ( { "xu xueting", "xu" }) );
	set("title", "神龙教青龙使");
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
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
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
	set_skill("unarmed", 90);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taoism", 150);
	set_skill("literate", 60);
	set_skill("tiyunzong", 80);
	set_skill("taiji-quan", 80);
	set_skill("taiji-shengong", 80);
	set_skill("taiji-jian", 90);
	set_skill("shedao-qigong", 100);
	set_skill("shenlong-xinfa", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");



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
"许雪亭怒道：唉，偌大一个神龙教，都毁在一个娘么手里了！\n",
"许雪亭叹口气，说道：唉，不杀了洪安通，谁也活不了。\n",
        }) );
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

int accept_object(object who, object ob)
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
                  call_out("destroying", 1, this_object(), ob);  
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
                  call_out("destroying", 1, this_object(), ob);  	
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
                  call_out("destroying", 1, this_object(), ob);   		  
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
                  call_out("destroying", 1, this_object(), ob);	          
	          return 1;
		  }
		 }	
	}
}

int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
	return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("shenlongjiao")) 
	{
	message_vision(HIC "许雪亭说道：你已经是神龙教弟子了。\n" NOR,this_player());
	return 1;
	}
   if ((int)ob->query("shen")>-1000)
        {
	message_vision(HIC "许雪亭对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "许雪亭对$N摇头道：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
  if ( ob->query_skill("bibo-shengong",1)
	|| ob->query_skill("hamagong",1)
	|| ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" 你现在就是神龙教弟子了.\n");
    return 1;	
   }
   else 
   {
   message_vision(HIC "许雪亭对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
	set_leader(this_player());
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, this_player()); 
  	return 1;
	}
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("shenlong-xinfa",1) < 40 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 40 ) {
        command("say 你的本门杖法太低了,还是努努力先提高一下吧!");
		return;
    }
    if ((int)ob->query("shen") > -5000  ) {
        command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
}
 
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}