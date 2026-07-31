// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: sky.h
// by FoF 99-12-3 19:52

#include <ansi.h>
#define SKYS_DIR "/d/skys/"

inherit ROOM;

int block_cmd(string args);
void set_random_below();
string *skys = ({"changan", "stone", "moon", "lingtai", "xueshan", "wuzhuang", "baoxiang", "yalong", "chechi", "jindou", "dudi", "jilei", "jingjiling", "zhuzi", "pansi", "qinghua", "qinfa", "yinwu", "baotou", "jinping", "tianzhu", "lingshan", "kaifeng", "sky", "penglai", "putuo", "meishan", "pingding", "wuji", "tongtian", "nuerguo", "firemount", "jisaiguo", "xiaoxitian", "qilin", "biqiu", "wudidong", "fengxian", "yuhua", "zhujie", "qinglong", "maoying"});

void init()
{
	object who = this_player();
	int delay = 10;
	int kee, sen, exp, mana, luck, encumbrance, weather, total;

	if( who->is_character() && !userp(who) && who->query("ride/msg") ) return;
	add_action("block_cmd", "", 1);

	// 道行和法力决定了飞行的时间
	exp = who->query("combat_exp");
	mana = who->query("mana");
	while( exp >= 10000 ) {
		exp /= 2;
		delay --;
	}
	while( mana >= 200 ) {
		mana /= 2;
		delay --;
	}
	delay += random(3);
	if( delay < 1 ) delay = 1;
	delay = 1;

	exp = who->query("combat_exp") / 10000;
	mana = who->query("mana") / 40;
	kee = who->query("kee") * 100 / who->query("max_kee");
	sen = who->query("sen") * 100 / who->query("max_sen");
	luck = who->query("luck");
//	weather = WEATHER_D->query_weather(query("outdoors"));
	encumbrance = (int)who->query_encumbrance() * 100 / (int)who->query_max_encumbrance();
//write(sprintf("kee%d sen%d exp%d mana%d luck%d encum%d delay%d\n", kee, sen, exp, mana, luck, encumbrance, delay));
//write(sprintf("tatal %d\n", kee + sen + mana + exp + luck + weather - encumbrance));
	total = kee + sen + mana + exp + luck + weather - encumbrance;
	switch(who->query_temp("fly/action"))
	{
		case "fly_up" : // 飞上天后面临三种情况：掉下去、飞到目的地上空、不知被吹到哪里去
			if( random(total) < 7 )
				call_out("letgo", delay, who, "fall");
			else if( random(total) < 20 )
				call_out("letgo", delay, who, "unlucky");
			else call_out("letgo", delay, who, "lucky");
		break;
		case "unlucky" : // 不幸的飞行
			if( random(total) < 8 )
				call_out("letgo", 1, who, "fall");
			else call_out("letgo", 1, who, "land");
		break;
		case "lucky" : // 成功的飞行
		default :
			if( random(total) < 5 )
				call_out("letgo", 1, who, "fall");
			else call_out("letgo", 1, who, "land");
		break;
	}
}

int block_cmd(string args)
{
	string verb;
	verb = query_verb();
    if (verb == "cast") return 1;
    if (verb == "drop") return 1;
    if (verb == "dismount") return 1;
    if (verb == "exercise") return 1;
    if (verb == "exert") return 1;
    if (verb == "fly") return 1;
    if (verb == "fight") return 1;
    if (verb == "find") return 1;
    if (verb == "ji") return 1;
    if (verb == "jjf_bing") return 1;
    if (verb == "kill") return 1;
    if (verb == "meditate") return 1;
    if (verb == "practice") return 1;
    if (verb == "perform") return 1;
//    if (verb == "quit") return 1;
    if (verb == "research") return 1;
    if (verb == "steal") return 1;
    if (verb == "study") return 1;
    if (verb == "teamkill") return 1;
    if (verb == "xiudao") return 1;
    return 0;
}

void letgo(object who, string mode)
{
	string random_sky;
	string ridemsg = "";
	object ridee;
	switch(mode)
	{
		case "lucky" : // 成功地飞到目的地上空
			who->set_temp("fly/action", "lucky");
			if( ridee = who->ride() ) {
				ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
				ridee->move(SKYS_DIR + who->query_temp("fly/arg"));
			}  
			tell_room(this_object(), who->name() + ridemsg + "飞了过去。\n", who);
			who->move(SKYS_DIR + who->query_temp("fly/arg"));
		break;
		case "unlucky" : // 被风吹到了意想不到的地方
			who->set_temp("fly/action", "unlucky");
			random_sky = SKYS_DIR + skys[random(sizeof(skys))];
			who->set_temp("fly/destination", load_object(random_sky)->query("below"));
			if( ridee = who->ride() ) {
				ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
				ridee->move(random_sky);
			}
			tell_room(this_object(), HIY"忽然刮起了一股劲风，" + who->name() + "被吹走了。\n"NOR, who);
			tell_object(who, HIY"忽然刮起了一股劲风，你把持不住平衡，被吹得东倒西歪。\n"NOR);
			who->move(random_sky);
			message_vision(HIY"$N" + ridemsg + "稀里糊涂地飞了过来。\n"NOR, who);
		break;
		case "fall" : // 摔下去 :-(
			set_random_below();
			message_vision(HIY"\n一阵狂风吹来，$N把持不住平衡，重重地摔了下去．．．\n"NOR, who);
			tell_object(who, HIY"\n．．．我．．．的．．．妈．．．呀．．．\n\n"NOR);
			if( ridee = who->ride() ) {
				ridee->move(query("below"));
			}
			who->move(query("below"));
			message_vision(HIY"$N像一颗大石头似地从天上掉了下来。\n"NOR, who);
			who->delete_temp("fly");
//                        who->unconcious();
		break;
		case "land" : // 安全降落
		default :
			if( ridee = who->ride() ) {
				ridemsg = ridee->query("ride/msg") + "着" + ridee->name();
				ridee->move(who->query_temp("fly/destination"));
			}
			if( who->query_temp("fly/action") == "lucky" )
				write(HIY"\n到了！你按下云头跳了下来。\n\n"NOR);
			who->move(who->query_temp("fly/destination"));
			if( (string)who->query("family/family_name") == "阎罗地府")
				message_vision(HIY"\n只见平地吹起一阵阴风，$N" + ridemsg + "从里面走了出来。\n"NOR, who);
			else if( (string)who->query("family/family_name") == "大雪山"
			|| (string)who->query("family/family_name") == "陷空山无底洞")
				message_vision(HIY"\n只见狂风大作，$N" + ridemsg + "从里面走了出来。\n"NOR, who);
			else
				message_vision(HIY"\n只见半空中降下一朵云彩，$N" + ridemsg + "从里面走了出来。\n" NOR, who);
			who->delete_temp("fly");
		break;
	}
	return;
}

void set_random_below()
{
	int i, j;
	mixed* file;
	string dir = query("map_dir");
	file = get_dir(dir + "*.lpc", -1);
	if( !sizeof(file) ) return;
	i = sizeof(file);
	while(1) { // pick up a file with size > 0 and has outdoors
		j = random(i);
		if( file[j][1] > 0 && (dir + file[j][0])->query("outdoors") )  break;
	}
	set("below", dir + file[j][0]);
	return;
}
