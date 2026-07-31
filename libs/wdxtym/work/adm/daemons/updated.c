// updated.c

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <room.h>
#include <login.h>

inherit F_SAVE;
#include <vip_skill.h>

// data need save
mixed title_base;
string query_save_file() { return DATA_DIR "pinfo"; }

void remove_title(object ob);
void set_title(object ob);
object global_find_player(string user);
void global_destruct_player(object ob, int raw);

nosave mapping skill_list = ([
	"dragon-strike" 		: (["congenital" :(["str" :30, "con" :22, ]), ]),
	"beimin-shengong" 	: (["congenital" :(["int" :32, "con" :24, ]), ]),
	"longxiang" 			: (["congenital" :(["str" :24, "con" :30, ]), ]),
	"six-finger" 			: (["congenital" :(["int" :32, "con" :26, ]), ]),
	"yijin-duangu" 			: (["congenital" :(["int" :26, ]), ]),
	"xixing-dafa" 			: (["congenital" :(["con" :20, ]), "no_character" :({"光明磊落", }), ]),
	"taixuan-gong" 		: (["congenital" :(["str" :25, "int" :18, "con" :25, "dex" :25, ]), ]),
	"qiankun-danuoyi" 	: (["congenital" :(["int" :22, ]), ]),
	"jiuyang-shengong" 	: (["congenital" :(["int" :25, "con" :29, ]), ]),
	"lonely-sword" 		: (["congenital" :(["int" :34, ]), "character" :({"狡黠多变", }), ]),
	"jiuyin-shengong" 		: (["character" :({"光明磊落", }), ]),
	"never-defeated" 		: (["character" :({"狡黠多变", }), ]),
	"bluesea-force" 		: (["character" :({"心狠手辣", }), ]),
	"kuihua-shengong" 	: (["character" :({"阴险奸诈", }), "sex" :({"无性", }), ]),
	"kuihua-mogong" 	: (["character" :({"阴险奸诈", }), "sex" :({"无性", }), ]),
	"riyue-guanghua" 		: (["congenital" :(["dex" :25, ]), "no_character" :({"光明磊落", }), "sex" :({"无性", }), ]),
	"qishang-quan" 		: (["congenital" :(["str" :24, "con" :30, ]), ]),
	"piaoxue-zhang" 		: (["congenital" :(["str" :24, "con" :23, ]), ]),
	"bianfu-bu" 			: (["congenital" :(["dex" :26, ]), "no_congenital" :(["str" :26, ]), ]),
	"baihua-quan" 			: (["congenital" :(["int" :28, "con" :28, ]), ]),
	"shenghuo-shengong" : (["congenital" :(["int" :32, ]), ]),
	"xiaoyao-jian"			: (["congenital" :(["int" :30, ]), ]),
	"yijin-duangu"			: (["congenital" :(["int" :26, ]), ]),
	"chuixiao-jifa"			: (["congenital" :(["int" :24, ]), ]),
	"tanqin-jifa"			: (["congenital" :(["int" :24, ]), ]),
	"huagong-dafa"		: (["no_character" :({"光明磊落", "狡黠多变",}), ]),
	"poison"				: (["no_character" :({"光明磊落", }), ]),
]);
void log_delsk(object ob, string type, string skname, int lvl, string family_name)
{
	if (skname && lvl && type && family_name) {
		log_file("delsk", sprintf("%s(%s) %s->%s lvl=%d 于%s\n", 
					ob->query("id"), family_name, type, skname, lvl, ctime(time())));
	}
}
void check_skill(object me)
{
	mapping all_skill=([]);
	string *list;
	int i, size, lvl;
	string character;
	mapping cong=([]);
	string *list2;
	int k;
	string skname, sex;
		
	if (!me)
		return;

	if (size = sizeof(all_skill = me->query_skills()))
	{
		list = keys(all_skill);
		character = me->query("character");
		sex = me->query("gender");
		for(i=0;i<size; i++) {
			reset_eval_cost();
			skname = list[i];
			if (skill_list[skname]) {//进入条件检查，不符合的删除，做好记录
				if (check_vip_skill(skname, me)) {//检查VIP对应等级赠送的技能，满足条件则无条件拥有
					continue;
				}
				
				if (skill_list[skname]["sex"]) {//性别检查
					list2 = skill_list[skname]["sex"];
					if (member_array(sex, list2) ==-1) {//没有该性别
						if (lvl = me->query_skill(skname, 1)) {
							tell_object(me, sprintf("你的性别%s不符合%s，已经删除%s。\n", 
											sex, to_chinese(skname), to_chinese(skname)+"("+(skname)+")"));
							me->delete_skill(skname);
							log_delsk(me, "del", skname, lvl, "性别"+sex+"不符");
						}
					}
				}
				if (!me->query_skill(skname, 1))
					continue;
				if (skill_list[skname]["character"]) {//性格检查
					list2 = skill_list[skname]["character"];
					if (member_array(character, list2) ==-1) {//没有该先天
						if (lvl = me->query_skill(skname, 1)) {
							tell_object(me, sprintf("你的性格%s不符合%s，已经删除%s。\n", 
											character, to_chinese(skname), to_chinese(skname)+"("+(skname)+")"));
							me->delete_skill(skname);
							log_delsk(me, "del", skname, lvl, "性格"+character+"不符");
						}
					}
				}
				if (!me->query_skill(skname, 1))
					continue;
				if (skill_list[skname]["no_character"]) {//性格检查
					list2 = skill_list[skname]["no_character"];
					if (member_array(character, list2) !=-1) {//有该先天
						if (lvl = me->query_skill(skname, 1)) {
							tell_object(me, sprintf("你的性格%s不符合%s，已经删除%s。\n", 
											character, to_chinese(skname), to_chinese(skname)+"("+(skname)+")"));
							me->delete_skill(skname);
							log_delsk(me, "del", skname, lvl, "性格"+character+"不符");
						}
					}
				}
				if (!me->query_skill(skname, 1))
					continue;
				if (skill_list[skname]["congenital"]) {//先天检查
					cong = skill_list[skname]["congenital"];
					list2 = keys(cong);
					for(k =0; k< sizeof(list2); k++) {
						if (me->query(list2[k], 1)< cong[list2[k]]) {
							if (lvl = me->query_skill(skname, 1)) {
								tell_object(me, sprintf("你的先天%s小于%d点，已经删除%s。\n", 
												list2[k], cong[list2[k]], to_chinese(skname)+"("+(skname)+")"));
								me->delete_skill(skname);
								log_delsk(me, "del", skname, lvl, "先天"+(list2[k])+"小于"+(cong[list2[k]]));
							}
						}
					}
				}
				if (!me->query_skill(skname, 1))
					continue;
				if (skill_list[skname]["no_congenital"]) {//先天检查
					cong = skill_list[skname]["no_congenital"];
					list2 = keys(cong);
					for(k =0; k< sizeof(list2); k++) {
						if (me->query(list2[k], 1)> cong[list2[k]]) {
							if (lvl = me->query_skill(skname, 1)) {
								tell_object(me, sprintf("你的先天%s大于%d点，已经删除%s。\n", 
												list2[k], cong[list2[k]], to_chinese(skname)+"("+(skname)+")"));
								me->delete_skill(skname);
								log_delsk(me, "del", skname, lvl, "先天"+(list2[k])+"大于"+(cong[list2[k]]));
							}
						}
					}
				}
			}
		}
	}
}
void create()
{
	seteuid(ROOT_UID);
	restore();

	if (arrayp(title_base))
		title_base = filter_array(title_base, (: arrayp($1) && sizeof($1) == 2 :));
	else
		title_base = 0;
}

