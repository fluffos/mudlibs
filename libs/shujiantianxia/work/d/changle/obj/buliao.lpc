// buliao.c
// By River@SJ 2003.2.26 For Changle_Job

#include <ansi.h>
#include <get_place.h>

inherit ITEM;
int check(object ob);
object ppl;

void create()
{
	set_name("粗布碎片", ({ "cu bu", "bu", "cloth" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("material", "cloth");
		set("long", "一块粗布的碎片，看来是从他人身上撕下来的，也许可以查看(chakan)一下。\n");
		set("no_give", 1);
		set("no_drop", 1);
	}
	setup();
}

void init()
{
	if (environment() == this_player()){
		add_action("do_jianding", "chakan");
		add_action("do_xunwen", "xunwen");
	}
}

int do_jianding(string arg)
{
	object obj, me = this_player();
	object ob, weapon, where, target, *list;
	string str, fam, msg;
	int i =0 ;

	if ( query_temp("target") != getuid(me)) return 0;

	if ( me->query_temp("changle/done"))
		return notify_fail("你难道还没查看够？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( !id(arg) && !me->query_temp("changle/check_bu"))
		return notify_fail("你要查看什么？\n");

	if ( id(arg)) {
		message_vision("$N仔细的查看了粗布，发现看不出什么异常。\n", me);
		tell_object(me, "你心道：还是查看下尸体，也许能发现些什么。\n");
		me->set_temp("changle/check_bu", 1);
		return 1;
	}

	if ( ! arg || arg != "corpse")
		return notify_fail("你要查看什么？\n");

	if ( ! objectp(obj = present("corpse", environment(me))))
		return notify_fail("你附近有尸体可以查看么？\n");

	if ( obj != query_temp("unconcious"))
		return notify_fail("你查看"+obj->name()+"有用么？\n");

	ob = new("/d/changle/npc/npc_copy");
	weapon = ob->query_temp("weapon");
	if (weapon){
		switch (weapon->query("skill_type")){
			case "sword":		msg = "长剑刺伤";		break;
			case "blade":		msg = "钢刀劈伤";		break;
			case "hook":		msg = "单钩钩伤";		break;
			case "dagger":		msg = "匕首割伤";		break;
			case "whip":		msg = "长鞭卷伤";		break;
			case "brush":		msg = "铁笔刮伤";		break;
			case "staff":		msg = "钢杖击伤";		break;
			case "club":		msg = "铁棍敲伤";		break;
			case "axe":		msg = "钢斧砍伤";		break;
			case "hammer":		msg = "法轮砸伤";		break;
			case "stick":		msg = "竹棒戳伤";		break;
			case "throwing":	msg = "暗器所伤";		break;
		}
		i = 1;
	}
	else
		msg = "空手内功震伤";

	fam = ob->query("family_type");

	me->set_temp("changle/target_family", fam);
	me->set_temp("changle/target_team", ob->query("team"));
	me->set_temp("changle/target_weapon", i);
	me->set_temp("changle/done", 1);
// dest
	remove_call_out("dest_object");
	call_out("dest_object", 1, ob);

	message_vision(HIY"\n$N仔细地查看"+obj->name()+"，发现似乎是被"+msg+"，从伤口看来，应该是"+fam+"所为。\n"NOR, me);

	ppl = me;
	list = filter_array(
		users(), (:
			$1->query("combat_exp") > 3000
			&& !wizardp($1)
			&& environment($1)
			&& $1->query("family")
			&& query_idle($1) < 120
			&& interactive($1)
			&& query_ip_number($1) != query_ip_number(ppl)
			&& $1->query("registered") > 1
			&& strsrch(file_name(environment($1)),"/d/sld/seawar") != 0
			&& strsrch(file_name(environment($1)),"/d/wizard") !=0						
			&& !$1->query_condition("relax")
			&& !$1->query_condition("killer")
			&& $1->query_temp("cl_job_time") < uptime()
			&& getuid($1)!=ROOT_UID
		:)
	);

	list -= ({me, 0});

	if(sizeof(list) < 1 )
		return notify_fail("看来只能查看到这步了，还是先回去交差吧。\n");

	target = list[random(sizeof(list))];

	if ( ! target )
		return notify_fail("看来只能查看到这步了，还是先回去交差吧。\n");

	target->set_temp("cl_job_time", uptime() + 2700);
	where = environment(target);
	if (strsrch(file_name(where), "/d/zhiye/") >= 0
	 || strsrch(file_name(where), "/d/group/") >= 0) {
	 	if ( where->query("outdoors"))
			str = where->query("outdoors") + where->query("short");
	 	else if ( where->query("indoors"))
			str = where->query("indoors") + where->query("short");
		else  str = where->query("short");
	}
	else str = get_place(base_name(where))+where->query("short");
	str = strip(str);

	me->set_temp("changle/user_name", getuid(target));
	target->query("gender")=="女性"?msg="她":msg="他";
	tell_object(target, YEL"你突然瞥见一条黑影与你擦肩而过，往另一方逃窜，心里不禁疑窦顿生。\n"NOR);
	tell_object(me, YEL"你暗下寻思询问"+target->query("family/family_name")+"的"+target->name(1)+"("+capitalize(getuid(target))+")或许能得到提示，传闻"+msg+"曾在"+str+"附近出现。\n"NOR);
	return 1;
}

void dest_object(object ob)
{
	if(ob) destruct(ob);
}

int do_xunwen(string arg)
{
	object me, obj, ob, *living, target;
	string str, address;
	object objwhere;
	int i,j;

	me = this_player();

	if ( ! me->query_temp("changle/user_name") || query_temp("target") != getuid(me)) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("changle/done") > 1 )
		return notify_fail("你不是已经询问过了？还不快去。\n");

	if ( ! arg || arg != me->query_temp("changle/user_name"))
		return notify_fail("你要询问谁？\n");

	if ( ! obj = present( arg, environment(me)))
		return notify_fail("你身旁有这个人么？\n");

	if ( !interactive(obj) || !living(obj))
		return notify_fail("看起来"+obj->name()+"暂时无法回答你的问题。\n");

	EMOTE_D->do_emote(me ,"hi", obj->query("id"));
	message_vision(CYN"$N对着$n作了个揖，拱手问道：「这位"+ RANK_D->query_respect(obj)+"可曾看见有"+me->query_temp("changle/target_family")+"的人杀害长乐帮帮众"+me->query_temp("changle/npc_name")+"。」\n"NOR, me, obj);
	me->start_busy(random(2));
	me->set_temp("changle/done", 2);

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			target = living[j];
			objwhere = environment(target);
			str = objwhere->query("short");
			if (!sizeof(objwhere->query("exits"))
			|| str == "武僧堂"
			|| str == "僧舍"
			|| str == HIR"心禅堂"NOR
			|| str == "金刚伏魔圈" ) continue;
			if( get_place(base_name(environment(target))) == get_place(base_name(environment(me)))) continue;
			if( get_place(base_name(environment(target))) != "" ) break;
		}
	}

	if( ! target ) {
		EMOTE_D->do_emote(obj, "sign");
		tell_object( me, GRN+obj->name()+"在你的耳边悄声说道：刚才是有人从我身边经过，可惜我没看清楚他往哪个方向离开了。\n"NOR);
		tell_object( obj, GRN"你在"+me->name()+"的耳边悄声说道：刚才是有人从我身边经过，可惜我没看清楚他往哪个方向离开了。\n"NOR);
		tell_room( environment(me), obj->name() + "在" + me->name() + "耳边小声地说了些话。\n", ({ obj, me }) ); 
		return 1;
	}

	ob = new("/d/changle/npc/pantu");
	ob->set_temp("target_pantu", getuid(me));
	ob->do_copy(me, me->query_temp("changle/target_team"), me->query_temp("changle/target_weapon"));
	ob->set("env/invisibilty", 10);
	ob->move(objwhere);

	for ( j = 0; j < 5; j ++)
		ob->random_move();

	if ( environment(ob)->query("no_fight") ||  environment(ob)->query("quest") )
		ob->random_move();

	ob->delete("env/invisibilty");

	if (strsrch(file_name(environment(ob)), "/d/zhiye/") >= 0
	 || strsrch(file_name(environment(ob)), "/d/group/") >= 0) {
	 	if ( environment(ob)->query("outdoors"))
			me->set_temp("change/job_place1", environment(ob)->query("outdoors")+environment(ob)->query("short"));
	 	else if ( environment(ob)->query("indoors"))
			me->set_temp("change/job_place1", environment(ob)->query("indoors")+environment(ob)->query("short"));
		else me->set_temp("changle/job_place1", environment(ob)->query("short"));
	}
	else me->set_temp("changle/job_place1", get_place(base_name(environment(ob)))+environment(ob)->query("short"));

	if ( ! me->query_temp("changle/job_place1")) {
		EMOTE_D->do_emote(obj, "sign");
		tell_object( me, GRN+obj->name()+"在你的耳边悄声说道：刚才是有人从我身边经过，可惜我没看清楚他往哪个方向离开了。\n"NOR);
		tell_object( obj, GRN"你在"+me->name()+"的耳边悄声说道：刚才是有人从我身边经过，可惜我没看清楚他往哪个方向离开了。\n"NOR);
		tell_room( environment(me), obj->name() + "在" + me->name() + "耳边小声地说了些话。\n", ({ obj, me }) ); 
		return 1;
	}

	me->set_temp("changle/target", ob);
	address = strip(me->query_temp("changle/job_place1"));
	EMOTE_D->do_emote(obj ,"nod", me->query("id"));
	tell_object( me, GRN+obj->name()+"在你的耳边悄声说道：适才"+ob->query("title")+ob->name()+"从我身边经过，好像前往了"+address+"。\n"NOR);
	tell_object( obj, GRN"你在"+me->name()+"的耳边悄声说道：适才"+ob->query("title")+ob->name()+"从我身边经过，好像前往了"+address+"。\n"NOR);
	tell_room( environment(me), obj->name() + "在" + me->name() + "耳边小声地说了些话。\n", ({ obj, me }) );
	return 1;
}

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("outdoors") == "昆仑翠谷"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}
