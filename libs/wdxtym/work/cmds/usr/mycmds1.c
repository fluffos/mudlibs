// mudage.c
//[xiaojl 1999/11/20 海洋II]

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int min, hrs, day, mon, age;
		string sec;
        string out_str;
    	sec = sprintf(HIY"  『 迷宫探险 』 "NOR"\n");
if (!me->query("migong/lev1"))
    	sec += sprintf(HIR"  迷宫第 一 层 『未完成』    "NOR" \n");
else
    	sec += sprintf(HIC"  迷宫第 一 层 『 完成 』  "NOR"   \n");
if (!me->query("migong/lev2"))
    	sec += sprintf(HIR"  迷宫第 二 层 『未完成』  "NOR"   \n");
else
    	sec += sprintf(HIC"  迷宫第 二 层 『 完成 』    "NOR"  \n");
if (!me->query("migong/lev3"))
    	sec += sprintf(HIR"  迷宫第 三 层 『未完成』   "NOR"   \n");
else
    	sec += sprintf(HIC"  迷宫第 三 层 『 完成 』   "NOR"   \n");
if (!me->query("migong/lev4" ))
    	sec += sprintf(HIR"  迷宫第 四 层 『未完成』   "NOR"   \n");
else
    	sec += sprintf(HIC"  迷宫第 四 层 『 完成 』 "NOR"\n");
if (!me->query("migong/lev5"))
    	sec += sprintf(HIR"  迷宫第 五 层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第 五 层 『 完成 』    "NOR"  \n");
if (!me->query("migong/lev6"))
    	sec += sprintf(HIR"  迷宫第 六 层 『未完成』 "NOR"     \n");
else
    	sec += sprintf(HIC"  迷宫第 六 层 『 完成 』    "NOR"  \n");
if (!me->query("migong/lev7"))
    	sec += sprintf(HIR"  迷宫第 七 层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第 七 层 『 完成 』    "NOR"  \n");
if (!me->query("migong/lev8"))
    	sec += sprintf(HIR"  迷宫第 八 层 『未完成』   "NOR"   \n");
else
    	sec += sprintf(HIC"  迷宫第 八 层 『 完成 』  "NOR"    \n");
if (!me->query("migong/lev9"))
    	sec += sprintf(HIR"  迷宫第 九 层 『未完成』   "NOR"   \n");
else
    	sec += sprintf(HIC"  迷宫第 九 层 『 完成 』 "NOR"     \n");
if (!me->query("migong/lev10"))
    	sec += sprintf(HIR"  迷宫第 十 层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第 十 层 『 完成 』   "NOR"   \n");
if (!me->query("migong/lev11"))
    	sec += sprintf(HIR"  迷宫第十一层 『未完成』 "NOR"     \n");
else
    	sec += sprintf(HIC"  迷宫第十一层 『 完成 』  "NOR"    \n");
if (!me->query("migong/lev12"))
    	sec += sprintf(HIR"  迷宫第十二层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第十二层 『 完成 』    "NOR"  \n");
if (!me->query("migong/lev13"))
    	sec += sprintf(HIR"  迷宫第十三层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第十三层 『 完成 』     "NOR" \n");
if (!me->query("migong/lev14"))
    	sec += sprintf(HIR"  迷宫第十四层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第十四层 『 完成 』      "NOR"\n");
if (!me->query("migong/lev15"))
    	sec += sprintf(HIR"  迷宫第十五层 『未完成』  "NOR"    \n");
else
    	sec += sprintf(HIC"  迷宫第十五层 『 完成 』     "NOR"\n");
    	
    	

if ((int)me->query("szj/failed")>3)
    	sec += sprintf(HIR"  解密:神照经  『失败』   "NOR"   \n");
if ((int)me->query("szj/passed"))
    	sec += sprintf(HIC"  解密:神照经  『成功』  "NOR"    \n");
if ((int)me->query("jiuyin/shang-failed")>2)
    	sec += sprintf(HIR"  解密:九阴上  『失败』   "NOR"   \n");
if ((int)me->query("jiuyin/shang"))
    	sec += sprintf(HIC"  解密:九阴上  『成功』    "NOR"  \n");
if ((int)me->query("jiuyin/xia-failed")>2)
    	sec += sprintf(HIR"  解密:九阴下  『失败』  "NOR"    \n");
