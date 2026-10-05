#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM"绣花荷包"NOR, ({ "notecase"}) );
        set_weight(100);
        set_max_encumbrance(80000);
        set("unit", "个");
        set("long", "一个上好锦缎编织的绣花荷包，珠面光滑圆润，正是江南的手工艺。\n");
        set("closed", 1);
        set("value", 10000);
} 
//int is_container() {return 1;} 
void init()
{
        if(this_player()==environment())
                 add_action("do_open","open");
}
int do_open(string arg)
{
	object gold, me;
        me = this_player();
        if(arg != "notecase" ) return 0;
        if(query("opened"))
                return notify_fail("你打开荷包，但里面是空的！\n");
        gold = new("/d/shenshui/npc/obj/pearl2");
        gold->set_amount(12);
        gold->set("name","珍珠");
        gold->set("base_unit","颗");
        gold->move(this_player());
        set("opened",1);
        return notify_fail(NOR "\n你打开荷包，一粒如情人泪滴一样的珍珠掉入你怀中。\n" NOR);

} 
