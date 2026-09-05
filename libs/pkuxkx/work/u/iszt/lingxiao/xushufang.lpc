// File		: xuenorth2.c
// Created By	: iszt@pkuxkx, 2006-09-04

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIG"书房"NOR);
	set("long", @LONG
这里是徐先生的书房，清雅幽静，壁上书画也自端庄大方，四处都是才
气横溢、亦庄亦谐的铭文。书房一角是一张卧榻，一只瓷枕(zhen)。窗下的
桌上摆着一把茶壶(hu)，一方端砚，紫檀砚盒盖上雕了嵌绿漆的阴文，题为
“自用砚铭”(ming)。
LONG);

	set("indoors", "凌霄城");
	set("no_fight", 1);
	set("no_get_from", 1);
	set("item_desc", ([
		"zhen" : "这是一只空心粉底、松鹤白云花色的瓷枕，枕上铭文写道：\n"HIY"              甜乡醉乡温柔乡，三者之梦谁短长？仙人与我炊黄梁。\n"NOR,
		"hu" : "一把阳羡砂壶，上面又有用隶书工工整整写下的铭文：\n"CYN"上如斗，下如卣，鳌其足，螭其首，可以酌玉川之茶，可以斟金谷之酒。\n                         丁酉春元文志于燕京\n"NOR,
		"ming" : HIG"石友石友，与尔南北走，伴我诗，伴我酒，画蚓涂鸦不我丑，告汝黑面知，共我白头守。\n"NOR,
	]));
	set("exits", ([
		"southwest" : __DIR__"xuxiaoyuan",
	]));

	setup();
	replace_program(ROOM);
}

