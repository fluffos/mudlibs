// shandong3.c
// Modified by Java Apr.27 1998
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","山洞");
        set("long",@LONG
这是一个小小的山洞，血刀老祖的藏身之地。由於此地比较隐秘，
仇家很难寻到这来。洞底有一张供桌，上面供了什麽东西，你看不清。
壁上画了一些模糊不清的文字图案，也不知道是些什么。
好像有一条通向不知道什么地方的密道(midao)
LONG );
        set("exits",([
                "out" : __DIR__"shandong2",
                "midao" :"/d/city/kedian",
        ]));
        
set("roomif","$botten#美女任务|取消抢劫|上交美女:ask laozu about job|ask laozu about 失败|give <物品> to laozu$#");
        
        set("objects", ([
                "quest/menpaijob/xuedao/xuedao" :1,
                __DIR__"npc/x_lama" :1,
                
        ]));
        setup();
        "/clone/board/xuedao_b"->foo();
}

void init()
{
        add_action("do_watch", "watch");
        add_action("do_watch", "kan");
        add_action("do_watch", "mianbi");
        add_action("do_watch", "face");
	add_action("do_baohu", "baohu");
	add_action("do_qiang", "qiang");
}

int do_watch()
{
        object ob = this_player();
        int lvl = this_player()->query_skill("xue-dao",1);

        if ((int)ob->query_skill("longxiang", 1) < 20)
        {
                message_vision("$N的龙象功不够，看不懂上面刻的是什么。\n",ob);
                return 1;
        }
        if ((int)ob->query_skill("xue-dao", 1) > 50)
        {
                message_vision("$N的血刀刀法早就超越壁上所刻了。\n",ob);
                return 1;
        }
        if((lvl * lvl * lvl) > (int)ob->query("combat_exp"))
        {
                message_vision("$N的实战经验不足，无法领悟壁上内容。\n",ob);
                return 1;
        }
        if (ob->query("jing")<20)
        {
                 message_vision("$N太累了，现在无法领悟壁上内容。\n",ob);
                 return 1;
        }
        message_vision("$N面对着壁上图案揣摩良久，似有所悟。\n",ob);
        ob->improve_skill("xue-dao", random(ob->query("int")));
        ob->receive_damage("jing", 20);
        return 1;
}

int do_baohu(string arg)
{
	object me = this_player(), ob;
	if (!me->query_temp("szj/wait_baohu")) return 0;
	if (arg != "shui sheng") return 0;
	me->delete_temp("szj/wait_baohu");
	ob = present("xuedao laozu", this_object());
	message_vision(HIW"$N叫道：“别再杀人了！”扑将上去，手中树枝击在$n腕上。\n"NOR, me, ob);
	message_vision(HIC"若在平时，$n焉能给$N击中？但这时衰颓之余，功力不到原来的半成，手指一松，血刀脱手。\n"NOR, me, ob);
	me->set_temp("szj/baohu", 1);
	me->set_temp("szj/wait_qiang", 1);
	return 1;
}

int do_qiang(string arg)
{
	object me = this_player(), ob;
	if (!me->query_temp("szj/wait_qiang")) return 0;
	if (arg != "dao" && arg !="blade") return 0;
	me->delete_temp("szj/wait_qiang");
	ob = present("xuedao laozu", this_object());
	message_vision(HIW"$N和$n同时俯身去抢兵刃。$N手掌在下，先按到了刀柄。\n"NOR, me, ob);
	message_vision(HIC"$n提起双手，便往$N颈中扼去。$N一阵窒息，放开了血刀，伸手撑持。\n"NOR, me, ob);
	message_vision(HIC"$n知道自己力气无多，这一下若不将$N扼死，自己便命丧$N手。\n"NOR, me, ob);
	message_vision(HIC"$N头颈被血刀僧扼住，呼吸越来越艰难，胸口如欲迸裂。\n\n"NOR, me, ob);
	me->start_busy(100);
	call_out("story3", 2, me, ob);
	return 1;
}

