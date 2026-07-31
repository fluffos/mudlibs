// Room: /u/xdd/gumu/xuanya
// Modify by river 98/08/29
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
	set("short", HIM"悬崖"NOR);
	set("long", @LONG
此处已是绝路，光秃秃的石壁，下面则是云雾弥漫的万丈深崖(xuanya)，
传闻中有个古墓弟子因受不了古墓之清苦寡欲，从此处一跃而下，了却一生，
近悬崖边有棵摩天大树(tree)，枝叶极盛，如大伞一张遮掩住方圆之地。
LONG        );

	set("outdoors","古墓");
 
	set("exits", ([
		"north" : __DIR__"rukou",
	]));    

	set("item_desc", ([
		"xuanya" :HIM"悬崖下只是一片云雾缭绕。跳(tiao)下去恐是有去无回。\n"NOR,
		"tree" : "一棵高大的巨树,上面留下曾经被人摇晃的痕迹。\n", 
	]));

	setup();
}

void init()
{
	add_action("do_tiao", "tiao"); 
	add_action("do_yao", "yao");
}

int do_tiao(string arg)
{ 
	object me,tmp,*ob;
	int i;
	me = this_player();
	if ( arg == "xuanya") {
		if (me->query_temp("mark/jump") < 2) {
			write("人生苦短,且古墓神功绝世,你再考虑一下吧. \n");
			me->add_temp("mark/jump", 1);
			return 1;
		}
		message_vision(HIR"$N纵身跳下悬崖,悲呼一声,兄弟姐妹们,来生再见,回声不绝于耳。\n"NOR, me);       
		me->delete_temp("mark/jump");
		me->set_temp("last_damage_from", "跳崖自杀而");      
		me->die();
		if (tmp = present("corpse", this_object())){
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
			if(me) tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
		}
		return 1;        
	}
	return notify_fail("你要跳到哪里？\n");    
}

int do_yao(string arg)
{
	mapping fam;
	object me = this_player();

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");          

	if (me->query("jing") < 40)
		return notify_fail("你精力不能集中,去稍作歇息吧. \n");

	if (arg == "tree") {           
		if (me->query_skill("parry", 1) < 51)
			return notify_fail("你使出浑身的劲力，但是大树却纹丝不动。\n");
		if (me->query_skill("parry", 1) > 100)
			return notify_fail("你使劲地摇晃大树，发现大树快被你摇断了。\n");          
		write("你使劲地摇晃着大树，震的大树微微晃动。\n");
		me->receive_damage("jing", 15 + random(20));
		me->improve_skill("parry", (int)(me->query_int()/3)+(int)(me->query_skill("parry")/4));
		return 1;
	}
	return notify_fail("你要摇什么？\n");
}
