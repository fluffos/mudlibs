// Modify By River@SJ 2003.08.26

inherit NPC;

#include <ansi.h>
#include "question.h"

void create()
{
	set_name("狄云", ({ "di yun","di","yun" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "他忠厚老实，乐于帮助江湖新手。\n");

	set("per", 20);
	set("str", 40);
	set("int", 15);
	set("dex", 30);
	set("con", 35);

	set("max_qi", 12500);
	set("max_jing", 7500);
	set("neili", 18600);
	set("eff_jingli", 7500);
	set("max_neili", 18500);
	set("jiali", 150); 
	set("unique", 1);
	set("combat_exp", 4700000);
	set("attitude", "friendly");

	set_skill("cuff", 320);
	set_skill("dodge", 320);
	set_skill("force", 340);
	set_skill("parry", 340);
	set_skill("sword", 320);
	set_skill("literate", 150);
	set_skill("shenzhao-jing", 340);
	set_skill("shaolin-shenfa", 320);
	set_skill("taizu-quan", 300);

	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taizu-quan");
	map_skill("cuff", "taizu-quan");
	map_skill("dodge", "shaolin-shenfa");
	prepare_skill("cuff", "taizu-quan");

	setup(); 
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object ob;
	add_action("do_answer","answer");
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ! ob->query_temp("wgtask") && ob->query("combat_exp") < 400 ) {
		ob->set_temp("wgtask",1);
		ob->set_temp("wgmeet", 1);
		command("bow "+ob->query("id"));
		command("whisper "+ob->query("id")+" 这位" + RANK_D->query_respect(ob) +"初次来到这个神秘的武侠世界，是不是\n"+
			"感觉充满着新奇和陌生？我可以告诉你怎样慢慢熟悉这个世界的，请问你是否\n"+
			"需要帮助呢？如果您是个新手，请输入 "HIY HBCYN"answer y"GRN"，否则就请输入 "HIY HBCYN"answer n"GRN"。");
	}
	if( ob->query_temp("jobover") == 1) {
		ob->set_temp("jobask",2);
		command("pat "+ob->query("id"));
		command("whisper "+ ob->query("id")+ " 现在对自己和武馆的环境有一定了解了吧？不过，\n"+
			"光了解周围的环境还不够，还要了解整个世界的情况才行，周圻师兄常年闯荡\n"+
			"江湖，知道的比较多，你可以去找他问问。他现在在偏厅一带，你可以按照我\n"+
			"孙均兄弟告诉你的武馆地图（help map wuguan）去找他。");
	}
	if( ob->query_temp("jobover") == 2) {
		ob->set_temp("jobask",3);
		command("smile "+ob->query("id"));
		command("whisper "+ ob->query("id")+ " 了解了整个世界，是不是感觉雄心勃勃，想到江湖\n"+
			"中有一番作为呢？那么，去找我沈城师兄学习下战斗知识吧。他现在正在练功\n"+
			"房教人练功呢。"NOR);
	}
	if( ob->query_temp("jobover") == 3) {
		ob->set_temp("jobask",4);
		command("hehehe");
		command("whisper "+ ob->query("id")+ " 行走江湖，光凭好勇斗狠是不行的，还要注意跟大\n"+
			"家多多交流哦。我师妹最爱唠叨，有深厚的“聊天功力”，你去找她准没错。\n"+
			"她现在在睡房附近，恐怕正想找人聊天呢。"NOR);
	}
	if( ob->query_temp("jobover") == 4 && ob->query_temp("jobask") != 5) {
		ob->set_temp("jobask", 5);
		command("nod");
		command("whisper "+ ob->query("id")+ " 好了，现在你已经对书剑也了解的差不多了。武馆\n"+
			"有还有很多事情要做，我鲁坤师兄正缺人手，你可以到他那找点工作来做。");
	}
	if( ob->query("combat_exp") < 3000 && ob->query_temp("jobover") == 5) {
		command("pat " +ob->query("id"));
		tell_object(ob, CYN"狄云说道：「这位" + RANK_D->query_respect(ob) +"，我出几个问题考考你，如果答对了可有奖哦。」\n"NOR);
		tell_object(ob, WHT"\n如果确认回答问题，请输入 "HIY HBCYN"answer y"WHT" ，不愿意回答的话，可以继续去鲁坤师\n"+
				"兄那里继续工作，请输入 "HIY HBCYN"answer n"WHT" 。\n\n");
		ob->set_temp("wgquestion",1);
	}
}

string replace_number(string msg)
{
	msg = replace_string(msg, "一", "a");
	msg = replace_string(msg, "二", "b");
	msg = replace_string(msg, "三", "c");
	msg = replace_string(msg, "四", "d");
	msg = replace_string(msg, "五", "e");
	msg = replace_string(msg, "六", "f");
	return msg;
}

string *answer_type;

mixed choose_type(object me, string *answer, int j, string right_answer)
{
	int x, y;
	string str;

	for ( x = 0; x < j ; x ++) {
		str = answer[random(j)];
		answer_type = me->query_temp("answer_type");
		if ( ! sizeof(answer_type))
			me->set_temp("answer_type", ({ str }));
		else {
			for(y=0; y < j; y ++) {
				if (member_array(str, answer_type) != -1)
					str = answer[y];
			}
			answer_type = answer_type + ({ str });
			me->set_temp("answer_type", answer_type );
		}
		if ( str == right_answer )
			me->set_temp("answer", replace_number(chinese_number(x+1)));
	}
	return answer_type;
}

int do_question(object me)
{
	string right_answer, str, *answer;
	int i, j, x;
	mapping question;

	if ( me->query_temp("answer_list") && sizeof(keys(me->query_temp("answer_list"))) >= sizeof(question_list)) {
		command("say 不好意思，没有题目了。");
		return 1;
	}

	i = random(sizeof(question_list));

	if ( me->query_temp("answer_list/"+ i) )
		do_question(me);
	else {
		me->set_temp("answer_list/"+ i , 1);

		question = question_list[i];
		answer = question["choose"] + ({ question["answer"] });
		right_answer = question["answer"];

		j = sizeof(answer);

		choose_type(me, answer, j, right_answer);

		me->add("wgjob/quest", 1);

		tell_object(me, CYN"\n狄云说道：「现在是第"+chinese_number(me->query("wgjob/quest"))+"题，一共有"+chinese_number(j)+"个选项，请用 "HIY HBCYN"answer 字母"CYN" 回答。」\n"NOR);
		str = "请问：" + question["question"] +"\n";

		for ( x = 0; x < j ; x ++ ) {
			str += sprintf("%s、%-31s%s", 
				capitalize(replace_number(chinese_number(x+1))), 
				answer_type[x], 
				(x+1)%2?"":"\n"
			);
		}

		if ( j % 2)
			str += "\n";
		tell_object(me, str);
		return 1;
	}
}

int do_answer(string arg)
{
	object me = this_player();
	string str;
	float i;

	if ( ! arg ) return 0;
	if ( me->query_temp("wgmeet")) {
		me->delete_temp("wgmeet");
		if ( arg == "y" ) {
			command("nod "+ me->query("id"));
			command("whisper " + me->query("id")+ " 那好，我们先来了解一下一些基本的指令：在书剑\n"+
				"里移动的命令是e、w、s、n、u、d，分别代表东西南北上下六个基本方向，以\n"+
				"及ne、wd、su、enter、out等组合和特殊命令，它们分别代表东北、西下、南\n"+
				"上等方向以及进入和外出等。好了，现在你可以去找孙均，他会告诉你更多的\n"+
				"常识，他现在应该在门廊一带，往南走两步就到了。");
			me->set_temp("jobask",1);
			me->set_temp("need_answer", 1);
		}
		else if ( arg == "n" ) {
			command("nod "+ me->query("id"));
			command("whisper " + me->query("id")+ " 看来你对书剑已经有了一定的了解，武馆里还有很\n"+
				"多事情要做，我鲁坤师兄正缺人手，你可以到他那找点工作来做。");
			me->set_temp("jobask", 5);
		}
		return 1;
	}
	if ( me->query_temp("wgquestion")) {
		me->delete_temp("need_answer");
		me->delete_temp("wgquestion");
		me->delete_temp("jobover");
		if ( arg == "y") {
			tell_object(me, CYN"狄云说道：「好吧，不过在回答问题前，我还是要先提醒你一下，你可以通过\n"+
					"指令 "HIY HBCYN"help"CYN" 来了解一下书剑的一些基本情况。下面的一些问题，你可以通过查\n"+
					"询 help 来得到正确的答案，如果实在找不到答案，也可以通过 "HIY HBCYN"chat"CYN" 来询问\n"+
					"别人来得到答案。」\n"NOR);
			tell_object(me, HIR"\n\t\t准备好了吧！那我们就开始了。\n\n"NOR);
			call_out("do_question", 0 , me);
		}
		else if ( arg == "n" ) {
			tell_object(me, CYN"狄云说道：「哎，不过既然你不想回答，那也就算了。」\n"NOR);
		}
		return 1;
	}
	if ( me->query_temp("answer")) {
		if ( arg == "字母")
			return notify_fail(CYN"狄云说道：「请回答具体的字母，例如回答："HIY HBCYN"answer A"CYN" 。」\n"NOR);
		if ( arg == me->query_temp("answer") || arg == capitalize(me->query_temp("answer"))) {
			me->add("combat_exp", 80 );
			me->add_temp("right", 1);
			if ( me->query_skill("literate", 1) < 30 ) {
				me->set_skill("literate", me->query_skill("literate", 1) + 1);
				str = "和一级读书写字。";
			}
			else
				str ="。";
			i = me->query_temp("right")*100.0 / me->query("wgjob/quest");
			tell_object(me, HIW"恭喜你，答对了！你被奖励了八十点实战经验"+str+"\n"NOR);
			tell_object(me, CYN"狄云说道：「您到目前一共回答了"+chinese_number(me->query("wgjob/quest"))+"题，答对了"+chinese_number(me->query_temp("right"))+"题，成功率为 "+sprintf("%3.2f%%", i)+"。」\n"NOR);
		}
		else tell_object(me, CYN"狄云说道：「哎，真可惜，你答错了，正确答案应该是 "+capitalize(me->query_temp("answer"))+" 才对。」\n"NOR);

		me->delete_temp("answer");
		me->delete_temp("answer_type");

		if ( me->query("combat_exp") < 3000 && me->query("wgjob/quest") < 50 ) 
			do_question(me);
		else {
			if ( me->query("combat_exp") >= 3000 ) {
				command("congra "+me->query("id"));
				tell_object(me, CYN"狄云说道：「你可以去找我师伯万震山询问离馆的事情了 "HIY HBCYN"ask wan about 离馆"CYN" 。」\n"NOR);
			}
			else {
				command("addoil "+ me->query("id"));
				tell_object(me, CYN"狄云说道：「你可以继续去到我大师兄那儿找工作做 "HIY HBCYN"ask lu about 工作"CYN" 。」\n"NOR);
			}
		}
		return 1;
	}
	return 0;
}
