// wizardb.c


inherit NPC;

int ask_name();
int ask_guild();
void create()
{
	set_name("巫师",({  "wizard", "wushi" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long", "这是一个成天无所事事的巫师。\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

	set("inquiry", ([
		"name": (: ask_name :),
		"rumors": "听说玩家自建帮派系统进入开放阶段了。",
        	"bbb": "见到帮主我，难道没有任何表示吗？",
		"建帮": (:ask_guild :),
         	"杀手": "见到帮主我，难道没有任何表示吗？",
	]) );

        carry_object("/clone/misc/cloth")->wear();
}

int ask_name()
{
	object ob = this_player();

	command("smash " + ob->query("id"));
	say("没搞错吧？一声不吭就smash别人？准是BBB。\n");
	return 1;
}

int ask_guild()
{
	object ob = this_player();
	int exp = ob->query("combat_exp");
//		command("say 新的帮派系统正在开发中，到时候再来申请吧。\n");
//		return 1;
//	if ( ob->query("g_title"))
//		say("巫师说道：你已经有令牌了。\n");
	if (exp >= 2000000 && (!present("lingpai",ob)))
	{
          	new("/data/group/obj/ling")->move(ob);
		say("巫师说道：把令牌拿去吧。帮派系统，有建议、BUG 请向 bbb 报告。\n");
	}
	if ( exp < 2000000 )
		say("巫师说道：你的经验不够，暂时不能创建帮派。\n");
	if ( present("lingpai",ob))
		say("巫师说道：你已经有令牌了。\n");
	else	say("巫师说道：条件不符合，不能创建帮派。\n");
	return 1;
}
