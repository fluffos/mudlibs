#include <ansi.h>
inherit __DIR__"npc_item";
void create()
{
	set_name("神龙武学概览", ({ "wuxue gailan", "book"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本神龙武学概览<NPC专用>。\n");
		set("value", 25000);
		set("material", "paper");
		set("anti_job",({"jobs/completed/huyidao"}));
	}
	setup();
}

void init()
{
	add_action("do_read","read");
}
int do_read()
{
	int n;
	string *skills=({"shenlong-bian","dulong-bi","huagu-mianzhang","yixingbu"});
	object me=this_player(),ob=this_object();
	if (userp(me))
	return 0;
	if (me->query("read"))
	return 0;
	n=random(sizeof(skills));
	me->set_skill(skills[n],me->query_skill(skills[n],1)/8+me->query_skill(skills[n],1));
	tell_room(environment(me),me->name()+"读完"+query("name")+"瞬间领悟"+to_chinese(skills[n])+"的真意。\n");
	me->set("read",1);
	destruct(this_object());
	return 1;
}