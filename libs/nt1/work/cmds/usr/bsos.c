// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#define BSOS_DIR       "/data/bsos/"
#define BSOS_FILENAME  "bsos"

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

mapping *notes;

string query_save_file()
{
        return BSOS_DIR + BSOS_FILENAME ;
}

int help(object me);

void done_post(object me, mapping note, string text)
{
        int i; 
        string *lines;

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "你的留言中短句太多了，请调整一下以便他人阅读。\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "你留言中有些行太长了，请分行以便他人阅读。\n");
                        return;
                }
        }
                                    
        note["msg"] = text;

        if (! pointerp(notes) || ! sizeof(notes))
                notes = ({ note });
        else
        {
                i = sizeof(notes) - 1;
                if (note["time"] <= notes[i]["time"])
                        note["time"] = notes[i]["time"] + 1;
                notes += ({ note });
        }

        set("notes", notes);
        tell_object(me, HIM "求救完毕。你的信息已经被加到巫师通知队列里。\n");
        tell_object(me, HIM "巫师正在处理其他玩家，请等待。\n");
        tell_object(me, HIM "你可以先忙你自己的事情，过一段时间后可以用" NOR + 
                        HIR "bsos read" NOR + HIM "查看是否被解决。\n" NOR);        
        save();
        return;
}

void done_re(object me, mapping report, int project, string text)
{
        int i;
        mapping *reports;
        string *lines;  

        if (! stringp(text))
                return;
                
        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "你的留言中短句太多了，请调整一下以便他人阅读。\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "你留言中有些行太长了，请分行以便他人阅读。\n");
                        return;
                }
        }

        report["msg"] = text;

        reports = notes[project]["re"];
        
        if (! arrayp(reports))  
                reports = ({ report });
        else 
                reports += ({ report });

        notes[project]["re"] = reports;
        notes[project]["time"] = time();

        set("notes", notes);
        tell_object(me, HIW "回复完毕。\n" NOR);

        save();
        return;
}

int do_list() 
{
        int i, last_time_read;
        string msg;
        object me = this_player();      

        if (! pointerp(notes) || ! sizeof(notes)) 
        {
                write("没人发出求救信号。\n");
                return 0;
        }
                
        msg = sprintf("%s已经发出的求救信号列表如下：" HIW "\n────────────────────────────────────────────\n" NOR, 
                      wizardp(me) ? "玩家" : "你");
        
        last_time_read = me->query("board_last_read/bsos");
        
        for (i = 0; i < sizeof(notes); i++) 
        {
                if (wizardp(me) || ! strcmp(me->query("id"), notes[i]["author"]))
                        msg += sprintf("%s[" WHT "%2d" NOR "]" NOR "  %-50s %-12s [%s]\n", 
                                       (notes[i]["time"] > last_time_read ? HIY : ""),
                                       i + 1, notes[i]["title"], 
                                       notes[i]["solve"] == "" ? HIY "No solved   " NOR 
                                                               : "By " + notes[i]["solve"],  
                                       ctime(notes[i]["time"])[0..15]);
        }
        msg += HIW "────────────────────────────────────────────\n" NOR;
        me->start_more(msg);
        return 1;
}

int do_read(string arg) 
{
        int i, num, last_time_read;
        string msg;
        object me = this_player();    
                
        if (! pointerp(notes) || ! sizeof(notes))
        { 
                write("没人发出求救信号。\n");
                return 0;
        }
                
        if (! sscanf(arg, "%d", num))
        {
                write("你要查阅第几个求救信号？\n");
                return 0;
        }
                                                    
        if (num < 1 || num > sizeof(notes))
        {
                write("没有这个求救信号。\n");
                return 0;
        }
        num--;

        if (! wizardp(me) && strcmp(me->query("id"), notes[num]["author"]))
        {
                write("这张求救信号你不能阅读。\n");
                return 0;
        }

        msg = sprintf(
                      "[" WHT "%2d" NOR "]" NOR "  %-50s %-12s [%s]\n────────────────────────────────────────────\n%s\n"
                      "──────────────────────────────────────[" HIW " 本 篇 完 " NOR "]\n",
                      num + 1, notes[num]["title"], 
                      notes[num]["solve"] == "" ? "No solved   " : "By " + notes[num]["solve"],
                      ctime(notes[num]["time"])[0..15], notes[num]["msg"]);
                      
        for (i = 0; i < sizeof(notes[num]["re"]); i++) 
        {
                msg += sprintf(
                               "\n[ " HIW "回复编号：" NOR "%2d] [ " HIW "回复标题：" NOR "%-58s ] \n"
                               "────────────────────────────────────────────\n"
                               "%s\n────────────────────────────────────────────\n[ " HIW "时间：" NOR "%s ] [ "
                               HIW "回复者：" NOR " %41s]\n",
                               i + 1,
                               notes[num]["re"][i]["title"],
                               notes[num]["re"][i]["msg"],
                               ctime(notes[num]["re"][i]["time"]),
                               notes[num]["re"][i]["author"] + "(" +
                               notes[num]["re"][i]["owner"] + ")");
        }
                        
        me->start_more(msg);
        
        last_time_read = me->query("board_last_read/bsos");       
        
        if (notes[num]["time"] > last_time_read)
                me->set("board_last_read/bsos",
                        notes[num]["time"]);
        return 1;
}

