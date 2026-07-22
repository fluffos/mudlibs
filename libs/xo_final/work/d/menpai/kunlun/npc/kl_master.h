//  kl_p.h
//  Ffox    98-9-9 14:34

inherit F_NEW_MASTER;
#include <kunlun.h>

mapping *go_where=({
([
    "where"    : "厨房",
    "give_msg" : "白鹿子对$N说道：听厨房大师傅说厨房现在缺人手，你去那儿帮忙吧。",
]),
([
    "where"    : "药房",
    "give_msg" : "白鹿子对$N说道：听药房执事说药房现在缺人手，你去那儿帮忙吧。",
]),
([
    "where"    : "蔬圃",
    "give_msg" : "白鹿子对$N说道：蔬圃现在正是忙的时候，你去帮帮忙吧。"
]),
});

string about_here()
{
    return ("此处是地处昆仑山脉腹地的三圣坳，一直是昆仑派所辖的地盘。");
}

int refuse_killing(object me)
{
    command("heng");
    me->apply_condition("kill_kunlun", 
        me->query_condition("kill_kunlun")+30 );
    return 0;
}

varargs int family_quest(object me, int candone)
{
    string add_level = "canyue/level";
    mapping work;
    int level;
    int last_time;

    if ( !kl_dizi(me) )
    {
        return 0;
    }

    if ( kl_mark("query", me, "kunlun_task/where", 1, 1) )
    {
        //如果有干活的地方
        if ( candone && kl_mark("query", me, "kunlun_task/success", 1, 1) >= 2 )
        {
            //如果成功点数为2奖励
            command("nod " + me->query("id"));
            command("say 听说你这一段时间在那边干得不错啊！");
            me->add("class_score/昆仑派",
                    kl_mark("query",me,"kunlun_task/point", 1, 1) ); 

            add_level += sprintf("%1d", kl_mark("query", me, "kunlun_task/level", 1, 1));
            kl_mark("add", me, add_level, 2, 1);
            kl_mark("add", me, "kunlun_task/level", 1, 1);
        }
        else if ( candone && kl_mark("query", me, "kunlun_task/success", 1, 1) <= -2 )
        {
            //如果成功点数为-2…
            command("shake " + me->query("id"));
            command("say 你真是个好吃懒做的家伙，这么点事都干不好。");
            me->add("class_score/昆仑派",
                    kl_mark("query",me,"kunlun_task/point", 1, 1) );
            kl_mark("add", me, "kunlun_task/level", -1, 1);
        }
        else
        {
            command("angry " + me->query("id"));
            command("say 不是让你到"+
                 kl_mark("query", me, "kunlun_task/where", 1, 1)+"去帮忙吗？");
            return 1;
        }

        if ( candone )
        {
            if ( kl_mark("query", me, "kunlun_task/point", 1, 1) >= 0 )
            {
                write("你的师门忠诚度升高" + chinese_number(
                    kl_mark("query",me,"kunlun_task/point",1,1) )+"点。\n");
            }
            else
            {
                write("你的师门忠诚度下降"+chinese_number(
                    0-kl_mark("query",me,"kunlun_task/point",1,1))+"点。\n");
            }

             kl_mark("delete", me, "kunlun_task/where", 1, 1);
             kl_mark("delete", me, "kunlun_task/point", 1, 1);
             kl_mark("delete", me, "kunlun_task/task_time", 1, 1);
             kl_mark("delete", me, "kunlun_task/success", 1, 1);

             last_time = time();
             kl_mark( "set", me, "last_time", last_time, 1 );
         }

         return 1;
    }

    level = kl_mark("query", me, "kunlun_task/level", 1, 1);//任务等级参数
    if ( level <= 3 )
    {
        if ( level == 0 )
        {
            kl_mark("set", me, "kunlun_task/level", 1, 1);
        }

        work = go_where[random(3)];
        kl_mark("set", me, "kunlun_task/where", work["where"], 1);
        message_vision( work["give_msg"]+"\n", me );

        kl_mark("set", me, "kunlun_task/quest", "到" + work["where"] + "帮忙", 1);
        kl_mark("set", me, "kunlun_task/task_time", time() + 500000, 1);

        return 1;
    }

    last_time = time();
    kl_mark( "set", me, "last_time", last_time, 1 );

    return OLD_QUEST_D->give_oldquest(me, this_object());
}

int have_family_quest(object me)
{
    if ( !kl_dizi(me) )
    {
        return 0;
    }

    if ( kl_mark("query", me, "kunlun_task/where", 1, 1) )
    {
        return 1;
    }

    return OLD_QUEST_D->have_oldquest(me, this_object());
}

void done_family_quest(object me)
{
    if ( kl_mark("query", me, "kunlun_task/where", 1, 1) )
    {
        family_quest(me, 1);
    }

    if ( OLD_QUEST_D->have_oldquest(me, this_object()) )
    {
        OLD_QUEST_D->done_oldquest(me, this_object());
    }
}

void cancel_family_quest(object me)
{
    tell_object(me, this_object()->query("name") + "冷冷地说道：你下去吧，我找其它弟子来做。\n");
    tell_object(me, this_object()->query("name") + "转身叫来一名弟子，吩咐了他几句。\n");
    tell_object(me, "昆仑弟子拱了拱手，匆匆走了出去。\n");

    me->add("class_score/昆仑派", -10);

    if ( kl_mark("query", me, "kunlun_task/where", 1, 1) )
    {
        kl_mark("delete", me, "kunlun_task/where", 1, 1);
        kl_mark("delete", me, "kunlun_task/point", 1, 1);
        kl_mark("delete", me, "kunlun_task/task_time", 1, 1);
        kl_mark("delete", me, "kunlun_task/success", 1, 1);
    }

    if ( OLD_QUEST_D->have_oldquest(me, this_object()) )
    {
        OLD_QUEST_D->cancel_oldquest(me, this_object());
    }
}

