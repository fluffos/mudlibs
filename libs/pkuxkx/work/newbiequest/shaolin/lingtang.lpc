// 灵堂，主要是为超度任务开发使用
// seagate@pkuxkx 2010/10/12

inherit ROOM;
inherit "/newbiequest/book";

#define BOOK_PATH "/newbiequest/book/"
#include <ansi.h>
protected int absolute_value(int x);

void create()
{
        set("short", "灵堂");
        set("long", @LONG
灵堂正中立着死者的画像，旁边有几个人跪着那里悲伤地哭泣，
两边放满了亲朋好友送过来的花圈，有几个请来的高僧正在为死者超
度(release)。
LONG);

        setup();
}

void init()
{
	if(userp(this_player())&&!this_player()->query_temp("channels")) {
		tell_object(this_player(), "灵堂之中一切消息暂时无法收听，如果出现意外请自行打开消息频道。\n");
	  this_player()->set_temp("channels",this_player()->query("channels"));
	  this_player()->set("channels", ({}));
	}
	add_action("do_release", "release");
}

void showPage(object me)
{
	int budlvl,page;
	string title;
	
	if(!me->query_skill("buddhism", 1))
		budlvl=0;
	else
		budlvl=me->query_skill("buddhism", 1);
	
	page=this_object()->query("release/page");
	if(budlvl>100) budlvl=100;
	
	if(page>5)
		page=page-random(5-budlvl/20);
	else
		page=page+random(5-budlvl/20);
	
	if ( !page )
	  page=1;
	
	title=read_file(BOOK_PATH+this_object()->query("release/book")+".txt",page*3,1);
	tell_object(me, "你观察了一下其他人的诵经进度，发现大家可能在诵唱"+HIY+title+NOR+"。\n");
}

