//filename /sgdoamin/tianzai/ev_tianzai.c
//Created by Suicide in 02/20/2000
#include <mudlib.h>
#include <security.h>
#include <daemons.h>
#define SAVE_FILE "/data/daemons/fate_d"
#define LOG       "/data/log/fates.log"
inherit M_ACCESS;
static string array sym_tien = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
static string array sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
static string array season = ({"spring","summer","autumn","winter"});
static array omen=({
({"good","east","north"}),
({"bad","east","center"}),
({"good","east","south"}), 
({"good","east","south"}),
({}),
({"good","center","south"}),
({"bad","west","south"}),
({"good","center","west"}),
({"good","west","north"}),
({"good","west","north"}),
({"bad","east","center"}),
({"good","east","north"}),
({"bad","south","north"}),
({"good","center","south"}),
({"bad","center","east"}),
({"bad","center","east"}),
({"good","center","west"}),
({"bad","west","south"}),
({"bad","south","north"}),
({"bad","center","north"}),
({"bad","east","west"}),
({"bad","east","west"}),
({"good","center","south"}),
({"bad","south","north"}),
({"bad","center","north"}),
({}),
({"bad","east","west"}),
({"bad","east","west"}),
({"bad","center","north"}),
({"bad","south","north"}),
({"good","east","south"}),
({"bad","center","east"}),
({"bad","west","south"}),
({"bad","west","south"}),
({}),
({"bad","center","north"}),
({"good","west","north"}),
({"good","center","west"}),
({"good","east","north"}),
({"good","east","north"}),
({"bad","center","north"}),
({"good","east","south"}),
({}),
({"good","center","south"}),
({"good","center","west"}),
({"good","center","west"}),
({"good","center","west"}),
({"good","west","north"}),
({}),
({"bad","center","north"}),
({}),
({}),
({"good","center","south"}),
({}),
({"good","center","south"}),
({}),
({}),
({}),
({"bad","center","north"}),
({})
                     });
                     
static mapping geo = ([
"east":({"兖州","青州","徐州"}),            //5+3+5=13 cities
"south":({"扬州","郢州","交州","南荆州"}),  //7+6+3+8=24 cities
"center":({"司隶","豫州","北荆州"}),          //7+4+7=18 cities
"west":({"益州","梁州","凉州","雍州"}),    //4+8+8+8=28 cities
"north":({"并州","冀州","幽州"})           //4+4+6=14 cities
      ]);
private int adjust_level;  
private int create_year;  
private mapping tz_type;                  
private mapping fate_table;
void log(string msg)
{
 unguarded(1, (: write_file, LOG,msg:));
}
void save_data()
{
    unguarded(1, (: save_object, SAVE_FILE, 1 :));
    return;
}
mixed add_fate_type(string what,string type,array seasons)
{
if ((type!="good")&&(type!="bad")) return "天道时间类型只有good和bad两种.\n";
foreach(string ss in seasons)
{int index = member_array(ss,season);
 if (index!=-1)
tz_type[type][index] -= ({what});
tz_type[type][index] += ({what});
}
save_data();
return 1;
}
mixed del_fate_type(string what,string type,array seasons)
{
if ((type!="good")&&(type!="bad")) return "天道时间类型只有good和bad两种.\n";
foreach(string ss in seasons)
{int index = member_array(ss,season);
 if (index!=-1)
tz_type[type][index] -= ({what});
}
save_data();
return 1;
}
int get_adjust_level()
{  
  return adjust_level;
}
int set_adjust_level(int lvl)
{ 
  adjust_level = lvl;
  save_data();
  return adjust_level;
       
}
int get_create_year()
{
  return create_year;
}
void area_effect(string p_area,mapping effect,int damage_level) 
{ 
 mixed val;      
 foreach(string st in keys(effect))
 {
  val=AREA_D->get_area(p_area,st);
  if (mapp(val))
     {foreach(string ss in keys(val))
      if (val[ss]>0)
          val[ss] += val[ss]*damage_level*adjust_level*effect[st]/5000;
     }
  else
     val += val*damage_level*adjust_level*effect[st]/5000;
  AREA_D->set_area(p_area,st,val);
 }
}
int get_damage_level(string p_area,mapping condition,int type)
{
 int i=0;int j=0;  
 foreach(string ss in keys(condition))
   { 
     if ((j=AREA_D->get_area(p_area,ss))<condition[ss])
        i +=  (condition[ss]-j)*10/condition[ss]+1;
   }
 if (i==0) 
    if (type==0) return 0;   //type =0 灾祸 type = 1 降幅
    else      return 6+random(5);
 if (type==1) i= 10*sizeof(condition)-i;
 if (random(10)<=(i/sizeof(condition))) 
    if (type==0) return random(10)+1;
    else return 1+random(5);
 else return 0;   
}            
 
                     
string get_tgdz(int year)  //得到对应年份的天干地支
{year -= 184;        //三国的启动起始年为184年,为甲子年
 return sym_tien[year%10]+sym_dee[year%12];
}
mapping create_tz_table(int year)  //得到每年的天灾表
{
 array data=({});
 array zhou=({});
 array type=({});
 array areas=({});
 mapping table=([
 "spring":({}),
 "summer":({}),
 "autumn":({}),
 "winter":({})
               ]);
 int datalen,i,rad,tgdz;
 array seek;
 create_year= year;
 tgdz = (year-184)%60;
 data = omen[tgdz];
if (!(datalen=sizeof(data))) {
fate_table = ([]);
save_data();
return ([]);}
 //if (data[0]=="good") type =1;
   // else type = 0;
 for (i=1;i<datalen;i++)
 {
   zhou+=geo[data[i]];
 }
 //SGSYS(sprintf("list is %O\n",zhou ));
 areas = filter_array(AREA_D->list_areas(),(: (member_array(AREA_D->get_area($1,"zhou"),$(zhou))!=-1) :));
 datalen = sizeof(areas);
 i=0;
 seek=({});
 while (i<=datalen/3)
 { rad= random(datalen);
   if (member_array(rad,seek)==-1)
      { 
      	i++;
seek += ({rad});
        type = tz_type[data[0]][i%4]; //由i决定四季
      	table[season[i%4]] += ({({areas[rad],type[random(sizeof(type))]})});
      }
 }
  fate_table = table;
  save_data();
  return fate_table;
}
array query_tz_info(string season)
{if (!fate_table[season]) return ({});
 return fate_table[season];}  
     
void create()
{   array p_date;   
    p_date = DAY_D->query_date(); 
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    if (!adjust_level) adjust_level=5;
    if (!sizeof(tz_type)||!mapp(tz_type))
        tz_type =([
        "bad" : ({
         ({"earthquake","flood","fire","murrain"}),     //spring
         ({"earthquake","flood","drought","locust","fire","cyclone","murrain"}), //summer
         ({"earthquake","drought","locust","fire","murrain"}), //autumn
         ({"earthquake","fire","murrain"})  //winter
        }),
        "good" : ({
         ({"goodsign"}),        
         ({"goodsign"}),
         ({"goodsign","foison"}),
         ({"goodsign","snow"})
        })
                   ]);
        	
    if ( !sizeof(fate_table)||!mapp(fate_table)||(create_year!=p_date[3]) )
        {
         fate_table = create_tz_table(p_date[3]);	
         create_year = p_date[3];
         save_data();
         }
   
}
