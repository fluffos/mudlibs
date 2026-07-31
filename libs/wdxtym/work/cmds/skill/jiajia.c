// abandon.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;
	string skill;
	int queren;


	if (! arg || arg == ""||!me->query("exp301"))
		return notify_fail("？？？\n");

	if(sscanf(arg,"%s %d %d",skill,lvl,queren)==3)
	{
		if(lvl<1)
			return notify_fail("增加单位至少需要大于零 。。。\n");
	}
	else if(sscanf(arg,"%s %d",skill,lvl)==2)
	{

	if (skill == "exp"&& lvl>0 && lvl<100000 && me->query("exp301")>lvl)
	  {
		tell_object(me,"你喃喃的念叨：天灵灵，地灵灵，各路神仙快显灵！"NOR"\n");
		//me->start_busy(1);
		me->add("exp301", -lvl);
		me->add("combat_exp", lvl);
	      log_file("static/jialian", sprintf("%s：%s("+me->query("id")+")加了%d个%s。\n",ctime(time()),me->query("name"),lvl,skill ));
	      if (me->query("exp301")<1000) {
		  me->delete("exp301");
		  tell_object(me,HIR"你的灵力用完了！"NOR"\n");
              }
		return 1;
	  }
	return notify_fail("你好像觉得那里有些不对劲！！\n");
   }

}

