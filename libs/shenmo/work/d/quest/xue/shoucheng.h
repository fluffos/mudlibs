

string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 300 )
        return ("不敢有劳大驾。");
    if ( me->query("combat_exp") < 100000 )
        return ("我怎么能放心你去呢？");
    if ( me->query("bad") == 0 )
        return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
      int i;
      string bname = who->name()+"的"+who->query("bad/name") + "的头颅";
     
     if ( (string)ob->query("name") != bname )
        return notify_fail("薛仁贵怒道：你竟敢糊弄我！\n");
        
     if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("薛仁贵大怒：不是你杀的也敢拿来,小心我扁你！\n");
                i =who->query("combat_exp");
      who->add("office_number", 1);
      if (i< 1500 ) {
      who->add("combat_exp", who->query("combat_exp")/2000 );
        }
      else { 
      who->add("combat_exp", 1501);
 }
      who->add("potential", 50 + random(100) );
      command("smile");
      command("touch " + who->query("id"));
      tell_object(who,"薛仁贵点点头：不错，应该奖励。\n");
//    message("channel:chat",HIY+"【大唐天朝】薛仁贵(Xue rengui)："+who->query("name")+"杀死了"+who->query("bad/name")+"，功加一等。\n"+NOR,users());
      who->delete("bad");
      return 1;
}

int done_bad()
{
        object who = this_player();
        if ( who->query("bad") == 0 )
        {
                tell_object(who,"你现在没有逃犯要杀啊。\n");
                return 1;
        }
        command("qi");
        command("kick" + who->query("id"));
        tell_object(who,"薛仁贵的样子看起来气冲冲的：你这人，真没用。\n");
        who->delete("bad");
        return 1;
}
        

int do_job()
{      
        object me;
        me = this_player(); 
        
    if( me->query("job/sxy-done")>0)
    {
                tell_object(me,"你必须先把上次的任务报告了以后才能再要任务。\n");
                return 1;
    } 
    else 
    if( me->query("job/sxy")>0)
    {
                tell_object(me,"你已在这儿要过任务了，快去守城。\n");
                return 1;
    } 
    else 
    if( me->query("combat_exp")<500000)
    {
                tell_object(me,"你为朝廷效力之心可表，可是守城不是儿戏，不要丢了性命。\n");
                return 1;
    }

    message_vision(CYN"薛仁贵对$N说道：你这就去吧，为朝廷效力，才是升官捷径者。\n"NOR,me); 
        me->set("job/sxy", 1);
        me->apply_condition("sxy-job", 8);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        int gong,exp,pot,money;
        me = this_player();
        gong = me->query("job/gong");
        exp = gong * 250;
        pot = gong * 100;
        
    if( me->query("job/sxy-done")< 1)
    {
                tell_object(me,"你的任务还没完成呢。\n");
                return 1;
    }

    message_vision(CYN"薛人贵对$N说道：做得不错！为国出力就应如此。\n"NOR,me);
    message_vision(CYN"薛仁贵对$N说道：你总共立了" + gong + "件功。\n"NOR,me);     
    message_vision(CYN"薛仁贵对$N说道：该奖励你" + exp + "点经验，" + pot + "点潜能，"+gong + "点官值。\n"NOR,me);        
    me->add("combat_exp",exp);
    me->add("potential",pot);
    me->add("office_number",gong); //Cigar 在2002.05.14更改去掉silver奖励，并且平衡了pot&exp与逃犯的之间差！
    me->delete("job/gong");
    me->delete("job/sxy");
    me->delete("job/sxy-done");
    return 1;
}
