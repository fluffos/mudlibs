inherit ITEM;

#include <ansi.h>
void create()
{
        set_name(WHT"云之遥的魔法杖"NOR, ({ "magic stick","stick"}));
        set_weight(600);
		set("unit", "支");
		set("long","这是云之遥的魔法杖，用来修改某些object无法用call指令的特殊属性，比如带有颜色代码的属性。\n");
		set("value", 1);
		set("material", "wood");
}
void init()
{
	add_action("do_change_temp", "change_temp_mapping");
	add_action("do_change", "change_mapping");
	add_action("do_change_temp_array", "change_temp_array");
	add_action("do_change_intarray", "change_intarray");
}

int do_change_temp(string arg)
{
    string tar, att;
	mapping ratt;
	string *n;
	int idx, val;
	object ob;
	if (this_player()->query("id")!="lordstar")
		return notify_fail("只有创造它的人才可使用这把魔法杖。\n");
	if (!arg || sscanf(arg, "%s %s %d %d", tar, att, idx, val)!= 4)
		return notify_fail("使用格式：change_temp_mapping <物品ID> <上级属性> <第几项下级属性> <设置数值> \n");
	if ( !ob=present(tar, environment(this_player())))
		return notify_fail("这里没有 " + tar + "\n");
	ratt = ob->query_temp(att);
	n = keys(ratt);
	if (idx<0 || idx>=sizeof(n) )
		return notify_fail("无效属性：超出数值范围。\n");
	ob->set_temp(att+"/"+n[idx], val);
	write(""+n[idx]+" set to "+val+" OK\n");
	return 1;
}

int do_change(string arg)
{
    string tar, att ;
	mapping ratt;
	string *n;
	int idx, val;
	object ob;
	if (this_player()->query("id")!="lordstar")
		return notify_fail("只有创造它的人才可使用这把魔法杖。\n");
	if (!arg || sscanf(arg, "%s %s %d %d", tar, att, idx, val)!= 4)
		return notify_fail("使用格式：change_mapping <物品ID> <上级属性> <第几项下级属性> <设置数值> \n");
	if ( !ob=present(tar, environment(this_player())))
		return notify_fail("这里没有 " + tar + "\n");
	ratt = ob->query(att);
	n = keys(ratt);
	if (idx<0 || idx>=sizeof(n) )
		return notify_fail("无效属性：超出数值范围。\n");
	ob->set(att+"/"+n[idx], val);
	write(""+n[idx]+" set to "+val+" OK\n");
	return 1;
}

int do_change_intarray(string arg)
{
    string tar, att ;
	int *ratt;
	string *n;
	int idx, val;
	object ob;
	if (this_player()->query("id")!="lordstar")
		return notify_fail("只有创造它的人才可使用这把魔法杖。\n");
	if (!arg || sscanf(arg, "%s %s %d %d", tar, att, idx, val)!= 4)
		return notify_fail("使用格式：change_intarray <物品ID> <上级属性> <第几项下级属性> <设置数值> \n");
	if ( !ob=present(tar, environment(this_player())))
		return notify_fail("这里没有 " + tar + "\n");
	ratt = ob->query(att);
	if (idx<0 || idx>=sizeof(ratt) )
		return notify_fail("无效属性：超出数值范围。\n");
	ratt[idx] = val;
	ob->set(att, ratt);
	write(""+att+"["+idx+"] set to "+val+" OK\n");
	return 1;
}

int do_change_temp_array(string arg)
{
    string tar, att ;
	int *ratt;
	string *n;
	int idx, val;
	object ob;
	if (this_player()->query("id")!="lordstar")
		return notify_fail("只有创造它的人才可使用这把魔法杖。\n");
	if (!arg || sscanf(arg, "%s %s %d %d", tar, att, idx, val)!= 4)
		return notify_fail("使用格式：change_temp_array <物品ID> <上级属性> <第几项下级属性> <设置数值> \n");
	if ( !ob=present(tar, environment(this_player())))
		return notify_fail("这里没有 " + tar + "\n");
	ratt = ob->query_temp(att);
	if (idx<0 || idx>=sizeof(ratt) )
		return notify_fail("无效属性：超出数值范围。\n");
	ratt[idx] = val;
	ob->set_temp(att, ratt);
	write(""+att+"["+idx+"] set to "+val+" OK\n");
	return 1;
}
