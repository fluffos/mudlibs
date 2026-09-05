// vote robot
// modified by Mark

#include <net/dns.h>
#include <vote.h> 
#include <ansi.h>

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv; // valid voter numbers
  int vc;  // vote count;
  int df;
  string *juror, my_id,chargeroom;

  if (me == victim)
  {
      if (random(2)) me->add("vote/abuse", 10);
      return notify_fail("你不是开玩笑吧？当心被剥夺表决权！\n");
   }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_ROBOT))
  {
      return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
  }

    if ( victim->query("learn_xiake_gf") )
        return notify_fail(victim->name()+HIG+"正在侠客岛读侠客行，怎么会是机器人？\n");
  if( victim->query("robot_on") ) 
  {
     return notify_fail(victim->name()+HIG+"正在被青狼主法官审讯中。\n");
  }

  if (reason <= 0)
  {
      victim->set("vote/reason", (int)V_ROBOT); 
  }

  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");

  if( !pointerp(juror) )
  {
     victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
     victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
     me->add("vote/abuse", 10);
     return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
  }

  vv = (int) ("/cmds/std/vote")->valid_voters(me)/3;
  vc = victim->add("vote/count",1);

  df = vv - vc;
    if (vv < 3) df=3-vc;

  if (df>0)
  {
      shout( HIG "【表决】"+me->name()+HIG+"投票对" +victim->name()
            +HIG+"进行机器人审讯，还差"+sprintf("%d", df)+"票。\n" NOR);
      write( HIG "【表决】"+me->name()+HIG+"投票对" +victim->name()
            +HIG+"进行机器人审讯，还差"+sprintf("%d", df)+"票。\n" NOR);
      victim->apply_condition("vote_clear", 10);
  } else
  {
      shout( HIG "【表决】"+me->name()+HIG+"投票对" +victim->name()
            +HIG+"进行机器人审讯。"+victim->name()+HIG+"被青狼主法官抓去了！\n" NOR);
      write( HIG "【表决】"+me->name()+HIG+"投票对" +victim->name()
            +HIG+"进行机器人审讯。"+victim->name()+HIG+"被青狼主法官抓去了！\n" NOR);

      victim->apply_condition("vote_clear", -10);
      victim->set("robot_on", 1);
      
      // moving
      tell_room(environment(victim),"天空中伸出一只大手把"+
      (string)victim->query("name")+"抓了起来, 然後不见了.\n", victim);
      tell_object(victim,"一只手把你抓了起来, 你眼前一阵黑....\n");
      
      victim->apply_condition("vote_clear", -10);
  }

  return 1;
}
