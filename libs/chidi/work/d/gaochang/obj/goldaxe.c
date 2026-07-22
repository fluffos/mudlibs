// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(YEL "黄金斧" NOR, ({"axe","gold axe"}));
    set_weight(80000);

    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "这是一把"+YEL+"黄金"+NOR+"打造的斧头。斧柄末端似乎有些松动。\n");
        set("value", 5000000);
        set("flag",1);
        set("get_拉1",1);
        set("material", "gold");
        set("wield_msg", "$N从背上拔出一把"+YEL+"黄金斧"+NOR+"，握在手中。\n");
        set("unwield_msg", "$N将一把"+YEL+"黄金斧"+NOR+"插在背上。\n");
          set("weapon_prop/dodge", 50);
      }  
    init_axe(500,1);
    setup();
    }
void init()
{
      if (environment()==this_user())
            add_action("do_pick","pick");
}
   
int do_pick(string arg)
{
        object me,ob,ob1;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (query("get_拉1"))
        if( arg=="斧柄") {
             ob=new("/d/gaochang/obj/yu");
            if (ob->move(me)){
                     write("你扭开斧柄，从中间抽出一块玉简。\n");
                         add("get_拉1",-1);   {
             ob1=new("/d/gaochang/obj/goldaxe1");
             this_object()->move(environment(me));
             ob1->move(me);
             destruct(this_object());
             return 1;
        }         
             }else
                     write("你扭开斧柄，发现里面什么也没有。\n");
             return 1;
       }
        return 0;
}
void dest() { destruct(this_object()); }
void owner_is_killed() { call_out("dest",1); }

