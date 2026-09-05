//近身太监
//by Zine
inherit NPC;
#include <ansi.h>
int ask_task();
void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        string color1=color[random(sizeof(color))];
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title", HIM"近身太监"NOR);
	    set("gender", "无性");
        set("age", 20);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 100000);
        set("asked",0);
        set_skill("force", 50);
        set_skill("jiuyin-shengong", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	    set_skill("hand",40);
	    set_skill("pipa-shou",40);
        set_skill("feitian-shenfa", 40);
        set_skill("literate",20);
        map_skill("force", "jiuyin-shengong");
        map_skill("parry", "pipa-shou");
        map_skill("dodge", "feitian-shenfa");
        map_skill("hand","pipa-shou");
	    set("inquiry", ([
	
         "偷东西": (: ask_task :),
         "steal": (: ask_task :),
       
        
        ]));
        setup();
       
}

int ask_task()
{
    object me=this_player();
    object ob=this_object();
   
    if (!me->query("ming/tj/pin"))
    {
        command("say 你到底是什么人？\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        command("say 你、你到底是什么人？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
    if (me->query_temp("mingtasks/dongchang/task")!=1)
    {
        command("say 没事一边凉快着，别烦我！\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/dongchang/task1"))
    {
        command("say 没事一边凉快着，别烦我！\n");
        return 1;
    }
    else
    {
        message_vision("$N看着$n，尖声道：你都知道了？今天看来是不死不休了。\n",ob,me);
        me->delete_temp("mingtasks/dongchang/task1");
        ob->set("asked",1);
        ob->kill_ob(me);
        
        return 1;
    }
}

void unconcious()
{
    object killer;
    object ob=this_object();
    killer = ob->get_damage_origin_object();
    if (killer->query_temp("mingtasks/dongchang/task")==1)
    {
        killer->set_temp("mingtasks/dongchang/task1thief",ob);
        ob->set("gettheif",killer);
    }
    ::unconcious();
    return;
}

void die()
{
    object killer,thing,ob;
    ob=this_object();
    killer = ob->get_damage_origin_object();
    if (killer->query_temp("mingtasks/dongchang/task")==1)
    {
        thing=new(__DIR__"obj/xiaoji");
        thing->move(environment(ob));
        message_vision("$N临死前，身下掉下一件事物。\n",ob);
    }
    ::die();
}
    
