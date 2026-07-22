#include <ansi.h>

varargs int family_quest(object me, int candone)
{ 
    string *quest_place = ({"厨房", "磨房", "菜园"});
    int now_place;
    int now_time;
    int use_time;
    int add_class_score;

    if ( me->query("family/family_name") != "青城派" ) // 非我青城弟子
    {
        return 0;
    }

    if ( me->query("class_score/青城派") <= 900 ) // 一般性的任务
    {
        if ( me->query("xli_marks/do_renwu") ) // 正在作着renwu呢！
        {
            now_place = me->query("xli_marks/renwu_where");
            tell_object(me, this_object()->query("name") + "说道：不是叫你到"+quest_place[now_place-1]+"去干活吗？\n");
            return 1;
        }

        if ( me->query("xli_marks/finish_renwu") )  // 作完上一个了
        {
            if ( candone )
            {
                me->delete("xli_marks/finish_renwu");
                now_time = time();

                use_time = now_time - me->query("xli_marks/renwu_time");  // 检查用的时间
                me->set("xli_marks/can_do_renwu", 1);

                // todo:在这里加入增加门忠的一段程序
                add_class_score = 6 - (int)(use_time / 60);
                if ( add_class_score < 0 )
                {
                    add_class_score = 0;
                }
                if ( add_class_score )
                {
                    tell_object(me, this_object()->query("name") + "说道：好徒儿，为师没有白收你！\n");
                    tell_object(me, this_object()->query("name") + "说道：你对我青城派真是忠心耿耿啊！\n");
                    me->add("class_score/青城派", add_class_score );
                }
                else
                {
                    tell_object(me, this_object()->query("name") + "说道：这么一点小事都办得如此拖沓，你真是......\n");
                }

                me->delete("xli_marks/renwu_where");
                me->delete("xli_marks/do_renwu");
            }
            else
            {
                tell_object(me, this_object()->query("name") + "说道：好徒儿，你的任务还没交差呢！\n");
            }

            return 1;
        }

        if ( me->query("xli_marks/can_do_renwu") ) // 可以做
        {
            me->delete("xli_marks/can_do_renwu");
            now_place = random(sizeof(quest_place)) + 1;

            me->set("xli_marks/do_renwu", 1);
            me->set("xli_marks/renwu_where", now_place);
            me->delete("xli_marks/have_pin");

            tell_object(me, this_object()->query("name") + "说道：好徒儿，既然你想为我青城效力，为师就让你做一点事吧！\n");
            tell_object(me, this_object()->query("name") + "说道：现在"+quest_place[now_place-1]+"正缺人手，你就到那里去帮忙吧！\n");

            command("smile " + me->query("id"));
            me->set("xli_marks/renwu_time", time());  // 计时开始
            return 1;
        }
    }
    else // 其它任务
    {   
/*
        if ( me->query("class_score/青城派") < 900 )
        {
            if ( me->query("xli_marks/higher_renwu") ) // 正在做
            {
                if ( me->query("xli_marks/higher_finish") ) // 做完了
                {
                    // 不判断时间，这些quest其实是让你到处去看看，熟悉一下各个地形用的。:)
                    tell_object(me,"司马卫笑道：好徒儿，你对我青城真是忠心耿耿啊！\n");
                    me->add("class_score/青城派", 15);
                    me->delete("xli_marks/higher_finish");
                }
                else
                {
                    tell_object(me, "司马卫生气地看了你一眼，说道：跑一趟路这种小事都干不好，你真是干不成大事的人！\n");
                    tell_object(me, "司马卫冷冷地说道：你下去吧，我找其它弟子来做。\n");
                    tell_object(me, "司马卫转身叫来一名弟子，吩咐了他几句。\n");
                    tell_object(me, "青城弟子拱了拱手，匆匆走了出去。\n");
                    me->add("class_score/青城派", -10);
                }

                me->delete("xli_marks/higher_renwu");
                return 1;
            }
            else   // 开始给任务了
            {  
                me->set("xli_marks/ling_lufei", 1); // 可以去领一回路费                
                me->set("xli_marks/higher_finish", 1);
                tell_object(me, "司马卫说道：看你心术不正，就不用你去送蟠桃。\n");
                return 1;
             }
        }
        else
*/
        {
            // 靠修道涨忠诚度的时候到了。:)
            tell_object(me, this_object()->query("name") + "捋了一下胡子，说道：你对我青城派的忠心耿耿，为师心里有数。\n");
            tell_object(me, "你也不用再作什么琐碎的事情了！\n");
            tell_object(me, "我道教中人，还是应该多多修道为上，你可不要荒废了正道啊！\n");
            tell_object(me, this_object()->query("name") + "慈祥地看着你，目光中充满赞赏和关爱！\n");
            return 0;
        }  
    }

    //tell_object(me, "司马卫说道：现在没有任务......\n");
    return 0;
}

int have_family_quest(object me)
{
    if ( me->query("family/family_name") != "青城派" ) // 非我青城弟子
    {
        return 0;
    }

    if ( me->query("xli_marks/do_renwu") || me->query("xli_marks/finish_renwu") || me->query("xli_marks/higher_renwu") ) // 正在作着renwu呢！
    {
        return 1;
    }

    return 0;
}

void done_family_quest(object me)
{
    family_quest(me, 1);
}

void cancel_family_quest(object me)
{
    tell_object(me, this_object()->query("name") + "冷冷地说道：你下去吧，我找其它弟子来做。\n");
    tell_object(me, this_object()->query("name") + "转身叫来一名弟子，吩咐了他几句。\n");
    tell_object(me, "青城弟子拱了拱手，匆匆走了出去。\n");
    me->add("class_score/青城派", -10);

    me->delete("xli_marks/now_thing");
    me->delete("xli_marks/renwu_where");
    me->delete("xli_marks/do_renwu");
    me->delete("xli_marks/higher_renwu");
    me->set("xli_marks/can_do_renwu", 1);
}

