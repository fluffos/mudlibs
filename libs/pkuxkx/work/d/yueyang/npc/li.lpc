#include <ansi.h>
inherit NPC;
int ask_quest();
string* place = ({

       "/d/yueyang/dangpu",
	   "/d/yueyang/dongtinghu",
	   "/d/yueyang/eastgate",
	   "/d/yueyang/eaststreet",
       "/d/yueyang/guangchang",
	   "/d/yueyang/machehang",
	   "/d/yueyang/northgate",
	   "/d/yueyang/northstreet",
       "/d/yueyang/qianzhuang",
	   "/d/yueyang/southgate",
       "/d/yueyang/southstreet",
	   "/d/yueyang/yueyang2",
       "/d/yueyang/weststreet",
	   "/d/yueyang/westhgate",
	   "/d/yueyang/yueyanglou",
	   
});


#include "/d/song/obj/askmap.h"

void create()
{
	set_name("李保长", ({ "li baozhang", "baozhang","li" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 40+random(25));
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
            "name" : "我就是大名鼎鼎的李保长。",
			"quest" : (: ask_quest :),
            "江南八镇" : (: ask_quest :),
       	]) );
    set("loc","岳阳");
	setup();
    carry_object("/clone/cloth/cloth")->wear();

}

int ask_quest()
{
    object ob=this_object();
    object me=this_player();
    object room;
    object xie;
    if (me->query("jiangnanquest/finish"))
    {
        command("admire "+me->query("id"));
        return 1;
    }
    else if (!me->query("jiangnanquest/step1"))
    {
        command("? "+me->query("id"));
		return 1;
    }
    else if (me->query("jiangnanquest/step2"))
    {
        command("say 我这没什么事了，你去成都，武侯祠似乎有人在找人帮忙。\n");
        me->set_temp("jn/step3",1);
		return 1;
    }
    else if (me->query_temp("jn/step2"))
    {
        command("say 你快去找吧。");
        return 1;
    }
    else if (present("xie",me))
    {
        command("say 你快去找吧。");
        return 1;
    }
    else
    {
		while (!objectp(room)||!room->isroom())
        room = load_object( place[random(sizeof(place))] );
        room->set("shoesearch",me->query("id"));
        command("say 我好像在城里赶庙会时丢了一只一模一样的鞋，如果你能帮我找到就好了。\n");
        xie=new("/d/yueyang/npc/obj/xie");
        xie->set("owner",me->query("id"));
        xie->move(me);
        tell_object(me,ob->query("name")+"给了你一只鞋。\n");
        me->set_temp("jn/step2",1);
		return 1;
    }
}

int dest(object xie,object me)
{
    int exp=random(200);
    if (xie)
    {
        destruct(xie);
    }
    me->add("combat_exp",exp);
    tell_object(me,HIW+sprintf("做完好事后，你的心情大爽，不由挥舞起拳脚，练了起来。\n你的经验增加了%d点。\n",exp)+NOR);
    return 1;
}

int accept_object(object me, object xie)
{
	if( xie->query("name") != "李保长的一双鞋")
	return notify_fail("李保长说：你确定这是你给我找回的鞋？\n");
    if (!me->query_temp("jn/step2"))
    return notify_fail("李保长无语了。\n");
    me->delete_temp("jn/step2");
    if (xie->query("owner")!=me->query("id"))
    return notify_fail("李保长说：鞋是不错，但似乎不太合脚啊。\n");
	if (me->is_busy() || me->is_fighting())
    return notify_fail("你正忙着哪！\n");
    if (this_object()->is_busy() || this_object()->is_fighting())
    return notify_fail(this_object()->query("name")+"正忙着哪！\n");
	else
		{
			me->set("jiangnanquest/step2",1);
			command("say 不错，这就是我赶庙会时候丢掉的鞋子。\n");
            call_out("dest",1,xie,me);
            this_object()->add_busy(1);
            me->add_busy(1);
            return 1;
		}
}
