inherit ROOM;

void create()
{
	set("short", "铁玲关");
	set("long",@long
关呈长方形，砖石结构，正中的三层敌楼为新建。铁玲关地处水陆要冲登
敌楼，既可了望，又能放炮射箭。这关垣、运河、石桥所组成的联合工事，当
时是为了防御合抵抗侵扰的倭寇。
long);
	set("outdoors", "苏州");
	set("objects",([
		NPC_D("guanfu/wujiang") : 1,
		NPC_D("guanfu/bing") : 2,
	]));
	set("exits",([
		"south" : __DIR__"fengqiao",
	]));
	setup();
}
