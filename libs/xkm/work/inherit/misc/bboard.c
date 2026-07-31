// bboard.c
//jhy 为贡献度加的同时防止palyer用大米连续post and read挣贡献度加了一点等待时间 ///
//bug fixed by Seashore 2002/6
#define EDITOR_D "/adm/daemons/editord"
#include <ansi.h>
#include <localtime.h>


#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void tune_channels();
void open_channels();
string chinese_time(int i);

void setup()
{
	string loc;
		
	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
	add_action("do_store", "store");
	add_action("do_list","list");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ 没有任何留言 ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf("%s [ %d 张留言，%d 张未读 ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d 张留言 ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, last_time_read;
	string msg, myid;

	notes = query("notes");
	msg = query("long");
	msg = msg + query("name") +"的使用方法请见 help board。\n";
	return msg;
}

int do_list(string arg)
{
        mapping *notes;
        int i, last_time_read, n=0;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        
        if( !pointerp(notes) || !sizeof(notes) ) 
                	return notify_fail(msg+query("name")+"上目前没有任何留言。\n");
                	
        if (!arg)
	{
		msg += query("name")+"上现有下列留言：\n————————————————————————\n";
		last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
		for(i=0; i<sizeof(notes); i++)
			msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
				( notes[i]["time"] > last_time_read ? HIY: ""),
				i+1, notes[i]["title"], notes[i]["author"], chinese_time(notes[i]["time"])[0..16] );
		this_player()->start_more( msg);
		return 1;
	}
	else
	{
		msg += query("name")+"上现有下列 "+capitalize(arg)+" 写的留言：\n————————————————————————\n";
		last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
		for(i=0; i<sizeof(notes); i++)
			if (strsrch(notes[i]["author"], "("+arg+")") >= 0){
				msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
					( notes[i]["time"] > last_time_read ? HIY: ""),
					i+1, notes[i]["title"], notes[i]["author"], chinese_time(notes[i]["time"])[0..16] );
				n++;
			}
		msg +="\n";
		msg += ( n > 0 ? "共找到 "+n+" 篇 "+capitalize(arg)+" 写的留言。\n": HIR"没有找到任何 "+capitalize(arg)+" 写的留言。"NOR);
		this_player()->start_more( msg);
		return 1;		
	}

}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["msg"] = text;
	note["time"] = time();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 4 .. BOARD_CAPACITY];

	set("notes", notes);
	tell_object(me, "留言完毕。\n");
	////////////////jhy add gxd
	if ( (int)me->query_condition("boardpost" ) > 0 ){
		me->apply_condition("boardpost", 10);
		}
	else
		{
		me->apply_condition("boardpost", 10);
		me->add("chatpts",30);
		}
	///////////////end

	open_channels();
	save();
	return;
}

int do_post(string arg)
{
	int i, j=0;
	mapping note;
	string poster_lvl, family;
	object the_player;
	mapping fam;

	the_player = this_player();	
	poster_lvl = query("poster_level");
	
	if(!stringp(poster_lvl))
		poster_lvl = "(player)";

	for(i=0; i<sizeof(query("notes")); i++){
		if (the_player->name()+"("+the_player->query("id")+")" == query("notes")[i]["author"]) 
		j++;}

	if(j>=10 && !wizardp(the_player)) return notify_fail("对不起，你的留言已超过十篇，请删掉前面的再POST新的。\n");

//	write("Board Restricted to " + poster_lvl + " and above.\n");

	if ( (int)SECURITY_D->cmp_wiz_level(the_player, poster_lvl ) < 0 )
		return notify_fail("本板不接受你的投稿。\n");

	family = query("poster_family");
	fam = the_player->query("family");

//	write("Board Restricted to " + family + " players only.\n");

	if ( stringp(family)
		&& (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
		&& ( !mapp( fam ) || fam["family_name"] != family ) )
		return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

	if(!arg) return notify_fail("留言请指定一个标题。\n");
	
	note = allocate_mapping(4);
	note["title"] = arg;
	note["author"] = the_player->name()+"("+the_player->query("id")+")";
	tune_channels();
	the_player->edit( (: done_post, the_player, note :) );
	return 1;
}

int do_read(string arg)
{
	int num, arc;
	mapping *notes, last_read_time;
	string myid;
	object the_player;
	string family;
	mapping fam;

	the_player = this_player();	

	last_read_time = the_player->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");
//dts
	arc = query("wizard_only");
	if ( arc
		&& (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0)
		return notify_fail("内部通讯不得窥视。\n");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

	family = query("poster_family");
	fam = the_player->query("family");

//	write("Board Restricted to " + family + " players only.\n");

	if ( stringp(family)
		&& (int)SECURITY_D->cmp_wiz_level(the_player, "(immortal)" ) < 0
		&& ( !mapp( fam ) || fam["family_name"] != family ) )
		return notify_fail("非本派弟子不得窥视本派内部通讯。\n");

	if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else {
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
		}
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	tune_channels();
	the_player->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"],chinese_time(notes[num]["time"])[0..16])
		+ notes[num]["msg"] );
	if ( (int)the_player->query_condition("boardread" ) > 0 ){
		the_player->apply_condition("boardread", 10);
		}
	else
		{
		the_player->apply_condition("boardread", 10);
		the_player->add("chatpts",3);
		}
	///////////////end
	open_channels();
	
	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		the_player->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["author"] != (string)this_player(1)->name()+"("+this_player(1)->query("id")+")"
	&&  ( (int)SECURITY_D->cmp_wiz_level(this_player(), "(caretaker)") < 0 ) )
		return notify_fail("这个留言不是你写的。\n");

	notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("删除第 " + (num+1) + " 号留言....Ok。\n");
	return 1;
}

