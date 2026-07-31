#include <ansi.h>

inherit ITEM;

string no_get()
{
	object me = this_player();
	if(!me) return 0;
	if(me->query("combat_exp")<750000)
		return "你江湖游历不足，怕得此宝物也无用处。\n";
	if(me->query("drop_hj_uniqe") && ( me->query("mud_time")-me->query("drop_hj_uniqe"))<172800)
		return "你暴殄天物，高昌不欢迎你。\n";
	return 0;
}

int no_drop()
{
	object me = this_player();
	if(!me) return 0;
	me->set("drop_hj_uniqe",me->query("mud_time"));
	return 0;
}

void remove(string id)
{
	object me = environment();
	if(me && objectp(me) && userp(me))
		me->set("drop_hj_uniqe",me->query("mud_time"));
}

void create()
{
        set_name(HIC"快雪时晴帖"NOR, ({ "kuaixueshiqing tie", "tie"})); 
       
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "张");
                set("unique", 1);
                set("weight", 300);
		set("long", "这是晋王羲之所写之帖，纸册本，纵二三寸，横一四寸。\n");
		set("material", "paper");
		set("no_get",(:no_get:));
		set("no_drop",(:no_drop:));
		}
	setup();
}