//超度命令分为三个选项：start，check，end，
//start表示房间里面的僧侣开始进行诵经
//check为检查房间里面僧侣的诵经进度以便自己可以跟上进度
//end为结束房间里面僧侣的诵经
//超度与是否领任务无关，但是要想拿到奖励就必须有任务在身。
int do_release(string arg)
{
	object me,ob,ob2;
	string *args;
	string *books=({
		"阿含经",
		"般若经",
		"大般涅磐经",
		"法华经",
		"华严经",
		"金刚经",
		"维摩经",
		"无量寿经"});
	int page,maxPage,currPage,ckBook;
	int randPage;
	
	if(!arg) {
		printf(@LONG
    超度的命令格式为release start|check|end|chanting，其中start为开
始超度，check为检查目前超度的经卷进度，后面可以跟数字表示具体页数，但是
必须你知道是在用哪一种经卷进行超度的情况下才能跟数字猜测具体是哪一页。
end是在你超度完以后执行该命令进行任务收尾。chanting为你知道高僧超度时候
具体念诵的经文位置以后，在大家念新一段开始的阶段可以念诵跟上进度，后面跟
数字决定你应该具体念诵的页码。
LONG);
    return 1;
  }
  
  me=this_player();
  ob=this_object();
  args=explode(arg, " ");
  
  randPage=4+random(2);
  switch(args[0]) {
//选择start的时候房间里开始出现诵经声音，随机选择一本书，并且从前面一半页面中随机选择一页作为开始
  	case "start":
  		if(me->query("class")!="bonze") {
  			printf("只有僧侣才能参加这场法事！\n");
  			return 1;
  		}
  		else if(query("release/chanting")&&time()-query("release/chanttime")<180) {
  			printf("法事正在进行中，你要不加入这场法事，要不等别人法事做完再重新开始。\n");
  			return 1;
  		}
  		else if(query("release")&&time()-query("release/starttime")<240) {
  			printf("你要等这场法事做完以后才能进行下一场法事！\n");
  			return 1;
  		}
  		
  		ob->set("release/book", books[random(1000)%sizeof(books)]);
  		ob->set("release/page", random(get_pages(ob->query("release/book"))/2));
  		ob->set("release/starttime", time());
  		tell_room(ob, "请来的高僧开始拿着手里的"+HIY+ob->query("release/book")+NOR+"诵起经文来，后来的僧侣请注意跟上整个诵经的节奏！\n");
  		remove_call_out("pure_chanting");
  		pure_chanting(ob, ob->query("release/book"), ob->query("release/page"), 22, 1, 3);
  		me->start_busy(1);
  		call_out("showPage",5,me);
  		break;
//如果什么也不加按照上中下三卷的原则告诉超度念经是在上卷经书还是中卷经书还是下卷经书
//如果加上数字以后100以外和上面提示一样，50-100，10-50，0-10分成三种提示。
  	case "check":
  		if(sizeof(args)>=2&&!sscanf(args[1],"%d",page)) {
  			printf("在检查诵经进度的时候后面跟着数字或者什么都不写。\n");
  			return 1;
  		}
  		else if(me->is_busy()||me->is_fighting()) {
  			printf("你现在正忙着呢。\n");
  			return 1;
  		}
  		else if(!ob->query("release/book")||!ob->query("release/page")) {
  			printf("法事还没有开始，等法事开始后才能检查他人的诵经进度。\n");
  			return 1;
  		}
  				
  		maxPage=get_pages(ob->query("release/book"));
  		currPage=query_pureChanting("page");
  		if(sizeof(args)==1||absolute_value(currPage-page)>100) {
  			if(currPage<=maxPage/3)
  				tell_object(me,HIC"你偷偷的看了一眼别人翻开的经书，发现正在诵唱上半卷经书！\n"NOR);
  			else if(currPage>maxPage/3&&currPage<=(maxPage*2)/3)
  				tell_object(me,HIC"你偷偷的看了一眼别人翻开的经书，发现正在诵唱中间半卷经书！\n"NOR);
  			else if(currPage>(maxPage*2)/3)
  				tell_object(me,HIC"你偷偷的看了一眼别人翻开的经书，发现正在诵唱下半卷经书！\n"NOR);
  		}
  		else if(absolute_value(currPage-page)<=50&&absolute_value(currPage-page)>20)
  			tell_object(me, HIG"你偷偷的看了看别人念诵的经书，发现和你猜的差距不是特别大。\n"NOR);
  		else if(absolute_value(currPage-page)<=20&&absolute_value(currPage-page)>randPage)
  			tell_object(me, HIY"你偷偷的看了看别人念诵的经书，发现和你猜的已经比较接近了。\n"NOR);
  		else if(absolute_value(currPage-page)<=randPage)
  			tell_object(me, HIR"你偷偷的看了看别人念诵的经书，发现和你猜的已经非常接近了。\n"NOR);
  		me->start_busy(1);
  		break;
//选择end的时候房间里面结束诵经声音。
  	case "end":
  		if(me->query_temp("quest_release/page")&&me->query_temp("quest_release/page")!=query_pureChanting("page")) {
  			tell_object(me, "你跟着高僧们念完了一整段经书，完成了"+ me->query_temp("quest_release/promoter")+"交代的任务。\n");
  			me->set_temp("quest_release/success",1);
  		}
  		me->start_busy(1);
  		if(me->query_temp("quest_release/success")) {
  			ob->delete("release");
  			remove_call_out("pure_chanting");
  			tell_room(ob, "高僧们念完了一段"+HIY+ob->query("release/book")+NOR+"，开始歇息等着下一场法事。\n");
  		}
  		else
  			tell_room(ob, "法事还没有做完呢，不用着急休息！\n"); 
  		break;
//诵经的时候由于是跟着大家一起念诵，所以自己本身不需要发出特殊的念诵声音。
//只需要找到节奏跟对了就行。
  	case "chanting":
  		if(sizeof(args)==1) {
  			printf("诵经的时候必须跟上诵经的页数！\n");
  			return 1;
  		}
  		else if(sizeof(args)>=2&&!sscanf(args[1],"%d",page)) {
  			printf("在诵经的时候后面必须跟页数。\n");
  			return 1;
  		}
  		else if(me->is_busy()||me->is_fighting()) {
  			printf("你现在正忙着呢。\n");
  			return 1;
  		}
  		
  		ckBook=0;
  		foreach(ob2 in all_inventory(me)) { 
  			if(ob2->query("id")=="shu" && ob2->query("name")==ob->query("release/book")) {
  				ckBook=1;
  				break;
  			}
  		}
  		
  		if(!ckBook) {
  			printf("你手上没拿着"+HIG+ob->query("release/book")+NOR+"就来做法事了？\n");
  			return 1;
  		}
  		else if(page!=query_pureChanting("page")) {
  			printf("你翻的和别人念的不是一页经书，没法跟别人一起做法事。\n");
  			return 1;
  		}
  		else if(query_pureChanting("font")>=5) {
  			printf("只有在念诵一段开始的时候才能和别人一起做法事！\n");
  			return 1;
  		}
  		
  		tell_object(me, "你偷偷的看了看别人的经书，连忙将经书翻到念诵的哪一页，开始做起了法事！\n");
  		if(me->query_temp("quest_release/start"))
  			me->set_temp("quest_release/page",page);
  		me->start_busy(3600);
//设置诵经的时候，在你诵经开始的3分钟内不允许别人重新开始一场新的法事
  		ob->set("release/chanting",1);
  		ob->set("release/chanttime",time());
  		break;
  	default:
  		printf(@LONG
    超度的命令格式为release start|check|end|chanting，其中start为开
始超度，check为检查目前超度的经卷进度，后面可以跟数字表示具体页数，但是
必须你知道是在用哪一种经卷进行超度的情况下才能跟数字猜测具体是哪一页。
end是在你超度完以后执行该命令进行任务收尾。chanting为你知道高僧超度时候
具体念诵的经文位置以后，在大家念新一段开始的阶段可以念诵跟上进度，后面跟
数字决定你应该具体念诵的页码。
LONG);
  }
  return 1;
}

int valid_leave(object me, string dir)
{
	if(userp(this_player())&&this_player()->query_temp("channels")) {
    tell_object(this_player(), "离开灵堂所有消息频道恢复正常。\n");
	  this_player()->set("channels",this_player()->query_temp("channels"));
	  this_player()->delete_temp("channels");
	}
  return ::valid_leave(me, dir);
}

protected int absolute_value(int x) {
	if(x>-1) 
		return x;
	else 
		return -x;
}