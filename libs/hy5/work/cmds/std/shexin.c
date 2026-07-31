// shexin.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string dest, cmd, verb;
        object ob,obj;
        mapping fam;

        seteuid(getuid());

        if( environment(me)->query("no_fight") )
                return notify_fail("这里禁止战斗。\n");
        if( me != this_player() ) return 0;
        me = this_player();
        if ((!(fam = me->query("family")) || fam["family_name"] != "雪山寺"))
             return notify_fail("只有雪山弟子才能行使慑心术！\n");          
        if (me->query_skill("necromancy",1) < 40)
             return notify_fail("你的降伏法还太浅薄了，没法行使慑心术。\n");

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式: shexin <某人> to <指令>\n");

//      if (!ob = get_object( dest ) )
        if( !objectp(ob = present(dest, environment(me))))
                return notify_fail("找不到" + dest + "。\n");
        if( !living(ob) )
                return notify_fail("这个物件不能被慑心。\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("你没法对" + ob->name() + "行使慑心术。\n");

	if( !ob->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");
	if(ob->query_temp("host"))
		return notify_fail("你不能慑心这个人。\n");
	if(!userp(ob) && ob->query_leader())
		return notify_fail("你不能慑心这个人。\n");

	if(userp(ob) &&  me->query("age")<=19)
		return notify_fail("要经验>600k,年岁>20才能使用慑心术。\n");

	if(userp(ob) && me->query("combat_exp")<600000)
		return notify_fail("要经验>600k,年岁>18才能使用慑心术。\n");

	if(ob->query_temp("no_kill"))
		return notify_fail("你不能慑心这个人。\n");

        if( ob->query("winner") )
		return notify_fail("此人不能慑心。\n");

	if( ob->query("tasknpc"))
		return notify_fail("此人不能慑心。\n");

        if (userp(me) && userp(ob)
         && ob->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(ob)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");
        
    if( userp(me) && userp(ob) && ob->query_condition("nokill")
    && !ob->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");
if( !living(ob) && userp(ob) && ob->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");        
        if( ob->query("ownmake") )
                return notify_fail("此人不能慑心。\n");

//        if( ob->query("env/no_fight") )
//        return notify_fail("不能慑心，慑心不得啊！\n");

    if( userp(ob) && ob->query("PKS")<=0 && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(ob) && ob->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");


//免战系统
obj=ob;
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");

	if( ob->is_fighting() )
	return notify_fail("此人正打的热闹着呢!\n");

	if( me->is_fighting() )
	return notify_fail("你正打的热闹着呢!\n");

	if(ob->query("no_get"))
		return notify_fail("你不能慑心这个人。\n");

 //&& strsrch(base_name(ob),"/quest/")>1
	if(!userp(ob)&& strsrch(base_name(ob),"quest") > 0)
//{
//        message_vision(HIG "文件名:"+base_name(ob)+"!\n" NOR, me);
		return notify_fail("此人和任务有关，不能慑心。\n");
//}

//if (!userp(ob))
//return notify_fail("由于BUG,暂不开放对NPC的慑心!\n");
	if((int)ob->query("age") <= 18 && userp(ob))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");

message_vision("
$N的一对眼睛半眯着，只如两道细缝，但细缝中莹然有光，眼神甚是清朗。
$n微觉不妥，要想转头避开$N的眼光，可是一双眼睛竟似被$N的目光吸住了，
不由自主的凝视着他。\n", me, ob);
        if( random(me->query_skill("necromancy",1)) < random(ob->query_skill("force",1)))
        {
message_vision("突然$n猛地一阵清醒，于是，$n大喝一声：你活腻了，敢来对我施慑心术？\n", me, ob);
                if( ob->query("age")>17) 
me->kill_ob(ob);
                ob->fight_ob(me);
                return 1;
        }

        if( !userp(ob) && me->query("combat_exp") < ob->query("combat_exp"))
        {
message_vision("突然$n猛地一阵清醒，于是，$n大喝一声：你活腻了，敢来对我施慑心术？\n", me, ob);
                me->kill_ob(ob);
                ob->fight_ob(me);
                me->kill_ob(ob);
                return 1;
        }

        if (strsrch(cmd, "give ") >= 0)
        {
message_vision("于是，$n迷迷糊糊也不知道是递了些什么给$N。\n", me, ob);
        }
        else
        {
            if (strsrch(cmd, "go ") >= 0)
            {
message_vision("结果，$n迷迷糊糊也不知道怎么回事就往前摸着走开了。\n", me, ob);
            }
            else
            {
                if (strsrch(cmd, "follow ") >= 0)
                {
message_vision("果然，$n迷迷糊糊地就跟在$N的屁股后面走了。\n", me, ob);
                }
                else
return notify_fail("你只能慑心人家做：give、go和follow。\n");
            }
        }
        if( wizardp(ob) )
return notify_fail("巫师不能被你慑心。\n");

        if( userp(ob) )
                log_file("shexin_player", sprintf("[%s] %s shexin %s to %s\n",
                        ctime(time()), geteuid(me), geteuid(ob), cmd));
        return ob->force_me(cmd);
}

int help(object me)
{
        write(@Help
 指令格式: shexin <某人> to <指令>

 shexin sb to give sth to sb
 shexin sb to follow sb
 shexin sb to go <dir>

利用慑心术诱惑某人做把身上的东西给你, 或往那里离开，或者
跟着你。当然你必须是雪山派弟子，且有相当的降伏法修为。
对方如果内功深厚，而你学艺不精，必然也会招致以牙还牙。当心！
Help
        );
        return 1;
}

