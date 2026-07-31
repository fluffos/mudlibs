// CMDS USR news.c
// Created by kittt@DJX2000
// Last Modified by kittt@DJX 6/2/2000
//
// XKX 中玩家了解更新消息一般是用 Help Whatsnew
// 因此巫师在更新后需要编写/doc/help/文件，很不方便。
// 采用了这个新闻系统，发布更新消息只需像POST一样简单
// 也更有条理。玩家阅读起来也比较方便。


#include <ansi.h>;
inherit BULLETIN_BOARD;

// create part和普通的BOARD差不多
void create()
{
	set_name("海洋V新闻版", ({ "newsboard"}) );
	set("location", "/d/wizard/proom"); // 这里用了一个ROOM来放置BOARD，简单，你做 
	set("board_id", "hy2news_b");              // 成一个指令来输入新闻也可以。
	setup();
	set("capacity", 500);
}

// 这个部份是用来在login时调用的。
int check_news(object me)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg="";
	
	notes = query("notes");
	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	
	if( !pointerp(notes) || !sizeof(notes) ) return 1;

 	if(userp(me))
	{
		i=sizeof(notes)-me->query("LastReadNews");
		
		if(i < 6 && i > 0) // 小于6条新闻才显示标题，不然会FLOOD
		{
			msg = "\n\n    ━━━━━━━━━━━━ "HIW"海洋V最新消息"NOR" ━━━━━━━━━━━━    \n";
			
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
				
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>num-2 ; i--)
			{
				msg += sprintf("<%3d>"NOR,i+1);
				msg += sprintf("     %-=36s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					ctime(notes[i]["time"])[0..15]);
			}
			
			msg += "    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━    \n\n";
			
			me->start_more(msg);
		}
		
		i=sizeof(notes)-me->query("LastReadNews");
		
		write("\n从您上次阅读到现在"+((i==0)? "没有任何":"共有"+HIY+chinese_number(i)+NOR"条")+"新闻。\n\n");
		write("你可以 Help news 来查看海洋V新闻系统的使用方法。\n"); // 提醒不知道有NEWS系统的玩家使用news
	}
}

int main(object me, string arg)
{
	int num,i,last_time_read;
	mapping *notes, last_read_time;
	string myid,msg;
//seteuid(getuid());
	last_read_time = me->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
	i=sizeof(notes)-me->query("LastReadNews");
	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("「海洋V」目前没有任何新闻。\n");
		
	if( !arg ) 
	{
		if(i>10) write("你可以 Help news 来查看海洋V新闻系统的使用方法。\n"); 
			return notify_fail(
				"「海洋V」目前共有"+HIW+chinese_number(sizeof(notes))+NOR"条新闻"+((i==0)? "。":"，您有"+HIY+chinese_number(i)+NOR"条新闻尚未阅读。")+"\n"); }
				
		if( arg=="all") // 显示所有新闻
		{
			msg = "\n\n    ━━━━━━━━━━━━ "HIW"海洋V新闻一览"NOR" ━━━━━━━━━━━━    \n";
			notes = query("notes");
			
			if (mapp(last_read_time)) last_time_read = last_read_time[myid];
			for(i=sizeof(notes)-1 ; i>-1 ; i--)
			{
				msg += sprintf("%s<%3d>" NOR,
				notes[i]["time"] > last_time_read ? HIY: "", i+1);
				msg += sprintf("     %-=36s %18s (%s)\n",
					notes[i]["title"], notes[i]["author"],
					ctime(notes[i]["time"])[0..15]);
			}
			msg += "\n";
			me->start_more(msg);
			return 1;
			
		}
		else
		if ( arg=="new" )  // 显示最新新闻
		{
			if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
				num = 1;
			else
				for(num = 1; num<=sizeof(notes); num++)
					if( notes[num-1]["time"] > last_read_time[myid] ) break;
					
		} else if( !sscanf(arg, "%d", num) )
		
	return notify_fail("你到底"+arg+"要看第几条新闻呀？\n");
	
	if( num < 1 || num > sizeof(notes) )
		return notify_fail("看清楚点，好像没有这条新闻耶。\n");
		
	num--;
	me->start_more( sprintf("\n\n%s\n"HIR"新闻主题："HIY"%s\n"HIW"新闻巫师："NOR"%s\n"HIG"新闻时间：%s\n"NOR
	"-------------------------------------------------------------------------------\n",
		BBLU HIG"「"HIR"海"HIY"洋"HIW"V"HIG"」第"+chinese_number(num + 1)+"条新闻"NOR, 
		notes[num]["title"], notes[num]["author"],
		ctime(notes[num]["time"])[0..15])
		+ HIY+notes[num]["msg"]+NOR+
	"-------------------------------------------------------------------------------\n\n", );

	if( !mapp(last_read_time) )
		me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	if(me->query("LastReadNews") < num + 1)
		me->set("LastReadNews",num+1);

	return 1;
}

void init()
{
	object me=this_player();
// 只给apprentice级别以上的巫师修改新闻
       if (wizardp(me) &&  wiz_level(me) > wiz_level("(apprentice)") )
	{
		add_action("do_post", "post");
		add_action("do_discard", "discard");
      }	
}

/* 这个部份可能大部份的MUD都不需要
   这里有是因为只是我修改了DJX的bboard有一些地方变了。   
int do_post(string arg)
{
	mapping note;

	if(!arg) return notify_fail("新闻要个加题目。\n");

	note = allocate_mapping(4);
	note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
	note["id"] = this_player()->query("id"); 
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}
*/

void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["time"] = time();
	note["msg"] = text;
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	if( sizeof(notes) > query("capacity"))
		notes = notes[query("capacity")/2 .. query("capacity")];

	set("notes", notes);
	save();
	restore();
// 使用channel显示提示有了最新新闻
	CHANNEL_D->do_channel(me, "news", BLINK HIY"\n「海洋V」有了最新新闻，请用 news 查看。\n\n" NOR);

	tell_object(me, "新闻发表完毕。\n");

	return;
}

int help(object me)
{
    write(@HELP
「海洋V」新闻系统指令 

指令格式 :
news                    查看共有的和最新发布的新闻。
news all                海洋V新闻一览。 
news new                阅读最新的新闻。 
news <新闻编号>         查看此编号新闻的详细内容。 
HELP
    );
    return 1;
}
