// xiang.c
inherit ITEM;

void init();
int do_dian(string arg);
void create()
{
        set_name("高香", ({ "xiang" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柱");
                set("long", "这是一柱敬佛用的高香,你可以点燃它(dian)。\n");
                set("value", 100);
                set("material", "wood");
        }
	set("fire",0);
        setup();
}

void init()
{
        add_action("do_dian", "dian");
}

int do_dian(string arg)
{
	object me;
	me = this_player();
	if(!arg||arg!="xiang")
                return notify_fail("你要点燃什么东西？\n");
	if(query("fire"))
		return notify_fail("你手中的高香已经点燃了。\n");
	message_vision("$N点燃了手中的高香。\n",me);
	set("fire",1);
	call_out("fire",60);
	return 1;
}

void fire()
{
        message_vision("$N烧完了。\n",this_object());
        destruct(this_object());
}