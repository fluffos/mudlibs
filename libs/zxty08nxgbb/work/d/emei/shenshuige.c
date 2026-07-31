// Room: /d/emei/shenshuige.c 神水池


inherit ROOM;


void create()
{
        set("short", "玉液池");
	set("long", @LONG
这里就是神水阁外的玉液池，此池虽然不大，但常年有泉水流出，并且池水
还散发着微微的热气，据说若平常人喝了这里的是水会使人延年益寿，如果练武
人喝了可以增进内力的修为，故此峨嵋专门派人看管此池，这里也是峨嵋僧众取
水的地方。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "southup" : __DIR__"qingyinge",
                "northdown":__DIR__"lshenggang",
                "east": __DIR__"zfengsi",
	]));


	set("objects",([
                __DIR__"npc/zhaolingzhu": 1,
	]));

	setup();
}
