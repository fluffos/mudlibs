// questlist.c
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string *jm1=({
"尚未开始",
"夜探商家堡 救人于水火",
"佛山小茶亭 大战袁紫衣",
"北京康王府 解秘掌门会",
"智救苗人凤 战胜田归农",
"义助程灵素 战败毒夫妇",
"战两雄得胜 得宝藏铁盒",
});

string *jm2=({
"尚未开始",
"守护奇铁盒 打败众强盗",
"智入玉笔峰 救出苗若兰",
"解闯王宝藏 败三大高手",
"败大内高手 成民族大义",
});
string *jm3=({
"尚未开始",	
"大败万震山 得连城剑法",
"大闹黑监狱 救出丁典来", 
"败落花流水 见血刀恶僧",
"救美女水笙 杀血刀恶僧",
"破庙败敌人 解连城宝藏",
});
string *jm4=({
"尚未开始",	
"智探无量山 进山洞寻宝",
"败四大恶人 恶战救段誉",
"保护天龙寺 挑战六脉剑",
"苏州探慕容 大败慕容复",
"识康敏奸计 破丐帮大阵",
"解逍遥棋局 打败丁春秋",
"救天山童姥 败七十二洞",
"探西夏皇宫 战胜李秋水",
"勇斗少林寺 败双雄挑战",
"大败辽国兵 败敌接乔锋",
});
string *jm5=({
"尚未开始",	
"义助铁木真 大败梅超风",
"试比武招亲 败叛徒杨康",
"寻访沙窟洞 胜桃花叛徒",
"智做叫花鸡 战败欧阳克",
"桃花岛探密 赢比武招亲",
"陆家庄破敌 大败金兵归",
"解四徒挑战 见一灯大师",
"铁掌山探险 得武穆移书",
"救襄阳危难 退拖雷大军",
"于华山论剑 得武学大成",
});
string *jm6=({
"尚未开始",	
"杀头狼获胜 挑战苏普胜",
"恶战陈达海 力帮李文秀",
"进高昌迷宫 败江南华辉",
"解高昌迷宫 败吕梁三杰",
"识破马家骏 打败计老人",
});

string *jm7=({
"尚未开始",	
"营救矛十八 再救白衣尼",
"救天地会主 见庄家遗孀",
"智杀螯拜回 抱得双儿归",
"进宫探秘密 识破假皇后", 
"智上神龙岛 大败洪教主",
"清凉寺灭敌 再杀吴三桂",
"关外守边疆 西藏灭叛逆",
"得四十二经 解大清宝藏",
});
string *jm8=({
"尚未开始",	
"败青城四兽 相救令狐冲",
"访福威镖局 再救林平之",
"打败田伯光 智救小仪琳",
"智上思过崖 约见风清扬",
"寻找药王庙 败剑宗门人", 
"败敌人追杀 力救向问天",
"秘密访梅庄 智救任我行",
"克少林群雄 救出任盈盈",
"夜探黑木崖 杀东方不败",
"嵩山比武会 败五派掌门",
"力救岳灵姗 败葵花辟邪",
});
string *jm9=({
"尚未开始",	
"华亭败清兵 救文泰骆冰",
"硬闯铁胆庄 破百花错拳",
"力救霍青桐 老云寨夺宝",
"刺杀张召重 抢七族盟书",
"杭州救皇帝 打败陈家洛",
});

string *jm10=({
"尚未开始",	
"过全真大阵 全真败霍都",
"打败李莫愁 力救陆无双",
"闯武林大会 三场定胜败",
"解绝情谷密 救出裘千尺",
"重阳宫抗敌 杀死赵志敬",
"解独孤求败 得玄铁重剑",
"智闯黑龙潭 探绝情谷底",
"救出小郭襄 杀金轮法王",
});
string *jm11=({
"尚未开始",	
"寻丁家两怪 得玄冰碧酒",
"战关东四帮 救大悲老人",
"救出石中玉 大败贝海石",
"硬闯凌霄城 打败白自在",
"接赏罚令牌 打败众岛主",
});
string *jm12=({
"尚未开始",	
"冰火岛解迷 教出张无忌",
"守护武当派 打败五大派", 
"解九阳秘密 打败朱九真",
"闯明教禁地 光明顶显威",
"探秘绿柳庄 得黑玉神药",
"访问灵蛇岛 败波斯三使",
"探险万安塔 败玄冥二老",
"打败三渡僧 杀成昆小人",
});
string *jm13=({
"尚未开始",	
"黑松堡救人 访问夏雪宜",
"拔出金蛇剑 杀敌救温仪",
"五毒教探险 打败何铁手",
"单挑玉真子 打败袁承志",
"打败皇太极 怒杀曹化淳",
});

