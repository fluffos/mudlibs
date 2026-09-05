//古玩字画
#include "ansi.h"
inherit ITEM;
#include "identify.h"

string * guwanlist=({"龙耳虎足方壶","三尺珊瑚","莲鹤方壶","虎噬鹿器座","合卺杯","铜仙承露盘","禾大人面纹方鼎","蓝釉灯","夜明珠",});
string * guwanid=({"fang hu","shanhu","lianhe fanghu","luqi zuo","hejin bei","chenglu pan","fang ding","lanyou deng","yeming zhu",});
int * guwanvalue=({350000+random(50000),440000+random(100000),645000+random(200000),510000+random(70000),500000+random(140000),910000+random(50000),990000+random(200000),600000+random(50000),650000+random(150000),});
string * s_guwanlist=({"和氏璧","传国玉玺",});
string * s_guwanid=({"heshi bi","chuanguo yuxi",});
int * s_guwanvalue=({5000000,5500000,});
string * zihualist=({"蜀素帖","龙门二十品","衡方碑","寿春堂记","神策军碑","颜家庙碑","化度寺碑","黄庭经","枯木竹石图","历代帝王图","江帆楼阁图","秋山晚翠图","睿鹤图","赤壁图","四季花卉图","富春山居图","金明池夺标图"});
int * zihuavalue=({740000+random(50000),780000+random(50000),990000+random(50000),520000+random(50000),600000+random(150000),700000+random(80000),900000+random(200000),1000000+random(50000),810000+random(50000),910000+random(50000),740000+random(50000),690000+random(100000),720000+random(50000),600000+random(50000),500000+random(50000),620000+random(50000),610000+random(80000)});
string * zihuaid=({"shusu tie","ershi pin","hengfang bei","shouchuntang ji","shence junbei","yanjia miaobei","huadusi bei","huangting jing","kumu tu","diwang tu","louge tu","wancui tu","ruihe tu","chibi tu","huahui tu","shanju tu","duobiao tu"});
string * s_zihualist=({"兰亭序","快雪时晴帖","天王送子图",});
string * s_zihuaid=({"lanting xu","kuaixue tie","songzi tu",});
int * s_zihuavalue=({2700000,1900000,1750000,});
int get_level(object ob)
{
    int n,i;
    if (ob->query("guwan"))
    {
        n=random(sizeof(guwanlist));
        ob->set("itemlist",n+1);
        ob->set("real_value",guwanvalue[n]);
    }
    else if (ob->query("zihua"))
    {
        n=random(sizeof(zihualist));
        ob->set("itemlist",n+1);
        ob->set("real_value",zihuavalue[n]);
    }
    else if (ob->query("is_guwanzihua"))
    {
        if (random(100)>49)
        {
            n=random(sizeof(guwanlist));
            ob->set("guwan",1);
            ob->set("itemlist",n+1);
            ob->set("real_value",guwanvalue[n]);
        }
        else
        {
            n=random(sizeof(zihualist));
            ob->set("zihua",1);
            ob->set("itemlist",n+1);
            ob->set("real_value",zihuavalue[n]);
        }
          
    }
    else
    {
        return 1;
    }
    if (ob->query("real_value")<200000)
    {
        ob->set("level",1);
        return 1;
    }
    else if (ob->query("real_value")<350000 && ob->query("real_value")>=200000)
    {
        ob->set("level",2);
        return 1;
    }
    else if (ob->query("real_value")<500000 && ob->query("real_value")>=350000)
    {
        ob->set("level",3);
        return 1;
    }
    else if (ob->query("real_value")<700000 && ob->query("real_value")>=500000)
    {
        ob->set("level",4);
        return 1;
    }
    else if (ob->query("real_value")<1000000 && ob->query("real_value")>=700000)
    {
        ob->set("level",5);
        return 1;
    }
    else if (ob->query("real_value")<1400000 && ob->query("real_value")>=1000000)
    {
        ob->set("level",6);
        return 1;
    }
    else if (ob->query("real_value")<1800000 && ob->query("real_value")>=1400000)
    {
        ob->set("level",7);
        return 1;
    }
    else if (ob->query("real_value")<2200000 && ob->query("real_value")>=1800000)
    {
        ob->set("level",8);
        return 1;
    }
    else
    {
        ob->set("level",9);
        return 1;
    }
}

