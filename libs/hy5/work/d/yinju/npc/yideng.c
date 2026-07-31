// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("一灯大师", ({"yideng dashi", "dashi", "yideng"}));
	set("nickname", HIG "天南一帝" NOR );
    set("gender", "男性");
    set("age", 52);
	set("long", 
		"他就是号称「南帝」的一灯大师，俗名段智兴，现已逊位为僧。\n"
		"他身穿粗布僧袍，两道长长的白眉从眼角垂了下来，面目慈祥，\n"
		"长须垂肩，眉间虽隐含愁苦，但一番雍容高华的神色，却是一\n"
		"望而知。大师一生行善，积德无穷。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 61);
    set("int", 60);
    set("con", 66);
    set("dex", 60);

    set("qi", 33000);
    set("max_qi", 33000);
    set("jing", 35000);
    set("max_jing", 33000);
    set("neili", 60500);
    set("max_neili", 60500);
    set("jiali", 100);
	
    set("combat_exp", 9500000);
    set("score", 0);
	 
        set_skill("unarmed", 250);
        set_skill("force", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("cuff", 250);
        set_skill("strike", 250);
        set_skill("sword", 250);
        set_skill("staff", 250);
        set_skill("finger", 380);
        set_skill("buddhism", 500);
	set_skill("kurong-changong", 380);
        set_skill("tiannan-step", 380);
        set_skill("jinyu-quan", 380);
        set_skill("wuluo-zhang", 380);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 380);
        set_skill("feifeng-whip", 380);
        set_skill("sun-finger", 380);
	set_skill("six-finger", 380);
	set_skill("sun-finger", 380);
	set_skill("literate", 320);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("unarmed", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");
if (random(2)==0)
{
	map_skill("finger", "six-finger");
	prepare_skill("finger", "six-finger");
}
//	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.sandie" :),
                (: perform_action, "unarmed.dian" :),
                (: perform_action, "unarmed.jian" :),
                (: perform_action, "unarmed.qian" :),
                	 (: perform_action, "unarmed.dragon" :),

                (: perform_action, "finger.liumaijingshen" :),
                (: perform_action, "finger.qi" :),
                (: perform_action, "finger.zong" :),
                (: perform_action, "finger.zongheng" :),
                	
                  (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);

    create_family("大理段家", 16, "弟子");
    setup();

    carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{       
        string oldtitle;
	oldtitle = ob->query("title");
        if (!oldtitle) return;

        if( ob->query("family/family_name") != "大理段家")
           {
		command("say 老衲已经出世，不再涉足江湖俗务，不能收徒了。\n");
                      return;
            }

	if (strsrch(oldtitle, "大理镇南王府武将")< 0)
  	{
   	if (strsrch(oldtitle, "大理镇南王府家奴")< 0)
        {
		command("shake "+this_player()->query("id"));
		command("say 老衲已经出世，不再涉足江湖俗务，不能收徒了。\n");
		return;
	}
	}
       if ((int)ob->query("shen") < 10000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
          if (ob->query_temp("give_bunan") != 1)
       {
                command("sigh "+this_player()->query("id"));
		command("say 老衲虽然已经出世，"+ RANK_D->query_respect(ob) +
            "是否能帮老衲看看英姑现在近况如何。\n");
		return;
       }
        command("chat 想不到老衲在垂死之年，又觅得一个可塑之才，既已入府，便当尽忠报主。");
	command("recruit " + ob->query("id"));
        ob->set("title","大理镇南王府皇卿");

	
}
int accept_object(object who, object ob)
{
                object nvxu;
        object obj;
        object fang;
        int i;
    int payed;


if (!who->query_temp("give_wawa")){
      command("say 你过我渔隐徒儿的考验了吗?..唉...");
      return 0;
   }

if (!who->query_temp("book571")){
      command("say 你过我樵夫徒儿的考验了吗?..唉...");
      return 0;
   }


if (!who->query_temp("du_allow")){
      command("say 你过我书生徒儿的考验了吗?..唉...");
      return 0;
   }

if (!who->query_temp("help_nongfu")){
      command("say 你过我农夫徒儿的考验了吗?..唉...");
      return 0;
   }




	
   if (ob->query("id")=="bu nan")
   {
   	
                if ((int)who->query("jinyong/book5")==6 && !query("iskillok"))
        {
      	fang = load_object(__DIR__"yinggu");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
        command("say 英姑 你终究还是来了。");
return 0;
}

if ((int)who->query("jinyong/book5")==6 && !who->query_temp("book572")){
      command("say 英姑还是想不通..唉...");
      return 0;
   }
if ((int)who->query("jinyong/book5")==6){   	

                        		i = 900+random(2000);
		who->set("jinyong/book5",7);
		who->add("combat_exp",i+16000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		
		tell_object (who,"你赢得了"+chinese_number(i+16000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		write("一灯说道：听说铁掌帮在与金人勾结，去看看吧。\n");
		who->save();
      return 1;
   }


   	
      who->set_temp("give_bunan",1);
      command("say 英姑，原来你还想不通...唉...");
      return 1;
   }
else
	message_vision("一灯皱眉对$N说：施主请回吧。\n", who);
        return 0;
}

    
 

