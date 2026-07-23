// Room: /city/wudao.c
// Date: Feb.28 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_gaoshi();
string look_pai();
string clear_title(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "武道场");
	set("long", @LONG
这里是比武大会巫师席，高据擂台之上，雕梁琉瓦，花木游栏。四望青山
迎爽，向下看擂台周围人头攒动。桌上放着一块小木牌 (pai)，后壁上贴着一
张红纸告示(gaoshi)。
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
		"pai"    : (: look_pai :),
	]));
	set("exits", ([
		"down"      : __DIR__"leitai",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	setup();
//	replace_program(ROOM);
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
string look_gaoshi()
{
	return 
HIR"\n\n                           
                 海洋II的比武大会
\n"HIY"
第一、每月的十五日晚上十九时三十分举行比武大会。地点在扬州西门
      外武道场。
第二、比赛按年龄分组，每组设天下第一，第二称号。分组如下：
      幼儿组 十四到十五岁 少年组 十六到二十岁 青年组 廿一到三十岁
      壮年组 卅一到四十岁 盛年组 四十以上
      如果在一组内只有两人，他就直接获得该组第一、二名。
第三、比武实行淘汰制。预先分组淘汰。每轮实行三局两胜制，分别比
      赛第一兵器，拳脚和第二兵器，先胜两局者进入下一轮。幼儿组
      和少年组除了决赛外每轮只赛一场。
第四、为使天下第一名实相符，允许使用现行所有武功，允许perform，
      powerup，enforce，poison等。但roar由于严重影响比武秩序，
      因此谢绝使用。违者停赛。
第五、比赛时所用兵器和防具请在擂台上的兵器架上自行拿取，经研究，
      禁止使用自造兵器。禁止使用金丝甲、软猥甲、真丝宝甲外，禁
      止使用伤害力超过50的兵器如敖拜匕首，倚天剑，伏魔刀等。
第六、比赛时请注意言行，犯众怒者、违反现场巫师安排者，取消一年
      比赛资格。

"HIG"                                      海洋II  敬启
\n"NOR;
}
void init()
{
	add_action("do_start", "start");
	add_action("do_allow", "allow");
	add_action("do_deny", "deny");
	add_action("do_load", "load");
	add_action("do_kick", "kick");
	add_action("do_heal", "heal");
	add_action("do_life", "life");
	add_action("do_titles", "titles");
}

int do_start()
{
        int i,j;
	object *allob, ob, me;

        allob = users();
        me = this_object();
        ob = this_player();
        if (!me) return 1;
        if (!ob) return 1;
if (!wizardp(ob))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

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

	me = this_player();
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

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

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: loadup <player id>\n");
if (!wizardp(me))
		return notify_fail("只有 (wizard) 以上的巫师才能使用此命令" + MUD_NAME + "\n");

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
