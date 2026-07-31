// wenxuan.c
// Copyright (C) XKX Organization 1996. All rights reserved.

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string month;
        int issue, year;
        string filename;
        string text;

        seteuid(geteuid(me));

        if (!arg)
                return notify_fail("指令格式 : wenxuan <月份名> [编号] [年份]\n");

        if (sscanf(arg, "%s %d %d", month, issue, year) != 3)
        {
                year = 2002;
                if (sscanf(arg, "%s %d", month, issue) != 2)
                {
                        month = arg;
                        issue = 0;
                }
        }

        if ( year < 1900)
                year += 1900;

        month = lower_case(month);

        if ( month[0..2] == "jan" || month == "1" )
                month = "Jan";

        else if ( month[0..2] == "feb" || month == "2" )
                month = "Feb";

        else if ( month[0..2] == "mar" || month == "3" )
                month = "Mar";

        else if ( month[0..2] == "apr" || month == "4" )
                month = "Apr";

        else if ( month[0..2] == "may" || month == "5" )
                month = "May";

        else if ( month[0..2] == "jun" || month == "6" )
                month = "Jun";

        else if ( month[0..2] == "jul" || month == "7" )
                month = "Jul";

        else if ( month[0..2] == "aug" || month == "8" )
                month = "Aug";

        else if ( month[0..2] == "sep" || month == "9" )
                month = "Sep";

        else if ( month[0..2] == "oct" || month == "10" )
                month = "Oct";

        else if ( month[0..2] == "nov" || month == "11" )
                month = "Nov";

        else if ( month[0..2] == "dec" || month == "12" )
                month = "Dec";
        else
                return notify_fail("【泥潭文选】你要查阅几月份的文选？\n");

        if ( issue )
                filename = sprintf("/data/wenxuan/%04d/%s/%03d", year, month , issue);
        else
                filename = sprintf("/data/wenxuan/%04d/wenxuan.%s", year, month , issue);
                
//      write("wenxuan: "+ filename + "\n");
        if (file_size(filename) <= 0)           
                return notify_fail("【泥潭文选】你要的那篇还没出版或找不到。\n");

        text = read_file(filename);

        if (!stringp(text))
                return notify_fail("【泥潭文选】你要的那篇还没出版或找不到。\n");

        me->start_more(text);

        return 1;
}


int help(object me)
{
write(@HELP
          　　　【泥潭文选】

指令格式 : wenxuan <月份名> [文章编号] [年份]

“月份”名可以是英文月名（大小写皆可），也可以是数字。
如不指明“文章编号”，则查阅文选该月目录。
“年份”可以是全称，如1997，也可以是缩写，如97。

用例：
    wenxuan Aug        # 查阅文选今年 Aug 卷目录。
    wenxuan 8          # 查阅文选今年 Aug 卷目录。
    wenxuan 8 0 1996   # 查阅文选96年 Aug 卷目录。
    wenxuan Aug 1      # 阅读文选今年 Aug 卷 001 篇。
    wenxuan 8 1        # 阅读文选今年 Aug 卷 001 篇。
    wenxuan sep 2      # 阅读文选今年 Sep 卷 002 篇。
    wenxuan 9 2        # 阅读文选今年 Sep 卷 002 篇。

文选阅读指令:

q      : 离开阅读器。
b      : 显示前一页的内容。
[ENTER]: 显示下一页的内容。

附：有关一般留言版的用途请看help board 。

HELP
    );
    return 1;
}