string *jm14=({
"尚未开始",	
"挑战黑风寨 勇救萧中慧",
"智上常春岛 巧进白云岛",
"杀上蝙蝠岛 恶人谷探险",
"解秘进萧府 打败四高手",
"智得红钥匙 挑战袁冠男",
});


void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob, obt;
        string hymsg;
	mapping my;
	string line, str, skill_type,zs,zs1,zs2;
	object weapon;
        int attack_points, dodge_points, parry_points, btmp, t, d, r,money,i,zs3,zs4,money2;
        int a,b,c,hylv;
	seteuid(getuid(me));
        btmp=1;
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
                obt = find_player(arg);
                if ( !obt ) btmp=0;
                if (!ob) ob = obt;
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");


write(HIC"≡"+HIY"───────────────────────────────"HIC"≡\n"NOR);
write(HIW"【"HIM"飞 狐 外传"HIW"】"HIY+jm1[ob->query("jinyong/book1")]+" 。");	
if ((int)ob->query("jinyong/book1",1)== sizeof(jm1)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 
  

write(HIW"【"HIM"雪 山 飞狐"HIW"】"HIY+jm2[ob->query("jinyong/book2")]+" 。");	
if ((int)ob->query("jinyong/book2",1)== sizeof(jm2)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"连 城   决"HIW"】"HIY+jm3[ob->query("jinyong/book3")]+" 。");	
if ((int)ob->query("jinyong/book3",1)== sizeof(jm3)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"天 龙 八部"HIW"】"HIY+jm4[ob->query("jinyong/book4")]+" 。");	
if ((int)ob->query("jinyong/book4",1)== sizeof(jm4)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"射雕英雄传"HIW"】"HIY+jm5[ob->query("jinyong/book5")]+" 。");	
if ((int)ob->query("jinyong/book5",1)== sizeof(jm5)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"白马啸西风"HIW"】"HIY+jm6[ob->query("jinyong/book6")]+" 。");	
if ((int)ob->query("jinyong/book6",1)== sizeof(jm6)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"鹿  鼎  记"HIW"】"HIY+jm7[ob->query("jinyong/book7")]+" 。");	
if ((int)ob->query("jinyong/book7",1)== sizeof(jm7)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"笑 傲 江湖"HIW"】"HIY+jm8[ob->query("jinyong/book8")]+" 。");	
if ((int)ob->query("jinyong/book8",1)== sizeof(jm8)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"书剑恩仇录"HIW"】"HIY+jm9[ob->query("jinyong/book9")]+" 。");	
if ((int)ob->query("jinyong/book9",1)== sizeof(jm9)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"神 雕侠 侣"HIW"】"HIY+jm10[ob->query("jinyong/book10")]+" 。");	
if ((int)ob->query("jinyong/book10",1)== sizeof(jm10)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"侠  客  行"HIW"】"HIY+jm11[ob->query("jinyong/book11")]+" 。");	
if ((int)ob->query("jinyong/book11",1)== sizeof(jm11)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"倚天屠龙记"HIW"】"HIY+jm12[ob->query("jinyong/book12")]+" 。");	
if ((int)ob->query("jinyong/book12",1)== sizeof(jm12)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"碧  血  剑"HIW"】"HIY+jm13[ob->query("jinyong/book13")]+" 。");	
if ((int)ob->query("jinyong/book13",1)== sizeof(jm13)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIW"【"HIM"鸳  鸯  刀"HIW"】"HIY+jm14[ob->query("jinyong/book14")]+" 。");	
if ((int)ob->query("jinyong/book14",1)== sizeof(jm14)-1) 
write(HIG"已完成。\n");
 else
write(HIR"未完成。\n"); 

write(HIC"≡"+HIY"──────────主线解迷进程情况─────"HIC"≡\n"NOR);
	return 1;
        
}



int help(object me)
{
	write(@HELP
指令格式 : questlist
           questlist <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象的主线解秘情况。
基本资料的设定请参阅 'help questlist'。

see also : hp
HELP
    );
    return 1;
}
