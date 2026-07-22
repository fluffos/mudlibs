// Room: /d/emei/podao1.c 峨嵋派 坡道1

inherit ROOM;

void create()
{
	set("short", "坡道");
	set("long", @LONG
这里是一条窄窄的上山小路，浑然天成。道路很陡峭，高处望下使人
阵阵心寒，登山的人一个不小心很容易便会跌堕到崖谷之中。你艰难行走
在天然形成得一格格石阶上，已经感到气喘吁吁。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "enter": __DIR__"lianhuashi",
                "southup":__DIR__"podao2",
	]));

	setup();
}



