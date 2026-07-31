//yuzhu.c
inherit ITEM;
#include <ansi.h>
void owner_is_killed() { destruct(this_object()); }  
void create()
{
        set_name(MAG"金斑紫竹"NOR, ({"jinban zizhu","zizhu","jinban"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",MAG"这是根坚韧无比的金斑紫竹，浅紫色的竹身上有一些金色的斑点，十分好看，它又轻又硬，似乎是制造兵器的上好材料。\n"NOR);
                set("can_make", "all");
                set("not_make", ({"锤", "斧"}));
                set("no_sell", 1);
                   set("tianya_money",3); 
                //set("no_drop", "这么珍贵的稀有金属，你可不能随意丢弃！\n");
                set("rate", 3); //设置材料等级
                set("power_point", 150+random(30)); //做成后的jiali大小
                set("material_attrib", "bamboo");
              }
}
