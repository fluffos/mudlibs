//Made By:pingpang
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("木棺", ({ "coffin"}) );
        set_weight(500); 
        set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "个");
                set("long", "一个巨大的木棺,你可以打开(open)它。\n");
                set("value", 1);
                set("been_get", 1);
        }
}
int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object jifeng,qixing,yulu;
        if((int)this_player()->query_str()<19) return notify_fail("你使出吃奶的力气，可是木棺纹丝不动。\n");
        if(!arg||arg!="coffin") return notify_fail("你想打开什么?\n");
        message_vision("$N试着打开木棺的盖子...\n",this_player());
        if(query("been_get")<1)
                return notify_fail("你打开木棺，但里面空空如也，什么也没有。\n");
        add("been_get",-1);
         if (random(3)) return notify_fail("你打开木棺，但里面空空如也，什么也没有。\n");
        tell_object(this_player(),"你发现里面藏着一双"HIC"疾风靴"NOR",一把"HIC"七星剑"NOR"和一棵"GRN"天仙玉露"NOR"，你把它拿了出来。\n");
        yulu=new(__DIR__"obj/yulu");
        yulu->move(this_player());
    jifeng=new(__DIR__"obj/jifeng");
    jifeng->move(this_player());
    qixing=new(__DIR__"obj/qixing");
    qixing->move(this_player());
    return 1;
}