#define LUBAN	   "/adm/npc/luban"
#define RING_DIR	"/data/item/ring/"
void check_family(object ob)
{
	int lvl;
	string skname, family_name;
	
	family_name = ob->query("family/family_name");
	if (!family_name)
		family_name = "无门派";

}
// check the user's data when login
void check_user(object ob)
{
	mapping my;
	mapping skill_status;
	string *sname;
	int combat_exp;
	int level;
	int i;
	mapping party;

	my = ob->query_entire_dbase();

	if (ob->query("family/generation") == 0)
		ob->delete("family");
	
	if (!wizardp(ob) 
	&& ob->query("id")!="z110614_1" 
	&& ob->query("check_all_times") < time()) {
		check_family(ob);
		check_skill(ob);
		ob->set("check_all_times", time() +600);//间隔10分钟检查一次
	}
	
	if (ob->query("quest/kuihua/pass")) {//修复葵花解密引起的quest无法接的问题。by luoyun 2018.6.4
		ob->delete("quest");
		ob->set("quest2/kuihua/pass", 1);
	}
	if (ob->query("gender") == "无性")
		ob->set("class", "eunach");

	if ((int)ob->query("combat/today/which_day") != time() / 86400)
		ob->delete("combat/today");

	if (ob->query("couple") && ! ob->query("static/marry"))
		ob->set("static/marry", 1);

	if (mapp(party = my["party"]) && stringp(party["party_name"]))
		party["party_name"] = filter_color(party["party_name"]);

	// 记录名字
	NAME_D->map_name(ob->query("name"), ob->query("id"));

	// 重新设置运行计时器
	reset_eval_cost();

	// 赋予称号
	set_title(ob);

	// 更新数据
	if (arrayp(my["channels"]))
	{
		for (i = 0; i < sizeof(my["channels"]); i++)
			if (my["channels"][i] == "sing") my["channels"][i] = "sos";
	}

	if (undefinedp(my["eff_jing"]))  my["eff_jing"] = my["max_jing"];
	if (undefinedp(my["eff_qi"])) my["eff_qi"] = my["max_qi"];
	if (my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];
	if (my["eff_qi"] > (my["max_qi"]+ob->query_gain_qi())) my["eff_qi"] = my["max_qi"]+ob->query_gain_qi();
	if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
	if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
	if (my["neili"] > my["max_neili"] * 2) my["neili"] = my["max_neili"] * 2;

	combat_exp = (int)ob->query("combat_exp");
	if (! mapp(skill_status = ob->query_skills()))
		return;
	sname  = keys(skill_status);

	for (i = 0; i < sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if (file_size(SKILL_D(sname[i]) + ".c") == -1)
		{
			tell_object(ob, "No such skill:" + sname[i] + "\n");
			continue;
		}

		if (SKILL_D(sname[i])->type() == "martial")
		{
	    		while (level &&
			       //(level - 1) * (level -1 ) * 10 > combat_exp)   //掉线不掉技能
				   (level - 1) * (level -1 ) * (level - 1) / 10 > combat_exp) //恢复掉线掉技能
	    		       level--;
	
	    		ob->set_skill(sname[i], level);
		}
	}
	
	if (ob->query("gender") == "无性" ) {
	   if (ob->query_skill("yijinjing",1)) {
		log_file("delete", sprintf("%s：%s(%s)删除了%d级%s。\n",
				ctime(time()),ob->query("name"),ob->query("id"),
				ob->query_skill("yijinjing",1),to_chinese("yijinjing"),));
		ob->delete_skill("yijinjing", 1);
            }
	}
	if (ob->query_skill("qiankun-danuoyi",1) > (ob->query("int")-22)*50 && ob->query_skill("qiankun-danuoyi",1)>0) {
         if (ob->query("int")>22) {
		log_file("delete", sprintf("%s：%s(%s)重置了%d级%s，原来%d级。\n",
				ctime(time()),ob->query("name"),ob->query("id"),(ob->query("int")-22)*50,
				to_chinese("qiankun-danuoyi"),ob->query_skill("qiankun-danuoyi",1),));
		ob->set_skill("qiankun-danuoyi", (ob->query("int")-22)*50 );
            }
         else {
		log_file("delete", sprintf("%s：%s(%s)删除了%d级%s。\n",
				ctime(time()),ob->query("name"),ob->query("id"),
				ob->query_skill("qiankun-danuoyi",1),to_chinese("qiankun-danuoyi"),));
		ob->delete_skill("qiankun-danuoyi", 1);
            }
	}
	if (ob->query("zhuanshi") != 1 && ob->query_skill("zuoyou-hubo",1) > (35-ob->query("int"))*30 && ob->query_skill("zuoyou-hubo",1)>0) {
         if (ob->query("int")<30) {
		log_file("delete", sprintf("%s：%s(%s)重置了%d级%s，原来%d级。\n",
				ctime(time()),ob->query("name"),ob->query("id"),(34-ob->query("int"))*30,
				to_chinese("zuoyou-hubo"),ob->query_skill("zuoyou-hubo",1),));
		ob->set_skill("zuoyou-hubo", (35-ob->query("int"))*30 );
            }
         else {
		log_file("delete", sprintf("%s：%s(%s)删除了%d级%s。\n",
				ctime(time()),ob->query("name"),ob->query("id"),
				ob->query_skill("zuoyou-hubo",1),to_chinese("zuoyou-hubo"),));
		ob->delete_skill("zuoyou-hubo", 1);
            }
	}
	

}

