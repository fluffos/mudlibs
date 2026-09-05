// modify by chui
#include <ansi.h>
#include <mudlib.h>
#define TOPTEN_RICH "/adm/etc/top/rich"
#define TOPTEN_PKER "/adm/etc/top/pker"
#define TOPTEN_EXP "/adm/etc/top/exp"
#define TOPTEN_AGE "/adm/etc/top/age"
#define TOPTEN_BEAUTY "/adm/etc/top/beauty"
#define TOPTEN_HANDSOME "/adm/etc/top/handsome"
#define RICH_B "北大侠客行十大富翁爬行榜"
#define PKER_B "北大侠客行十大杀手爬行榜"
#define EXP_B "北大侠客行十大快手爬行榜"
#define AGE_B "北大侠客行十大老手爬行榜"
#define BEAUTY_B "北大侠客行十大美女排行榜"
#define HANDSOME_B "北大侠客行十大帅哥排行榜"
int paiming;
void topten_checkplayer(object);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
int how_many_money(object ob);
string topten_query(string);
int rm_prev_logs();

int rm_prev_logs()
{
        rm(TOPTEN_RICH);
        rm(TOPTEN_PKER);
        rm(TOPTEN_EXP);
        rm(TOPTEN_AGE);
        rm(TOPTEN_BEAUTY);
        rm(TOPTEN_HANDSOME);
        return 1;
}
void topten_checkplayer(object player)
{
        paiming=0;
        topten_add(player,"rich");
        topten_add(player,"pker");
        topten_add(player,"exp");
        topten_add(player,"age");
        topten_add(player,"beauty");
        topten_add(player,"handsome");
        return;
}

int topten_save(string f_name,string b_name,string str)
{
        string *astr;
        int i;
        astr=explode(str,"\n");
        str="";
        for(i=0;i<sizeof(astr)&&i<10;i++)
        str+=astr[i]+"\n";
        if(!write_file(f_name,str,1))
        return notify_fail("无法写文件"+f_name+"，权限不够!不能更新"+b_name+"!\n");
        if(paiming>0&&paiming<=10)
        write("\t你名列最近"YEL + b_name +NOR "第"RED + chinese_number(paiming)+ NOR"名!!\n");   

        paiming=0;
        return 1;
}

string topten_query(string type)
{
        string b_name,f_name,str,*astr,*bstr,title,name,id,score;
        int i,j,k,data;
        string *top = ({
                YEL"    ΩΩΩΩΩΩΩ=  北大侠客行十大富翁爬行榜  =ΩΩΩΩΩΩΩ\n",
                GRN"    ♀♀♀♀♀♀♀=  北大侠客行十大快手爬行榜  =♀♀♀♀♀♀♀\n",
                RED"    ※※※※※※※=  北大侠客行十大杀手爬行榜  =※※※※※※※\n",
                CYN"    ≈≈≈≈≈≈≈=  北大侠客行十大老手排行榜  =≈≈≈≈≈≈≈\n",
                BLU"    〓〓〓〓〓〓〓= 北大侠客行十大"HIR"美女"BLU"排行榜  =〓〓〓〓〓〓〓\n",
                MAG"    〓〓〓〓〓〓〓= 北大侠客行十大"HIC"帅哥"MAG"排行榜  =〓〓〓〓〓〓〓\n",
                });
        string *bottom = ({
                YEL"    ΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩΩ\n"NOR,
                GRN"    ♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂\n"NOR,
                RED"    ※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"NOR,
                CYN"    ≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n"NOR,
                BLU"    〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"NOR,
                MAG"    〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n"NOR,
                });
        string *middle = ({
                YEL"    ＄                                                    ＄\n",
                GRN"    ☆                                                    ☆\n",
                RED"    ★                                                    ★\n",
                CYN"    §                                                      §\n",
                BLU"    △                                                    △\n",
                MAG"    ◆                                                    ◆\n",
                });
        string *str_left = ({
                YEL"    ＄ "MAG,
                GRN"    ☆ "YEL,
                RED"    ★ "BLU,
                CYN"    § "YEL,
                BLU"    △ "MAG,
                MAG"    △ "HIC,
                });
        string *str_center = ({
                GRN,
                CYN,
                MAG,
                WHT,
                CYN,
                BLU,
                });
        string *str_right = ({
                YEL "＄\n"NOR,
                GRN "☆\n"NOR,
                RED "★\n"NOR,
                CYN "§\n"NOR,
                BLU "△\n"NOR,
                MAG "△\n"NOR,
                });
        
        switch(type)
        {
                case "rich":
                        k=0;
                        b_name=RICH_B;
                        f_name=TOPTEN_RICH;
                        break;
                case "pker":
                        k=2;
                        b_name=PKER_B;
                        f_name=TOPTEN_PKER;
                        break;
                case "exp":
                        k=1;
                        b_name=EXP_B;
                        f_name=TOPTEN_EXP;
                        break;
                case "age":

                        k=3;
                        b_name=AGE_B;
                        f_name=TOPTEN_AGE;
                        break;
                case "beauty":
                        k=4;
                        b_name=BEAUTY_B;
                        f_name=TOPTEN_BEAUTY;
                        break; 
                case "handsome":
                        k=5;
                        b_name=HANDSOME_B;
                        f_name=TOPTEN_HANDSOME;
                        break;      
                default:
                        return "对不起，暂时没有这种排行榜！\n";
        }
        if(file_size(f_name)==-1)
        return b_name+"的数据文件还没有创建！\n";
        astr=explode(read_file(f_name),"\n");
        str=top[k]+middle[k];
        paiming=0;
        for(i=0;i<sizeof(astr)&&paiming<10;i++)
        {
                
                bstr=explode(astr[i],";");
        for(j=0;j<sizeof(bstr)&&paiming+j<10;j++)
                {
                        if(sscanf(bstr[j],"%s(%s)%d",name,id,data)!=3)
                return "数据错误!文件："+f_name+"第"+i+"行第"+j+"项！\n"+
                                "该行数据："+bstr[j]+"\n";
        title ="排行第"+chinese_number(paiming+1)+"：";
        if(j>=1) title ="并列第"+chinese_number(paiming+1)+":";
        score=sprintf("%d",data);
        if (type == "rich")
        {
                if (data>=10000)
                        score = sprintf("%d两黄金",(int)data/10000);
                else if (data >=100)
                        score = sprintf("%d两白银",(int)data/100);
                else
                        score = sprintf("%d个铜板",data);
        }
        if (type == "pker")
                score = sprintf("杀%d人",data);
        if (type == "exp")
                score = sprintf("%d/小时",data);
        if (type == "age")
                score = sprintf("%d岁",14+data);
        if (type == "beauty")
                score = sprintf("%d点容貌－年龄",data);
        if (type == "handsome")
                score = sprintf("%d点容貌－年龄",data);

        str += str_left[k] +  sprintf("%12s %s %-20s%-14s   %2s", title, str_center[k], name+"("+id+")",score,str_right[k]);
                }
                paiming+=sizeof(bstr);
            }
        str+=middle[k];
        str+=bottom[k];
        return str;
}

