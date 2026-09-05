// File		: maofang.c
// Created By	: iszt@pkuxkx, 2007-02-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIC"茅房"NOR);
	set("long", @LONG
这里是一个四面透着寒风的茅房，靠墙一排茅坑，下面和深谷相连。石缝光
溜溜的，不知经过多少次的踩踏，却是很窄，就算不怕其中的污秽，也绝无可能
从中钻入钻出。看来在此方便也不是那么简单的事，需要颇强的定力才能忍耐住
倒灌而入的冷气。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"stonen1",
	]));

	setup();
	replace_program(ROOM);
}