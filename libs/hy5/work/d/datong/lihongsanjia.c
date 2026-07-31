// Room: /open/dt/lihongsanjia.c

inherit ROOM;

void create()
{
	set("short", "李洪三家");
	set("long", @LONG
这里是大同府捕快头领“铁手”李洪三的家。李头领为人刚
正不阿，一身功夫着实了得，据说当年他还在江湖上闯荡的时候
曾经凭着一双铁掌只身独斗点苍三绝剑，虽然最终不敌负伤，但
点苍三绝剑也都中了他的铁沙掌，后来四人不打不相识，便与他
结为异姓兄弟，一时传为武林佳话。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huaandao2",
]));

	setup();
	replace_program(ROOM);
}
