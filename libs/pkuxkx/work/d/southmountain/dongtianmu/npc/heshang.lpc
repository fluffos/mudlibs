#include <ansi.h>
inherit NPC;
int ask_story();
int ask_mirror();
int ask_name();
int ask_zen();
int ask_here();
void create()
{
	set_name("澄雨", ({"cheng yu", "chengyu","cheng","yu","monk"}));
    set("title", HIW"大觉寺"+HIY+" 住持"+NOR);
	set("nickname","大和尚");
    set("gender", "男性");
    set("age", 60);
    set("long", "他就是大觉寺的住持澄雨和尚。\n他虽然是和尚，却穿着大宋的官服，有些不伦不类。\n");
    set("attitude","heroism");
    set("generation",0);
    set("max_qi",1800);
    set("eff_qi",1800);
    set("qi",2800);
    set("max_jing",8000);
    set("jing",8000);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",2000000);

    create_family("少林派", 37, "弟子");

	set("NoBusyAsking",1);
	set("inquiry", ([
	"往事" : (:ask_story:),
	"铜镜" : (:ask_mirror:),
	"name" : (:ask_name:),
	"随口禅" : (:ask_zen:),
	"东天目山" : (:ask_here:),
	"here" : (:ask_here:),
    	]));
    setup();
    carry_object("/d/song/npc/obj/cloth1")->wear();
}
int ask_here()
{
	object me=this_player();
	me->add_busy(2);
	command("say 那你问我可算问对人了，我在这住了十来年了。");
	command("say 东天目山盛产各种药材，只要找对(lookfor)地方，就可以采集(gahter)。");
	return 1;
}
int ask_zen()
{
	object me=this_player();
	me->add_busy(1);
	command("say 随口禅可是大神通，我夜观天象，发现你暂时是学不会的。");
	return 1;
}
int ask_name()
{
	object me=this_player();
	me->add_busy(1);
	command("say 我就是老和尚，老和尚就是我啊。");
	return 1;
}
int ask_mirror()
{
	object me=this_player();
	me->add_busy(1);
	command("say 这面铜镜据说是殷商时期留下来的。");
	return 1;
}
int ask_story()
{
	object me=this_player();
	me->add_busy(1);
	if (me->query("family/family_name")!="朝廷")
	{
		command("say 往事？往事不堪回首，还问什么往事？");
		return 1;
	}
	else
	{
		command("say 想当年我的官可比你大多了，但又有什么好提的呢？");
		tell_object(me,"朝廷后续任务开发中，请耐心等待。\n");
		return 1;
	}
}