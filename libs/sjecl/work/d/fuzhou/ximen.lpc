// Room: /d/fuzhou/ximen.c
// Lklv 2001.9.10

inherit ROOM;

string look_gaoshi();
void quarter_pass();

void create()
{
        set("short", "西门");
        set("long", @LONG
这里是福州府的西门，城墙不是很高，有一座中等规模的城门。出此门向
西北可往湘赣，进而入川；西南可达两广，直抵云贵；因此出入往来的客商一
向很多。城门旁边的城墙上张贴着一纸告示(gaoshi)。
LONG
        );

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
                "east" : __DIR__"xijie2",
                "west" : __DIR__"wroad",
	]));

        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));

        set("outdoors", "福州");
	setup();
        quarter_pass();
}

void quarter_pass()
{
        string local;

        local = NATURE_D->query_daytime();

        switch(local){
            case "event_night":
            case "event_midnight":
                  set("long", @LONG
这里是福州府的西门，城墙不是很高，有一座中等规模的城门。出此门向
西北可往湘赣，进而入川；西南可达两广，直抵云贵；因此出入往来的客商一
向很多。因为现在是夜晚，城门已经关了，所以暂时无法出城。城门旁边的城
墙上张贴着一纸告示(gaoshi)。
LONG);
        	  delete("exits/west");
                  break;
            default: set("long", @LONG
这里是福州府的西门，城墙不是很高，有一座中等规模的城门。出此门向
西北可往湘赣，进而入川；西南可达两广，直抵云贵；因此出入往来的客商一
向很多。城门旁边的城墙上张贴着一纸告示(gaoshi)。
LONG);
                  set("exits/west", __DIR__"wroad");
        	  break;
        }
        call_out("quarter_pass", 60);
}

int valid_leave(object me, string dir)
{
          if (dir =="west" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("官兵手中的刀挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}
string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n福州巡府\n";
}
