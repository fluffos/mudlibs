 inherit ROOM;
void create()
{
        set("short", "大堂");
        set("long", @LONG
大堂中灯火通明，光如白昼，名副其实是一个大堂。堂中的陈设犹如王侯府，
灯光照耀下更是华丽。南北两边是全套酸枝公座椅，当中摆着云石桌子、云石凳子。
西面靠墙是一个红木桌子，上面陈设着碧玉、玛瑙、珊瑚、怪石种种玩器。正中并
排放着五张太师椅，后面是一面屏风，遮住了东侧的照壁。
LONG
        );
        set("exits", ([ 
                "north":  __DIR__"village1",
                "south": __DIR__"lroad3",
                "east": __DIR__"pingfeng",
        ]));
        set("item_desc", ([
        
         ]));
         set("objects", ([
                __DIR__"npc/daniang": 1,
                __DIR__"npc/whitewoman": 2,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me,string dir) { 
        object li,woman;
        li=present("li daniang",this_object());
        if (dir=="east" && li)
        if (!userp(li)) {
                message_vision(li->name()+"身子一晃，挡住了$N的去路。\n",me);
                return notify_fail("");
        }
        woman=present("white cloth woman",this_object());
        if (dir=="east" && woman)
        if (!userp(woman)) {
                message_vision(woman->name()+"身子一晃，挡住了$N的去路。\n",me);
           return notify_fail("");
        }
        return 1;
        
}
