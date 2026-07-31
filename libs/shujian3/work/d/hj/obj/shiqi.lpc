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
        switch(random(7)) {
        case 0 : set_name("牛文明墓画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 1 : set_name("车骑过桥画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 2 : set_name("狩猎画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 3 : set_name("桥头交战画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 4 : set_name("斗兽画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 5 : set_name("两桃杀三士画像石", ({ "xiang shi", "shi", "stone"})); break;
        case 6 : set_name("比武画像石", ({ "xiang shi", "shi", "stone"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "块");
                set("weight", 1000);
		set("long", "这是东汉石雕像中的一个，出自陕西，山东，河南一带。\n");
		set("material", "stone");
                set("unique", 4);
                set("no_get",(:no_get:));
		set("no_drop",(:no_drop:));
        }
	setup();
}
