#include <ansi.h>
inherit NPC;
#include "/d/tianlong/bonus.h"
void create()
{
        string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("long",
                "他是一个乡里的缙绅。\n");
        set("title",HIC "缙绅"NOR);
        set("gender", "男性");
        set("age", 30+random(60));
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
        set("bonus",1+random(4));
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        call_out("moving",1);
        call_out("dest",500);
}

void init()
{
    add_action("do_huayuan","huayuan");
}

int reward(object me)
{
    object ob=this_object();
    tell_object(me,"劝人向善成功，你心里也挺美的。\n");
    bonus(me);
    destruct(ob);
    return 1;
}

int do_huayuan()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("tlnewbiejob/adv2/pin"))
    {
        command("say 这年头，骗子不少啊。");
        return 1;
    }
    if (me->is_busy())
    {
        command("say 要说什么？手忙脚乱的。");
        return 1;
    }
    message_vision("$N向$n叙说天龙寺里需要大笔金钱重塑佛祖金身的事。\n",me,ob);
    me->add_busy(2);
    if (ob->query("pin")!=me->query_temp("tlnewbiejob/adv2/pin"))
    {
        command("say 这年头，骗子不少啊。");
        return 1;
    }
    if (random(10)<7)
    {
        command("say 这年头，骗子不少啊。");
        random_move();
        return 1;
    }
    message_vision("$N道：$n说的对，我老人家应该慷慨解囊了。\n",ob,me);
    command("say 我这就回去解一笔款子去天龙寺。");
    tell_object(me,ob->name()+"转身离开了。\n");
    
    call_out("reward",2,me);
    return 1;
}

int moving()
{
    random_move();
    if (!random(4))
    {
        random_move();
    }
    call_out("moving",60);
    return 1;
}

int dest()
{
    object ob=this_object();
    message_vision("$N见左右无事，就回家去了。\n",ob);
    destruct(ob);
    return 1;
}


