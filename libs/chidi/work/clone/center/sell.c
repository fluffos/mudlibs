#include <ansi.h>
inherit ROOM;

       void create() 
       { 
                   set("short", HIY "江 湖 购 物 中 心" NOR);
                   set("long", HIG "这里是江湖会员购物中心，只见这里"
                               "四周宽敞明亮，不远处\n整齐地摆放着很多"
                               "自动售货机(ASM)。\n" NOR
                   );
                  set("no_fight", 1);
                  set("no_fight_npc",1);
                  set("no_steal", 1);
                  set("have_quest", 1);   
                  set("no_sleep_room", "1");
                   set("exits", ([
                          "out"  :  "/clone/center/out_center",
                   ]));
                   set("objects", ([
                           __DIR__"npc/guanjian"  :  1,
                   ]));
                   set("no_fight", 1); 
                   set("item_desc", ([ 
                          "asm"  :    "机器屏幕上显示：" HIM + BLINK" 请插入(insert)你的会员卡 " NOR 
                                      "的字样，机器上\n布满着各种奇怪的按扭。\n",
                   ]));

                   setup();     
       } 


void init()
{
        add_action("do_insert", "insert");
        add_action("do_pull", "pull");
        add_action("do_list", "list");
        add_action("do_buy", "want");
        add_action("do_list_vip", "list_vip");
        add_action("do_buy_vip", "want_vip");        
}
int do_insert(string arg)
{
        object me, ob;
        me = this_player();

        if (! arg || arg == "")
                return 0;

        if (arg == "card" || arg == "huiyuan card")
        {
                if (! ob = present("huiyuan card", me)) return 0;

                if (me->query("temp/insert"))
                        return notify_fail("卡还没取呢!\n");

                if (me->is_busy())
                {
                        return notify_fail("你正忙着呢。\n");
                        return 1; 
                }
                destruct(ob);
                write(HIW "你将卡片插入自动售货机...\n" NOR);
                write(HIY "【江湖】自动售货机正在读取你卡上的数据，请稍后...\n" NOR);
                me->set("temp/insert", 1);
                call_out("show", 4 + random(2));
                return 1;
        }
}

//数据读取完毕，允许购物
int show()
{  
   int rmb;
   object me = this_player();
   rmb = this_player()->query("rmb");
   tell_object(me, HIC "你目前的存款为" + chinese_number(rmb) + "圆人民币。\n" NOR);
   write(HIG "数据读取成功，请输入(list)显示可以购买的普通物品，输入(want)购买物品。\n" NOR);
   write(HIG "输入(list_vip)显示可以购买的VIP物品，输入(want_vip)购买物品。\n" NOR);
   this_player()->set("temp/can_pull", 1);
     
   return 1; 
}

