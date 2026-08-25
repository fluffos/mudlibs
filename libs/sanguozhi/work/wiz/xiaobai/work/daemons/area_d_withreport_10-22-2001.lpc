/* area_d.c by fire on 15/06/98
this is used to handle the common control of areas
area includes cities towns and obstalce
*/
#include <mudlib.h>
#include <security.h>
#include <area.h>

#define _DEBUG_ID   "xiaobai"

inherit M_ACCESS;
inherit __DIR__+"area_d/distance";
inherit __DIR__+"area_d/string";
inherit __DIR__+"area_d/level";
inherit __DIR__+"area_d/salary";
inherit __DIR__+"area_d/head";
inherit __DIR__+"area_d/stat_me";
inherit __DIR__+"area_d/soldiernumber";
private mapping areas;
nosave private string *stlist;
nosave private mapping a_ld=([]);
nosave private string *a_list=({});
nosave private mapping zhou_head=([
"幽州":"beiping"
,"冀州":"nanpi"
,"青州":"beihai"
,"兖州":"ye"
,"豫州":"xuchang"
,"徐州":"xuzhou"
,"并州":"taiyuan"
,"司隶":"luoyang"
,"雍州":"changan"
,"凉州":"xiliang"
,"梁州":"hanzhong"
,"益州":"chengdu"
,"北荆州":"xiangyang"
,"南荆州":"jiangling"
,"郢州":"lujiang"
,"扬州":"jianye"
,"交州":"nanhai"
]);

#define SAVE_FILE "/data/daemons/areas"
nosave private int m_modified;

string get_zhou_head(string zhou) {
	return zhou_head[zhou];
}
void save_data()
{  if(m_modified)
   {  unguarded(1, (: save_object, SAVE_FILE :));
      m_modified=0;
   }
}

void add_st() {
        string *ks,*ls;
        ks=keys(areas);
        foreach(string a in ks) {
                areas[a]["st"]=([]);
                ls=keys(areas[a]);
                if(sizeof(ls)) {
                        foreach(string st in ls) {
                                if(member_array(st,stlist)!=-1) {
                                        areas[a]["st"][st]=areas[a][st];
                                }
                        }
                }
        }
        m_modified=1;
        save_data();
}

void remove_st() {
        string *ks,*ls;
        ks=keys(areas);
        foreach(string a in ks) {
                ls=keys(areas[a]);
                if(sizeof(ls)) {
                        foreach(string st in ls) {
                                if(member_array(st,stlist)!=-1) {
                                        map_delete(areas[a],st);
                                }
                        }
                }
        }
        m_modified=1;
        save_data();
}

