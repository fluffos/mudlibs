// Room: /city/nandajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "十里长街");
	set("long", @LONG
十里长街原本是扬州的中心，繁华之至。街边茶肆酒楼林立，店铺
面街开店，热闹非凡，每当夜市来临时，店家高挂灯笼，尽夜喧哗，灯
火不绝。杜牧曾描绘到：“每重城向夕，常有绛纱灯万数，辉煌罗列空
中。”现在街边的店铺多搬至新城，十里长街的繁荣教往昔已逊色许多，
但做为进出扬州的要道，依旧行人拥挤，车马如流。北边是一个热闹的
广场。东边是一家店铺，墙上写着一个大大的“当”字，仔细倾听，可以
听到压低的讨价还价的声音。西边则是一片喧嚣，夹杂着“一五一十”的
数钱声，原来那是方圆千里之内最大的一家赌场。
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west"  : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
	]));

	setup();
	replace_program(ROOM);
}

