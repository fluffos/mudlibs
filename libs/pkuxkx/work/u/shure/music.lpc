///cmds/wiz/music.c
// base on the work of jjgod
// by shure@mudbuilder.net 2001-10-06

#include <ansi.h>
inherit F_CLEAN_UP;

int  main(object me, string arg);
void get_author(string author,object me,string id,mapping song);
void get_context(object me,string id,mapping song,string context);
void add_decide(string yn, object me, string name, mapping song);
void add_continue(string ac, object me, string name, mapping song);
void add_ChangeName(string newname, object me, string name, mapping song);
void delete_all(string yn);
int  check_legal_name(string name);
int  check_legal_line(string line);
int  help();

string *para = ({"-c", "-d", "-r", "-sd", "rd"});

int main(object me, string arg)
{
	string  flag, name, *k, msg;
	mapping song, v;
	int i, all;
	
	if( !arg )
		return notify_fail("你要编辑什么乐曲？\n");
	if( sscanf(arg, "%s %s", flag, name) == 2 )
	{
		if( flag == "-c" )
		{
			if(!wizardp(me))
				return notify_fail("该项参数为巫师专用。\n");
			if( undefinedp(song = MUSIC_D->query_PlayerSong(name)) )
				return notify_fail("玩家推荐曲库中没有这首曲目。\n");
			if( !undefinedp(MUSIC_D->query_song(name)) )
			{
				write(MUD_NAME"曲库中已经有同名曲目，是否要覆盖？(y/n)\n");
				input_to("add_decide",me, name, song);
				return 1;
			}
			write("从玩家推荐曲库拷贝《" + name + "》到"+MUD_NAME+"曲库\n");
			song["vouch"] = me->name()+"("+me->query("id")+")";
			MUSIC_D->add_songs(name, song);
			MUSIC_D->delete_PlayerSongs(name);
			write("清除玩家推荐曲库中本曲信息完毕。\n");
			return 1;		
		}
		if( flag == "-d" )
		{
			if(!wizardp(me))
				return notify_fail("该项参数为巫师专用。\n");
			if( undefinedp(MUSIC_D->query_song(name)) )
				return notify_fail(MUD_NAME+"词曲库中没有这个曲目。\n");
			write("从"+MUD_NAME+"曲库中删除词曲：《" + name + "》\n");
			MUSIC_D->delete_songs(name);
			return 1;
		}
		if( flag == "-rd" )
		{
			if(!wizardp(me))
				return notify_fail("该项参数为巫师专用。\n");
			if( undefinedp(MUSIC_D->query_PlayerSong(name)) )
				return notify_fail(MUD_NAME+"玩家推荐曲库中没有这个曲目。\n");
			write("从"+MUD_NAME+"玩家推荐曲库中删除词曲：《" + name + "》\n");
			MUSIC_D->delete_PlayerSongs(name);
			return 1;
		}		
		if( flag == "-sd" )
		{
			song = me->query("songs");
			all = sizeof(song);
			if(!mapp(song) || !all)
				return notify_fail("你没有为自己编辑过任何曲目。\n");
			if( undefinedp(song = song[name]) )
				return notify_fail("你没有编辑过这个曲目。\n");
			write("删除自编曲目：《" + name + "》\n");
			me->delete("songs/"+name);
			return 1;
		}
		if( flag == "-l" )
		{
			if( undefinedp(song = MUSIC_D->query_song(name)) )
				return notify_fail(MUD_NAME+"词曲库中没有这个曲目。\n");
			printf("\n"RED MUD_NAME"曲库查询\n"NOR"\n"RED"□"NOR"作者：%-10s\n"RED"□"NOR"曲题：%s\n",song["author"],name);
			printf(RED"□"NOR"内容：\n\t%s\n",implode(song["context"], "\n\t"));
			printf("-----------------\n"RED"□"NOR"推荐人：%s\n",song["vouch"]);
			return 1;
		}
		if( flag == "-rl" )
		{
			if( undefinedp(song = MUSIC_D->query_PlayerSong(name)) )
				return notify_fail(MUD_NAME+"玩家推荐曲库中没有这个曲目。\n");
			printf("\n"BLU MUD_NAME"玩家推荐曲目查询\n"NOR"\n"BLU"□"NOR"作者：%-10s\n"BLU"□"NOR"曲题：%s\n",song["author"],name);
			printf(BLU"□"NOR"内容\n\t%s\n",implode(song["context"], "\n\t"));
			printf("-----------------\n"BLU"□"NOR"推荐人：%s\n",song["vouch"]);
			return 1;
		}
		if( flag == "-sl" )
		{			
			song = me->query("songs");
			all = sizeof(song);
			if(!mapp(song) || !all)
				return notify_fail("你没有为自己编辑过任何曲目。\n");
			if( undefinedp(song = song[name]) )
				return notify_fail("你没有编辑过这个曲目。\n");
			printf("\n"MAG MUD_NAME"玩家自编辑曲目查询\n"NOR"\n"MAG"□"NOR"作者：%-10s\n"MAG"□"NOR"曲题：%s\n",song["author"],name);
			printf(MAG"□"NOR"内容：\n\t%s\n",implode(song["context"], "\n\t"));
			return 1;
		}
		if( flag == "-r" )
		{
			if(me->query("age") < 18)
				return notify_fail("你尚未成年，没有资格发布曲目。\n");
			if (me->query("commend_time"))
			{
				if ((int)me->query("commend_time") > (int)time()-3600*24)
				{
        				if (me->query("commend_time") > 2)
        				{
        					write("不要过于频繁地发布曲目。\n");
        					return 1;
        				}
        			}
        			else
        			{
        				me->set("commend_times", 1);
					me->set("commend_time", (int)time());
        			}
			}
			else
				me->set("commend_times", (int)time());
			song = me->query("songs");
			all = sizeof(song);
			if(!mapp(song) || !all)
				return notify_fail("你没有为自己编辑过任何曲目。\n");
			if( undefinedp(song[name]) )
				return notify_fail("你没有编辑过这个曲目。\n");
			if( !undefinedp(MUSIC_D->query_PlayerSong(name)) )
			{
				write(MUD_NAME"曲库中已经有了同名曲目。\n");
				return 1;
			}
			MUSIC_D->add_PlayerSongs(name, song[name]);
			write("发布成功！\n《"+name+"》已经添加到"+MUD_NAME+"玩家推荐曲库中。\n");
			return 1;
		}
	}
	else
	{
		if(arg == "-l")
		{
			song = MUSIC_D->query_songs();
			all = sizeof(song);
			if(!mapp(song) || !all)
				return notify_fail("目前"+MUD_NAME+"词曲库中没有任何曲目。\n");
                	k = keys(song);                	
                	k = sort_array(k, 1);

                	msg = "─────────────────────────——───———─————\n";
                	msg += HBRED+HIW+"\t\t     【"MUD_NAME"】 词曲库目录\t\t\t\t\n"NOR;
                	msg += "──────────────────────——───────————─——\n";
               		for (i = 0; i < all; i++)
               		{
               			v = MUSIC_D->query_song(k[i]);
                       		msg += sprintf( WHT "  %-24s" NOR "作者：%-15s\t推荐人：%s\n", 
                       		k[i],
                                v["author"],
                                v["vouch"] );
                	}
                	msg += "───────────────────────────——──————─——\n";
                	msg += "目前共有 " + i +" 首词曲。\t\t\t\t\n";
                              	me->start_more(msg);
                	return 1;
		}
		if(arg == "-rl")
		{
			song = MUSIC_D->query_PlayerSongs();
			all = sizeof(song);
			if(!mapp(song) || !all)
				return notify_fail("目前没有玩家推荐曲目。\n");
                	k = keys(song);                	
                	k = sort_array(k, 1);

                	msg = "──────────────────——──────────—─——————\n";
                	msg += HBBLU+HIW+"\t\t     【"MUD_NAME"】玩家推荐曲目列表\t\t\t\n"NOR;
                	msg += "────────────────——─────────——───—─————\n";
               		for (i = 0; i < all; i++)
               		{
               			v = MUSIC_D->query_PlayerSong(k[i]);
                       		msg += sprintf( WHT "  %-24s" NOR "作者：%-15s\t发布人：%s\n", 
                       		k[i],
                                v["author"],
                                v["vouch"] );
                	}
                	msg += "────────────────────────────——─————─——\n";
                	msg += "目前共有 " + i +" 首词曲。\t\t\t\t\n"NOR;
                	me->start_more(msg);
                	return 1;
		}
		if(arg == "-sl")
		{
			song = me->query("songs");
			all = sizeof(song);
			if(!mapp(song) || !all)
				return notify_fail("你没有为自己编辑过任何曲目。\n");
                	k = keys(song);                	
                	k = sort_array(k, 1);

                	msg = "─────────────────────────——───———─————\n";
                	msg += HBMAG+HIW+"\t\t     【"MUD_NAME"】 玩家自编辑曲目\t\t\t\n"NOR;
                	msg += "──────────────────────——───────————─——\n";
               		for (i = 0; i < all; i++)
               		{
               			v = song[k[i]];
                       		msg += sprintf( WHT "  %-24s" NOR "作者：%-15s\n", 
                       		k[i],
                                v["author"],);
                	}
                	msg += "─────────────────────────────——─——————\n";
                	msg += "目前共有 " + i +" 首词曲。\t\t\t\t\n";
    			me->start_more(msg);
                	return 1;
		}
		if( arg == "-ad" )
		{
			if(!wizardp(me))
				return notify_fail("该项参数为巫师专用。\n");
			write("你确定要删除全部玩家推荐曲目？(y/n)\n");
			input_to("delete_all");
			return 1;
		}
		for(i = 0; i < sizeof(para); i++)
		{
			if(strsrch(arg, para[i]) != -1)
			{
				write("使用此参数，词曲名不可省略 (help music)。\n");
				return 1;
			}
		}
		if(!check_legal_name(arg))
			return 1;
		song=([]);
		if(sizeof( me->query("songs") ) > 19)
			return notify_fail("你已经编辑太多的曲目了，请删掉一些(music -sd <词曲名>)。\n");
		write("请输入曲辞的作者：");
		input_to("get_author",me, arg, song);
		return 1;		
	}
}

