//兵部侍郎

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_b1();
int ask_b2();
int ask_b3();

void create()
{
    set_name("兵部左侍郎", ({"bingbu shilang", "shilang"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的兵部左侍郎。\n");
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
	
     "操练新军": (: ask_b1 :),
     "督造军械": (: ask_b2 :),
     "清点军粮": (: ask_b3 :),
     
	]));

    setup();
    setup_player_name();
}

int ask_b1()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"兵部侍郎傲慢地望着天花板，并不理你。\n");
        return 1;
    }
    else
    {
        command("say 近年我朝兵备废弛。");
        command("say 你到了应天府西北的军营，检阅(jianyue)后会了解官军的训练程度。");
        command("say 接下来就要练兵(lianbing)了，训练程度超过八十五就可以回来复命，但要记住，不能把官军往死里练，训练度超过一百，会哗变的。");
        return 1;
    }
}

int ask_b2()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"兵部侍郎傲慢地望着天花板，并不理你。\n");
        return 1;
    }
    else
    {
        command("say 近年我朝兵备废弛。");
        command("say 你到了应天府北城，直接督造(duzao)军械，造好就回来复命。");
        return 1;
    }
}

int ask_b3()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"兵部侍郎傲慢地望着天花板，并不理你。\n");
        return 1;
    }
    else
    {
        command("say 近年我朝兵备废弛。");
        command("say 你到了应天府西北的军仓，清点(qingdian)好米粮回来复命。");
        return 1;
    }
}