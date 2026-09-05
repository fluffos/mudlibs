//book.c
//书籍（主要针对佛经之类），有翻页，朗诵两大功能，书籍默认来源于/p/shaolin/下面同汉字名的文件
//以后如果公共处理如何取消差异性还没想好。等迁移过去再说吧。
//seagate@pkuxkx 2010/10/09

#include <ansi.h>
#define BOOK_PATH "/newbiequest/book/"

public void chanting(object,int,int,string);
int get_pages(string name);
protected int chantSec, chantPage, chantFontRate, chantFont;      
//分别代表时间间隔，朗诵页，朗诵速率（每间隔字数），位置。其中速率100为每次一行

void init()
{
	int maxPage;
//为了当铺修改的，由于当铺会修改书名
	if(this_object()->query("pages")) {
		maxPage=get_pages(this_object()->query("name"));
		if(maxPage!=this_object()->query("pages"))
			this_object()->set("pages",maxPage);
	}
	add_action("do_page", "page");
	add_action("do_pagedown", "pagedown");
	add_action("do_pageup", "pageup");
	add_action("do_chanting", "chanting");
}

/*从经书的第一行中取出这本经书的页数*/
int get_pages(string name)
{
	string jingHead,*head;
	int maxPage,rt;
  
	jingHead=read_file(BOOK_PATH+name+".txt",1,1);
	if(!jingHead)return 0;
	head=explode(jingHead,"#");
	rt=sscanf(head[1],"%d",maxPage);
	return maxPage;
}

/*根据输入的页数显示当前页的经书内容。*/
int do_page(string arg)
{
	string jing,head;
	int pageNo,maxPage,lines,lp;

	if(environment() != this_player()) return 0;
//当输入页数的时候直接翻到当前页数，否则翻到经书默认已经翻到过的页数	
	maxPage=this_object()->query("pages");
	if(nullp(arg))
		pageNo=this_object()->query("page");
	else if(!sscanf(arg,"%d",pageNo)) {
		notify_fail("请输入想看的经书页数。\n");
		return 0;
	}
	
	if(pageNo>maxPage) {
		notify_fail("这本"+this_object()->query("name")+"一共只有"+chinese_number(maxPage)+"页！\n");
		return 0;
	}
	else if(pageNo<1) {
		notify_fail("你最少要从第一页开始翻起。\n");
		return 0;
	}

//取出该页的标题和内容，内容按照10个字一行的格式显示
	jing=read_file(BOOK_PATH+this_object()->query("name")+".txt",1+pageNo*3,1);
	head=read_file(BOOK_PATH+this_object()->query("name")+".txt",pageNo*3,1);
	
	if((sizeof(jing)-1)%20==0)
		lines=(sizeof(jing)-1)/20;
	else
		lines=(sizeof(jing)-1)/20+1;
	
	tell_object(this_player(),HIG+head+NOR);
	tell_object(this_player(),YEL"================================================================\n"NOR);
	tell_object(this_player(),YEL"==                                                            ==\n"NOR);
	for(lp=1;lp<=lines;lp++) {
		if(lp==lines)
			tell_object(this_player(),YEL"=="NOR+sprintf("%20s%-20s%20s"," ",jing[20*(lp-1)..sizeof(jing)-2]," ")+YEL"==\n"NOR);
		else
			tell_object(this_player(),YEL"=="NOR+sprintf("%20s%-20s%20s"," ",jing[20*(lp-1)..20*lp-1]," ")+YEL"==\n"NOR);
	}
	tell_object(this_player(),YEL"==                                                            ==\n"NOR);
	tell_object(this_player(),YEL"================================================================\n"NOR);
	tell_object(this_player(),HIY+sprintf("%-20s%44s",this_object()->query("name"),"第"+chinese_number(pageNo)+"页/总"+chinese_number(maxPage)+"页")+"\n"NOR);
	tell_object(this_player(),HIY"上一页(pageup)/下一页(pagedown)                   诵经(chanting)\n"NOR);
  this_object()->set("page",pageNo);
  
	return 1;
}

/*页数-1，再调do_page显示经书内容。*/
int do_pageup()
{
	int pageNo,rt;
	if(environment() != this_player()) return 0;
	pageNo=this_object()->query("page");
	if(pageNo==1) {
		notify_fail(HIR"这是首页！没法再往前翻了。\n"NOR);
		return 0;
	}
	else {
		pageNo--;
		return do_page(sprintf("%d",pageNo));
	}
}

