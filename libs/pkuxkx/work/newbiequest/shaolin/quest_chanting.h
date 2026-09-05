//fojing.h
//诵经任务头文件。处理和任务相关内容
// seagate@pkuxkx 2010/10/09

#include <ansi.h>
#define BOOK_PATH "/newbiequest/book/"

//获得诵经任务状态
int quest_chanting(int pageNo)
{
	mapping result=([]);

	if(mapp(this_player()->query_temp("quest_chanting"))) {
		result["room"]=this_player()->query_temp("quest_chanting/room");
		result["name"]=this_player()->query_temp("quest_chanting/name");
		result["book"]=this_player()->query_temp("quest_chanting/book");
		result["title"]=this_player()->query_temp("quest_chanting/title");
		result["page"]=this_player()->query_temp("quest_chanting/page");
		
		if(result["room"]!=environment(this_player())->query("short")||
       result["book"]!=this_object()->query("name")||
       result["page"]!=pageNo) {
    		tell_object(this_player(),"任务"+MAG+result["name"]+NOR+"要求你拿着"+HIG+result["book"]+NOR+"在"+
    		      RED+result["room"]+NOR+"诵唱"+HIW+result["title"]+NOR+"。\n佛经可以从藏经楼找到或者找藏经楼的玄彦大师租借！\n");
        return 0;
      }
	}
	
	return 1;
}

//诵经任务成功置成功标志
//诵经任务完成能过获得额外的佛法奖励，并且诵经任务奖励的佛法等级比正常诵经等级再高50级，并且不受最小等级限制。
//不过诵经任务奖励的点数比诵经正常获得应该来说能够少一点，当然高级玩家是另外一回事。
//按照先天悟性30，读书写字100级，诵经的经书最高等级100级来计算，2分钟诵经获得经验差不多是(120+100+40*2)*10=3000这个量级。
void success_chanting()
{
	mapping skill;
	int lp;
	
	if(mapp(this_player()->query_temp("quest_chanting"))) {
		tell_object(this_player(), "你做完了"+this_player()->query_temp("quest_chanting/promoter")+"布置的功课，可以回去向他要奖赏了。\n");
		this_player()->set_temp("quest_chanting/success",1);
		skill=query("skill");
  	if(this_player()->query_skill(skill["name"], 1)<=skill["max_skill"]+100) {
  		for(lp=0;lp<(int)this_player()->query("int")/3;lp++)
  			this_player()->improve_skill(skill["name"], 120+skill["max_skill"]+random(this_player()->query_int())*4);
  	}
	}
}

string start_chanting(string name,string questid)
{
	string *books=({
		"阿含经",
		"般若经",
		"波罗蜜多心经",
		"大般涅磐经",
		"法华经",
		"华严经",
		"金刚经",
		"维摩经",
		"无量寿经"});
	string *rooms=({"西侧殿","东侧殿","天王殿","大雄宝殿","后殿","般若堂一部",
		              "般若堂二部","般若堂三部","般若堂四部","般若堂五部","般若堂六部",
		              "般若堂七部","般若堂八部","般若堂九部","罗汉堂一部","罗汉堂二部",
		              "罗汉堂三部","罗汉堂四部","罗汉堂五部","罗汉堂六部","罗汉堂七部",
		              "罗汉堂八部","罗汉堂九部","和尚院一部","和尚院二部","和尚院三部",
		              "和尚院四部","和尚院五部","和尚院六部","地藏殿","白衣殿","千佛殿",
		            	GRN"达摩洞"NOR});
	string head,*headBuf,book;
	int *lines,lp,rt,maxPage,totalPage,randPage;
	object me;
	mapping chanting;
	
	this_object()->newbieStart(name,questid);
	lines=allocate(sizeof(books));
	totalPage=0;
	me=this_player();
	chanting=([]);
	
	for(lp=0;lp<sizeof(books);lp++) {
		head=read_file(BOOK_PATH+books[lp]+".txt",1,1);
		headBuf=explode(head,"#");
		rt=sscanf(headBuf[1],"%d",maxPage);
		lines[lp]=maxPage;
		totalPage=totalPage+maxPage;
	}
	
	randPage=random(totalPage);
	for(lp=0;lp<sizeof(lines);lp++) {
		if(randPage<lines[lp]) {
			chanting["name"]=name;
			chanting["book"]=books[lp];
			chanting["page"]=randPage+1;
			chanting["success"]=0;
			chanting["title"]=read_file(BOOK_PATH+books[lp]+".txt",(randPage+1)*3,1);
			chanting["room"]=rooms[random(sizeof(rooms))];
			chanting["promoter"]=this_object()->query("name");
			break;
		}
		else
			randPage=randPage-lines[lp];
	}
	
	me->set_temp("quest_chanting",chanting);
	this_object()->newbieDesc("在"+HIC+chanting["room"]+NOR+"诵唱"+HIC+chanting["book"]+NOR+"的"+HIC+chanting["title"]+NOR+"。\n");
	return "今天的早课安排在"+HIC+chanting["room"]+NOR+"，请"+me->query("name")+NOR"诵唱"+
	       HIC+chanting["book"]+NOR+"的"+HIC+chanting["title"]+NOR+"。\n佛经可以从藏经楼找到或者找藏经楼的玄彦大师租借！\n";
}

string fail_chanting()
{
	if(!mapp(this_player()->query_temp("quest_chanting")))
		return "你没有领诵经任务。\n";

	this_object()->newbieFail();
	this_player()->delete_temp("quest_chanting");
	return "今天的早课你也不用参加了。\n";
}

string end_chanting(int reward)
{
	mapping chanting;
	if(!mapp(this_player()->query_temp("quest_chanting")))
		return "你没有领诵经任务。\n";
	else if(!this_player()->query_temp("quest_chanting/success")) {
		chanting=this_player()->query_temp("quest_chanting");
		return "你还没有完成早课！今天早课安排在"+HIC+chanting["room"]+NOR+"，据说要诵唱"+
	       HIC+chanting["book"]+NOR+"的"+HIC+chanting["title"]+NOR+"，赶快过去吧。\n";
	}

	this_object()->newbieEnd(reward);
	this_player()->delete_temp("quest_chanting");
	return "今天的早课你表现的非常出色。\n";
}