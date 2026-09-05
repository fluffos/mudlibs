// Room: /d/beijing/zijin/qianqingmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"乾清门"NOR);
	set("long",
HIC"   这是内廷的正门,是清朝御门听政的地方.很多军国大
事都是在御门听政时决定的。
   这里向北是一条白玉石通道,两侧是庑廊,通向各个房间。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"xiaohuayuan",
  	"north" : __DIR__"yard1",
  	"west" : __DIR__"jingshifang",
  	"east" : __DIR__"shangshufang",
  	"southeast" : __DIR__"houzuomen",
  	"southwest" : __DIR__"houyoumen",
//  	"northwest" : __DIR__"neiyoumen",
//  	"northeast" : __DIR__"neizuomen",
]));
	set("outdoors", "beijing");
	set("objects", ([
		"/d/beijing/npc/shiwei3" : 4,
		"/d/beijing/npc/shiwei2" : 4,
		]) );
	setup();
	replace_program(ROOM);
}
