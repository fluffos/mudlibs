//modify by gudu October 02
//shibi.h
//写个.h利于改
int canwu(object me,string skill,string msg,int times)
{
   int realtimes,i;
   string fail_msg;
   
        if (times < 1)
          return notify_fail("你至少要读一次！\n");
   message_vision("$N正专心观看石壁。\n", me);
   if ( me->query_int() < 35 )
   {
        write("你面对于这‘侠客行’的古诗图解，竭尽心智，试图理解其中包蕴的古往今来最最博大精深的武学秘奥，怎奈终究不能参悟其中十之一二 \n");
        return 1;
   }
//        if(!me->is_busy()) return 0;
   if( (int)me->query("max_jingli")<100)
   {
        write("你精力不够，无法领悟石壁。\n");
        return 1;
   }
   if((int)me->query("jing")<150
     ||(int)me->query("neili")<150
    ||(int)me->query("qi")<150)
   {
        write("你已经累了，还是休息一会吧。\n");
        return 1;
   }

   realtimes = times;
   fail_msg = "";
   if (me->query("jing")/50 < times)
   {
   	realtimes = me->query("jing")/50;
   	fail_msg = "你已经累了，还是休息一会吧。\n";
   }
     if ((me->query("neili")-150)/5 < realtimes)
   {
   	realtimes = me->query("neili")/5;
	fail_msg = "你内力不足，无法依照石壁内容行功参悟。\n";
   }
   message_vision(msg, me);
   me->receive_damage("jing",50*realtimes);
   me->add("neili",-5*realtimes);
   me->improve_skill(skill,(int)(me->query_skill("literate",1)/6+1)*realtimes);
   if (fail_msg != "") tell_object(me,fail_msg);
   return 1;

}