/*页数+1，再掉do_page显示经书内容。*/
int do_pagedown()
{
	int pageNo,maxPage;
	if(environment() != this_player()) return 0;	
	pageNo=this_object()->query("page");
	maxPage=this_object()->query("pages");
	
	if(pageNo==maxPage) {
		notify_fail(HIR"这是尾页！没法再往后翻了。\n"NOR);
		return 0;
	}
	else {
		pageNo++;
		return do_page(sprintf("%d",pageNo));
	}
	return 1;
}

/*基本上进行一大堆合法性检查以后开始调用函数chanting开始念经。合法性检查包括命令格式、诵唱的经书指定页、
  精神是否饱满、是否在干别的事情、是否读书识字、特定任务接口等等
  其中特定任务接口需要书籍实现int quest_chanting函数和void success_chanting函数，分别对应诵唱开始
  的时候任务合法性检查和诵唱结束的时候置任务成功标志。success_chanting函数在完成任务以后置标志方便
  后续任务流程识别。*/
int do_chanting(string arg)
{
	string *args,jing;
	mapping *chanting,chantBuf;
	int pageNo;
	if(environment() != this_player()) return 0;	
	if(!arg)
		return notify_fail("诵经的格式是"+HIW"chanting 页数 经文内容"NOR+"。\n");

	args=explode(arg," ");
	
	if(sizeof(args)!=2) {
		notify_fail("诵经的格式是"+HIW"chanting 页数 经文内容"NOR+"。\n");
		return 0;
	}
	else if(!sscanf(args[0],"%d",pageNo)) {
		notify_fail("你指定了错误格式的经书页数。经书页数只能是数字。\n");
		return 0;
	}
	else if(pageNo<1||pageNo>this_object()->query("pages")) {
		notify_fail("你至少要从第一页开始指定，"+HIG+this_object()->query("name")+NOR+"一共有"+chinese_number(this_object()->query("pages"))+"页经书。\n");
		return 0;
	}
	else if(this_player()->query("jing")<this_player()->query("max_jing")*80/100) {
		notify_fail("你太疲劳了，请休息一会儿再诵经吧。");
		return 0;
	}
	else if (this_player()->is_busy()) {
		notify_fail("你现在正忙着呢。\n");
		return 0;
	}
	else if (this_player()->is_fighting()) {
		notify_fail("你无法在战斗中专心诵唱！\n");
		return 0;
	}
	else if( !this_player()->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
	else if(!nullp(this_player()->query_temp("chanting"))&&arrayp(this_player()->query_temp("chanting"))) {
		chanting=this_player()->query_temp("chanting");
		foreach(chantBuf in chanting)
			if(chantBuf["book"]==this_object()->query("name")&&chantBuf["page"]==pageNo)
				return notify_fail("你总不能就这几页翻来覆去的诵唱吧？\n");
	}
	
	if(!this_object()->quest_chanting(pageNo))
    return 1;

	jing=read_file(BOOK_PATH+this_object()->query("name")+".txt",1+pageNo*3,1);
	if(jing[sizeof(jing)-1]=='\n')
		jing=jing[0..sizeof(jing)-2];
	
	if(args[1]!=jing) {
		notify_fail("你诵经的内容和"+HIG+this_object()->query("name")+NOR+"中第"+chinese_number(pageNo)+"页中经书内容不符。\n");
		return 0;
	}
//朗诵之前tune all
  if(!this_player()->query_temp("channels")) {
  	tell_object(this_player(), "朗诵经文之前要心无外物，一切消息暂时无法收听，如果出现意外请自行打开消息频道。\n");
	  this_player()->set_temp("channels",this_player()->query("channels"));
	  this_player()->set("channels", ({}));
	}
	this_player()->start_busy(10);
	chanting(this_player(), pageNo,1,jing);
	
	return 1;
}

//纯粹的朗诵接口函数，接口为
//me               --当前玩家
//book             --书名，不需要加后缀，强制性后缀.txt，强制性书籍路径BOOK_PATH变量定义指定目录
//page             --页号
//chantClass       --朗诵级别，代表朗诵语速，0代表非开始朗诵，沿用上一个朗诵级别，正常朗诵级别为两位数字
//                   第一位数字代表时间间隔，第二位数字代表间隔内朗诵字数，其中第二位是X代表一次朗诵一页。
//                   朗诵级别可以为数字或者字符串。
//autopage         --1或者0，表示是否自动换页朗诵
//objecttype       --对象me的类型，1 表示为npc 2 表示为玩家 3 表示为room
void pure_chanting(object me, string book, int page, mixed chantClass, int autopage, int objecttype)
{
	string row;
	int maxPage,lp,native;
	
	if(file_size(BOOK_PATH+book+".txt")<0)
		error(BOOK_PATH+book+".txt并不存在！");
	maxPage=get_pages(book);
	if(page>maxPage)
		error(BOOK_PATH+book+".txt一共只有"+chinese_number(maxPage)+"页。");
	
	if((intp(chantClass)&&(chantClass<0||chantClass>100))||
		 (stringp(chantClass)&&(sizeof(chantClass)>2||
		  sizeof(chantClass)==0||chantClass[0]<'0'||chantClass[0]>'9'||
		  (sizeof(chantClass)==2&&(chantClass[1]<'0'||chantClass[1]>'9')&&
		   chantClass[1]!='X'))))
		error("朗诵级别只能是两位数字或者1位数字1位'X'。\n");
	else if(!intp(chantClass)&&!stringp(chantClass))
		error("朗诵级别只能是数字或者字符串。\n");

  native=0;
	if(intp(chantClass)&&chantClass>0) {
		if(chantClass<10)
			error("朗诵级别不能是1位非0数字。\n");
		chantSec=chantClass/10;
		chantFontRate=chantClass%10;
		if(!chantFontRate)
			chantFontRate=1;
		chantFont=0;
		native=1;
		chantPage=page;
	}
	else if(stringp(chantClass)&&chantClass!="0") 
	{
		if(sizeof(chantClass)==1)
			error("朗诵级别不能是1位非0字符。\n");

		if(chantClass[1]=='X') {
			chantFontRate=100;
			if(!sscanf(chantClass, "%dX", chantSec))
				error("非法的朗诵级别"+chantClass+"。\n");
		}
		else {
			chantSec=chantClass[0]-'0';
			chantFontRate=chantClass[1]-'0';
		}
		chantFont=0;
		native=1;
		chantPage=page;
	}
	else if(!chantSec||!chantFontRate)
			error("未对朗诵级别作定义，没有可采用的默认朗诵级别。\n");
	
	row=read_file(BOOK_PATH+book+".txt", 1+page*3, 1);
	if(!row)
		error(BOOK_PATH+book+".txt没有这么多行数据，读取该书第"+chinese_number(page)+"页失败。\n");

	if(chantFontRate==100) {
		switch(objecttype) {
			case 1:
				tell_room(environment(me), row+"\n");
				if(page+1>maxPage) {
					tell_room(environment(me), HIG+"\n"+book+"已经整个朗诵完毕了。\n"+NOR);
					return;
				}
				break;
			case 2:
			  tell_object(me, row+"\n");
				if(page+1>maxPage) {
					me->start_busy(1);
					tell_object(me, HIG+"\n"+book+"已经整个朗诵完毕了。\n"+NOR);
					return;
				}
			  break;
			case 3:
			  tell_room(me, row+"\n");
				if(page+1>maxPage) {
					tell_room(me, HIG+"\n"+book+"已经整个朗诵完毕了。\n"+NOR);
					return;
				}
			  break;
			default:
				error("对象类型仅支持1（npc）、2（玩家）、3（房间）。\n");
		}
		chantPage++;
		if(objecttype==2)
			me->start_busy(chantSec+2);
		remove_call_out("pure_chanting");
		call_out("pure_chanting", chantSec, me, book, page+1, 0, autopage, objecttype);
		return;
	}
	else {
		for(lp=0;lp<chantFontRate;lp++) {
			switch(objecttype) {
				case 1:
					tell_room(environment(me), row[chantFont*2..chantFont*2+1]+".");
					break;
				case 2:
			  	tell_object(me, row[chantFont*2..chantFont*2+1]+".");
			  	break;
				case 3:
			  	tell_room(me, row[chantFont*2..chantFont*2+1]+".");
			  	break;
				default:
					error("对象类型仅支持1（npc）、2（玩家）、3（房间）。\n");
			}
			chantFont++;
			if((chantFont+1)*2>sizeof(row)-1) {
				if(!autopage)
					return;
				else {
					switch(objecttype) {
						case 1:
							if(page+1>maxPage) {
								tell_room(environment(me), HIG+"\n"+book+"已经整个朗诵完毕了。\n"+NOR);
								return;
							}
							tell_room(environment(me), HIG+"\n"+book+"又翻了一页。\n"+NOR);
							break;
						case 2:
							if(page+1>maxPage) {
								me->start_busy(1);
								tell_object(me, HIG+"\n"+book+"已经整个朗诵完毕了。\n"+NOR);
								return;
							}
							tell_object(me, HIG+"\n"+book+"又翻了一页。\n"+NOR);
			  			break;
						case 3:
							if(page+1>maxPage) {
								tell_room(me, HIG+"\n"+book+"已经整个朗诵完毕了。\n"+NOR);
								return;
							}
							tell_room(me, HIG+"\n"+book+"又翻了一页。\n"+NOR);
			  			break;
						default:
							error("对象类型仅支持1（npc）、2（玩家）、3（房间）。\n");
					}
					chantPage++;
					chantFont=0;
					if(objecttype==2)
						me->start_busy(chantSec+2);
					remove_call_out("pure_chanting");
					call_out("pure_chanting", chantSec, me, book, page+1, 0, autopage, objecttype);
					return;
				}
			}
		}
	}
	
	if(objecttype==2)
		me->start_busy(chantSec+2);
	remove_call_out("pure_chanting");
	call_out("pure_chanting", chantSec, me, book, page, 0, autopage, objecttype);
}

//查询纯粹朗读函数pure_chanting现在读到哪一页，哪一个字
//其中item=page查询读到哪一页
//    item=font查询读到哪一个字
int query_pureChanting(string item)
{
	if(item=="page")
		return chantPage;
	else if(item=="font")
		return chantFont;
	else
		return 0;
}

//诵完整段经书以后获得比正常读书最高等级高50级的经验限制。
//经验获得计算和先天悟性、经书长度有关系，消耗的精神也和经书长度有关。
//按照先天悟性30，经书长度120字节来计算，2分钟获得经验差不多是(120+120+30*2)*10=3000经验。
public void chanting(object me, int pageNo,int fontNo,string jing)
{
	mapping skill,chanting,*result;
	string questTest;
	int lp;
	
	if ( !objectp(me) )
	  return;
	
	if(fontNo==1)
		tell_room(environment(me),me->query("name")+"拿起了"+HIG+this_object()->query("name")+NOR+"，翻到了第"+
		              HIW+chinese_number(pageNo)+NOR+"页，慢慢的诵唱：\n");
  
  tell_room(environment(me),HIC+jing[(fontNo-1)*2..(fontNo-1)*2+1]+".."NOR);
  if((fontNo+1)*2>sizeof(jing)) {
  	questTest=function_exists("success_chanting",this_object());

    if(me->query_temp("channels")) {
    	tell_object(me, "朗诵经文已经结束，消息频道恢复正常。\n");
	    me->set("channels",me->query_temp("channels"));
	    me->delete_temp("channels");
	  }
  	
  	me->receive_damage("jing",(int)sizeof(jing)/5);
  	me->start_busy(1);
  	
  	if(nullp(me->query_temp("chanting"))||!arrayp(me->query_temp("chanting")))
  		result=({});
  	else
  		result=me->query_temp("chanting");
  	
  	chanting=([]);
  	chanting["book"]=me->query("name");
  	chanting["page"]=pageNo;
  	result=result+({chanting});
  	if(sizeof(result)>30)
  		result=result-({result[0]});
  	me->set_temp("chanting",result);

  	skill=this_object()->query("skill");
  	if(me->query_skill(skill["name"], 1)>skill["max_skill"]+50) {
  		notify_fail("你的"+WHT+to_chinese(skill["name"])+NOR+"已经非常高深了，已经不能通过诵唱"+HIG+this_object()->query("name")+NOR+"获得提高。\n");
  		if(sizeof(questTest))
  			this_object()->success_chanting();
  		return 0;
  	}
  	else if(me->query_skill(skill["name"], 1)<skill["min_skill"]) {
  		notify_fail(HIG+this_object()->query("name")+NOR+"对你来说过于晦涩，你怎么都无法理解它所包含的深意。\n");
  		if(sizeof(questTest))
  			this_object()->success_chanting();
  		return 0;
  	}
  	tell_room(environment(me),"\n你诵唱完了整段经书，对"+WHT+to_chinese(skill["name"])+NOR+"的理解又进了一步。\n");
  	for(lp=0;lp<(int)me->query("int")/3;lp++)
  		me->improve_skill(skill["name"], 120+random(sizeof(jing))*2+random(me->query("int"))*4);
  	if(sizeof(questTest))
  		this_object()->success_chanting();
  }
  else {
  	me->start_busy(3);
  	remove_call_out("chanting");
  	call_out("chanting",2,me, pageNo,fontNo+1,jing);
  }
}