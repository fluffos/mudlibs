// danfang.c
// seagate@pkuxkx 2010/10/31

#include <ansi.h>
inherit ROOM;

string *fire_color=({HIY, HIM, HIR, HIC});

string look_lu();
void create()
{
  set("short", "丹房");
  set("long", @LONG
自从俞岱岩遭奸人所害以后就开始醉心于炼丹术，武当派从
扬州王铁匠哪里专门定制了一座重达三千多斤的全身精铜打制而
成的炼丹炉(lu)，专供三侠闲暇时候炼丹研究药理使用。清风明
月两个道童正看守着炼丹炉。
LONG);

  set("exits", ([
	  "north" : __DIR__"yudaiyan"
  ]));

  set("item_desc", ([
  "lu" : (:look_lu:)
  ]));

	set("objects",([
		CLASS_D("wudang") +"/qingfeng" : 1,
		CLASS_D("wudang") +"/mingyue" : 1,
		]));
  
  setup();
}

/*这里是炼丹的函数主体部分，主要使用玩家状态query_temp("quest_liandan");
  炼丹分为以下几个步骤：首先使用命令zuo坐在一个蒲垫上，然后使用命令kan
  开始看守丹炉，看守的时候丹炉炉火会随机减弱，这时候需要用命令change来
  调整炉火。相关状态如下：
  zuoflag                 --是否坐在蒲垫上
  allow_shou              --是否在俞岱岩哪里领了看守丹炉任务
  shouflag                --是否在看守丹炉
  shou_flag               --炉火的状态（0-3），3最强，不需要调整，0最弱
  lu_color                --炉火的颜色 从最弱的黄色开始，紫色，红色一直到青色
  change_flag             --需要调整的强度，0不需要调整，最大调整强度3
  shou_fail               --看守炉火失败了，在炉火开太大导致爆炸或者炉火太弱导致丹药出问题两种情况
  shou_success            --看守炉火成功，丹药炼成了！这时候可以回去找俞岱岩了结任务
*/
void init()
{
	add_action("do_zuo","zuo");
	add_action("do_zhan","zhan");
	add_action("do_shou","kan");
	add_action("do_chang","change");
}

string look_lu()
{
	string desc;
	
	desc=read_file("/newbiequest/wudang/liandanlu.txt");
	if(!this_player()->query_temp("quest_liandan/lu_color"))
		desc=replace_string(desc,"^",HIG+"^"+NOR);
	else
		desc=replace_string(desc,"^",this_player()->query_temp("quest_liandan/lu_color")+"^"+NOR);
	desc+=RED+"\n炼丹炉旁边有一个坐垫让你盘膝而坐(zuo)看守(kan)丹炉，丹炉上有一个开关可以调节(change)炉火大小。\n"+NOR;
	return desc;
}

int do_zuo()
{
	
	this_player()->set_temp("quest_liandan/zuoflag",1);
	write("你盘膝坐到丹炉旁边的坐垫上，开始准备看守(kan)丹炉，如果坐累了可以站(zhan)起来走走。\n");
	return 1;
}

int do_zhan()
{
	if(this_player()->is_busy()) {
		printf("你现在正忙着呢。\n");
		return 1;
	}
	else if(!this_player()->query_temp("quest_liandan/zuoflag")) {
		printf("你本来就是站立着的！\n");
		return 1;
	}
		
	this_player()->delete_temp("quest_liandan/zuoflag");
	write("你从坐垫上站起来。\n");
	return 1;
}

int do_shou()
{
	object me,oth;
	me=this_player();
	
	if(!me->query_temp("quest_liandan/zuoflag")) {
		printf("你要先坐下才能开始看守(kan)丹炉。\n");
		return 1;
	}
	if(me->is_busy()||me->is_fighting()) {
		printf("你现在正忙着呢。\n");
		return 1;
	}
	if(!me->query_temp("quest_liandan/allow_shou")) {
		printf("俞岱岩急急忙忙跑过喊道：我还没有开始炼丹呢，不要着急。\n");
		return 1;
	}
//	if(query("shou_player")&&(oth=present(query("shou_player"),this_object()))) {
//		printf("丹炉正有人用着呢，等一会儿再来吧！\n");
//		return 1;
//	}
	if(me->query_temp("quest_liandan/shouflag")) {
		printf("你已经在看守丹炉了！\n");
		return 1;
	}
	
	me->start_busy(63);
	write("你开始看守丹炉的火候，请根据炉火状态随时使用阀门调整(change)调整炉火大小！\n");
	write("从现在开始每10秒钟就要看一次丹炉火候，炉火是青色的时候就不需要调整，其他颜色都需要调整。\n");
	write("炉火颜色从青色->红色->紫色->黄色以此降低，相应调整幅度也一次加大。\n");
	write("炉火的调整(change)分为大(H)、中(M)、小(L)三档，请根据丹炉火候作出相应调整。\n");
	write("每次调整炉火颜色都会发生变化，如果调整出错就会导致丹炉爆炸！\n");
	write(HIC+"炉火现在烧得正旺，请注意观察此刻的炉火，以后炉火有变化都要调整到这个程度！\n"+NOR);
	me->set_temp("quest_liandan/shouflag",1);
//	set("shou_player", me->query("id"));
	me->set_temp("quest_liandan/shou_flag",3);
	me->set_temp("quest_liandan/lu_color",fire_color[3]);
	me->set_temp("quest_liandan/change_flag",0);
	write(look_lu());
//	remove_call_out("in_shou");
	call_out("in_shou",15,me);
	return 1;
}

