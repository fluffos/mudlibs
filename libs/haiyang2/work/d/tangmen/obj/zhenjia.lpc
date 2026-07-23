//kaolu.c
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("暗器宝匣", ({ "anqi baoxia" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
set("no_clone",1);
            set("unit", "个");
            set("value", 15000);
            set("material", "stone");
            set("long", "一个暗器宝匣，里面可以装备用的暗器，你可以用它补允(insert)暗嚣。\n");
          }

    setup();
}
void init()
{
 add_action("do_kao","insert");
 add_action("do_kao","zhuang");
}                             

int do_kao(string arg)
{
        object me;
        object tar;
        object meat;
        string name;
        int decayed;
        me = this_player();
        if( !arg || arg == "")
                return notify_fail("你装什么？\n");

	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");

        if(!objectp(tar = present(arg, me)) )
                         return notify_fail("你装什么？\n");
         if(!objectp(tar = present(arg, me)) )
                return notify_fail("你装什么上啊？\n");
        if(tar->is_character() && living(tar))//!tar->is_corpse())
                return notify_fail("那个不能装额。\n");
        if( (string)tar->query("skill_type") != "throwing")
                return notify_fail("那个不能装额，只能给暗器补充．\n");
        if( tar->query_amount() >= 100)
                return notify_fail("现在不需要给暗器补充．\n");

        if( tar->query("skill_type")== "throwing")
        {
          tar->add_amount(100);
            }
        message_vision("$N打开暗器宝匣取出了一些$n拿在了手中。\n", me, tar);
        me->start_busy(3);

        return 1;
}
