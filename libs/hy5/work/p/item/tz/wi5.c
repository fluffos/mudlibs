// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"慈云腰带"NOR, ({ "waist5"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
		
		set("value", 1900);
		set("material", "leather");
		set("armor_prop/armor", 159);
set("armor_prop/constitution",13);
set("armor_prop/dodge", 4);
	}
	setup();
}
