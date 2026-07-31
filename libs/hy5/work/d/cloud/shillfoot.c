
// Room: /u/cloud/dragonhill/shill.c

inherit ROOM;

void create()
{
        set("coor",({1000,4400,0}));
	set("short", "卧龙岗南坡");
        set("long",
"这是卧龙岗的东南坡。东南的路通向绮云镇，往北就要过岗了。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"hummock",
  "south" : __DIR__"shijie5",
  "southeast" : __DIR__"entrance"
]));
        set("outdoors", "cloud");

        setup();
}
int valid_leave(object me, string dir)
{       object ob;
        object *inv;
        int i;
if (dir=="southeast"&&ob=present("soldier", this_object()))
{
if (ob->query("leader")==me->query("name")&&
    me->query("rank")==1) return 1;
else{
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)               
 {if (((inv[i]->query("targetid")) == me->query("id"))
        &&((string)(inv[i]->query("id")) == "token"))
        return 1;
 }              
return notify_fail(ob->name()+"向你嚷道：奉"+
ob->query("leader")+"之命封锁此路!没有通行证不得通过!\n");
    }
}
else return 1;  
}       
