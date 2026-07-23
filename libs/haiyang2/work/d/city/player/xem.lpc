// xem.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("静梅", ({ "xem"}));
	set("gender", "女性");
	set("title", HIY"翰林硕士"HIG"明教地字门教众"NOR"峨嵋派第四代弟子");
	set("age", 40);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 28);
	set("per", 20);
	set("int", 30);
	set("dex", 16);
	set("con", 15);
	set("str", 19);
	set("weiwang", 70);
	set("shen", 107080);
	set("combat_exp", 3688251);
	set("PKS", 4);
	set("MKS", 1032);

	set("max_jing", 580);
	set("jing", 580);
	set("max_qi", 1350);
	set("qi", 1350);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 4040);
	set("neili", 4040);
	set("meili", 60);

	set_skill("literate", 121);
	set_skill("mahayana", 200);
	set_skill("buddhism", 105);
	set_skill("persuading", 130);
	set_skill("force", 252);
	set_skill("unarmed",250);
	set_skill("parry", 260);
	set_skill("dodge", 260);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("strike", 250);
	set_skill("hand", 250);
	set_skill("claw", 250);
	set_skill("finger", 250);
	set_skill("cuff", 250);
	set_skill("jinding-zhang", 328);
	set_skill("qishang-quan", 328);
	set_skill("yanxing-dao", 328);
	set_skill("linji-zhuang", 278);
	set_skill("tianyu-qijian", 328);
	set_skill("zhutian-bu", 328);
	set_skill("huifeng-jian", 328);
	set_skill("kongming-quan", 328);
	set_skill("tiangang-zhi", 328);
	set_skill("jiuyin-baiguzhao", 310);

	map_skill("force", "linji-zhuang");
	map_skill("dodge", "zhutian-bu");
	map_skill("parry", "huifeng-jian");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("strike", "jinding-zhang");
	map_skill("cuff", "qishang-quan");
	map_skill("unarmed", "kongming-quan");
	map_skill("finger", "tiangang-zhi");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("峨嵋派",4, "弟子");
	setup();
	carry_object(__DIR__"xem_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 250/    0\n"+
"  禅宗心法 (buddhism)                      - 心领神会 105/    0\n"+
"  基本爪法 (claw)                          - 深不可测 250/    0\n"+
"  基本拳法 (cuff)                          - 深不可测 250/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 260/    0\n"+
"  基本指法 (finger)                        - 深不可测 250/    0\n"+
"  基本内功 (force)                         - 深不可测 252/    0\n"+
"  基本手法 (hand)                          - 深不可测 250/    0\n"+
"□回风拂柳剑 (huifeng-jian)                - 深不可测 328/    0\n"+
"□金顶绵掌 (jinding-zhang)                 - 深不可测 328/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 310/    0\n"+
"□空明拳 (kongming-quan)                   - 深不可测 328/    0\n"+
"□临济十二庄 (linji-zhuang)                - 深不可测 278/    0\n"+
"  读书写字 (literate)                      - 了然於胸 121/    0\n"+
"  大乘涅磐功 (mahayana)                    - 深不可测 200/    0\n"+
"  基本招架 (parry)                         - 深不可测 260/    0\n"+
"  渡世济人 (persuading)                    - 了然於胸 130/    0\n"+
"□七伤拳 (qishang-quan)                    - 深不可测 328/    0\n"+
"  基本掌法 (strike)                        - 深不可测 250/    0\n"+
"  基本剑法 (sword)                         - 深不可测 250/    0\n"+
"□天罡指穴法 (tiangang-zhi)                - 深不可测 328/    0\n"+
"  天羽奇剑 (tianyu-qijian)                 - 深不可测 328/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 250/    0\n"+
"□雁行刀 (yanxing-dao)                     - 深不可测 328/    0\n"+
"□诸天化身步 (zhutian-bu)                  - 深不可测 328/    0\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  580/  580 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】 1350/ 1350 (100%)    【 内 力 】 4040 / 4040 (+0)\n"+
"【 食 物 】    0/  290           【 潜 能 】  0\n"+
"【 饮 水 】    0/  290           【 经 验 】  3688251\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世女侠】翰林硕士明教地字门教众峨嵋派第四代弟子 静梅(Xem)\n"+
"\n"+
" 你是一位四十岁的女性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 44]  悟性：[ 42]  根骨：[ 40]  身法：[ 42]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   508564            战斗防御力   970895\n"+
" 战斗伤害力       30            战斗保护力      100\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 1036 个人，其中有 4 个是其他玩家。\n"+
"\n"+
" 正    气：   107080     潜    能：   0 (100%)   实战经验：  3688251\n"+
" 魅    力：       60     综合评价：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
