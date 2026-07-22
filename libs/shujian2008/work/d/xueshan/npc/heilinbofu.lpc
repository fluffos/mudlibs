// heilinbofu.c 黑林钵夫
// by iceland

#include <ansi.h>
inherit NPC;

string ask_for_join();

void create()
{
	set_name("黑林钵夫", ({"heilin bofu","heilinbofu","heilin","bofu"}));
	set("long",
                "他生得身高体阔，虎背熊腰，满脸的横肉，一双绿豆小眼\n"
                "朝四外来回打量着。\n"
	);

        set("title", HIY "大轮寺第十三代弟子" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "huanxi");

	set("inquiry",([
		"出家"	: (: ask_for_join :),
		"受戒"	: (: ask_for_join :),
	]));

	set("age", 30);
	set("shen_type", -1);
	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 20);
	set("max_qi", 450);
	set("eff_jing", 200);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("score", 1000);
	set("unique", 1);

	set_skill("force", 30);
	set_skill("longxiang-boruo", 30);
	set_skill("dodge", 30);
	set_skill("yuxue-dunxing", 30);
	set_skill("claw", 30);
	set_skill("tianwang-zhua", 30);
	set_skill("parry", 30);
	set_skill("huanxi-chan", 30);
	set_skill("literate", 30);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("claw", "tianwang-zhua");
	map_skill("parry", "tianwang-zhua");

	prepare_skill("claw", "tianwang-zhua");

	create_family("大轮寺", 13, "弟子");

	setup();

        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();
}

void init(){add_action("do_kneel", "kneel");}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("family/family_name") != "大轮寺")
		return RANK_D->query_respect(me) + "不是在开玩笑吧。\n";

	if( (string)me->query("class")=="huanxi" )
		return "我已经给你开坛受戒过了，你想比别人多一次？这可不行。\n";

	if( (string)me->query("gender") == "无性" )
		return "施主身体残缺，虽说佛祖普渡众生，可是……\n";

	if (me->query_temp("pending/join_huanxi"))
		return "虔诚点，做法事的时候别老问这问那。\n";
        
	me->set_temp("pending/join_huanxi", 1);
	return "你若真心献身侍奉欢喜佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	if( !me->query_temp("pending/join_huanxi") )
		return 0;

	message_vision("$N弯腰低头，恭恭敬敬地跪了下来。\n\n",me);
        message_vision("黑林钵夫掏出几件法器，低眉垂目，围着你绕了几圈，口中念念有词。\n\n",me);
        message_vision("黑林钵夫弹些清水撒在$N头上，山风一吹，$N不由得打了几个寒战。\n\n",me);
        message_vision("黑林钵夫声音越来越高，额头渗出密密的汗水，似乎用了很大的力气。\n\n",me);
        message_vision("黑林钵夫长吁了一口气，把法器放回怀中，用衣袖擦了擦脸上的汗水。\n\n",me);
	command("smile");
	command("say 好啦，受戒法事做完了，从今以后欢喜佛祖会保佑你的。\n");
	me->delete_temp("pending/join_huanxi");
	me->set("class", "huanxi");
        return 1;
}
