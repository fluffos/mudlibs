// jail_gate.c
// Created by Numa 19991021

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "监狱大门");
	set("long", @LONG
你站在一扇铁铸的大门前面，门上挂着一把大锁，大门的正面写着“日月
神教 监狱”几个大字。四周是高耸的围墙，一种阴森恐怖的气氛直袭而来。
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"andao8",
	]));
	set("item_desc",([
		"锁":	"一把十分牢固的青铜大锁，看来除非拿钥匙才能打开了。(unlock)",
		"lock":	"一把十分牢固的青铜大锁，看来除非拿钥匙才能打开了。(unlock)",
	]));
	setup();
}
