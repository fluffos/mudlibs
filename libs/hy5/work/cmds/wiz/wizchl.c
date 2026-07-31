// wizchl.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) return notify_fail("你想要说什么？\n");
        shout(HIC+"【江湖通知】"HIY+HBBLU+ me->name() +"(" + me->query("id") +")"+"：" +HIY+HBBLU+ arg + "\n" + NOR);
//if (me->query("id")!="hxsd")
//{
//     write(HIC+"【江湖通知】"HIY+HBBLU+ me->name() +"(" + me->query("id") +")"+"：" +HIY+HBBLU+ arg + "\n" + NOR);
//}
        write(HIC+"【江湖通知】"HIY+HBBLU+ me->name() +"(" + me->query("id") +")"+"：" +HIY+HBBLU+ arg + "\n" + NOR);
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : wizchl <讯息>
 
这个指令是巫师专用的.而且是高亮显示，非常
cool。sj的wiz也用这个。hoho。wizard以上
等级的巫师可以使用。
 

HELP
    );
    return 1;
}
 
