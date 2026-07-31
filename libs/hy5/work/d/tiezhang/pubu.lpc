// Room: /u/zqb/tiezhang/pubu.c

inherit ROOM;
void init()
{
	add_action("lingwu","lingwu");
}
void create()
{
	set("short", "[32m瀑布[0;37;0m");
	set("long", @LONG
    山路行到这里，忽听远处传来隐隐水声，转过一道山梁，只见一 
道白龙似的大瀑布从对面双峰之间奔腾而下，空山寂寂，那水声在山谷中激 
荡回想，声势甚是惊人。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xzfeng",
  "eastdown" : __DIR__"sblu-1",
]));
	set("no_clean_up", 0);

	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");

	if(me->query("potential") < 100 ) 
         return notify_fail("你的潜能太少了!\n");	

	if(me->query("potential") < 0 ) 
         return notify_fail("你的潜能太少了!\n");	
	if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
         return notify_fail("你的潜能太少了!\n");	
	

	//if (!me->query("luohan_winner")) return notify_fail("你级别不够，不能在此领悟。\n");
	if (!arg) return notify_fail("你要领悟什么？\n");
	if (!me->query_skill(arg,1))
		return notify_fail("你不会这种技能。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("你只能从特殊技能中领悟。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 20) {
		me->receive_damage("jing",bl/2);
		return notify_fail("你没办法集中精神。\n");
	}
	if(me->query("potential") < 100 ) 
         return notify_fail("你的潜能太少了!\n");	

	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("你的"+to_chinese(special)+"造诣不够，无法领悟更深一层的"+CHINESE_D->chinese(arg)+"。\n");
	write("你瞑思苦想，对"+to_chinese(arg)+"的体会又深了一层。\n");
	me->receive_damage("jing",bl/2);
//	if(me->query("combat_exp") > 1000000 ) {
//        me->add("potential", -random(3));
//        }
        if(me->query("combat_exp") < 2000000 )
         {
	me->improve_skill(arg,sl/5+1);
         }
else {
	me->improve_skill(arg,sl/10+1);
}
	return 1;
}
