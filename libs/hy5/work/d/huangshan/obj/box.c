#include <ansi.h>
inherit ITEM; 
void create()
{
    set_name("绿石盒", ({ "box", "stone box"}) );
    set_weight(800);
    set_max_encumbrance(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
                set("unit", "个");
                set("long", "一个碧绿色的小石盒。你可以试着把它打开(open)\n");
                set("value", 20);
        set("prep", "in");
        set("value", 500);
    }
        
} 
int is_container() {return 1;} 
void init()
{
   add_action("do_open","open");
} 
int do_open(string arg)
{
        object me, ob, item;
        
        me = this_player();
        ob = this_object();
    if( !arg || arg != "box" ) {
        return notify_fail("你要打开什么？\n");
    }
    if(ob->query_temp("marks/opened")) {
        return notify_fail("石盒已经被打开过了。\n");
        }
        if(!me->query("宿命B/桃源_核桃") || me->query("stone_mark/gstone")) {
                message_vision("$N试着打开小石盒，小盒有如一块整体石头纹丝不动。\n", me);
                return 1;
        }       
        message_vision("$N用力把$n打开．．．\n", me, ob);
    set("long", "一个绿色的小石盒，盒盖已经被打开了。\n");
    item = new("/obj/specials/stone/gstone");
        if (objectp(item)){
                message_vision("一块晶莹剔透的翡翠落入$N怀中。\n", me);
        item->move(me);
        me->set("stone_mark/gstone", 1);
        me->add("combat_exp", 200);
        ob->set("value", 0);
    }
        ob->set_temp("marks/opened",1);
    return 1;
}       
