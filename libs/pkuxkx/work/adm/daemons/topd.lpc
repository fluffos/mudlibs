// topd.c created by jun
#include <ansi.h>
#define TOP_SIZE 20
#define TOP_LST "/log/doc/top_lst"
mapping *read_text(string file);
mapping *top_lst;
void create()
{
seteuid(getuid());
top_lst = sort_array(read_text(TOP_LST),"sort_user",this_object());
}

void write_list()
{
int i;
string outp;
rm(TOP_LST);
for(i=0;i<sizeof(top_lst);i++)
{
outp = sprintf("%s,%s,%s,%d,%d,%d\n",top_lst[i]["id"],top_lst[i]["name"],
                top_lst[i]["family"],top_lst[i]["exp"],top_lst[i]["pot"],
                top_lst[i]["sum"]);
write_file(TOP_LST,outp,0);
}

}
mapping *read_text(string file)
{
string *line;
mapping *data;
string lines;
int i;
data = ({});
lines= read_file(file);
if(lines)
{
 line = explode(lines, "\n");
 for(i=0;i<sizeof(line);i++)
 {
        data += ({ allocate_mapping(6) });
        sscanf(line[i],"%s,%s,%s,%d,%d,%d",data[i]["id"],
        data[i]["name"],data[i]["family"],data[i]["exp"],data[i]["pot"],
        data[i]["sum"]);
 }
}
return data;
}
int sort_user(mapping a, mapping b)
{
return b["sum"] - a["sum"];
}

void compare_status(object me)
{
mapping mydata;
int i;
int T_ALREADY =0;
if (wiz_level(me) > 0) return;
if (me->query("env/invis") >= 2) return;
if (me->query("no_top")) return;
//if (me->query("combat_exp")>100000000) return;	
//if((int)me->query("mud_age") < 3600) return;
mydata = ([]);
mydata["id"]= (string) me->query("id");
mydata["name"] = (string) me->query("name");
if(me->query("family") == 0)
mydata["family"] = "普通百姓";
else
mydata["family"] = (string) me->query("family")["family_name"];
mydata["exp"] = ((int)me->query("combat_exp")-1990) / ((int) me->query("mud_age")/3600 +1 );
mydata["pot"] = ((int)me->query("potential")-290) /  ((int) me->query("mud_age")/3600 +1 );
mydata["sum"] = ((int)me->query("combat_exp")/100);//+random(100);
// compare with the top list
for(i=0;i<sizeof(top_lst);i++)
if(top_lst[i]["id"] == mydata["id"])
{
        top_lst -= ({ top_lst[i] });
        top_lst += ({ mydata });
        T_ALREADY =1;
        break;

}
if(!T_ALREADY) top_lst += ({ mydata });
top_lst = sort_array(top_lst,"sort_user",this_object());


// check the list size, get rid of extras from the bottom of the list
while(sizeof(top_lst) > TOP_SIZE)
        top_lst -= ({ top_lst[sizeof(top_lst)-1] });

}

string show_top1()
{
int i;
string msg;
msg = HIR"                  "HIG "◎" + MUD_NAME + HIG "◎" + HIW + "高手爬行榜前"+chinese_number(TOP_SIZE)+"名\n"NOR;
msg +="────────────────────────────────────────────\n\n";
msg += sprintf("%-20s%-20s%-10s%-15s%-15s\n",
"英文名","中文名","门派","经验／小时","潜能／小时")
;
 for(i=0;i<sizeof(top_lst);i++)
      msg += sprintf("%-20s%-20s%-15s%-15d%-13d\n",
top_lst[i]["id"],top_lst[i]["name"],top_lst[i]["family"],top_lst[i]["exp"],top_lst[i]["pot"]);
msg +="────────────────────────────────────────────\n\n";
 return msg;
}
string show_top()
{
int i;
string msg;
msg = HIR"                  "HIG "◎" + MUD_NAME + HIG "◎" + HIW + "高手爬行榜前"+chinese_number(TOP_SIZE)+"名\n"NOR;
msg +="────────────────────────────────────────────\n\n";
msg += sprintf("%-15s%-15s%-10s%-15s%-15s%-15s\n",
"英文名","中文名","门派","经验／小时","潜能／小时","综合／统计");
for(i=0;i<sizeof(top_lst);i++)
msg += sprintf("%-15s%-15s%-15s%-15d%-13d%-10d\n",
top_lst[i]["id"],top_lst[i]["name"],top_lst[i]["family"],top_lst[i]["exp"],top_lst[i]["pot"],top_lst[i]["sum"]);
msg +="────────────────────────────────────────────\n\n";
return msg;
}
