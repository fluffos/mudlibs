// cooker.c
// by Find.

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小厨子", ({ "cooker" }) );
	set("gender", "男性" );
	set("age", 33);
	set("long", "他就是浮华酒楼的厨子。\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);

	set("inquiry",([
	"干活" : CYN + "小厨子说道：“这倒有些洗(xi)碗洗盘子的活。”\n" + NOR,
	"工作" : CYN + "小厨子说道：“这倒有些洗(xi)碗洗盘子的活。”\n" + NOR,
	"work" : CYN + "小厨子说道：“这倒有些洗(xi)碗洗盘子的活。”\n" + NOR,
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_work",({"wash","xi"}));
}

int do_work(string arg)
{
	object me = this_player();
	int time;

	if( arg != "plate"
	&& arg != "bowl"
	&& arg != "盘子"
	&& arg != "碗")
		return notify_fail(sprintf(CYN "%s疑惑的看了你一眼：“你要干什么？”\n" NOR,name()));

	if(me->query_temp("changan_work"))
		return notify_fail("给你的活还没有干完呢，等会儿再说吧。\n");

	time = time();

	if(time - me->query("changan_work") < 30)
		return notify_fail(sprintf(CYN "%s说道：这么大年龄也该去干点正事了，等会儿再来吧。\n" NOR,name()));
	if(me->query("age") > 22)
		me->set("changan_work",time);

	// 应该可以，就是拿不到钱。 by Find.
	if(me->query("jing") <= 0
	|| me->query("qi") <= 0
	)
		return notify_fail(sprintf(CYN"%s摇摇头说：“你这人面色蜡黄，身体虚弱，我这不敢用。”\n"NOR,
	name()));

	if(arg == "plate")
		arg = "盘子";
	else if(arg == "bowl")
		arg = "碗";

	message_vision(sprintf("$N%s抱起了一堆%s跑到边上洗了起来。\n",
	( mapp(me->query_temp("armor"))
	&& !sizeof(keys(me->query_temp("armor"))) )?
	"光着身子":"捋起袖子",arg),me);

	me->start_busy(3);
	me->set_temp("changan_work",1);
	call_out("finish_work",3,me,arg);
	return 1;
}

void finish_work(object me,string what)
{
	object ob;
	int flag = 0,kee,gin;

	if( ((gin = me->query("jing")) < 20)
	|| ((kee = me->query("qi")) < 20) )
	{
		tell_object(me,what+"还没洗完你就已经累得不行了。\n");
		flag = 1;
	}

	me->receive_damage("qi",20);
	me->receive_damage("jing",20);
	me->delete_temp("changan_work");

	if(flag)
		return;

	tell_object(me,sprintf("你累了个满头大汗总算把%s洗完了。\n",what));

	if(!living(me) || environment(me) != environment())
		return;

	ob = new(SILVER_OB);
	if(!ob->move(me))
	{
		flag = 1;
		ob->move(environment());
	}
	else
		flag = 0;

	message_vision(sprintf(CYN"$N冲$n点点头说道：“这是你的工钱”\n"NOR,
	(flag)?"，给你放地上了。":"。"),this_object(),me);
	return;
}
