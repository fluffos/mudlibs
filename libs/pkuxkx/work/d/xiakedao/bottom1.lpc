
inherit ROOM;

void create()
{
        set("short", "小溪底");
        set("long", @LONG

    这里实在很美，很静。溪水清澈冰凉，，看著水草在砂石
间娥娜起舞，这种感觉不是未曾经历此境的人所能领略得到的。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"bottom",
		"eastup" : __DIR__"gudi",
		"north" : __DIR__"bottom3",
	]));

        setup();
}

int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i;

	if( dir == "eastup" ) return 1;
        if( userp(me)) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) 
                        if(inv[i]->name() == "花草")  return 1;
        }
        return notify_fail("\n你觉得胸口发闷，还是赶快上岸的好！\n");
}


