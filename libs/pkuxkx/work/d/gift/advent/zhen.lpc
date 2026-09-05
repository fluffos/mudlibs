#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_AUTOLOAD;
inherit F_SAVE;
void setup()
{}
void create()
{
        set_name(HIG"碧磷针"NOR, ({"bilin zhen","zhen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIG"这是一根星宿独门暗器－碧磷针，上面微微罩着一层幽绿的磷光。\n"NOR);
                set("value", 800000);
                set("no_get", 1);
                set("no_drop", 1);
                set("no_steal", 1);
                set("material", "steel");
                set("rigidity", 3000000);
                set("auto_load", 1);
                set("wield_msg", HIG"$N从腰间锦囊中轻轻拈起一根碧磷针，捏在手中。\n"NOR);
                set("unwield_msg", HIR"$N将手中的碧磷针插回腰间锦囊。\n"NOR);
        }
        init_sword(3000);
        seteuid(getuid());
        setup();
}
void init()
{
add_action("do_heshi", "heshi");
}
int do_heshi(string arg)
{       object me=this_player(),zhen;
        if (!id(arg))
                return notify_fail("你要念什么？\n");
else {
message_vision(HIY"$N双手合什，默念咒语，锦囊又鼓了起来！\n"NOR, me);
         zhen = new("/d/gift/advent/zhen");
         zhen->move(me);
return 1;
}
}
string query_autoload()
{
     return query("name");
}
void autoload()
{}
