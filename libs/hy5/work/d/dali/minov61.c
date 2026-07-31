//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "喜州城");
	set("long", @LONG
喜州又名大鳖城，是大理南部大城，自唐代已极繁荣，邑居人户
尤众，商贸甚繁荣，有大量他国客商来此交易，采购大理产的金银、
丝织品、象牙、皮毛等，其中又以来自印度的客商最多，前来贩丝绸
往波斯甚至更远的西方。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov62",
		"south" : __DIR__"minov64",
		"east" : __DIR__"xizhou",
		"southwest" : __DIR__"minov66",
		]));

	set("objects", ([
		__DIR__"npc/indiman" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
