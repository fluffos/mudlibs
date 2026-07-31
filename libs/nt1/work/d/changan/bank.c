// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit AREA_ROOM;

void create ()
{
        set ("short", "四海钱庄");
        set("long", @LONG
这是长安城的一家老字号钱庄，老板是山西人，这家钱庄从他的祖先
来到这里时就开始办起，一直传到他的手里。钱庄的信誉非常好，而且在
全国各地都开了分店。它发行的银票通行全国。钱庄的门口挂有一块牌子
(paizi)。
LONG );
        set("item_desc", ([
        	"paizi": 
HIG"本钱庄提供的服务有：\n"NOR
HIC"--------------------------------\n"NOR
HIG"check(chazhang)        查帐\n"NOR 
HIC"--------------------------------\n"NOR
HIG"deposit(cun)           存款\n"NOR
HIC"--------------------------------\n"NOR
HIG"withdraw(qu)           取款\n"NOR
HIC"--------------------------------\n"NOR
HIG"convert(duihuan)       兑换钱币\n"NOR
HIC"--------------------------------\n"NOR

        ]) );
        set("exits", 
        ([ //sizeof() == 1
        	"south" : __DIR__"qixiang4",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	__DIR__"npc/tiegongji" : 1,
        ]));
        set("area/ziyuan", "黄金");

	set("no_clean_up", 0);
        setup();
}