void story3(object me, object ob)
{
	if (me->query_skill("shenzhao-jing", 1) < 200) {
		call_out("finish", 1, me, ob);
		return;
	}
	tell_object(me, HIR"你肺中积聚着的一股浊气数度上冲，要从口鼻中呼了出来，但喉头的要道被阻，这股气冲到喉头，又回了下去。\n"NOR);
	tell_object(me, HIR"一股浊气在你体内左冲右突，始终找不到出路。\n"NOR);
	tell_object(me, HIR"你只感全身难受困苦已达极点，心中只叫：“我快要死了，我快要死了！”\n\n"NOR);
	call_out("story4", 2, me, ob);
}

void story4(object me, object ob)
{
	object obj;
	int lev = me->query_skill("force", 1);
	if (random(150 + lev/2) < 300
	) {
		call_out("finish", 1, me, ob);
		return;
	}
	tell_object(me, HIW"突然之间，你只觉胸腹间剧烈刺痛，体内这股气越胀越大，越来越热，犹如满镬蒸气
没有出口，直要裂腹而爆，蓦地里前阴后阴之间的“会阴穴”上似乎被热气穿破了一个小
孔，登时觉得有丝丝热气从“会阴穴”通到脊椎末端的“长强穴”去。人身“会阴”“长
强”两穴相距不过数寸，但“会阴”属于任脉，“长强”却是督脉，两脉的内息决不相通。
你体内的内息加上无法宣泄的一股巨大浊气，交迸撞激，竟在危急中自行强冲猛攻，替你
打通了任脉和督脉的大难关。这内息一通入“长强穴”，登时自腰俞、阳关、命门、悬枢
诸穴，一路沿着脊椎上升，走的都是背上督任各个要穴，然后是脊中、中枢、筋缩、至阳、
灵台、神道、身柱、陶道、大椎、痖门、风府、脑户、强间、后顶、而至顶门的“百会穴”。\n"NOR);
	tell_object(me, HIW"这股内息冲到百会穴中，只觉颜面上一阵清凉，一股凉气从额头、鼻梁、口唇下来，通到
了唇下的“承浆穴”。这承浆穴已属任脉，这一来自督返任。任脉诸穴都在人体正面，这
股清凉的内息一路下行，自廉泉、天突而至璇玑、华盖、紫宫、玉堂、膻中、中庭、鸠尾、
巨阙、经上、中、下三脘，而至水分、神厥、气海、石门、关元、中极、曲骨诸穴，又回
到了“会阴穴”。如此一个周天行将下来，郁闷之意全消，说不出的畅快受用。内息第一
次通行时甚是艰难，任督两脉既通，道路熟了，第二次、第三次时自然而然的飞快运转，
顷刻之间，连走了一十八次。\n\n"NOR);
	me->start_busy(1);
	me->set("szj/over200",1);
	message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"机缘巧合，打通了任督二脉，达到了神照经心法的最高境界！\n"NOR, users());
	message_vision(HIC"$N体内的劲力愈来愈强，心中却仍是十分害怕，只求挣扎脱身，双手乱抓乱舞，始终碰
不到$n身上，左脚向后乱撑几下，突然一脚踹在$n的小腹之上。\n\n"NOR, me, ob);
	if (ob) ob->start_busy(100);

	obj = present("shui sheng", this_object());
	if (!obj) return;
	message_vision(HIY"$N说道：姑娘你走吧，否则$n醒来一定不会放过你的。\n"NOR, me, ob);
	message_vision(HIY"$n冷哼一声：你也不是好人，我以后不会放过你的！\n"NOR, me, obj);
	message_vision(HIY"$n说完哭着向外面跑去。\n\n"NOR, me, obj);
	destruct(obj);


}

void finish(object me, object ob)
{
	object obj = present("shui sheng", this_object());
	if (!obj) return;
	message_vision(HIY"$n冷哼一声，小崽子自不量力，看在你给老子找女人的分上饶你不死。\n"NOR, me, ob);
	message_vision(HIY"可是这个小妞咱可不能防过，否则等她力气恢复了，肯定会杀了我们两个。\n"NOR, me, ob);
	message_vision(HIY"$n挥刀砍向水笙，水笙躲避不及，鲜血从喉咙口直流出来。\n"NOR, me, ob);
	obj->die();
	me->start_busy(1);
	me->set_temp("isdeads",1);
	me->unconcious();
}

