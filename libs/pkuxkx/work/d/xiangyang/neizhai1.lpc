
inherit ROOM;
void create()
{
	set("short", "吕家内宅");
	set("long", @LONG
这里是吕文德家的内宅,几个亲兵在这里守卫,桌上摆着简简单单几样小菜.
这些亲兵敬酒吃菜,好不悠闲.楼上传来丝竹之声,夹杂着女子嬉笑之声.
LONG
	);

	set("exits", ([
		"south" : __DIR__"lvzhai",
		"up" : __DIR__"neizhai2"          
	]));

	set("objects", ([
		__DIR__"npc/qinbing" : 4,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{        
    object *ob;
    int i;
    
    if( dir != "up" )
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "qin bing" )
            return notify_fail("亲兵拦住了你的去路,大声喝到:敢闯吕大人的家,你不想活了?\n");
    }
    return ::valid_leave(me, dir);
}

