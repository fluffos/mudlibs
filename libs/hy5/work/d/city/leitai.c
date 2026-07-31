// Room: /city/leitai.c
// Date: Feb.27 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_shelf();
string do_quit(string arg);
string look_gaoshi();
string look_pai();
string clear_title(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "擂台");
	set("long", @LONG
这是一个四丈见方的擂台。粗壮结实的木柱撑起一片平台，四角的支柱上
高挂着四副对联，四面的观众都能清楚地看到台上的手起脚落。擂台角上有个
兵器架(shelf) ，刀剑鞭棒样样俱全。主持人请看公吿版(pai)
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"shelf" : (: look_shelf :),
"pai"    : (: look_pai :),
	]));

	set("exits", ([
		"up"        : __DIR__"wudao",
		"eastdown"  : __DIR__"wudao1",
		"westdown"  : __DIR__"wudao2",
		"southdown" : __DIR__"wudao3",
		"northdown" : __DIR__"wudao4",
	]));
	set("objects", ([
                __DIR__"npc/referee": 1,
//                "/u/zmud/gongping": 1,
	]));
        set("no_npc",1);
	set("no_clean_up", 0);
	set("no_openshelf", 1);
	setup();
}
string look_pai()
{
	return 
"\n
"HIR"start                  "HIY"----  擂台上之玩家开始比武。
"HIR"allow    <player id>   "HIY"----  设定允许上擂台之玩家。
"HIR"deny     <player id>   "HIY"----  取消玩家上台资格。
"HIR"load     <player id>   "HIY"----  拉玩家上擂台。
"HIR"kick     <player id>   "HIY"----  踢玩家下擂台。
"HIR"heal     <player id>   "HIY"----  给擂台上玩家九花玉露丸。
"HIR"life     <player id>   "HIY"----  送被杀玩家上天堂恢复。

"HIG"titles  <player id> 01 "HIY"----  赠玩家幼年天下第一 (15以下)。
"HIG"titles  <player id> 02 "HIY"----  赠玩家幼年天下第二 (15以下)。
"HIG"titles  <player id> 11 "HIY"----  赠玩家少年天下第一 (20以下)。
"HIG"titles  <player id> 12 "HIY"----  赠玩家少年天下第二 (20以下)。
"HIG"titles  <player id> 21 "HIY"----  赠玩家天下第一侠少 (30以下)。
"HIG"titles  <player id> 22 "HIY"----  赠玩家天下第二侠少 (30以下)。
"HIG"titles  <player id> 31 "HIY"----  赠玩家天下第一侠客 (40以下)。
"HIG"titles  <player id> 32 "HIY"----  赠玩家天下第二侠客 (40以下)。
"HIG"titles  <player id> 41 "HIY"----  赠玩家天下第一大侠 (40以上)。
"HIG"titles  <player id> 42 "HIY"----  赠玩家天下第二大侠 (40以上)。

\n"NOR;
}
string look_shelf()
{
	return 
"\n
一个很有年头的兵器架，红漆都剥落得差不多了。
架上摆满了: 
                 钢刀(blade)    长剑(sword)
                 钢杖(staff)    长鞭(whip)
                 铁锤(hammer)   长棍(club)
                 暗器(throwing) 短兵(dagger)
                 钢甲(armor)

参加比武者可以按需要，随便拿取(take)使用。

                                侠客行擂台  敬启
\n";
}

void init()
{
//	add_action("do_yun","yun");
//	add_action("do_yun","exert");
//	add_action("do_quit","hit");
//	add_action("do_quit","fight");
//	add_action("do_quit","qiecuo");
//	add_action("do_quit","kill");
//	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","dazuo");
	add_action("do_quit","exercise");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_take","take");
	add_action("do_open","open");
	add_action("do_close","close");

	add_action("do_start", "start");
	add_action("do_allow", "allow");
	add_action("do_deny", "deny");
	add_action("do_load", "load");
	add_action("do_kick", "kick");
	add_action("do_heal", "heal");
	add_action("do_life", "life");
	add_action("do_titles", "titles");
	
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) && !userp(me))
                return notify_fail("裁判席只有被特邀才能进去。\n");
	me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}