void create()
{  unguarded(1, (: restore_object, SAVE_FILE, 1 :));
   stlist=(EV_MERCHANT)->query_goods("list");
//   call_out("add_st",1);
//   add_st();
   return;
}
string add_area(string p_id)
{   if(!areas)
    areas=([]);
    if(!areas[p_id])
    {   areas[p_id]=([]);
        m_modified=1;
        return "新地区增加成功．\n";
    }
    else
    {   return "该地区已经存在．\n";
    }
}
// this function should be just used in the early develop 
// time. later to use it may cause other conflict
string remove_area(string p_id) 
{  if (!areas[p_id]) 
      return "该地区不存在．\n";
   map_delete(areas, p_id);
   m_modified=1;
   return "地区删除成功．\n";
}
int add_neighbor(string p_id1,string p_id2)
{   if((!areas[p_id1])||(!areas[p_id2]))
    {    return 0;
    }
    if(!areas[p_id1]["neighbor"])
        areas[p_id1]["neighbor"]=({});
    if(!areas[p_id2]["neighbor"])
        areas[p_id2]["neighbor"]=({});
    areas[p_id1]["neighbor"]-=({p_id2});
    areas[p_id2]["neighbor"]-=({p_id1});
    areas[p_id1]["neighbor"]+=({p_id2});
    areas[p_id2]["neighbor"]+=({p_id1});
        return 1;
}
int rm_neighbor(string p_id1,string p_id2)
{   if((areas[p_id1])&&(areas[p_id1]["neighbor"]))
        areas[p_id1]["neighbor"]-=({p_id2});
    if((areas[p_id2])&&(areas[p_id2]["neighbor"]))
        areas[p_id2]["neighbor"]-=({p_id1});
    if((!areas[p_id1])&&(!areas[p_id2]))
    {    return 0;
    }
    return 1;
}
//modified by suicide in 2000.02.20
//更改了st物资的数据格式.
//old:(["food":11200,
//      "wine":1000,
//      "cotten":100,
//    ])   物资名:数量
//new:(["food":(["num":11200,"price":100,"maxstock":100]),
//      "wine":(["num":12200,"price":200,"maxstock":150]),
//      "cotten":(["num":2200,"price":400,"maxstock":200]),
//num==数量 price==成本价 maxstock==地区最大保留值
void set_area_st(string p_id,string st_name,mixed para_name,mixed para_value)
{
    string name;
    mixed value;
    
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "原始参数值为：%d", para_value) );
#endif  // _DEBUG_ID

    if(!sizeof(areas[p_id]["st"])) 
      areas[p_id]["st"]=([]);

    if(!sizeof(areas[p_id]["st"][st_name])) 
      areas[p_id]["st"][st_name]=([]);

    if(intp(para_name))
    //为了保持对以前code的兼容
    // xiaobai: 22-10-2001, 如果第三个参数是数字，那么
    //   这个数字就是 "num"，这里先转换一下
    {
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, "参数转换。" );
#endif  // _DEBUG_ID

        value = para_name;
        name = "num";
    }
   
    if(stringp(para_name)) 
    {
        name = para_name;
        value = para_value;
    }

#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "准备设置 “%s”", name ) );
#endif  // _DEBUG_ID

    if ( name )
    {    
        if ( name == "num" )
        {
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, sprintf( "参数值为：%d", value) );
#endif  // _DEBUG_ID

            // 记录旧的数字
            SGREPORT_D->add_city_log(p_id,file_name(previous_object()),
                  ({p_id,st_name,para_value-areas[p_id]["st"][st_name]["num"]}));
    
            if ( value <= 0 )
            {
                // 数目为 0 就直接删除了，删除完之后可直接结束
#ifdef _DEBUG_ID
    TELL_BUG( _DEBUG_ID, "删除一种物资。" );
#endif  // _DEBUG_ID

                 map_delete( areas[p_id]["st"], st_name );
                 return;
            }           
    
        }

        areas[p_id]["st"][st_name][name] = value;
        
    }

}

//added by suicide in 2000.02.20
void add_area_st(string p_id,string para_name,int num,int price) {
   if(!sizeof(areas[p_id]["st"])) 
      areas[p_id]["st"]=([]);
   if(!sizeof(areas[p_id]["st"][para_name])) 
      areas[p_id]["st"][para_name]=([]);
   if((areas[p_id]["st"][para_name]["num"]+num)<=0) {
     map_delete(areas[p_id]["st"],para_name);
     return;
   }
   if (num<0)
       areas[p_id]["st"][para_name]["num"]+=num;
   else {
       int total = areas[p_id]["st"][para_name]["num"]*areas[p_id]["st"][para_name]["price"]+
                   num*price+areas[p_id]["st"][para_name]["left"];
       areas[p_id]["st"][para_name]["price"] = total/(areas[p_id]["st"][para_name]["num"]+num);
       areas[p_id]["st"][para_name]["left"]  = total%(areas[p_id]["st"][para_name]["num"]+num);
       areas[p_id]["st"][para_name]["num"]+=num;
   } 
   if (member_array("maxstock",keys(areas[p_id]["st"][para_name]))!=-1)//如果有maxstock的设定
      {
      if (areas[p_id]["st"][para_name]["num"]>areas[p_id]["st"][para_name]["maxstock"])
         COUNTRY_D->add_country_st(areas[p_id]["nation"],para_name,
                    areas[p_id]["st"][para_name]["num"]-areas[p_id]["st"][para_name]["maxstock"],
                    areas[p_id]["st"][para_name]["price"]);
      areas[p_id]["st"][para_name]["num"]=areas[p_id]["st"][para_name]["maxstock"];

      }
   save_data();   
       
   return;
     
}



