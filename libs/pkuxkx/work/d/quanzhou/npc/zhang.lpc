// du. 杜老板
// modified by Zine 10/4/2011 add 宴客功能给玩家
#include <ansi.h>
#include "/d/luoyang/npc/ask_yanke.h"
inherit NPC;
int ask_yanke();
void create()
{
	set_name("张老板", ({ "zhang laoban", "zhang" }));
	set("title", HIM"烟雨楼  "HIW"老板"NOR);
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	
        set("inquiry", ([
   
                "yanke" : (: ask_yanke :),
        ]));
    set("palace","/d/quanzhou/guodao");
    set("yanke_no","yanke3");
	setup();
    carry_object("/clone/armor/cloth")->wear();
        add_money("silver", 10);
        //add_money("gold", 1);
}

