// mudage.c
//[xiaojl 1999/11/20 海洋II]

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int sec, min, hrs, day, mon, age;
        string out_str;
    	write(HIY"  『 迷宫探险 』 \n"); 
if (!me->query("migong/lev1"))
    	write(HIR"  迷宫第 一 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 一 层 『 完成 』     \n"); 
if (!me->query("migong/lev2"))
    	write(HIR"  迷宫第 二 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 二 层 『 完成 』     \n"); 
if (!me->query("migong/lev3"))
    	write(HIR"  迷宫第 三 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 三 层 『 完成 』     \n"); 
if (!me->query("migong/lev4" ))
    	write(HIR"  迷宫第 四 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 四 层 『 完成 』     \n"); 
if (!me->query("migong/lev5"))
    	write(HIR"  迷宫第 五 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 五 层 『 完成 』     \n"); 
if (!me->query("migong/lev6"))
    	write(HIR"  迷宫第 六 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 六 层 『 完成 』     \n"); 
if (!me->query("migong/lev7"))
    	write(HIR"  迷宫第 七 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 七 层 『 完成 』     \n"); 
if (!me->query("migong/lev8"))
    	write(HIR"  迷宫第 八 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 八 层 『 完成 』     \n"); 
if (!me->query("migong/lev9"))
    	write(HIR"  迷宫第 九 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 九 层 『 完成 』     \n"); 
if (!me->query("migong/lev10"))
    	write(HIR"  迷宫第 十 层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第 十 层 『 完成 』     \n"); 
if (!me->query("migong/lev11"))
    	write(HIR"  迷宫第十一层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第十一层 『 完成 』     \n"); 
if (!me->query("migong/lev12"))
    	write(HIR"  迷宫第十二层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第十二层 『 完成 』     \n"); 
if (!me->query("migong/lev13"))
    	write(HIR"  迷宫第十三层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第十三层 『 完成 』     \n"); 
if (!me->query("migong/lev14"))
    	write(HIR"  迷宫第十四层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第十四层 『 完成 』     \n"); 
if (!me->query("migong/lev15"))
    	write(HIR"  迷宫第十五层 『未完成』     \n"); 
else
    	write(HIC"  迷宫第十五层 『 完成 』     \n"); 
if ((int)me->query("szj/failed")>3)        
    	write(HIR"  解密:神照经  『失败』     \n"); 
if ((int)me->query("szj/passed"))        
    	write(HIC"  解密:神照经  『成功』     \n"); 
if ((int)me->query("jiuyin/shang-failed")>2)        
    	write(HIR"  解密:九阴上  『失败』     \n"); 
if ((int)me->query("jiuyin/shang"))        
    	write(HIC"  解密:九阴上  『成功』     \n"); 
if ((int)me->query("jiuyin/xia-failed")>2)        
    	write(HIR"  解密:九阴下  『失败』     \n"); 
if ((int)me->query("jiuyin/xia"))        
    	write(HIC"  解密:九阴下  『成功』     \n"); 
if ((int)me->query("jiuyin/emei"))        
    	write(HIC"  解密:九阴速成『成功』     \n"); 
if ((int)me->query("jiuyin/full"))        
    	write(HIC"  解密:九阴全部『成功』     \n"); 
if ((int)me->query("double_attack"))        
    	write(HIC"  解密:双手互搏『成功』     \n"); 
if ((int)me->query("jiuyin/gumu-failed")>2)        
    	write(HIR"  解密:九阴古墓『失败』     \n"); 
if ((int)me->query("zhou/failed")>2)        
    	write(HIR"  解密:互  搏  『失败』     \n"); 
if ((int)me->query("zhou/fail")>2)        
    	write(HIR"  解密:互  搏  『失败』     \n"); 
if ((int)me->query("zhou/jieyi")>2)        
    	write(HIR"  解密:互搏结义『失败』     \n"); 


        return 1;
}


int help(object me)
{
	write(WHT"\n【迷宫寻宝】："NOR"\n");
	write(@HELP
    新任务,玩家可以去迷宫寻宝.迷宫有15层,里面有quest和不少迷题.
每层有些怪物,和宝箱,玩家可以kill 怪物,用openbox命令打开宝箱
宝箱中的宝物是随机的,可能有很普通的东西,也可能有神兵利器,武功奇
书, 还可能为你加exp,pot,neili,在第5层以下的迷宫里在宝箱里可能
找到  力量珠  悟性珠 根骨珠 身法珠 福缘珠 容貌珠这六个神珠
找到后,你可以用eat来吃了,长exp,pot.如果你找全六个神珠,就能用
hebing来合并神珠,获得100000exp, 1000000pot,500 neili的最大
奖励.(打开宝箱,也有中喑器,中毒的可能)
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
如果找全的话可以
风火雷土水五珠合壁(wuzhuhebi)
合成圣灵珠

    在后面几层有boss守护,打败之,可获exp,pot

    在最后一层有火龙守护,
    打败千年火龙,可获千年火龙甲（防御力2000）
    打败普通火龙,可获火龙甲（防御力1000）

 
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
  玩家完成2转后，经验达到20M,可以向大神以上巫师提出3转要求，
3转后,只保留属性，和道具。但可以进入迷宫16层以后的6个世界，
并可以学习其中的新的技能！，新世界有上百种敌人，上百种道具，等着
你来发现!!                        
HELP
	);
	return 1;
}