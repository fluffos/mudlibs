// Room: /d/ningbo/ningbocheng.c 宁波

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", HIY"城中心"NOR);
	set("long", @LONG
这里是宁波城的城中心，宁波城是本府的大城，历来都是南北兵家必争之
地，城中驻扎着重兵。士兵们除了负责盘查南来北往的行人，还负责翦灭附近
山上的草寇。城门边贴着张告示(gaoshi)，写着官府通缉的逃犯。城内一队队
官兵来来去去，一派森严气象。这里的海港是与外界交往的重要通道。
LONG
	);
        set("objects",([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("exits", ([
		"west" : __DIR__"ttcsi",
		"northwest" : __DIR__"aywsi",
		"south" : __DIR__"kedian",
		"east" : __DIR__"dongqianhu",
	]));
	set("outdoors", "宁波");
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n宁波知府\n";
}
