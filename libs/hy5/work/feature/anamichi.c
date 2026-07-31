#include <ansi.h>

int get_anamichi(object me,string meridian,mapping *anamichis);
mapping get_meridian(string meri);
mapping *get_anamichis(string meri);
int chongxue(object me, string meridian);
int breaking(object me);

/*效果分别为：A增加精气，B增加气血，C战斗中恢复精气，D恢复气血*/
//按穴道序号，5以下一种特效，10以下二种特效，超过10有三种特效，全通再增加所有四种特效翻倍效果

mapping *meridians = ({
(["mer":"阴 跷 脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"阴 维 脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"阳 跷 脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"带    脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"阳 维 脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"冲    脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"督    脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"任    脉","A":2,"B":2,"C":2,"D":2,]),
(["mer":"经外奇脉","A":2,"B":2,"C":2,"D":2,]),
	});

mapping *anamichi_m1 = ({
(["ana":"然谷穴","A":1,"B":0,"C":0,"D":0,"force":100]),
(["ana":"照海穴","A":1,"B":0,"C":0,"D":0,"force":125]),
(["ana":"交信穴","A":0,"B":1,"C":0,"D":0,"force":150]),
(["ana":"阴谷穴","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"横谷穴","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"气冲穴","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"乳根穴","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"盆缺穴","A":1,"B":0,"C":0,"D":1,"force":275]),
(["ana":"人迎穴","A":1,"B":0,"C":0,"D":1,"force":300]),
(["ana":"睛明穴","A":1,"B":0,"C":1,"D":0,"force":325]),
(["ana":"不容穴","A":1,"B":0,"C":1,"D":0,"force":350]),
(["ana":"梁门穴","A":1,"B":0,"C":1,"D":1,"force":375]),
(["ana":"横鼻穴","A":0,"B":1,"C":1,"D":1,"force":400]),
(["ana":"足三里","A":1,"B":0,"C":1,"D":1,"force":425]),
(["ana":"丰隆穴","A":0,"B":1,"C":1,"D":1,"force":450]),
(["ana":"解溪穴","A":1,"B":1,"C":1,"D":0,"force":475]),
(["ana":"冲阳穴","A":1,"B":1,"C":1,"D":0,"force":500]),
(["ana":"属兑穴","A":1,"B":1,"C":1,"D":0,"force":525]),
	});
mapping *anamichi_m2 = ({
(["ana":"府舍穴","A":0,"B":0,"C":0,"D":1,"force":100]),
(["ana":"大横穴","A":0,"B":1,"C":0,"D":0,"force":125]),
(["ana":"阳交穴","A":1,"B":0,"C":0,"D":0,"force":150]),
(["ana":"腹哀穴","A":0,"B":0,"C":1,"D":0,"force":175]),
(["ana":"期门穴","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"廉泉穴","A":0,"B":0,"C":0,"D":1,"force":225]),
(["ana":"极泉穴","A":0,"B":1,"C":0,"D":1,"force":250]),
(["ana":"青灵穴","A":1,"B":0,"C":1,"D":0,"force":275]),
(["ana":"少海穴","A":1,"B":0,"C":0,"D":1,"force":300]),
(["ana":"灵道穴","A":1,"B":0,"C":0,"D":1,"force":325]),
(["ana":"通里穴","A":0,"B":1,"C":1,"D":0,"force":350]),
(["ana":"阴郄穴","A":1,"B":0,"C":1,"D":1,"force":375]),
(["ana":"神门穴","A":1,"B":1,"C":1,"D":0,"force":400]),
(["ana":"少府穴","A":1,"B":0,"C":1,"D":1,"force":425]),
(["ana":"少冲穴","A":0,"B":1,"C":1,"D":1,"force":450]),
(["ana":"筑宾穴","A":1,"B":1,"C":0,"D":1,"force":475]),
	});
mapping *anamichi_m3 = ({
(["ana":"申脉穴","A":0,"B":0,"C":1,"D":0,"force":100]),
(["ana":"仆参穴","A":0,"B":0,"C":0,"D":1,"force":125]),
(["ana":"跗阳穴","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"居髎穴","A":0,"B":0,"C":0,"D":1,"force":175]),
(["ana":"臑俞穴","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"肩髃穴","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"巨骨穴","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"地仓穴","A":0,"B":0,"C":1,"D":1,"force":275]),
(["ana":"巨髎穴","A":0,"B":0,"C":1,"D":1,"force":300]),
(["ana":"承泣穴","A":0,"B":0,"C":1,"D":1,"force":325]),
(["ana":"风池穴","A":1,"B":1,"C":0,"D":0,"force":350]),
(["ana":"攒竹穴","A":0,"B":1,"C":1,"D":1,"force":375]),
(["ana":"眉冲穴","A":1,"B":1,"C":1,"D":0,"force":400]),
(["ana":"曲差穴","A":0,"B":1,"C":1,"D":1,"force":425]),
(["ana":"五处穴","A":1,"B":1,"C":1,"D":0,"force":450]),
(["ana":"承光穴","A":0,"B":1,"C":1,"D":1,"force":475]),
(["ana":"通天穴","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"络却穴","A":1,"B":1,"C":0,"D":1,"force":525]),
(["ana":"玉枕穴","A":1,"B":1,"C":0,"D":1,"force":550]),
(["ana":"天柱穴","A":1,"B":1,"C":1,"D":0,"force":575]),
(["ana":"承山穴","A":1,"B":0,"C":1,"D":1,"force":600]),
(["ana":"飞扬穴","A":1,"B":1,"C":0,"D":1,"force":625]),
(["ana":"昆仑穴","A":1,"B":1,"C":0,"D":1,"force":650]),
	});
mapping *anamichi_m4 = ({
(["ana":"带脉穴","A":0,"B":0,"C":1,"D":0,"force":100]),
(["ana":"五枢穴","A":1,"B":0,"C":0,"D":0,"force":125]),
(["ana":"维  穴","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"天冲穴","A":0,"B":0,"C":0,"D":1,"force":175]),
(["ana":"浮白穴","A":0,"B":1,"C":0,"D":0,"force":200]),
(["ana":"头窍阴","A":0,"B":1,"C":0,"D":0,"force":225]),
(["ana":"完骨穴","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"本神穴","A":0,"B":1,"C":1,"D":0,"force":275]),
(["ana":"阳白穴","A":0,"B":1,"C":1,"D":0,"force":300]),
(["ana":"头临泣","A":0,"B":0,"C":1,"D":1,"force":325]),
(["ana":"目窗穴","A":0,"B":0,"C":1,"D":1,"force":350]),
(["ana":"正营穴","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"承灵穴","A":1,"B":0,"C":1,"D":1,"force":400]),
(["ana":"脑空穴","A":0,"B":1,"C":1,"D":1,"force":425]),
(["ana":"外丘穴","A":1,"B":1,"C":0,"D":1,"force":450]),
(["ana":"光明穴","A":1,"B":1,"C":0,"D":1,"force":475]),
(["ana":"阳辅穴","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"悬钟穴","A":1,"B":1,"C":0,"D":1,"force":525]),
(["ana":"丘墟穴","A":1,"B":1,"C":0,"D":1,"force":550]),
	});
mapping *anamichi_m5 = ({
(["ana":"金门穴","A":0,"B":1,"C":0,"D":0,"force":100]),
(["ana":"阳交穴","A":0,"B":0,"C":0,"D":1,"force":125]),
(["ana":"臑俞穴","A":0,"B":1,"C":0,"D":0,"force":150]),
(["ana":"天髎穴","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"肩井穴","A":0,"B":0,"C":1,"D":0,"force":200]),
(["ana":"头维穴","A":0,"B":1,"C":0,"D":0,"force":225]),
(["ana":"本神穴","A":0,"B":1,"C":1,"D":0,"force":250]),
(["ana":"阳白穴","A":0,"B":0,"C":1,"D":1,"force":275]),
(["ana":"头临泣","A":0,"B":1,"C":1,"D":0,"force":300]),
(["ana":"目窗穴","A":1,"B":1,"C":0,"D":0,"force":325]),
(["ana":"正营穴","A":1,"B":1,"C":0,"D":0,"force":350]),
(["ana":"承灵穴","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"脑空穴","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"风池穴","A":1,"B":1,"C":0,"D":1,"force":425]),
(["ana":"风府穴","A":1,"B":1,"C":0,"D":1,"force":450]),
(["ana":"哑门穴","A":1,"B":0,"C":1,"D":1,"force":475]),
(["ana":"云门穴","A":1,"B":1,"C":0,"D":1,"force":500]),
(["ana":"尺泽穴","A":0,"B":1,"C":1,"D":1,"force":525]),
(["ana":"孔最穴","A":1,"B":0,"C":1,"D":1,"force":550]),
(["ana":"列缺穴","A":1,"B":0,"C":1,"D":1,"force":575]),
(["ana":"经渠穴","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"太渊穴","A":0,"B":1,"C":1,"D":1,"force":625]),
(["ana":"鱼际穴","A":0,"B":1,"C":1,"D":1,"force":650]),
(["ana":"少商穴","A":0,"B":1,"C":1,"D":1,"force":675]),
	});
mapping *anamichi_m6 = ({
(["ana":"会阴穴","A":1,"B":0,"C":0,"D":0,"force":100]),
(["ana":"阴交穴","A":1,"B":0,"C":0,"D":0,"force":125]),
(["ana":"气冲穴","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"横骨穴","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"大赫穴","A":1,"B":0,"C":0,"D":0,"force":200]),
(["ana":"气  穴","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"四满穴","A":0,"B":1,"C":1,"D":0,"force":250]),
(["ana":"中注穴","A":0,"B":1,"C":0,"D":1,"force":275]),
(["ana":"肓俞穴","A":1,"B":0,"C":0,"D":1,"force":300]),
(["ana":"商曲穴","A":1,"B":0,"C":0,"D":1,"force":325]),
(["ana":"石关穴","A":1,"B":0,"C":1,"D":0,"force":350]),
(["ana":"阴都穴","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"通谷穴","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"幽门穴","A":1,"B":1,"C":0,"D":1,"force":425]),
(["ana":"关门穴","A":1,"B":0,"C":1,"D":1,"force":450]),
(["ana":"太乙穴","A":1,"B":0,"C":1,"D":1,"force":475]),
(["ana":"滑肉门","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"天枢穴","A":0,"B":1,"C":1,"D":1,"force":525]),
(["ana":"外陵穴","A":1,"B":1,"C":0,"D":1,"force":550]),
(["ana":"大巨穴","A":0,"B":1,"C":1,"D":1,"force":575]),
(["ana":"水道穴","A":1,"B":0,"C":1,"D":1,"force":600]),
(["ana":"归来穴","A":1,"B":0,"C":1,"D":1,"force":625]),
(["ana":"水突穴","A":1,"B":1,"C":0,"D":1,"force":650]),
(["ana":"气舍穴","A":1,"B":1,"C":1,"D":0,"force":675]),
	});
mapping *anamichi_m7 = ({
(["ana":"长强穴","A":0,"B":0,"C":1,"D":0,"force":100]),
(["ana":"腰俞穴","A":0,"B":0,"C":1,"D":0,"force":125]),
(["ana":"命门穴","A":0,"B":0,"C":0,"D":1,"force":150]),
(["ana":"悬枢穴","A":0,"B":1,"C":0,"D":0,"force":175]),
(["ana":"脊中穴","A":0,"B":1,"C":0,"D":0,"force":200]),
(["ana":"至中枢","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"筋缩穴","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"灵台穴","A":1,"B":1,"C":0,"D":0,"force":275]),
(["ana":"神道穴","A":0,"B":1,"C":0,"D":1,"force":300]),
(["ana":"身柱穴","A":1,"B":1,"C":0,"D":0,"force":325]),
(["ana":"陶道开","A":1,"B":0,"C":1,"D":0,"force":350]),
(["ana":"大椎穴","A":1,"B":0,"C":1,"D":1,"force":375]),
(["ana":"风府穴","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"脑户穴","A":1,"B":1,"C":1,"D":0,"force":425]),
(["ana":"强间穴","A":1,"B":0,"C":1,"D":1,"force":450]),
(["ana":"后顶排","A":0,"B":1,"C":1,"D":1,"force":475]),
(["ana":"百会穴","A":0,"B":1,"C":1,"D":1,"force":500]),
(["ana":"囟会穴","A":0,"B":1,"C":1,"D":1,"force":525]),
(["ana":"上星穴","A":1,"B":0,"C":1,"D":1,"force":550]),
(["ana":"神庭穴","A":1,"B":1,"C":1,"D":0,"force":575]),
(["ana":"素  穴","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"水沟穴","A":1,"B":1,"C":1,"D":0,"force":625]),
(["ana":"兑端穴","A":1,"B":0,"C":1,"D":1,"force":650]),
(["ana":"龈交穴","A":0,"B":1,"C":1,"D":1,"force":675]),
	});
mapping *anamichi_m8 = ({
(["ana":"曲骨穴","A":1,"B":0,"C":0,"D":0,"force":100]),
(["ana":"中极穴","A":0,"B":0,"C":1,"D":0,"force":125]),
(["ana":"关元穴","A":0,"B":0,"C":1,"D":0,"force":150]),
(["ana":"下脘穴","A":0,"B":0,"C":1,"D":0,"force":175]),
(["ana":"中脘穴","A":0,"B":0,"C":0,"D":1,"force":200]),
(["ana":"上脘穴","A":0,"B":0,"C":1,"D":0,"force":225]),
(["ana":"天突穴","A":0,"B":1,"C":0,"D":1,"force":250]),
(["ana":"廉泉穴","A":1,"B":0,"C":0,"D":1,"force":275]),
(["ana":"承浆穴","A":1,"B":0,"C":1,"D":0,"force":300]),
(["ana":"大钟穴","A":0,"B":1,"C":1,"D":0,"force":325]),
(["ana":"水泉穴","A":1,"B":0,"C":0,"D":1,"force":350]),
(["ana":"大赫穴","A":1,"B":1,"C":1,"D":0,"force":375]),
(["ana":"灵墟穴","A":1,"B":1,"C":0,"D":1,"force":400]),
(["ana":"箕门穴","A":1,"B":1,"C":1,"D":0,"force":425]),
(["ana":"涌泉穴","A":1,"B":1,"C":0,"D":1,"force":450]),
(["ana":"神封穴","A":1,"B":1,"C":1,"D":0,"force":475]),
(["ana":"地机穴","A":1,"B":0,"C":1,"D":1,"force":500]),
(["ana":"血海穴","A":1,"B":1,"C":1,"D":0,"force":525]),
(["ana":"腹通谷","A":1,"B":1,"C":1,"D":0,"force":550]),
(["ana":"步廊穴","A":1,"B":1,"C":0,"D":1,"force":575]),
(["ana":"神藏穴","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"俞府穴","A":1,"B":1,"C":0,"D":1,"force":625]),
(["ana":"复溜穴","A":1,"B":1,"C":1,"D":0,"force":650]),
(["ana":"阴陵泉","A":1,"B":0,"C":1,"D":1,"force":675]),
	});
mapping *anamichi_m9 = ({
(["ana":"神聪穴","A":0,"B":0,"C":0,"D":1,"force":100]),
(["ana":"印堂穴","A":0,"B":0,"C":1,"D":0,"force":125]),
(["ana":"鱼腰穴","A":0,"B":0,"C":1,"D":0,"force":150]),
(["ana":"太阳穴","A":0,"B":0,"C":0,"D":1,"force":175]),
(["ana":"耳尖穴","A":0,"B":0,"C":1,"D":0,"force":200]),
(["ana":"球后穴","A":0,"B":1,"C":0,"D":0,"force":225]),
(["ana":"金津穴","A":1,"B":0,"C":1,"D":0,"force":250]),
(["ana":"玉液穴","A":1,"B":0,"C":1,"D":0,"force":275]),
(["ana":"翳明穴","A":1,"B":0,"C":1,"D":0,"force":300]),
(["ana":"定喘穴","A":1,"B":1,"C":0,"D":0,"force":325]),
(["ana":"夹脊穴","A":1,"B":1,"C":0,"D":0,"force":350]),
(["ana":"腰奇穴","A":1,"B":1,"C":0,"D":1,"force":375]),
(["ana":"二白穴","A":1,"B":0,"C":1,"D":1,"force":400]),
(["ana":"腰痛点","A":1,"B":0,"C":1,"D":1,"force":425]),
(["ana":"八邪穴","A":0,"B":1,"C":1,"D":1,"force":450]),
(["ana":"四缝穴","A":1,"B":0,"C":1,"D":1,"force":475]),
(["ana":"十宣穴","A":0,"B":1,"C":1,"D":1,"force":500]),
(["ana":"鹤顶穴","A":1,"B":1,"C":1,"D":0,"force":525]),
(["ana":"百虫窝","A":1,"B":0,"C":1,"D":1,"force":550]),
(["ana":"膝眼穴","A":0,"B":1,"C":1,"D":1,"force":575]),
(["ana":"胆囊穴","A":0,"B":1,"C":1,"D":1,"force":600]),
(["ana":"阑尾穴","A":0,"B":1,"C":1,"D":1,"force":625]),
(["ana":"八风穴","A":1,"B":0,"C":1,"D":1,"force":650]),
	});
int chongxue(object me, string arg)
{
	object where;
	int i;
	string meri;
	mapping anamichi;
	mapping *anamichis;
	mapping meridian;
	seteuid(getuid());
	where = environment(me);
	
	switch (arg)
	{
		case "m1":
		case "m2":
		case "m3":
		case "m4":
		case "m5":
		case "m6":
		case "m7":
		case "m8":
		case "m9":
			break;
		default:
			return notify_fail("请指定经脉代号! (m1-m9)\n");
	}

	meri = arg;
	meridian = get_meridian(meri);
	anamichis = get_anamichis(meri);
		
	//查找所冲经脉的穴道，用这个命令只能按穴位顺序依次冲穴
	i = get_anamichi(me,arg,anamichis);
	if(i>=(sizeof(anamichis)))
		return notify_fail(meridian["mer"]+"的穴道你已经全部打通，没有必要再打通一次!\n");
	
	//if (i<=0) i=0;
	anamichi=anamichis[i];

	if (where->query("pigging"))
	    return notify_fail("你还是专心拱猪吧！\n");
	
	if (! where->query("no_fight"))
	    return notify_fail("在这里打通经脉穴道？不太安全吧？\n");
	
	if (! where->query("sleep_room"))
	    return notify_fail("你得找一个能够休息的地方闭关修行。\n");
	
	if ( where->query("pingan"))
	    return notify_fail("这个地方不允许。\n");
	
	if ( where->query("biwu"))
	    return notify_fail("这个地方不允许。\n");
	
	if ( where->query("citybiwu"))
	    return notify_fail("这个地方不允许。\n");


//	if (!wizardp(me))
//	    return notify_fail("未开放,内部测试中。\n");

	
	if (me->query_temp("biguan"))
	    return notify_fail("你正在闭关打通经脉。\n");
	
	if (me->is_busy())
	    return notify_fail("你现在正忙着呢。\n");
		
	if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
	    return notify_fail("你现在的气太少了，无法静心闭关。\n");
	
	if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
	    return notify_fail("你现在的精太少了，无法静心闭关。\n");
	
	if ((int)me->query("max_neili") < (int)anamichi["force"]*3/2)
	    return notify_fail("你觉得内力颇有不足，看来目前还难以打通"+meridian["mer"]+"的"+anamichi["ana"]+"。\n");

	if ((int)me->query_skill("force", 1) < (int)anamichi["force"])
	    return notify_fail("你觉得自己的内功火候还有限，看来需要先锻炼好内功才行。\n");

	if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
	    return notify_fail("你现在的内力太少了，无法静心闭关。\n");
	if (me->query_condition("bg_busy") && !wizardp(me))
	    return notify_fail("你刚闭过关，休息几天再来吧!\n");
	
	message_vision("$N盘膝坐下，开始冥神运功，闭关修行，试图打通"+meridian["mer"]+"的"+HIY+anamichi["ana"]+NOR"。\n", me);
		
	me->set_temp("biguan", 1);
	me->set("doing", "breakup");
	me->set_temp("meri",meri);
	me->set_temp("anami",i);
	//message_vision("$N测试"+meri+"的"+i+NOR"。\n", me);
	
	me->apply_condition("bg_busy",100);
	me->start_busy(10);

        //if (call_out("breaking", 10, me) && !me->query("breakup"))
                call_out("breaking", 10, me);
	return 1;
}

int breaking(object me)
{
	string msg;
	int i,anaok,merok,tempana;
	string meri = me->query_temp("meri");
	int anami= (int)me->query_temp("anami");
  int nl,fc;	
	mapping meridian = get_meridian(meri);
	mapping *anamichis = get_anamichis(meri);
	mapping anamichi = anamichis[anami];
	//message_vision("测试!", me);


	if (!me)  return notify_fail("你已经断线了！\n");
    anaok = 0;
    merok = 0;


	if( !me->query_temp("biguan") )
        {
                tell_object(me, "你打算下次再冲穴。\n");
                message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }



        if( (int)me->query("potential") < 10 )
        {
                tell_object(me, "你的潜能耗尽了。\n");
                message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }


if((int)me->query("potential") - (int)me->query("learned_points") < 200 ) 
        {
                tell_object(me, "你的潜能耗尽了。\n");
                message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }
	if( (int)me->query("learned_points") < 1 )
        {
                tell_object(me, "你的潜能耗尽了。\n");
                message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        me->set_temp("biguan", 0);
                        		me->delete_temp("meri");
		me->delete_temp("anami");
                        call_out("user_quit", 0, me);
                }

                return 0;
        }
        if (me->query("potential") <= me->query("learned_points"))
        {
                tell_object(me, "你的潜能耗尽了。\n");
                message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);

                if (! interactive(me))
                {
                        me->force_me("chat* sigh");
                        		me->delete_temp("meri");
		me->delete_temp("anami");
                        me->set_temp("biguan", 0);
                        call_out("user_quit", 0, me);
                }

                return 0;
        }

        if (random(2)==0) me->add("potential",-1);


	if (random(me->query_skill("force",1)*6) < me->query("con") *me->query_skill("force",1) /100 && (me->query("ana/"+meri)< (anami+1)))
	{
		message_vision(HIW "只见$N" HIW "头上白雾腾腾、浑身"
					 "如同笼罩在云中，看来已经到了三花聚顶、"
					 "五气朝元、龙虎相济、天人交会的紧要关头！\n" NOR, me);
		tell_object(me, HIR "你觉得内力在丹田源源而生，不断"
				  "冲击"+meridian["mer"]+"的"+anamichi["ana"]+HIR"，浑身燥热难当，几欲大声呼喊。\n" NOR);
		message_vision(HIC "突然$N" HIC "大喝一声，一股无形气浪"
					 "陡然散布开来，四周空气登时变得燥热。\n" NOR, me);
		tell_object(me, HIG "你顿时觉得浑身一阵轻松，一股清凉之意油然"
				  "而起，心灵一片空明，内力通过"+meridian["mer"]+"的"+anamichi["ana"]+HIG"时没有丝毫阻滞，舒泰之极。\n" NOR);
		tell_object(me, HIC "恭喜你打通了"+meridian["mer"]+"的"+anamichi["ana"]+HIC+"自身修为又上了一个台阶。\n" NOR);
		if (anami+1>=sizeof(anamichis))
		{
			anaok = 1;
			tell_object(me, HIG "恭喜你打通了"+meridian["mer"] + "的所有穴道，内力在"+meridian["mer"] + "的所有穴道游走，畅通无比。\n" NOR);
		}	
		me->set_temp("biguan", 0);
		me->delete_temp("meri");
		me->delete_temp("anami");
		anami=anami+1;
		me->set("ana/"+meri, anami);

if (!present("chongxue tongren", me))
{

nl=me->query("max_neili",1)-me->query("max_neili",1)/4;	
fc=me->query_skill("force",1)-me->query_skill("force",1)/4;
        if (random(80)==2  && !present("chongxue tongren", me))
{
me->set_skill("force",fc);
me->set("max_neili",nl);
me->die();
			tell_object(me, HIR "你五官流血，吐血不止，看来走火入魔无药可救了。\n" NOR);	
}	
else        if (random(60)==0 && !present("chongxue tongren", me))
{
me->set("max_neili",nl);
			tell_object(me, RED "你吐出一口鲜血，看来走火入魔了，内功受到了损伤。\n" NOR);	
}	
else        if (random(70)==1 && !present("chongxue tongren", me))
{
me->set_skill("force",fc);
			tell_object(me, RED "你吐出一大口鲜血，看来走火入魔了，内力受到了损伤。\n" NOR);	
}	


}




			//经脉全通。
			if ((get_anamichi(me,"m1",anamichi_m1)>=sizeof(anamichi_m1)) &&
				(get_anamichi(me,"m2",anamichi_m2)>=sizeof(anamichi_m2)) &&
				(get_anamichi(me,"m3",anamichi_m3)>=sizeof(anamichi_m3)) &&
				(get_anamichi(me,"m4",anamichi_m4)>=sizeof(anamichi_m4)) &&
				(get_anamichi(me,"m5",anamichi_m5)>=sizeof(anamichi_m5)) &&
				(get_anamichi(me,"m6",anamichi_m6)>=sizeof(anamichi_m6)) &&
				(get_anamichi(me,"m7",anamichi_m7)>=sizeof(anamichi_m7)) &&
				(get_anamichi(me,"m8",anamichi_m8)>=sizeof(anamichi_m8)) &&
				(get_anamichi(me,"m9",anamichi_m9)>=sizeof(anamichi_m9)))
			{
				merok = 1;
				tell_object(me, HIC "恭喜你打通了所有经脉，内力在全身的所有穴道游走，畅通无比。\n" NOR);
			}

		//精气内力如果有增加，则增加的数值是force的1/50
		me->add("max_jing",me->query_skill("force",1)*2 /50*(int)anamichi["A"]);
		me->add("eff_jing",me->query_skill("force",1)*2 /50*(int)anamichi["A"]);

		me->add("max_qi",me->query_skill("force",1)*2 /50*(int)anamichi["B"]);
		me->add("eff_qi",me->query_skill("force",1)*2 /50*(int)anamichi["B"]);
		
		me->add("combat_exp",(int)anamichi["force"]*100);
		me->add("potential",(int)anamichi["force"]*50);
		//该经脉全通
		if (anaok==1)
		{
			//精气内力如果有增加，则增加的数值是force的1/50
			me->add("max_jing",me->query_skill("force",1)*2 /50*(int)meridian["A"]);
			me->add("eff_jing",me->query_skill("force",1)*2 /50*(int)meridian["A"]);
		
			me->add("max_qi",me->query_skill("force",1)*2 /50*(int)meridian["B"]);
			me->add("eff_qi",me->query_skill("force",1)*2 /50*(int)meridian["B"]);
			
			me->add("combat_exp",me->query_skill("force",1) *100);
			me->add("potential",me->query_skill("force",1) *50);
		}	

		//所有经脉全通
		if (merok==1)
		{
			//精气内力如果有增加，则增加的数值是force的1/10
			me->add("max_jing",me->query_skill("force",1)*2 /10);
			me->add("eff_jing",me->query_skill("force",1)*2 /10);
		
			me->add("max_qi",me->query_skill("force",1)*2 /10);
			me->add("eff_qi",me->query_skill("force",1)*2 /10);

			me->add("combat_exp",me->query_skill("force",1) *300);
			me->add("potential",me->query_skill("force",1) *200);
          me->set("breakup", 1);
   	    me->set_skill("biguan",200);
			
		}	

		me->save();
		return 0;
	}
	else
	{
		switch (random(5))
		{
			case 0:
				msg = "你默默运转内力，隐隐有些感觉。\n";
				me->start_busy(5);
				break;
			case 1:
				msg = "你将内力运经诸穴，抵四肢百赅，然后又回收丹田。\n";
				me->start_busy(5);
				break;
			case 2:
				msg = "你在丹田中不断积蓄内力，只觉得浑身燥热。\n";
				me->start_busy(5);
				break;
			default:
				msg = "你缓缓呼吸吐纳，将空气中水露皆收为己用。\n";
				me->start_busy(5);
				break;
		}
	
		tell_object(me, msg);
		call_out("breaking", 5, me);
		return 0;
	}
}

int get_anamichi(object me,string meridian,mapping *anamichis)
{
	if ((int)me->query("ana/"+meridian)>=sizeof(anamichis))
		return sizeof(anamichis);
	else
		return (int)me->query("ana/"+meridian);
}

mapping get_meridian(string meri)
{
	mapping meridian;
	switch (meri)
	{
		case "m1":
			meridian = meridians[0];
			break;
		case "m2":
			meridian = meridians[1];
			break;
		case "m3":
			meridian = meridians[2];
			break;
		case "m4":
			meridian = meridians[3];
			break;
		case "m5":
			meridian = meridians[4];
			break;
		case "m6":
			meridian = meridians[5];
			break;
		case "m7":
			meridian = meridians[6];
			break;
		case "m8":
			meridian = meridians[7];
			break;
		case "m9":
			meridian = meridians[8];
			break;
	}
	return meridian;
}

mapping *get_anamichis(string meri)
{
	mapping *anamichis;
	switch (meri)
	{
		case "m1":
			anamichis = anamichi_m1;
			break;
		case "m2":
			anamichis = anamichi_m2;
			break;
		case "m3":
			anamichis = anamichi_m3;
			break;
		case "m4":
			anamichis = anamichi_m4;
			break;
		case "m5":
			anamichis = anamichi_m5;
			break;
		case "m6":
			anamichis = anamichi_m6;
			break;
		case "m7":
			anamichis = anamichi_m7;
			break;
		case "m8":
			anamichis = anamichi_m8;
			break;
		case "m9":
			anamichis = anamichi_m9;
			break;
	}
	return anamichis;
}
