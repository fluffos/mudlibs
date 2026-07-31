// vote jail
#include <command.h> 
#include <vote.h> 
#include <ansi.h>

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  int i;
  string *juror, my_id;
  object *inv;

  if ( !wizardp(me) && wizardp(victim) )
    return notify_fail("你不可以把巫师投进监狱!\n");

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("你不是开玩笑吧？当心被剥夺表决权！\n");
  }

  if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_CHBLK))
  {
  	return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");
  }

  if( victim->query("xkx_jail") ) 
  {
  	return notify_fail(victim->name()+"已经被关在刑部大牢里了。\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_CHBLK); 
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

  vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 4) df = 4 - vc;

  if (df>1)
  {
	shout( HIG "【表决】"+me->name()+"投票将" +victim->name()
			+"送往刑部大牢，还差"+sprintf("%d", df)+"票。\n" NOR);
	write( HIG "【表决】"+me->name()+"投票将" +victim->name()
			+"送往刑部大牢，还差"+sprintf("%d", df)+"票。\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
	shout( HIG "【表决】"+me->name()+"投票将" +victim->name()
			+"送往刑部大牢。"+victim->name()+"已经被送往刑部大牢了！\n" NOR);
	write( HIG "【表决】"+me->name()+"投票将" +victim->name()
			+"送往刑部大牢。"+victim->name()+"已经被送往刑部大牢了！\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(victim, inv[i]);
	}
	victim->set("block_time", 36000);
	victim->move("/clone/misc/laofang");
  } 
  
  return 1;
}

