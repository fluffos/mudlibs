//daoju.c 唱戏用的道具
//海洋II（云起云落）
//星星lywin 2000/6/20

#include <ansi.h>
inherit ITEM;
string *msg_biaoyan = ({
      "$P挥舞着手中的长剑，不料手一滑长剑脱手而飞，围观人群纷纷闪躲！\n",
      "$P把剑舞得相当得意，不小心被脚下的石头绊了一跤，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地表演着剑法，浑然忘了周围的观众。\n",
      "舞剑，舞剑，$P正精彩地表演着剑术套路。\n",
      "舞剑，舞剑，$P专心致志地表演着剑术套路。\n",
      "舞剑，舞剑，$P心无杂念地表演着剑术套路。\n",
      "舞剑，舞剑，$P一丝不苟地表演着剑术套路。\n",
      "舞剑，舞剑，$P熟练地表演着剑术套路。\n",
      "舞剑，舞剑，$P英姿飒爽地表演着剑术套路。\n",
      "舞剑，舞剑，$P纯熟地表演着剑术套路。\n",
      "舞剑，舞剑，$P得意地表演着剑术套路。\n",
      "舞剑，舞剑，$P满腔豪情地表演着剑术套路。\n",
      "$P扯着大破锣嗓子没吼几声，就把围观的人都吓跑了！\n",
      "$P正得意地迈着小碎步，不小心被脚下的石头绊了一跤，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地唱着小曲儿，浑然忘了周围的观众。\n",
      "唱曲儿，唱曲儿，$P正精彩地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P专心致志地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P心无杂念地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P一丝不苟地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P熟练地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P万般风情地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P纯熟地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P得意地唱着小曲儿。\n",
      "唱曲儿，唱曲儿，$P满腔豪情地唱着小曲儿。\n",
      "$P像模像样的站稳马步，运气，大喝一声劈掌下去，结果手掌鲜血直流。\n",
      "$P想劈面前的石块，结果劈来劈去劈不中，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地劈着石块，结果越劈越来劲，停不下手了。\n",
      "劈砖，劈砖，$P正精彩地表演着劈砖。\n",
      "劈砖，劈砖，$P专心致志地表演着劈砖。\n",
      "劈砖，劈砖，$P心无杂念地表演着劈砖。\n",
      "劈砖，劈砖，$P一丝不苟地表演着劈砖。\n",
      "劈砖，劈砖，$P熟练地表演着劈砖。\n",
      "劈砖，劈砖，$P英姿飒爽地表演着劈砖。\n",
      "劈砖，劈砖，$P纯熟地表演着劈砖。\n",
      "劈砖，劈砖，$P得意地表演着劈砖。\n",
      "劈砖，劈砖，$P气势不凡地表演着劈砖。\n",
      "$P走在绳索上，一摇一晃，煞是好看。却不料绳索突然松开，$P摔了一个嘴啃泥！\n",
      "$P正得意地在绳索上翻着筋斗，突然一个踏空摔了下来，引起围观人群哄堂大笑。\n",
      "$P旁若无人般地走着绳索，来来回回地走了很多趟，没有停下来的意思。\n",
      "走索，走索，$P精彩地表演着走索儿。\n",
      "走索，走索，$P专心致志地表演着走索儿。\n",
      "走索，走索，$P心无杂念地表演着走索儿。\n",
      "走索，走索，$P一丝不苟地表演着走索儿。\n",
      "走索，走索，$P熟练地表演着走索儿。\n",
      "走索，走索，$P英姿飒爽地表演着走索儿。\n",
      "走索，走索，$P纯熟地表演着走索儿。\n",
      "走索，走索，$P得意地表演着走索儿。\n",
      "走索，走索，$P满腔豪情地表演着走索儿。\n",
    });

void init()
{
	add_action("do_changxi", "biaoyan");
}