int do_solve(string arg)
{
        int num;
        object me = this_player();
        
        if (sscanf(arg, "%d", num) != 1) 
                return help(me);
                
        if (! pointerp(notes) || ! sizeof(notes) ||
            num < 1 || num > sizeof(notes)) 
        {
                write("无此求救信号编号!!\n");
                return 0;
        } 
        if (notes[num-1]["solve"] != "") 
        {
                write(notes[num-1]["solve"] + "已经标志啦!\n");
                return 1;
        }
        notes[num-1]["solve"] = me->query("id");
        
        save();
        write("该求救信息已标志为解决。\n");
        return 1;
}

int main(object me, string arg)
{
        mapping note;
        object where;
        string s, str, arg1, arg2; 
        int i, num;
        string title;

        restore();
        
        notes = query("notes");
        
        if (! arg) 
        {
                if (! wiz_level(me))
                {
                        if (base_name(environment(me)) == "/inherit/room/chatroom")
                                return notify_fail("聊天室内无法发出求助信号！\n");

                        tell_object(me, HIM "你正在" HIY MUD_NAME HIM "里辛苦地挖着泥巴，突然发现一只大个的臭虫向你爬来。\n" NOR);
                        tell_object(me, HIM "你赶紧向巫师们发出紧急求救信号：ＢＳＯＳ！！！\n" NOR);
                        where = environment(me);
                        if (! where) 
                                s = sprintf("%s(%s)求救", (string)me->name(), (string)me->query("id"));
                        else
                                s = sprintf("%s(%s)在%s(%s)求救",
                                            (string)me->name(),
                                            (string)me->query("id"),
                                            clean_color((string)where->query("short")),
                                            (string)file_name(where));
                        note = allocate_mapping(5);
                        note["title"] = s;
                        note["author"] = me->query("id"); 
                        note["time"] = time();
                        note["solve"] = "";
                        me->edit( (: done_post, me, note :) );
                } else 
                {
                        do_list();
                }
                return 1;
        } 

        if (sscanf(arg, "%s %s", arg, arg2) == 2) 
        {
                if (arg == "re")
                {
                        if (sscanf(arg2, "%d.%s", num, title) < 1)
                                return notify_fail("指令格式：bsos re <帖子编号>.<回复标题>\n");
                                
                        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                                return notify_fail("没有这个求救贴子。\n");

                        if (strlen(title) > 30)
                                return notify_fail("这个标题太长了，请换一个简洁一点的。\n");

                        if (! title) 
                                title = "Re: " + notes[num - 1]["title"];
                
                        note = allocate_mapping(5);
                        note["title"] = title;
                        note["owner"] = me->query("id");
                        note["author"] = me->name(1);
                        note["time"] = time();
                        me->edit((: done_re, me, note, num - 1 :));
                        return 1;
                } else                        
                if (arg == "solve")
                {
                        if (! wiz_level(me)) 
                                return help(me);
                        
                        if (arg2 == "all") 
                        {
                                if (! (i = sizeof(notes))) 
                                        return notify_fail("没人发出 BSOS 求救信号。\n");
                                for ( ; i > 0; i-- ) 
                                        notes[i-1]["solve"] = me->query("id");
                                write("所有的求救信息已经标志为解决了。\n");
                                save();
                                return 1;
                        } else
                        {
                                do_solve(arg2);
                                return 1;
                        }
                } else
                if (arg == "read")
                {
                        do_read(arg2);
                        return 1;       
                } else
                return help(me);
        }
                                                                                                    
        if (sscanf(arg, "%s", arg1) == 1) 
        {
                switch(arg1)
                {
                case "list":
                        do_list();
                        break;
                
                case "pack":
                        if (! wiz_level(me)) 
                                return help(me);
                                
                        if (! (i = sizeof(notes))) 
                                return notify_fail("没人发出 BSOS 求救信号。\n");
                                
                        for( ; i > 0; i-- ) 
                        if ("" != notes[i-1]["solve"]) 
                        {
                                printf("%s的 BSOS 求救已被删除！\n", notes[i-1]["author"]);
                                if (sizeof(notes) == 1) 
                                        notes = ({});
                                else 
                                if (i == 1) 
                                        notes = notes[1..sizeof(notes)-1];
                                else 
                                if (i == sizeof(notes)) 
                                        notes = notes[0..sizeof(notes)-2];
                                else 
                                        notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
                                        
                                set("notes", notes);
                        }
                        save();
                        break;
                default:
                        if (sscanf(arg1, "%d", num) == 1) 
                                do_read(arg1);
                                
                        else return help(me);
                        break;
                } 
                return 1;
                        
        } else 
        return help(me);
}

int help(object me)
{
        if (!wiz_level(me) )
        write(@HELP
指令格式 :            
           bsos list
           bsos read
           bsos <贴子编号>
           bsos re <贴子编号>.<回复标题>
这个指令可以在系统出现 BSOS 时来向巫师求助。
输入该命令后，系统将提示你输入对 BSOS 的描述。玩家在这里应该将 
出现的情况和系统的提示尽量详细地进行说明，以便巫师修改该 BSOS。
可以用 bsos read 阅读自己贴出的求救信号。
HELP
        );
        else 
write(@HELP
指令格式 : bsos 
           bsos list
           bsos <贴子编号>                       
           bsos read <贴子编号>            
           bsos solve <贴子编号> 
           bsos pack                                
           bsos re <贴子编号>.<回复标题> 

这个指令可以辅助巫师处理玩家提出的求救信息列表。bsos 和 bsos list 的功能一样，
都是将所有的 bsos 信息进行列表。带参数的 bsos 命令，根据参数的不同，则将显示
对应号码或对应玩家的 bsos 的详细信息。bsos solve用来标志某个bsos已经被解决了。
bsos pack 将删除所有已经标志为解决了的 bsos。
HELP
    );
    return 1;
}

