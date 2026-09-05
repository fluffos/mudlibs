//石碑
//create by zine 29/3/2011
#include <ansi.h>

inherit ITEM;
void create()
{	
	set_name(WHT"石碑"NOR, ({ "shi bei","bei"}));
	set_weight(500000000);
	set("long", "这是一面巨大的石碑，上面篆刻的字你完全读不懂。\n");
	set("material", "jade");
	set("unit", "面");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_put",1);
    set("no_store",1);
    set("is_shibei",1);
    set("is_bonus_xiulian",1);
	setup();
    call_out("checkme",1);
}

int checkme()
{
    object ob=this_object();
    object room=environment(ob);
    if (!room)
    {
        message_vision(HIB"突然一声巨响，$N"+HIB+"四分五裂开。\n"NOR,ob);
        destruct(ob);
        return 1;
    }
    if (!room->isroom())
    {
        message_vision(HIB"突然一声巨响，$N"+HIB+"四分五裂开。\n"NOR,ob);
        destruct(ob);
        return 1;
    }
    if (!room->query("goodplace"))
    {
        message_vision(HIB"突然一声巨响，$N"+HIB+"四分五裂开。\n"NOR,ob);
        if (!ob->query("roomno_reset"))
        {
            room->delete("no_reset");
            room->delete("no_clean_up");
        }
        destruct(ob);
        return 1;
    }
    remove_call_out("checkme");
    call_out("checkme",60);
    return 1;
}