// 解毒..
inherit F_MEDICINE;

void create()
{
	set_name("去春丸",({"cure flower pill","pill"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
  	        set("unit", "盒");
                set("base_unit", "粒");
                set("base_weight", 100);
		set("value", 500);
		set("cure_type","poison");
		set("cure_poison_type","flower_poison");
		set("medicine_power",1);
	}
	set_amount(1);
	setup();
}
