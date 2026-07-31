// /d/zhuojun/jinlou.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "浏阳文庙");
	set("long", @LONG
浏阳文庙是仿曲阜孔庙的宫殿式古建筑群。庙宇面街背山，共
有13个建筑单元。庙宇东西对称，回廊贯通,朱墙怀抱金碧辉煌，其
中大成殿更是气宇轩昂，现在这里是首饰精品买卖行，这里打造的金
银首饰堪称一绝，做工精细，据说很久以前这里打制的首饰还是供品
呢。
LONG
	);
set("exits", ([
                "north"  :__DIR__"dongdajie2",
	]));
set("objects",([
 __DIR__"npc/zhubao-boss":1,
 ]));
       setup();
	replace_program(ROOM);
}	
