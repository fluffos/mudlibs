// /d/xiakedao/shishi24.c 侠客岛 石室24

inherit ROOM;

//int do_study(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
这里火光昏暗，只见那龙岛主与木岛主盘膝坐在锦垫之上，面对
石壁(wall)，凝神苦思。此石室已是山腹最深处，却宽阔高大，足可
容下近百人。洞中火把亦是其他洞的二三倍之多。
LONG );
        set("exits", ([
                "east" : __DIR__"shihole6",
        ]));
        set("item_desc", ([
                "wall" : @WALL
墙的正上方刻着「白首太玄经」几个大字。字的下方刻的是密密麻麻
的蝌蚪文，成千上万。文字排列甚不整齐，或横或竖，或直或斜。左
下的大片甚至混成一团难分次序，委实难以辨认。
WALL
        ]));
        set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects", ([
                __DIR__"npc/long" : 1,
                __DIR__"npc/mu"   : 1,
"/quest/menpai/newmp/shi12" : 1,
"/d/biwu/champion_xkd" : 1,	
"/d/xiakedao/npc/xkddizi" : 4,	
        ]));
        set("no_clean_up", 0);
        //set("no_fight", 1);
        set("no_beg", 1);
        setup();
}

void init()
{
        add_action("do_study","think");
}
int do_study(string arg)
{
        object me, where;
        int jing_cost, learn_pot, item, times, i, success=0;
        string skillname;

        me = this_player();
        if( !arg ) return notify_fail("你要领悟什么呀？\n");
	if( sscanf(arg, "%s %d", arg, times)!=2)
		return notify_fail("指令格式：think wall <次数>\n");
        if( ( arg != "wall" ) )
		return notify_fail("指令格式：think wall <次数>\n");
	if (times < 1 || times > 20)
		return notify_fail("领悟次数最少一次，最多也不能超过二十次。\n");
        if ((int)me->query("combat_exp")<500000)
                return notify_fail("你的经验太低, 没法领悟石壁内容。\n");
        if ((int)me->query_skill("literate",1)<1)
                return notify_fail("你晕了吧! 还是先去学点文化吧。\n");
        jing_cost = 30 + random(me->query_int());
        if( me->query("jing") < jing_cost * times)
                return notify_fail("你现在太累了，领悟不了这么多次，休息一会儿再来吧。\n");

        message_vision("$N正在钻研石壁上的图案和注释。\n",me);
	for (i = 1; i<=times; i++)
	{
		me->receive_damage("jing",jing_cost);
//		if (!me->query_skill("taixuan-gong"))
//		{
//			write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太深奥了。\n");
//			return 1;
//		}
		if (me->query_skill("taixuan-gong",1)>=250)
		{
			write("你望着石壁冥思苦想了一会，发觉上面的东西对你来说太浅薄了。\n");
			return 1;
		}
		else
		{
			if( !SKILL_D("taixuan-gong")->valid_learn(me) )
			return SKILL_D("taixuan-gong")->valid_learn(me);
		}
		if((int)(me->query_skill("taixuan-gong",1) * 
			me->query_skill("taixuan-gong",1) * 
			me->query_skill("taixuan-gong",1)) /5 >= me->query("combat_exp"))
		{
			write("你对着石壁冥思苦想了一会，毫无收获。\n");
			return 1;
		}
		learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int"))
			- (int)(me->query_skill("literate",1)/2);
		if (learn_pot > 0)
		{
			me->improve_skill("taixuan-gong", learn_pot);
			success=1;
		}
	}
	if (success == 1)
		write("你对着石壁冥思苦想了"+chinese_number(times)+"回，似乎"+CHINESE_D->chinese("taixuan-gong")+"有些心得。\n");
	else write("你对着石壁冥思苦想了一会，可是资质太差，似乎没啥心得。\n");
	success=0;
	return 1;
}

