inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("苏合香酒", ({ "xiangjiu","jiu" }) );
        set("long", "一种名贵的药酒,经三年才能制成.\n");
        set("unit", "瓶");
        set("weight", 700);
        set("value", 10000);
	  set("max_liquid", 15);

}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object ob;
	if( !living(this_player()))	return 0;
        if( !id(arg) ) return notify_fail("你要喝什麽？\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        ob->set("jing",(int)ob->query("eff_jing"));
        ob->set("eff_jing",(int)ob->query("eff_jing"));
        write("你喝了几口苏合香酒.\n");
	set("liquid", ([
		"type": "alcohol",
		"name": "苏合香酒",
		"remaining": 15,
		"drunk_apply": 4,
	]));

        return 1;
}
