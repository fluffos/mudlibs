//shaohuogun.c 烧火棍

#include <weapon.h>
inherit CLUB;

void create()
{        
	set_name("烧火棍", ({ "shaohuo gun", "gun" }));        	
	set_weight(3000);        
	if (clonep()) set_default_object(__FILE__);        
	else 
	{                
		set("unit","根");                
		set("long","一根黑乎乎的烧火棍，上面满是烟油，摸起来滑腻腻的，却是尺寸刚好，颇为就手。\n");                
		set("value", 200);                
		set("material", "bamboo");                
		set("wield_msg", "$N抽出一根黑乎乎的$n握在手中。\n");               
		set("unwield_msg", "$N将手中的$n插回腰间。\n");		
		set("value",10);      
	}        
	init_club(50);        
	setup();
}
