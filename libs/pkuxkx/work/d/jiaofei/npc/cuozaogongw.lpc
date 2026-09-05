//by skywolf for wuzhishan-yushi 2009-2-8

inherit NPC;
#include <ansi.h>
void init();
string a="apply/strength";
int amount;
int do_caozao();
void create()
{
        set_name(HIY"女搓澡工"NOR, ({"cuozao gong", "gong"}));
        set("long","一位女性搓澡工，她一丝不挂，肩膀上搭着一条毛巾。\n");
        set("gender", "女性");
        set("attitude", "friendly");        
        set("age", 25);
        set("str", 21);
        set("int", 25);      
        set("con", 20);
        set("no_get", 1);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("cuff", 100);
        set_skill("parry", 100);
         set("inquiry", ([ 
              "anmo" : "搓澡一次五十两黄金，在老板那里交钱", 
        ]));

        set("shen_type",1);set("score",200);setup();
}

void init()
{
   add_action("do_cuozao","cuozao");
}                               


int do_cuozao()
{
	object ob = this_object();
	object me = this_player();
	object obj;
	if (!me->query_temp("jiaofei/bath_paid"))
	{
		return notify_fail("搓澡工说到：想霸王搓么？出去交钱先！！\n");
	}
	if(me->is_busy())
	{
		return notify_fail("你正忙着呢！\n");
	}	 
	if(me->query("temp_cuozao"))
	{
		return notify_fail("还搓？再搓你的皮就搓没了！！\n");
	}
	amount=random(8)+1;
	tell_object(me,"你在木床上躺了下来。\n");
	tell_object(me,HIY"一位搓澡工走了过来，开始给你搓澡。\n"NOR);
	tell_object(me,HIR"随着有规律的敲击声。。。你渐渐进入梦乡。\n"NOR);
	me->set_temp("block_msg/all", 1);
	me->disable_player("<搓澡中>");
	me->start_busy(10);
	me->set("temp_cuozao",1);
	me->delete_temp("jiaofei/bath_paid");
	call_out("wakeup", 10, me);
	return 1;
}
void wakeup(object me)
{
	me->start_busy(0);
    me->delete_temp("block_msg/all");
	switch (random(4))
	{
	case 0:
		a="apply/strength";
		me->add_temp(a, amount);
		call_out("remove_effect", 3600 , me, amount);     
		message_vision(HIW"$N你感觉神清气爽，似乎自己又强壮了一些。"NOR +"\n\n",me);
	break;
	case 1:
		a="apply/intelligence";
		me->add_temp(a, amount);
		call_out("remove_effect", 3600 , me, amount);     
		message_vision(HIW"$N你感觉神清气爽，似乎自己又聪明了一些。"NOR +"\n\n",me);
	break;
	case 2:
		a="apply/dexerity";
		me->add_temp(a, amount);
		call_out("remove_effect", 3600 , me, amount);     
		message_vision(HIW"$N你感觉神清气爽，似乎自己又敏捷了一些。"NOR +"\n\n",me);
	break;
	case 3:
		a="apply/constitution";
		me->add_temp(a, amount);
		call_out("remove_effect", 3600 , me, amount);     
		message_vision(HIW"$N你感觉神清气爽，似乎自己的根骨又增强了一些。"NOR +"\n\n",me);
	break;
	}
}
void remove_effect(object me, int b)
{
	if(!me)  return;
    tell_object(me,HIY"你打了个冷颤，感觉精油的效力已去。\n"NOR);
	me->delete("temp_cuozao");
    me->add_temp(a, - b);
	amount=0;
}