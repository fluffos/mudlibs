// shanding.c 山顶
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",YEL"山顶平地"NOR);
	 set("long",@LONG
山顶四周草木青翠欲滴，繁花似锦，一路上已是风物佳胜，此处更是个罕
见的美景之地，信步而行，只见路旁仙鹤三二、白鹿成群，松鼠小兔，尽是见
人不惊。东面一条山路不知通往何处，北面是一大片竹林。
LONG
);
          set("outdoors","绝情谷"); 
          set("exits",([
             "southdown": __DIR__"shanjing1",
             "west": __DIR__"xshiwu",
             "east": __DIR__"shanlu4",
             "northdown": __DIR__"shuitang"
          ]));

          setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir,object *obj)
{
       object *inv = deep_inventory(me);
       if (dir == "northdown") {
           write("北面是一大片竹林，北方很少见长得这般茂密的竹林，数量之大，确实罕见。\n");
        obj = filter_array(inv,(:get_object:));        
        if ( random(me->query("kar")) > 12 && ! sizeof(obj))
           write(HIW"\n你缓缓在绿竹篁中穿过，闻到一阵阵淡淡花香，登觉烦俗尽消。\n\n"NOR);
            else {
             tell_room(environment(me), me->name()+"往北边的"GRN"竹林"NOR"快步离开。\n"NOR, ({ me }));
             me->move(__DIR__"zhulin" + (random(6) + 1));
             tell_room(environment(me), me->name()+"从山顶平地快步走了过来。\n"NOR, ({ me }));
             me->look();
             return notify_fail("");
             }
        }
        return ::valid_leave(me, dir);
}
