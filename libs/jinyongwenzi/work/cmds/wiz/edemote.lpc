// edemote.c
// Modified by Numa 1999-11-18 can edit emote by line 

inherit F_CLEAN_UP;

string *line = ({
	"myself",
	"others",
	"myself_self",
	"others_self",
	"myself_target",
	"target",
	"others_target",
});

string *line_info = ({
	"不指定对象使用这个 emote 时，你自己看到的讯息：\n",
	"不指定对象使用这个 emote 时，其他人看到的讯息：\n",
	"对自己使用这个 emote 时，自己看到的讯息：\n",
	"对自己使用这个 emote 时，其他人看到的讯息：\n",
	"对别人使用这个 emote 时，自己看到的讯息：\n",
	"对别人使用这个 emote 时，使用对象看到的讯息：\n",
	"对别人使用这个 emote 时，除你自己和使用对象外，其他人看到的讯息：\n",
});

int main(object me, string arg)
{
        mapping emote;
        mapping tmp;
        string newemote, place;
        int i, j, k, get=0;

        if( !arg ) return notify_fail("你要编辑什么 emote？\n");

        if( sscanf(arg, "-c %s %s", arg, newemote) ) {
                write("拷贝 emote：" + arg + "\n");
                EMOTE_D->set_emote(newemote, EMOTE_D->query_emote(arg));
                return 1;
        }

        if( sscanf(arg, "-d %s", arg) ) {
                write("删除 emote：" + arg + "\n");
                EMOTE_D->delete_emote(arg);
                return 1;
        }

        if( sscanf(arg, "-p %s", arg) ) {
                emote = EMOTE_D->query_emote(arg);
                printf("上次修改：%s\n", emote["updated"]);
                printf("—————————————\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                        emote["myself"], emote["others"], emote["myself_self"],
                        emote["others_self"], emote["myself_target"], emote["target"],
                        emote["others_target"] );
                return 1;
        }
// Here add by Numa for edemote can select line.
	if( sscanf(arg, "-%d %s", i, arg) )
	{
                tmp = EMOTE_D->query_emote(arg);
                emote = (["updated":geteuid(me)]);
		for (j=0;j<7;j++)
                {
                	if (i == j+1)
                	{
                		get = 1;
                		for (k=0;k<7;k++)
                		{
                			emote[line[k]] = tmp[line[k]];
                		}
	                	place = line[j];
        	        	write("编辑 emote：" + arg + "的第"+CHINESE_D->chinese_number(i)+"行：\n");
                		write("————————————————————————————————————\n");
        			write(line_info[j] + tmp[place] + "->");
                		input_to("get_msg_select", place, emote, tmp, arg);
                		return 1;
                	}
                }
                
                if (get == 0)
                	write("你要编辑 emote ("+arg+")的第几行？\n");
                return 1;
        }
// End
        tmp = EMOTE_D->query_emote(arg);
        emote = (["updated":geteuid(me)]);

        write("编辑 emote：" + arg + "\n");
        write("讯息可以有好几行，用 . 表示结束。\n");
        write("讯息中可使用的参数有以下几种：\n");
        write("  $N  自己的名字。\n");
        write("  $n  使用对象的名字。\n");
        write("  $P  自己的人称代名词，如你、他、她、它。\n");
        write("  $p  使用对象的人称代名词，如你、他、她、它。\n");
        write("  $S  对自己的称呼。\n");
        write("  $s  对自己的粗鲁称呼。\n");
        write("  $C  对自己的呢称。\n");
        write("  $c  对别人的呢称。\n");
        write("  $R  对别人的尊称。\n");
        write("  $r  对别人的粗鲁称呼。\n");
        write("————————————————————————————————————\n");
        write("不指定对象使用这个 emote 时，你自己看到的讯息：\n" + tmp["myself"] + "->");
        input_to("get_msg_myself", emote, tmp, arg);
        return 1;
}

int get_msg_select(string msg, string place, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote[place])) {
                emote[place] = tmp[place];
                msg=".";
        }
        if (msg==".") {
                EMOTE_D->set_emote(pattern, emote);
                write("Emote 编辑完毕。\n");
                return 1;
        }
        emote[place] = msg + "\n";
        write("->");
        input_to("get_msg_select", place, emote, tmp, pattern);
        return 1;
}

