#include <ansi.h>
inherit NPC;

int ask_ore();


void create()
{
	set_name("珠宝商", ({ "zhubao shang", "shang" }));
    set("gender", "男性");
	set("age", 50);
	set("long", "他是一个珠宝商，可以帮助玩家把矿石提炼成宝石，是完全免费的。\n");
	
	set("combat_exp", 10000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

    set("inquiry", ([
    "ore" : (: ask_ore :) ,
    "矿石" : (: ask_ore :) ,
    ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_ore()
{
	command("say 我可以帮你把矿石提炼成宝石，只要给我矿石就可以了。\n");
	return 1;
}

int dest_and_give(object me,object ore)
{
    object ob;
    if (ore)
    {
        ob=ore->recover();
        destruct(ore);
    }
    ob->move(me);
    message_vision("$N递还给$n一"+ob->query("unit")+ob->query("name")+"。\n",this_object(),me);
    return 1;
}

int accept_object(object me, object ore)
{
    if (this_object()->is_busy())
    {
        return notify_fail("我正忙着呢，你一会再来。\n");
    }
    else if (!ore->is_ore())
    {
        return notify_fail("我只能帮你提炼矿石，而不是其他什么东西。\n");
    }
    else 
    {
        this_object()->start_busy(1);
        call_out("dest_and_give",1,me,ore);
        return 1;
    }
}

