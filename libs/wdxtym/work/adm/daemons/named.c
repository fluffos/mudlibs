// named.c 保存所有玩家的名字

#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

static string *family_name = ({ "东方","操你","操他","操她","日你","日他","日她","大爷","妈","干你","干他","干她",
"大便","fuck","下阴","阴部","口交","性交","阴唇","阴道","轩辕三光",
"自己","杀手","闪电","雪人","逍遥","我们","你们","他们","咱们","大家","某人","尸体",
"天神","总管","龙神","仙人","巫师","门客","玩家","书剑","名字待定","中神通","蒙面",
"蒙面人","刺客","忍者","镖师","鬼魂","头颅","杀人犯",
// Mud 地名，门派名
"衡山","华山","嵩山","恒山","泰山","雪山","黄山","天山","西域","苗疆","东北","中原",
"南疆","长江","黄河","中国","中华","昆仑山","长白山","白驼山","武当山","峨嵋山",
"冰火岛","桃花岛","黑木崖",
"少林","丐帮","明教","密宗","古墓","全真","铁掌","大理","白驼","桃花","星宿",
"天龙寺","大轮寺","五毒教","正义","邪恶","五岳剑派","日月神教","官府","武林",
"少林寺","武当派","铁掌帮","普通百姓","峨嵋派","姑苏慕容","古墓派","华山派","嵩山派",
"明教","神龙教","星宿派","蜀山剑派"
// 重要人物名字
"金庸","邓小平","江泽民","毛泽东","朱榕基","皇帝","皇上","总理","主席","习近平","李克强",
 "管理员","巫师","干部",
// 小说人物
"张三丰","张无忌","郭靖","杨过","令狐冲","胡斐","苗人凤","韦小宝","袁承志","胡一刀",
"陈家洛","段誉","萧锋","乔锋","虚竹","东方不败","欧阳锋","洪七公","黄药师","段皇爷",
"一灯大师","王重阳","周伯通","黄蓉","风清扬","独孤求败",
// 脏话
"统一","法轮","吃人","他妈的","去你的","干你娘","废物",
"混蛋","坏蛋","杀人","抢劫","强奸","妓女","台独","领导","中央","屁眼","屁股","裸体",
"放屁","鸡巴","阴道","婊子","你丫","日你","赤佬","瘪三","傻逼","蠢蛋","操他","我操",
"太监","宦官","阉割","阉人","鸡婆","奸淫","淫荡","奸","三级","政治",
//特殊名字
"淑女","君子",
});

void create()
{
	seteuid(getuid());
	restore();
}

void remove()
{
	save();
}

void mud_shutdown()
{
	save();
}

// the name PATH store in dbase
#define PATH(name)      (name[0..1] + "/" + name)

// remove the mapping of a name & id
public void remove_name(string name, string id)
{
	string old;
	string *ms;

	if (! stringp(name) || strlen(name) < 2 ||
	    undefinedp(old = query(PATH(name))))
		return;

	if (! stringp(old) ||
	    ! sizeof(ms = explode(old, "/") - ({ id })))
	{
		delete(PATH(name));
		if (! sizeof(query(name[0..1])))
			delete(name[0..1]);
		save();
		return;
	}

	set(PATH(name), implode(ms, "/"));
	save();
}

// record the mapping of a name & id
public void map_name(string name, string id)
{
	string old;
	string *ms;

	if (! stringp(name) || strlen(name) < 2)
		return;

	if (! stringp(old = query(PATH(name))))
		set(PATH(name), id);
	else
	{
		ms = explode(old, "/");
		if (member_array(id, ms) != -1)
			// alreay exist
			return;

		ms += ({ id });
		set(PATH(name), implode(ms, "/"));
	}

	save();
}

// check name
public string who_is(string name)
{
	string id;

	if (! stringp(name) || strlen(name) < 2 ||
	    ! stringp(id = query(PATH(name))))
		return "没有人叫这个名字。\n";

	return "武动仙途中叫" + name + "的有：" + id + "\n";
}

// check the id - name
private int really_exist(string name, string id)
{
	object ob;
	object user;
	int result;

	if (! stringp(id))
		return 0;

	ob = find_player(id);
	if (objectp(ob))
	{
		if (ob->name(1) == name)
			return 1;
		else
			return 0;
	}

	// read the data of user object
	ob = new(LOGIN_OB);
	ob->set("id", id);
	user = LOGIN_D->make_body(ob);
	destruct(ob);

	if (! objectp(user))
		// no such user
		return 0;

	result = user->restore() && (user->name(1) == name);
	destruct(user);

	return result;
}

// assure the id matched the name
public void assure_map_name(string name)
{
	string id;
	string *ids;

	if (! stringp(id = query(PATH(name))))
		// null name
		return;

	ids = explode(id, "/");

	// examine all the id
	ids = filter_array(ids, (: really_exist, name :));

	if (! sizeof(ids))
	{
		// no id matched
		delete(PATH(name));
		return;
	}

	// reset name-id mapping
	id = implode(ids, "/");
	set(PATH(name), id);
}

// If the name to be a new name, dose it invalid ?
public string invalid_new_name(string name)
{
	string id;
	int i;
	int l;

	if (! stringp(name) || strlen(name) < 2 || strlen(name) > 8)
		return "名字只能是1-4个中文字。\n";

	if (! is_chinese(name))
		return "名字只能是1-4个中文字。\n";

	for(i=0;i<sizeof(family_name);i++)
	{
		if (strsrch(name,family_name[i]) != -1)
			return "对不起，名字中不能包含【"+family_name[i]+"】。\n";
	}

	// 和对有关ID-名字的信息
	assure_map_name(name);

	if (id = query(PATH(name)))
		return "这个名字和 " + id + " 的名字重复了。\n";

/*
	if (strlen(name) < 4)
		return 0;

	l = strlen(name);
	for (i = 0; i <= l - 4; i++)
	{
		// 和对有关ID-名字的信息
		assure_map_name(name[i..i + 3]);
		if (i + 6 <= l)
			assure_map_name(name[i..i + 5]);

		if (member_array(name[i..i + 3], family_name) == -1 &&
		    stringp(id = query(PATH(name[i..i + 3]))))
			return "这个名字和 " + id + " 的名字太接近了。\n";

		if ((i + 6 <= l) &&
		    stringp(id = query(PATH(name[i..i + 5]))))
			return "这个名字和 " + id + " 的名字太接近了。\n";
	}
*/
	return 0;
}

// change a user's name
public varargs string change_name(object me, string new_name, int force)
{
	string result;
	mapping dbase;

	if (stringp(me->name(1)))
	{
		remove_name(me->name(1), me->query("id"));
		result = invalid_new_name(new_name);
	} else
		result = 0;

	if (force || ! result)
	{
		dbase = me->query_entire_dbase();
		dbase["name"] = new_name;
	}
	
	map_name(me->name(1), me->query("id"));
	return result;
}

// how many name
public int query_total_name()
{
	string *ks;
	int total;
	int i;

	total = 0;
	ks = keys(query_entire_dbase());
	for (i = 0; i < sizeof(ks); i++)
		total += sizeof(query(ks[i]));

	return total;
}

string query_save_file() { return DATA_DIR "named"; }
