//Zine 艄公，长江边收钱的，钱多船就快

inherit NPC;
#include <ansi.h>
int ask_me();
int adv();
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));	
        set("title", color[random(sizeof(color))]+"日月神教"+color[random(sizeof(color))]+" 引路人"NOR);
        set("gender", "男性");
        set("age", 60+random(10));
        set("str", 20);
        set("dex", 20);
        set("long", "他是日月神教的引路人，负责在各大城市招徕教众。\n");
        set("combat_exp", 2000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("random_npc",1);
        set_skill("unarmed", 10);
        set_skill("force", 10);
        set_skill("sword", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set("inquiry", ([
                "riyue" : (: ask_me :),
                "shenjiao" : (: ask_me :),
                "日月神教" : (: ask_me :),
                "神教" : (: ask_me :),
        ]) );
        set("neili", 200); 
        set("max_neili", 200);
        set("jiali", 1);
        set("chat_chance", 1);
        set("chat_msg", ({
                (:adv:),
        }) );
        set("shen_type",1);set("score",200);setup();
       	carry_object("/clone/armor/cloth")->wear();
}

int adv()
{
    if (random(100)>60&&time()-(int)this_object()->query("time")>600)
    {
        this_object()->set("time",time());
        CHANNEL_D->do_channel(this_object(), "qy", "日月神教广招天下豪杰会盟黑木崖。");
        CHANNEL_D->do_channel(this_object(), "qy", "在下将在"+TASK_D->place_belong(environment(this_object()))+"的"+environment(this_object())->query("short")+"恭候大驾，送人去黑木崖。");
    }
}

int ask_me()
{
    object me=this_player();
    object dache;
    if (me->query("family")&&me->query("family/family_name")!="日月神教")
    {
        command("say 我们神教招人，阁下有意就直接去黑木崖吧。");
        return 1;
    }
    else if (!me->query("family"))
    {
        dache=load_object("/d/nanchang/dache-riyue");
        command("say 我马上找辆大车，把你送去黑木崖。");
        tell_object(me,"你被扶上一辆马车。\n");
        me->move(dache);
        dache->do_qu(me);
        return 1;
    }
    else if (me->query("family/family_name")=="日月神教")
    {
        dache=load_object("/d/nanchang/dache-riyue");
        command("say 兄弟要回教？我这里正好有大车要回去，送你一程吧。");
        tell_object(me,"你坐上了一辆马车。\n");
        me->move(dache);
        dache->do_qu(me);
        return 1;
    }
    else
    {
        command("ah");
        return 1;
    }
}

void kill_ob(object ob)
{
      ob->remove_killer(this_object());
      remove_killer(ob);
}

