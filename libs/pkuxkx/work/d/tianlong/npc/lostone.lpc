#include <ansi.h>
inherit NPC;
#include "/d/tianlong/bonus.h"
int ask_job();
int ask_job2();
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("long",
                "他是一个出门在外的路人，似乎迷了路。\n");
        set("title",RED "路人"NOR);
        set("gender", "男性");
        set("age", 16+random(60));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        set("max_qi", 200);
        set("max_jing", 150);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 3000);
        set("score", 3000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 20);
        set_skill("parry", 30);
        set("random_npc",1);
        set("bonus",3+random(2));
        set("inquiry", ([
        "迷路":   (: ask_job() :),
        "lost":   (: ask_job() :),
        "带路":   (: ask_job2() :),
        "lead":   (: ask_job2() :),
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        call_out("dest",300);
}

int dest()
{
    object ob=this_object();
    object owner;
	if (ob->query("owner")&&find_player(ob->query("owner")))
	{
		owner=find_player(ob->query("owner"));
		owner->set_temp("tlnewbiejob/lead/where","unknown");
	}
	
    message_vision("$N找到了回家的路，匆匆忙忙离开了。\n",ob);
    destruct(ob);
    return 1;
}

void init()
{
    object env,env2;
    object owner,where;
    object ob=this_object();
    
    owner=find_player(ob->query("owner"));
    if (!owner||!living(owner))
    {
        message_vision("$N找到了回家的路，匆匆忙忙离开了。\n",ob);
        destruct(ob);
        return;
    }
    env=environment(ob);
    env2=environment(owner);
    if (owner->query_temp("tlnewbiejob/lead/where")&&env==env2&&base_name(env)==owner->query_temp("tlnewbiejob/lead/where"))
    {
        if (random(2)&&!owner->query_temp("tlnewbiejob/lead/wrongplace"))
        {
            owner->set_temp("tlnewbiejob/lead/wrongplace",1);
            while (!objectp(where) || 
              !where->isroom()||
              TASK_D->place_belong(where)=="不明区域"||
              base_name(where) == "/adm/daemons/taskd"||
              where->query("no_tianlong")||
              where==env)
        {where=TASK_D->random_room("/d/tianlong/");}
        command("say 哎呀，我记错了，其实要去的是"+where->query("short")+"。");
        command("blush");
        owner->set_temp("tlnewbiejob/lead/where",base_name(where));
        return;
        }
        command("good "+owner->query("id"));
        command("say 太感谢啦！");
        tell_object(owner,ob->name()+"找到了要去的地方，高兴地离开了。\n");
        bonus(owner);
        destruct(ob);
        return;
    }
}

int ask_job2()
{
    object me=this_player();
    object ob=this_object();
    object where;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("tlnewbiejob/lead/start"))
    {
        command("fear "+me->query("id"));
        message_vision("$N暗地里低估，这人莫非是个强贼？",ob);
        return 1;
    }
    if (me->query("id")!=ob->query("owner"))
    {
        command("say 天行健，君子以自强不息，找路嘛，难不倒我的。");
        command("addoil "+ob->query("id"));
        return 1;
    }
    if (!me->query_temp("tlnewbiejob/lead/where"))
    {
        command("dao");
        command("say 山大王饶命啊！");
        message_vision("$N暗想，连地方都不问就要带我走，一定是强贼了！\n",ob);
        return 1;
    }
    command("follow "+me->query("id"));
    return 1;
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    object where;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("tlnewbiejob/lead/start"))
    {
        command("fear "+me->query("id"));
        message_vision("$N暗地里低估，这人莫非是个强贼？",ob);
        return 1;
    }
    if (me->query("id")!=ob->query("owner"))
    {
        command("say 天行健，君子以自强不息，找路嘛，难不倒我的。");
        command("addoil "+ob->query("id"));
        return 1;
    }
    if (me->query_temp("tlnewbiejob/lead/where"))
    {
        command("ks");
        return 1;
    }
    while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
          where->query("no_tianlong"))
        {where=TASK_D->random_room("/d/tianlong/");}
    command("say 是啊，我本要去"+where->query("short")+"，结果迷路，不知道你能不能带我去？");
    me->set_temp("tlnewbiejob/lead/where",base_name(where));
    me->add_busy(random(3));
    return 1;
}


