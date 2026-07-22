// Room: /d/emei/chunyangd1.c 峨嵋派 纯阳殿广场


inherit ROOM;


void create()
{
	set("short", "纯阳殿广场");
	set("long", @LONG
这里是峨嵋的纯阳殿外的广场，这里山环水绕，飞阁流云，十分清雅
秀丽。在南面一座大殿是纯阳殿，雄伟高大，下面是茂密树林，往东是通
往寺外的一条上山小道。
LONG
	);
      set("outdoors", "emei");
	set("exits", ([
                "east":__DIR__"lshenggang",
                "south":__DIR__"chunyangd",
                "northdown":__DIR__"jietuopo",
	]));

	set("objects",([
	  "/d/emei/npc/qingyi" : 2,
         ]));

	setup();
}

