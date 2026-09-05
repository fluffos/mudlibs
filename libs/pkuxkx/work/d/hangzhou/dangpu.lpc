// Room: /hangzhou/dangpu.c
// hubo 2008/4/19 

#include <ansi.h>
inherit F_HOCKSHOP;


void create()
{
	set("short", "祚德庙");
	set("long","祚德庙的门口开了一间当铺，极受此地百姓的欢迎。立着一个牌子" + YEL "(paizi)" NOR +"，\n柜台后坐着裴老板，一双精明的眼睛上上下下打量着你。\n");
	set("no_beg",1);
        set("no_steal", 1);
       set("no_fight", 1);
	set("item_desc", ([
		"paizi" : (:use_help:),
	]));
	set("objects", ([
"/d/hangzhou/npc/pei" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));

	setup();
}
