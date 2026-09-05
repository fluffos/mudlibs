//shibi.h
//写个.h利于改
int canwu(object me,string skill,string msg)
{
   message_vision("$N正专心观看石壁。\n", me);
   if ( me->query_int() < 35 )
   {
        write("你面对于这‘侠客行’的古诗图解，竭尽心智，试图理解其中包蕴的古往今来最最博大精深的武学秘奥，怎奈终究不能参悟其中十之一二 \n");
        return 1;
   }
   if( (int)me->query("max_jingli")<500)
   {
        write("你精力不够，无法领悟石壁。\n");
        return 1;
   }
   if(  ((int)me->query("jing")<150) || ((int)me->query("qi")<150 ) )
   {
        write("你已经累了，还是休息一会吧。\n");
        return 1;
   }
   if((int)me->query("learned_points")-(int)me->query("potential")<5)
   	return notify_fail("你感觉头痛欲裂,怎么也参悟不出图解上的奥秘.\n");
   message_vision(msg, me);
   me->add("jing",-50);
   me->add("learned_points",5);
   me->improve_skill(skill,(int)(me->query_skill("literate")/5+1));
   return 1;

}
