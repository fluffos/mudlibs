
#include <ansi.h>
inherit NPC;
int ask_quest();

void create()
{
	set_name("少女", ({ "girl"}));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 15+random(3));
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("random_npc",1);
    set("inquiry", ([
			"quest" : (: ask_quest :),
            "倩影" : (: ask_quest :),
            "邀约" : (: ask_quest :),
            "帮助" : (: ask_quest :),
       	]) );

	setup();
    carry_object("clone/cloth/female2-cloth")->wear();

}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    int exp=random(300);
    if (me->query("jiangnanquest/step3"))
    {
        command("say 你还不坐大车去昆明？\n");
        me->set_temp("jn/step4a",1);
		return 1;
    }
    if (!me->query_temp("jn/step3d"))
    {
        command("?");
		return 1;
    }
    else
    {
        command("say 其实我只不过和你开个玩笑，千万别介意啊，听说昆明平西王府的管家在找人帮忙，你从这里坐大车，过去到昆明就知道了。");
        me->set("jiangnanquest/step3",1);
        me->delete_temp("jn/step3d");
        me->set_temp("jn/step4a",1);
        me->add("combat_exp",exp);
        tell_object(me,HIW+sprintf("少女跟了聊了聊她小时候的故事。\n你的经验增加了%d点。\n",exp)+NOR);
		return 1;
    }
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}