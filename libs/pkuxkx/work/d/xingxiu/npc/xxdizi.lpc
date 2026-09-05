// 星宿传功弟子
// Zine Oct 16 2010

inherit NPC;
#include "/new_quest/qxiepai.h"
#include "/new_quest/quest.h"

#include <ansi.h>

int ask_skill();
void create()
{
	set_name("传功弟子", ({ "chuangong dizi", "dizi"}));
	set("long", "她是星宿派负责传授新人武功的弟子。\n");
	set("gender", "女性");
    set("title", HIR"星宿派"NOR);
	set("age", 15);
    set("start_room","/d/xingxiu/tianxiugong");
	set_skill("literate", 100);
    set_skill("poison", 80);
    set_skill("force", 80);
    set_skill("tianshan-zhang", 80);
    set_skill("xingxiu-duzhang", 80);
    set_skill("zhaixing-shou", 80);
    set_skill("zhaixinggong", 80);
    set_skill("strike", 80);
    set_skill("hand", 80);
    set_skill("dodge", 1);
    set_skill("staff", 1);
	set_skill("huagong-dafa", 80);
	set_skill("parry", 80);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("strike", "xingxiu-duzhang");
    map_skill("hand", "zhaixing-shou");
    map_skill("parry", "xingxiu-duzhang");
    map_skill("staff", "tianshan-zhang");
    prepare_skill("strike", "xingxiu-duzhang");
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
    set("xingxiu_chuangong_dizi",1);
	set("combat_exp", 400000);
	set("shen_type", 1);
    set("inquiry", ([
                "quest":   (: ask_quest() :),
                "cancelquest":   (: ask_cancel() :),
                "取消任务":   (: ask_cancel() :),
			"skills" : (: ask_skill :),
            "技能" : (: ask_skill :),
            
			
			
            
       	]) );
	set("chat_chance", 2);
        set("chat_msg", ({
                "传功弟子说：你可以用ask dizi about 技能 来了解可以跟我学习什么。\n",
                
        }) );
    create_family("星宿派", 3, "弟子");
	setup();
}

void init()
{
    object ob=this_object();
    if (environment(ob)&&base_name(environment(ob))!="/d/xingxiu/tianxiugong")
    {
        message_vision("$N急急忙忙的离开了。\n",ob);
        ob->move("/d/xingxiu/tianxiugong");
    }
}

int is_mentor()
{
	return 1;
}
int recognize_apprentice(object ob)
{
    if (this_player()->query("family/family_name")=="星宿派")
    {
        return 1;
    }
}

int ask_skill()
{
	string *ems=EMOTE_D->query_all_emote();
	string em=ems[random(sizeof(ems))];
    if (this_object()->is_busy() || this_object()->is_fighting())
	{
		return notify_fail("传功弟子正忙着呐！\n");
	}
        write(HIW"传功弟子告诉你：我学过\n");
        write("\t一百级读书写字。\n");
        write("\t八十级基本毒技。\n");
        write("\t八十级基本内功。\n");
        write("\t八十级天山杖法。\n");
        write("\t八十级星宿毒掌。\n");
        write("\t八十级摘星手。\n");
        write("\t八十级摘星功。\n");
        write("\t八十级基本掌法。\n");
        write("\t八十级基本手法。\n");
        write("\t一级基本轻功。\n");
        write("\t一级基本杖法。\n");
        write("\t八十级化功大法。\n");
        write("\t八十级基本招架。\n");
        write("在新手阶段你可以跟我学习(xue)。\n"NOR);
        this_object()->add_busy(2);
		command(em);
		return 1;
}