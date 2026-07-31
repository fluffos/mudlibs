// blind_beggar.c

inherit NPC;

string ask_me(object who);
int is_quest_object() { return 1;}

private int being,time,finish = 0;

void create()
{
	set_name("瞎眼乞丐", ({ "blind beggar" }) );

	set("gender", "男性" );

	set("age", 57);

	set("long","这是一位瞎了眼睛的老乞丐。\n");
	set("combat_exp", 100);

	set("no_kill", 1);
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("attitude", "friendly");

	set("inquiry",([
	"衣服" : (: ask_me :),
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	if(!who->query("quest/shaolin_quest/asked_yahuan"))
		return 0;

	if(who->query("quest/shaolin_quest/have"))
		return "小的不是已经给你了，怎么还要。";

	return "那件衣服是诸葛老爷家赏的，你拿走了小的就没法过冬了，要不您随便赏个三、五两银子吧。";
}

int accept_object(object who,object ob)
{
	object cloth;

	if(being)
		return 0;

	being++;

	if(who->query("quest/shaolin_quest/asked_yahuan")
	&& ob->query("money_id") && ob->value() > 300)
	{
	cloth = new(__DIR__"obj/tupu");
	write(sprintf("%s从腰里拿出一个破衣服卷交给了你。\n\n你展开脏兮兮的衣服看到上面画满了小人。\n
以你的武功学识看来，这正是一幅『拳法图谱』！！\n",name()));
	cloth->move(who);
	who->set("quest/shaolin_quest/have",1);
	finish = 1;
	}
	command("say 多谢这位" + RANK_D->query_respect(who) + "，您好心一定会有好报的！");
	return 1;
}

int heal_up()
{
	int t;

	if(finish && living(this_object()))
	{
		call_out("go_away",1);
		return 1;
	}

	t = time();

	if(!time)
		time = t;

	else if(t - time > 1200)
	{
		call_out("go_away",1);
		return 1;
	}

	return ::heal_up() + 1;
}

void go_away()
{
	if(environment())
		tell_object(environment(),name()+"匆匆忙忙地走了。\n");
	destruct(this_object());
}
