//给alucar画蒙古地图用 Zine
#include <ansi.h>
#include <title.h>
inherit ITEM;	



void create()
{
        set_name(HIC"指南针"NOR,({ "zhinan zhen","zhen"}) );
        set_weight(4000);
        set("unit", "套");
        set("value", 0);
        set("material", "steel");
        set("auto_load", 1);
        set("long", "这是一套指南针。\n");                
        set("no_drop",1);
        set("no_get",1);
		set("zhinanzhen",1);
        setup();
        call_out("check",1);
}

int check()
{
    object ob=this_object();
    object me=environment(ob);
    object env;
    if (me->query("id")!="alucarxy"&&me->query("id")!="zine")
    {
        remove_call_out("check");
        call_out("check",1);
        return 1;
    }
    if (environment(me))
    {
        env=environment(me);
    }
    else
    {
        remove_call_out("check");
        call_out("check",1);
        return 1;
    }
    if (env->query("origin_file")&&ob->query("room")!=file_name(env))
    {
        ob->set("room",file_name(env));
        tell_object(environment(ob),"这里是随机迷宫，可以用getout <方向>走出去，<方向>为迷宫四个出口，只能是east/south/west/north.\n");
        remove_call_out("check");
        call_out("check",1);
        return 1;
    }
    else
    {
        remove_call_out("check");
        call_out("check",1);
        return 1;
    }
}

void init()
{
    
    add_action("do_getout","getout");
    add_action("do_area","area");
    


}

int do_getout(string arg)
{
    object e,origin,me=this_player(),ob;
    if (environment(me))
    {
        ob=environment(me);
    }
    else
    {
        tell_object(me,"无环境\n");
        return 1;
    }
    if (!ob->query("origin_file"))
    {
        tell_object(me,"这里不是迷宫！\n");
        return 1;
    }
    origin=load_object(ob->query("origin_file"));
    if (arg=="east")
    {
        if (origin->query("most_east"))
        {
            e=origin->query("most_east");
            me->move(e);
            tell_object(me,"你来到了迷宫的东面出口。"+HIR+"此处还是迷宫范围，再向外一步离开迷宫，进入固定地图。\n"+NOR);
            return 1;
        }
        else
        {
            tell_object(me,arg+"方向似乎没有出口，试试别的。\n");
            return 1;
        }
    }
    else if (arg=="west")
    {
        if (origin->query("most_west"))
        {
            e=origin->query("most_west");
            me->move(e);
            tell_object(me,"你来到了迷宫的西面出口。"+HIR+"此处还是迷宫范围，再向外一步离开迷宫，进入固定地图。\n"+NOR);
            return 1;
        }
        else
        {
            tell_object(me,arg+"方向似乎没有出口，试试别的。\n");
            return 1;
        }
    }
    if (arg=="south")
    {
        if (origin->query("most_south"))
        {
            e=origin->query("most_south");
            me->move(e);
            tell_object(me,"你来到了迷宫的南面出口。"+HIR+"此处还是迷宫范围，再向外一步离开迷宫，进入固定地图。\n"+NOR);
            return 1;
        }
        else
        {
            tell_object(me,arg+"方向似乎没有出口，试试别的。\n");
            return 1;
        }
    }
    if (arg=="north")
    {
        if (origin->query("most_north"))
        {
            e=origin->query("most_north");
            me->move(e);
            tell_object(me,"你来到了迷宫的北面出口。"+HIR+"此处还是迷宫范围，再向外一步离开迷宫，进入固定地图。\n"+NOR);
            return 1;
        }
        else
        {
            tell_object(me,arg+"方向似乎没有出口，试试别的。\n");
            return 1;
        }
    }
    else
    {
        tell_object(me,"用getout <方向>走出去，<方向>为迷宫四个出口，只能是east/south/west/north.\n");
    }
    return 1;
}

int do_area()
{
    object ob=this_object(),env,me=this_player();
    if (userp(me)&&environment(me))
    {
        env=environment(me);
    }
    if (env->query("outdoors"))
    {
        tell_object(me,env->query("outdoors")+"\n");
        return 1;
    }
    else
    {
        tell_object(me,"无区域信息。\n");
        return 1;
    }
}