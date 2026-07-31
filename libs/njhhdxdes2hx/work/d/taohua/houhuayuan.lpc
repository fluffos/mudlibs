// Room: /d/new_taohua/houhuayuan.c

inherit ROOM;

void create()
{
	set("short", "荷塘");
	set("long", @LONG
你的眼前出现一大片荷塘，塘中白莲盛放，清香阵阵，莲叶田田。一条
小石堤伸至荷塘中央，又分叉向四处延伸。   
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"yonglu3",
  "south" : __DIR__"yonglu2",
  "west" : __DIR__"liangongfang",
  "east": __DIR__"yonglu6",
  "northwest": __DIR__"wangluting",
]));
	set("outdoors", "new_taohua");

	setup();
	replace_program(ROOM);
}
