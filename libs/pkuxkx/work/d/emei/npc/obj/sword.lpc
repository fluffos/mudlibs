//Zine EM　ｎｅｗｂｉｅ　ｊｏｂ
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(CYN"软剑"NOR, ({ "ruan jian", "jian"}) );
        set_weight(100);
        if (clonep())
		set_default_object(__FILE__);
	    else {
        set("unit", "把");
        set("value", 10000);
        set("material", "steel");
        set("long", "这是一把又细又长的软剑，非常轻便。\n");
        set("wield_msg", "一道青光闪过，$N手中已多了把$n。\n");
        set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(105);
        setup();
}

int query_autoload() 
{
    object env=environment(this_object());
    if (!env)
    {
        return 0;
    }
    if (!env->query("emeinewbiejobdonedone2"))
    {
        return 0;
    }
    return 1; 
}

void init()
{
    object ob=this_object();
    object env=environment(ob);
    if (!env)
    {
        return;
    }
    if (env&&userp(env)&&env->query("emeinewbiejobdonedone2"))
    {
        set("long","这是一把师门赠给"+HIW+env->query("name")+NOR+"的软剑，锋利异常。\n");
        return;
    }
}

