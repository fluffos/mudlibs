inherit ITEM;

void create()
{      object ob;
        set_name("镖车", ({ "biaoche", "biao", "che"}) );
        set_weight(80000);
        set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "一辆用驴子拉的镖车,上面还插着一面镖旗。\n");
		   set("material", "wood");
        }
 setup();
	//ob=new("clone/misc/gold.c");
	//ob->move(this_object());
	//ob->set_amount(random(3));
}

int is_container() { return 1; }

