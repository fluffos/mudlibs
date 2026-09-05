// judge.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要处理谁的什么问题？\n");
	ob = LOGIN_D->find_body(dest);
  if (!ob) return notify_fail("等他上线了再处理吧。\n");
  if (msg == "isrobot_hb")
	{write( ob->name()+"("+ob->query("id")+")"+"被你打上了护镖机器人的标签。" + "\n" NOR);
	ob->set("isrobot/hb",1);
  log_file("reveal",me->name()+"("+me->query("id")+")给"+ob->name()+"("+ob->query("id")+")打上了护镖机器人的标签。@"+ ctime(time())+"\n");
  CHANNEL_D->do_channel(me, "rumor",sprintf("听说%s(%s)被巫师判定为全自动护镖机器人啦！", ob->name(),ob->query("id")));
  }
  else return notify_fail("没有这个标签，请参看help judge。\n");
  return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：reveal <讯息>

这个指令可以用来处理玩家的不正当行为，比如给全自动机器人id加mark。
例如：judge icer isrobot_hb
现有标签列表：
护镖全自动机器人：isrobot_hb
TEXT
	);
	return 1;
}
