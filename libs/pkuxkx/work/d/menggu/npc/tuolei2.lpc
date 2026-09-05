// 哲别
// create by zine Aug 30 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("拖雷", ({"tuo lei", "tuo ", "lei"}));
	set("long", 
            HIR"他是铁木真幺子拖雷。\n"NOR);
	set("gender", "男性");
	set("age", 18);
    set("combat_exp", 250000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth4")->wear();
	
}
	
int bye(object me)
{
	object cloth;
	cloth=new(__DIR__"items/tuocloth");
	me->set("shediaoquest/zjk",2);
	cloth->move(this_object());
	command("give "+me->query("id")+" diao qiu");
	command("say 好兄弟，这件貂裘是从王罕的宝库夺来的，通体漆黑，全无一丝杂毛。");
	message_vision("只见华筝双额红晕，脉脉不语。$N笑道：“妹子，你跟他说话啊，我走开就是。”说着纵马走开。\n",this_object());
	destruct(this_object());
	return 1;
}