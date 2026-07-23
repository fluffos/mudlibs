inherit ROOM;

void create()
{
	set("short", "文县石林");
	set("long", @LONG
文县内众多奇峰怪石拔地而起，似剑如戟，破土直刺苍
穹。石峰最高达30余米，又有地峡石罅幽深曲折。因绿树古
藤、蟠枝虬根常年攀附石峰，使石林平添了几许柔情，获得
了“绿色”石林的美誉。又因它造型迥异的石形而赢得了“拟
态动物园”的美名。  
LONG );

	set("exits", ([
               "southwest"      : __DIR__"xiaolu1",
               "southeast"      : __DIR__"tulu8",
             	]));
        set("objects", ([
		"/clone/npc/man": 1,
	]));
 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



