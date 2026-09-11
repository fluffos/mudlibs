//create by suicide@sgz in 2000/02/28 for top 50 
int cal_sgrate(string id)
{mixed c;
 int rate,ext_skil;
 c = CHAR_D->get_char(id,"");
 if(sizeof(c["skills"])) 
   {
foreach(string s,int r in c["skills"])
           ext_skil+=r;
   }
 rate = (c["skills"]["sk_wuli"]+c["skills"]["sk_meili"]+c["skills"]["sk_zhimou"])*20
         +ext_skil*10+c["reputation"]/100
         +c["literate"]*2+c["ju"]*1000
 +CHAR_D->get_char(id,"nationcontribution")/10;
 return rate;
}
	
string get_top(string prop)
{
string *ids;
mapping title =([
"reputation" :"排名  ID          姓名        所属国    年龄  性别  声望      \n",
"literate"   :"排名  ID          姓名        所属国    年龄  性别  文学修养  \n",
"sgrate"     :"排名  ID          姓名        所属国    年龄  性别  三国等级点\n",
"beauty"     :"排名  ID          姓名        所属国    年龄  性别  容貌\n",
"handsome"   :"排名  ID          姓名        所属国    年龄  性别  容貌\n",
"sk_wuli"    :"排名  ID          姓名        所属国    年龄  性别  武力\n",
"sk_meili"   :"排名  ID          姓名        所属国    年龄  性别  魅力\n",
"sk_zhimou"  :"排名  ID          姓名        所属国    年龄  性别  智力\n",
"age"        :"排名  ID          姓名        所属国    年龄  性别  年龄\n",
"newbie"     :"排名  ID          姓名        所属国    年龄  性别  三国等级点\n",
"nationcontribution":"排名  ID          姓名        所属国    年龄  性别  国家贡献\n"
]);
 string msg="";
 mixed c;
 int MAX=50;
 ids = CHAR_D->check_char("type",1);
 ids = filter_array(ids, (: !wizardp($1) :));
 ids = filter_array(ids, (: CHAR_D->get_char($1,"level") :));
 switch (prop)
 {
  case "sgrate"     :
case "newbie"    :
    {
if (prop=="newbie")
ids = filter_array(ids, (: (CHAR_D->get_char($1,"age")<18) :));
     ids= sort_array(ids, (: ((cal_sgrate($1) >
                               cal_sgrate($2) ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "男性" :"女性" ),
             cal_sgrate(ids[i]));
        }
      return msg;      
     }
 	
  case "reputation" :
  case "literate"   :
  case "age"        :
  case "nationcontribution" :
  {
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,$(prop)) >
                      CHAR_D->get_char($2,$(prop)) ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "男性" :"女性" ),
             CHAR_D->get_char(ids[i],prop));
        }
      return msg;      
     }
  case "beauty"     :
  case "handsome"   :
  
    {
     if (prop=="beauty")
        ids = filter_array(ids, (: (CHAR_D->get_char($1,"gender")==2) :));
     if (prop=="handsome")
        ids = filter_array(ids, (: (CHAR_D->get_char($1,"gender")==1) :));
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,"gift")["rongmao"] >
                      CHAR_D->get_char($2,"gift")["rongmao"] ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "男性" :"女性" ),
             c["gift"]["rongmao"]);
        }
      return msg;      
     }
       
   case "sk_wuli"  :
   case "sk_meili" :
   case "sk_zhimou":
   {
       
     ids= sort_array(ids, (: (( CHAR_D->get_char($1,"skills")[$(prop)] >
                      CHAR_D->get_char($2,"skills")[$(prop)] ) ? -1 : 1):));
     msg+=title[prop];
     
     for(int i=0;i<MAX;i++)
       { c = CHAR_D->get_char(ids[i],"");
         msg+=sprintf("%-6d%-12s%-12s%-10s%-6d%-6s%-8d\n",
             i+1,ids[i],c["name"],
             COUNTRY_D->get_country(c["nation"],"name"),
             c["age"],
             (c["gender"]==1? "男性" :"女性" ),
             c["skills"][prop]);
        }
      return msg;      
     }       
   default :
      return "该类型的排行榜尚未开放\n";
 }
}
  
string log_news(string type)
{
 mixed * p_date;
 int MAX=50;
 mapping rank=([
 "reputation" : "名人",
 "literate"   : "才子",
 "sgrate"     : "栋梁",
 "beauty"     : "靓女",
 "handsome"   : "帅哥",
 "sk_wuli"    : "勇者",
 "sk_meili"   : "魅力",
 "sk_zhimou"  : "谋士",
 "age"        : "元老",
"newbie"     : "新人",
 "nationcontribution" : "功臣"
 ]);
 if (member_array(type,keys(rank))==-1)
      return "该类型的排行榜尚未开放\n";
 p_date = DAY_D->query_date();
NEWS_D->system_post("ranks",
            "三国志"+chinese_number(p_date[3])+"年"
            +chinese_number(MAX)+"大"+rank[type], 
get_top(type),"三国排名");
 tell(users(),"%^YELLOW%^【三国排行榜】"+rank[type]+
 "排行榜更新了，大家有空到洛阳城中心看看自己是否榜上有名哦!\n%^RESET%^");
 return  rank[type]+"排行榜创建成功!\n";
}
void log_all(int i)
{
mixed * type= ({"reputation",
            "literate",
            "beauty",
            "handsome",
            "age",
            "nationcontribution",
            "sk_wuli",
            "sk_meili",
            "sk_zhimou",
            "newbie",
            "sgrate"
           });
 log_news(type[i]);
 i++;
if (i<sizeof(type)) 
 call_out((:log_all:),10,i);
else
     SGSYS("所有排行榜创建成功!\n");
}
void start()
{log_all(0);}