int get_all_data(object player,string type)
{
        int total;
        switch(type)
        {
                case "rich":
                        total=how_many_money(player);
                        break;
                case "pker":
                        total=(int)player->query("PKS");
                        break;
                case "exp":
                          total=(int)(player->query("combat_exp")/(int)(1+(player->query("mud_age")/3600)));
                        break;

                case "age":
                        total=(int)player->query("mud_age")/(3600*24);
                        break;
                case "beauty":
                        total=(int)player->query("per") - (int)player->query("age")/2;
                        break;
                case "handsome":
                        total=(int)player->query("per") - (int)player->query("age")/2;
                        break;
                default:
                        total=-1;//用-1标志类型出错！
        }
        return total;
}

int topten_del(string pid,string type)
{
        string str,*astr,*bstr,name,id,b_name,f_name;
        int i,j,k,money;
        switch(type)
        {
                case "rich":
                        b_name=RICH_B;
                        f_name=TOPTEN_RICH;
                        break;
                case "pker":
                        b_name=PKER_B;
                        f_name=TOPTEN_PKER;
                        break;
                case "exp":
                        b_name=EXP_B;
                        f_name=TOPTEN_EXP;
                        break;
                case "age":
                        b_name=AGE_B;
                        f_name=TOPTEN_AGE;
                        break;
                case "beauty":
                        b_name=BEAUTY_B;
                        f_name=TOPTEN_BEAUTY;
                        break;
                case "handsome":
                        b_name=HANDSOME_B;
                        f_name=TOPTEN_HANDSOME;
                        break;
               default:
                        return notify_fail("没有"+type+"这种排行榜！\n");
        }
        if(file_size(f_name)==-1)       return notify_fail(b_name+"还没有创建！\n");
        str=read_file(f_name);
        astr=explode(str,"\n");
        for(i=0;i<sizeof(astr);i++)
        {
                if(strsrch(astr[i],pid)!=-1)//该行包括id则为真
                {
                        if(strsrch(astr[i],";")==-1)
                        //为真表示该行只有一个id，即pid
                        {
                                str="";
                                for(j=0;j<sizeof(astr);j++)
                                        if(j!=i)
                                                str+=astr[j]+"\n";
                                return topten_save(f_name,b_name,str);
                        }
                        else
                        {
                                bstr=explode(astr[i],";");
                                for(j=0;j<sizeof(bstr);j++)
                                        if(strsrch(bstr[j],pid)!=-1)//说明该项即pid,应该去除
                                        {
                                                astr[i]="";
                                                for(k=0;k<sizeof(bstr);k++)
                                                        if(k!=j)
                                                        {
                                                                if((k+1)!=sizeof(bstr)
                                                                        &&!((j+1)==sizeof(bstr)&&j==(k+1))

                                                                )
                                                                        astr[i]+=bstr[k]+";";
                                                                else
                                                                        astr[i]+=bstr[k];
                                                        }
                                                //本来去除后j的循环应该停止,但是不影响结果
                                        }
                                str=implode(astr,"\n");
                                return topten_save(f_name,b_name,str);
                        }
                }
        }
        return 1;
}