// clear the user's data
// when catalog parameter equal to "all", I will remove all
// the informatino of this user. This may be used when the
// user was purged.
string clear_user_data(string user, string cat)
{
	object login_ob;
	object ob;
	string couple_id;
	string path, file_name;
	string *dirs;
	object temp;
	string brothers;
	string bro_id;
	string *ks;
	mapping bro;
	int flag;
	int i;

	// only root uid can does it
	if (previous_object() &&
	    getuid(previous_object()) != ROOT_UID &&
	    geteuid(previous_object()) != user)
		return "你无权清除该玩家的数据。\n";

	// find the user's body
	seteuid(getuid());
	login_ob = 0;
	ob = find_player(user);
	if (! ob)
	{
		login_ob = new(LOGIN_OB);
		login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
		if (! ob)
		{
			catch(destruct(login_ob));
			return "暂时无法生成玩家对象。\n";
		}

		if (! ob->restore())
		{
			catch(destruct(login_ob));
			catch(destruct(ob));
			return "没有这个玩家。\n";
		}

		ob->setup();
	}

	// no catalog? treat it as "all"
	if (! cat) cat = "all";
	flag = 0;

	// remove name information
	if (cat == "name" || cat == "all")
		NAME_D->remove_name(ob->query("name"), ob->query("id"));

	// remove room information
	if ((cat == "room" || cat == "all") &&
	    mapp(ob->query("private_room")))
	{
		// Demolish the room of the user
		LUBAN->demolish_room(ob);
		flag++;
	}

	// remove balance information
	if (cat == "balance" || cat == "all")
		ob->set("balance", 0);

	// remove marriage information
	if ((cat == "couple" || cat == "all") &&
	    mapp(ob->query("couple")))
	{
		// clear the couple infomation

		// remove the ring
		file_name = RING_DIR + ob->query("id");
		if (file_size(file_name + ".c") > 0)
		{
			if (temp = find_object(file_name))
			{
				if (environment(temp))
				{
					message("vision", HIM + temp->name() +
						HIM "忽然化作一缕清烟，不见了！"NOR"\n",
						environment(temp));
				}
			}
			DBASE_D->clear_object(file_name);
		}

		couple_id = ob->query("couple/id");
		ob->delete("couple");
		ob->delete("can_summon/wedding ring");
		if (! sizeof(ob->query("can_summon")))
			ob->delete("can_summon");
		flag++;
		if (couple_id) clear_user_data(couple_id, "couple");
	}

	// remove item information
	if (cat == "item" || cat == "all")
	{
		object item;
		mapping sum;

		// clear the all item
		path = ITEM_DIR + ob->query("id")[0..0] + "/";
		dirs = get_dir(path + ob->query("id") + "-*");
		for (i = 0; i < sizeof(dirs); i++)
		{
			file_name = path + dirs[i];
			if ((item = find_object(file_name)) &&
			    environment(item))
			{
				message("vision", HIM + item->name() +
					"忽然化作一股轻烟，不见了！"NOR"\n",
					environment(item));
			}

			// rememberd by doing, for keep the item'sdata in dbased
			// DBASE_D->clear_object(file_name);
			rm(file_name);
		}

		if (mapp(sum = ob->query("can_summon")))
		{
			// clear summon information
			ks = keys(sum);
			for (i = 0; i < sizeof(ks); i++)
				if (sscanf(sum[ks[i]], path + ob->query("id") + "-%*s") == 1)
					map_delete(sum, ks[i]);

			if (! sizeof(sum))
				ob->delete("can_summon");
		}
	}

	// remove board information
	if (cat == "board" || cat == "all")
	{
		object *rooms;
		rooms = filter_array(children(CHAT_ROOM),
				     (: clonep($1) && $1->query("owner_id") == $(user) :));
		for (i = 0; i < sizeof(rooms); i++)
			destruct(rooms[i]);
		file_name = DATA_DIR + "board/chatroom_" + user + __SAVE_EXTENSION__;
		rm(file_name);
	}

	if (cat == "hatred" || cat == "all")
	{
		FAMILY_D->remove_hatred(ob->query("id"));
		LEAGUE_D->remove_hatred(ob->query("id"));
	}

	if (mapp(bro = ob->query("brothers")) &&
	    (sscanf(cat, "brothers:%s", brothers) == 1 || cat == "all"))
	{
		if (cat == "all") brothers = "all";

		if (brothers == "all")
		{
			foreach (bro_id in keys(bro))
				clear_user_data(bro_id, "brothers:" + ob->query("id"));

			ob->delete("brothers");
		} else
		if (! undefinedp(bro[brothers]) != -1)
		{
			map_delete(bro, brothers);
			if (sizeof(bro) < 1)
				ob->delete("brothers");
			else
				ob->set("brothers", bro);
		}
		flag++;
	}

	if (cat == "league" || cat == "all")
	{
		LEAGUE_D->remove_member_from_league(ob);
		ob->delete("league");
	}

	if (cat == "title" || cat == "all")
		remove_title(ob);

	// remove granted information
	if (cat == "grant" || cat == "all")
		SECURITY_D->remove_grant(ob, "*");

	// save the data of the user
	if (flag) ob->save();

	// Destrut the object if create temporate
	if (login_ob)
	{
		catch(destruct(login_ob));
		catch(destruct(ob));
	}

	return "成功。\n";
}

