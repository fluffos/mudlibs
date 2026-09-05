// 弟子by Zine newbie job HS
inherit NPC;
#include <ansi.h>

int bugen(object me);
int ask_gen();

void create()
{
        int i= random(2);
        string * pre=({"大","二","三","四","五","六","七","八","九","十","十一","十二","十三","十四","十五","十六","十七","十八",});
        string * pre2=({"长","二","三","四","五","六","七","八","九","十","十一","十二","十三","十四","十五","十六","十七","十八",});
        set("gender", i?"男性":"女性");
        if (query("gender")=="男性")
        {
            set_name(pre[random(sizeof(pre))]+"皇子",({"huang zi","huangzi","prince"}));
        }
        if (query("gender")=="女性")
        {
            set_name(pre2[random(sizeof(pre2))]+"公主",({"gong zhu","gongzhu","princess"}));
        }
        set("long",
"这是一位皇室贵胄。\n");
        set("age", 10+random(10));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 2000);
        set("score", 100);
        
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("sword", 20);

         set("inquiry", ([
        "gen":   (: ask_gen() :),
        "跟随":   (: ask_gen() :),
        "学习":   (: ask_gen() :),
		
      ]));
        setup();
        carry_object("/d/yingtianfu/neicheng/obj/h_cloth")->wear();
        
}

void init()
{
    add_action("do_jiaodao","jiaodao");
}


int do_jiaodao()
{
    object ob=this_object();
    object me=this_player();
    int n=1+random(5);
    if (me->query_temp("mingtasks/zhanshifu/task")!=1)
    {
        return 0;
    }
    if (!living(ob))
    {
        tell_object(me,"很明显"+ob->name()+"现在无法被教导。\n");
        return 1;
    }
    if (me->query("id")!=ob->query("owner"))
    {
        tell_object(me,ob->query("name")+"转过了头去，根本不理睬你。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (base_name(environment(me))!="/d/yingtianfu/neicheng/zanshi")
    {
        tell_object(me,"这里人多嘈杂，不是个合适的教导场所。\n");
        return 1;
    }
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/zhanshifu/jd_degree")>10)
    {
        tell_object(me,ob->query("name")+"已经大体上掌握宫廷礼仪，你可以复命了。\n");
        message_vision("$N对$n拱手行了次礼，$n打起仪仗回宫去了。\n",me,ob);
        destruct(ob);
        return 1;
    }
    if (me->query_temp("mingtasks/zhanshifu/jd_degree")>50)
    {
        tell_object(me,ob->query("name")+"已经大体上掌握宫廷礼仪，你可以复命了。\n");
        message_vision("$N对$n拱手行了次礼，$n打起仪仗回宫去了。\n",me,ob);
        destruct(ob);
        return 1;
    }
    if (ob->query("gender")=="男性")
    {
        message_vision(HIY"$N开始教导$n历史上的为君之道。\n"NOR,me,ob);
    }
    if (ob->query("gender")=="女性")
    {
        message_vision(HIM"$N开始教导$n女红以及宫廷各项规矩。\n"NOR,me,ob);
    }
    me->add_busy(1+random(2));
    me->add_temp("mingtasks/zhanshifu/jd_degree",2+random(2));
    if (random(100)>85)
    {
        bugen(me);
    }
    return 1;
}

int gen(object me)
{
    command("follow "+me->query("id"));
    return 1;
}

int ask_gen()
{
    object ob=this_object();
    object me=this_player();
    if (me->query_temp("mingtasks/zhanshifu/task")!=1)
    {
        return 0;
    }
    if (me->query("id")!=ob->query("owner"))
    {
        tell_object(me,ob->query("name")+"转过了头去，根本不理睬你。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (random(1000)>950)
    {
        bugen(me);
    }
    if (random(100)<55)
    {
        message_vision("$N道：休息一会行不行啊？人家难得出宫一次。\n",this_object());
        return 1;
    }
    message_vision("$N道：好吧，好吧，我跟你回去还不行吗？\n",this_object());
    me->add_busy(random(2));
    gen(me);
    return 1;
}
int bugen(object me)
{
    object ob=this_object();
    int i;
    command("follow none");
    ob->move("/d/yingtianfu/neicheng/yudao3");
    for (i=0;i<random(3)+5;i++)
    {
        random_move();
    }
    message_vision(HIW"$N趁$n不注意，一溜烟不知道逃到哪里玩去了。\n",ob,me);
    
    return 1;
}