void get_author(string author, object me, string id, mapping song)
{
	if (author=="" || author==".")
		song["author"]="无名氏";
	else
		song["author"]=author;

	write("请输入曲辞的内容：\n");
	me->edit((: call_other, __FILE__, "get_context", me, id, song :));
	return;
}

void get_context(object me, string id, mapping song, string context)
{
	string *txt, *txt_o;
	int all, i;
	
	txt = explode(context, "\n");	
        all = sizeof(txt);
        if( all == 0 )
        {
                write("词曲行不得为空！\n");
                return;
        }
        if( all > 30 )
        {
                write("请把曲辞控制在三十行以内！\n");
                return;
        }
       	txt_o = ({});
       	for(i = 0; i < all; i++)
       	{
       		if(!check_legal_line(txt[i]))
       		{
       			txt_o = ({});
       			return;
       		}
       		txt_o += ({txt[i]});
        }
        song["context"] = txt_o;
        song["vouch"] = me->name()+"("+me->query("id")+")";
        if(wizardp(me))
        	MUSIC_D->add_songs(id, song);	
        else
        	me->set("songs/"+id, song);
        write(HIW"\n曲目《"+id+"》编辑完毕。\n"NOR);
}

void add_decide(string yn, object me, string name, mapping song)
{
	mapping songs;
	if (yn[0] != 'y' && yn[0] != 'Y')
	{
		write("放弃拷贝曲目(a)还是更改曲目名称(c)？");
		input_to("add_continue", me, name, song);
		return;
	}
	write("从玩家推荐曲库拷贝到"+MUD_NAME+"曲库：《" + name + "》\n");
	songs = MUSIC_D->query_PlayerSong(name);
	songs["vouch"] = me->name()+"("+me->query("id")+")";
	MUSIC_D->add_songs(name, songs);
	MUSIC_D->delete_PlayerSongs(name);
	write("清除玩家推荐曲库中本曲信息完毕。\n");
	return;
}

