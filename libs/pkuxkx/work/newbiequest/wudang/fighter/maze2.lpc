// milin3.c 密林
// seagate@pkuxkx 路径动态更新

inherit ROOM;
inherit F_VIRTUAL;

void create()
{
  set("outdoors", 1);
  set("no_cleanup",1);
  set("no_reset",1);
	setup();
}

void init()
{
	object tf;
	object me=this_player();
	
	if ( userp(me) &&
		   me->query_temp("quest_fighter") &&
		   time() - me->query_temp("quest_fighter/fight_stime")>=360 )
  {
  	tell_object(me, "你在小树林里面待了太长时间，引起了树林里面的土匪头目的怀疑。\n你寡不敌众被抓到土匪窝里。\n");
  	if ( living(me) )
  	{
  	  me->start_busy(10);
  	  me->move(__DIR__"jianyu");
  	}
  }	
//50%的几率刷新土匪
	if(userp(me)&&
		 random(100)%4<2&&
		 me->query("family/family_name")=="武当派") {
		tf=new(__DIR__"npc/tufei");
		tf->reset_stat(me);
		tf->move(this_object());
		tf->kill_ob(me);
		me->kill_ob(tf);
		tell_room(this_object(), "土匪一声大喊: 此山是我开，此树是我栽，若要从此过，留下买路财 !\n");
	}
}

int valid_leave(object me,string dir)
{
	object tf;
	
  if((tf=present("tu fei",this_object()))&&living(tf)&&tf->query("uni_target")==me)
  	return notify_fail("土匪把路一挡，狞笑道：怎么，想溜，没那么容易！\n");
  else 
  	return ::valid_leave(me, dir);
}
  	