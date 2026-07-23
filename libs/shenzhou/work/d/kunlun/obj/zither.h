//Cracked by Roath
void init()
{
        add_action("do_play", "tan");
        add_action("do_tan","play");
}

string *tan_msg = 
({
	HIM"\n$N对照曲谱十指挥动琴弦开始抚琴奏左手按节捻弦，右手弹了起来。顿时瑶琴之声渐响，琴声不断\n传来，甚是优雅。\n"NOR,
	HIM"\n琴音渐渐高亢有如游丝随风飘荡，却连绵不绝，更增回肠荡气之意，耳中传入几下幽幽的胡琴声，\n琴声凄凉，似是叹息，又似哭泣。\n"NOR,
	HIG"\n跟着琴声颤抖，发出瑟瑟瑟断续之音，如是一滴滴小雨落上树叶，$N三指一挥，琴声突然止歇。\n"NOR,
	MAG"\n接着只听得琴声响起，幽雅动听弹不多久，突然间琴音高了上去，越响越高，声音尖锐之极，\n铮的一声响，断了一根琴弦，再高了几个音，铮的一声，琴弦又断了一根。\n"NOR,
	HIG"\n琴音响起，调了调弦，停了一会，似是在将断了的琴弦换去，又调了调弦，便奏了起来。\n到后来越转越高，那琴韵竟然履险如夷，举重若轻，毫不费力的便转了上去。\n"NOR,
	HIM"\n这一曲时而慷慨激昂，时而温柔雅致。奏了良久，琴韵渐缓，似乎乐音在不住远去，\n倒像奏琴之人走出了数十丈之遥，又走到数里之外，细微几不可再闻。\n"NOR,
	HIM"\n此时琴声宛如一人轻轻叹息，又似是朝露暗润花瓣，晓风低拂柳梢，那琴声平和中正，\n隐然有王者之意。\n"NOR, 
});


int do_play()
{
	int i, count, range, skill;
	object me, ob, weapon;
        string msg, tan_type, *shape, family;

	ob = this_object();
	me = this_player();
	shape = ob->query("shape");
	skill = me->query_skill("qinqi-shuhua", 1);
	
	if (me->query("family/family_name"))
		family=me->query("family/family_name");
	
	if(skill < 60) 
	{
		message_vision(CYN"\n$N端坐几上小心的拿出琴平放在案上十指生硬的压在琴弦上，手指扶弄单弦，发出铮铮几声! 伊伊呀呀的响起了琴之声 。\n"NOR, me);
		tell_object(me,"\n你的琴棋书画等级不够，无法将音律控制自如。\n"NOR);
		me->add("jingli", -(10 + random(5)));
		return 1;
	}
	
	if ( !present("qupu", me))
		return notify_fail("你觉的自己十指已经灵活，基本功已经有一定的基础，应该找本曲谱来练习了。\n");
		
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
		
        if(! family || family != "昆仑派" && !wizardp(me))
               	return notify_fail("你并非昆仑弟子！\n");
	
	if( me->query_skill("force") < 40 )
                return notify_fail("你的内功火候欠佳！\n");

        if( (int)me->query("neili") < 200 )
        	return notify_fail("你的内力不够！\n");
        	
        if( (int)me->query("jing") < 200 )
		return notify_fail("你的精神不佳。\n");
		
	if( (int)me->query("jingli") < 250 )
		return notify_fail("你太累了。\n");
	
	if( !objectp(weapon = me->query_temp("weapon")) )
                return notify_fail("你没有带琴如何弹奏。\n");

	if( weapon->query("name") != ob->query("name") )
		return notify_fail("你手中并没有拿琴。\n");

	if (find_call_out("playing") >= 0) 
		return notify_fail("你能同时弹两首曲子吗？\n");
	
		msg = "\n$N摆出了一张古筝，近地而坐，慢慢弹了起来，一时间，万具晖音，周围的人都沉静在一片琴音之中！\n";
	
	
	message_vision(msg, me, ob);
	message_vision(HIC"\n突然之间，半空中如鸣金，如击玉，发了几声，接着悠悠扬扬，飘下一阵清亮柔和的琴声来。\n"NOR, me);
	me->start_busy(2);
	call_out("playing", 2, me, 0);
	return 1;
}

void playing(object me, int stage)
{
	int i, size, exp, pot, myexp, jingcost, jinglicost;
	size=sizeof(tan_msg);
	if( stage < size)
	{
		message_vision(tan_msg[stage], me);
		me->start_busy(2);
		call_out("playing", 2 , me, ++stage);
		
	}
	else 
	{
		message_vision("\n弹到后来，琴声渐低，突然铮的一声，琴声止歇，$N轻抚琴弦，缓缓的站了起来。\n", me);	
		myexp=me->query("combat_exp");
		exp = 6+random(3);
		pot = 4+random(2);
		jingcost= (int)((myexp/1000)*4);
		jinglicost = (int)((myexp/1000)*2);
		
		if (jingcost > 150) jingcost = 150;
		if (jinglicost > 200) jinglicost = 200;
		me->add("combat_exp", exp);
                if (me->query("potential") < me->query("max_potential"))
			me->add("potential", pot);
		me->add("jing", -jingcost);
		me->add("jingli", -jinglicost);
                  me->improve_skill("qinqi-shuhua", 25+random(10));
		log_file("/job/Kunlun_tan", ctime(time()) + me->query("name") +"(" + me->query("id") + ")弹琴获得" + exp + "经验和"+ pot + "潜能\n" );
	}
}
