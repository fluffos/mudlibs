#include <mudlib.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(6);
	set_name( "Cicada", "蝉" );
	add( "id", ({ "cicada"}) );
	set_short( "蝉" );
	set_long(@C_LONG
你眼前所见的是只体型巨大无比，全身泛出紫蓝色的蝎子。它的头好像是一个人的
脸，但额前却多凸出两只茶杯大小的怪眼，睁合之间凶芒四射，忽红忽蓝，奇光闪
烁不定。
C_LONG
        );
        set("race","insect");
        set_skill("dodge",20);
        set_natural_armor(30,1);
        set_natural_weapon( 9,5,9 );
        set_c_verbs( ({ "%s用它的翅膀拍打%s", }) );
        set_c_limbs( ({ "门面", "头部", "触角", "翅膀", "身体", }) );
}
