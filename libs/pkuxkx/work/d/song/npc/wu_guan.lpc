#include <ansi.h>
inherit NPC;
int ask_help();

void create()
{
    string name,*tmp,*pinying;
    name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("title", HIR"大宋"NOR" 低阶武官");
    set("gender", "男性");
    set("age", 20+random(20));
    set("long", "他是一名低阶的武官。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",3);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

	set("inquiry", ([
	
     "述职": (: ask_help :),
     "shuzhi": (: ask_help :),
     
	]));
    setup();
	call_out("dest",360);
}
int dest()
{
	if (this_object())
	{
		destruct(this_object());
	}
}
int ask_help()
{
	object ob=this_object(),me=this_player();
	if (me->is_busy())
	{
		return notify_fail("你正忙着呢。\n");
	}
	if (ob->query("owner")!=me)
	{
		command("hmm");
		me->add_busy(5);
		return 1;
	}
	if (me->query_temp("songtasks/bingbu/wg_degree")>20)
	{
		tell_object(me,"你已了解了详情，可以回去复命了。\n");
		return 1;
	}
	message_vision("$N向$n细细询问这些年任职的一些情况。\n",me,ob);
	message_vision("$N一一作了解答。\n",ob);
	me->add_temp("songtasks/bingbu/wg_degree",1+random(2));
	me->add_busy(2);
	if (me->query_temp("songtasks/bingbu/wg_degree")>20)
	{
		me->set_temp("songtasks/bingbu/wg_name",ob->name());
		me->set_temp("songtasks/bingbu/2/finish",1);
		tell_object(me,HIG+"你认为你已经了解了足够多的事情，可以回去复命了。\n"+NOR);
		remove_call_out("dest");
		call_out("dest",20);
		return 1;
	}
	return 1;
}