/* Created by ???
 * Updated by lonely
 * Paiban /d/ 就会将整个 /d/ 目录下面所有子目录的房间描述统一成 30 个
 * 汉字一行。这个命令只能 Paiban /d/ 和 /u/, 不允许更换其他目录。每行
 * 30 个字满了以后，检测下一行的头一个字是不是标点符号，如果是， 就将
 * 该标点符号加到当前这一行。不过特定的房间的描述将会被打乱，如果是比
 * 较特殊的排版方法的话，比如
 * 剑    刀
 * 试    横
 * 天    九
 * 下    州
 * 这样的房间描述，只好手动改回来。
 * 第一行为 28 个汉字(by Lonely)，保留 @LONG LONG 的格式。
 */

#pragma save_binary

#include <ansi.h>

inherit F_CLEAN_UP;

string format_room_long(string roomlong1, int count);
int    save_room_long(string roomlong, string file);
string get_room_long(string file);
int    is_punctuation(string str);
int    help(object me);

void create() { seteuid(getuid()); } 

int main(object me, string arg)
{

        int j, num, k, i, w, count;
        string dir, roomlong;
        mixed *file, *d_dir;
        
        seteuid(getuid());
        
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;
                
        if (! arg || sscanf(arg, "%s %d", dir, count) != 2) 
                return help(me);
                
        if (count < 20 || count > 40)
                return notify_fail("每行的字数不能太少，也不能太多，要保持在 20 到 40 个之间。\n");
                       
        dir = resolve_path(me->query("cwd"), dir);
        
        if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/' ) 
                dir += "/";
        
        if (dir[0..2] != "/d/" && dir[0..2] != "/u/")
                return notify_fail("这个命令只允许更改/d/ /u/ 目录下面的房间描述。\n");

        file = get_dir(dir, -1);
        
        if (! sizeof(file))
        {
                if (file_size(dir) == -2) 
                        return notify_fail("目录是空的。\n");
                else
                        return notify_fail("没有这个目录。\n");
        }
        message_system("整理批量档案中，请稍候..."); 
        
        roomlong = "";
        num = 0;               
        i = sizeof(file);
        w = 0;
        
        while (i--) 
        {
                if (file[i][1]== -2) 
                        file[i][0] += "/";
                        
                if (strlen(file[i][0]) > w) 
                        w = strlen(file[i][0]) + 1;
        }
        
        write("目录：" + dir + "\n");
        
        if (sizeof(file))
        {               
                for (i = 0, j = sizeof(file); i < j; i++)
                {
                        reset_eval_cost();
                        
                        if (file[i][0][0..0] == ".") 
                                continue;
                        // col = sizeof(file[i][0]);
                        
                        if (file[i][1] > 0 && sscanf(dir + file[i][0], "%*s.c"))
                        {
                                // reset_eval_cost();
                                // write("file is " + dir + file[i][0] + "\n");
                                roomlong = get_room_long(dir + file[i][0]);
                                
                                if (roomlong == "") 
                                        continue;
                                
                                roomlong = format_room_long(roomlong, count); 
                                // 获取整理过的 long
                                save_room_long(roomlong, dir + file[i][0]);
                                // 重新写入源文件
                                num++;
                                
                                // return 1;
                        }
                        write(dir + file[i][0] + "读入\n");
                }
        
        } else 
                write("没有任何档案。\n");
                
        write(HIR "有" + num + "个房间被替换掉。\n" NOR);
        message_system("整理批量完毕，请继续进行游戏..."); 
        return 1;       
}


string get_room_long(string file)
{
        
        string roomlong, err;
        object room;
        
        err = catch(call_other(file, "???"));
        
        if (err) 
                return "";
        /*        
        call_other(file, "???");
        room = find_object(file + ".c");
        if (! objectp(room = find_object(file + ".c")))
                room = load_object(file + ".c");
        */
        room = get_object(file + ".c");
            
        if (! room) 
                return "";
        
        // if (! inherits(ROOM, room)) 
        if (! room->is_room())
                return ""; 
        
        roomlong = room->query("long");
        
        destruct(room);
        
        if (! roomlong) 
                return "";
                
        return roomlong;

}


