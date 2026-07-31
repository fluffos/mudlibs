//CODE BY SCATTER
//pbaohe.c
//V1.01

#include "ansi.h"

inherit ITEM;

private int copy_skill(object ob);
void setup()
{}


void create()
{
        set_name(HIW "玩家形宝盒" NOR, ({ "player box", "he", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "打 menu 来看实际操作手册以及规定\n");
                set("material", "steel");
        }
}


void init()
{
	add_action("do_error", "quit");
	//add_action("do_error", "give");
	add_action("do_error", "sell");
	add_action("do_error", "jiaoyi");
	add_action("do_error", "rumor");
	add_action("do_error", "drop");
	add_action("do_error", "get");
	
	add_action("do_menu", "menu");
	
	add_action("do_cpskill", "cpskill");
	add_action("do_gitem", "gitem");
	add_action("do_fullexp", "fullexp");
	add_action("do_setneili", "setneili");
	add_action("do_setjingli", "setjingli");
	add_action("do_setshen", "setshen");
	add_action("do_resetall", "resetall");
}

int do_resetall(string arg)
{
	object me=this_player();
	me->reincarnate();
	me->clear_condition();
	message_vision(HIW"$N使用了巫师给予的力量。\n",me);
	log_file("/static/player_resetall",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒 RESET 所有的数据  "+ctime(time())+"\n"); 
	return 1;
}

int do_setshen(string arg)
{
	object me=this_player();
	int nvalue;
	nvalue = atoi(arg);

	message_vision(HIW"$N使用了巫师给予的力量。\n",me);
	me->set("shen", nvalue);
	log_file("/static/player_shen",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒 call 了 " + arg + "点神  "+ctime(time())+"\n"); 
	return 1;
}


int do_setjingli(string arg)
{
	object me=this_player();
	int nvalue;
	nvalue = atoi(arg);

	message_vision(HIW"$N使用了巫师给予的力量。\n",me);
	me->set("max_jingli", nvalue);
	me->set("jingli", nvalue);
	log_file("/static/player_jingli",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒 call 了 " + arg + "精力  "+ctime(time())+"\n"); 
	return 1;
}

int do_setneili(string arg)
{
	object me=this_player();
	int nvalue;
	nvalue = atoi(arg);

	message_vision(HIW"$N使用了巫师给予的力量。\n",me);
	me->set("max_neili", nvalue);
	me->set("neili", nvalue);
	log_file("/static/player_neili",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒 call 了 " + arg + "内力  "+ctime(time())+"\n"); 
	return 1;
}

int do_fullexp(string arg)
{
        object me = this_player();
        int myexp, mylvl ;
        mapping skill_status;
        string *sname;
        int i, count,point;

        if(!arg) return notify_fail("你要多少经验？\n");

        sscanf(arg, "%d", myexp);
        if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i],mylvl);
                }
        }

		log_file("/static/player_fullexp",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒 call 了 " + arg + "EXP以及 FULL SKILL  "+ctime(time())+"\n"); 

        me->set("combat_exp",myexp);

        message_vision(HIW"$N使用了巫师给予的力量。\n",me);

        return 1;
}


int do_gitem(string arg)
{
	//剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(falun)，鞭(whip)，铁甲(armor)
	object ob, me=this_player();
	string wpos;

	if(!arg)
	{
		write("指令错误!\n");
	}
	else if(arg == "sword")
	{
		wpos = "/clone/weapon/gangjian";
	}
	else if(arg == "blade")
	{
		wpos = "/clone/weapon/gangdao";
	}
	else if(arg == "stick")
	{
		wpos = "/clone/weapon/gangbang";
	}
	else if(arg == "staff")
	{
		wpos = "/clone/weapon/gangzhang";
	}
	else if(arg == "falun")
	{
		wpos = "/clone/weapon/falun";
	}
	else if(arg == "whip")
	{
		wpos = "/clone/weapon/bian";
	}
	else if(arg == "armor")
	{
		wpos = "/clone/armor/tiejia";
	}
	else if(arg == "feizei")
	{
		wpos = "/task/feizei/feizei";
		message_vision(HIW"$N眼前突然掉下一样东西。\n",me);
		ob = new(wpos);
		ob->move(environment(me));
		log_file("/static/player_getitem",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒拿了 " + arg + " "+ctime(time())+"\n"); 
		return 1;
	}
	else
	{
		write("你要的东西目前无法处里, 请向巫师询问.\n");
		return 1;
	}
	log_file("/static/player_getitem",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒拿了 " + arg + " "+ctime(time())+"\n"); 
	message_vision(HIW"$N眼前突然掉下一样东西。\n",me);
	ob = new(wpos);
	ob->move(me);
	return 1;
}


int do_cpskill(string arg)
{
        object ob, me=this_player();
        object tob;
        string target;

		ob = present(arg, environment(me));
        if (! arg)
        {
                write("指令错误\n");
                return 1;
        }

        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("你眼前没有 " + arg + " 这个人。\n");
		ob = present(arg, environment(me));

		log_file("/static/player_cpskill",me->query("name") + " (" + me->query("id") + ") 使用了玩家宝盒 copy 了 " + arg + " "+ctime(time())+"\n");

        copy_skill(ob);
        message_vision(HIM + me->name(1) + HIM "口中念念有词，只见一道红光笼罩了$N"+ HIM +"和$n"+HIM+"。\n" NOR, me, ob);
        return 1;
}

private int copy_skill(object ob)
{
        mapping hp_status, skill_status, map_status, prepare_status;
        mapping my;
        object me=this_player();
		string *sname, *mname, *pname;
        int i, temp;

        if (mapp(skill_status = me->query_skills()))
        {
                skill_status = me->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        me->delete_skill(sname[i]);
        }

        if (mapp(skill_status = ob->query_skills()))
        {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        me->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        me->map_skill(mname[i]);
        }

        if (mapp(map_status = ob->query_skill_map()))
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        me->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = me->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        me->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = ob->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

        hp_status = ob->query_entire_dbase();
        my = me->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];

        my["max_qi"]     = hp_status["max_qi"];
        my["eff_qi"]     = hp_status["eff_qi"];
        my["qi"]         = hp_status["qi"];
        my["max_jing"]   = hp_status["max_jing"];
        my["eff_jing"]   = hp_status["eff_jing"];
        my["max_jingli"]   = hp_status["max_jingli"];
        my["eff_jingli"]   = hp_status["eff_jingli"];
        my["jingli"]       = hp_status["jingli"];
        my["jing"]       = hp_status["jing"];
        my["max_neili"]  = hp_status["max_neili"];
        my["neili"]      = hp_status["neili"];
        my["jiali"]      = hp_status["jiali"];
        my["combat_exp"] = hp_status["combat_exp"];

        me->reset_action();
        return 1;
}

int do_menu(string arg)
{
	write("----------------------------\n");
	write("|"+ HIW +"    玩家形宝盒使用手册    "+NOR+"|\n");
	write("----------------------------\n\n");
	write(HIG"【使用手册】\n"NOR);
	write("以下是可接受的指令:\n");
	write("- 完全复制 NPC 的武功及设定 (cpskill <ID>)\n");
	write("- 取出指定的武器或铁甲或NPC (gitem <ITEM>) 可使用的东西有\n");
	write("    剑(sword)，刀(blade)，棒(stick)，杖(staff)，轮(falun)，鞭(whip)，铁甲(armor)\n");
	write("    飞贼(feizei)，如需要MASTER请向巫师询问\n");
	write("- 将目前的武功 FULL SKILL 到一个指定的经验直 (fullexp <EXP>) 注: 1 = 1K\n");
	write("- 设定内力 (setneili <数字>)\n");
	write("- 设定精力 (setjingli <数字>)\n");
	write("- 设定正负神 (setshen <数字>)\n");
	write("- FULL 全部和去除毒 (resetall)\n");
	write("\n\n");
	write(HIR"可能某些 PERFORM 要破 QUEST, 可以向巫师询问开启被限制的 PERFORM\n"NOR);
	write(HIY"\nBETA (V1.01)\n"NOR);
	return 1;
}

int do_error(string arg)
{
	write("这个指令你现在不能用\n详情请洽巫师, 谢谢.\n");
	return 1;
}