int rename()
{
    object ob=this_object();
    int n;
    ob->set("no_pawn",1);
    ob->set("no_store",1);
    if (ob->query("guwan"))
    {
        n=ob->query("itemlist")-1;
        ob->set_name(guwanlist[n],({guwanid[n],}));
        ob->set("value",guwanvalue[n]);
        if (ob->query("owner"))//桃花新手任务
        {
            ob->set("value",100);
            ob->set("level",1);
        }
        ob->set("guwan_jiandinged", 1);
        return 1;
    }
    else if (ob->query("zihua"))
    {
        n=ob->query("itemlist")-1;
        ob->set_name(zihualist[n],({zihuaid[n],}));
        ob->set("value",zihuavalue[n]);
        if (ob->query("owner"))//桃花新手任务
        {
            ob->set("value",100);
            ob->set("level",1);
        }
        ob->set("guwan_jiandinged", 1);
        return 1;
    }
    else if (ob->query("is_guwanzihua"))
    {
        if (random(100)>49)
        {
            n=ob->query("itemlist")-1;
            ob->set_name(guwanlist[n],({guwanid[n],}));
            ob->set("value",guwanvalue[n]);
            if (ob->query("owner"))//桃花新手任务
            {
                ob->set("value",100);
                ob->set("level",1);
            }
            ob->set("guwan_jiandinged", 1);
            return 1;
        }
        else
        {
            n=ob->query("itemlist")-1;
            ob->set_name(zihualist[n],({zihuaid[n],}));
            ob->set("value",zihuavalue[n]);
            if (ob->query("owner"))//桃花新手任务
            {
                ob->set("value",100);
                ob->set("level",1);
            }
            ob->set("guwan_jiandinged", 1);
            return 1;
        }
          
    }
    else
    {
        return 1;
    }
}

//返回物品是否需要鉴定
//对于需要鉴定物品，返回鉴定类型
//0为不能鉴定的物品，
//1为直接调用物品本身的identify函数鉴定就可以的物品
//2为武器装备，需要鉴定技能鉴定
int is_identify()
{
  object ob=this_object();
  
  if ( ob->query("is_guwanzihua") &&
       !ob->query("guwan_jiandinged") )
    return IDF_ANTIQUE;
  else
    return IDF_CANT;
}

//校验鉴定能否鉴定该物品的方法
varargs int valid_identify(object player)
{
  object ob=this_object();
  int type, ob_lv;

  //不可鉴定物品不能鉴定
  if ( (type=ob->is_identify())==IDF_CANT )
    return 0;
  
  ob_lv=(int)ob->query("level");
  if ( ob_lv<=0 || ob->query("owner") )
  {
    ob_lv=1;
  }
    
  if ( objectp(player) && 
       userp(player) && 
       ( player->query_skill("identification",1)<ob_lv*ob_lv*ob_lv ||
         player->query_skill("anti-disguise",1)<ob_lv*(ob_lv+1)-1 ) )
  {
    tell_object(player, "鉴定技能不足无法鉴定出任何有价值信息。\n");
    return 0;
  }
  
  if ( objectp(player) && 
       userp(player) && 
       player->query_temp("cannotidentify") )
  {
    tell_object(player, "你正在鉴定其他物品，无法分心鉴定这件宝物。\n");
    return 0;
  }
    
  //不存在鉴定者无法给你鉴定
  if ( !objectp(player) )
    return 0;
    
  //非玩家如果本身设定的鉴定级别判定无法通过则无法鉴定
  if ( objectp(player) &&
       !userp(player) &&
       !player->get_idflevel(ob) )
    return 0;
  
  return 1;
}

//设定物品的鉴定级别
//被鉴定者鉴定以后设定对物品的鉴定程度
//古玩本身没有细分鉴定级别，只有一次鉴定机会
varargs int set_idflevel(object player)
{
  return 1;
}

//显示物品的鉴定级别
//所有鉴定级别定义采用标准定义，具体见IL_系列define，不管内部如何定义，外部统一采用该返回值定义
//古玩本身没有鉴定级别，都是IL_FULL
varargs int get_idflevel(object item)
{
  object ob=this_object();
  
  if ( ob->query("is_guwanzihua") )
    return IL_FULL;
  else
    return IL_INIT;
}

//增加装备的鉴定功能
//idf_level:鉴定级别，同identify.h中关于鉴定级别的定义
//player为鉴定者，鉴定者不一定需要有
varargs string identify(int idf_level, object player)
{
  object ob=this_object();
  int dur, d_lv, i_lv;
  //IL_INIT级别的时候无法鉴定出任何有用信息
  if ( idf_level==IL_INIT )
    return "";
  
  d_lv=(int)(player->query_skill("anti-disguise",1))/10;
  i_lv=(int)(player->query_skill("identification",1))/10;
  dur=(int)ob->query("level")*5-random(d_lv+i_lv);
  if (dur>=15)
  {
    dur=15;
  }
  if (dur<1)
  {
    dur=1;
  }
  
  player->set_temp("鉴定周期",dur);
  call_out("jd",1,player,ob);
  return player->name()+"在正专心地鉴定"+ob->name()+"。\n";
}

int jd(object me,object ob)
{
    if (!me)
    {
        return 1;
    }
    if (!living(me))
    {
        me->delete_temp("鉴定周期");
        return 1;
    }
    if (!ob)
    {
        tell_object(me,"你要鉴定的东西不见了。\n");
        me->delete_temp("鉴定周期");
        return 1;
    }
    if (me->query_temp("鉴定周期")<1)
    {
        ob->rename();
        ob->set("guwan_jiandinged", 1);
        message_vision("$N发现手中的竟是"+ob->query("name")+"。\n",me);
        me->delete_temp("cannotidentify");
        return 1;
    }
    message_vision("$N小心地捧着$n上上下下仔仔细细的打量了一遍。\n",me,ob);
    me->add_temp("鉴定周期",-1);
    call_out("jd",1,me,ob);
    return 1;
}