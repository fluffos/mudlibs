// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        int n;
        string* setcolor=({HIR,HIY,HIB,HIG,HIC,HIM,HIW});
        string color;
        n=sizeof(setcolor);
        n=random(n);
        color=setcolor[n];
        set_name(color+"钢剑"+NOR, ({ "sword","gang jian" }));
        set("color",n+1);
        set("mingjiaoquest",1);
        set("unit", "柄");
        set("long", "这是一柄锋利的钢剑，江湖中人很喜欢用它。\n");
        set("value", 0);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        
        init_sword(20);
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