// Room: /d/emei/rongshulin1.c 榕树林


inherit ROOM;

void create()
{
	set("short", "榕树林");
	set("long", @LONG
这里是凉风桥旁的一条小路，花草树木生长的十分茂密，尤榕数为多。繁
茂的枝叶遮得浓荫蔽空。在林间不时可以看到有几只鸟儿掠过，每至清晨或黄
昏，正是林间鸟儿出林或会巢得时候，在朝霞满天或暮色苍茫得天空中飞翔，
鸣叫声清脆委婉，响彻云霄。
LONG
	);

	set("exits", ([
                 "west":__DIR__"jietuopo",
                 "east":__DIR__"rongshulin2",
	]));
        set("outdoors", "emei");
	setup();
}