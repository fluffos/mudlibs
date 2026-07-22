// npc_leitai.c
// modified by augx@sj  10/29/2001

#include <ansi.h>
inherit NPC;

int desc(string arg)
{
	if (arg && present(arg, environment()) == this_object()) {
		write("
这是一个专门用来放各种物品的架子。
你可拿自己喜欢的物品 ( na <物品名称> )。
里面有：
    刀(dao, blade)，       鞭(bian, whip)，
    剑(jian, sword)，      棍(gun, club)，
    针(zhen, needle)，     杖(zhang, staff)，
    令(ling, dagger)，     棒(bang, stick)，
    铁甲(jia, armor)，     锤(chui, hammer)，
    钩(gou, hook)，        斧(fu)，
    轮(lun)，              石子(shi)，
    笔(bi,brush)，         萧(xiao)。
    火折(fire)，           毒粉(fen)。
"
		);
		return 1;
	}
	return 0;
}

void create()
{
	set_name("兵器架", ({ "bingqi jia" }) );
	set("gender", "男性" );
	set_temp("apply/long", 1);
	set("age", 20);
	set("str", 30);
	set("dex", 25);
	set("con", 25);
	set("int", 30);
	set("max_qi", 0);
	set_temp("leitai", 1);
	set("attitude", "friendly");
	set_temp("apply/id", ({ "jia" }));
	set_temp("apply/short", ({HIW"兵器架"NOR"(Jia)"}));
	setup();
}

object room1, room2, room3, room4;
string prefix, str;

int move(mixed dest, int silently)
{
	if (::move(dest, silently)) {
		str = environment()->query("dest_room");
		prefix = WHT "【"+environment()->query("short")+WHT "】";
		return 1;
	}
	return 0;
}

void init()
{
	add_action("desc", "look");
	if(this_player()->query_temp("leitai"))
		add_action("do_get",({"拿","na"}));
}

string buf = "", color = NOR;

void relay_message(string msgclass, string msg)
{
	string *ary;
	string tmp, tmp1, tmp2;

	if (msgclass[0..5] == "wizard") return;
	buf += msg;
	buf = replace_string(buf, "\r\n", "\n");
	ary = explode("\n"+buf, "\n");
	if (sizeof(ary) && buf[<1..<1] != "\n") {
		buf = ary[<1];
		ary = ary[0..<2];
	} else buf = "";

	if (!room1) room1 = load_object(str+"a");
	if (!room2) room2 = load_object(str+"b");
	if (!room3) room3 = load_object(str+"c");
	if (!room4) room4 = load_object(str+"d");
	if (sizeof(ary)) foreach (tmp in ary) {
		message("vision", prefix+color+tmp+NOR"\n", room1);
		message("vision", prefix+color+tmp+NOR"\n", room2);
		message("vision", prefix+color+tmp+NOR"\n", room3);
		message("vision", prefix+color+tmp+NOR"\n", room4);
		while (sscanf(tmp, "%s"CSI"%sm%s", tmp1, color, tmp2) == 3)
			tmp = tmp1 + tmp2;
		if (color[0] != 27) color = CSI+color+"m";
	}
}

int do_get(string arg)
{
	object me,ob;

	me=this_player();
	if( !arg )return notify_fail("命令格式: 拿(na) <物品名称> 。\n");

	switch (arg){
		case "sword":
		case "jian": 	ob=new(BINGQI_D("changjian")); break;
		case "blade":
		case "dao": 	ob=new(BINGQI_D("blade")); break;
		case "whip":
		case "bian":	ob=new(BINGQI_D("whip")); break;
		case "dagger":
		case "ling":	ob=new(BINGQI_D("dagger")); break;
		case "zhang":
		case "staff":   ob=new(BINGQI_D("gangzhang")); break;
		case "zhen":
		case "needle":	ob=new(BINGQI_D("xiuhua")); break;
		case "gun":
		case "club":	ob=new(BINGQI_D("tiegun")); break;
		case "xiao":    ob=new(BINGQI_D("yuxiao")); break;
		case "hammer":
		case "chui":	ob=new(BINGQI_D("falun1")); break;
		case "bang":
		case "stick":	ob=new(BINGQI_D("zhubang")); break;
		case "gou":
		case "hook":    ob=new(BINGQI_D("hook")); break;
		case "armor":
		case "jia":     ob=new(ARMOR_D("armor")); break;
		case "fu" :	ob=new(BINGQI_D("dafu"));break;
		case "lun":	ob=new(BINGQI_D("falun1"));break;
		case "shi":	ob=new(BINGQI_D("feihuangshi"));break;
		case "bi":
		case "brush":	ob=new(BINGQI_D("tiebi"));break;
		case "fire":
		case "huo":     ob=new(MISC_D("fire")); break;
		case "fen":     ob=new("/d/xingxiu/obj/yao"); break;
		default :	return notify_fail("没有这种东西。\n");
	}

	if(!ob) return 0;
	ob->delete("value");
	if(ob->query("weapon_prop/damage"))
		ob->set("weapon_prop/damage", 80);
	ob->move(me);
	message_vision("$N从物品架上拿出一"+ob->query("unit")+"$n。\n",me, ob);
	return 1;
}