int get_msg_myself(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["myself"])) {
                emote["myself"] = tmp["myself"];
                msg=".";
        }
        if (msg==".") {
                write("不指定对象使用这个 emote 时，其他人看到的讯息：\n" + tmp["others"] + "->");
                input_to("get_msg_others", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself"]) )
                emote["myself"] += msg + "\n";
        else emote["myself"] = msg + "\n";
        write("->");
        input_to("get_msg_myself", emote, tmp, pattern);
        return 1;
}

int get_msg_others(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["others"])) {
                emote["others"] = tmp["others"];
                msg=".";
        }
        if (msg==".") {
                write("对自己使用这个 emote 时，自己看到的讯息：\n" + tmp["myself_self"] + "->");
                input_to("get_msg_myself_self", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["others"]) )
                emote["others"] += msg + "\n";
        else emote["others"] = msg + "\n";
        write("->");
        input_to("get_msg_others", emote, tmp, pattern);
        return 1;
}

int get_msg_myself_self(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["myself_self"])) {
                emote["myself_self"] = tmp["myself_self"];
                msg=".";
        }
        if (msg==".") {
                write("对自己使用这个 emote 时，其他人看到的讯息：\n" + tmp["others_self"] + "->");
                input_to("get_msg_others_self", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself_self"]) )
                emote["myself_self"] += msg + "\n";
        else emote["myself_self"] = msg + "\n";
        write("->");
        input_to("get_msg_myself_self", emote, tmp, pattern);
        return 1;
}

int get_msg_others_self(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["others_self"])) {
                emote["others_self"] = tmp["others_self"];
                msg=".";
        }
        if (msg==".") {
                write("对别人使用这个 emote 时，自己看到的讯息：\n" + tmp["myself_target"] + "->");
                input_to("get_msg_myself_target", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["others_self"]) )
                emote["others_self"] += msg + "\n";
        else emote["others_self"] = msg + "\n";
        write("->");
        input_to("get_msg_others_self", emote, tmp, pattern);
        return 1;
}

int get_msg_myself_target(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["myself_target"])) {
                emote["myself_target"] = tmp["myself_target"];
                msg=".";
        }
        if (msg==".") {
                write("对别人使用这个 emote 时，使用对象看到的讯息：\n" + tmp["target"] + "->");
                input_to("get_msg_target", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself_target"]) )
                emote["myself_target"] += msg + "\n";
        else emote["myself_target"] = msg + "\n";
        write("->");
        input_to("get_msg_myself_target", emote, tmp, pattern);
        return 1;
}

int get_msg_target(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["target"])) {
                emote["target"] = tmp["target"];
                msg=".";
        }
        if (msg==".") {
                write("对别人使用这个 emote 时，除你自己和使用对象外，其他人看到的讯息：\n" + tmp["others_target"] + "->");
                input_to("get_msg_others_target", emote, tmp, pattern);
                return 1;
        }
        if( !undefinedp(emote["target"]) )
                emote["target"] += msg + "\n";
        else emote["target"] = msg + "\n";
        write("->");
        input_to("get_msg_target", emote, tmp, pattern);
        return 1;
}

int get_msg_others_target(string msg, mapping emote, mapping tmp, string pattern)
{
        if (msg=="" && undefinedp(emote["others_target"])) {
                emote["others_target"] = tmp["others_target"];
                msg=".";
        }
        if (msg==".") {
                EMOTE_D->set_emote(pattern, emote);
                write("Emote 编辑结束。\n");
                return 1;
        }
        if( !undefinedp(emote["others_target"]) )
                emote["others_target"] += msg + "\n";
        else emote["others_target"] = msg + "\n";
        write("->");
        input_to("get_msg_others_target", emote, tmp, pattern);
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : edemote [-c|-d|-p|-数字] <emote>
 
这个指令可以修改，删除 emote 或列出其内容。加上 -d 参数会删除
指定的 emote。-p 参数则会列出指定 emote 的内容(列出的顺序与编
辑 emote 时相同)。-数字 参数则可以编辑指定 emote 的指定行(范围
是从1->7)。
 
输入 emote 讯息时有三个项目: 没有目标, 指定目标或是对自己. 若
不想有某项讯息, 则直接在空白行输入 '.' 跳过.
 
一个 emote 讯息可以有很多行, 在空白行输入 '.' 结束输入该项 emote.
 
编辑 emote 时可以用以下的符号来表示:
 
$N : 自己的名字.
$n : 目标的名字.
$P : 自己的人称代名词.
$p : 目标的人称代名词.
$S : 对自己的称呼。
$s : 对自己的粗鲁称呼。
$C : 对自己的呢称。
$c : 对别人的呢称。
$R : 对别人的尊称。
$r : 对别人的粗鲁称呼。
HELP
    );
    return 1;
}
