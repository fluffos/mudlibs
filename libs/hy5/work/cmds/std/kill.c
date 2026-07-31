// kill.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    int my_idle,your_idle;
    object obj,ob;
    string callname,msg;;
    if (!me)    return 0;
        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
return notify_fail("由于你没有心跳，请重新登陆!!\n");
        }

//    if (me->is_fighting()) 
//        return notify_fail("你正打的热闹着呢!\n");

    if( !arg )
        return notify_fail("你想杀谁？\n");

    if(!objectp(obj = present(arg, environment(me))) || !me->visible(obj))
        return notify_fail("这里没有这个人。\n");

      if((int)obj->query("age") <= 19 && userp(obj))
        return notify_fail("为了世界更美好，放过小孩子吧.\n");

    if( environment(me)->query("no_fight") && !obj->query_condition("killer"))
        return notify_fail("这里不准战斗。\n");

     if( obj->query("env/no_fight") )
        return notify_fail("不能打，打不得啊！\n");
     if( obj->query_temp("no_kill") )
        return notify_fail("不能打，打不得啊！\n");

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");
    if(obj==me)
        return notify_fail("用 suicide 指令会比较快:P。\n");
    if(me->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");
        
    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");

	if (me->is_fighting(obj) || me->is_killing(obj))
		return notify_fail("你正在和人家生死相博呢。\n");
        
        
if( !living(obj) && userp(obj) && obj->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");

//pk
    if( userp(obj) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");


//免战系统
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
	
	

        if (userp(obj) && !query_heart_beat(obj)
        && !obj->query_condition("killer"))
        {
         write("你想做什么！\n");
        return notify_fail("此人无心跳！\n");
//         write("此人不能beg！\n");
        }
    if(userp(me) && userp(obj) && me->is_fighting() && obj->is_fighting()) 
    {
        return notify_fail("你已经在打了！在杀别的玩家看来是不行的！\n");
    }

    if (userp(me)){
    your_idle = obj->query_skill("fadai-qigong",1);
    my_idle = me->query_skill("fadai-qigong",1);
    if(userp(obj)&&random(your_idle)>30 && random(your_idle)>random(my_idle)&&!obj->is_fighting()&&!environment(obj)->query("fight_room"))
    {
         write("你想对"+obj->query("name")+"下杀手，但是看着他那呆若木鸡的样子，你始终狠不下心来。\n");
         tell_object(obj,"一种不详的感觉笼罩着你全身。。。\n");
         tell_object(obj,me->query("name")+"("+me->query("id")+")"+"想对你下毒手，还在考虑中，你还是快逃吧！\n");
         me->start_busy(5);
     }
//    if (wizardp(obj))
//        return notify_fail(obj->query("name")+"瞪了你一眼，你突然吓得两腿发抖，几乎跪了下来。\n");
    if((int)obj->query("age") <= 17 && userp(obj) && !obj->query_condition("killer"))
        return notify_fail("为了世界更美好，放过小孩子吧.\n");
    if( !living(obj) && userp(obj) && obj->query_temp("sleeped")&&me->query("shen")>obj->query("shen"))
        return notify_fail("趁人家睡觉的时候下手？嘿嘿，你也太缺德了！\n");
    }
    callname = RANK_D->query_rude(obj);
        if(me->query("race")=="人类"){
                if(me->query("mute"))
                        msg = HIR"\n$N突然冲向$n，双眼通红，看来是要至$p于死地！！\n\n";
                else if(stringp(me->query("env/kill_msg")) && strlen(me->query("env/kill_msg")) < 50 )
                        msg = "\n$N对着$n大喝一声："+me->query("env/kill_msg")+"！\n\n";
                else if(me->query("combat_exp") > obj->query("combat_exp")*2){
		        if(me->query("shen") < -10000)
                       msg = HIY"\n$N对着$n啐了一口：「"+callname+"！，怪你生不逢时，"+RANK_D->query_self_rude(me)+"今天看你极不顺眼，认命吧！！」\n\n";
                    else msg = HIY"\n$N对着$n吼道：「"+callname+"！，你记好"+RANK_D->query_self_rude(me)+"的名字，死后到阴司去告我一状吧！！」\n\n";
		        }
	        else if(obj->query("combat_exp") > me->query("combat_exp")*2){
		        if(me->query("shen") < -10000)
                       msg = HIG"\n$N对着$n一声奸笑：「"+callname+"！，别看你平时耀武扬威，今天"+RANK_D->query_self_rude(me)+"就要取你性命！！」\n\n";
		        else msg = HIG"\n$N嘿嘿一笑：$n"+callname+"，我虽技不如你，但今天就是拼了命也要将你碎尸万断！！\n\n";
		        }
	        else {
		        if(me->query("shen") < -10000)
                     msg = HIW"\n$N对着$n猛吼一声：「"+callname+"！，明年的今天就是你的祭日，让"+RANK_D->query_self_rude(me)+"送你上路吧！！」\n\n";
		        else msg = RED"\n$N对着$n喝道：「" + callname + "！，你死期已到，今天就让"+RANK_D->query_self_rude(me)+"送你上西天吧！」\n\n";
	                }
	        }
	else msg = "\n$N大吼一声，猛然扑向$n，看来是要将$p杀死！！\n\n";
	message_vision(msg, me, obj);
if (environment(me)->query("no_fight") && userp(obj) && obj->query_condition("killer"))
{
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
me->start_busy(1);
}
    me->kill_ob(obj);
    if(userp(me) && userp(obj))
    {
         me->start_busy(1);
    }

    //me->start_busy(1);
    obj->delete_temp("fighting");
    if ( userp(obj)){
 		if ( me->query("age")<18 )
			me->att_kill_ob(obj);
		}
    if( !userp(obj))
        obj->kill_ob(me);
    else {
        obj->fight_ob(me);
        tell_object(obj, HIR "如果你要和" + me->name() 
            + "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
    }
      if (!userp(me)) return 1;
    if (!obj) return 1;
    	if (stringp(obj->query("marry"))){
    ob=present(obj->query("marry"),environment(me));
    if (ob && userp(ob) && living(ob) && ob!=me ){
        if (ob->query("gender")=="男性")
            message_vision(CYN"\n$N一声怒吼："+me->name()+"！你竟敢欺负俺老婆，我跟你拼了！\n\n"NOR, ob);
        else
            message_vision(CYN"\n$N娇喝一声："+me->name()+"！看来你不把咱夫妇放在眼里，看招！\n\n"NOR, ob);
        ob->kill_ob(me); me->fight_ob(ob);
    }
    }
    if( !stringp(callname=obj->query("family/family_name")))
        if( !stringp(callname=obj->query("friend")))
        return 1;
    ob=first_inventory(environment(me));
    while(ob){
        if( ob!=obj && ob->is_character() && !ob->is_corpse() && living(ob)){
//同门互助（玩家可不参与）
        if( !ob->query_temp("no_kill") ) 
        {
            if ( (string)ob->query("family/family_name")==callname && !ob->is_killing(me) && !userp(ob) ){
                message_vision(CYN"\n$N大怒："+me->name()+"！你竟敢谋害我的同门？看招！\n\n"NOR, ob);
                ob->fight_ob(me); me->fight_ob(ob);
            }
        }
//拜把的兄弟互助
        if( !ob->query_temp("no_kill") ) 
        {
            if ((string)ob->query("friend")==callname  || (string)ob->query("friend")==obj->query("id") ){
                message_vision(CYN"\n$N冷冷一笑："+me->name()+"！你要杀我拜把的兄弟，得先问问我！\n\n"NOR, ob);
                ob->kill_ob(me); me->fight_ob(ob);
            }
        }
        }
        ob=next_inventory(ob);
    }
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且试图杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。
当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。
其他相关指令: hit, fight
有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 