void create()
{
	set_name("唱戏道具", ({"changxi daoju", "daoju"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop","不要乱丢，要赔的！\n");
		set("no_put",1);
		set("long", "这是一套唱戏用的道具，你可以用它来表演节目（biaoyan）。\n");
		set("value", 0);
	}
	setup();
}

int do_changxi(string arg)
{
        object me=this_player();

        if(me->is_busy()||me->is_fighting())
        return notify_fail("你正忙着呢。\n");

        if (me->query("obj/done") >= 1)
        {
          tell_object(me,"你已唱完戏了，回去报告吧。\n");
          return 1;
        }
        else
        if (me->query("obj/changxi") < 1)
        {
          tell_object(me,"没有戏院管事的允许，谁都不能在街上表演 ...\n");
          return 1;
        }
        else
        if (!environment(me)->query("outdoors"))
       {
       tell_object(me,"室内不能进行表演。\n");
       return 1;
         }
        else
         if (me->query("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"管事安排你来的不是这个地方吧？\n");
          return 1;
        }
        else
        if ((me->query("jing") < 20))
        {
          tell_object(me,"你的精力不能集中，不可以表演！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"你的身体状态太差，不能表演！\n");
          return 1;
        }
        else
        if ((me->query("jingli") < 30))
        {
          tell_object(me,HIB"\n你的精力不济，需要调整一下才能表演！"NOR"\n\n");
          tell_object(me,CYN"\n你可以用吐纳("HIW"tuna 10"NOR")来获得精力，进一步信息可以查询 "HIW"newbie 吐纳"NOR"。"NOR"\n\n");
          return 1;
        }
        else
	if (environment(me)->query_temp("changxi") >= 1)
        {
        tell_object(me,"刚刚才有人来这儿唱过戏了，人们都不想再看戏。\n"NOR,me);
       	return 1;
      	}
      	else
        if (!arg || arg == "" )
        {
          tell_object(me,"你要进行哪种表演？
          唱曲（changqu），碎砖（suizhuan），走绳索（zousheng），舞剑(wujian)？\n");
          return 1;
        }
        else
        if ( arg == "changqu" )
        {
          if(me->is_busy())
          return notify_fail("你正忙着呢！\n");

           if ((me->query_skill("force",1) < 20))
            return notify_fail("唱曲讲究的是内息悠长，你的基本内功不足，唱不出好曲。\n");
    	if(me->query("per")<16)
        return notify_fail("你长得丑不是你的错。要是你那么丑还唱小曲吓唬人，就是你不对了。\n");

             if(random(3)){
        message_vision(YEL"\n"+msg_biaoyan[12+random(12)]+"\n\n"NOR,me);
          me->start_busy(4+random(2));
            me->add("neili",-(20+random(20)));
         if(me->query("neili") < 0) me->set("neili",0);
          call_out("changqu",6,me);
          return 1;
          }

      if(!random(3)){
              object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",2 * me->query("combat_exp"));
            message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
          return 1;
          }

            message_vision(HIW"\n$N一边拉着胡琴，一边应和着唱着小曲儿。\n\n"NOR,me);
           me->start_busy(6);
            call_out("changqu",6,me);
          return 1;
       	}
       	else
        if ( arg == "suizhuan" )
        {
        if(me->is_busy())
        return notify_fail("你正忙着呢!\n");

           if ((me->query_skill("strike",1) < 20))
            return notify_fail("你的拳脚功夫不足，哪里打得动大石？\n");

          if ((me->query("str") < 16))
            return notify_fail("你一副弱不禁风的样子，就算劈开了石块别人也以为是假的！\n");

          if(random(3)){
             message_vision(RED"\n"+msg_biaoyan[24+random(12)]+"\n\n"NOR,me);
            me->add("qi",-(10+random(10)));
          me->start_busy(4+random(2));
       	  call_out("suizhuan",6,me);
         return 1;
         }
            if(!random(3)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
            message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
            return 1;
}
          message_vision(HIW"$N运功于掌，一声大喝，用力向一个石块劈去。\n"NOR,me);
           me->start_busy(6);
       	  call_out("suizhuan",6,me);
       	  return 1;
       	}
       	else
        if ( arg == "zousheng" )
        {
        if(me->is_busy())
        return notify_fail("你正忙着呢!\n");
           if ((me->query_skill("dodge",1) < 20))
            return notify_fail("以你这样的轻功也想去走绳？怕不一下子就掉了下来。\n");

	  if ((me->query("dex") < 16))
            return notify_fail("你手长腿短，重心偏上，一副笨拙的样子，怎么表演走绳索？\n");

            if(random(3)){
          message_vision(HIY"\n"+msg_biaoyan[36+random(12)]+"\n\n"NOR,me);
          me->start_busy(4+random(2));
          me->add("jingli",-(10+random(20)));
          if(me->query("jingli") < 0) me->set("jingli",0);
       	  call_out("zousheng",6,me);
          return 1;
         }
            if(!random(3)){
            object ob1=new(__DIR__"rascal");
            ob1->move(environment(me));
            ob1->set("combat_exp",me->query("combat_exp"));
            message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
        ob1->kill_ob(me);
        return 1;
}
          message_vision(HIW"$N在绳索上走来走去，表演着复杂而优美的动作。\n"NOR,me);
            me->start_busy(6);
       	  call_out("zousheng",6,me);
       	  return 1;
       	}
        else
        if ( arg == "wujian" )
        {

        if(me->is_busy())
        	return notify_fail("你正忙着呢！\n");

        if ((me->query_skill("sword",1) < 20))
        	return notify_fail("你一点剑法都不会，怎么表演？\n");

        if ((me->query("int") < 16))
        	return notify_fail("你的剑法一点灵气都没有。杀人放火还凑合，表演的话就免了吧。\n");

          if(random(3)){
        	message_vision(YEL"\n"+msg_biaoyan[random(12)]+"\n\n"NOR,me);
        	me->start_busy(4+random(2));
        	me->add("jing",-(10+random(20)));
        	if(me->query("jing") < 0) me->set("jing",0);
          	call_out("wujian",6,me);
        		return 1;
        }

      if(!random(3)){
              object ob1=new(__DIR__"rascal");
          ob1->move(environment(me));
          ob1->set("combat_exp",me->query("combat_exp"));
              message_vision("当$N正要开始表演的时候，人群里突然冲出个小流氓。\n小流氓对$N大声骂道：懂不懂江湖规矩？在老子地盘上混饭吃也不知道孝敬老子！\n",me);
            ob1->kill_ob(me);
            return 1;
        }

          message_vision(HIW"\n$N左手捏了一个剑诀，右手将剑一收，做了一个漂亮的收势。\n\n"NOR,me);
           me->start_busy(6);
          call_out("wujian",6,me);
          return 1;
    }
}

int changqu(object me)
{
        message_vision(HIY"$N一曲唱毕，旁边的人鼓起了掌。\n"NOR,me);
        me->set("obj/done",1);
        environment(me)->set_temp("changxi",1);
         if(!random(6) && me->query("max_neili") < 350)
        {
         me->add("max_neili",1);
	tell_object(me,"\n你感到内息修养有所长进！\n\n");
	}
        me->add("neili",-(30+random(30)));
        if(me->query("neili") < 0) me->set("neili",0);
        return 1;
}

int suizhuan(object me)
{
        message_vision(HIY"$N只见好大的块砖头应声而碎，旁人看得张大口说不出话来。\n"NOR,me);
        me->set("obj/done",1);
        environment(me)->set_temp("changxi",1);
        if(!random(5))
        {
       me->improve_skill("strike",1 + random(10* (me->query("str") + me->query("kar"))));
         tell_object(me,"\n你感到基本掌法有所长进！\n\n");
	}
        me->receive_damage("qi", 10+random(10), "碎砖失手");
        return 1;
}

int zousheng(object me)
{
        message_vision(HIY"$N从绳索上轻轻的走了过去，晃也没晃一下，旁人都看得目瞪口呆。\n"NOR,me);
        me->set("obj/done",1);
        environment(me)->set_temp("changxi",1);
        me->improve_skill("dodge",1 + random(15*(me->query("dex") + me->query("kar"))));
        tell_object(me,"\n你感到基本轻功 有所长进！\n\n");
        me->add("jingli",-(10+random(10)));
        if(me->query("jingli") < 0) me->set("jingli",0);
        return 1;
}
int wujian(object me)
{
        message_vision(HIY"$N舞剑完毕，引来了一阵喝采声。\n"NOR,me);
        tell_object(me,"\n你感到基本剑法有所长进！\n\n");
        me->set("obj/done",1);
        me->improve_skill("sword",1 + random(10* (me->query("int") + me->query("kar"))));
        me->receive_damage("jing", 30+random(30), "舞剑失手");
        environment(me)->set_temp("changxi",1);
        return 1;
}          