int topten_add(object player,string type)
{
        string str,name,id,str1,b_name,f_name;
        string *astr;
        int i,j,data;
                if(wizardp(player))//禁止巫师参加排行榜
                return 0;
                if (player->query("env/invis")>=1)
                return 0;
        switch(type)
        {
                case "rich":
                        b_name=RICH_B;
                        f_name=TOPTEN_RICH;
                        break;
                case "pker":
                        b_name=PKER_B;
                        f_name=TOPTEN_PKER;
                        break;
                case "exp":
                        b_name=EXP_B;
                        f_name=TOPTEN_EXP;
                        break;
                case "age":
                        b_name=AGE_B;
                        f_name=TOPTEN_AGE;
                        break;
                case "beauty":
                        b_name=BEAUTY_B;
                        f_name=TOPTEN_BEAUTY;
                        break;
                case "handsome":
                        b_name=HANDSOME_B;
                        f_name=TOPTEN_HANDSOME;
                        break;
                default:
                        return notify_fail("没有"+type+"这种排行榜！\n");
        }
        if(!objectp(player)||!userp(player))
                return 0;
        if (type == "beauty" && player->query("gender")!="女性")
                return 0;
        if (type == "handsome" && player->query("gender") =="女性")
                return 0;

//f_name为空.
        if(file_size(f_name)==-1)
        {
                str=player->query("name")+"("+player->query("id")+")"+
                        get_all_data(player,type);
        paiming=1;
        return topten_save(f_name,b_name,str);
        }
        //主要程序！
        if(get_all_data(player,type)==-1)
                return notify_fail("数据查询错误，可能是查询类型错误！\n");
        //关键词为零，不记入排行。
        if(get_all_data(player,type)==0)
        return 0;
        //应该先排除该player的id!
        topten_del(player->query("id"),type);
        str=read_file(f_name);
        astr=explode(str,"\n");
        i=0;

        while(i<sizeof(astr))
        {
                //判断/topten下的*.txt文件格式是否符合要求
                    if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3)
                        if(sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)
                                return notify_fail(b_name+"文件数据错误！请呼叫巫师！\n");
                str="";
//                排名上升。
                if(data<(int)get_all_data(player,type))
                {
                
                        //单独加入，暂时没考虑人数超过十行！
                        for(j=0;j<sizeof(astr);j++)
                        {
                                
                                if(j==i)
                                str+=player->query("name")+"("+player->query("id")+")"+
                                                get_all_data(player,type)+"\n";
                                str+=astr[j]+"\n";
                        }
                paiming=i+1;
                return topten_save(f_name,b_name,str);
                }

                else
// 并列排名
                if(data==(int)get_all_data(player,type))
                {

                        for(j=0;j<sizeof(astr);j++)
                        {
                                if(j==i)
                                        str+=astr[j]+";"+player->query("name")+
                                                "("+player->query("id")+")"+get_all_data(player,type)+"\n";
                                else
                                        str+=astr[j]+"\n";
                        }
        paiming=i+1;
        return topten_save(f_name,b_name,str);
                }
                i++;
        }
        if(sizeof(astr)<10)
        {
                paiming=sizeof(astr)+1;
                str=implode(astr,"\n")+"\n"+player->query("name")+"("+player->query("id")+
                        ")"+get_all_data(player,type);
                return topten_save(f_name,b_name,str);
        }
        return 0;
}
int how_many_money(object ob)
{
        int total;
        int total2;
        object gold,silver,coin,cash;
        total = 0;
        total2 = 0;                  
        gold   = present("gold",ob);
        silver = present("silver",ob);
        coin   = present("coin",ob);
        cash   = present("thousand-cash",ob);
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();
        if(cash) total += cash->value();
        total2 = (int)ob->query("balance");
        if (!total2 || total2 < 0) {
        ob->set("balance", 0);
    }
    total=total+total2;
    return total;
}

