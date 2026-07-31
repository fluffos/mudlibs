#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"麦克峰"NOR, ({ "mi","phone" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄麦克峰，你可以用它高歌一曲。\n");
                set("material", "steel");
                set("wield_msg", "$N拿出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放回口袋里。\n");
        }
        init_sword(100);
        setup();
}
void init()
{
       add_action("do_music","music");
}
int do_music(string arg)
{
        object room, me;
        me = this_player();
        if( !arg || arg == "" ) return notify_fail("不可以拿这东东乱叫！\n");
      if( me->is_busy() )
                return notify_fail("你的喉咙都哑了吧？来喝口水先。\n");

        
message("channel:chat", HIC"〖"HIB"世纪演唱会"HIC"〗"+ HIY + me->query("name") + "高声唱道："HIR + arg +"\n"NOR,users());    
      me->start_busy(3);
        return 1;
}

