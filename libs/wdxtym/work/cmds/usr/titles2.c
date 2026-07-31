// special

#include <ansi.h>
#define TITLE_D "/adm/daemons/titled.c"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	mapping ss;
	string title;
	object ob;
	string pro,sname;
	int i;
	
	if (wizardp(me) && stringp(arg) &&
	    objectp(ob = find_player(arg)))
		// 查看其他玩家的特殊技能
		arg = 0;
	else
		ob = me;

	pro = (ob == me) ? "你" : ob->name(1);

	if (! ob->query("born"))
		return notify_fail(pro + "还没有出生呐，哪里有什么成就呢？\n");
	 
     if (! mapp(ss = ob->query("titles"))|| ! sizeof(ss))
		 	return notify_fail(pro + "现在好像什么成就都没有哦，继续加油吧。\n");
		
			if(arg && (ob == me))
		{
          if(me->is_busy())
          return notify_fail("你现在忙着呢，不能更改成就\n");
	      title = arg;
		  if (!ss[title])
			  return notify_fail("你好像没有这个成就。\n");
		  else
			   TITLE_D->use_title(me,title);
	      return 1;
        }
	      return 1;
     	}
int help(object me)
{
write(@HELP
指令格式 : titles2 <title>

使用这条命令可以佩戴你拥有的成就。

HELP );
    return 1;
}
