// File		: xuyuanwen.c
// 顾炎武 by pishou and zqb :) and Updated by Jpei
// Modified By	: iszt@pkuxkx, 2006-08-14

#include <ansi.h>

inherit NPC;

string ask_degree();
string ask_price();
void create()
{
	set_name("徐元文", ({ "xu yuanwen", "xu" }));
	set("long", "徐元文字公肃，出生于世代文运昌盛、出了不少学问之士的
江苏昆山徐氏大族。徐元文的舅父，更是闻名南北的学问大
家顾炎武。徐元文幼年既以神童才子著称，他诗才超妙，性
格风流潇洒，文人骚客无不倾仰。文士多爱此处梅花，徐元
文亦如是，所以就暂居于此，设馆为生。\n");
	set("gender", "男性");
	set("title", HIC"风流才子"NOR);
	set("age", 34);
    	set("per", 24);

	set("no_get","徐元文对你来说太重了。\n");
    	set_skill("literate", 300);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 10);

	set("combat_exp", 3500);
	set("shen_type", 1);
	setup();

	set("inquiry", ([
		"熊赐履" : "赐履兄性情刚毅，道学严谨，不知现在如何了？",
		"赐履" : "赐履兄性情刚毅，道学严谨，不知现在如何了？",
		"敬修" : "那是在下的一个朋友，姓熊，名赐履，字敬修。",
		"道学" : "道可道，非常道，此中玄妙还须徐徐参详。",
		"舅父" : "我舅父顾炎武是一代江南名儒，一向耻食周粟，要为大明守节。",
		"皇上" : "皇上英明有为，天下科举铨选必将一扫积秽，杜绝弊端。",
		"朝廷" : "朝廷虽是重用人才，但若要在武林中出人头地，加入朝廷绝对不是好主意。",
		"学问" : (:ask_degree:),
		"学识" : (:ask_degree:),
		"学位" : (:ask_degree:),
		"科举" : (:ask_degree:),
		"学费" : (:ask_price:),
		]) );
	set("chat_chance", 3);
	set("chat_msg", ({
		"徐元文不觉叹道：「敬修那一园芳草，叫人顿觉生意满眼，多少诗情画意，真个流连难舍啊！……」”\n",
		"徐元文笑道：「我舅父，一向耻食周粟，要为大明守节，但近年来也不反对我出仕了。」”\n",
		"徐元文道：「皇上英明有为，天下科举铨选必将一扫积秽，杜绝弊端。」\n",
		"徐元文道：「江南科场弊端已发，朝廷必将严惩。这不正是我辈出头之日么！」\n",
	}) );
	carry_object("/clone/misc/cloth")->wear();
}

string ask_price()
{
	int money, level;
	
	money = 10;
	level = this_player()->query_skill("literate", 1);
	
	if (level > 29) money = 20;
	if (level > 59) money = 50;
	if (level > 139) money = 100;
	if (level > 199) money = 200;

	return "你现在的学费是每次" + MONEY_D->money_str(money) + "。\n";
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 10, level = ob->query_skill("literate", 1);

	if (level >= ob->query("int")*10){
		message_vision(CYN"\n$N对着$n端详了一番道：「人的天赋有限，我已经无法教你学问了。」\n"NOR, this_object(), ob);
		message_vision(CYN"$N又点了点头：「"+ask_degree()+"」\n\n"NOR, this_object());
		return 0;
	}
	
	if (level > 29) money = 20;
	if (level > 59) money = 50;
	if (level > 139) money = 100;
	if (level > 199) money = 200;

	ob->delete_temp("mark/literate");
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
		return notify_fail("你现在学习一次所需要的费用是"+MONEY_D->money_str(money)+"，你身上带的零钱不够了。\n");
	}
	ob->set_temp("mark/literate", 1);
	return 1;
}

string ask_degree()
{
	object me = this_player();

	string title,newtitle;
	int level;

	level = me->query_skill("literate",1);
	if (!level || level < 1 )
		newtitle = GRN"文盲"NOR;
	else if (level < 10)
		newtitle = GRN"学童"NOR;
	else if (level < 20)
		newtitle = CYN"童生"NOR;
	else if (level < 40)
		newtitle = CYN"书生"NOR;
	else if (level < 60)
		newtitle = YEL"秀才"NOR;
	else if (level < 80)
		newtitle = HIY"举人"NOR;
	else if (level < 100)
		newtitle = HIY"解元"NOR;
	else if (level < 120)
		newtitle = MAG"贡士"NOR;
	else if (level < 140)
		newtitle = MAG"会元"NOR;
	else if (level < 160)
		newtitle = HIG"进士"NOR;
	else if (level < 180)
		newtitle = HIG"庶吉士"NOR;
	else if (level < 200)
		newtitle = HIG"传胪"NOR;
	else if (level < 240)
		newtitle = HIM"探花"NOR;
	else if (level < 270)
		newtitle = HIM"榜眼"NOR;
	else if (level < 300)
		newtitle = HIM"状元"NOR;
	else if (level < 340)
		newtitle = HIC"翰林"NOR;
	else if (level < 380)
		newtitle = HIC"学士"NOR;
	else if (level < 420)
		newtitle = HIC"内阁大学士"NOR;
	else if (level < 460)
		newtitle = HIC"内阁首辅"NOR;
	else if (level < 500)
		newtitle = HIW"文坛领袖"NOR;
	else if (level < 600)
		newtitle = HIW"文学大宗师"NOR;
	else if (level < 1000)
		newtitle = HIW"文圣"NOR;
	else newtitle = HIR"北侠活神仙"NOR;

	title =  newtitle + " " + me->query("name") +
		"(" + capitalize(me->query("id")) + ")";
	if(level >= 60 && level < 380)
		title = CHINESE_D->chinese_date(time())[0..5] + title;
	me->set_temp("apply/short", title);

	return "凭阁下的学识，依在下看，你可以做一名"+newtitle+"。";
}

