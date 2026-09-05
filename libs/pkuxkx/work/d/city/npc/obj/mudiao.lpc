//mudiao By Zine 史可法三期

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(RED"木雕"NOR, ({"mu diao", "diao", "craft"}));
	set_weight(80);
	set("long", "一个栩栩如生的木雕，由一百刀刻成。\n");
	set("unit", "个");
	set("value", 0);
    setup();
    call_out("checkme",1);
}

int checkme()
{
    object ob=this_object();
    object belong;
    if (ob->query("owner"))
    {
        belong=find_player(ob->query("owner"));
    }
    
    if (objectp(belong)&&
    	  belong->is_character()&&
    	  userp(belong)&&
    	  belong->query_temp("skf/killnumber"))
        {
            set("long","一个栩栩如生的木雕，由一百刀刻成。上面有"+chinese_number(belong->query_temp("skf/killnumber"))+"道，已经被鲜血染红。\n");
        }
    remove_call_out("checkme");
    call_out("checkme",10);
    return 1;
}
