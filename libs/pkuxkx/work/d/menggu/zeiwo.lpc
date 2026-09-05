// Room: zeiwo.c
// created by 2012
// for 战斗时暂存马贼队伍，平时暂存马贼,player no access
#include <ansi.h>
inherit F_SAVE;
inherit ROOM;
#define JOB "/data/business/mazei_job"
string query_save_file()
{
	return JOB;
}

void create()
{
	set("short", "马贼窝");
	set("long", @LONG
这里马贼的大本营。
LONG
	);
    set("no_task", 1);
	set("no_clean_up", 1); 
	set("no_reset",1);
	set("no_robber",1);
	setup();
}
