

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
#include <ansi.h>
void create()
{
	set_name("婆子", ({ "pozi", "po" }));
	set("shen_type", -1);

	set("per", 1);
	set("gender", "女性");
	set("age", 25);
	set("long",
		"妓院的鸨母，年纪显然很大了，面上的脂粉多的可以做馒头了\n"
		);
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("鸨母堆起一脸的皱纹笑道：这位" + RANK_D->query_respect(ob) +
			"，快请进来玩玩吧。\n");
		break;
	case 1 :
		say("鸨母说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！今天刚来的雏，要不要啊？\n");
		break;
	}
}


int accept_object(object who, object ob)
{
  
           if(ob->value()>=500000&&ob->query("money_id")) 
   {
              remove_call_out("destroying");
              call_out("destroying", 1, this_object(), ob);       
              who->set_temp("gold_given",1);
              say("鸨母高兴的说道：这位"+RANK_D->query_respect(who)+"出手真是阔绰，快快，楼上请!\n");
              who->set_temp("can_fuck",1);
              if(who->query("gender")=="男性") 
               {  
                 who->move("/d/pker/room1");
                 message("vision",YEL"还没明白怎么回事，鸨母连推带拉的把你送上了消魂屋\n"NOR,who);
                 return 1;
                }
               message("vision","鸨母叹了口气：如今这世道。。。什么人都来妓院。。\n",who);
               command("sigh");
               return 0;
   }
           else
            {
              say("你发情了是吧，拿钱来啊!\n");
              return 0;
            }
}            