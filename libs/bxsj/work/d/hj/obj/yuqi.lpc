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
        switch(random(13)) {
        case 0 : set_name(GRN"玉人头饰"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 1 : set_name(HIY"兽面纹玉琮"NOR, ({"yu pei", "yu", "pei"})); break;
        case 2 : set_name(HIW"三叉形玉器"NOR, ({"yu pei", "yu", "pei"})); break;
        case 3 : set_name(MAG"玉龙"NOR, ({"yu pei", "yu", "pei"})); break;
        case 4 : set_name(YEL"猪龙形玉佩饰"NOR, ({"yu pei", "yu", "pei"})); break;
        case 5 : set_name(WHT"玉龟"NOR, ({ "yu pei", "yu", "pei"})); break;
        case 6 : set_name(WHT"兔形玉佩"NOR, ({"yu pei", "yu", "pei"})); break;
        case 7 : set_name(YEL"虎形玉佩"NOR, ({"yu pei", "yu", "pei"})); break;
        case 8 : set_name(GRN"蛙形绿松石佩"NOR, ({"yu pei", "yu", "pei"})); break;
        case 9 : set_name(HIY"跪式玉人"NOR, ({"yu pei", "yu", "pei"})); break;
        case 10 : set_name(CYN"拱手玉人"NOR, ({"yu pei", "yu", "pei"})); break;
        case 11 : set_name(CYN"玉虎"NOR, ({"yu pei", "yu", "pei"})); break;
        case 12 : set_name(MAG"玉凤"NOR, ({"yu pei", "yu", "pei"})); break;
        }
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "块");
                set("weight", 1000);
		set("long", "这是东汉玉石饰品中的一个，出自陕西，山东，河南一带。\n");
		set("material", "stone");
                set("unique", 4);
                set("no_get",(:no_get:));
		set("no_drop",(:no_drop:));
        }
	setup();
}
