#include <ansi.h>
#pragma save_binary
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)
inherit F_DBASE;

static int current_day_phase, current_month;

mapping *day_phase;

static string ppl;

string *month_desc = ({
        HIW"隆冬的"NOR,
        HIW"寒冬的"NOR,
        HIG"初春的"NOR,
        HIG"早春二月的"NOR,
        HIG"阳春三月的"NOR,
        HIC"初夏的"NOR,
        HIC"盛夏的"NOR,
        HIR"仲夏的"NOR,
        HIY"初秋的"NOR,
        HIY"秋高气爽的"NOR,

        YEL"深秋的"NOR,
        WHT"初冬的"NOR,
});
string *bad_weather=({
        "受干旱的影响，$N亏空",
        "由于暴雨袭击，$N收成跌了",
        "$N遭到了倭寇的袭击，被劫",
        "官府加重对$N的征税，$N亏空",
        "疾病在$N肆虐，损失惨重",
        "龙卷风袭卷了$N，结果造成巨大损失",
        "$N突发地震，人员伤亡惨重，花费巨大",
});


int party_at,count=0;
object room_c;
string *party=({
        "神龙教",
        "灵鹫宫",
        "少林派",
        "华山派",
        "峨嵋派",
        "昆仑派",
        "全真教",
        "武当派",
});
string *party_a=({
        "/d/shenlong/haitan",
        "/d/lingjiu/damen",
         "/d/shaolin/guangchang1",
        "/d/huashan/zhenyue",
        "/d/emei/jinding",
        "/d/kunlun/klpsm",
        "/d/quanzhen/guangchang",
        "/d/wudang/zixiaogong",
});
string *party_add=({
        "神龙教海滩",
        "独尊厅大门", 
        "少林寺",
        "镇岳宫",
        "金顶",
        "昆仑派山门",
        "全真教广场",
        "紫霄宫",
});

mapping *read_table(string file);
void init_day_phase();

void haojie();
void create()
{
        string get_month, get_day;
        mixed *local;

        local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
        get_month = CHINESE_D->chinese_number(local[4]);
        switch(get_month)
        {
                //spring weather
                case "三":
                case "四":
                case "五":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/spring_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/spring_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/spring_wind");
                           break;
                     }
                     break;
                //summer weather

                case "六":
                case "七":
                case "八":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/summer_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/summer_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/summer_wind");
                           break;
                     }
                     break;
                //autumn weather
                case "九":
                case "十":
                case "十一":
                     switch(random(3))
                     {
                        case 0:

                           day_phase = read_table("/adm/etc/nature/autumn_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/autumn_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/autumn_wind");
                           break;
                     }
                     break;
                //winter weather
                case "零":
                case "二":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:         
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");

                     }
                case "一":
                        if(get_day=="一")
                      { day_phase = read_table("/adm/etc/nature/spring");break;}
                      else switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:         
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                        
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }

        init_day_phase();
}

