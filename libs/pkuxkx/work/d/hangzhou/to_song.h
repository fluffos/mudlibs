// 到大宋其他建筑，不对普通用户开放，Zine@pkuxkx
string looking(string dir);
#include <ansi.h>
#include "/d/hangzhou/gates.h"//守门相关
int valid_pass(object me)
{
	if (me->query("song/pro"))
	return 2;
	if (me->query_temp("songtasks/libu/theone")||me->query("presong/total_check")>=7)//吏部邀请
	return 1;
	return 0;
}
int make_entrance()
{
	mapping dirs=query("dirs_to_song");
	mapping init_dirs=([
		"北面" : (:looking("north"):),
		"东面" : (:looking("east"):),
		"西面" : (:looking("west"):),
		"南面" : (:looking("south"):),
		"东北面" : (:looking("northeast"):),
		"东南面" : (:looking("southeast"):),
		"西北面" : (:looking("northwest"):),
		"西南面" : (:looking("southwest"):),
		"里面" : (:looking("enter"):),
		"外面" : (:looking("out"):),
	]);
	mapping trans_dir=(["north":"北面","south":"南面","west":"西面","east":"东面","northwest":"西北面","northeast":"东北面","southwest":"西南面","southeast":"东南面","enter":"里面","out":"外面"]);
	string *all_dirs=({"north","south","west","east","northwest","northeast","southwest","southeast","enter","out"}),*the_dirs=keys(dirs);
	set("the_dirs",the_dirs);
	for (int i=0;i<sizeof(all_dirs);i++)
	if (member_array(all_dirs[i],the_dirs)==-1)
	map_delete(init_dirs,trans_dir[all_dirs[i]]);
	set("item_desc_color",HBWHT+HIR);
	set("item_desc",init_dirs);

}
string looking(string dir)
{
	mapping dirs=query("dirs_to_song");
	string *the_dirs;
	if (!mapp(dirs))
	return dir+"方向上什么都没有。\n";
	the_dirs=keys(dirs);
	if (member_array(dir,the_dirs)==-1)
	return dir+"方向上什么都没有。\n";
	if (valid_pass(this_player())>1)
	{
		if (query("look_accept_msg")&&stringp(query("look_accept_msg")))
		return query("look_accept_msg");
		return dirs[dir][1]+"面正是我大宋"+dirs[dir][2]+"所在，你如果有事就赶紧过去(pass "+dir+")吧。\n";
	}
	if (query("look_refuse_msg")&&stringp(query("look_refuse_msg")))
	return query("look_refuse_msg");
	return "一队甲士走了过来，阻止了你对"+dirs[dir][1]+"边的窥视。\n";
}

void init()
{
	add_action("do_pass","pass");
	if (query("is_GaTe"))
	{
		add_action("do_guard","guarding");
		add_action("do_pancha", "pancha");

		if (this_player()->query("class")!="officer") 
		{
 			this_player()->set_temp("pancha_stage", 1);
			call_out("remove_need_pancha", 5, this_player());
		}
	}
	if (query("common_entry"))
	{
		add_action("do_northwest",({"northwest","nw"}));
	}
}

int do_pass(string dir)
{
	object me=this_player(),rm;
	mapping dirs=query("dirs_to_song");
	string *the_dirs;
	if (!mapp(dirs))
	return 0;
	the_dirs=keys(dirs);
	if (member_array(dir,the_dirs)==-1)
	return 0;
	if (!valid_pass(this_player()))
	return 0;
	rm=load_object("/d/song/"+dirs[dir][0]);
	if (!rm)
	{
		if (query("refuse_enter_msg")&&stringp(query("refuse_enter_msg")))
		{
			write(query("refuse_enter_msg"));
			return 1;
		}
		else
		{
			message_vision("$N却被巡弋的甲士拦了下来。\n",me);
			return 1;
		}
	}
	if (query("accept_enter_msg")&&stringp(query("accept_enter_msg")))
	write(query("accept_enter_msg"));
	else
	message_vision("$N跟巡弋的甲士核对了身份，信步向"+dirs[dir][1]+"面走去。\n",me);
	tell_object(rm,me->name()+"从"+this_object()->query("short")+"走了过来。\n");
	me->move(rm);
	return 1;
}
