//Cracked by Roath
// laohu.c 老虎
#include <ansi.h>
inherit NPC_TRAINEE;
#include "../newbie_village.h"

void create()
{
	set_name("老虎", ({ "lao hu", "hu", "tiger" }) );
	set("race", "野兽");
	set("gender","雄性");
	set("age", 25);
	set("long", "这是一头吊睛白额，气势汹汹的大虎，正恶狠狠地盯着你，好象随时随地都会扑上来择人而噬！\n");
	set("msg_fail", "$n冲$N呲牙吼了一声");
	set("msg_succ", "$n一面口中向$N荷荷发威，一面向后退了半步，似乎有些怯了");
	set("msg_trained","$n低吼着在$N的面前伏了下来");
	// set("auto_follow",1);
	set("attitude", "aggressive");

	set("wildness", 12);
	set("ridable", 1);
	set("ability", 4);

	set("limbs", ({ "头部", "身体", "右爪", "左爪", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );	
	set("str", 25);	
	set("con", 10);
	set("dex", 25);	
	set("int", 10);

	set("combat_exp", 2000);

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 10);
	set_temp("apply/armor",  0);

	set_weight(150000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"老虎用前爪拍击着地面，口中荷荷发威，好象随时都要扑上来！\n",
		"老虎微微侧着脑袋，双目炯炯，紧紧地注视着你的一举一动。\n",
		"老虎突然立了起来，绕着你走了半圈，似乎在观察着什么。\n",
	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"\n老虎怒啸一声，一反身，长长的尾巴向铁棍一样挥了过来！\n",
		"\n老虎全身一曲一弓，忽然跃起半空，猛地扑了下来！\n",
	}) );
		
	setup();
}

void die()
{
    object *inv;
    object who;
    int i;
    
    inv=all_inventory(environment());
    for (i=0;i<sizeof(inv);i++)
    {
        if (userp(inv[i]))
        {
            who=inv[i];
            break;
        }
    }

    set_nextquest(who,"去未明谷的树林除掉老虎","手刃了恶虎，你感觉自己威风凛凛！回去再向游鲲翼问问能不能闯荡江湖了吧！", 50, 250);
	// message_vision("\n$N仰天惨嚎了一声，趴在地上不动了。\n", this_object());
	::die();
}

void greeting(object ob)
{
	if (!objectp(ob)) return;
	tell_object(ob,GRN"那老虎长得极为狰狞，面向凶恶，趴在那里。行侠仗义的时候到了！\n注意检查一下自己的太乙剑是否装备好了。(wield sword)\n"NOR+HIC"kill lao hu，记得试试刚刚领悟的绝招“八方风雨”--perform sword.bafang！\n"NOR);
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && check_questindex(ob,"去未明谷的树林除掉老虎") == 1) {
		call_out("greeting",1,ob);
		if(!this_object()->query_lord(ob)) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 2, ob);
		}
	}	
}