void add_continue(string ac, object me, string name, mapping song)
{
	if (ac[0] == 'a' || ac[0] == 'A')
	{
		write("放弃拷贝曲目： "+name+"\n");
		return;
	}
	if (ac[0] == 'c' || ac[0] == 'C')
	{
		write("请输入更改后的曲目名称：\n");
		input_to("add_ChageName", me, name, song);
		return;
	}
	else
	{
		write("你只能在放弃拷贝曲目(a)还是更改曲目名称(c)中作选择。\n");
		input_to("add_continue", me, name, song);
		return;
	}
}

void add_ChangeName(string newname, object me, string name, mapping song)
{
	mapping songs;
	if(!check_legal_name(newname))
		return;
	if( !undefinedp(MUSIC_D->query_song(newname)) )
	{
		write(MUD_NAME"曲库中已经有同名曲目，是否要覆盖？\n");
		input_to("add_decide",me, name, song);
		return;
	}
	write("从玩家推荐曲库拷贝到"+MUD_NAME+"曲库：《" + name + "》\n");
	songs = MUSIC_D->query_PlayerSong(name);
	songs["vouch"] = me->name()+"("+me->query("id")+")";
	MUSIC_D->add_songs(name, songs);
	MUSIC_D->delete_PlayerSongs(name);
	write("清除玩家推荐曲库中本曲信息完毕。\n");
	return;
}

