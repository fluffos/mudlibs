//jiaowei qin 焦尾琴

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIM"焦尾琴"NOR,({"jiaowei qin","qin", "jiaowei"}));
        set_weight(10500);
        if(clonep())
                 set_default_object(__FILE__);
        else{
              set("unit","张");
              set("value",40000);
              set("rigidity", 2);
              set("unique", 1);
              set("material","steel");
              set("long","相传这便是当年蔡文姬从火中所救出的焦木做成的美琴，琴的尾端仍可见焦黑色。\n");
              set("wield_msg",HIY"$N伸手轻轻一挥,一张焦尾琴便已出现在$N手中.\n"NOR);
              set("unwield_msg",HIY"$N十指一拂，琴声曳然而止。$N收起焦尾琴，放进背着的包袱里。\n"NOR);
              }
    init_sword(65);
        setup();
}