int do_yun(string arg)
{
	if (arg=="roar")
	{
        write(this_player()->query("name")+"，专心比武吧！\n");
	return 0;
	}
	return 1;
}

int do_open()
{
	if(wizardp(this_player()))
	{
		message_vision("$N把兵器架启封了。\n", this_player());
		this_object()->delete("no_openshelf");
		return 1;
	}
	else return 0;
}
int do_close()
{
	if(wizardp(this_player()))
	{
		message_vision("$N拿了条封条把兵器架给封了。\n", this_player());
		this_object()->set("no_openshelf", 1);
		return 1;
	}
	else return 0;
}
int do_take(string arg)
{
	object obj,ob;
	ob = this_player();
	if(this_object()->query("no_openshelf"))
	{
		message_vision("非大比武的时候，兵器架给封住了。\n", ob);
		return 1;
	}
	if( !arg || arg=="" )
	{
		message_vision("$N站在兵器架前，还没想好要什么兵器。\n", ob);
		return 1;
	}
	switch (arg)
	{
		case "sword":
			obj = new("/clone/weapon/changjian");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一口长剑。\n",ob);
			break;
		case "blade":
			obj = new("/clone/weapon/gangdao");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一口钢刀。\n",ob);
			break;
		case "staff":
			obj = new("/clone/weapon/gangzhang");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一杆钢杖。\n",ob);
			break;
		case "whip":
			obj = new("/clone/weapon/changbian");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一条长鞭。\n",ob);
			break;
		case "club":
			obj = new("/clone/weapon/qimeigun");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一条齐眉棍。\n",ob);
			break;
		case "hammer":
			obj = new("/clone/weapon/hammer");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一把铁锤。\n",ob);
			break;
		case "throwing":
			obj = new("/clone/weapon/lianzi");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一包铁莲子。\n",ob);
			break;
		case "dagger":
			obj = new("/clone/weapon/dagger");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一把匕首。\n",ob);
			break;
		case "armor":
			obj = new("/clone/weapon/tiejia");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一副铁甲。\n",ob);
			break;
		default:
			message_vision("$N站在兵器架前，还没想好要什么兵器。\n", ob);
	}
	return 1;
}

