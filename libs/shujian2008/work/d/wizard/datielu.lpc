// datielu.c
// by augx@sj  9/7/2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"打铁炉"NOR, ({ "datie lu" , "lu" }));
	set_weight(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", HIR"这是一座日夜炉火通明的打铁炉。\n"NOR+
"你可以用它来打铁(datie)：datie 矿石\n");
		set("value", 3000);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_datie","datie");
}

int do_datie(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level;

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");
	if (me->is_fight()) return notify_fail("你正忙着呢！\n");
	if (!arg) return notify_fail("你要打什么？\n");
	if (!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	if (!objectp(obj2 = present(obj->query("id")+" 2", me)))
		return notify_fail("你必须用两块"+obj->query("name")+"来打铁。\n");
	if( !(int)obj->query("kuangshi") || !(int)obj->query("level")
	 || !(int)obj2->query("kuangshi") || !(int)obj2->query("level"))
		return notify_fail("在这里只能用矿石来打造。\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
		return notify_fail("你必须装备铁锤才能来打铁。\n");
	if ( !wizardp(me) && (time()<(int)me->query("worker/datie")) )
		return notify_fail("你刚刚打铁结束，感觉过于劳累！\n");
	level = (int)me->query_skill("datie",1);
	if ( level<1 )
		return notify_fail("你根本就不会打铁！\n");

	switch( (int)obj->query_level() ) {
		case 1: break;
		case 2: if(level<40)  return notify_fail("你的打铁技能不够！\n"); break;
		case 3: if(level<80)  return notify_fail("你的打铁技能不够！\n"); break;
		case 4: if(level<120) return notify_fail("你的打铁技能不够！\n"); break;
		case 5: if(level<170) return notify_fail("你的打铁技能不够！\n"); break;
		case 6: if(level<220) return notify_fail("你的打铁技能不够！\n"); break;
		case 7: if(level<270) return notify_fail("你的打铁技能不够！\n"); break;
		case 8: if(level<330) return notify_fail("你的打铁技能不够！\n"); break;
		case 9: if(level<390) return notify_fail("你的打铁技能不够！\n"); break;
	}

	message_vision(RED"$N开始反复锤击"+obj->query("name")+RED"，努力把它变成可以用来锻造兵器的材料。\n\n"NOR, me);
	delay = 6 + random(12);
	if (wizardp(me) && (int)me->query("env/test")) delay = 3;
	me->start_busy(delay);
	call_out("datie_finish",delay*2-1,me,obj);
	destruct(obj2);
	return 1;
}

void datie_finish(object me,object obj)
{
	object tools;
	int level, kuangshi, i=1,improve;

	if(!objectp(me) || !userp(me) || !objectp(obj)) return;
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("datie",1);
	if(level>390) level = 390 + (level-390)*11;
	kuangshi = (int)obj->query_level();

	message_vision(YEL"$N累的大汗淋漓，但总算打完了。\n"NOR, me);
	if ( objectp(tools) && tools->query("id")=="tiechui" )
		tools->use();

	switch(kuangshi) {
		case 1: i = 40;  break;
		case 2: i = 80;  break;
		case 3: i = 120; break;
		case 4: i = 170; break;
		case 5: i = 220; break;
		case 6: i = 270; break;
		case 7: i = 330; break;
		case 8: i = 390; break;
		case 9: i = 500; break;
	}
	i = 100 - (level - i)/2;
	if(i>200) i = 200;
	if(i< 10) i = 10;
	improve = me->query_int()*i/100;

	switch(kuangshi) {
		case 1: i = 40;  if(level>100) level=100; break;
		case 2: i = 80;  if(level>150) level=150; break;
		case 3: i = 120; if(level>200) level=200; break;
		case 4: i = 170; if(level>300) level=300; break;
		case 5: i = 220; if(level>400) level=400; break;
		case 6: i = 300; if(level>500) level=500; break;
		case 7: i = 450; if(level>500) level=500; break;
		case 8: i = 600; if(level>500) level=500; break;
		case 9: i = 850; if(level>500) level=500; break;
	}
	if( random(level+i) > i ) {
		me->improve_skill("datie", improve*8);
		me->add("combat_exp", random(improve));
		me->add("potential", random(improve/5*3));
		obj->change_state();
		message_vision(HIC"$N得到一块"+obj->query("name")+"。\n"NOR, me);
	}
	else {
		me->improve_skill("datie", improve*2);
		me->add("combat_exp", random(improve/2));
		me->add("potential", random(improve/5));
		message_vision(HIC"但是在打铁炉里，$N只看到一堆废铁。\n"NOR, me);
		destruct(obj);
	}
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/datie",time()+6+random(12));
}
