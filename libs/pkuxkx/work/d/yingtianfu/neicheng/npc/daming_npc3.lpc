#include <ansi.h>
inherit NPC;
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_help();
void create()
{
    set_name("太常寺卿", ({"taichangsi qing", "qing"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的太常寺卿。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    set("mingpin",3);
	set("inquiry", ([
	
     "help": (: ask_help :),
     "帮助": (: ask_help :),
     
	]));
    setup();
    setup_player_name();
   
}

int ask_help()
{
	object me=this_player();
    object ob=this_object(),an;
    string *taskname=({"采买祭品","布置太庙"});
    int n;
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
   
    if (!me->query_temp("mingtasks/taichangsi/start"))
    {
        command("say 我这里暂时没有什么事，你去别的衙门看看哪里需要帮忙吧。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query("mingpin")>6)
    {
        command("say 你只是一个芝麻小官，恐怕不能胜任太常寺的艰巨任务。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/taichangsi/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
		n=random(sizeof(taskname));
		me->set_temp("mingtasks/taichangsi/task",n+1);
        if (n==0)
        {
			if (me->query("mingpin")<4)
			command("say 大人请到应天府杂货铺采买一些贡品，代为存放(store)到太常寺的库房吧。");
			else
            command("say 你到应天府杂货铺去采买一些贡品，存放(store)到太常寺的库房吧。");
        }
		if (n==1)
        {
			if (me->query("mingpin")<4)
			command("say 很快就要到冬至了，下官实在走不开，大人可以去太庙布置(buzhi)一番吗？");
			else
			command("say 很快就要到冬至了，你去太庙布置(buzhi)一番吧。");
        }
        return 1;
    }
}