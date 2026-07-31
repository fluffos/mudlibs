// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

inherit AREA_ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
一间老字号的杂货铺。祖孙三代经营下来，在长安城南一带已经有了
一些小名气。这里无论是油盐酱醋，还是大米白面，老百姓日常生活需要
的东西一样都不少。再加上这里的老掌柜待客如宾，杂货铺的生意看来一
天比一天好。
LONG );
	set("exits", ([
		"south" : __DIR__"huarui5",
	]));
	set("objects", ([
        	__DIR__"npc/liu": 1,
	]));

	set("no_clean_up", 0);
        set("area/ziyuan", "杂货");
	setup();
}

