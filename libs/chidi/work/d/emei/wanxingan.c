// Room: /d/emei/wanxingan.c 峨嵋派 万行庵

inherit ROOM;

void create()
{
	set("short", "万行庵");
	set("long", @LONG
这里是莲花峰旁的万行庵，是接待香客及来宾的地方。殿内摆着几张桌子，
桌旁围放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满经书。有几
位进香客正在品茶养神，欣赏墙上的字画或翻阅架上的经书。还有两个二十来
岁的姑娘在向一位师太打听有关出家的事。一个十来岁的小师太正在忙前忙后
招待客人。
LONG
	);

	set("exits", ([
		"east" : __DIR__"lianhua",
	]));

	set("objects",([

                CLASS_D("emei") + "/jinghui": 1,
	]));
        setup();
}