varargs string set_area(string p_id,string para_name,mixed para_value,mixed *wparm)
{   string p_ret;
    if(!areas[p_id]) return "该地区不存在．\n";
    
    if( !para_value || ( intp(para_value)&&(para_value<0) ) )
    // xiaobai: Oct. 22, 2001 如果没有给 para_value 的值，其值为 0
        para_value=0;
    
    if (!wparm) wparm=({});
    switch (para_name)
    {
        case "train":
        case "morale":
        case "safe":
            if(para_value>200)
            {
                    SGSYS(sprintf("%s的%s超高，值为:%d，现强制为200",p_id,para_name,
                    para_value));
                    para_value=200;
            }
            areas[p_id][para_name]=para_value;
           
            p_ret="地区参数设置成功．\n";
    
            break;
        case "addneighbor": // neighbor
            if (add_neighbor(p_id,para_value))
               p_ret = "相邻区域设置成功．\n";
            else
               p_ret= "相邻区域设置失败．\n";
            break;
        case "rmneighbor": // neighbor
           if (rm_neighbor(p_id,para_value))
                p_ret = "相邻区域设置成功．\n";
           else
                p_ret= "相邻区域设置失败．\n";
           break;
        default:
            if(member_array(para_name,stlist)!=-1)
               set_area_st(p_id,para_name,para_value,0);//suicide 2000.02.26
            else
            {
               if (
                  (para_name=="population")||
                  (para_name=="gold")
                  )
               {
                   SGREPORT_D->add_city_log(p_id,file_name(previous_object()),
                                          ({p_id,para_name})+wparm+({para_value-areas[p_id][para_name]}));
               }  // end if
               
               areas[p_id][para_name]=para_value;
            }
            p_ret="地区参数设置成功．\n";

            break;
    }
        m_modified=1;
        return p_ret;
}
mixed get_area_leadera(string p_id)
{   string* char_list;
    int* p_title_list;
    p_title_list=OFFICER_D->query_area_officer_title
        (areas[p_id]["level"],0,0);
    char_list=CHAR_D->check_char_area("ranklocal",p_title_list[0],p_id);
    a_ld[p_id]=0;
    if(sizeof(char_list)) 
	a_ld[p_id]=char_list[0];
    return a_ld[p_id];
}

mixed get_area_real_leader(string p_id)  //2001.4.13
{  string leader;
   if (a_ld[p_id]) leader = a_ld[p_id];
   else leader = get_area_leadera(p_id);
   if (!leader) return 0;
   if (CHAR_D->get_char(leader,"grant"))
      leader = CHAR_D->get_char(leader,"grant")["leader"]; 
   return leader;
}

mixed get_area_leader(string p_id) {
	string p_ld;
	int *p_title_list;
	if(!a_ld[p_id]) return get_area_leadera(p_id);
	p_ld=a_ld[p_id];

        p_title_list=OFFICER_D->query_area_officer_title(areas[p_id]["level"],0,0);
	if(CHAR_D->get_char(p_ld,"ranklocal")!=p_title_list[0])
		return get_area_leadera(p_id);

	if(CHAR_D->get_char(p_ld,"area")!=p_id)
		return get_area_leadera(p_id);
	return p_ld;	
}
int get_area_soldier(string a_id,string type) {
   mixed troop;
   string *k;
   int n;
   troop=areas[a_id]["troop"];
   if(!troop) troop=([]);
   switch(type) {
      case "sum":
        if(!sizeof(troop)) return 0;
        k=keys(troop);
        n=0;
        foreach(string kk in k) {
          n+=troop[kk];
        }
        return n;
      default : return troop[type];
   }
}