if ((int)me->query("jiuyin/xia"))
    	sec += sprintf(HIC"  解密:九阴下  『成功』     "NOR" \n");
if ((int)me->query("jiuyin/emei"))
    	sec += sprintf(HIC"  解密:九阴速成『成功』 "NOR"     \n");
if ((int)me->query("jiuyin/full"))
    	sec += sprintf(HIC"  解密:九阴全部『成功』   "NOR"   \n");
if ((int)me->query("double_attack"))
    	sec += sprintf(HIC"  解密:双手互搏『成功』    "NOR"  \n");
if ((int)me->query("jiuyin/gumu-failed")>2)
    	sec += sprintf(HIR"  解密:九阴古墓『失败』   "NOR"   \n");
if ((int)me->query("zhou/failed")>2)
    	sec += sprintf(HIR"  解密:互  搏  『失败』   "NOR"   \n");
if ((int)me->query("zhou/fail")>2)
    	sec += sprintf(HIR"  解密:互  搏  『失败』    "NOR"  \n");
if ((int)me->query("zhou/jieyi")>2)
    	sec += sprintf(HIR"  解密:互搏结义『失败』   "NOR"   \n");

		sec = replace_string(sec,"\n",ZJBR)+"\n";
		write(ZJOBLONG+sec+"\n");

        return 1;
}


int help(object me)
{
	string sec;
	sec = sprintf(WHT"\n【迷宫寻宝】："NOR"\n");
	sec += sprintf(@HELP
新任务,玩家可以去迷宫寻宝.位置在襄阳北的龙门石窟进入，迷宫有15层,里面有quest和不少迷题.
每层有些怪物,和宝箱,玩家可以kill 怪物,用openbox命令
打开宝箱宝箱中的宝物是随机的,可能有很普通的东西,也
可能有神兵利器,武功奇书, 还可能为你加exp,pot,neili,
在第5层以下的迷宫里在宝箱里可能找到  力量珠  悟性
珠根骨珠 身法珠 福缘珠 容貌珠这六个神珠找到后,你可
以用eat来吃了,长exp,pot.如果你找全六个神珠,就能用
hebing来合并神珠,获得100000exp, 1000000pot,500 neili的最大奖励.(打开宝箱,也有中喑器,中毒的可能)
珠类宝物说明
力量珠->山洞
悟性珠->钟乳石洞
根骨珠->岩洞
身法珠->熔岩洞
福缘珠->熔岩洞
容貌珠->岩洞
找全后可以hebing后eat
火灵珠->山洞
雷灵珠->钟乳石洞
土灵珠->岩洞
风灵珠->熔岩洞
水灵珠->岩洞
找到后可以wear,有巨大战斗效果
如果找全的话可以风火雷土水五珠合壁(wuzhuhebi)
合成圣灵珠

    在后面几层有boss守护,打败之,可获exp,pot

    在最后一层有火龙守护,
    打败千年火龙,可获千年火龙甲（防御力2000）
    打败普通火龙,可获火龙甲（防御力1000）

    在第6-12层，都各有一个地方，可以用newup方向，
到达传说中的圣域，在那里可以挑战，12黄金站士，每
打败一人，可获修为20000，如果全部打败，可获黄金
圣衣一件(防御力1200)，大量修为和潜能。

 注:1.本任务危险极大....
    2.本任务最好几个人team去做....
    3.任务条件exp>100000exp
	4.杀敌长exp,pot条件情况
    lev1 exp < 200000
    lev2  300000
    lev3  700000
    lev4  1000000
    lev5  1500000
    lev6  2500000
    lev7  3000000
    lev8  3500000
    lev9  4500000
    lev10 6000000
    lev11 8000000
    lev12 9000000
    lev13 10000000
    lev14 12000000-15000000
    lev15 16000000-18000000

相关命令:openbox(开宝箱)mgmap(显示附近地图)
玩家完成2转后，修为达到20M,可以向大神以上巫师提出3转要求，
3转后,只保留属性，和道具。但可以进入迷宫16层以后的6个世界，
并可以学习其中的新的技能！，新世界有上百种敌人，上百种道具，等着你来发现!!
HELP
	);

		sec = replace_string(sec,"\n",ZJBR)+"\n";
		write(ZJOBLONG+sec+"\n");
	return 1;
}