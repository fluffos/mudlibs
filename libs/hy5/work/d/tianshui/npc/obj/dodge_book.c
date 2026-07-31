// dodge_book.c

inherit ITEM;

void create()
{
	set_name("《轻功入门》", ({ "dodge book","book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long",
                        "这本旧书的纸张都已经泛黄了，上面只有一些字迹模糊的字句，似乎\n"
                        "提到一些呼吸方法什麽的。\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"dodge",
			"exp_required":	0,
			"sen_cost":	20,
			"difficulty":	20,
			"max_skill":	42,
		]) );
	}
}