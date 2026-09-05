// caopan.c  by hubo

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("操盘手", ({ "shou","caopan shou"}) );
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"他是著名的赌球操盘手，场次赔率都是他定的，据说\n"
    "和欧洲赌博公司有很大瓜葛\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
	set("shen_type",1);set("score",200);setup();
}

void init()
{
	 object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

                add_action("do_paicai","paicai"); 
}
int do_paicai(string arg)
{
          object me;
          me = this_player();
          write("现在赌局正在进行中，还没有进行派彩，别着急，耐心等等！\n");
          return 1;               
}
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        if( !this_object()->visible(ob)) return;
        switch(random(2))
        {
        case 0 :
                say("操盘手笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
                        "，来看看哪场比赛适合您，押点玩玩。规则请看help duqiu。\n");
                break;
        case 1 :
                say("操盘手说道：这位" + RANK_D->query_respect(ob) + 
                        "欢迎您，有不懂的事情请查help duqiu。\n");
                break;
        }
}


