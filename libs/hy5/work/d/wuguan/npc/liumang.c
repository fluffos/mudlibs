// by dubei
// liumang.c 流氓

inherit NPC;
#include <ansi.h>
void create()
{
    set_name("小流氓", ({ "xiao liumang", "xiao", "liumang" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的流氓，专门欺负一些比自己弱小的人。\n");
	set("combat_exp", 1000);
	set("shen", -10);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	set_skill("dodge", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 6);
}
void init()
{
        object ob;

        ::init();
    if (!living(this_object())) return;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        add_action("do_bihua", "bihua");
        }
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
              if ( ob->query("combat_exp",1)<2500)
           message_vision(CYN "$N恶狠狠地对$n说道：前几天我们几个兄弟被你们武馆的人打伤了，象是你干的吧！
今天想从这里出去就跟我"HIR"(bihua)"CYN"比划比划，如果赢了，我就闪开一条路，让你走，否则就爬回武馆去！\n", this_object(), ob);
        else message_vision("$N谄媚地对$n说道：这位"+RANK_D->query_respect(ob)+"武功高强，实在是英雄出少年，您老请，您老请。\n", this_object(), ob);
}
int do_bihua()
{
	object me, ob;
	int current_qi,exp;

	me = this_object();
	ob = this_player();
        current_qi = (int)me->query("qi");
        exp = (int)ob->query("combat_exp");
      if (exp >2500) return notify_fail("您就饶了我吧，我怎敢和你比划呢？\n");
        if (me->is_fighting(ob)) return notify_fail("着什麽及，大爷先打发了他，一会就来教训你！\n");
	command("say 好吧，今天就让我教训，教训你。");
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        
	while ( ((int)ob->query("qi")*100 / (int)ob->query("max_qi")) > 50) { 
		if ( !present(ob, environment()) ) return 1;
                COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"));
		if (((int)me->query("qi")*100/current_qi)< 50) {
                   message_vision("$N沮丧的对$n说道：您果然出手不凡，当真是自古英雄出少年，今天小的总算见识了，
以后您老经过这里，小的绝不敢在骚扰您老了。你大人大量，今天就放过小的吧。说完
就恭恭敬敬的把$n让到了青龙内街。\n",me, ob);
		   ob->move("/d/xiangyang/eroad1");
           ob->delete("enter_wuguan");
                   tell_room(environment(ob), ob->name() + "在集市从人群中神气活现的走了过来。\n", ({ ob }));
		   return 1;
		   }
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
                reset_eval_cost();
		}
		say("小流氓趾高气扬冲着" + ob->name() + "撇了撇嘴，说道：就你这点本事还来充英雄？！给我乖乖的爬回去吧！\n");
                return 1;
	say("小流氓不耐烦的对" + ob->name() + "说道：你怎麽比猪还慢，要打就动手，罗嗦什么！\n");
	return 1;
}
void unconcious()
{
    reincarnate();
    set("eff_qi", query("max_qi"));
    set("qi", query("max_qi"));
    set("eff_jing", query("max_jing"));
    set("jing", query("max_jing"));
    set("jingli", query("eff_jingli"));
}

void die()
{
    unconcious();
}
