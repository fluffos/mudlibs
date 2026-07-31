// /d/mr/xiaojing1-4.c

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",GRN"小径"NOR);
	set("long",@long
一条曲曲折折由鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木点
缀在其中。你走在石地上，啪嗒啪嗒的发出清脆的响声，顺着小径向东面方向
望去有一处空场。
long);
	set("outdoors","慕容");
	set("exits",([
		"north":__DIR__"guanxing",
		"east" : __DIR__"fenmu",
		"west" : __DIR__"xiaojing3",
	]));
	set("objects",([
		__DIR__"../npc/deng" : 1,
	]));
	setup();
}
