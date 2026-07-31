 inherit ROOM;
void create()
{
        set("short", "花厅");
        set("long", @LONG
推开门，又是间花厅。厅堂的中央，有张桌子，桌子上有只天青色的
大碗，碗里是只烧得红红的鸡。四面的椅子上，坐着几个人。这几人虽然
都是男人，但看来却又和女子相似，每个人都懒洋洋地坐在那里。
LONG
        );
        set("exits", ([ 
                "northwest" : __DIR__"bedroom1",
                "north" : __DIR__"bedroom2",
                "south" : __DIR__"palace3",
                "east" : __DIR__"corridor",
                        ]));
        set("objects", ([
                __DIR__"npc/girl1" : 1,
                __DIR__"npc/girl3" : 1,
                __DIR__"npc/baiyi" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "north"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"说：主人正忙着呢。\n");
                }
        }       
   return 1;
} 
