// Room: /d/emei/jieyindian.c 峨嵋派 接引殿

inherit ROOM;


void create()
{
	set("short", "接引殿");
	set("long", @LONG
这里是峨嵋的接引殿。这里是峨嵋派专门接待那些前来上香理佛的香客
或者是一些武林同道的地方，虽然寺庙并不太大，却很繁华。只见有一位师
太在那里热情接待着来往的客人。
LONG
	);

	set("exits", ([
                "north" : __DIR__"basipan3",
	]));

	set("objects",([
	]));

	setup();
}
