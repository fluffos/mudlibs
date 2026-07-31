inherit ROOM;
void create()
{
        set("short", "听雨楼");
        set("long", @LONG
听雨楼坐落在浣花溪上，淙淙的溪流从它的正下方流过。这座小楼充分地
显示着江南小镇那种独特仅有的风格，楼下的溪水清清的。偶尔一两只粉
蝶从溪上飞过，也象是破坏了这里平静的气氛。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"guanyuge",
		"north" : __DIR__"xiaoxuan" ,
]));
        set("objects", ([
                 __DIR__"npc/dizi" : 2,
                        ]) );
        set("outdoors", "huanhua");
        set("resource/water",1);
        set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	set("coor/x",70);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清水",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("你从弯弯的小溪流里装满了清水! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？");
        }
        return 1;
}

