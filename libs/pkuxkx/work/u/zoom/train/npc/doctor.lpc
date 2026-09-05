//Cracked by Roath
// doctor.c 医者
// Ssy

#include <ansi.h>
inherit NPC;

void greeting(object);

void create()
{
	set_name("医者", ({ "doctor", "yizhe"}));
	set("long", 
	    "一位白发银须的老者。据说当年曾经是江湖上一位著名的神医。\n"
            "他看起来懒洋洋的，你要是想请他疗伤的话恐怕不那么容易。\n");
	set("gender", "男性");
	set("age", 74);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("race", "人类");	
	set("max_qi", 150);
	set("eff_qi", 150);
	set("qi", 150);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);
	set("max_neili", 150);
	set("eff_neili", 150);
	set("neili", 150);
	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 1000);

	set_skill("force", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("cuff", 5);
	set_skill("sword", 5);
	
	set("inquiry", ([
			"疗伤"   : 	"去后院帮我摘几个银杏来吧。\n",
			"heal"   :      "去后院帮我摘几个银杏来吧。\n",
		]));

	setup();
//        carry_object("/d/wudang/obj/greyrobe")->wear();

}

void init()
{
        object me = this_player();        

        ::init();
        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
        int wound = (me->query("eff_qi")*100)/(me->query("max_qi"));
	if (wound < 20)
	  {
	    command("walkby " + me->query("id"));
	    command("say " + RANK_D->query_respect(me) + "怎么伤得这样厉害？\n");
	  }
	else if (wound < 100)
	  {
	    command("sigh");
	    command("say " + RANK_D->query_respect(me) +
"又受伤啦？没关系，练武嘛，不吃点苦头怎么能成大器呢？");
	  }
	else
	  {
	    command("hehehe " + me->query("id"));
	    command("say 
         练武功之人，难免受伤。如果学了高级内功，就可以用内力来自己治疗。
在没伤上限时可以用yun regenerate来补精，用yun recover来补气。如果伤了上限，
所学内功中有heal，lifeheal的话，就可以自己疗伤:  yun heal or yun lifeheal。
否则只能求助于他人，或者用药品来补充，当然只要食物和饮水不为零， 是能自动
补充的，但是速度是特别慢的，精可以吃养精丹，气可以吃金疮药。");
	command("say 如果想让我帮你疗伤就打"+HBRED+HIW"(ask doctor about heal)"NOR+"。");
	  }
}

int accept_obj(object me, object obj)
{
        object ke;
        if( obj->query("name")=="银杏") 
	  {
	     command("thumb "+ me->query("id"));
	     command("say " + RANK_D->query_respect(me) +
"这是什么东西？好罢，看你挺可怜的，我给你看看伤……\n");
	     message_vision("$N取了些药品，又拿来许多绷带夹板等物，给$n利落地包扎了一下，果然是妙手回春！\n", this_object(), me);
	     message_vision("$N笑道：你这点小伤，在我看来算不了甚么。\n", this_object(), me);
	     me->set("eff_qi", me->query("max_qi"));
	     return 1;
	  }
	else 
	  {
             command("? "+ me->query("id"));
	     return 0;
	  }
}
 
