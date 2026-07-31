 // searoad.c
inherit ROOM;
void create()
{
        set("short", "平原路");
        set("long", @LONG
大道自西向东，地势渐平。路面铺着小石子，光脚走上去，觉得颇为硌脚。道两
旁的树木越来越少，骄阳似火，令人真想找个地方休息一下。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"searoad",
  "west" : __DIR__"troad4",
]));
        set("outdoors", "tieflag");
        set("coor/x",980);
        set("coor/y",-290);
        set("coor/z",-10);
        set("coor/x",980);
        set("coor/y",-290);
        set("coor/z",-10);
        set("coor/x",980);
        set("coor/y",-290);
        set("coor/z",-10);
        setup();
}  
int valid_leave(object who,string dir)
{
        if(userp(who) && random(3))
        {
                who->move(this_object());
                return notify_fail(""); 
        }
        return 1;
}    
