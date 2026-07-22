// Room: //dali/ximen.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
西门是通向天龙古刹的必经之地，不少作奸犯科的歹徒妄想从这里逃向山
中，均被在此值勤的武将官兵擒获，段王爷更是常派自己的贴身侍卫来此守卫，
城门旁进出的行人络绎不绝。
LONG
	);
	set("outdoors", "大理");
	set("no_fight",1);
	set("exits", ([
		"westup" : "/d/tls/diancang",
		"east" : __DIR__"xijie4",
	]));
	set("objects", ([
		__DIR__"npc/zhudanchen" : 1,
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}
