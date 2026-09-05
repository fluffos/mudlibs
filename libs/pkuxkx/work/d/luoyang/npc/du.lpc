// du. 杜老板
// modified by Zine 10/4/2011 add 宴客功能给玩家
#include <ansi.h>
#include "/d/luoyang/npc/ask_yanke.h"
inherit NPC;
int ask_yanke();
void create()
{
	set_name("杜老板", ({ "du laoban", "du" }));
	set("title", HIC"望"HIY"星"HIC"楼\t"NOR"老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
        set("long", "杜老板新近刚刚买下生意红火的望星楼。\n");
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
    set("palace","/d/luoyang/guodao");
    set("yanke_no","yanke2");
	setup();
    carry_object("/clone/armor/cloth")->wear();
        add_money("silver", 10);
        //add_money("gold", 1);
}

int adv_tell(object ob)
{
    command("tell "+ob->query("id")+" 阁下这样大喜的日子，还是来望星楼才够气派了。");
    if (ob->query("pyh_obtain_high_gem"))
    {
        command("tell "+ob->query("id")+" 古语有云：破财消灾，你在鄱阳湖寻宝中拿到那么大宝石不怕折福吗？");
    }
    command("tell "+ob->query("id")+" 详情咨询请来望星楼，ask du about 宴客。醉仙楼经常人满为患");
    return 1;
}