// remove an user
string remove_user(string user)
{
	object ob;
	string result;

	// destruct the user object
	if (ob = find_player(user))
	{
		if (ob->query_temp("link_ob"))
			catch(destruct(ob->query_temp("link_ob")));
		catch(destruct(ob));
	}

	// Remove the user from wizlist if the user was wizard
	SECURITY_D->set_status(user, "(player)");

	// Remove the user's grant inforamtion
	SECURITY_D->remove_grant(user, "*");

	// clear the data of user first
	result = clear_user_data(user, "all");

	// remove the file of the user
	rm(DATA_DIR + "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "user/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "baibao/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
}

void init_player(object me)
{
	string *dbs;
	int i;
	object *inv;
	mapping my;
	mapping db = ([
		"str":10,
		"dex":10,
		"con":10,
		"int":10,
		"kar":10,
		"per":10,
		"gender":me->query("gender"),
		"id":me->query("id"),
		"surname":me->query("surname"),
		"purename":me->query("purename"),
		"name":me->query("name"),
		"title":"普通百姓",
		"birthday":time(),
		"potential":99,
		"food":200,
		"water":200,
		"channels":({ "chat", "rumor", "party","bill", "sos", "family","ic", "rultra" }),
		"env/wimpy":60,
		"zjvip":me->query("zjvip"),
		"yuanbao":me->query("yuanbao"),
	]);
	my = me->query_entire_dbase();
	dbs = keys(my);
	for(i=0;i<sizeof(dbs);i++)
	{
		if(db[dbs[i]])
			me->set(dbs[i],db[dbs[i]]);
		else
			me->delete(dbs[i]);
	}
	me->clear_all_skill();
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("equipped"))
			inv[i]->unequip();
		destruct(inv[i]);
	}
	me->set("startroom", REGISTER_ROOM);
	me->move(REGISTER_ROOM);
	me->save();
}

