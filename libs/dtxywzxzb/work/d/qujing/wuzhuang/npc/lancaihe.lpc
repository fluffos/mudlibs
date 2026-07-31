// lancaihe.c...weiqi, 98.02.24.
#include <ansi.h>
int fly_sea();
inherit NPC;
void create()
{
	set_name("蓝采和", ({"lan caihe", "lan", "caihe"}));
	//set("title", "");
	set("gender", "男性" );
	set("age", 18);
	set("per", 20);
	set("long", "一位面腆和善的少年。\n");
	set("class", "xian");
	set("combat_exp", 120000);
  set("daoxing", 200000);

	set("attitude", "peaceful");
	create_family("五庄观", 3, "弟子");
	set_skill("unarmed", 60);
	set_skill("wuxing-quan", 60);
	set_skill("dodge", 80);
	set_skill("baguazhen", 80);
	set_skill("parry", 80);
	set_skill("blade", 90);
	set_skill("yange-blade", 100);
	set_skill("force", 70);   
	set_skill("zhenyuan-force", 70);
	set_skill("literate", 80);
	set_skill("spells", 80);
	set_skill("taiyi", 80);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("blade", "yange-blade");
	map_skill("dodge", "baguazhen");

	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);
	set("inquiry",([
    "重游东海": (: fly_sea :),
		]));
	setup();
	carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/obj/weapon/blade/yanblade")->wield();
}

int fly_sea()
{
  string *jnames = ({
    "热酒",
    "清白老酒",
    "清茶",
	"水酒",
    "酥合香油",
    "淡茶",
    "江米酒",
    "老白干",
	"西湖龙井茶",
	"米酒",
	"羊奶酒",
	"泡的已经没有味的茶水",
	"清水",
	"白烧酒",
	"桂花酒",
	"云雾山香茶",
	"碧樨茶",
	"玄火酒",
  });  
   	string jname;
	object me,ob;
    me=this_player();
	ob=this_object();

	  if( me->query_temp("wzg_baxian")!="go" )
		  return 0;
      if (me->query("wzggive/lancaihe"))
    	{
	 		  message_vision(HIB"\n蓝采和问道：我要的"+CYN""+me->query("wzggive/lancaihe")+HIB"可曾拿到了吗？！\n"NOR,me);
			  return 1;
		}
	  if( me->query_temp("wzg/lancaihe")!="give")
	    {
	      jname = jnames[random(sizeof(jnames))];
		  message_vision(HIB"\n蓝采和想了想对$N说道：要是有"+CYN""+jname+HIB"我就去！\n"NOR,me);
		  me->set("wzggive/lancaihe",jname);
		  return 1;
		}
	command("say " + RANK_D->query_respect(me) + "快去叫上其他八仙，我先走一步了！\n");
	ob->move("/d/changan/eastseashore");
    return 1;
}

int accept_object(object who, object ob)
{
	  object me = this_object();

	  if( !who->query("wzggive/lancaihe"))
		  return 0;
	  if ((string)ob->query("liquid/name")!=who->query("wzggive/lancaihe"))
   {
     command ("shake "+who->query("id"));
	call_out ("return_ob",1,who,ob);
    return 1;
  }
  

  message_vision(HIB"\n$N拿着$n乐不释手，喃喃道：一路畅游东海还有$n陪伴一定比闷在这里强．\n"NOR,me,ob);
  who->set_temp("wzg/lancaihe","give");
  who->delete("wzggive/lancaihe");
  return 1;
}



void return_ob (object who, object ob)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="五庄观" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("consider");
			command("say 是你自己要拜的，你师父打上门来我可得拿你挡。\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say 好，那我就勉为其难吧。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}




