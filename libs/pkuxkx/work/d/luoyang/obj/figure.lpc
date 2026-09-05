//泥人
inherit ITEM;
#include <ansi.h>
void create()
{
        string* color=({YEL,WHT,GRN});
        set_name(color[random(sizeof(color))]+"泥人"NOR, ({"ni ren", "ren", "clay figure" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个泥塑的小人，栩栩如生，巧夺天工。\n");
                set("unit", "个");
                set("value", 10);
             }
}

void init()
{	
	add_action("do_da", ({ "da", }));
}

int daniren(object me)
{
    me->delete_temp("daniren");
    return 1;
}

int do_da()
{
    string* color=({HIC,HIW,HIR,HIY,HIG,HIM});
    object me=this_player();
    object target;
    if (me->query_temp("daniren"))
    {
        tell_object(me,"你刚打过小人，休息一会吧。\n");
        return 1;
    }
    if (this_object()->query("owner")==me->query("id"))
    {
        tell_object(me,"你有这么憎恨自己吗？不如去suicide吧。\n");
        return 1;
    }
    else
    {
        message_vision(color[random(sizeof(color))]+"打你个小人头，打到你面生毒瘤。\n",me);
        message_vision(color[random(sizeof(color))]+"打你个小人鼻，打到你全身死魚味。\n",me);
        message_vision(color[random(sizeof(color))]+"打你个小人手，打到你日日搽跌打酒。\n",me);
        message_vision(color[random(sizeof(color))]+"打你个小人腳，打到你情人节没人約。\n",me);
        message_vision(color[random(sizeof(color))]+"打你个小人肚，打到你人老錢又无。\n",me);
        message_vision(color[random(sizeof(color))]+"打你个小人胸，打到你个胸变猪肉松。\n",me);
        me->set_temp("daniren",1);
        remove_call_out("daniren");
        call_out("daniren",20,me);
        if (this_object()->query("owner"))
        {
            target=find_player(this_object()->query("owner"));
        }
        if (target)
        {
            message_vision("千里之外的"+this_object()->query("name")+"似乎感应到什么，腹痛如刀绞。\n",me);
            tell_object(target,RED"你似乎被人狠狠在心口打了一拳，痛如刀绞。\n"NOR);
            target->add_busy(random(3));
            return 1;
        }
        else
        {
            message_vision("但是似乎什么都没有发生。\n",me);
            return 1;
        }
    }
    
}