int do_list()
{
   string msg;
   if (! this_player()->query("temp/insert"))
   {
           write("请先插入会员卡。\n");
           return 1;
   }
  msg = HIC "【名称】                           \t【作用】            【成功率】                【价格】\n" NOR;
  msg +=HIR "------------------------------------会员普通商品价目表----------------------------------------\n";
  msg +=HIW "白虎赐元丹(Baihu dan)                  增加先天臂力            70%                    ￥ 15000.00\n";
  msg +=GRN "青龙炼睿丹(Qinglong dan)               增加先天悟性            70%                    ￥ 20000.00\n";
  msg +=HIR "朱雀玲珑丹(Zhuque dan)                 增加先天身法            70%                    ￥ 10000.00\n";
  msg +=HIW "玄武铸骨丹(Xuanwu dan)                 增加先天根骨            70%                    ￥ 10000.00\n";
  msg +=GRN "美容丸(Meili wan)                      增加先天容貌            90%                    ￥ 30000.00\n";
  msg +=GRN "福缘丹(Fu wan)                         增加先天福缘            90%                    ￥ 15000.00\n";
  msg +=HIY "神恩仙丹(shenen xiandan)               悟性20倍1小时           80%                    ￥ 500000000.00\n";
  msg +=HIY "魔力仙丹(moli xiandan)                 悟性8倍1小时            10%                    ￥ 2500000.00\n";
  msg +=HIY "神恩通神仙丹(Tongshen xiandan)         悟性4倍1小时            90%                    ￥ 40000.00\n";
  msg +=HIY "通灵仙丹(Tongling xiandan)             悟性4倍8小时            80%                    ￥ 150000.00\n";
  msg +=HIC "悟性丹(Wuxing dan)                     悟性2倍12小时           90%                    ￥ 20000.00\n";
  msg +=HIG "超级金刚钻(Super zuan)                 超级金刚钻              100%                   ￥ 100000000.00\n";
  msg +=HIG "锄头(Chutou)                           挖药材的锄头            100%                   ￥ 1000.00\n";
  msg +=HIR "功夫丹(gongfu dan)                     增加先天特技            10%                    ￥ 10000000.00\n";
  msg +=HIR "男溺泉(boy spring)                     变性                    10%                    ￥ 8000000.00\n";
  msg +=HIR "女溺泉(girl spring)                    变性                    10%                    ￥ 8000000.00\n";
  msg +=HIR "无溺泉(none spring)                    变性                    10%                    ￥ 8000000.00\n";
  msg +=HIR "九转九阳丹(jiuzhuan dan1)              学会九转九阳残篇        10%                    ￥ 8000000.00\n";
  msg +=HIR "九转九阴丹(jiuzhuan dan2)              学会九转九阴残篇        10%                    ￥ 8000000.00\n";
  msg +=HIR "九转六阴丹(jiuzhuan dan3)              学会九转六阴残篇        10%                    ￥ 8000000.00\n";
  msg +=HIR "九阳绝脉丹(jiuyang dan)                增加先天特技            10%                    ￥ 8000000.00\n";
  msg +=HIR "九阴绝脉丹(jiuyin dan)                 增加先天特技            10%                    ￥ 8000000.00\n";
  msg +=HIR "六阴鬼脉丹(liuyin dan)                 增加先天特技            10%                    ￥ 8000000.00\n";
  msg +=HIR "真命天子丹(emperor dan1)               增加先天特技            10%                    ￥ 8000000.00\n";
  msg +=HIG "天煞孤星丹(tiansha dan1)               增加先天特技            25%                    ￥ 8000000.00\n";
  msg +=HIM "九转吸阳丹(xiyang dan)                 增加特殊功效            20%                    ￥ 20000.00\n";
  msg +=RED "金刚钻(jinggang zuan)                  增加武器镶嵌孔数        100%                   ￥ 5000.00\n";
  msg +=MAG "幽昙仙花(youtan flower)                使人返老还童            100%                   ￥ 20000.00\n";
  msg +=HIM "莫邪令(moxie ling)                     转换武器种类            100%                   ￥ 50000.00\n";
  msg +=HIW "魔睛烛舞铁(tie1)                       属性300攻击400          100%                   ￥ 500000.00\n";
  msg +=HIW "魔睛烛舞铁(tie2)                       属性350攻击500          100%                   ￥ 1000000.00\n";
  msg +=HIW "魔睛烛舞铁(tie3)                       属性400攻击600          100%                   ￥ 2000000.00\n";
  msg +=HIW "魔睛烛舞铁(tie4)                       属性450攻击800          100%                   ￥ 20000000.00\n";
  msg +=HIW "魔睛烛舞铁(tie5)                       属性800攻击1200         100%                   ￥ 100000000.00\n";
 

  msg +=HIR "---------------------------------尚有众多商品正在生产中----------------------------------------\n\n" NOR;
  write(msg);
  return 1;

}
int do_list_vip()
{
   string msg;
   if (! this_player()->query("temp/insert"))
   {
           write("请先插入会员卡。\n");
           return 1;
   }
  msg = HIC "【名称】                           \t【作用】               【成功率】                【价格】\n" NOR;
  msg +=HIR "----------------------------------------会员VIP商品价目表---------------------------------------------\n";
  msg +=HIG "天书残谱第2篇(Tianshu canpu2)      一小时内可以和某人学习读书写字      30%                    ￥ 5.00\n";
  msg +=HIR "-------------------------------------尚有众多VIP商品正在生产中------------------------------------------\n\n" NOR;
  write(msg);
  return 1;

}


