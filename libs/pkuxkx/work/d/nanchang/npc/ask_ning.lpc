#include <ansi.h>
inherit NPC;
int ask_ning();
void init()
{
    object ob = this_object();
    if (!ob->query("inquiry"))
    {
        set("inquiry", ([
			"ningwang" : (: ask_ning :),
            "宁王" : (: ask_ning :),
			
        ]) );
    }
  
}

int cananswer(object ob)
{
    if (ob)
    {
        ob->delete("cantanswer");
    }
}
int ask_ning()
{
    object me=this_player();
    object ob=this_object();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/zongrenfu/task"))
    {
        command("say 你想要我的命吗？");
        return 1;
    }
    if (this_object()->query("cantanswer"))
    {
        command("say 你就是打死我，我也不会说的。");
        me->add_busy(1);
        return 1;
    }
    if (me->query_temp("mingtasks/zongrenfu/ningcount")>=3)
    {
        tell_object(me,"收集到足够的情报，你可以回去把你的判断告诉(gaosu)宗人令了。\n");
        return 1;
    }
    if (random(100)>35)
    {
        command("say 不可说，不可说。");
        me->add_busy(1);
        return 1;
    }
    else
    {
        ob->set("cantanswer",1);
        call_out("cananswer",600,ob);
        if (random(100)>49)
        {
            command("say 宁王要造反，这在南昌早已是众人皆知的秘密了。");
            tell_object(me,"你暗自心惊，赶紧记了下来，以备回报朝廷。\n");
            me->add_temp("mingtasks/zongrenfu/ningcount",1);
            me->add_temp("mingtasks/zongrenfu/ning",1);
            if (me->query_temp("mingtasks/zongrenfu/ningcount")>=3)
            {
                tell_object(me,"收集到足够的情报，你可以回去把你的判断告诉(gaosu)宗人令了。\n");
            }
            return 1;
        }
        else
        {
            command("say 宁王爱民如子，谁造他的谣？");
            tell_object(me,"你微微点头赶紧记了下来，以备回报朝廷。\n");
            me->add_temp("mingtasks/zongrenfu/ningcount",1);
            me->add_temp("mingtasks/zongrenfu/ning",-1);
            if (me->query_temp("mingtasks/zongrenfu/ningcount")>=3)
            {
                tell_object(me,"收集到足够的情报，你可以回去把你的判断告诉(gaosu)宗人令了。\n");
            }
            return 1;
        }
    }
    
}