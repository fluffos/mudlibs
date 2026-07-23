//niang.c/2001 by lestat
inherit NPC;

#include <ansi.h>

string ask_for_join();

void create()
{
    set_name("林公公", ({"lin gonggong", "gong gong", "lin"}));
    set("long", "神策军收人管理主任。\n");
    set("title", "神策军第二代弟子");
    set("gender", "无性");
    set("age", 20);
    set("class", "needle");
    set("attitude", "friendly");
    set("per", 30);
    set("int", 30);
    set("max_kee", 29000);
    set("max_sen", 10000);
    set("force", 8000);
    set("max_force", 8000);
    set("force_factor", 200);
    set("max_mana", 8000);
    set("mana", 8000);
    set("mana_factor", 40);
    set("combat_exp", 80000000);
    set("daoxing", 80000000);
    set("eff_dx", 80000000);
    set("nkgain", 350);

    set("inquiry", ([
        "进宫" : (: ask_for_join :),
    ]) );

    set("chat_chance",5);
    set("chat_msg", ({
        HIM"天干物燥，小心火烛！\n"NOR,
    }));

    create_family("神策军", 2, "弟子");
    setup();

    carry_object("/d/moon/obj/luoyi")->wear();
    carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void init()
{
   add_action("do_cut", "laydown");
}

string ask_for_join()
{
    object me;
    object ob;

    ob = this_object();
    me = this_player();


    if ( (string)me->query("gender") == "无性" )
    {
        command("shake");
        return ("已经做了太监，这位" +
            RANK_D->query_respect(me) + "还是歇着吧。\n");
    }

    if ( (string)me->query("gender") == "女性" )
    {
        command("shake");
        return ("女人是不能太监的，这位" +
            RANK_D->query_respect(me) + "还是另请高就吧。\n");
    }

    if ( (me->query("family")) && (me->query("family/family_name") == ob->query("family/family_name")) )
    {
        command("shake");
        return ("已经做了太监，这位" +
            RANK_D->query_respect(me) + "还是歇着吧。\n");
    }

    me->set_temp("pending/join_jjg", 1);

    return "好！" + RANK_D->query_respect(ob) + "真心愿意割掉JJ进宫侍候皇上，荣华富贵享用不尽！请躺下(laydown)受割。\n";
}

int do_cut()
{
    string name, new_name;
    mapping myskills;
    string *m_skills;
    int i;

    if ( !this_player()->query_temp("pending/join_jjg") )
    {
        return 0;
    }
    message_vision( HIC "$N平心静气，战战兢兢地躺了下来。\n\n" + 
        "$n拿起工具，在$N裆部又刺又掏又搅了，然后死劲往外一拽，将$N的男根连根拔去。\n\n" NOR,
        this_player(), this_object() );

    name = this_player()->query("name");
    new_name = "小" + name[0..1] + "子";

    command("say 从今以後你的名字叫做" + new_name + "。");

    myskills = this_player()->query_skills();
    if ( myskills )
    {
        m_skills = keys(myskills);
        i = sizeof(m_skills);
        while ( i-- )
        {
            if ( m_skills[i] && stringp(m_skills[i]) )
            {
                this_player()->delete_skill(m_skills[i]);
            }
        }
        command("grin " + this_player()->query("id"));
    }

    command("rumor 据说" + this_player()->query("name") + "躺在凳子上，只见林公公拿起工具，在" + this_player()->query("name") + "裆部又刺又掏又搅，然后死劲往外一拽，只听" + this_player()->query("name") + "一声夹着欢愉，痛苦，快乐的呻吟声，被林公公将" + this_player()->query("name") + "的男根连根拔去。!");

    this_player()->delete_temp("pending/join_jjg");
    this_player()->set("name", new_name);
    this_player()->set("jjg/old_name", name);

    this_player()->save();

    this_player()->set("class", "needle");
    this_player()->set("classxt", "needle");
    this_player()->set("gender", "无性");

    return 1;
}

