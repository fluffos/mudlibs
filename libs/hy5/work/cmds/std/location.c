// location.c

#include <ansi.h>

inherit F_CLEAN_UP;
#include "/quest/givegift.c"
string *place_desc = ({
	"客店" ,
	"武庙" ,
	"中心广场" ,
	"青石大道" ,
	"山路" ,
	"大驿道"
});
int main(object me, string arg)
{
	object ob,where,env,obj;
        mapping myfam;
        string region;
	mapping fam;
	int sp, dp;
	int i, cost;
	int lvl, diff, busy_time;
	        int b1,b2;
int maxpot;	        
	seteuid(getuid());

        if ( (!(fam = me->query("family")) || fam["family_name"] != "桃花岛") && !wizardp(me) )
		return notify_fail("只有桃花岛弟子才能打探别人的所在！\n");

	if( (lvl = (int)me->query_skill("count", 1)) < 10 )
		return notify_fail("你的阴阳八卦尚未纯熟，无法了解别人的所在！\n");


	if( ((int)me->query_skill("bibo-shengong", 1)) < 10 )
		return notify_fail("你的本门内功尚未纯熟！\n");
		
if (!environment(me))
                return notify_fail("不要影响别人，还是找一个别的地方吧。\n");
        if (environment(me)->query("sleep_room"))
                return notify_fail("不要影响别人，还是找一个别的地方吧。\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
       if( environment(me)->query("no_beg") ||
       environment(me)->query("no_fight") ||
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n不要影响别人，还是找一个别的地方吧。\n"NOR);

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

	if ( !arg )
		return notify_fail("你要打听谁的所在？\n");

if (me->query_condition("menpai_busy"))
return notify_fail("你才忙完，休息一下吧。\n");

        if ( present(arg, environment(me)) )
		return notify_fail("你要打听的人就在边上，你有问题吧？\n");

	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要打听谁的所在？\n");
        if( !wizardp(me) && wizardp(ob) ) 
		return notify_fail("你要打听谁的所在？\n");

	if ( ob == me )
		return notify_fail("你没这麽笨吧，要别人告诉你自己的所在？\n");
	if ( me->query("jing") <= 60 )		return notify_fail("现在你太累了，无法去打听别人的所在。\n");
if ( me->query("qi") <= 60 )		return notify_fail("现在你太累了，无法去打听别人的所在。\n");

	message_vision(CYN"$N拿起一只铁八卦屏心凝气，拇指依次掐向铁八卦上子、丑、寅、卯、辰、巳、午、未、申、酉、戌、亥\n各个方位，细心推算起来……\n\n\n"NOR, me);
	busy_time = 30 - lvl/10;
	if(busy_time < 8) busy_time = 8;
	if(busy_time > 20) busy_time = 20;
	me->start_busy(busy_time);
        me->add("jing", -me->query("max_jing")/15);
        me->add("qi", -me->query("max_qi")/15);
if( !environment(me)->query("no_fight"))
{
if (random(50)==1 && me->query("combat_exp") > 1200000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"巡逻官兵"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIY"附近走来一名很凶狠的巡逻官兵！\n"NOR, obj);
message_vision(HIR"$N说道: 你这个妖人竟敢惑众，我特来消灭你这等妖人！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return notify_fail("先把这恶官兵消灭再说吧？\n");
}
}
	message_vision(HIG"只见$N盘膝坐下，双手内握，口中念念有词，忽然脸露微笑: 有了!\n\n"NOR,me);

	sp = me->query_skill("count",1)*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	
	if ( random(sp) < random(dp)/2 )
{
		write(HIR"你殚精竭虑推算了半晌，却发现一无所得…… \n"NOR);
		me->set("jing", me->query("max_jing")/2);
                me->improve_skill("count",random((int)me->query_int()));
		return notify_fail( HIY"你又颓然坐下，摇了摇头，说道：不对的！\n"NOR);
}


	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在哪里耶...\n");
	if( !(where = environment(ob)) )
	        return notify_fail("这个人不知道在那里耶...\n");

        if( !wizardp(me) && wizardp(ob) ) 
		return notify_fail("大胆！竟想谋害巫师！\n");


//random(sp) < random(dp)
	if ( random(sp) > random(dp) )
	{
		if (strsrch(file_name(where), "city4") >= 0)
                tell_object(me,    ob->name()+"现在在长安城！\n"NOR);
		if (strsrch(file_name(where), "city") >= 0)
                tell_object(me,    ob->name()+"现在在扬州！\n"NOR);
		if (strsrch(file_name(where), "city3") >= 0)
			tell_object(me,    ob->name()+"的大概位置在成都城！\n");
		else if (strsrch(file_name(where), "city2") >= 0)
			tell_object(me,    ob->name()+"的大概位置在北京城！\n");
		else if (strsrch(file_name(where), "city") >= 0)
			tell_object(me,    ob->name()+"的大概位置在扬州城！\n");
		else if (strsrch(file_name(where), "dali") >= 0)
			tell_object(me,    ob->name()+"的大概位置在大理城！\n");
		else if (strsrch(file_name(where), "death") >= 0)
			tell_object(me,    ob->name()+"的大概位置在地狱里！\n");
		else if (strsrch(file_name(where), "emei") >= 0)
			tell_object(me,    ob->name()+"的大概位置在峨眉山上！\n");
		else if (strsrch(file_name(where), "foshan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在佛山镇！\n");
		else if (strsrch(file_name(where), "fuzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在福州城！\n");
		else if (strsrch(file_name(where), "gaibang") >= 0)
			tell_object(me,    ob->name()+"的大概位置在丐帮里！\n");
		else if (strsrch(file_name(where), "guanwai") >= 0)
			tell_object(me,    ob->name()+"的大概位置在关外！\n");
		else if (strsrch(file_name(where), "hangzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在杭州城！\n");
		else if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"的大概位置在黑木崖上！\n");
		else if (strsrch(file_name(where), "hengshan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在恒山上！\n");
		else if (strsrch(file_name(where), "henshan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在衡山上！\n");
		else if (strsrch(file_name(where), "henshan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在衡山上！\n");
		else if (strsrch(file_name(where), "huanggon") >= 0)
			tell_object(me,    ob->name()+"的大概位置在皇宫大内里！\n");
		else if (strsrch(file_name(where), "huashan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在华山上！\n");
		else if (strsrch(file_name(where), "lingjiu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在灵鹫峰上！\n");
		else if (strsrch(file_name(where), "mingjiao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在昆仑山上！\n");
		else if (strsrch(file_name(where), "qingcheng") >= 0)
			tell_object(me,    ob->name()+"的大概位置在青城山上！\n");
		else if (strsrch(file_name(where), "quanzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在泉州城！\n");
		else if (strsrch(file_name(where), "shaolin") >= 0)
			tell_object(me,    ob->name()+"的大概位置在少林寺里！\n");
		else if (strsrch(file_name(where), "shenlong") >= 0)
			tell_object(me,    ob->name()+"的大概位置在神龙岛上！\n");
		else if (strsrch(file_name(where), "songshan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在嵩山上！\n");
		else if (strsrch(file_name(where), "suzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在苏州城！\n");
		else if (strsrch(file_name(where), "taishan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在泰山上！\n");
		else if (strsrch(file_name(where), "taohua") >= 0)
			tell_object(me,    ob->name()+"的大概位置在桃花岛！\n");
		else if (strsrch(file_name(where), "tianlongsi") >= 0)
			tell_object(me,    ob->name()+"的大概位置在天龙寺里！\n");
		else if (strsrch(file_name(where), "village") >= 0)
			tell_object(me,    ob->name()+"的大概位置在华山村！\n");
		else if (strsrch(file_name(where), "wudang") >= 0)
			tell_object(me,    ob->name()+"的大概位置在武当山上！\n");
		else if (strsrch(file_name(where), "xiakedao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在侠客岛上！\n");
		else if (strsrch(file_name(where), "xiaoyao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在逍遥派里！\n");
		else if (strsrch(file_name(where), "xingxiu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在星宿海！\n");
		else if ((strsrch(file_name(where), "xuedao") >= 0) ||
		   (strsrch(file_name(where), "xueshan") >= 0))
			tell_object(me,    ob->name()+"的大概位置在大雪山上！\n");
		else if (strsrch(file_name(where), "yanziwu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在燕子坞！\n");
		else if (strsrch(file_name(where), "gumu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在终南山！\n");
		else if (strsrch(file_name(where), "meizhuang") >= 0)
			tell_object(me,    ob->name()+"的大概位置在梅庄！\n");
		else if (strsrch(file_name(where), "wanjiegu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在万劫谷！\n");
		else if (strsrch(file_name(where), "hg") >= 0)
			tell_object(me,    ob->name()+"的大概位置在皇宫大内！\n");
		else if (strsrch(file_name(where), "nio") >= 0)
			tell_object(me,    ob->name()+"的大概位置在牛家村！\n");			
		else if (strsrch(file_name(where), "feihu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在闯王宝藏！\n");
		else if (strsrch(file_name(where), "wuguan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在襄阳武馆！\n");
		else if (strsrch(file_name(where), "village") >= 0)
			tell_object(me,    ob->name()+"的大概位置在华山村！\n");
		else if (strsrch(file_name(where), "wanjiegu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在万劫谷！\n");
		else if (strsrch(file_name(where), "pingan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在平安城！\n");
		else if (strsrch(file_name(where), "taohuacun") >= 0)
			tell_object(me,    ob->name()+"的大概位置在桃花村！\n");
		else if (strsrch(file_name(where), "lingxiao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在凌霄城！\n");
		else if (strsrch(file_name(where), "wudujiao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在五毒教！\n");
		else if (strsrch(file_name(where), "jqg") >= 0)
			tell_object(me,    ob->name()+"的大概位置在绝情谷！\n");
		else if (strsrch(file_name(where), "sdxl") >= 0)
			tell_object(me,    ob->name()+"的大概位置在剑魔独孤求败墓！\n");
		else if (strsrch(file_name(where), "fairyland") >= 0)
			tell_object(me,    ob->name()+"的大概位置在昆仑附近的红梅山庄！\n");
		else if (strsrch(file_name(where), "changcheng") >= 0)
			tell_object(me,    ob->name()+"的大概位置在北京以北长城！\n");
		else if (strsrch(file_name(where), "jyguan") >= 0)
			tell_object(me,    ob->name()+"的大概位置在兰州以北嘉峪关！\n");
		else if (strsrch(file_name(where), "lanzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在兰州！\n");
		else if (strsrch(file_name(where), "yanjing") >= 0)
			tell_object(me,    ob->name()+"的大概位置在燕京！\n");
		else if (strsrch(file_name(where), "jingzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在荆州！\n");
		else if (strsrch(file_name(where), "kunming") >= 0)
			tell_object(me,    ob->name()+"的大概位置在昆明！\n");
		else if (strsrch(file_name(where), "ruzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在汝州城！\n");
		else if (strsrch(file_name(where), "lingshedao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在灵蛇岛！\n");
		else if (strsrch(file_name(where), "qianjin") >= 0)
			tell_object(me,    ob->name()+"的大概位置在北京千金楼！\n");
		else if (strsrch(file_name(where), "menggu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在蒙古草原！\n");
		else if (strsrch(file_name(where), "yinju") >= 0)
			tell_object(me,    ob->name()+"的大概位置在一灯大师居！\n");
		else if (strsrch(file_name(where), "huizhu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在回族部落！\n");
		else if (strsrch(file_name(where), "tiezhang") >= 0)
			tell_object(me,    ob->name()+"的大概位置在铁掌门！\n");
		else if (strsrch(file_name(where), "kunlun") >= 0)
			tell_object(me,    ob->name()+"的大概位置在昆仑山！\n");
		else if (strsrch(file_name(where), "baituo") >= 0)
			tell_object(me,    ob->name()+"的大概位置在白驼山！\n");
		else if (strsrch(file_name(where), "binghuodao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在冰火岛！\n");
		else if (strsrch(file_name(where), "gaochang") >= 0)
			tell_object(me,    ob->name()+"的大概位置在高昌迷宫！\n");
		else if (strsrch(file_name(where), "gumu") >= 0)
			tell_object(me,    ob->name()+"的大概位置在古墓派！\n");
		else if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"的大概位置在黑木崖！\n");
		else if (strsrch(file_name(where), "huanghe") >= 0)
			tell_object(me,    ob->name()+"的大概位置在黄河九曲！\n");
		else if (strsrch(file_name(where), "lingzhou") >= 0)
			tell_object(me,    ob->name()+"的大概位置在灵州！\n");
		else if (strsrch(file_name(where), "meizhuang") >= 0)
			tell_object(me,    ob->name()+"的大概位置在梅庄！\n");
		else if (strsrch(file_name(where), "mingjiao") >= 0)
			tell_object(me,    ob->name()+"的大概位置在明教！\n");
		else if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"的大概位置在黑木崖！\n");

		else tell_object(me,    ob->name()+"现在在某个地方的"+where->query("short")+"附近！\n");
	}
	if (random(10)>7)
	{
if (userp(ob))
{
                if( (random(lvl/4)) < ob->query("kar") )
                tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......\n"NOR);
}


		printf("%s现在在%s。\n",
		(string)ob->name(), place_desc[random(sizeof(place_desc))]);
		return 1;
	}
if (userp(ob))
{
                if( (random(lvl/4)) < ob->query("kar") )
                tell_object(ob, HIB"你感觉心神不定，似乎有人在暗中窥视着你......\n"NOR);
}
//b1=b1/2+8;
//addnl(me,"exp",b1);
b1=random(18)+28;
b2=random(18)+8;
b1=b1/2+8;
addnl(me,"exp",b1);

	printf("%s现在在%s。\n",
		(string)ob->name(),
		(string)where->query("short"));
me->apply_condition("menpai_busy",2);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: location <玩家的 ID>

这个指令是桃花岛弟子用来得知玩家目前所在的位置.

HELP
	);
	return 1;
}

