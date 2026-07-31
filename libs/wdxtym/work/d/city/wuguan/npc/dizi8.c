 //dizi8.c 沈城 by river

#include <ansi.h>
inherit NPC;
int ask_xuexi3();

void create()
{
	set_name("沈城", ({ "shen cheng","shen","cheng", "man" }));
	set("title", "襄阳武馆八弟子");
	set("gender", "男性");
	set("age", 21);        
	set("long", "他是万震山的八弟子，聪明机灵，很讨大家的喜欢。\n");
	set("combat_exp", 3500);
	set("shen_type", 1);         

	set_skill("force", 30);
	set_skill("strike", 30);
	set_skill("sword", 30);

	set("inquiry", ([
		"万震山" : "他老人家是我的恩师啊。",
		"修为" : "你的修为高低决定了你的武功技能和潜能最大值的高低。和人比划，\n"+
			"修为越高胜算也就越高。得修为最简单的方法是和非玩家（NPC）打架。NPC的\n"+
			"修为如果和你相差太大，你是得不到什麽修为的。怎样才知道一个NPC是不是适\n"+
			"合你，你需要多问问老玩家。还有些其他得修为的方法，各门各派都有不同的\n"+
			"方法。多向师兄，师姐们请教吧。",
		"exp" : "你的修为高低决定了你的武功技能和潜能最大值的高低。和人比划，\n"+
			"修为越高胜算也就越高。得修为最简单的方法是和非玩家（NPC）打架。NPC的\n"+
			"修为如果和你相差太大，你是得不到什麽修为的。怎样才知道一个NPC是不是适\n"+
			"合你，你需要多问问老玩家。还有些其他得修为的方法，各门各派都有不同的\n"+
			"方法。多向师兄，师姐们请教吧。",
		"潜能" : "潜能是用来向师父学功夫的。每向师父学一次，就需要花一点潜能。\n"+
			"得潜能的最简单方法和修为一样，和 NPC打架。也和修为一样，只有和与你功\n"+
			"夫相近的NPC打架才能得潜能。还有些其他得潜能的方法，各门各派都有不同的\n"+
			"方法。多向师兄，师姐们请教吧。",
		"pot" : "潜能是用来向师父学功夫的。每向师父学一次，就需要花一点潜能。\n"+
			"得潜能的最简单方法和修为一样，和 NPC打架。也和修为一样，只有和与你功\n"+
			"夫相近的NPC打架才能得潜能。还有些其他得潜能的方法，各门各派都有不同的\n"+
			"方法。多向师兄，师姐们请教吧。",
		"打架" : " 打架有两种，一种是比划(fight)，另一种是生死相拼(kill)。比划\n"+
			"时，你的精或气损失过多时，你就会认输停手。但有时对手会不想和你比划。如\n"+
			"果你想要逼之出手，你可以用 hit(或者 kill）。与对手生死相拼很危险：对方\n"+
			"不杀死你是不会停手的。为了安全，你可以把你的逃跑指数设高(set wimpy 60)。\n"+
			"60表示当你的精或气跌低过百分之六十，你就会自动逃跑。但有时对手的攻势太\n"+
			"强或招式太厉害，你还是会逃不开的。所以与人搏命时要特别小心。如果你想和\n"+
			"我比划，就用“fight shen”。不过我的修为值很高的喔。",
		"fight" : " 打架有两种，一种是比划(fight)，另一种是生死相拼(kill)。比划\n"+
			"时，你的精或气损失过多时，你就会认输停手。但有时对手会不想和你比划。如\n"+
			"果你想要逼之出手，你可以用 hit(或者 kill）。与对手生死相拼很危险：对方\n"+
			"不杀死你是不会停手的。为了安全，你可以把你的逃跑指数设高(set wimpy 60)。\n"+
			"60表示当你的精或气跌低过百分之六十，你就会自动逃跑。但有时对手的攻势太\n"+
			"强或招式太厉害，你还是会逃不开的。所以与人搏命时要特别小心。如果你想和\n"+
			"我比划，就用“fight shen”。不过我的修为值很高的喔。",
		"学习" : (: ask_xuexi3 :),
	]));

	setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}


void greeting(object ob)
{
	if(ob->query_temp("jobask") == 3) {    
		command("hi "+ob->query("id"));
		command("say 这位" + RANK_D->query_respect(ob) +",你可以 "HIY HBCYN"ask shen about 学习"CYN" 来向我了解战斗的情况。"NOR);
	}
}

int ask_xuexi3()
{
	object ob = this_player();
	if(ob->query_temp("jobask") == 3) {
		command("say 这位" + RANK_D->query_respect(ob) +"是刚来的吧。赶快加紧练功，早日出馆到江湖上出人投地\n"+
		"去。如果你在练功上有什么疑问，就来问我吧。比如说什么是 "HIY HBCYN"修为（exp） "CYN" 和\n"+
		HIY HBCYN"潜能（pot）"CYN" ，如何 "HIY HBCYN"打架（fight）"CYN" 等等。还有别的疑问可以参看 "HIY HBCYN"help newbie"CYN" 。"NOR);
		ob->delete_temp("jobask");
		if(ob->query_temp("jobover") != 3) {
			ob->set_temp("jobover",  3);
			command("say 听说狄云兄弟还有点事情找你，你最好去看一下。"NOR);
			if ( ob->query_temp("combat_exp") < 300 ){
				ob->add("potential", 20);
				ob->add("combat_exp", 100);
				tell_object(ob,HIW"你听了沈城的讲解，增加了一百点实战修为和二十点潜能，对江湖又多了一分了解。"NOR"\n");
			}
		}
		return 1;
	}
	if ( ob->query_temp("jobover") == 3) {
		command("say 我不是都和你说了么，狄云兄弟有事找你，快去看下吧。");
		return 1;
	}
}
