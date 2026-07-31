// shulin1.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "树林");
    set("long", @LONG
这是小镇北边的一片树林，林中静悄悄的，除了猎户，一般很少有人来
这里，所以这里经常有野兽出没。树林鸟语相间，遥相和呼,更为这寂静的
树林增添了几分神秘。
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "south" : "/d/xuzhou/xiaolu1",
	    "west" : __DIR__"shulin2",
          ]));

	setup();
	replace_program(ROOM);
}   