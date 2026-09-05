//Zine EM　ｎｅｗｂｉｅ　ｊｏｂ
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(HIG"柳叶刀"NOR, ({ "liuye dao", "dao"}) );
        set_weight(400);
        if (clonep())
		set_default_object(__FILE__);
	    else {
        set("unit", "把");
        set("value", 10000);
        set("material", "steel");
        set("long", "这是一把薄薄的柳叶刀，十分锋利。\n");
        set("wield_msg", "一道幽光闪过，$N手中已多了把$n。\n");
        set("unequip_msg", "$N将手中的$n插回腰间。\n");
        }
        init_blade(105);
        setup();
}

int query_autoload() 
{
    object env=environment(this_object());
    if (!env)
    {
        return 0;
    }
    if (!env->query("emeinewbiejobdonedone3"))
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
    if (env&&userp(env)&&env->query("emeinewbiejobdonedone3"))
    {
        set("long","这是一把师门赠给"+HIW+env->query("name")+NOR+"的柳叶刀，锋利异常。\n");
        return;
    }
}

