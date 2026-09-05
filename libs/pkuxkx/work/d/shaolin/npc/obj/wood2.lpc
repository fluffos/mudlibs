// wood2.c
// 木柴的原始版本，真正产生的时候会修改名称和id，并且会标记当前用户id，
// 木柴是和玩家身份绑定的，僧人不接受非本人劈出来的木柴。
//seagate@pkuxkx 2010/10/09

inherit ITEM;

void create()
{
	set_name("一寸宽的木柴", ({"yicun mucai","wood"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根加工处理好的笔直细长的木柴。\n");
		set("value", 0);
		set("material", "wood");
	}
	setup();
}