void delete_all(string yn)
{
	if (yn[0] == 'y' || yn[0] == 'Y')
	{
		write("删除全部玩家推荐曲目。\nOK!\n");
		MUSIC_D->delete_all_PlayerSongs();
		return;
	}
	if (yn[0] == 'n' || yn[0] == 'N')
	{
		write("终止删除操作。\n");
		return;
	}
	else
	{
		write("你确定要删除全部玩家推荐曲目？(y/n)\n");
		input_to("delete_all");
		return;
	}
}

int check_legal_name(string name)
{
        int i;
        i = strwidth(name);        
        if( i < 1 || i > 24  )
        {
                write("辞曲名只能是 1 到 24 个字符。\n");
                return 0;
        }
        while(i--)
        {
                if( name[i]<=' ' && !is_chinese(name[i]) )
                {
                        write("非法曲名！\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_line(string line)
{
        int i;
     
        i = strwidth(line);        
        if( i < 2 || i > 100)
        {
                write("每一行曲词请控制在2-100字符内。\n");
                return 0;
        }
        while(i--)
        {
                if( line[i]<=' ' && !is_chinese(line[i]) )
                {
                        write("歌词行含有非法字符！\n");
                        return 0;
                }
        }
        return 1;
}

int help()
{
write(@HELP

指令格式：music [-c|-d|-rd|-sd|-ad|-r|-l|-rl|-sl] <词曲名>
 
这个指令缺省参数的情况下，即编辑新曲目（巫师编辑曲目直接收入曲库）。
编辑曲目可以在乐器上演奏，如果想推荐给别人，可以使用-r参数发布到玩家推荐
曲目列表中，由巫师决定是否添加到游戏曲库中。一旦添加到曲库，所有玩家都可
以共享这首乐曲。

通过参数控制可以修改，删除乐曲或列出其内容。

参数说明：
-c  [巫师指令]将玩家推荐曲目加入游戏曲库。
-d  [巫师指令]删除游戏曲库中指定曲目。
-rd [巫师指令]删除玩家推荐曲目表中指定曲目。
-ad [巫师指令]清空玩家推荐曲目表中所有曲目。
-sd 删除玩家自己编辑的指定曲目。
-r  玩家推荐自己编辑的曲目。
-l  列出游戏曲库中指定乐曲的内容。<省略词曲名将列出游戏曲库所有曲目列表>
-rl 列出玩家推荐曲目表中指定乐曲的内容。<省略词曲名将列出玩家推荐曲目表>
-sl 列出玩家自己编辑的指定乐曲的内容。<省略词曲名将列出玩家自编辑曲目表>
 
一首曲辞可以有很多行，enter键换行。空白行输入'.' 结束输入该项乐曲。

HELP
    );
    return 1;
}