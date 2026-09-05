//board reader
//Made by jason@pkuxkx
//2001.3.14

inherit ITEM;
inherit F_SAVE;
#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

string board_data="/data/board/ct_b";
string board_file="/clone/board/ct_b";

string query_save_file()
{
	return board_data;
}

void create()
{
	set_name("留言版阅读时空门",({"board door","door"}));
	set("invisibility",5);
	set("no_get",1);
	set("long","这是一个供巫师管理各地留言斑的工具。\n");
	set("value",1000);
	set("capacity", 200);
	set("unit","扇");
	restore();
	set_name("留言版阅读时空门",({"board door","door"}));		
	set("env/invisibility",5);
	setup();
}

void init()
{
	object ppl=this_player();
	if(wizhood(ppl)=="(admin)")
	{
		add_action("do_read",({"wread","wr"}));
		add_action("do_discard",({"wdiscard","wd"}));
		add_action("do_post",({"wpost","wp"}));
		add_action("do_select",({"wselect","ws"}));
		//add_action("do_document", "wdocument");
	}
}

int do_select(string arg)
{
	if(!arg||arg=="") 
	{
		write("select 留言斑存档文件的全路径，请不要加.o后缀。\n");
		return 1;
	}
	board_data=arg;
	if(!restore())
	{
		write("这个档案读不出来以耶。。。\n");
		return 1;
	}
	board_file="/clone/board/"+query("board_id");
	set_name("留言版阅读时空门",({"board door","door"}));	
	set("env/invisibility",5);
	write("选择"+arg+"留言版数据。\n");
	return 1;
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
	string msg;

	notes = query("notes");
	msg = query("long");
	msg = msg + "留言版的使用方法请见 help board。\n";
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=sizeof(notes)-1; i>=0; i--)
	msg += sprintf("%s[%2d]"+ NOR +"  %-40s %12s (%s)\n",
	( notes[i]["time"] > last_time_read ? HIY: ""),
	i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );

		
	this_player()->start_more(msg);
	return "";
}

void done_post(object me, mapping note, string text)
{
	mapping *notes;
	object origin_b;
	note["msg"] = text;
	note["time"] = time();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 5 .. BOARD_CAPACITY];

	set("notes", notes);
	tell_object(me, "留言完毕。\n");
	
	//recording...
	log_file("POSTING", ctime( time() )+": "
		+me->query("name")+"("+me->query("id")+")"+" posted.\n");
	seteuid(ROOT_UID);
	
	if(objectp(origin_b=load_object(board_file)))
	{
		origin_b->set("notes",query("notes"));
		origin_b->save();
	}
	return;
}

int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("留言板上目前没有任何留言。\n");

	if( !arg ) return notify_fail("指令格式：read <留言编号>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几张留言？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	this_player()->start_more( sprintf(
"[%d] %-40s %s(%s)\n----------------------------------------------------------------------\n",
		num + 1, notes[num]["title"], notes[num]["author"], ctime(notes[num]["time"])[0..9])
		+ notes[num]["msg"] );

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;
	object me = this_player();
	object origin_b;
	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <留言编号>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这张留言。\n");
	num--;
	if( notes[num]["author"] != 
	  (string) this_player(1)->query("name")+
	  "("+capitalize(this_player(1)->query("id"))+")"
&& (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
	&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
		return notify_fail("这个留言不是你写的。\n");

	if (num >0)
             notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
        else
          notes =notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	seteuid(ROOT_UID);
	write("删除第 " + (num+1) + " 号留言....Ok。\n");
	if(objectp(origin_b=load_object(board_file)))
	{
		origin_b->set("notes",query("notes"));
		origin_b->save();
	}
	//recording...
	log_file("POSTING", ctime( time() )+": "
                +me->query("name")+"("+me->query("id")+")"
		+" discarded "+(num+1)+".\n");
	
	return 1;
}
int do_post(string arg)
{
	mapping note;
   	object me;

	me = this_player();
	if(!wizardp(me) && environment(me)->query("post_limit"))
	   return notify_fail("只有巫师才可以在这里留言。\n");

	if(!arg) return notify_fail("留言请指定一个标题。\n");
	
	note = allocate_mapping(4);
	note["title"] = arg;
	note["author"] = this_player()->query("name")+
	 "("+capitalize(this_player()->query("id"))+")";
//	note["time"] = time();
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}
