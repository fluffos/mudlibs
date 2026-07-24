// Creat by Ciwei@SJ

#include <ansi.h>

nosave mapping essence = ([
"weapon":({
([
	"name":                     HIW"岫玉",
	"id":                       ({"youyu","jade","yu"}),
	"long":                     "这是一块十分细腻致密的岫玉，看上去油脂光泽,性软而脆。\n",
	"weight":                   2500,
	"unit":                     "块",
	"level":                    1,
	"value":                    ({50000,30000}),
	"damage":                   ({1,30}),
	"status":                   ({0,2}),
]),
([
	"name":                     YEL"独玉",
	"id":                       ({"duyu","jade","yu"}),
	"long":                     "这是一块“独山玉”，看上去隐晶质，质地细腻，坚硬致密。\n",
	"weight":                   2500,
	"unit":                     "块",
	"level":                    2,
	"damage":                   ({10,30}),
	"status":                   ({1,2}),
	"value":                    ({80000,40000}),
]),
([
	"name":                     HIY"南玉",
	"id":                       ({"nanyu","jade","yu"}),
	"long":                     "这是一块质坚韧微密的南玉，看上去细腻柔润，光泽透明，色泽斑驳陆离。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({120000,50000}),
	"level":                    4,
	"damage":                   ({20,30}),
	"status":                   ({2,2}),
]),
([
	"name":                     HIB"密玉",
	"id":                       ({"miyu","jade","yu"}),
	"long":                     "这是一块质地紧硬的密玉，看上去细腻，色泽鲜艳、均匀，极少杂质，具有天然色彩。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({170000,60000}),
	"level":                    6,
	"damage":                   ({30,40}),
	"status":                   ({2,3}),
]),
([
	"name":                     GRN"风雷玉",
	"id":                       ({"fengleiyu","jade","yu"}),
	"long":                     "这是一块颜色纯正而美丽的风雷玉，看上去光亮、质地细腻。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({200300,70000}),
	"level":                    8,
	"damage":                   ({40,80}),
	"status":                   ({3,3}),
]),
([
	"name":                     HIY"龙鳞玉",
	"id":                       ({"longlingyu","jade","yu"}),
	"long":                     "这是一块乌金美玉，形如龙鳞，张牙舞爪，力透形魂。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({400300,90000}),
	"level":                    10,
	"damage":                   ({50,80}),
	"status":                   ({4,2}),
]),
}),
"armor":({
([
	"name":                     HIW"癍玉",
	"id":                       ({"banyu","jade","yu"}),
	"long":                     "有细微斑点，出产在华南温泉的小块碎玉。\n",
	"weight":                   2500,
	"unit":                     "块",
	"level":                    1,
	"value":                    ({50000,30000}),
	"armor":                   ({1,10}),
	"status":                   ({0,2}),
]),
([
	"name":                     YEL"琉玉",
	"id":                       ({"liuyu","jade","yu"}),
	"long":                     "通体流丽，光彩凝和，是来自高丽国的玉石。\n",
	"weight":                   2500,
	"unit":                     "块",
	"level":                    2,
	"armor":                   ({5,15}),
	"status":                   ({1,2}),
	"value":                    ({80000,40000}),
]),
([
	"name":                     HIY"脂玉",
	"id":                       ({"zhiyu","jade","yu"}),
	"long":                     "白腻犹如凝脂，抚摩上去轻柔灵动，从西域传来的美玉。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({120000,50000}),
	"level":                    4,
	"armor":                   ({10,20}),
	"status":                   ({2,2}),
]),
([
	"name":                     HIB"香凝玉",
	"id":                       ({"xiangniyu","jade","yu"}),
	"long":                     "透着一股子清香的玉石，仿佛是仙女下凡留在人间的饰物。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({170000,60000}),
	"level":                    6,
	"armor":                   ({20,30}),
	"status":                   ({2,3}),
]),
([
	"name":                     GRN"绿玉髓",
	"id":                       ({"lvyusui","jade","yu"}),
	"long":                     "这是一块颜色纯正而美丽的绿玉髓，看上去光亮、质地细腻。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({200300,70000}),
	"level":                    8,
	"armor":                   ({35,40}),
	"status":                   ({3,3}),
]),
([
	"name":                     GRN"凤瓴玉",
	"id":                       ({"fenglingyu","jade","yu"}),
	"long":                     "形如凤舞九天，飘渺凝炼，一看就是人间珍品。\n",
	"weight":                   2500,
	"unit":                     "块",
	"value":                    ({400300,90000}),
	"level":                    10,
	"armor":                   ({45,40}),
	"status":                   ({4,2}),
]),
}),
]);

void init()
{
	add_action("do_combine", "combine");
}

int do_combine(string arg)
{
	int i,j,k;
	object *inv, gem, me = this_player(),newgem;

	if (!arg || arg == "")
		return notify_fail("你想合并什么材料？\n");
	if (arg != query("id")) return 0;
	if (query("level") == 6)
		return notify_fail("这个材料已经是最高等级了！\n");
	if (me->query("max_neili") < 800 || me->query("neili") < 800)
		return notify_fail("以你现在的内力修为，还无法运功合并材料！\n");

	inv = all_inventory(me);
	for(i = 0; i < sizeof(inv); i++)
		if (inv[i] != this_object() && inv[i]->query("id") == query("id")) {
			if (!objectp(gem))
				gem = inv[i];
			else {
				message_vision(HIG"$N暗运内力劲透全身，但见" + name() + HIG"表面异彩流动，
渐渐的$N收回了内力，只觉" + name() + HIG"似乎变得更加完美了！\n", me);
				me->add("max_neili", -200);
				me->add("neili", -200);
				me->start_busy(1);
j=query("level");
j=j+1;
if (query("ayushi")==1)
	{
j=j+6;
}
j=j+1;
k=3;
if (j >=2) k=5;
if (j >=3) k=6;
if (j >=4) k=8;

if (random(k)==0)
{
           newgem = new("/p/newweapon/weaponobj/material"+j);
           newgem->move(me);
message_vision(HIG"在$N的内力下 " + name() + HIG"品质得到了提升变成"+newgem->query("name")+"\n"NOR, me);
//				new_gem(query("material"), query("level") + 1)->move(me);
}
else
{
				message_vision(RED"$N大叫一声不好! " + name() + RED"突然裂开了，失去了光泽！\n", me);

}
				destruct(gem);
				destruct(inv[i]);
				destruct(this_object());


				return 1;
			}
		}
	return notify_fail("你必须有三块同样的材料才能进行合并！\n");
}
