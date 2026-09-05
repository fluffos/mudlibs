// Room: /d/diaoyudao/zuozhang.c 左帐
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "左帐");
	set("long", @LONG
你大着胆子冲进了左帐，里面有四个东洋人正围着一张桌子不知
在干什么？你突然的闯进来，四个人先是一愣，随即抽出武士刀，嘴
里叽里咕噜的骂着，向你冲来。
LONG
	);
	
	set("exits", ([
		 "east": __DIR__"dazhang",
	]));

	set("objects", ([
                __DIR__"npc/wo_kou":4,

        ]));


//	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