// user born
void born_player(object me)
{
	mixed files;
	int i;
	string special;
	string msg;

	msg = HIG "你的天赋技能有：" NOR;

	// 查看所有的特殊技能文件
	files = get_dir("/kungfu/special/");
	me->delete("special_skill");

	if (sizeof(files))
	{
		// 整理所有的技能文件
		for (i = 0; i < sizeof(files); i++)
			sscanf(files[i], "%s.c", files[i]);

		// 先天容貌 < 20 不会驻颜
		if (me->query("per") < 20)
			files -= ({ "youth" });

		  //女性不会鬼脉
		  if(me->query("gender") == "女性")
			   files -= ({ "ghost" });

		// 获得第一项技能
		special = files[random(sizeof(files))];
		me->set("special_skill/" + special, 1);
		msg += SPECIAL_D(special)->name();

		files -= ({ special });
		if ((sizeof(files) && random(30) == 1 && me->query("combat_exp") > 1)|| me->query_temp("born_skill2"))
		{
			// 获得第二项技能
                        me->delete_temp("born_skill2");
			special = files[random(sizeof(files))];
			me->set("special_skill/" + special, 1);
			msg += HIG "、" NOR + SPECIAL_D(special)->name();
			files -= ({ special });
			if ((sizeof(files)&&random(10) == 1 )|| me->query_temp("born_skill3"))
			{
				// 获得第三项技能
                           me->delete_temp("born_skill3");
				special = files[random(sizeof(files))];
				me->set("special_skill/" + special, 2);
				msg += HIG "、" NOR + SPECIAL_D(special)->name();
				files -= ({ special });
				if ((sizeof(files)&&random(10) == 1 )|| me->query_temp("born_skill4"))
				{	// 获得第4项技能
					me->delete_temp("born_skill4");
				special = files[random(sizeof(files))];
				me->set("special_skill/" + special, 2);
				msg += HIG "、" NOR + SPECIAL_D(special)->name();
				files -= ({ special });
				if ((sizeof(files)&&random(10) == 1 )|| me->query_temp("born_skill5"))
				{// 获得第5项技能
				me->delete_temp("born_skill5");
				special = files[random(sizeof(files))];
				me->set("special_skill/" + special, 2);
				msg += HIG "、" NOR + SPECIAL_D(special)->name();
				files -= ({ special });
				if ((sizeof(files)&&random(10) == 1 )|| me->query_temp("born_skill6")){// 获得第6项技能
					me->delete_temp("born_skill6");
				special = files[random(sizeof(files))];
				me->set("special_skill/" + special, 2);
				msg += HIG "、" NOR + SPECIAL_D(special)->name();
				}
				}
				}
			}
		}
		msg += HIG " 。"NOR"\n";
		tell_object(me, msg);
	}
}

