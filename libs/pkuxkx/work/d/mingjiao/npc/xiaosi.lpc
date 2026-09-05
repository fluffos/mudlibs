#include <ansi.h>          

inherit NPC;   
string ask_lvliu();

void create()         
{
    set_name("小厮", ({ "xiao si", "si" }) );    
    set("gender", "男性");   
    set("age", 15);    
    set("per", 30);     
    set("long", "一个十多岁的小厮，眼神贼溜溜的，看起来相当机灵。\n" NOR); 
    set("combat_exp", 10000);     
    set("shen_type", 0);      
    set("attitude", "friendly");       
    set_skill("unarmed", 40);        
    set_skill("parry", 40); 
    set_skill("dodge", 40);        
    set_skill("force", 40);
    set("max_qi", 10000);
    set("max_jing", 10000);
    set("max_jingli", 1000);
    set("max_neili", 1000);
	set("inquiry",([
		"绿柳山庄": "这里就是绿柳山庄呀，你都来了还问，嘿嘿……",
		"别院": (: ask_lvliu :),
		"山庄别院": (: ask_lvliu :),
	]));
    setup();
}      

void unconcious()
{
	die();
}

void die()
{
	object ob = this_object();
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	message_vision(HIM"$N掏出一颗黑乎乎的丹药塞进嘴里，噎得直翻白眼，好不容易才咽了下去，脸上涌起了一阵潮红。\n"NOR, ob);
	ob->remove_all_killer();
	return;
}

string ask_lvliu()
{
	object me=this_player();
	if (me->query_temp("lvliu_ask_xiaosi"))
		return "尊客走好！";
	if (me->is_busy() || me->is_fighting())
		return "尊客还是先把手上的事忙完了再聊不迟。";
	command("consider");
	if (me->query("combat_exp")<10000000)
		return "别院……别院是什么？能吃么？";
	tell_object(me, HIG"小厮在你耳边小声说道：「原来尊客已经知道此处只是山庄的别院？也罢，这便请阁下赴敝庄稍歇！」\n"NOR);
	message_vision(HIW"$N" HIW "拨开一人高的草丛，为$n" HIW "指点了一条偏僻的小路。\n"NOR, this_object(), me);
	me->set_temp("lvliu_ask_xiaosi",1);
	me->start_busy(3);
	call_out("gogogo", 2, me);
	return "尊客走好！";
}

void gogogo(object me)
{
	if (!objectp(me)) return;
	me->delete_temp("lvliu_ask_xiaosi");
	me->move("/d/lvliu/xiaolu");
	tell_object(me, HIW"你沿着小厮指点的道路，一脚深、一脚浅地走到了一个陌生的地方。\n"NOR);
	message("vision", HIW + me->name() + HIW + "沿着偏僻小路一脚深、一脚浅地走了过来！\n" NOR, environment(me), ({ me }));
}

