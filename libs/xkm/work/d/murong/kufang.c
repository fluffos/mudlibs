//Cracked by hotjc
//kufang.c 

inherit ROOM;

void create()
{
     set("short", "库房");
        set("long", @LONG
这里是慕容的兵器库，墙边的兵器架上陈列着许多长剑，短剑和竹剑。
LONG
        );

        set("exits", ([
           "west" : __DIR__"qing3",
        ]));

        set("objects", ([
                __DIR__"obj/changjian" : 2,
                  __DIR__"obj/mudao" : 2,
                  __DIR__"obj/duanjian" : 2,
        ]));

        set("cost", 0);
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
        }
        
        if ( j == 1 ) me->set_temp("marks/剑", 1);
        if ( j > 1 ) return notify_fail("别那么自私！你不能带走超过一把兵器。\n");

        return ::valid_leave(me, dir);
}