// notice user a piece of message, delay call by born user
void notice_player(object me, string msg)
{
	tell_object(me, msg);
}

// query title dbase
mixed query_title_base()
{
	if (! is_root(previous_object()))
		return 0;

	return title_base;
}

// set title dbase
mixed set_title_base(mixed ts)
{
	if (! is_root(previous_object()))
		return 0;

	title_base = ts;
}

// 清除某个玩家的 title
void remove_title(object ob)
{
	int i;

	if (! arrayp(title_base) || ! ob->query("granted_title"))
		return;

	ob->delete_temp("title");
	ob->delete("granted_title");

	for (i = 0; i < sizeof(title_base); i++)
	{
		// 搜索所有的 title
		if (title_base[i][1] == ob->query("id"))
			// 去掉title
			title_base[i][1] = 0;
	}
	save();
	return;
}

// 设置某个玩家的 title
void set_title(object ob)
{
	string id;
	int i;

	if (! arrayp(title_base) || ! ob->query("granted_title"))
		return;

	id = ob->query("id");
	for (i = 0; i < sizeof(title_base); i++)
		if (title_base[i][1] == id)
		{
			// 加上title
			ob->set_temp("title", title_base[i][0]);
			return;
		}

	// 这个用户并没有分配的称号
	ob->delete("granted_title");
}

// 寻找或调入某一个玩家
// 如果程序处理中需要更新那些不在线的玩家，则可以使用该函数
// 将这个玩家调入并且进行修改，请注意：修改完毕以后程序必须
// 保存玩家，并且使用 global_destruct_player 将玩家析构，如
// 果没有调用这个函数，则赋予玩家的定时器会自动析构玩家。
object global_find_player(string user)
{
	object ob;
	object login_ob;

	ob = find_player(user);
	if (! ob)
	{
		login_ob = new(LOGIN_OB);
		login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
		if (! ob)
		{
			catch(destruct(login_ob));
			return 0;
		}

		evaluate(bind((: seteuid(getuid()) :), ob));

		if (! ob->restore())
		{
			catch(destruct(login_ob));
			catch(destruct(ob));
			return 0;
		}

		ob->set_temp("temp_loaded", 1);
		ob->start_call_out(bind((: call_other, __FILE__, "global_destruct_player", ob, 0 :), ob), 0);
		catch(destruct(login_ob));
	}

	return ob;
}

// 析构一个被 UPDATE_D 调入的玩家
void global_destruct_player(object ob, int raw)
{
	if (objectp(ob) && ob->query_temp("temp_loaded"))
	{
		if (raw) ob->save();
		destruct(ob);
	}
}
