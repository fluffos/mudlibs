// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    if( !arg ) return notify_fail("你要替自己取什么绰号？\n");
    if ( arg == "none" ) 
    {
	me->delete("nickname");
	write("你的绰号已经去掉了。\n");
	return 1;
    }
    if( strwidth(arg) > 80 )
	return notify_fail("你的绰号太长了，想一个短一点的、响亮一点的。\n");

    if( strsrch(arg,"|") >= 0 )
        return notify_fail("绰号中不能含有|字符.\n");
    arg = replace_string(arg, " ", "");
 //替换回车，防止昵称换行  boost
        arg = replace_string(arg, "\n", " ");

	arg = F_NAME->replace_color(arg);


    me->set("nickname", arg + NOR);
    write("Ok.\n");
    return 1;
}
int help(object me)
{
    write("
指令格式 : nick <外号, 绰号>
 
这个指令可以让你为自己取一个响亮的名号或头衔，你如果希望在绰号中
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

$BLK$ - "+BLK+"黑色"+NOR+"		$NOR$ - 恢复正常颜色
$RED$ - "+RED+"红色"+NOR+"		$HIR$ - "+HIR+"亮红色"+NOR+"
$GRN$ - "+GRN+"绿色"+NOR+"		$HIG$ - "+HIG+"亮绿色"+NOR+"
$YEL$ - "+YEL+"土黄色"+NOR+"		$HIY$ - "+HIY+"黄色"+NOR+"
$BLU$ - "+BLU+"深蓝色"+NOR+"		$HIB$ - "+HIB+"蓝色"+NOR+"
$MAG$ - "+MAG+"浅紫色"+NOR+"		$HIM$ - "+HIM+"粉红色"+NOR+"
$CYN$ - "+CYN+"蓝绿色"+NOR+"		$HIC$ - "+HIC+"天青色"+NOR+"
$WHT$ - "+WHT+"浅灰色"+NOR+"		$HIW$ - "+HIW+"白色"+NOR+"
 
"+BNK+"字体闪烁"+NOR+"为$BNK$，
"+REV+"反色"+NOR+"为$REV$,
"+U+"下划线"+NOR+"为$U$,
系统自动会在字串尾端加一个 $NOR$。

用nick none可以去掉你所设置的绰号。
"    );
    return 1;
}
