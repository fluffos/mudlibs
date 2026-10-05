#include <../under.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(19);
        set_name( "thunder horse", "爪黄飞电" );
        add( "id", ({ "horse" }) );
        set_short( "爪黄飞电" );
        set_long(
"这是赵子扬的爱马－爪黄飞电，它全身是雪白色的，只有四只脚踝杂著黄色的毛。\n"
"这爪黄飞电比起一般的牧马关战马似乎更是高大，坚实的腿肌让你想像得到它在战\n"
"场上对骑者有多大的帮助。这匹马是赵子扬亲手养大的，从它身上，你也可以看出\n"
"它的主人有多爱护它。\n"
);
        set( "unit", "匹" );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "con", 30 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 80,40 );
        set_skill("dodge",80);
        set( "alignment", 1000 );
        set( "extra_look","$N正骑在一匹爪黄飞电上，露出一付不可一世的表情。\n");
        set( "mountable", 1);
        set( "max_load", 2600 );
        set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
        set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起来，用前肢在%s一阵乱踩"}) );
        equip_armor( "/d/eastland/mumar/objs/saddle" );
}
void init()
{
        mount::init();
}
