//autonpc.c
//by luoyun
//飞贼刷新时间改为4分钟，数量增加一个
#include <ansi.h>

inherit F_DBASE;
#include <localtime.h>

mapping room_place = ([
	"白驼山"		: "/d/baituo/",
	"北京"			: "/d/beijing/",
	"长安" 			: "/d/changan/",
	"扬州"			: "/d/city/",
	"成都"			: "/d/city3/",
	"大理"			: "/d/dali/",
	"峨嵋山" 		: "/d/emei/",
	"佛山"			: "/d/foshan/",
	"丐帮" 			: "/d/gaibang/",
	"福州"			: "/d/fuzhou/",
	"关外"			: "/d/guanwai/",
	"归云山庄"	: "/d/guiyun/",
	"古墓" 			: "/d/gumu/",
	"杭州"			: "/d/hangzhou/",
	"黑木涯"		: "/d/heimuya/",
	"衡山" 			: "/d/hengshan/",
	"恒山"			: "/d/henshan/",
	"黄河"			: "/d/huanghe/",
	"华山派"		: "/d/huashan/",
	"灵鹫宫"			: "/d/lingjiu/",
	"灵州"			: "/d/lingzhou/",
	"梅庄"			: "/d/meizhuang/",
	"明教" 			: "/d/mingjiao/",
	"青城山"		: "/d/qingcheng/",
	"全真派" 		: "/d/quanzhen/",
	"泉州" 			: "/d/quanzhou/",
	"少林寺" 		: "/d/shaolin/",
	"神龙岛"		: "/d/shenlong/",
	"嵩山"			: "/d/songshan/",
	"苏州"			: "/d/suzhou/",
	"泰山"			: "/d/taishan/",
	"桃花岛"		: "/d/taohua/",
	"天龙寺"		: "/d/tianlongsi/",
	"万劫谷"		: "/d/wanjiegu/",
	"武当山"		: "/d/wudang/",
	"侠客岛"		: "/d/xiakedao/",
	"襄阳"			: "/d/xiangyang/",
	"逍遥派"		: "/d/xiaoyao/",
	"星宿海" 		: "/d/xingxiu/",
	"血刀门" 		: "/d/xuedao/",
	"雪山" 			: "/d/xueshan/",
	"燕子坞" 		: "/d/yanziwu/",
]);

string *special_list = ({
	"/clone/book/wuji1",
	"/clone/book/wuji2",
	"/clone/book/wuji3",
	"/clone/book/wuji4",
	"/clone/book/qiankun_book",
	"/clone/book/six_book",
	"/clone/book/yijinjing",
	"/clone/book/lbook4",
	"/clone/book/jiuyin1",
	"/d/tulong/obj/zhenjing",
	"/clone/book/ling1",
	"/clone/book/ling2",
	"/clone/book/ling3",
	"/d/tulong/obj/tulongdao",
	"/d/tulong/obj/yitianjian",
	"/clone/weapon/zhenwu",
	"/clone/weapon/xtbishou",
	"/clone/weapon/jsbaojia",
});

object load_room_place(string file_dir)
{
	string *file, bin_dir, path;
	int max, get_an;
	object room;

	bin_dir = file_dir;
		
	if (! bin_dir)
		bin_dir = "/binaries" + file_dir;

	if ( file_size(bin_dir) != -2 ) return 0;
	file = get_dir(bin_dir, -1);

	if ( !(max = sizeof(file)) ) return 0;

	get_an = random(max);
	path = bin_dir + file[get_an][0];
	if ( file_size(path) <= 0 ) return 0;

	if (room=find_object(path))
		return room;
	else
		return load_object(path[0..<3]);
}

int ok = 0;
int ok1 = 0;
string path_where=0;

void create()
{
	seteuid(getuid());
	set("channel_id", "飞贼系统");
	CHANNEL_D->do_channel( this_object(), "sys", "飞贼系统已经启动。"NOR);
	set_heart_beat(20);
}

int clean_up()
{
	return 1;
}
object do_copy()
{
	object room;
	string *strtemp, locastr, exit;
	int temp, i1, i;
	
	//确定位置 
	strtemp = keys(room_place);
	i1 = sizeof(strtemp);
	temp = random(i1);
	locastr = room_place[strtemp[temp]];
	room = load_room_place(locastr);
	path_where = strtemp[temp];
	
	if( objectp(room) )
	{
		exit = room->query("exits"); 
		if ( !room->query("short") || !mapp(exit) || !sizeof(exit) || !room->query("outdoors") || room->query("no_fight")) 
			return do_copy();
	} 

	if ( !objectp(room) )
		return do_copy();
	else
		return room;
}

void clear_special()
{
	int i,k;
	object *list,ob;

	for(i=0;i<sizeof(special_list);i++)
	{
		list = children(special_list[i]);
		if(!list||!sizeof(list)) continue;
		for(k=0;k<sizeof(list);k++)
		{
			if((ob=environment(list[k]))&&playerp(ob))
			{
				tell_object(ob,"系统特殊物品刷新，你身上的"+list[k]->short()+"消失了！\n");
				destruct(list[k]);
			}
		}
	}
}

void check_time()
{
	int GMT = time();
	string d, times;
	int h, s;
	object room, ob;

	times = ctime(GMT);
	//Sun(星期日) Mon(星期一)  Tue(星期二)  Wed(星期三)  Thu(星期四)  Fri(星期五)  Sat(星期六)
	d = times[0..2];//星期
	h = to_int(times[10..12]);//时
	s = to_int(times[14..15]);//分

	if ((s == 50) && !ok) {
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/clone/npc/feizei");
			if (ob->move(room)) {
				message("channel", HIR"【官府】:"HIY"听说有飞贼在"+HIG+path_where+HIY"一带出没，请留心自身财物安全！"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼生成失败。"NOR);
		}
	}
   if ((s == 50) && !ok) {
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/clone/npc/feizei");
			if (ob->move(room)) {
				message("channel", HIR"【官府】:"HIY"听说有飞贼在"+HIG+path_where+HIY"一带出没，请留心自身财物安全！"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼生成失败。"NOR);
		}
	}
	if ((s == 50) && !ok) {
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/clone/npc/feizei");
			if (ob->move(room)) {
				message("channel", HIR"【官府】:"HIY"听说有飞贼在"+HIG+path_where+HIY"一带出没，请留心自身财物安全！"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				call_out("remove_npc", 120, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼生成失败。"NOR);
		}
	}
   if ((s == 50) && !ok) {
		if (!room = do_copy())
			room = do_copy();
		else {
			ob = new("/clone/npc/feizei");
			if (ob->move(room)) {
				message("channel", HIR"【官府】:"HIY"听说有飞贼在"+HIG+path_where+HIY"一带出没，请留心自身财物安全！"NOR"\n", users());
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼出现了。"+ZJURL("cmds:goto "+file_name(ob))+"飞过去"+NOR"。");
				ok = 1;
				call_out("remove_npc", 240, ob);
			} else
				CHANNEL_D->do_channel( this_object(), "sys", "飞贼生成失败。"NOR);
		}
	}

	if ((h == 18) && (s == 0) && !ok1) {
		clear_special();
		ok1 = 1;
	}

	if (s!=50) ok = 0;
	if (!(h==18&&s==0)) ok1 = 0;
}

void remove_npc(object ob)
{
	if (ob) {
		ob->force_me("say 这鬼地方真穷，没什么油水可捞，还是回家吧！\n");
		destruct(ob);
	}
}

protected void heart_beat()
{	
	check_time();
}