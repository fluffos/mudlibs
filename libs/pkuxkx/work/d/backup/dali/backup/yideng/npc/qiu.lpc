//裘千仞
//by icer
#include <ansi.h>


inherit NPC;

int ask_ying();

void create()
{
        set_name("裘千仞", ({ "qiu qianren","qiu"}));
	set("nickname",HIY"铁掌水上飘"NOR);
        set("long", "此人身披葛衫，手执蒲扇，白须皓发正是铁掌帮主裘千仞。\n");
        set("gender", "男性");
        set("rank_info/respect", "前辈");
        set("age", 62);
        set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("shen_type", -1);
	set("shen",30000);

        set_skill("strike", 120);
        set_skill("force", 120);
        set_skill("dodge", 200);
	set_skill("parry",120);
	set_skill("huntian-qigong",150);
	set_skill("cuixin-zhang",150);
	map_skill("strike","cuixinzhang");
	map_skill("force","huntian-qigong");
	map_skill("parry","cuixin-zhang");
        set("combat_exp", 350000);

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("inquiry", ([
	    "瑛姑" : (: ask_ying :),
       ]) );

        setup();
        carry_object("/d/shaolin/obj/cloth")->wear();
}


int ask_ying()
{
	object me;
	int current_qi;
	me = this_player();
	current_qi = (int)me->query("qi");

	
	if (me->query_temp("marks/done瑛"))
	{
		command("sigh");
		command("say 我很对不起瑛姑。这些年来我回想自己的所作所为，时常汗颜。\n
我决定拜一灯大师为师，从此一心向佛。\n");
		command("thank "+ me->query("id"));
		me->set("task_duan2",1);
		return 1;
	}
	if (me->query_temp("marks/周2"))
	{
		command("say 你怎么知道了？\n");
		command("say 来来来，和我打一架，你赢了我就听你的，你输了就给我滚！\n");

		while ( ((int)me->query("qi")*100 / (int)me->query("max_qi")) > 50) { 
			if ( !present(me, environment()) )
				return 1;
                        COMBAT_D->do_attack(me, this_object(), query_temp("weapon"));
			if (((int)this_object()->query("qi")*100/current_qi)< 50) {
				say(
"裘千仞对" + me->name() + "说道：真是一代更比一代强啊！以前是我不对，我决定随一灯大师出家，
好好反省增加的过失。\n"
				);
				me->set("task_duan2", 1);
				return 1;
			}
	                 COMBAT_D->do_attack(this_object(), me);
		}
		say(
"裘千仞冲着" + me->query("name") + "大吼一声：滚！别再来烦老子！\n");
                return 1;
	}
	else
	{
		command("say 你是怎么知道的？这下可留你不得啦！\n");
		command("grin "+me->query("id"));
		command("kill "+me->query("id"));
		return 1;
	}
}

void die()
{
	object obj;
	if( objectp(obj = this_object()->get_damage_origin_object()) && (obj->query_temp("marks/裘2"))) 
	{
		 obj->set_temp("marks/killed_qiu",1);
	}
	::die();
}
	
	