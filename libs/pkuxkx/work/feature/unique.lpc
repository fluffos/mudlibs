// unique.c

#include <ansi.h>
#include <dbase.h>

inherit F_ONEOWNER;

nosave int compare_number = -1;
// mon 4/5/98

int query_unique() { return 1; }
int query_compare_number() { return compare_number; }

// This function returns the number of objects in the mud
varargs int query_number() { 
   int  num;

   num = sizeof(filter_array(children(file_name(this_object())), (:clonep:)));
   return num;
}

// This function sets the compare_number (used by /std/char/npc )
void set_compare_number()
{
   compare_number = 1;
}

void reset_compare_number()
{
   compare_number = -1;
}

// This function returns 1 if the object is already in mud
varargs int in_mud()
{
   if(compare_number<0) compare_number=1;
   // mon 4/5/98, set default number.

   if( query_number() >= compare_number )
   // mon 4/5/98 changed > to >= and modified 
   //  /std/char/npc.c accordingly.
	  return 1;
   return 0;
}

// This function returns the original file if in_mud() return 0
// or return replace_file.
varargs string clone_file()
{
   string rev;
   object me = this_object();

   if( !in_mud() )
	  return file_name(me);
   else   {
	  if( stringp(rev=me->query("replace_file")) )
		 return rev; 
      return ""; 
   }
}

void rob_ob(int interval, object ob)
{
  object robber,room; 
  int i;
	object owner = environment(ob);
	while (owner && !userp(owner))
		owner = environment(owner);	//循环判断外层环境,以防放在其他物品内
	call_out("rob_ob",random(interval*2),interval,ob);
	if (!owner)	//没环境,继续call_out,等待自己被消灭
		return;
        if (wizardp(owner)) return; //不抢夺wiz的 
	//产生劫匪来抢夺
	room = environment(owner);  
  	message_vision(HIR"忽然暗地里窜出蒙面人，阴笑道：“听说" + ob->query("name") + HIR + "在你手上，给大爷交出来罢！”\n" NOR, owner); 
  
  switch(random(5))
  {
  	case 0:
  robber=new("/clone/npc/robber/robber0");
  break;
  	case 1:
  robber=new("/clone/npc/robber/robber1");
  break;
  	case 2:
  robber=new("/clone/npc/robber/robber2");
  break;
  	case 3:
  robber=new("/clone/npc/robber/robber3");
  break;
  	case 4:
  robber=new("/clone/npc/robber/robber4");
  break;
  }
  robber->set("rob_unique",1);
    robber->set("uni_target",owner);
    robber->set("name","蒙面人");
    robber->set("id","robber");
    robber->set("sp",1);//防止再叫帮手
  robber->do_change(owner);
  robber->set_leader(owner);
  robber->move(room);
   robber->fight_ob(owner);
  robber->checking(robber,owner);
}
//稀有物品如果为玩家所有,则每隔随机参数时间出现robber抢夺
void check_robber()
{
	object ob=this_object();
	int robpending = this_object()->query("robpending");
	int robinterval = this_object()->query("robinterval");
	if (!robinterval)
                robinterval = 5400;     //如果物品上没有设置抢夺间隔,缺省为约一个半小时抢一次
	if (!robpending)
	{
		this_object()->set("robpending",1);
		call_out("rob_ob",random(robinterval*2),robinterval,ob);
	}
}
	
//only the first user owner can own this unique items.
// can't give it to others.
void init()
{
  check_owner();
  check_robber();
}
