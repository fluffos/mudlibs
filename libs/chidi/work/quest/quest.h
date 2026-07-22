#include <ansi.h>

int time_period(int timep, object me,object obj);
int give_quest();
int dest(object ob);

void init()
{
        add_action("give_quest", "mpquest");
}

int give_quest()
{
        mapping quest ;
        object me,obj,xin;
        int j, combatexp, timep,num;
        string tag = "1000000";
        string pai ;
        int score;
        string *menpai = ({
                "日月神教",
                "浣花剑派",
                "杀手楼",
                "雪山寺",
                "红花会",
                "云龙门",
                "姑苏慕容",
                "逍遥派",
                "峨嵋派",
                "昆仑派",
                "少林派",
                "武当派",
                "丐帮",
                "华山派",
                "明教",
                "星宿派",
                "桃花岛",
                "全真教",
                "白驼山派",
                "天龙寺",
                "古墓派",
                "灵鹫宫", 
                "镇南王府",        });
        string *dirfile = ({
                "riyue",
                "huanhua",
                "shashou",
                "xueshan",
                "honghua",
                "yunlong",
                "murong",
                "xiaoyao",
                "emei",
                "kunlun",
                "shaolin",
                "wudang",
                "gaibang",
                "huashan",
                "mingjiao",
                "xingxiu",
                "taohua",
                "quanzhen",
                "baituo",
                "tianlong",
                "gumu",
                "lingjiu",
                "dali",
        });

        string *levels = ({
                        "0",
                        "5000",
                        "50000",
                        "500000",
        });
        me = this_player();
        obj= this_object();

        if(me->query("family/family_name")!=obj->query("family/family_name"))
        {
                command("? "+me->query("id"));
                command("say "+RANK_D->query_respect(me)+"与本派素无来往，此话从何说起？");
                return 1;
        }

        if( me->query_temp("mpquest_finish"))
        {
                if (((int) me->query("task_time")) < time() )
                {
                        tell_object(me,obj->query("name")+"说道：真可惜！你没有在指定的时间内完成！\n");
                        me->delete_temp("mpquest_finish");
                        return 1;
                }
                else me->delete_temp("mpquest_finish");
        }
        else if ( mapp(quest = me->query("mpquest")) )
        {
                if( ((int) me->query("task_time")) > time() )
                        return notify_fail("还是先把你的任务完成吧。\n");
                else
                {
                        message_vision(obj->query("name")+"向$N叹了口气，说道：算了，看来我不应该让你去做这件事。\n", me);
                        score=1+random(quest["score"]/2);
                        tell_object(me,"你对"+me->query("family/family_name")+"的忠诚度降低了"+chinese_number(score)+"点。\n");
                        if(!me->query("score"))
                        me->set("score",0);
                        me->add("score",-score);
                        me->delete("mpquest");
                        return 1;
                }
        }

        if( ((int) me->query("task_time")) > time() )
        {
                message_vision(obj->query("name")+"向$N挥了挥手，说道：暂时没有什么事要做了，你先下去吧。\n", me);
                return 1;
        }

        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                                 num=j;
                                 break;
                        }
        }
        pai=me->query("family/family_name");
        for(j= 0;j<sizeof(menpai);j++)
        {
                if(pai == menpai[j])
                        break;
        }
        pai=dirfile[j];
        tag=levels[num];
        quest = ((string)"/quest/"+pai+"/qlist"+num)->query_quest();
        timep = quest["time"];
      tell_object(me,HIW" "+obj->query("name")+"沉思了一会儿，说道：\n");
        if (!undefinedp(quest["reason"]))
                tell_object(me ,HIW" "+quest["reason"]);
        time_period(timep, me , obj);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』给我。\n" NOR);
        }
        else if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
        }
        else if (quest["quest_type"] == "扫")
        {
        tell_object(me,"去把『"+quest["quest"]+"』打扫一下吧。\n" NOR);
        }
        else if (quest["quest_type"] == "送")
        {
        tell_object(me,"把这封信送给『"+quest["quest"]+"』吧。\n" NOR);
        xin=new("/u/ronger/xin");
        xin->move(me);
        }
        quest["score"]=quest["score"];

        me->set("mpquest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        return 1;
}

int time_period(int timep, object me,object obj)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW" "+"请在" + time + "内");

        return 1;
}

int accept_object(object who, object ob)
{
        int score;
        mapping quest;
        object obj=this_object();

        if( ob->is_character())
        {
        tell_object(who,obj->query("name")+"说道：这不是我想要的。\n");
        return 0;
        }
        if(userp(ob) || !(quest =  who->query("mpquest")))
        {
        tell_object(who,obj->query("name")+"说道：这不是我想要的。\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,obj->query("name")+"说道：这不是我想要的。\n");
        return 0;
        }
        remove_call_out("dest");
        call_out("dest",1,ob);
        who->delete("mpquest");
        who->set_temp("mpquest_finish",1);
        if ((int) who->query("task_time") < time() )
        {
                tell_object(who,obj->query("name")+"说道：真可惜！你没有在指定的时间内完成！\n");
                return 1;
        }
        else
        {
                tell_object(who,obj->query("name")+"说道：恭喜你！你又完成了一项任务！\n");
                score=quest["score"]+random(quest["score"]);
                tell_object(who,"你对"+who->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");
                if(!who->query("score"))
                who->set("score",0);
                who->add("score",score);
                return 1;
        }
}

int dest(object ob)
{
        destruct(ob);
        return 1;
}
