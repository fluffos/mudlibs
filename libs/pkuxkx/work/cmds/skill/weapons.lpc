//高级功夫去道具化，Zine 2012
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object file;
	if (!file=load_object("/d/yingtianfu/neicheng/adv_weapon/"+arg))
	return notify_fail("目前可用的高级兵器功夫只有剑意,刀芒,鞭影,霸斧,枪魂,怒锤,流戟,器灵,匕魔,横杖这十种。\n如不清楚请help weapons。\n");
	return file->act();
}
int help(object me)
{
	tell_object(me,@HELP
指令格式 : weapons + [高级兵器功夫]

可用剑意,刀芒,鞭影,霸斧,枪魂,怒锤,流戟,器灵,匕魔,横杖
等十种高级功夫，命令为weapons +高级兵器功夫拼音，也可
直接用高级功夫拼音来使用。
HELP
        );
	return 1;
}
