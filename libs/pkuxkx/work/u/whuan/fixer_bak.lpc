//装备修复器
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"装备修复器"NOR, ({ "xiufu qi","fixer"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "wood");
                set("value", 99);
                set("no_get", 1);
        }
        setup();
}

void init()
{
        add_action("do_fix", "fix");
}
int do_fix(string arg)
{
        object ob,who;
        who = this_player();    
        if(!arg)
                return notify_fail("你要修复什么装备？\n");
        if(!ob=present(arg,who))
                return notify_fail("你要修复什么装备？\n");
        if(!ob->is_gems())
                return notify_fail("这个东西我可修复不了！\n");
        if(!ob->query("weapon_prop")&&!ob->query("armor_prop"))
                return notify_fail("目前只能自动修复武器和盔甲！\n");   
        if(ob->query("gem_ob_autoloaded"))
                return notify_fail("这件东西取消自动加载之后方能修复！\n"); 
        if(ob->query("weapon_prop/damage"))
                {
                	  ob->delete("weapon_prop/damage");
                    ob->set("weapon_prop",ob->query("weapon"));
                    ob->set("name",ob->query("weapon/name"));
                    ob->delete("weapon_prop/max_dam");
                    ob->delete("weapon_prop/min_dam");
                    ob->delete("weapon_prop/name");
                    ob->set("rigidity",ob->query("max_rigidity"));
                    return 1;                               
                }
        if(ob->query("armor_prop/armor"))
                {
                	  ob->delete("armor_prop/armor"); 
                    ob->set("armor_prop",ob->query("armor"));
                    ob->set("armor_prop/armor",ob->query("armor/defense"));
                    ob->delete("armor_prop/defense");
                    ob->delete("armor_prop/max_def");
                    ob->delete("armor_prop/min_def");
                    ob->delete("armor_prop/name");
                    return 1;                               
                }
                tell_object(who,"你的装备没啥问题啊，为什么要修？\n");                                       
                return 1;
}
