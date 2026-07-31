// 请注意作者!是龙剑飞扬之纵横新世纪(202.103.98.74-5555)
// 【 天尊 】小黑马(xhm)和任天平(tianping)  
浩劫系统修改文件列表:
/feature/disaster.c //浩劫系统的主程序
/feature/damage.c //增加浩劫系统的触发条件 及 判断浩劫是否平息
/adm/daemons/logind.c //增加浩劫发生的判断条件变量 及 变量的设置和读取
/adm/daemons/natured.c //增加浩劫系统的导火索
/adm/daemons/combatd.c //增加浩劫过程中产生的杀手被player杀死后给
/include/globals.h //增加F_DISASTER
/d/haojie/ //增加浩劫系统所需的杀手(pker)和挑战书(shu)文件
/cmds/wiz/kan.c //查看临时参数的命令文件
/cmds/adm/kaishi.c //手动触发浩劫事件发生
//以下见个我只放上了pker1以后的npc就请自己改一下吧!^_^
//祝大家用得开心!
exp下限: exp上限: 文件名: 中文名: pot,exp,score(奖励)
0 10000, pker1, 青衣杀手 4, 100,10
10001 30000, pker2, 白衣杀手 6, 200,20
30001 50000, pker3, 黑衣杀手 8, 300,30
50001 80000, pker4, 灰衣杀手 10, 400,40
80001 150000, pker5, 黄衣杀手 12, 500,50
150001 300000, pker6, 红衣杀手 14, 600,60
300001 500000, pker7, 蓝衣杀手 16, 700,70
500001 800000, pker8, 紫衣杀手 18, 800,80
800001 1200000, pker9, 金衣杀手 20, 900,90
网吧线申请命令:
/cmds/adm/endueid.c //开启网吧线权限命令!开启网吧线权限以在logind.c中有!
巫师双重密码:
cmds/imm/passwd_w.c //双重密码在logind.c中也有!
