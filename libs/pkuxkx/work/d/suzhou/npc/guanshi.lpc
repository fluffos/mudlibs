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
         ([ "changxi":"平西王府","where":"pingxiwangfu"  ]),
         ([ "changxi":"杀手帮","where":"pker"]),
         ([ "changxi":"大理","where":"dali"   ]),
         ([ "changxi":"华山村","where":"xxx" ]),
         ([ "changxi":"泉州","where":"quanzhou"]),
         ([ "changxi":"襄阳","where":"xiangyang"]),
         ([ "changxi":"灵州","where":"lingzhou"]),
         ([ "changxi":"苏州","where":"suzhou"]),
         ([ "changxi":"全真派","where":"quanzhen"]),
         ([ "changxi":"华山","where":"xx"]),
         ([ "changxi":"武当山","where":"wudang"]),
         ([ "changxi":"归云庄","where":"guiyunzhuang"]),
         ([ "changxi":"桃花岛","where":"taohuadao"]),
         ([ "changxi":"峨眉山","where":"emei"]),
         ([ "changxi":"白驼山","where":"baituo"]),
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
                "他是苏州戏院的管事。\n");
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

        set("shen_type",1);set("score",200);setup();
        carry_object("/clone/armor/cloth")->wear();
}
int do_gongzuo()
{
        mapping changxi,changxiwhere;
        object me,ob;
        string family;
        string *familys=({"丐帮","全真派","天龙寺","古墓派","日月神教","桃花岛","峨嵋派","明教","华山派","少林派","武当派","星宿派"});
        me=this_player();
        family=me->query("family/family_name");
        if (member_array(family,familys)!=-1)
        {
            tell_object(me,"你想起之前师门给你的教诲，决定早早回去给师门做事。\n");
            return 1;
        }
    if( me->query("obj/changxi")>0)
    {
                tell_object(me,"快去表演吧。\n");
                return 1;
    }
    else
    if( me->query("combat_exp")>100000)
    {
                tell_object(me,"你已经很厉害了，这种工作不合适你做了。\n");
                return 1;
    }
    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(CYN"管事对$N说道：你去" + changxi["changxi"] + "表演一下吧。\n"NOR,me);
    message_vision("管事吩咐手下给了$N一套"CYN"表演道具"NOR"。\n",me);

        me->set("obj/changxi", 1);
        me->set("obj/where",changxiwhere);
        ob=new(__DIR__"obj/daoju");
        ob->move(me);
        return 1;
}

int ask_done()
{

        object me,ob;
        int pot, exp, money;
        me = this_player();

    if( me->query("obj/changxi")< 1)
    {
                tell_object(me,"你来我这儿要过任务？。\n");
                return 1;
    }
    if( me->query("obj/done")< 1)
    {
                tell_object(me,"还没表演你就以为自己完成了？快去表演吧。\n");
                return 1;
    }
    message_vision(CYN"管事对$N说道：做得不错！给你些奖励吧。\n"NOR,me);
    pot = 5 + random(10);
    exp = 10 + random(80);
    money = (10 + random(30))*100;
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->delete("obj");
    me->add("balance",money);
    tell_object(me,"你的经验增加了" + chinese_number(exp) +"点。\n你的潜能增加了" + chinese_number(pot) +"点。\n你得到了"+ chinese_number(money/100) + "两银子存款的奖励。\n");
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("管事把唱戏道具收了回去！\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}
void destroying(object obj)
{
	destruct(obj);
	return;
}
int accept_object(object me, object obj)
{
		object ob = this_player();
                object daoju;
                if(ob->query("obj/changxi"))
		{
                      if(obj->query("money_id") && obj->value() >= 1000)
             		{
				message_vision("$N叹道：罢了罢了，这么点小事都办不成！\n", this_object());
                   		ob->delete("obj");
                             if (objectp(daoju = present("changxi daoju", this_player())) )
                           {
                                message_vision("管事把唱戏道具收了回去！\n",me);
                                destruct(daoju);
                           }
                           call_out("destroying",1,obj);
                           return 1;
                	}
		}
		command( "say 你给我这东西做什麽？" );
		return 0;
}
