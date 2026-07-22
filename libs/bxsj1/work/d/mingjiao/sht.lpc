// sht.c 圣火堂
// Modify By River@SJ 99.06
// Modify by Lklv 2002.1.17
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIR"圣火堂"NOR);
       set("long", @LONG
这里就是明教圣火堂所在。你一走到这里突然产生一股前所没有的庄严肃
穆之意，在堂中央用大草书写着三个血红大字「圣火堂」，中间有一幅大横匾
上写着：“焚我残躯，熊熊圣火，生亦何欢，死亦何苦？为善除恶，惟光明故，
喜乐悲愁，皆归尘土。怜我世人，忧患实多！怜我世人，忧患实多”。这里点
着长年不灭的圣火，经常有武林人士和官家人士来朝拜。中间放着一张大虎头
椅，是明教历代教主之位。有几个丫环在旁边侍侯。
LONG);
	set("exits", ([
		"southdown" : __DIR__"jyt",
		"northup" : __DIR__"baota",
	]));
	set("objects",([
		__DIR__"npc/yahuan" :   1,
		__DIR__"npc/f-dizi" :   1,
		CLASS_D("mingjiao") + "/zhangwuji" : 1,
	]));
	setup();
}
