// 穆念慈

inherit NPC;
#include <ansi.h>
int ask_bwzq();

void create()
{
        set_name("红衣女子", ({ "hongyi nvzi", "nvzi", "girl" }));
        set("gender", "女性");
        set("age", 17);
        set("str", 10);
        set("dex", 200);
        set("long", "她长得楚楚可怜，一笑一颦，极具研态。\n");
        set("combat_exp", 75000);
        set("shen_type", 1);
        set("attitude", "peaceful");
		set("uni_target",1);
        set_skill("hand", 60);
		set_skill("shexing-shou",60);
		set_skill("xiaoyaoyou",60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
		map_skill("hand", "shexing-shou");
		map_skill("dodge", "xiaoyaoyou");
        prepare_skill("hand", "shexing-shou");

        set("neili", 400); 
		set("max_qi",1000000);
		set("qi",1000000);
        set("max_neili", 400);
        set("jiali", 10);
		set("inquiry", ([
			"比武招亲" : (: ask_bwzq :),


		]) );
		setup();


        
		carry_object(__DIR__"items/redcloth")->wear();
}

int cancelaskmu(object me)
{
	me->delete_temp("shediaoquest/bwzqaskmu");
	return 1;
}

int ask_bwzq()
{
	object me=this_player();
	if (me->query_temp("shediaoquest/bwzqaskmu"))
	{
		return notify_fail("穆念慈柳眉一竖，你老问这个，烦不烦啊？");
	}
	if (me->query("id")!="wanyan kang")
	{
		tell_object(me,HIM"穆念慈脸一红，更增几分颜色。\n"NOR);
		me->set_temp("shediaoquest/bwzqaskmu",1);
		remove_call_out("cancelaskmu");
		call_out("cancelaskmu",20,me);
		return 1;
	}
	else
	{
		message_vision(HIM"穆念慈看了看完颜康，并不答话。\n"NOR,me);
		return 1;
	}
}

int blush()
{
	command("blush");
}

void init()
{
	if(interactive(this_player()))
	{
		command("fight da han");
	}
}