void init_day_phase()
{
        mixed *local;
        int i, t;


        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];      


        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
        current_month = local[4];

        remove_call_out("init_day_phase");
        call_out("init_day_phase", 3600);


        remove_call_out("update_day_phase");    



        call_out("update_day_phase",
        (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        int i=0;
        remove_call_out("update_day_phase");
         if(current_day_phase==0) {
            init_day_phase();
            i=1;
        }

        current_day_phase = (++current_day_phase) % sizeof(day_phase);

        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
                call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
                  message("system", HIW"◇"HIC"苍茫大地      "HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
        if(i==0)
        call_out("update_day_phase", day_phase[current_day_phase]["length"]);

}
/* string room_event_fun()
{
    return day_phase[current_day_phase]["event_fun"];
}
*/
void event_morning()
{
        object badguy;
        object room;
        if (random(12) == 1)
        {
                 if(objectp(room=load_object("/d/changan/ca")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                        badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);

                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
     message("channel:chat", HIY"【天廷急报】"HIM + "在长安城中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 2)
        {
                  if(objectp(room=load_object("/d/city/dongdajie1")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                 badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
   message("channel:chat", HIY"【天廷急报】"HIM + "在扬州城中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 3)
        {
                 if(objectp(room=load_object("/d/city/ximen")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");

                badguy->move(room);
   message("channel:chat", HIY"【天廷急报】"HIM + "在扬州城中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 4)
        {
                  if(objectp(room=load_object("/d/xingxiu/xxh2")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
    message("channel:chat", HIB"【天廷急报】"GRN + "在星宿海中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 5)
        {
                  if(objectp(room=load_object("/d/kaifeng/chengmen")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);

message("channel:chat", HIB"【天廷急报】"GRN + "在开封城中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 6)
        {
                  if(objectp(room=load_object("/d/city2/tian_anm")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");

                badguy->move(room);
 message("channel:chat", HIB"【天廷急报】"GRN + "在天安门中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 7)
        {
                  if(objectp(room=load_object("/d/city2/road4")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);

 message("channel:chat", HIB"【天廷急报】"GRN + "在天安门中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 8)
        {
                  if(objectp(room=load_object("/d/city2/xidan")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("channel:chat", HIB"【天廷急报】"GRN + "在天安门中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 9)
        {
                 if(objectp(room=load_object("/d/nanyang/nanyang")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
    message("channel:chat", HIG"【天廷急报】"CYN + "在南阳城中发现妖怪！\n"NOR,users() );

        }
        if (random(12) == 10)
        {
                  if(objectp(room=load_object("/d/nanyang/xiaozheng")) && 
                objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
    message("channel:chat", HIG"【天廷急报】"CYN + "在南阳城中发现妖怪！\n"NOR,users() );
        }
        if (random(12) == 11)
        {
                  if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
    message("channel:chat", HIR"【天廷急报】"BLU + "在泉州中发现妖怪！\n"NOR,users() );
        }

        if (random(12) == 12)
        {
                  if(objectp(room=load_object("/d/quanzhou/jiaxing")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
    message("channel:chat", HIR"【天廷急报】"BLU + "在泉州中发现妖怪！\n"NOR,users() );
        }
        if (random(16) == 1)
        {
                  if(objectp(room=load_object("/d/wudang/sanqingdian")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");

                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                  message("channel:chat", HIR"【天庭告急】"HIW + "妖怪大军攻打三清殿！\n"NOR,users() );
        }
        if (random(16) == 2)
        {
                  if(objectp(room=load_object("/d/shaolin/guangchang1")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");

                badguy->move(room);
   message("channel:chat", HIR"【天庭告急】"HIW + "妖怪大军在少林！杀我百姓!!\n"NOR,users() );
        }
        if (random(16) == 4)

        {
                 if(objectp(room=load_object("/d/lingjiu/damen1")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                 message("channel:chat", HIR"【天庭告急】"HIW + "妖怪大军进军灵鹫宫！灵鹫宫告急!!\n"NOR,users() );
        }

        if (random(16) == 7)
        {
                  if(objectp(room=load_object("/d/city2/zhengmen")) && 
                objectp(badguy = new("/quest/weiguo/japan/japan4")))
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
    message("channel:chat", HIR"【天庭告急】"HIW + "妖怪的部队杀入了皇宫！皇宫告危!!\n"NOR,users() );
        }
}

void event_night()
{

        object badguy;
        object room;
 object area,who;
 mixed file,dir;
int bad_money;
int faith;
string bad_area,str;
 int amount,i,tax,people,trade,farm;
object *ob_list,*users;
dir=get_dir("/data/city/",0);
if(dir){      
message("channel:chat", HIY"【飞鸽传书】"HIR + "各地城市开始征税。\n"NOR,users() );
for(i=0;i<sizeof(dir);i++){
if( sscanf(dir[i], "%s.o", file)==1 ) {
if(!objectp(area=find_object("/p/residence/"+file)))

if(!objectp(area))continue;
if(area->query("owner"))  
{
tax=area->query("tax");if (!intp(tax))tax=0;
trade=area->query("trade");if (!intp(trade))trade=0;
farm=area->query("farm");if (!intp(farm))farm=0;
people=area->query("people");if(!intp(people))people=0;

amount=(people/2000)*((farm+trade)/5)*tax;
who=find_player(area->query("owner"));
    if(who) {
    if(random(10)>8)
             {
           bad_area=file;
           bad_money=(trade+1)*(farm+1)*(tax+1);
           str=bad_weather[random(sizeof(bad_weather))];
            str=replace_string(str,"$N",area->query("short"));
            message("channel:rumor",YEL"【谣言】某人："+
            str+"！\n"NOR,users());
trade=random(15);
farm=random(15);
faith=random(8);

people=random(8000);
area->add("trade",-trade);
area->add("farm",-farm);
area->add("faith",-faith);
 area->add("people",-people);
if (area->query("people")<1)
{
area->set("people",1);
people=1;
tell_object(who,HIR"你"+area->query("short")+"里的百姓都跑光了，就剩你一个了！\n"NOR);
}
tell_object(who,area->query("short")+"受损严重，\n
农业开发度下降了"+chinese_number(farm)+"点。\n
商业开发度下降了"+chinese_number(trade)+"点。\n
人口减少了"+chinese_number(people)+"，人民忠诚度下降了。\n");
continue;
}
   if(who->query("money",1)>100000000)   {
who->add("zjb_money",who->query("money",1)/100000000);
   who->set("money",who->query("money",1)-((who->query("money",1)/100000000)*100000000));
 tell_object(who,HIR"你在钱庄的钱已达到一万两黄金！\n"NOR);
tell_object(who,HIR"星空已经帮你把钱庄里的黄金转换成了"HIB"星空币"HIR"存在了钱庄!\n"NOR);
}

who->set("money",who->query("money",1)+amount);
       who->save();   
  log_file("city_log","pay "+amount+" to "+area->query("owner")+"\n");
 tell_object(who,area->query("short")+"税收"+MONEY_D->money_str(amount)+",已经存入你的户头。\n");
}
if((int)area->query("farm")<1)area->set("farm",0);
if((int)area->query("trade")<1)area->set("trade",0);
if((int)area->query("people")<1)area->set("trade",0);
if((int)area->query("faith")<1)area->set("faith",0);
area->save();
    }

}
if(bad_area=="")message("channel:rumor",YEL"【谣言】某人：各地盘收入良好。\n"NOR,users());
}
       users=users();
        for(i=0;i<sizeof(users);i++)    {
              if((int)users[i]->query("balance")<1)
                users[i]->set("balance",1);
    if((int)users[i]->query("balance",1)>2100000000)   {
                users[i]->set("balance",2100000000);
           tell_object(users[i],RED"你在钱庄的钱已达到二十一万两黄金，快点花吧！\n"NOR);
}}

        if (random(12) == 1)
        {
                  if(objectp(room=load_object("/d/changan/dongmen")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "长安城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 2)
        {
                  if(objectp(room=load_object("/d/kaifeng/chengmen")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "开封城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 3)
        {
                 if(objectp(room=load_object("/d/city/beimen")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
    message("channel:chat", HIW"【官府通告】"HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }

        if (random(12) == 4)
        {
                  if(objectp(room=load_object("/d/city/nanmen")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
    message("channel:chat", HIW"【官府通告】"HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 5)
        {
                 if(objectp(room=load_object("/d/shaolin/shijie9")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
    message("channel:chat", HIW"【官府通告】"HIR + "少寺山中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 6)
        {
                  if(objectp(room=load_object("/d/city2/wangfu3")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);

  message("channel:chat", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 7)

        {
                  if(objectp(room=load_object("/d/city2/di_an3")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 8)
        {
                  if(objectp(room=load_object("/d/city2/xichangdamen")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 9)
        {
                  if(objectp(room=load_object("/d/baituo/dating")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
    message("channel:chat", HIW"【官府通告】"HIR + "白驼山中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 10)
        {
                  if(objectp(room=load_object("/d/baituo/guangchang")) && 

                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
    message("channel:chat", HIW"【官府通告】"HIR + "白驼山中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
        if (random(12) == 11)
        {
                  if(objectp(room=load_object("/d/baituo/xijie")) && 
                objectp(badguy = new("/quest/feizei/feizei")))
                badguy->move(room);
    message("channel:chat", HIW"【官府通告】"HIR + "白驼山中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
        }
 }
 }

void event_afternoon()
{
        object area,lp;
        mixed *dir;
        int count,j;
        string *item,bad_area;
        int bad_money;
        int i=1,last; 
        int h;
      int bh_money;
        mapping data=([]);
        int kaifa,jizhi,area_money,npc_money;
        object *ob_list,*users;
        string file,str;

        int money;
        string *npc_banghui=({"明教","日月教","丐帮","天地会"});

        dir=get_dir("/data/area/",0);
        if(! dir)       dir=({});
// get the bad area
        if( sizeof(dir)>=30)    bad_area=dir[random(sizeof(dir))];
        else    bad_area="";
        if(sscanf(bad_area,"%s.o",bad_area)!=1) bad_area="";
// end

        area=new("/clone/misc/area");
        for(i=0;i<sizeof(dir);i++)      {
                if(sscanf(dir[i],"%s.o",file)==1)       {
                area->create(file);
                area_money=area->query("money");
                if(! intp(area_money))  area_money=0;
                kaifa=area->query("kaifa");
                if(! intp(kaifa))       kaifa=0;
                jizhi=area->query("jizhi");
                if(! intp(jizhi))       jizhi=0;
                if(file==bad_area)      {
                        if(jizhi&& kaifa<60)    {
                                bad_area=file;
                                bad_money=(kaifa+1)*jizhi*10000;
                                area_money-=bad_money;

                        }
                        else    {
                                bad_area="";
                                area_money+=(kaifa/2+random(kaifa/2)+1)*jizhi*10000;
                        }
                }
                else

                area_money+=(kaifa/2+random(kaifa/2)+1)*jizhi*10000;
                data[area->query("banghui")]+=area_money;
                area->set("money",0);
                area->set("last_money",area_money);
                area->save();
                }
        }

        destruct(area);

// set all banghui's money include npc_money & area_money
        dir=get_dir("/data/guild/",0);
        if(! dir)       dir=({});
        lp=new("/clone/misc/lingpai");
        for(i=0;i<sizeof(dir);i++)      {
                if(sscanf(dir[i],"%s.o",file)==1)       {
                lp->create(file);

                npc_money=lp->query("npc_money");
                lp->set("npc_money_last",npc_money);
                lp->set("area_money_last",data[file]);
                lp->set("npc_money",0);

                data[file]+=npc_money;
                if(data[file]<0)        data[file]=0;
                data[file]/=2;
                lp->set("money",data[file]);
                lp->set("bangzhu_money",data[file]);
                lp->save();
                }
        }
        destruct(lp);

// give all online player banghui's money
        users=users();
        if(arrayp(users))       {
        item=keys(data);
        for(i=0;i<sizeof(item);i++)     {
                count=0;
                for(j=0;j<sizeof(users);j++)    {
                        if(! users[j]->query("banghui") ||
                        users[j]->query("banghui")!=item[i])
                                continue;
                        count++;

                }

                if(count==0)    count=1;
                data[item[i]]/=count;
        }
if ((int)users[i]->query("more_money"))
{
users[i]->set("money",users[i]->query("money",1)+users[i]->query("more_money")*100000000);
users[i]->set("more_money",0);
}

if ((int)users[i]->query("money",1)>100000000)
{
users[i]->add("zjb_money",users[i]->query("money",1)/100000000);
users[i]->set("money",users[i]->query("money",1)-((users[i]->query("money",1)/100000000)*100000000));
tell_object(users[i],HIR"你在钱庄的钱已达到一万两黄金！\n"NOR);
tell_object(users[i],HIR"星空已经帮你把钱庄里的黄金转换成了"HIB"星空币"HIR"存在了钱庄!\n"NOR);
}

        for(i=0;i<sizeof(users);i++)    {
                if(! objectp(users[i])) continue;
                if(! users[i]->query("banghui"))        continue;
                if(member_array((string)users[i]->query("banghui"),npc_banghui)!=-1)    {
                money=(int)users[i]->query("score");
                if(money<5000)    money=5000;
                else if(money<20000)      money=20000;
                if(money>2000000) money=2000000;
                data[users[i]->query("banghui")]=money;
        }
bh_money=data[users[i]->query("banghui")];
                if(! data[users[i]->query("banghui")])  continue;
users[i]->set("money",users[i]->query("money",1)+bh_money);
                tell_object(users[i],"「"+users[i]->query("banghui")+"」"+
                "发饷，你的帐上增加了"+MONEY_D->money_str(data[users[i]->query("banghui")])+"！\n");
        }
        if(bad_area=="")        {
                message("channel:rumor",YEL"【谣言】某人：各地盘收入良好。\n"NOR,users());
        }
        else    {
                str=bad_weather[random(sizeof(bad_weather))];

                str=replace_string(str,"$N",bad_area);
                message("channel:rumor",YEL"【谣言】某人："+
                str+MONEY_D->money_str(bad_money)+"！\n"NOR,users());
        }
        for(i=0;i<sizeof(users);i++)    {
        if((int)users[i]->query("balance")>2100000000)  {
                users[i]->set("balance",2100000000);
                tell_object(users[i],RED"你在钱庄的钱已达到二一万两黄金，快点花吧！\n"NOR);
        }
        }
        }

        ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);

                }
        ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/jinbing/jin1");

                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))

                {
                message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);

                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }

        ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
        ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))
                {
                message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
}

void event_dawn()
{
        object *ob_list;
        int i;
        ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++) 
                if(environment(ob_list[i]))

                {
                        message_vision("$N笑道：天亮了，东西也到手了，我闪！\n",ob_list[i]);
                        destruct(ob_list[i]);
                }
}


void event_midnight()
{       
        
        string get_month, get_day;
        mixed *local;
        local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
        get_month = CHINESE_D->chinese_number(local[4]);
        switch(get_month)
        {
                //spring weather
                case "三":
                case "四":
                case "五":
                     switch(random(3))
                     {

                        case 0:
                           day_phase = read_table("/adm/etc/nature/spring_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/spring_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/spring_wind");
                           break;
                     }
                     break;
                //summer weather
                case "六":
                case "七":
                case "八":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/summer_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/summer_sun");
                           break;

                        case 2:
                           day_phase = read_table("/adm/etc/nature/summer_wind");
                           break;
                     }
                     break;
                //autumn weather
                case "九":
                case "十":
                case "十一":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/autumn_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/autumn_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/autumn_wind");
                           break;
                     }
                     break;
                //winter weather

                case "零":
                case "二":
                     switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;
                        case 1:
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                     
                     case "一":
                        if(get_day=="一")
                      { day_phase = read_table("/adm/etc/nature/spring");break;}
                      else switch(random(3))
                     {
                        case 0:
                           day_phase = read_table("/adm/etc/nature/winter_rain");
                           break;

                        case 1:         
                           day_phase = read_table("/adm/etc/nature/winter_sun");
                           break;
                        case 2:
                           day_phase = read_table("/adm/etc/nature/winter_wind");
                           break;
                     }
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }
          if(random(30) > 20)
        {
        message("chat", HIG"
〖"HIR"江湖"HIG"〗：黎明前的黑暗是最可怕的，江湖总是在一次一次的毁灭中获得重生，这
          样的江湖，才是每个侠客心中的梦想之地，能站到最后的人，才是真正
          的赢家。既入江湖，何患生死？只有失败才能体会成功的欢乐！只有哭
          过才知道眼泪的可贵！
                     
                             天下风云出我辈，
                             一入江湖岁月催。
                             皇图霸业谈笑中，
                             不胜人生一场醉！

        \n"NOR,users());
        remove_call_out("notice");
        call_out("notice",10);
        }



}
        

void event_noon()
{
        object *ob;
        int i, j,skill,con,con1,con2,con3;
        string get_month,ill,msg;
          object *mengzhu_list;

       mengzhu_list = children("/u/daniel/haojie/npc/mengzhu");
        for(i=0; i<sizeof(mengzhu_list); i++) 
        if(environment(mengzhu_list[i]))
        {
                message_vision("这次事件终于搞一段落，$N又隐迹山林了！\n",mengzhu_list[i]);
                destruct(mengzhu_list[i]);

        }
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                case "三":
                case "四":
                case "五":
                     ill = "ill_kesou";
                     msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
                     break;
                case "六":
                case "七":
                case "八":
                     ill = "ill_zhongshu";
                     msg = HIG+"突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
                     break;
                case "九":
                case "十":
                case "十一":
                     ill = "ill_shanghan";
                     msg = HIG+"陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n"+NOR;
                     break;

                case "十二":
                case "一":
                case "二":
                     ill = "ill_dongshang";
                     msg = HIG+"你肢体末端一阵僵直，看来你被冻伤了。\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"你偶感风寒，竟而发起烧来。\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//形成第一个生病判断条件
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
                  if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
        return "    " + sprintf(
                day_phase[current_day_phase]["desc_msg"],
                month_desc[current_month]) + "。\n";
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{

        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

      line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );

                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

int auto_shutdown(int flag)
{
    reclaim_objects();
    if (172800-uptime()<=0 || flag){
        message("vision", RED "要当机了！放心，您的档案已经自动存储了！\n" NOR, users());
        users()->disable_player("备份资料中......");
             call_out("backup",1);
    }
}


int backup()
{
    reset_eval_cost();
    foreach (object userob in children(USER_OB) ){
       if (!userob || !environment(userob)) continue;
           userob->save();

    }
        shutdown(0);
        return 1;

}

mapping *query_day_phase() { return day_phase; }
void notice()
{
        message("chat", HIG"
〖"HIR"江湖"HIG"〗：寂静已久的江湖似乎已不再宁静，表面上平静的各大门派私下里也有了
          骚动，正是风雨欲来之势.........

        \n"NOR,users());
        remove_call_out("notice1");
        call_out("notice1",10);
}

void notice1()
{       
        party_at=random(sizeof(party));
        message("chat", HIG"
〖"HIR""+party[party_at]+"告急"HIG"〗：我派最近收到密报，一江湖神秘组织妄想消灭各大门派，一统江湖，

                他们的第一个目标就是我派，请各派高手予以支援。
        \n"NOR,users());
        remove_call_out("notice2");
        call_out("notice2",60);
}


void notice2()
{       
        message("chat", HIG"
〖"HIR"武林令"HIG"〗：接获"+party[party_at]+"飞鸽传书告急，盟主已发盟主令，各派高手尽快集
            合于"+party[party_at]+"的"+party_add[party_at]+"联手抗敌！

        \n"NOR,users());
        remove_call_out("notice3");
        call_out("notice3",60);
}

void notice3()
{
        object soilder;
        object room;

        object fightroom;
        count++;
        if(count<3){
        message("chat", HIG"
〖"HIR"武林令"HIG"〗：现在是非常时刻，任何人不得擅自离开，盟主已发盟主令，各派高手尽快集
            合于"+party[party_at]+"的"+party_add[party_at]+"，联手抗敌！

        \n"NOR,users());
        remove_call_out("notice3");
        call_out("notice3",60);
        }else {
        message("chat", HIG"
〖"HIR"武林令"HIG"〗：现在是非常时刻，任何人不得擅自离开，盟主已发盟主令，各派高手尽快集
            合于"+party[party_at]+"的"+party_add[party_at]+"，联手抗敌！"HIR"这是最后召集！！

        \n"NOR,users());
        count=0;
        if(objectp(room_c=load_object(party_a[party_at])) && 

                  objectp(soilder = new("/u/daniel/haojie/npc/wuzhe"))){
                  room_c->set("exits/zhanchang","/u/daniel/haojie/zhanchang0");
                soilder->move(room_c);
        }
                message("chat", HIG"
〖"HIR"武林急报"HIG"〗：神秘组织皇皇教教众已经在"+party[party_at]+"附近出没了！！
                \n"NOR,users());

        fightroom = find_object("/u/daniel/haojie/zhanchang0");
        if( !fightroom) fightroom = load_object("/u/daniel/haojie/zhanchang0");
        if(fightroom){
        fightroom->set("out_permission", 0);
        fightroom->set("exits/out", party_a[party_at]);
        }
        remove_call_out("fight");
        call_out("fight",180);
        remove_call_out("kaoshang");
        call_out("kaoshang",620);
        }
        
}

void fight()
 {
        object enemy;
        object room;
        object *soilder_list;
        int i,n,j,k;

        if(objectp(room=load_object("/u/daniel/haojie/zhanchang0")) && 
        objectp(enemy = new("/u/daniel/haojie/npc/dibing")))
        enemy->move(room);
        message("chat", HIG"
〖"HIR"武林急报"HIG"〗：神秘组织皇皇教现在开始攻击"+party[party_at]+"了！！
        \n"NOR,users());
        for (n = 1; n <= 49; n++) {

                room=load_object("/u/daniel/haojie/zhanchang"+ random(5));
                enemy = new("/u/daniel/haojie/npc/dibing");
                enemy->move(room);
        }
     soilder_list = children("/u/daniel/haojie/npc/wuzhe");
     for(i=0; i<sizeof(soilder_list); i++) 
     if(environment(soilder_list[i]))
    {
                        message_vision("$N急急忙忙赶往堵击入侵的皇皇教！\n",soilder_list[i]);
                        destruct(soilder_list[i]);
                }

       remove_call_out("fight2");
       call_out("fight2",60);

}
void fight2()
 {
      object enemy;
      object room;
      int m,p,q;

        if(objectp(room=load_object("/u/daniel/haojie/zhanchang"+random(5))) && 
        objectp(enemy = new("/u/daniel/haojie/npc/dijun")))
        enemy->move(room);
        message("chat", HIG"
〖"HIR"神秘组织"HIG"〗：先灭少林，再灭武当。"+party[party_at]+"如果再顽冥不化，一律杀无赦！！
        \n"NOR,users());
        for (m = 1; m <= 25; m++) {

                room=load_object("/u/daniel/haojie/zhanchang"+random(5));
                enemy = new("/u/daniel/haojie/npc/dijun");
                enemy->move(room);
        }
       remove_call_out("fight3");
       call_out("fight3",60);
       
}
void fight3()

 {
        object enemy;
        object room;
        int n,j,k;

        if(objectp(room=load_object("/u/daniel/haojie/zhanchang"+random(5))) && 
        objectp(enemy = new("/u/daniel/haojie/npc/dijun")))
        enemy->move(room);
        message("chat", HIG"
〖"HIR"神秘组织"HIG"〗：杀光"+party[party_at]+"的弟子和这些顽冥不化家伙，统一江湖指日可待，杀....啊....！！
        \n"NOR,users());
        for (n = 1; n <= 9; n++) {

                room=load_object("/u/daniel/haojie/zhanchang"+random(5));
                enemy = new("/u/daniel/haojie/npc/dijiang");
                enemy->move(room);
        }
       
}

void event_sunrise()
{
        object *ob1_list;
      int i;
        ob1_list = children("/u/daniel/haojie/npc/dijiang");
        for(i=0; i<sizeof(ob1_list); i++) 
        if(environment(ob1_list[i]))
        {
                message_vision("神秘组织首领大声喊道：他奶奶的，点子硬，风紧，扯乎！！\n",ob1_list[i]);
                destruct(ob1_list[i]);
        }
       remove_call_out("chetui1");
       call_out("chetui1",5);

    
}
void chetui1()
{
        object *ob2_list;
        int i;
        

        ob2_list = children("/u/daniel/haojie/npc/dijun");
        for(i=0; i<sizeof(ob2_list); i++) 
        if(environment(ob2_list[i]))
        {
                message_vision("$N大声喊道：教主有令，大家分路撤退！\n",ob2_list[i]);
                destruct(ob2_list[i]);

        }
        remove_call_out("chetui2");
        call_out("chetui2",5);
}
void chetui2()
{
        object *ob3_list;
        int i;
        

        ob3_list = children("/u/daniel/haojie/npc/dibing");
        for(i=0; i<sizeof(ob3_list); i++) 
        if(environment(ob3_list[i]))
        {
                message_vision("$N大声喊道：快跑呀！教主都跑了!\n",ob3_list[i]);
                destruct(ob3_list[i]);
        }
}


void kaoshang()
{
        object soilder;
        object fightroom;

          if (! room_c=find_object(party_a[party_at]))
                room_c=load_object(party_a[party_at]);
        if(objectp(room_c) && objectp(soilder = new("/u/daniel/haojie/npc/mengzhu"))){
                room_c->delete("exits/zhanchang");
                soilder->move(room_c);
        }
        message("chat", HIG"
〖"HIR"江湖"HIG"〗：各大门派结成的联盟，终于挫败了皇皇教的阴谋，江湖又恢复了往日的平静。
          但是平静之后又是什么呢？.............

〖"HIR"江湖"HIG"〗神秘组织教主皇皇尊者仰天狂叫：我不服！我不服！！我不服！！！我一定会回来的。
        \n"NOR,users());

        fightroom = find_object("/u/daniel/haojie/zhanchang0");
        if( !fightroom) fightroom = load_object("/u/daniel/haojie/zhanchang0");
        if( fightroom )
        fightroom->set("out_permission", 1);
}