int do_pull(string arg)
{
        object me,ob;
        int rmb;
        me = this_player();

        if (! arg || (arg != "card" && arg != "huiyuan card"))
                return 1;

        if (me->is_busy())
        {
                return notify_fail("你正忙着呢。\n");
        }
        // 判断卡片是否未取出
        if (me->query("temp/insert") && me->query("temp/can_pull"))
        {      
                rmb = me->query("rmb");
                tell_object(me, HIC "你目前的存款为" + chinese_number(rmb) + "圆人民币。\n" NOR);
                write(HIW "你将卡片从【江湖】自动售货机中取出。\n" NOR);
                ob = new("/clone/center/hycard.c");
                ob->move(me);
                me->delete("temp/insert");
                return 1;
        }
        write(HIR "操作错误!\n" NOR);
        return 1;
}


int do_buy(string arg)
{
    object me, ob, diamond;
    int rmb, feng,sun,lighting,water;
    
    me = this_player();
    rmb = me->query("rmb");
    
    if (! arg || arg == "")  return notify_fail("你要购买什么？\n");
    
    
    
    
    
    if (arg == "baihu dan")
    {
          if (rmb < 15000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/str2");
          ob->move(me);
          me->add("rmb", -15000);  
          write(HIG "你买下一颗白虎赐元丹！\n" NOR);
    }    
     else if (arg == "qinglong dan")
    {
          if (rmb < 20000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/int2");
          ob->move(me);
          me->add("rmb", -20000);  
          write(HIG "你买下一颗青龙炼睿丹！\n" NOR);
    }        
    else if (arg == "zhuque dan")
    {
          if (rmb < 10000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/dex2");
          ob->move(me);
          me->add("rmb", -10000);    
          write(HIG "你买下一颗朱雀玲珑丹！\n" NOR);      
    }        
   
    else if (arg == "xuanwu dan")
    {
          if (rmb < 10000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/con2");
          ob->move(me);
          me->add("rmb", -10000);    
          write(HIG "你买下一颗玄武铸骨丹！\n" NOR);
    }        
    
     else if (arg == "meili wan")
    {
          if (rmb < 30000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/perwan");
          ob->move(me);
          me->add("rmb", -30000);      
          write(HIG "你买下一颗美丽丸！\n" NOR);
    }
     else if (arg == "fu wan")
    {
          if (rmb < 15000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/karwan");
          ob->move(me);
          me->add("rmb", -15000);      
          write(HIG "你买下一颗福缘丹！\n" NOR);
    }
    
    else if (arg == "shenen xiandan")
    {
          if (rmb < 500000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/20bei");
          ob->move(me);
          me->add("rmb", -500000000); 
          write(HIG "你买下一颗"HIY"神恩仙丹"NOR"！\n" );       
    } 
  
   else if (arg == "moli xiandan")
    {
          if (rmb < 2500000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/moli");
          ob->move(me);
          me->add("rmb", -2500000); 
          write(HIG "你买下一颗"HIY"魔力仙丹"NOR"！\n" );       
    } 
    
    else if (arg == "tongshen xiandan")
    {
          if (rmb < 40000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/wx/tongshen");
          ob->move(me);
          me->add("rmb", -40000); 
          write(HIG "你买下一颗"HIY"神恩通神仙丹"NOR"！\n" );       
    } 
    
    else if (arg == "tongling xiandan")
        {
          if (rmb < 150000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("clone/wx/tongling.c");
          ob->move(me);
          me->add("rmb", -150000);      
          write(HIG "你买下一颗通灵仙丹！\n" NOR);
    }

   else if (arg == "wuxing dan")
    {
          if (rmb < 20000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/wx/wxdan");
          ob->move(me);
          me->add("rmb", -20000); 
          write(HIG "你买下一颗悟性丹！\n" NOR);       
    } 
    
    else if (arg == "super zuan")
    {
          if (rmb < 100000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/luoyun/gift/jingangzuan2");
          ob->move(me);
          me->add("rmb", -100000000); 
          write(HIG "你买下一把超级金刚钻！\n" NOR);       
    } 
    else if (arg == "chutou")
    {
          if (rmb < 1000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/baowu/chutou");
          ob->move(me);
          me->add("rmb", -1000); 
          write(HIG "你买下一把锄头！\n" NOR);       
    } 
   
    else if (arg == "gongfu dan")
    {
          if (rmb < 10000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/gongfudan");
          ob->move(me);
          me->add("rmb", -10000000);        
          write(HIG "你买下一颗功夫丹！\n" NOR);
    }        
      else if (arg == "boy spring")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/boyspring");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一碗男溺泉水！\n" NOR);
    }        
   else if (arg == "girl spring")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/girlspring");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一碗女溺泉水！\n" NOR);
    }    

 else if (arg == "none spring")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/nonespring");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一碗无溺泉水！\n" NOR);
    }  
 
 else if (arg == "jiuzhuan dan1")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/jiuzhuandan1");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗九转九阳丹！\n" NOR);
    }        

 else if (arg == "jiuzhuan dan2")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/jiuzhuandan2");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗九转九阴丹！\n" NOR);
    }        

 else if (arg == "jiuzhuan dan3")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/jiuzhuandan3");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗九转六阴丹！\n" NOR);
    }     

  else if (arg == "jiuyang dan")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/jiuyangdan");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗九阳绝脉丹！\n" NOR);
    }        
    
    else if (arg == "jiuyin dan")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/jiuyindan");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗九阴绝脉丹！\n" NOR);
    }   

 else if (arg == "liuyin dan")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/seabird/gift/liuyindan");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗六阴鬼脉丹！\n" NOR);
    }   
     
    else if (arg == "emperor dan1")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/emperor1");
          ob->move(me);
          me->add("rmb", -8000000);        
          write(HIG "你买下一颗真命天子丹！\n" NOR);
    }        
   
    
    else if (arg == "tiansha dan1")
    {
          if (rmb < 8000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/lonely1");
          ob->move(me);
          me->add("rmb", -8000000); 
          write(HIG "你买下一颗天煞孤星丹！\n" NOR);       
    }        
       
   else if (arg == "xiyang dan")
    {
          if (rmb < 20000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/jiuzhuan1");
          ob->move(me);
          me->add("rmb", -20000);      
          write(HIG "你买下一颗九转吸阳丹！\n" NOR);
    }
   
     else if (arg == "jinggang zuan")
    {
          if (rmb < 5000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/u/luoyun/gift/jingangzuan");
          ob->move(me);
          me->add("rmb", -5000);      
          write(HIG "你买下一根金刚钻！\n" NOR);
    }
   
         else if (arg == "youtan flower")
    {
          if (rmb < 20000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/d/gaochang/obj/youtan2.c");
          ob->move(me);
          me->add("rmb", -20000);      
          write(HIG "你买下一株"MAG "幽昙仙花！\n" NOR);
    }
         else if (arg == "moxie ling")
    {
          if (rmb < 50000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/wx/moxieling.c");
          ob->move(me);
          me->add("rmb", -50000);      
          write(HIG "你买下一个"HIM "莫邪令！\n" NOR);
    }
     


    else if (arg == "tie1")
        {
          if (rmb < 500000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/d/jh/weapon/jue/jue1.c");
          ob->move(me);
          me->add("rmb", -500000);      
          write(HIG "你买下魔睛烛舞铁1号！\n" NOR);
    }
 else if (arg == "tie2")
        {
          if (rmb < 1000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/d/jh/weapon/jue/jue2.c");
          ob->move(me);
          me->add("rmb", -1000000);      
          write(HIG "你买下魔睛烛舞铁2号！\n" NOR);
    }
 else if (arg == "tie3")
        {
          if (rmb < 2000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/d/jh/weapon/jue/jue3.c");
          ob->move(me);
          me->add("rmb", -2000000);      
          write(HIG "你买下魔睛烛舞铁3号！\n" NOR);
    }
 else if (arg == "tie4")
        {
          if (rmb < 20000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/d/jh/weapon/jue/jue4.c");
          ob->move(me);
          me->add("rmb", -20000000);      
          write(HIG "你买下魔睛烛舞铁4号！\n" NOR);
    }


else if (arg == "tie5")
        {
          if (rmb < 100000000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/d/jh/weapon/jue/jue5.c");
          ob->move(me);
          me->add("rmb", -100000000);      
          write(HIG "你买下魔睛烛舞铁5号！\n" NOR);
    }
    
    else{
          write(HIR "操作错误！\n" NOR);
          return 1;
    }
    write(HIG "操作完成! 离开前请记得取出(pull)卡片。\n");
    rmb = me->query("rmb");
    tell_object(me, HIC "你目前的存款为" + chinese_number(rmb) + "圆人民币。\n" NOR);
    if (me->query("rmb") < 1000) 
          write(HIY "你的余额已不多，为避免给你带来的不便，请及时充值。\n" NOR);
    return 1;
}

int do_buy_vip(string arg)
{
    object me, ob;
    int rmb, feng,sun,lighting,water;
    
    me = this_player();
    rmb = me->query("rmb");
    if (rmb < 2000) 
            return notify_fail("你还不是VIP会员，VIP会员要求人民币金额大于2000元，
注：VIP会员无须申请，只要满足以上条件将会自动成为VIP会员。\n"); 
 
    if (! arg || arg == "") return notify_fail("你要购买什么？\n");  
    
    if (arg == "tianshu canpu")
    {
          if (rmb < 5)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/book1");
          ob->move(me);
          me->add("rmb", -5); 
          write(HIG "你买下一本《天书残谱-第2篇》！\n" NOR);       
    }     
   else if (arg == "tianshu canpu2")
    {
          if (rmb < 5)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/book1");
          ob->move(me);
          me->add("rmb", -5); 
          write(HIG "你买下一本《天书残谱-第2篇》！\n" NOR);       
    }
   else if (arg == "tianshu canpu3")
    {
          if (rmb < 2000)
          { 
              write("对不起,你的卡上余额已不足,请尽快充值!\n" NOR);
              return 1;
          }
          ob = new("/clone/fam/gift/book1");
          ob->move(me);
          me->add("rmb", -3000); 
          write(HIG "你买下一本《天书残谱-第2篇》！\n" NOR);       
    }  

   else{
          write(HIR "操作错误！\n" NOR);
          return 1;
        }    
         
    write(HIG "操作完成! 离开前请记得取出(pull)卡片。\n");
    rmb = me->query("rmb");
    tell_object(me, HIC "你目前的存款为" + chinese_number(rmb) + "圆人民币。\n" NOR);
    if (me->query("rmb") < 20) 
          write(HIY "你的余额已不多，为避免给你带来的不便，请及时充值。\n" NOR);
    return 1;
}


int valid_leave(object me, string dir)
{
	
	{
	mapping fam;

	if (dir == "out")
	{
		if( mapp(fam = me->query("temp/insert"))) 
		
			return ::valid_leave(me, dir);
		
		
		if( me->query("temp/insert"))
		{
			return notify_fail("关键说道：“请取出你的会员卡（pull card）再离开吧。”\n");
		}

	}

	return ::valid_leave(me, dir);
}



}