int do_chang(string arg)
{
	mapping chgLevel=(["H":3,"M":2,"L":1]);
	int level;
	object me;
	
	me=this_player();
	if(!me->query_temp("quest_liandan/shouflag"))
		return notify_fail("你没有在看守丹炉，不能进行炉火调整！\n");
	else if(!arg)
		return notify_fail("调整炉火的命令是change [H|M|L]分别对应大中小三档火候调整。\n");
	else if(arg!="H"&&arg!="M"&&arg!="L")
		return notify_fail("调整炉火的命令是change [H|M|L]分别对应大中小三档火候调整。\n");
	
	level=chgLevel[arg];
	me->set_temp("quest_liandan/shou_flag", me->query_temp("quest_liandan/shou_flag")+level);
	me->set_temp("quest_liandan/change_flag", me->query_temp("quest_liandan/change_flag")-level);
	if(me->query_temp("quest_liandan/shou_flag")>=4) {
		write("你将丹炉火候调整的过大了，只见丹炉『轰～～～』一声爆炸了！\n");
		me->delete_temp("quest_liandan/shouflag");
//		remove_call_out("in_shou");
		me->add_busy((-1)*me->query_busy());
		me->delete_temp("quest_liandan/allow_shou");
		me->delete_temp("quest_liandan/zuoflag");
		me->set_temp("quest_liandan/shou_fail",1);
		me->delete_temp("quest_liandan/shou_flag");
		me->delete_temp("quest_liandan/change_flag");
		me->delete_temp("quest_liandan/lu_color");
		me->unconcious();
		return 1;
	}
	else
		me->set_temp("quest_liandan/lu_color",fire_color[me->query_temp("quest_liandan/shou_flag")]);

	write("你将炉火稍微往大调整了一番，似乎炉火烧的更旺了！\n");
	return 1;
}

void in_shou(object me)
{
	if(me->query_temp("quest_liandan/change_flag")>0&&me->query_temp("quest_liandan/lu_color")!=HIC) {
		write("你没有看好丹炉，发现里面的丹药已经结块了，看来这炉丹药已经废了，到俞岱岩哪里领罚吧！\n");
		me->delete_temp("quest_liandan/shouflag");
//		remove_call_out("in_shou");
		me->add_busy((-1)*me->query_busy());
		me->delete_temp("quest_liandan/allow_shou");
		me->set_temp("quest_liandan/shou_fail",1);
		me->delete_temp("quest_liandan/shou_flag");
		me->delete_temp("quest_liandan/change_flag");
		me->delete_temp("quest_liandan/lu_color");
		return;
	}
	else if(me->query_busy()<15) {
		write(HIY+"丹炉里传出来一阵清香，看来已经成丹了！赶紧向俞岱岩报告！\n"+NOR);
		me->set_temp("quest_liandan/shou_success",1);
		me->delete_temp("quest_liandan/shouflag");
		me->delete_temp("quest_liandan/allow_shou");
//		remove_call_out("in_shou");
		me->add_busy((-1)*me->query_busy());
		me->delete_temp("quest_liandan/shou_flag");
		me->delete_temp("quest_liandan/change_flag");
		me->delete_temp("quest_liandan/lu_color");
		return;
	}
	
	me->set_temp("quest_liandan/shou_flag",random(4));
	me->set_temp("quest_liandan/lu_color",fire_color[me->query_temp("quest_liandan/shou_flag")]);
	me->set_temp("quest_liandan/change_flag",3-me->query_temp("quest_liandan/shou_flag"));
	write(look_lu());
	if(!me->query_temp("quest_liandan/change_flag"))
		write(HIY+"炉火燃烧地正旺，不需要作任何调整！\n"+NOR);
	else
		write(HIC+"炉火似乎正在慢慢减弱，赶紧查看火候作出相应调整吧！\n"+NOR);
//	remove_call_out("in_shou");
	call_out("in_shou",15,me);
}

int valid_leave(object me, string dir)
{
  if(me->query_temp("quest_liandan/zuoflag"))
  	return notify_fail("你现在坐在坐垫上没法行动！\n");
  else
  	return ::valid_leave(me, dir);
}