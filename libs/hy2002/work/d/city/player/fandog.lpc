// fandog.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("凡狗", ({ "fandog"}));
	set("gender", "无性");
	set("long","这是一只纯种博美名犬，身上的毛没有几根，
但却如黄金般璀璨，梳理得一丝不苟，油光
水滑，两只眼睛水灵灵的，温情脉脉地看着
你......人耶？狗耶？如果是狗应是一条好
狗，是人更应是一条好汉！\n");
	set("title", HIY"翰林博士"HIG"明教天字门教众"NOR"丐帮第十八代弟子");
	set("nickname", HIY"没毛犬"NOR);
	set("age", 46);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 25);
	set("int", 23);
	set("dex", 20);
	set("con", 21);
	set("str", 16);
	set("weiwang", 70);
	set("shen", 239340);
	set("combat_exp", 2137847);
	set("PKS", 4);
	set("MKS", 2629);

	set("max_jing", 593);
	set("jing", 593);
	set("max_qi", 1251);
	set("qi", 1251);
	set("max_jingli", 500);
	set("jingli", 500);
	set("max_neili", 3260);
	set("neili", 3260);
	set("meili", 60);

	set_skill("literate", 135);
	set_skill("taoism", 100);
	set_skill("hubo", 100);
	set_skill("force", 253);
	set_skill("unarmed",250);
	set_skill("parry", 255);
	set_skill("dodge", 253);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("staff", 250);
	set_skill("shenxing-baibian", 20);
	set_skill("yunlong-jian", 250);
	set_skill("pixie-jian", 250);
	set_skill("houquan", 238);
	set_skill("xianglong-zhang", 278);
	set_skill("xiaoyaoyou", 278);
	set_skill("huntian-qigong", 200);
	set_skill("dagou-bang", 278);
	set_skill("kongming-quan", 214);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "pixie-jian");
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("unarmed","xianglong-zhang");
	map_skill("staff","dagou-bang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("丐帮",18, "弟子");
	setup();
	carry_object(__DIR__"fandog_sword")->wield();
	carry_object("/d/city/npc/obj/jinsijia")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 250/    0\n"+
"□打狗棒法 (dagou-bang)                    - 深不可测 278/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 253/    0\n"+
"  基本内功 (force)                         - 深不可测 253/    0\n"+
"  猴拳 (houquan)                           - 深不可测 238/    0\n"+
"  左右互搏 (hubo)                          - 心领神会 100/    0\n"+
"□混天气功 (huntian-qigong)                - 深不可测 200/    0\n"+
"  空明拳 (kongming-quan)                   - 深不可测 214/    0\n"+
"  读书写字 (literate)                      - 了然於胸 135/    0\n"+
"  基本招架 (parry)                         - 深不可测 255/    0\n"+
"□辟邪剑法 (pixie-jian)                    - 深不可测 250/    0\n"+
"  神行百变 (shenxing-baibian)              - 粗通皮毛  20/    0\n"+
"  基本杖法 (staff)                         - 深不可测 250/    0\n"+
"  基本剑法 (sword)                         - 深不可测 250/    0\n"+
"  道学心法 (taoism)                        - 心领神会 100/    0\n"+
"  基本拳脚 (unarmed)                       - 出神入化 250/    0\n"+
"□降龙十八掌 (xianglong-zhang)             - 深不可测 278/    0\n"+
"  逍遥游 (xiaoyaoyou)                      - 深不可测 278/    0\n"+
"  云龙剑 (yunlong-jian)                    - 深不可测 250/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  593/  593 (100%)    【 精 力 】  500 /  500 (+0)\n"+
"【 气 血 】 1251/ 1251 (100%)    【 内 力 】 3260 / 3260 (+0)\n"+
"【 食 物 】    0/  260           【 潜 能 】  0\n"+
"【 饮 水 】    0/  260           【 经 验 】  2137847\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】翰林博士明教天字门教众丐帮第十八代弟子「没毛犬」凡狗(Fandog)\n"+
"\n"+
" 你是一位四十六岁的无性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 41]  悟性：[ 36]  根骨：[ 46]  身法：[ 45]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 战斗攻击力   269452            战斗防御力   581755\n"+
" 战斗伤害力       30            战斗保护力      100\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 2633 个人，其中有 4 个是其他玩家。\n"+
"\n"+
" 正    气：   239340     潜    能：   0 (100%)   实战经验：  2137847\n"+
" 魅    力：       60     综合评价：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
