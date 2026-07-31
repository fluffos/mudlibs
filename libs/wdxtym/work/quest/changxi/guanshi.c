//侠客行100海洋版II（云起云落）
// guanshi.c 襄阳戏院管事
//星星lywin 2000/6/21

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();

mapping *changxi = ({
         ([ "changxi":"扬州","where":"city"   ]),
         ([ "changxi":"北京","where":"beijing"  ]),
         ([ "changxi":"成都","where":"chengdu"]),
         ([ "changxi":"大理","where":"dali"   ]),
         ([ "changxi":"佛山","where":"foshan" ]),
         ([ "changxi":"泉州","where":"quanzhou"]),
         ([ "changxi":"杭州","where":"hangzhou"]),
         ([ "changxi":"灵州","where":"lingzhou"]),
         ([ "changxi":"苏州","where":"suzhou"]),
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
        set_name("管事", ({"guan shi", "guan"}));
        set("gender", "男性");
        set("age", 25);
        set("long",
                "他是襄阳戏院的管事。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);

        set("combat_exp", 1500);
        set("score", 200);

        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "完成" : (: ask_done    :),
                "报酬" : (: ask_done    :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}
int do_gongzuo()
{
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player();

    if( me->query_temp("obj/changxi")>0)
    {
                tell_object(me,"快去表演吧。\n");
                return 1;
    }
    else
    if( me->query("combat_exp")>1000000)
    {
                tell_object(me,"你已经很利害了，这种工作不合适你做了。\n");
                return 1;
    }
    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(CYN"管事对$N说道：你去" + changxi["changxi"] + "的大街上表演一下吧。\n"NOR,me);
        me->set_temp("obj/changxi", 1);
        me->set_temp("obj/where",changxiwhere);
        ob=new(__DIR__ "daoju");
        ob->move(me);
        return 1;
}

int ask_done()
{

        object me,ob;
        me = this_player();

    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"你曾来我这儿要过任务？。\n");
                return 1;
    }
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"还没表演你就以为自己完成了？快去表演吧。\n");
                return 1;
    }
    message_vision(CYN"管事对$N说道：做得不错！给你些奖励吧。\n"NOR,me);
    me->add("combat_exp",800+random(300));
    me->add("potential",500+random(200));
    me->delete_temp("obj");
    ob=new("/clone/money/silver");
    ob->set_amount(5+random(20));
    ob->move(me);
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("管事把唱戏道具收了回去！\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}