string format_room_long(string roomlong1, int count)
{

        int i, j, hang, x, y, z, aa, last;
        int count1, count2, count4, count5, count6;
        string roomlong2;
        
        roomlong1 = replace_string(roomlong1, "\n", "");
        roomlong1 = replace_string(roomlong1, " ", "");
        roomlong1 = replace_string(roomlong1, "\"", "");
        roomlong1 = replace_string(roomlong1, "\t", "");
        roomlong1 = replace_string(roomlong1, ",", "，");
        roomlong1 = replace_string(roomlong1, ".", "。");
        roomlong1 = replace_string(roomlong1, "?", "？");
        roomlong1 = replace_string(roomlong1, ";", "；");
        roomlong1 = replace_string(roomlong1, ":", "：");
        roomlong1 = replace_string(roomlong1, "!", "！");
        
        roomlong2 = "";
        
        if (! roomlong1) 
                return "";
                
        x = 0; 
        y = 0; 
        i = sizeof(roomlong1);
        count *= 2;
        count1 = count - 1;
        count2 = count - 2;
        count4 = count - 4;
        count5 = count - 5;
        count6 = count - 6;
        
        hang = i / count;         
        z = 0;
        z = i % count;
        
        if (z != 0) 
                hang++;
        
        last = 0;
        roomlong2 = "\n" + roomlong2;
        
        for (x = 0; x < hang; x++)
        {
                aa = 0;
                if (last > i - 1) 
                        break;
                // 防止 last 超出字符范围
                
                if (hang - x == 1) // 到最后一行 
                {
                        roomlong2 = roomlong2 + roomlong1[last..i-1] + "\n";
                                break;
                } else 
                if (x == 0)
                { // 第一行为 28 个汉字
                        for (j = 0; j < count4; j++)
                        {
                                if (last + j > i - 1) 
                                        break;
                                
                                if (roomlong1[last + j] <= 160) // 不是中文字
                                        aa++;
                                        
                                else 
                                        continue;
                        }
                        
                        if (aa % 2 != 0) // 这一行有几个非中文字，要做特殊处理，行的最大数字 + 1
                        {
                                roomlong2 = roomlong2 + roomlong1[last..last + count6];
                                // 这一行最大字母数加一
                                last = last + count5;
                                if ((i - 1) - last >= 1) // 下一行至少还有2个字符的位置，判断下面一行的开头是不是标点符号
                                {
                                
                                        if (is_punctuation(roomlong1[last..last + 1]) != -1) // 判断是否中文标点符号
                                        {                                
                                                roomlong2 = roomlong2 + roomlong1[last..last + 1] + "\n";
                                                last += 2;
                                                continue;
                                        }
                                        if (is_punctuation(roomlong1[last..last]) != -1) // 英文标点符号
                                        {                               
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;
                                } else 
                                if ((i - 1) - last >= 0) // 下一行至少还有一个字符的位置，判断它的开头是不是英文标点
                                {
                                        if (is_punctuation(roomlong1[last..last]) != -1)
                                        {                                
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;       
                                }
                        }
                        else // 这一行 28 个全部都是中文
                        {
                                roomlong2 = roomlong2 + roomlong1[last..last + count5];
                                last = last + count4;
                                if ((i - 1) - last >= 1) // 下一行至少还有 2 个字符的位置，判断下面一行的开头是不是标点符号
                                {
                                        if (is_punctuation(roomlong1[last..last + 1]) != -1) // 中文标点符号
                                        {  
                                                write("roomlong1[last..last+1]     is     \t" + roomlong1[last..last + 1] + "\n");
                                                roomlong2 = roomlong2 + roomlong1[last..last + 1] + "\n";
                                                last += 2;
                                                continue;
                                        }
                                        if (is_punctuation(roomlong1[last..last]) != -1) // 英文标点符号
                                        {
                                                write("\t roomlong1[last..last] is \t" + roomlong1[last..last] + "\n");
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;       
                                } else 
                                if ((i - 1) - last >= 0) // 下一行至少还有一个字符的位置，判断它的开头是不是英文标点
                                {
                                        if (is_punctuation(roomlong1[last..last]) != -1)
                                        {
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;       
                                }
                                roomlong2 = roomlong2 + "\n";
                        }
                }
                else{

                        for (j = 0; j < count; j++)
                        {
                                if (last + j > i - 1) 
                                        break;
                                        
                                if (roomlong1[last + j] <= 160) // 不是中文字
                                        aa++;
                                else 
                                        continue;
                        }
                        if (aa % 2 != 0) // 这一行有几个非中文字，要做特殊处理，行的最大数字 + 1
                        {

                                roomlong2 = roomlong2 + roomlong1[last..last + count2];
                                // 这一行的最大字数加一
                                last = last + count1;
                                
                                if ((i - 1) - last >= 1) // 下一行至少还有2个字符的位置，判断下面一行的开头是不是标点符号
                                {
                                
                                        if (is_punctuation(roomlong1[last..last + 1]) != -1) // 判断是否中文标点符号
                                        {                                
                                                roomlong2 = roomlong2 + roomlong1[last..last + 1] + "\n";
                                                last += 2;
                                                continue;
                                        }
                                        if (is_punctuation(roomlong1[last..last]) != -1) // 英文标点符号
                                        {                               
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;
                                } else 
                                if ((i - 1) - last >= 0) // 下一行至少还有一个字符的位置，判断它的开头是不是英文标点
                                {
                                        if (is_punctuation(roomlong1[last..last]) != -1)
                                        {                                
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;       
                                }
                                // roomlong2 = roomlong2 + "\n";
                                
                        } else // 这一行 30 个全部都是中文
                        {
                                // write_file("/u/lonely/hang.txt", roomlong1[last..last+59] + "\n", 0);
                                roomlong2 = roomlong2 + roomlong1[last..last + count1];
                                last = last + count;                               
                                // write("last is\t" + last + "\t roomlong1[last..last]     is \t" + roomlong1[last..last] + "\n");
                                
                                if ((i - 1) - last >= 1) // 下一行至少还有 2 个字符的位置，判断下面一行的开头是不是标点符号
                                {
                                        if (is_punctuation(roomlong1[last..last + 1]) != -1) // 中文标点符号
                                        {  
                                                write("roomlong1[last..last+1]     is     \t" + roomlong1[last..last + 1] + "\n");
                                                roomlong2 = roomlong2 + roomlong1[last..last + 1] + "\n";
                                                last += 2;
                                                continue;
                                        }
                                        if (is_punctuation(roomlong1[last..last]) != -1) // 英文标点符号
                                        {
                                                write("\t roomlong1[last..last] is \t" + roomlong1[last..last] + "\n");
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;       
                                } else 
                                if ((i - 1) - last >= 0) // 下一行至少还有一个字符的位置，判断它的开头是不是英文标点
                                {
                                        if (is_punctuation(roomlong1[last..last]) != -1)
                                        {
                                                roomlong2 = roomlong2 + roomlong1[last..last] + "\n";
                                                last++;
                                                continue;
                                        }
                                        roomlong2 = roomlong2 + "\n";
                                        continue;       
                                }
                                roomlong2 = roomlong2 + "\n";
                                
                        }

                }
        }
        return roomlong2;
        
}

int save_room_long(string roomlong, string file)
{
        string file_str, all, str1;
        int i, j, k;
        
        // file += ".c";
        
        if (! roomlong || roomlong == "") 
                return 0;
                
        roomlong = "set(\"long\", @LONG" + roomlong + "LONG );";
        
        if (! stringp(str1 = read_file(file, 0)))    
                return 0;
        
        all = str1; // 整个文件
        i = strsrch(str1, "create("); // 房间 create 找到
        j = strsrch(str1[i..], "set(\"long\","); // set("long",) 描述起始行找到
        
        if (i < 0 || j < 0) 
                return 0; // 确认是不是房间
                
        k = strsrch(str1[i+j..], ");"); // 描述结束行找到
        
        if (k < 0) 
                return 0;
                
        file_str = all[0..i+j-1] + roomlong + all[i+j+k+2..];
        
        write_file(file, file_str, 1);
        return 1;
}


int is_punctuation(string str)
{
        string *punctuation;
        
        punctuation = ({
                ",",
                ".",
                "?",
                ";",
                ":",
                "!",
                ")",
                "，",
                "。",
                "？",
                "；",
                "：",
                "！",
                "）",
                "、",
        });
        
        if (! str) return -1;
        return member_array(str, punctuation);
}

int help(object me) 
{
        write(@HELP 
指令格式 : typeset|paiban <目录名> <字数>

这个指令可以将某个目录下所有的房间的长描述自动排版成每行为指
定数目的汉字，当然第一行是少二个汉字，同时每行按指定的字数满
了以后，检测下一行的头一个字是不是标点符号，如果是，就将该标
点符号加到当前这一行，这样房间的描述就会很整齐。本指令还具有
将半角标点符号自动转换为全角中文标点符号的功能。
HELP ); 
        return 1; 
}