int do_start()
{
        int i,j;
	object *allob, ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

        allob = users();
        me = this_object();
        ob = this_player();
        if (!me) return 1;
        if (!ob) return 1;
        j = 0;
        for ( i=sizeof(allob); i>0; i-- ) {
//             if (environment(allob[i-1])->query("short") =="擂台") {
                if (j == 0) {
                    me = allob[i-1];
                    j = 1;
                }
                else ob = allob[i-1]; 
             }
//        }
        if (ob != this_player()) me->fight_ob(ob);
        return 1;
}
int do_allow(string arg)
{
	object ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: allow <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N设定让"+ob->name()+"上擂台。\n"NOR, me);
	ob -> set_temp("leitai_allow",1);
	ob -> delete("env/combatd");
	tell_object(ob,HIR"\n该你上擂台了。\n"NOR);
	return 1;
}
int do_deny(string arg)
{
	object ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: deny <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N设定让"+ob->name()+"先暂时别上擂台。\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n先不急上擂台了吧。\n"NOR);
	return 1;
}
int do_load(string arg)
{
	object ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");
	if (!arg) return notify_fail("<Syntax>: loadup <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N拉"+ob->name()+"上擂台。\n"NOR, me);
	message_vision(HIG"$N双腿一蹬，腾空而起，轻轻落在擂台边上，衣袂襟风，十分潇洒。\n"NOR, ob);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n发什么呆呀你，先上来吧给我。\n"NOR);
	ob -> move("/d/city/leitai");
	ob -> delete_temp("view_leitai");
	ob -> delete("env/combatd");
	message_vision(HIG"$N腾空落在擂台边上，衣袂襟风，十分潇洒。\n"NOR, ob);
	return 1;
}
int do_kick(string arg)
{
	object ob, me;

	string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");
	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if (!arg) return notify_fail("<Syntax>: kickdown <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N把"+ob->name()+"踢下擂台。\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	message_vision(HIG"只听得$N嗷的一声，飞身跳下擂台去了。\n"NOR, ob);
	tell_object(ob,HIR"\n没玩够啊，先下去吧你给我。\n"NOR);
	ob -> move("/d/city/wudao1");
	ob -> set_temp("view_leitai",1);
	message_vision(HIG"只见$N长呼声中，一个大屁股墩坐在地上唉唉不绝。\n"NOR, ob);
	return 1;
}
int do_heal(string arg)
{
	object ob, me, obj;
	string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if (!arg) return notify_fail("<Syntax>: heal <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N给"+ob->name()+"一粒九花玉露丸。\n"NOR, me);
	obj = new("/clone/misc/jiuhua");
	obj -> move(ob); 
	tell_object(ob,HIR"\n给你一粒九花玉露丸恢复体力。\n"NOR);
	return 1;
}
int do_life(string arg)
{
	object ob, me;

	string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if (!arg) return notify_fail("<Syntax>: reback <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("没这个人耶。\n");
	message_vision(HIG"$N送"+ob->name()+"上天堂恢复损失。\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n送你上天堂，下来后就会恢复的。\n"NOR);
	ob -> move("/d/death/god2");
	ob -> delete_temp("view_leitai");
	return 1;
}
int do_titles(string arg)
{
	object obj, me=this_player();
	string dest, topic;
	string wiz_status;
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

	if( !arg || sscanf(arg, "%s %s", dest, topic)!=2 )
		return notify_fail("你要封谁什么称号？\n");
	obj = find_player(dest);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
	switch (topic)
	{
		case "01": add_title(obj, "幼年天下第一"); break;
		case "02": add_title(obj, "幼年天下第二"); break;
		case "11": add_title(obj, "少年天下第一"); break;
		case "12": add_title(obj, "少年天下第二"); break;
		case "21": add_title(obj, "天下第一侠少"); break;
		case "22": add_title(obj, "天下第二侠少"); break;
		case "31": add_title(obj, "天下第一侠客"); break;
		case "32": add_title(obj, "天下第二侠客"); break;
		case "41": add_title(obj, "天下第一大侠"); break;
		case "42": add_title(obj, "天下第二大侠"); break;
		default: break;
	}
	message_vision(HIG"$N授"+obj->name()+"封号。\n"NOR, me);
	return 1;
}
void add_title(object me,string arg)
{
        string title;
        title=arg+clear_title(me->query("title"));
        me->set("title",title);
}
string clear_title(string arg)
{
        if( (strsrch(arg, "幼年天下第一") >= 0) ||
            (strsrch(arg, "幼年天下第二") >= 0) ||
            (strsrch(arg, "少年天下第一") >= 0) ||
            (strsrch(arg, "少年天下第二") >= 0) ||
            (strsrch(arg, "天下第一侠少") >= 0) ||
            (strsrch(arg, "天下第二侠少") >= 0) ||
            (strsrch(arg, "天下第一侠客") >= 0) ||
            (strsrch(arg, "天下第二侠客") >= 0) ||
            (strsrch(arg, "天下第一大侠") >= 0) ||
            (strsrch(arg, "天下第二大侠") >= 0))
                {
                arg = replace_string(arg, "幼年天下第一","");
                arg = replace_string(arg, "幼年天下第二","");
                arg = replace_string(arg, "少年天下第一","");
                arg = replace_string(arg, "少年天下第二","");
                arg = replace_string(arg, "天下第一侠少","");
                arg = replace_string(arg, "天下第二侠少","");
                arg = replace_string(arg, "天下第一侠客","");
                arg = replace_string(arg, "天下第二侠客","");
                arg = replace_string(arg, "天下第一大侠","");
                arg = replace_string(arg, "天下第二大侠","");
        }
        return arg;
}
