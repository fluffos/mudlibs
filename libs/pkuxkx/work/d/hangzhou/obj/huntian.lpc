#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"浑天仪"NOR, ({ "huntian yi", "yi", "huntian" }) );
        set_weight(3000);
        set("unit", "座");
        set("long", "这是一座浑天仪，据说是张衡发明的。\n");
        
        set("value", 1000);
        set("material", "bronze");
        set("no_get",1);
        set("no_drop",1);
               
        setup();
}

void init()
{
    add_action("do_jisuan", "jisuan");
}

int do_jisuan()
{
    object me=this_player();
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    message_vision("$N拨动浑天仪，开始计算着什么。\n",me);
    if (!me->query("exp_dep"))
    {
        message_vision("$N发现浑天仪上有些模糊。\n",me);
        return 1;
    }
    else
    {
        tell_object(me,"浑天仪转了转，终于停了下来："+me->query("exp_dep")+"。\n");
        return 1;
    }
}