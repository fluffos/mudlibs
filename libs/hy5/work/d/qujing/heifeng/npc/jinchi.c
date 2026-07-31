//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/jinchi.c
 
inherit NPC;
string ask_jiasha();

void create()
{
        set_name("金池长老", ({"jin chi","monk","jinchi"}));
        set("long", "一个看上去很慈祥的老和尚。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 150);
        set("combat_exp", 300000);
        set("combat_exp",2000000);
        set("per", 25);
        set("max_qi", 500);
        set("qi",500);
        set("max_jing",500);
        set("jing",500);
        set("neili", 1000);
        set("force_factor", 50);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("spells",80);
        set_skill("buddhism", 100);
        set_skill("unarmed", 80);

        set("inquiry", ([
        "袈裟": (: ask_jiasha :),
        "jiasha": (: ask_jiasha :),
        ]));
        
        setup();
        carry_object("/d/obj/weapon/staff/chanzhang")->wield();
        carry_object("/d/qujing/heifeng/obj/cloth")->wear();
        setup();
}

string ask_jiasha()
{
         object ob = this_player();

        if( ob->query_temp("fired") )
                {
                command("fear");
                return("袈裟....袈裟....袈裟不见了。");
                }
        if( ob->query("obstacle/hf") == "done" 
         || ob->query_temp("see_jiasha"))
                return("这位施主不是已经看过袈裟了吗？\n");


        command("haha");
        command("knock wall");
        ob->set_temp("see_jiasha",1);
        return("哈哈，看袈裟，你找对人了。\n");

}

int accept_object(object who, object ob)
{
                if( (string)ob->query("id") == "wucai jiasha"
                   && who->query_temp("see_jiasha"))
                {
                command("ah");
                who->set_temp("jiasha_given",1);
                return 1;
                }
        else return notify_fail("什么玩意？不稀罕。\n");
}