//Add By Listen
//will reduce footman first
int reduce_soldier(string a_id, string type, int number) 
{
	mixed troop;
	string *k;
	int n=get_area_soldier(a_id, type);
	if (n < number) return 0;
	troop=areas[a_id]["troop"];
	if(!troop) troop=([]);
	if (type=="sum") 
	{
	   if(!sizeof(troop)) return 0;
	   k=keys(troop);
	   if (troop["footman"]>number) //reduce footman first
	   {
	   	troop["footman"]-=number;
	   	return 1;
	   }
	   else
	   	number-=troop["footman"]; //if footman not enough
	   k-=({"footman"}); //reduce other troops
	   foreach(string kk in k)
	   {
		if (troop[kk]>= number)
		{
	   	   troop[kk]-=number;
		   number=0;
		}
		else 
		{
		   number-=troop[kk];
		   troop[kk]=0;
		}
	   }
	   if (number > 0) return 0; //not enough troop to reduce
	}
	else //only reduce one fixed troop
	{
	   if(troop[type]<number)
	      return 0;
	   troop[type]-=number;
	}
	return 1;
}



//modified by suicide in 2000.02.26
int get_area_st(string p_id,string st_name,mixed para_name) {
   if(!sizeof(areas[p_id]["st"])) areas[p_id]["st"]=([]);
   if(!sizeof(areas[p_id]["st"][st_name]))  areas[p_id]["st"][st_name]=([]);
   if (!para_name) return areas[p_id]["st"][st_name]["num"];
   return areas[p_id]["st"][st_name][para_name];
}

//added by suicide in 2000.2.20
int get_area_st_price(string p_id,string stuff) {
   if(!sizeof(areas[p_id]["st"])) return 0;
   if (!areas[p_id]["st"][stuff]) return 0;
   return areas[p_id]["st"][stuff]["price"];
}

mixed get_area(string p_id,string para_name)
{  if (!areas[p_id]) 
       return 0;
   switch(para_name)
   {
     case "status" :
        if((!areas[p_id]["status"])||(areas[p_id]["status"]==ST_NOOFFICER))
           return areas[p_id]["status"];
        return TASK_D->get_area_task(p_id);
     case "salary":
        return AREA_D->get_areasalary(p_id);
     case "goldin":
        return AREA_D->get_income(p_id,"gold");
     case "foodin":
        return AREA_D->get_income(p_id,"food");
     case "stuffin":
        return AREA_D->get_income(p_id,"stuff");
     case "goldout":
        return AREA_D->get_output(p_id,"gold");
     case "foodout":
        return AREA_D->get_output(p_id,"food");
     case "stuffout":
        return AREA_D->get_output(p_id,"stuff");
     case "statusstr":
        return get_area_statusstr(p_id);
     case "militarylevel":
        return get_area_military_level(p_id);
     case "safelevel":
        return get_area_safe_level( p_id);
     case "productlevel":
        return get_area_product_level( p_id);
     case "importancestr":
        return get_area_importancestr(p_id);
     case "leader": // query 太守
        return get_area_leader(p_id);
     case "soldier":
        return get_area_soldier(p_id,"sum");
     case "area":
     case "map": 
        return p_id;
   case "": return areas[p_id];
     default:
        if(member_array(para_name,stlist)!=-1)
           return get_area_st(p_id,para_name,0);//suicide 2000.02.26
        else
           return areas[p_id][para_name];
    }
}
string* check_area(string para_name,mixed para_value)
{  string *ret, *list;
   if(para_name=="area") {
       if(areas[para_value]) return ({para_value});
       return 0;
   }
   list=keys(areas);
   ret=filter_array(list, (:areas[$1][$(para_name)]==$(para_value):));
   return ret;
}
int get_income(string p_id,string p_item)
{   int p_population,p_safe,p_industry;
    int p_agriculture,p_business;
    int p_localtax;
    float p_tmp;
    p_population=areas[p_id]["population"];
    p_safe=areas[p_id]["safe"];
    p_industry=areas[p_id]["industry"];
    p_agriculture=areas[p_id]["agriculture"];
    p_business=areas[p_id]["business"];
    p_localtax=areas[p_id]["taxlocal"];
    switch(p_item)
    {  case "gold":
         p_tmp=p_population/25.*p_business/100.* 
           (p_safe+20)/100. * p_localtax/100.;
         p_tmp=p_tmp/2.;    //suicide in 2001.8.21 for 减少月金收入为原来的50%
                            //这样人口和可供养兵力的比例基本是20:1
                            //算上农场,10k兵需要2.5k gold维持
         break;
       case "food":
         p_tmp=p_population*10.*p_agriculture/100.*
           (p_safe+20)/100.*p_localtax/100.;
         break;
       case "stuff":
         p_tmp=p_population/100. * p_industry/100. *
           (p_safe+20)/100.;
         break;
       default:
         p_tmp=0;
    }
    return to_int(p_tmp+0.5);
}
/*int get_output(string p_id, string p_item)
{   int p_bing;
    float ret;
    p_bing=get_area(p_id, "soldier");
    
    switch(p_item)
    {
      case "gold":
         ret=p_bing/10.;
         break;
      case "food":
         ret=p_bing;
         break;
      case "stuff":
         ret=p_bing/100.;
         break;
      default:
         ret=0.;
    }
    return to_int(ret+0.5);
}*/
//modified by suicide in 2001.08.09 for multitroop cost per month
//footman: gold 0.1 food 1  bowman and cavalry gold 0.4 food 2
int get_output(string p_id, string p_item)
{   mapping p_bing;
    float ret;
    p_bing=get_area(p_id, "troop");
    switch(p_item)
     {
      case "gold":
         ret=p_bing["footman"]/10.+p_bing["bowman"]*4/10.+p_bing["cavalry"]*4/10.;
         break;
      case "food":
         ret=p_bing["footman"]+p_bing["bowman"]*2+p_bing["cavalry"]*2;
         break;
      case "stuff":
         ret=(p_bing["footman"]+p_bing["bowman"]+p_bing["cavalry"])/100.;
         break;
      default:
         ret=0.;
     }
    return to_int(ret+0.5);
}

