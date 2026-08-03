// quest.h
void init()
{
        add_action("give_quest", "quest");
        add_action("stop_quest","unquest");
}
int stop_quest(object me)
{
     mapping quest,fam,obfam;
     me = this_player();
     obfam = query("family");
     if(!(quest =  me->query("quest")))
          return notify_fail("你现在没有任何任务！\n");
     if((int) me->query("task_time") - time() < 0)
          return notify_fail("你现在没有任何任务！\n");
     if (!(fam = me->query("family")) || fam["family_name"] != obfam["family_name"] )
      {
       write(RANK_D->query_respect(me) +"与本派素无来往，不知此话从何谈起？\n");
       return 1;
       }
         if((int)quest["exp_bonus"] * 2 > me->query("score") )
       {
         write(this_object()->query("name")+"说道：未练武，先学做人。在为本派自觉效力方面，\n");
         write(this_object()->query("name")+"说道："+RANK_D->query_respect(me)+"是否还不够勤勉？\n");
              return 1;
        }
       write(this_object()->query("name")+"说道："+RANK_D->query_respect(me)+"对本派尚算忠心，就再给一次机会。\n。");
       me->add("score", -(quest["exp_bonus"] * 2));
       me->delete("quest");
       return 1;
}
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
        string test,name;
        mapping quest;
        name = query("name");
        if(!(quest =  who->query("quest")))
        {
        tell_object(who,name+"说道：这不是我想要的。\n");
        return 0;
        }
        if( (string)ob->query("name") != quest["quest"])
        {
        tell_object(who,name+"说道：这不是我想要的。\n");
        return 0;
        }
        if( ob->is_character() || userp(ob))
        {
        tell_object(who,name+"说道：这不是我想要的。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,name+"说道：真可惜！你没有在指定的时间内完成！\n");
        return 1;
        }
        else
        {
        command("nod");
        tell_object(who,name+"说道：做的很好！继续努力。！\n");
        exp = (quest["exp_bonus"]*2) + random(quest["exp_bonus"]/2)+1;
        if(exp > 300) exp = 300;
        pot = exp / 5 + 1;
        score = (exp+pot)/2;
        who->add("combat_exp",exp);
        who->add("potential",pot);
        who->add("score",score);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n"+
        chinese_number(score) + "点忠诚度\n" NOR);
        who->set("equest",quest);
        who->delete("quest");
                        return 1;
        }
                return 1;
}
int give_quest(string arg)
{
        mapping quest,fam,obfam,equest;
        object me;
        string fammsg,name;
        int j, combatexp, timep, lvl=0,k;
        mixed *local;
        int t;
        string tag="1024000";
       string *levels = ({
 "0",
 "4000",
 "8000",
 "16000",
 "32000",
 "64000",
 "128000",
 "256000",
 "512000",
 "1024000",
});
        name = query("name");
        if( ! arg || !sscanf(arg, "%d", lvl))
        lvl = 0;
        if(lvl<0) lvl=0;
        me = this_player();
       obfam = query("family");
       if (!(fam = me->query("family")) || fam["family_name"] != obfam["family_name"] )
      {
         write(RANK_D->query_respect(me) +"与本派素无来往，不知此话从何谈起？\n");
         return 1;
       }
        if((int)me->query("combat_exp") >= 3500000)
        {
                write("你无需再向"+name+"请任务了！\n");
                        return 1;
        }
        if((int) me->is_ghost())
        {
                write("鬼魂不可要任务．\n");
                return 1;
        }
            if( me->is_busy() )
            {

            write("你现在正忙着呢。\n");
                        return 1;

        }
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
                return 0;
        else
                me->set("qi", me->query("qi")/2+1);
        }
        combatexp = (int)me->query("combat_exp");
        for(j= sizeof(levels)-1 ; j>=0; j--)
        {
              if( atoi(levels[j])  <=  combatexp )
                        {
                           k = random(3);
                           if( j - k < 0 )
                                tag = levels[j];
                           else
                                tag = levels[j - k];
                //       if(j < (sizeof(levels)- lvl)) tag = levels[j+lvl];
                                break;
                        }
        }
        quest = GQUEST_D(tag)->query_quest();
        equest = me->query("equest");
        timep = 600;
        timep = random(timep/2)+timep/2;

        if( quest["quest"] == this_object()->name() )
        {
       tell_object(me,"这个任务有杀师灭祖之嫌，请"+RANK_D->query_respect(me)+"换一个任务吧。\n"NOR);
        return 1;
        }
        if( equest ) {
        if( quest["quest"] == equest["quest"] )
        {
        tell_object(me,"这个任务你刚刚完成，你可以再要其他任务。\n"NOR);
        return 1;
           }
        }
        time_period(timep, me);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』。\n" NOR);
        sysmsg +="找回『"+quest["quest"]+"』。";
        }
                if (quest["quest_type"] == "杀")
        {
        fam = query("family");
        fammsg = fam["family_name"]; 
        tell_object(me,"杀了『"+quest["quest"]+"』，扬我"+fammsg+"威名！\n" NOR);
        sysmsg +="杀了『"+quest["quest"]+"』。";
        }
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) timep);
        message("channel:gab", HIC"【任务频道】"+me->query("name")+"("+me->query("id")+")"+sysmsg+"\n"NOR,users());

return 1;
}

int time_period(int timep, object me)
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

   tell_object(me,HIW + sprintf("%s",this_object()->name()) +"说道：\n请在"+ time + "内");
        sysmsg = "在" + time + "内";
        return 1;
}
