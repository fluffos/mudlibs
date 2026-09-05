// NPC yupopo.c

#include <ansi.h>

inherit NPC;

inherit F_MASTER;
void create()
{
    set_name("程青霜", ({ "cheng qingshuang", "cheng", "qingshuang" }));
    set("long",
            "她是「灵鹫宫」九天九部中钧天部的副首领.\n");
    set("title", "钧天部副首领");
    set("gender", "女性");
    set("age", 20);
    set("shen_type",1);
    set("attitude", "peaceful");

    set("str", 20);
    set("int", 25);
    set("con", 30);
    set("dex", 30);

    set("qi", 1500);
    set("max_qi", 1500);
    set("jing", 1200);
    set("max_jing", 1200);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 50);

    set("combat_exp", 80000);
    set("score", 1000);
    
    set_skill("literate",70);
    set_skill("force", 80);
    set_skill("dodge", 80);
    set_skill("parry", 70);
    set_skill("hand",70);
    set_skill("strike", 80);
    set_skill("sword",60);

    set_skill("changhen-jian",70);
    set_skill("zhemei-shou",60);
    set_skill("liuyang-zhang",70);
    set_skill("yueying-wubu",60);
    set_skill("bahuang-gong", 70);
    set_skill("duzun-xinfa", 70);

    map_skill("force", "bahuang-gong");
    map_skill("strike","liuyang-zhang");
    map_skill("dodge", "yueying-wubu");
    map_skill("hand", "zhemei-shou");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword", "changhen-jian");
    create_family("灵鹫宫",4,"弟子");
    setup();
    carry_object("/d/lingjiu/obj/qingyi")->wear();
    carry_object("/d/lingjiu/obj/doupeng")->wear();
    carry_object("/clone/weapon/changjian")->wield();
    add_money("silver",40);
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("gender")!="女性")
    {
        command("say 你找死啊!");
        return;
    }
    if (ob->query("betrayer")>1)
    {
        command("say 本宫最忌欺师灭祖之事，你多次判师，我怎么还能收你？");
        return;  }

        if  ((int)ob->query("family/generation") <5 && ob->query("family/family_name") == "灵鹫宫")
        {
            command("say 您开什么玩笑？我这点玩意哪能教您呀？");
            return;  }

            if (ob->query_con() < 20) 
            {
                command("say 本门功法极为难练,你的根骨似乎不够.");
                return;
            }
            command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
            command("recruit " + ob->query("id"));
            return;
}



void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("title",MAG "灵鹫宫" NOR + HIG +"弟子" NOR); 
    return;
}
