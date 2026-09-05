//made by  delphi

#include <ansi.h>
#define HELPNEW_LST "/log/helpnew/helpnew_lst"

int main()
{
        string msg;
        string *line;
        int vote_number;
        string lines, my_id, ip_list, victim_id, cname,victim_ip;
        int i, j, k, m;
        mapping *data;
        mapping *list;
                
//  将HELPNEW_LST里的数据读入数组data, 并统计投票者和票数
        lines = read_file(HELPNEW_LST);
        if(lines)
        {
           line = explode(lines, "\n");
           j = 0;
           data = ({});
           for(j=0,m=0;m<sizeof(line);)
           {
               for(i=m;i<sizeof(line);i++)
              {
                 sscanf(line[i],"%s,%s,%s,%s,%s", my_id, ip_list, victim_id, cname,victim_ip);
                 if(i == m) 
                 {
                    for(k=j-1;k>=0;k--) 
                    {
                       if(data[k]["id"] == victim_id) break;
                    }         
                    if(k<0)
                    {
                       data += ({ allocate_mapping(3) });
                       data[j]["id"] = (string)victim_id;
                       data[j]["name"] = (string)cname;
                       data[j]["num"] = 0;
                    }
                    else break;
                 }
                 if(victim_id == data[j]["id"] )  data[j]["num"] = data[j]["num"] + 1;
              }
              m++;
              if(i==sizeof(line)) j++;
           } 
        }
//   投票读数完成


//   将数组data里的内容按票数由大到小排序，并取出前十名放入数组list内
        list = ({});
        k=sizeof(data);
        for(j=0;j<k && j<10;j++)
        {
           for(i=0,m=0,vote_number=0;i<sizeof(data);i++)
           {
              if(data[i]["num"]>vote_number) 
              {
                 vote_number = data[i]["num"];
                 m=i;
              }
           }
           list += ({ allocate_mapping(3) });
           list[j]["id"]=data[m]["id"];
           list[j]["num"]=data[m]["num"];
           list[j]["name"]=data[m]["name"];
           data -= ({ data[m]});
        }
//   排序完成

//   显示列表
        msg = HIR"                  "HIG "◎" + MUD_NAME + HIG "◎" + HIW + "乐于助人排行榜\n"NOR;
        msg +="────────────────────────────────────────────\n\n";
        msg += sprintf("%-20s%-20s%-15s\n","英文名","中文名","票数");
        msg +="────────────────────────────────────────────\n\n";
        for(i=0;i<sizeof(list);i++)
        msg += sprintf("%-20s%-20s%-15d\n",list[i]["id"],list[i]["name"],list[i]["num"]);
        msg +="────────────────────────────────────────────\n\n";                                              
        write(msg);
//完成

        return 1;       
}





int help(object me)
{
write(@HELP
指令格式 : helpnewlist
说明     ：列出帮助新手排行榜。
HELP
    );
    return 1;
}
