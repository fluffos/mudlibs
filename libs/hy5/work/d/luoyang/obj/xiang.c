// xiang.c
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name("关帝像", ({ "guandi xiang", "xiang" }) );
	set("gender", "男性" );
	set("unit", "尊");
	set("value", 1);
	set("kar", random(21));
	set("no_get", 1);
	set("no_put", 1);
	set("no_get_from", 1);
        set("long", 	
"这是一尊三人像。前坐者"HIG"绿衫"HIR"赤面"NOR"，右手捋髯，左手正执竹简，正是
关帝夜读春秋像。后立者，左手一位"HIW"银甲白面"NOR"，手捧令旗，正是关平。
右手一将，"BLK"黑面皂袍"NOR"，手握"HIC"青龙偃月刀"NOR"的，便是周仓了。\n");
}

