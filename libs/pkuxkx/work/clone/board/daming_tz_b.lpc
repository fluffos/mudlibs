// /clone/board/gaibang_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("通政司奏折递送处", ({ "board" }) );
	set("location", "/d/yingtianfu/neicheng/tongzhen");
	set("board_id", "daming_tz_b");
	set("long", "这里可以汇报大明系统内任何BUG，每个人只能看到自己的留言，避免他人用BUG牟利。\n" );
	setup();
	set("capacity", 45);
	
}

void init()
{
    add_action("do_list","list");
    ::init();
}

int do_list()
{
    mapping *notes;
    int i,no,count=0;
    object me=this_player();
    string list="你递送的奏折有：\n\n";
    if (!this_player()->query("mingpin")&&!this_player()->query("ming/tj/pin"))
		return notify_fail("你不是大明官员也不是内廷官员，不能阅读通政司的奏折。\n");
    notes = query("notes");
    if( !pointerp(notes) || !sizeof(notes) )
    {
        tell_object(me,"暂无任何奏折。\n");
	    return 1;
    }
    for (i=0;i<sizeof(notes);i++)
    {
        if (notes[i]["authorid"]==me->query("id"))
        {
            no=i+1;
            list+="『第"+chinese_number(no)+"号奏折』"+"  "+"『"+notes[i]["title"]+"』\t『递于："+ctime(notes[i]["time"])+"』\n";
            count=count+1;
        }
    }
    if (count==0)
    {
        tell_object(me,"你没有递送过任何奏折。\n");
        return 1;
    }
    tell_object(me,list);
    return 1;

}

int do_post(string arg)
{
	if (!this_player()->query("mingpin")&&!this_player()->query("ming/tj/pin"))
		return notify_fail("你不是大明官员也不是内廷官员，不能递送奏折。\n");
	return ::do_post(arg);
}

int do_read(string arg)
{
    mapping *notes;
    int num;
	if (!this_player()->query("mingpin")&&!this_player()->query("ming/tj/pin"))
		return notify_fail("你不是大明官员也不是内廷官员，不能阅读通政司的奏折。\n");
    

    if( !arg || sscanf(arg, "%d", num)!=1 )
	return notify_fail("指令格式：read <留言编号>\n");
    notes = query("notes");
    if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
	return notify_fail("没有这张留言。\n");
    num--;
    if( notes[num]["authorid"] != (string) this_player(1)->query("id")
      &&	this_player()->query("id")!="zine")
	return notify_fail("这张奏折不是你能看到的。\n");
	return ::do_read(arg);
}