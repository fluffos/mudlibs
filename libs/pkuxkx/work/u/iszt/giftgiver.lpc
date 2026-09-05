// File         : giftgiver.c
// Created By   : iszt@pkuxkx, 2007-01-12

#include "ansi.h"

inherit ITEM;

void create()
{
     set_name("在线礼物发布器",({"online gift giver", "gift", "giver"}));     
     set("short", HIY"在线"HIM"礼物"HIC"发布器"NOR);
     set("env/invisibility",1);
     set("unit", "个");
     set_weight(100);
     set("value", 1);
     set("no_get",1);
     set("no_fight", 1);
     set("mark", "online_mark");
     seteuid(getuid());
     setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_givemark", "givemark");
}

int do_jump(string arg)
{
        object me = this_player();
        string reward; //奖励的文字描述
        int point; //奖励的点数

        if(arg)
                return 0;
        if(!me->query_temp(query("mark")))
                return 0;
        switch(random(5))
        {
        case 0:
                point = 40;
		reward = "价值" + chinese_number(point) + "两黄金的银票";
                MONEY_D->pay_player(me, 400000);
                break;
        case 1:
                point = 50 + random(50);
                reward = chinese_number(point) + "点伤害力";
		me->add_temp("apply/damage", point);
                break;
        case 2:
                point = 1 + random(14);
                reward = chinese_number(point) + "点后天悟性";
                me->add_temp("apply/intelligence", point);
                break;
        case 3:
                point = 1 + random(14);
                reward = chinese_number(point) + "点后天膂力";
                me->add_temp("apply/strength", point);
                break;
        case 4:
                point = 40;
                reward = chinese_number(point) + "级有效内功";
                me->add_temp("apply/force", point);
                break;
//      case :
//              point = ;
//              reward = chinese_number(point) + "";
//              me->add_temp("", point);
//              break;
        }

	message_vision(HIG"$N得到了" + BLINK + HIR + reward + NOR + HIG"的在线奖励！\n"NOR, me);
        me->delete_temp(query("mark"));
        return 0;
}

int do_givemark(string arg)
{
	int i;
        object* ob = users();

        if(!wizardp(this_player()))
                return 0;
        set("mark", arg);
	write(HIG"在线玩家全部set_temp(\"" + arg + "\", 1)，共" + sizeof(ob) + "人……"NOR);
        for(i=sizeof(ob)-1; i>=0; i--)
                ob->set_temp(arg, 1);
        write(HIR"成功！\n"NOR);
        return 1;
}
