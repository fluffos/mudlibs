//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "半山竹林");
	set("long", @LONG
一大片茂密的成年竹林生长在半山腰的缓坡上。竹子对大理地区
各民族来说是，既是重要的建筑材料，也是日常生活用品的原材料。
山下的村庄里的摆夷人经常上山来采伐竹子。北面山上有溪流下，到
这里水流已经颇大，山民经常把砍伐下的竹子丢在溪中，任其顺水飘
流，到村子附近的溪水里再捞起来。
LONG
        );

	set("exits", ([
		"northup" : __DIR__"minov27",
		"east" : __DIR__"minov31",
		]));

	set("objects", ([
		__DIR__"npc/byshanren1.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
