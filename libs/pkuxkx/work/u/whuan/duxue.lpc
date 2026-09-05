// 督学，负责发放工钱
#include <ansi.h>
inherit NPC;
int ask_done();
int do_report(string arg);
void create()
{
        set_name("督学", ({ "du xue", "duxue" }));
        set("gender", "男性" );
        set("age", 20+random(15));
        set("long",
                "这是督学，负责监督抄经工作的，如果你完成了抄经的工作，
                不妨问他拿赏钱。(ask du xue about finish)\n");
        set("combat_exp", random(1500));
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
        set("attitude", "friendly");
        set("no_fight",1);
        set("uni_target",1);
        set("inquiry",([
                "工作":"您得去问朱熹大人，我可做不了主。",
                "job":"您得去问朱熹大人，我可做不了主。",
                "完成":(:ask_done:),  
                "finish":(:ask_done:), 
                "done":(:ask_done:), 
                ]));
        setup();
        carry_object("clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_report", "report");
}
int ask_done()
{
        object me=this_player();
        if (!me->query_temp("chaojing/finished")) 
            return 0; 
        command("look "+me->query("id"));
        command("say 报上你的工号！(report 工号)\n");
        me->set_temp("chaojing/report",1);
        return 1;    
}

int do_report(string arg)
{
        object me=this_player();
        if (!me->query_temp("chaojing/report")) return 0;
        if (!arg || arg=="")
        {
           command("say 请报上工号！");
           return 1;
        }
        if (arg==me->query_temp("chaojing/sn"))
           {
           command("say 很好！我已经吩咐人存了100两银子到您的帐号，欢迎下次再来抄经。");  
           me->add("balance",10000);
           } 
        else
          {
           command("say 工号不对，本次工作不能领取工钱。");
          }
        me->delete_temp("chaojing"); 
        return 1;
}