void nation_income()
{   string* list;
    list=keys( areas );
    foreach(string p_id in list)
    {   int p_population,p_safe,p_industry,p_agriculture,p_business;
        int p_nationtax,p_ran,p_goldin, p_foodin, p_stuffin;
        int p_gold,p_food,p_stuff, p_month;
        float p_tmp;
        mixed * p_date;
        string p_nation;
        p_nation=AREA_D->get_area(p_id,"nation");
        p_date=DAY_D->query_date();
        p_month=p_date[2];
        p_population=areas[p_id]["population"];
        p_safe=areas[p_id]["safe"];
        p_industry=areas[p_id]["industry"];
        p_agriculture=areas[p_id]["agriculture"];
        p_business=areas[p_id]["business"];
        p_nationtax=areas[p_id]["taxnation"];
        p_food=COUNTRY_D->get_country(p_nation,"food");
        p_tmp=0;
        if(p_month==9) // harvest
        {   p_ran=random(30);
            p_tmp=p_population*10.*p_agriculture/100.*(p_safe+20)/100.*
               p_nationtax/100.*(p_ran+70)/100.+0.5;
        }
        p_foodin=to_int(p_tmp);
        p_food=p_food+p_foodin;
        p_ran=random(30);
        p_gold=COUNTRY_D->get_country(p_nation,"gold");
        p_tmp=p_population/25.*p_business/100.* (p_safe+20)/100. *
           p_nationtax/100. * (p_ran+70)/100.+0.5;
        p_goldin=to_int(p_tmp);
        p_gold=p_gold+p_goldin;
        p_stuff=COUNTRY_D->get_country(p_nation,"stuff");
        p_ran=random(30);
        p_tmp=p_population/100. * p_industry/100. * (p_safe+20)/100.*
            p_nationtax/100. *(p_ran+ 70)/100.+0.5;
        p_stuffin=to_int(p_tmp);
        p_stuff=p_stuff+p_stuffin;
        COUNTRY_D->set_country(p_nation,"gold",p_gold);
        COUNTRY_D->set_country(p_nation,"food",p_food);
        COUNTRY_D->set_country(p_nation,"stuff",p_stuff);
   }
}
// this function will be call manually ?
void area_init()
{
    string* list;
    list=keys(areas);
    foreach(string p_id in list)
    {  if((areas[p_id]["level"])&&(!areas[p_id]["population"]))
       {   switch(areas[p_id]["level"])
           {
              case 5:  areas[p_id]["population"]=random(MAX_POPULATION5/3)
+MAX_POPULATION5/10; break;
              case 4:  areas[p_id]["population"]=random(MAX_POPULATION4/3)
+MAX_POPULATION4/10; break;
              case 3: areas[p_id]["population"]=random(MAX_POPULATION3/3)+
                MAX_POPULATION3/10; break;
              case 2:  areas[p_id]["population"]=random(MAX_POPULATION2/3)
+MAX_POPULATION2/10; break;
              case 1: areas[p_id]["population"]=random(MAX_POPULATION1/3)+
                MAX_POPULATION1/10; break;
            }
            areas[p_id]["taxnation"]=10;
            areas[p_id]["taxlocal"]=40;
            areas[p_id]["safe"]=30+random(30);
            areas[p_id]["business"]=30+random(30);
            areas[p_id]["industry"]=30+random(30);
            areas[p_id]["agriculture"]=30+random(30);
        }
     }
     m_modified=1;
}
int area_exist(string p_id)
{
        if(areas[p_id])
                return 1;
        return 0;
}
mixed list_areas()
{
  	if(!sizeof(a_list))
		a_list=keys(areas);
	return a_list;
}
mixed list_areas_id(int i) {
  	if(!sizeof(a_list))
		a_list=keys(areas);
	if((i<0)||(i>=sizeof(a_list))) return 0;
	return a_list[i];
}
string pick_area(){
  	if(!sizeof(a_list))
		a_list=keys(areas);
	return a_list[random(sizeof(a_list))];
}
// this is used to check if an area is
// 完整，一致
void area_check()
{  string* list;
   int i, *head_title;
   mixed m_tmp;
   list=keys(areas);
   for(i=0;i<sizeof(list);++i)
   {   string p_id;
       p_id=list[i];
       if (!areas[list[i]]["level"])
       {  CHANNEL_D->deliver_emote("announce","notice"
            ,sprintf("地区 %s 没有设定等级\n",list[i]));
            break;
       }
       if((areas[p_id]["level"])&&(!areas[p_id]["population"]))
            area_init();
       if(!areas[p_id]["nation"])
       {   CHANNEL_D->deliver_emote("announce","notice"
            ,sprintf("地区 %s 没有设定所属国\n",list[i]));
           break;
       }
       head_title=OFFICER_D->query_area_officer_title(areas[p_id]["level"]
,0,0);
       m_tmp=CHAR_D->check_char_area("ranklocal",head_title[0],p_id);
       if(sizeof(m_tmp)&&(!areas[list[i]]["status"]))
       {    areas[list[i]]["status"]=ST_NORMAL;
            m_modified=1;
       }
       if(!sizeof(m_tmp))
       {   AREA_D->auto_head(p_id);
           m_modified=1;
       }
   }
}
void remove() {
  save_data();
}
void clear_bn(string a_id) {
   mixed bn;
   string *ks;
   int p_t=time();
   bn=get_area(a_id,"bn");
   if(!sizeof(bn)) return;
   ks=keys(bn);
   foreach(string k in ks) {
      if(bn[k]<p_t) 
        map_delete(bn,k);
   }
   set_area(a_id,"bn",bn);
}
int set_area_soldier(string a_id,string type,int num) {
   mixed troop;
   troop=areas[a_id]["troop"];
   if(!mapp(troop)) troop=([]);
   if(num<=0)
      map_delete(troop,type);
   troop[type]=num;
   areas[a_id]["troop"]=troop;
   m_modified=1;
}
int clean_up() {
   return 0; // means never_again
}

int add_soldier(string p_id,string typ,int num,int morale,int train) {
   int t_num;
   int n_morale,n_train;
   t_num=get_area_soldier(p_id,"sum"); 
   n_morale=(areas[p_id]["morale"]*t_num)+num*morale;
   n_train=(areas[p_id]["train"]*t_num)+num*train;
   t_num+=num; if(!t_num)t_num=1;
   n_morale/=t_num;n_train/=t_num;
   t_num=get_area_soldier(p_id,typ);
   set_area_soldier(p_id,typ,t_num+num);
   set_area(p_id,"morale",n_morale);
   set_area(p_id,"train",n_train);
   return 1;
}