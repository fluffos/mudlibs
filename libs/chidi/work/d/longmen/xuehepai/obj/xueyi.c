// xueyi.c 血翼
// 宝宝制作，笨小孩修改

#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
inherit F_UNIQUE;

mapping default_dirs = ([
	"north":	"北边",
	"south":	"南边",
	"east":		"东边",
	"west":		"西边",
	"northup":	"北边",
	"southup":	"南边",
	"eastup":	"东边",
	"westup":	"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":		"上面",
	"down":		"下面",
	"enter":	"里面",
	"out":		"外面",
]);

void create()
{
        set_name(HIR"血翼"NOR, ({ "xueyi","yi" }) );
        set("long",@LONG
血红色一层薄薄的不知道什么材料制成的翼翅，装在双臂上可以
借助风力可以滑翔，这就是萧萧天赖以成名的宝物，后为大风所
得。实是血河镇帮之宝之一。
LONG );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value", 100000);
		set("armor_prop/dodge", 100);
		set("wear_msg","$N拿出"HIR"血翼"NOR"展开，仔细的绑在臂、腰之间，双臂一振，似能飞翔。\n");
	}
	setup();
}

void init()
{
	add_action( "do_fly", "fly" );
}

int do_fly(string arg)
{
	string dest, mout, min, dir;
	object env, obj, me;
	int result, i;
	mapping exit;
	object *f_obs, *ob;

	me = this_player();
	env = environment(me);

	if ( !arg ) return notify_fail("你要往哪个方向飞？\n");

	if ( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if ( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");

	if (!me->is_fighting())
		return notify_fail("血翼最好在战斗中使用，平常飞来飞去不怕太招摇了吗？\n");

	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) )
			return notify_fail("这个方向没有出路。\n");

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
		call_other(dest, "???");
	if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	mout = HIC"\n$N突然跃起，双臂一展，鼓起"HIR"血翼"HIC"，已向"NOR + dir + HIC"滑了出去。\n\n"NOR;
	min = "半空中一个人影振着"HIC"血翼"NOR"飞了过来，渐渐落在了地上。\n";

	message_vision( mout, me );
	me->move(obj);
	message( "vision", min, environment(me), ({me}) );

	return 1;
}
