//夜读<<风云>>有感
// jianxia.c 天龙神剑之剑匣
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("剑匣",({ "jian xia", "jianxia", "xia", "box" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 10000);
                set("material", "wood");
                set("long", "这是黑色的剑匣,沉甸甸的,一股寒气弥漫四周。\n");
                 }
        setup();
}
void init()
{
       add_action("do_break", "break");
       add_action("do_break", "zhen");
       add_action("do_break", "sui");
       add_action("do_break", "posui");
}

int do_break(string arg)
{
        object me,ob;
        me = this_player();
               
       if (!(arg=="xia" || arg == "jian xia" || arg == "jianxia" || arg == "box"))
       return 0;

if( (int)me->query("max_neili") < 3000)
		        {
                       write("你内力太低无法驱动神剑。\n");
			return 1;
				}
       
        if( (int)me->query_skill("sword", 1) < 180)
		        {
              write("你剑法造诣太低,无法使用绝世好剑。\n");
                 return 1;
				}
      
message_vision(HIY   "$N一把将自己背着的剑匣重重插在地上，剑匣登时应劲破开！「嗡」的一声,一道光芒冲天而起,\n"+
                                    "一把神剑缓缓飞起,而匣 内的神剑，赫然无法出鞘！\n"+
                                    "只  因   剑    已    无   鞘   可   出   ！\n"+
                                     "剑鞘已在剑匣破开之时，给$N的无俦内力震爆！迸为寸碎！\n"+
                                    "一柄盖世无敌的天龙神剑，此刻握在$N的手上！。\n" NOR, me);
            ob=new("/clone/weapon/tianlong-shenjian");
            ob->move(me);
            ob->wield();
            destruct(this_object());
            return 1;
}
