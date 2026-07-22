// Room: /d/emei/baoguosi.c 峨嵋派 保国寺


inherit ROOM;


void create()
{
        set("short", "报国寺");
	set("long", @LONG
这里是峨嵋的山下的报国寺，寺前溪水奔流，寺内古木参天，清幽秀
丽。寺后一条大道只通峨嵋山山脚，在寺边矗立一个巨大的石碑，上面篆
刻着“华严经”全文。正面是报国寺的大殿，东边是一间禅房。寺旁一条
小路直通一片密林。
LONG
	);

	set("exits", ([
                "east":__DIR__"chanfang",
                "south": __DIR__"baoguosi1",
                "southwest":__DIR__"milin1",
                "northdown":__DIR__"shanmen",
	]));
        set("objects",([
	 "/d/emei/npc/xiang-ke" : 2,]));

	setup();
}
