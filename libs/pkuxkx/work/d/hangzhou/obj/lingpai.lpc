// paper.c
inherit ITEM;
#include <ansi.h>
int checkenv();
void create()
{
        set_name("令牌", ({"ling pai", "ling"}));
        set_weight(100);
        set("unit", "块");
        set("long","这是一块临安府尹签发的令牌，新晋官员通常被要求带着令牌巡守都城。\n");
        set("material", "wood");
        set("is_xc_ling",1);
        setup();
        call_out("checkenv",1);
}
string *place_list(int number)
{
	if (number==1)//18
	return ({"/d/hangzhou/dongdajie4","/d/hangzhou/yuewang","/d/hangzhou/dongdajie3","/d/hangzhou/xiawa","/d/hangzhou/hanwang",
			"/d/hangzhou/xiawa2","/d/hangzhou/qianzhuang","/d/hangzhou/jiyuan","/d/hangzhou/dianxinpu","/d/hangzhou/jiulou","/d/hangzhou/erlou",
			"/d/hangzhou/zahuopu","/d/hangzhou/zhongan","/d/hangzhou/dongdajie1","/d/hangzhou/dongdajie2","/d/hangzhou/offline_shop1",
			"/d/hangzhou/datiepu","/d/hangzhou/dongmen","/d/hangzhou/jewelrystore"});
	if (number==2)//4
	return ({"/d/hangzhou/xidajie1","/d/hangzhou/hockshop5","/d/hangzhou/rbz","/d/hangzhou/ximen"});
	if (number==3)//14
	return ({"/d/hangzhou/bazi","/d/hangzhou/linanfu","/d/hangzhou/nandajie1","/d/hangzhou/xiongwu","/d/hangzhou/xijie",
			"/d/hangzhou/chenghuang","/d/hangzhou/qingbo","/d/hangzhou/nandajie2","/d/hangzhou/dutingyi","/d/hangzhou/xiaorenfang",
			"/d/hangzhou/paozhang","/d/xinfang/bieshuqu3","/d/hangzhou/heningmen"});
	if (number==4)//15
	return ({"/d/hangzhou/beidajie1","/d/hangzhou/dangpu","/d/hangzhou/mingqing","/d/hangzhou/kedian","/d/hangzhou/machehang","/d/hangzhou/beidajie2",
			"/d/hangzhou/jinglinggong","/d/hangzhou/changping","/d/hangzhou/chouduan","/d/hangzhou/beijie3","/d/hangzhou/beijie2","/d/hangzhou/xianlinsi",
			"/d/hangzhou/beijie1","/d/hangzhou/wensiyuan","/d/hangzhou/beimen"});
}
int checkenv()
{
    object ob=this_object();
    object me=environment(ob);
    object env;
    string *rooms=({});
    if (!me)
    {
        destruct(ob);
        return 1;
    }
    if (!userp(me))
    {
        message_vision("$N被丢在了路边，渐渐被杂物掩盖。\n",ob);
        destruct(ob);
        return 1;
    }
    if (!me->query_temp("chaoting/newjob/xuncheng"))
    {
        return 1;
    }
    env=environment(me);
    if (member_array(base_name(env),place_list(me->query_temp("chaoting/newjob/xuncheng")))==-1)
	{
		remove_call_out("checkenv");
		call_out("checkenv",1+random(4));
		return 2;
	}
	if (arrayp(me->query_temp("chaoting/newjob/xuncheng_already"))&&member_array(base_name(env),me->query_temp("chaoting/newjob/xuncheng_already"))!=-1)
	{
		remove_call_out("checkenv");
		call_out("checkenv",1+random(4));
		return 3;
	}
    message_vision("$N在"+env->query("short")+"巡弋，并未发现什么异常情况。\n",me);
	if (arrayp(me->query_temp("chaoting/newjob/xuncheng_already")))
	rooms=me->query_temp("chaoting/newjob/xuncheng_already");
    rooms+=({base_name(env)});
	me->set_temp("chaoting/newjob/xuncheng_already",rooms);
    remove_call_out("checkenv");
    call_out("checkenv",1+random(4));
    return 4;
}

