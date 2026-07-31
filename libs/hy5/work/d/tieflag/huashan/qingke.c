 inherit ROOM;
void create()
{
        set("short", "青柯坪南脉");
        set("long", @LONG
穿过水帘洞瀑布，山路一转，眼前豁然开朗，一块平地出现在眼前。这里三面
环山，景色幽静，泉清石奇巨树浓荫遮天，翠峰云绕，亭台楼阁掩映在绿树丛中，
给人以如登仙境之感觉。
LONG
        );
    set("exits", ([ 
                "northeast" : __DIR__"snowcave",
                "west" : __DIR__"shibapan2",
                "southup" : __DIR__"huixin",
        ])); 
        set("objects", ([
                __DIR__"obj/stone1" : 1,
                __DIR__"npc/woodcutter" : 1,
                __DIR__"npc/seller2" : 1,
        ]) );   
        set("outdoors", "huashanfy"); 
        set("coor/x",-580);
        set("coor/y",-70);
        set("coor/z",40);
        setup();
   
} 
void reset()
{
        object *inv;
        object item, obj;
        int i;
        
        ::reset(); 
        obj = present("stone", this_object());
        inv = all_inventory(obj);
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("id")=="handkerchief") return;
        }
        item = new(__DIR__"obj/handkerchief");
           item->move(obj);
} 
