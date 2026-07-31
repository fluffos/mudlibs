
// Room: /d/snow/hroad1.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long",
"你一路往西行，正是秋高气爽，百草凋零，微风过面，略有寒意。路上时有满脸风尘的旅人\n"
"行色匆匆地擦肩而过。偶尔有装饰华丽的马车从你身边经过，车帘起伏，隐约可闻幽香阵阵\n"
"，环佩叮当。远处，山峦叠嶂，山脚零星散落着几处农家茅舍。\n"
);
        set("exits", ([ /* sizeof() == 2 */
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
//	set("objects",(["/d/snow/npc/txtrainee": 3]));
        setup();
        replace_program(ROOM);
}
