// clone/work/besom.c     扫把

inherit COMBINED_ITEM;

void create()
{
        set_name("扫把", ({ "besom" }));
        
       	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "把");
                set("base_value", 50);
                set("base_wieght", 80);
        }
        setup();
	set_amount(1);

}

void init()
{
        add_action("do_sweep", "sweep");
}

int do_sweep()
{
	object ob;
	
	ob = this_player();
	
        WORK_D->start_work(ob, "kezhan");
        return 1;  
}
