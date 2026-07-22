// /d/yazhang/qianzhuang.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "定襄钱庄");
	set("long", @LONG
这是定襄城甚至东突厥最大的一家钱庄，信誉卓著，它开出的银票，
不要说在塞外，就是在中原也可以对兑，钱庄的门口挂着一块很大的金字
招牌，上书“定襄钱庄”长长的柜台，都打扫得干干净净。
LONG
	);
set("exits", ([
                 "east" : __DIR__"beidajie2",  
	]));
	set("objects",([
	 __DIR__"npc/wu":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