void tune_channels()
{
	string *tuned_ch;
	object me;
	
	me = this_player();
	
	tuned_ch = me->query("channels");
	me->set_temp("tuned_ch", tuned_ch);
	me->set("channels", 0);
}
 
void open_channels()
{
	string *tuned_ch;
	object me;
	
	me = this_player();
	               
	tuned_ch = me->query_temp("tuned_ch");
	me->set("channels", tuned_ch);
	me->set_temp("tuned_ch", 0);
}                             

int do_store(string arg)
{
	int num, numb;
	mapping *notes, last_read_time;
	string myid, fmonth, fyear, filename;
	int arc;
	object me=this_player();
	
	arc = query("wizard_only");
	seteuid(getuid()); /* yzc */

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

//	if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
//	&&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)"
//	&&      (string)SECURITY_D->get_status(this_player(1)) != "(wizard)")
//		return notify_fail("你不能收编“侠客行”文摘。\n");

	if( !arg ) return notify_fail("指令格式：store <留言编号>\n");

	if( !sscanf(arg, "%d", num) )
		return notify_fail("你要收编第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["stored"] ) 
		return notify_fail("这张留言已经被收录了。\n记录显示："+notes[num]["stored"]+"\n");

	fyear  = chinese_time(notes[num]["time"])[20..23];
	fmonth = chinese_time(notes[num]["time"])[4..6];
//	fmonth = lower_case( ctime(notes[num]["time"])[4..6] );
//	write( "FILENAME +" + fext );

	numb = EDITOR_D->get_file_num(arc, fyear, fmonth) + 1;

//	filename = sprintf("%s/%s/%03d", fyear, fmonth, numb);
		//bug above,for system can't distinguish a file name from a directory name. 
	filename = sprintf("%s/%s/%03d.pst", fyear, fmonth, numb);	

	if (arc)
	write( "ARC: writing ..." + filename + "\n" );
	else
	write( "WEN: writing ..." + filename + "\n" );
	
	EDITOR_D->add(arc, "※※※※※※※※※※※※※※【“侠客行”文选】"+
		"※※※※※※※※※※※※※※", filename);
	EDITOR_D->add(arc, sprintf("№%03d  %-40s  %12s(%s)",
		numb, notes[num]["title"],
		notes[num]["author"],
		chinese_time(notes[num]["time"])[0..9]), filename );
	EDITOR_D->add(arc, notes[num]["msg"], filename);
	EDITOR_D->add(arc, "〖本篇完〗", filename);

/* index */
	filename = sprintf("%s/wenxuan.%s", fyear, fmonth);	

	if (arc)
	write( "ARC: writing ..." + filename + "\n" );
	else
	write( "WEN: writing ..." + filename + "\n" );

	if ( numb == 1)
	{
EDITOR_D->add(arc,
"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n" +
"                    【侠客行文选" + fyear +"年第 " + fmonth + " 卷目录】\n" +
"编号   题目                                              作者(发稿日期)\n"+
"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※",
	filename);
	}

	if (EDITOR_D->add(arc, sprintf("№%03d  %-40s  %12s(%s)",
		numb, notes[num]["title"],
		notes[num]["author"],
		chinese_time(notes[num]["time"])[0..9]), filename )) {
		write( notes[num]["stored"] = sprintf("【“侠客行”文选】第 %d 篇收入 %s 卷，第 %03d 篇。\n",
			num+1, fmonth, numb) );
		log_file("wenxuan",sprintf("%s%s(%s)收入【“侠客行”文选】第 %d 篇收入 %s 卷，第 %03d 篇。\n",
                        ctime(time()),me->query("name"),me->query("id"),num+1, fmonth, numb) );
		set("notes", notes);
		save();//we need save the board,or another wizard can store it again.
	} else
		write( sprintf("【“侠客行”文选】第 %d 篇收编失败。\n", num+1) );

	return 1;
}
string chinese_time(int i)
{
	int t, y, mo, d, h, m, s;
	mixed *ltime;
	string time,time1,time2,time_tmp;
	ltime = localtime(i);
	s = ltime[LT_SEC];
	m = ltime[LT_MIN];
	h = ltime[LT_HOUR];
	d = ltime[LT_MDAY];
	mo = ltime[LT_MON]+1;
	y = ltime[LT_YEAR];
	time2="";
	
        if(d>=10)   
		time = "/" + (d);
	else
		time = "/" + "0"+(d);
	
	time_tmp = time;
	
	if(mo>=10)	 
		time = "/" + (mo) + time_tmp;
	else
		time = "/" + "0"+(mo) + time_tmp;
	
	time_tmp = time;
	
	while (y) {
		time2 =(y%10)+time2;
		y /= 10;
	}
        
        time = "/" + time2 + time_tmp;
        
        if(h>=10)
		time1 =  (h) + ":";
	else
		time1 = "0" + (h) + ":";
	if(m>=10)	
		time1 += (m) + ":";
	else
		time1 += "0"+(m) + ":";	
	time1 = time1 + (s);
	return time+" " + time1;
}
