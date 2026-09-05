// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        int n;
        string* setcolor=({HIR,HIY,HIB,HIG,HIC,HIM,HIW});
        string color;
        n=sizeof(setcolor);
        n=random(n);
        color=setcolor[n];
        set_name(color+"钢刀"+NOR, ({ "blade","gang dao" }));
        set("color",n+1);
        set("mingjiaoquest",2);
        set("unit", "柄");
        set("long", "这是一柄亮晃晃的钢刀，江湖中人很喜欢用它。\n");
        set("value", 0);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        
        init_blade(20);
        setup();
        call_out("dest",120);
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
        return 1;
    }
}

void init()
{
    int i,count=0;
    object* all=all_inventory(environment());
    
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("mingjiaoquest"))
        {
            count=count+1;
            if (count==2)
            {
                if (all[i]!=this_object())
                {
                    destruct(all[i]);
                    count=count-1;
                }
            }
        }
    }
    
    return;
}