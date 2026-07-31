#include <ansi.h>
inherit ITEM;
void create()
{
                
        set_name(RED"迷宫入口"NOR, ({ "maze door","door"}) );
        set_weight(5);
        set("no_get",1);
set("no_drop",1);
set("dynamic_quest",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入迷宫。(enter door)\n"NOR); 
                set("unit", "个");
                set("lore",1);
                set("value", 20);
        set("maze_entry", "/p/migong/boss/VRM_0011/entry");
        }
        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg) {
        object maze;
        string entry;
                
        if( arg != "door" )
                return 0;
        
        entry = query("maze_entry");
        
        if( !stringp(entry) || entry == "" )
                return notify_fail("迷宫已经摧毁，无法进入。\n");

        if( !objectp(maze = find_object(entry)) ) maze = load_object(entry);
        if( !objectp(maze) ) return notify_fail("迷宫已经摧毁，无法进入。\n");
                
        this_player()->move(maze);
        return 1;
}

