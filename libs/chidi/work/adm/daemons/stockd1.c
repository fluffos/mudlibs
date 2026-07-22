//stockd.c
#include <ansi.h>
       //股市行情 
       //2010.6.26 
      
      //#pragma optimize
      // #pragma save_binary 
       
       inherit F_SAVE; 
      inherit F_DBASE; 
       
      mapping td_name = 0; //上市股票 
      mapping buy_name = 0; //购买股票 
       
      static object xw; 
      int oldZhishu; 
       
      void create() 
      { 
             seteuid(ROOT_UID); 
             set_heart_beat(60); 
              restore(); 
              load_object("/d/city/qianzhuang"); 
              xw = find_object("/d/city/npc/qian"); 
      } 
       
      void remove() { save(); } 
       
      void mud_shutdown() { save(); } 
       
      string query_save_file() { return DATA_DIR "gupiao"; } 
       
      mapping query_stock_list() { return td_name; } 
      
      mapping query_buy_list() { return buy_name; } 
       
      int query_zhishu() { return oldZhishu; } 
       
      void dest_buy_list() { buy_name = 0; } 
       
      void add_stock_index(int index) 
      { 
              int i,size; 
              mixed key; 
              
             key = keys(td_name); 
              size = sizeof(key); 
              for(i=0;i<size;i++) 
              { 
                      td_name[key[i]] = ({td_name[key[i]][0]+index,td_name[key[i]][1],td_name[key[i]][2],td_name[key[i]][3],td_name[key[i]][4]});  
              } 
      } 
       
      void init_td_list() 
      { 
              int i,size; 
              mixed key; 
       
              key = keys(td_name); 
              size = sizeof(key); 
                for(i=0;i<size;i++) 
              { 
          td_name[key[i]] = ({5000+random(5500),0,1+random(20),"",0});       
              } 
              oldZhishu = 0; 
      } 
       
      void heart_beat() 
      { 
              int time = time(),rand,tiao=0,random; 
              int i,size,money,tmp=0,index,zhishu=0; 
              mixed keys; 
              mapping info; 
              string str=""; 
       
              //股票涨跌 
              if(!td_name) return; 
              keys = keys(td_name); 
              size = sizeof(keys); 
              for(i=0;i<size;i++) 
              { 
                      info = td_name[keys[i]]; 
                      money = info[2] - info[1]; 
                      str = info[3]; 
                      //退市 
                      if(info[2] < 1) 
                      { 
                              if(!info[4]) info[4] =time(); 
                             //再次上市 
                              if(info[4]+60 < time) //600
                              { 
                                      //公告再次上市 
                                      td_name[keys[i]] = ({5000+random(2500),0,1+random(10),"↑",time}); 
                                      CHANNEL_D->do_channel( xw, "xw", sprintf("%s扭亏为盈，再次通过资产审核，股本上市。\n",keys[i]));
                                     
                             } 
                              else 
                              { 
                                      td_name[keys[i]] = ({0,0,0,"退市",info[4]}); 
                                     buy_name[keys[i]] = 0; 
                                     if(random(100) < 8) CHANNEL_D->do_channel( xw, "xw", sprintf("%s遭到大庄稼大幅抛售股本，现金已支付一空被迫退市。\n",keys[i])); 
                             } 
                     } 
                     //价格波动 
                     else 
                     { 
                             random = random(500); 
                             //发生意外 
                             if(random < 3) 
                             { 
                                     random = random(100); 
                                     if(info[3] != "退市") switch(info[3]) 
                                     { 
                                             case "↓" : 
                                                     if(random < 33) CHANNEL_D->do_channel( xw, "xw", sprintf("%s因谎报业绩，蓄意扰乱股市行情，从而获取暴利，相关责任人已被巡捕逮捕。\n",keys[i])); 
                                                    else if(random < 66) CHANNEL_D->do_channel( xw, "xw", sprintf("%s因庄家抛售，大幅度下跌。\n",keys[i])); 
                                                     else CHANNEL_D->do_channel( xw, "xw", sprintf("%s受到三路奶粉影响，股价下跌。\n",keys[i])); 
                                                     td_name[keys[i]] = ({info[0],1,1,info[3],info[4]}); 
                                             break; 
                                            case "↑" : 
                                                     if(random < 50) CHANNEL_D->do_channel( xw, "xw", sprintf("一个叫美国USA的地方，近日来爆发经济危机，严重影响%s的股票价格。\n",keys[i])); 
                                                     else CHANNEL_D->do_channel( xw, "xw", sprintf("%s邀请芙蓉姐姐作代言人，导致群众不满。\n",keys[i])); 
                                                     td_name[keys[i]] = ({info[0],1,1,info[3],info[4]}); 
                                             break; 
                                             case "→" : 
                                                     if(random < 25) CHANNEL_D->do_channel( xw, "xw", sprintf("%s邀请芙蓉姐姐作代言人，导致群众不满，纷纷抛售该股。\n",keys[i])); 
                                                     else if(random < 50) CHANNEL_D->do_channel( xw, "xw", sprintf("%s因经营不善，依据相关规定，勒令限期整改，大家赶快清仓。\n",keys[i])); 
                                                   else if(random < 75) CHANNEL_D->do_channel( xw, "xw", sprintf("%s因庄家抛售，大幅度下跌。很多散户已经清仓。\n",keys[i])); 
                                                     else CHANNEL_D->do_channel( xw, "xw", sprintf("%s受到三路奶粉影响，股价下跌。\n",keys[i])); 
                                                     td_name[keys[i]] = ({0,0,0,"退市",info[4]}); 
                                                     buy_name[keys[i]] = 0; 
                                             break; 
                                    } 
                                    continue; 
                            } 
     
                             if(td_name[keys[i]][0] < 0 ) tiao = 1; //continue; 
                              
                            rand = random(info[1]); 
                            if(random < 42 ) tmp = info[2]-1; 
                             else if(random < 65 ) tmp = info[2]+1; 
      
                             if(tmp < 2) tmp = 2; 
     
                             //绘制波动坐标 
                             if(sizeof(str) > 300) str = ""; 
                             if(money > 0) str = "↑"; 
                             else if(money == 0) str = "→"; 
                             else str = "↓"; 
      
                             //模拟AI 
                             //当价格涨到一定程度时 抛售赚钱 
                             if(tmp > info[2] + info[2]*100/10) 
                             { 
                                    str = "↓"; 
                                     //影响股票价格 
                                     if(random <50) tmp /= 10; 
                                     else tmp = 1+tmp/100; 
                                     //影响股票数量 
                                     info[0] += 5000+random(5000); 
                             } 
                             //价格过低就买入 
                             if(tmp < info[2] - info[2]*100/10) 
                             { 
                                     str = "↑"; 
                                     //影响股票价格 
                                     tmp *= 2; 
                                     //影响股票数量 
                                     info[0] = 5000+random(5000); 
                             } 
      
                             td_name[keys[i]] = ({info[0],info[2],tmp,str,0}); 
                             zhishu += tmp; 
                     } 
                     //股本分红 
             } 
      
             if(!xw) xw = find_object("/d/city/npc/qian"); 
             zhishu /= size; 
             if(random(100) < 35)  
             { 
                     if(zhishu > oldZhishu) CHANNEL_D->do_channel( xw, "xw", "股本市盈率突破大观。详情请用 stock 指令察看。\n"); 
                     else if(zhishu == oldZhishu) CHANNEL_D->do_channel( xw, "xw", "部分个股开始大幅上扬。购入请用 stock <买进> 指令。\n"); 
                     else if(zhishu < oldZhishu) CHANNEL_D->do_channel( xw, "xw", "股本行情开始小幅震荡。抛售请用 stock <卖出> 指令。\n"); 
             } 
             oldZhishu = zhishu; 
     } 
      
     //股票上市 
     int add_stock(object me,string arg,int index) 
     { 
             if(!arg || !index || index < 1 || index > 50000) 
             { 
                     tell_object(me,"你要增加哪支股票，多少股本？\n"); 
                     return 0; 
             } 
      
             if (!td_name) td_name = ([ ]); 
      
             //每股价格 = 股票每股收益X行业市盈率 
             //({index,0,0}) 股本,旧价格,新价格,走势,退市时间 
             if (undefinedp(td_name[arg])) td_name += ([ arg : ({index,0,1+random(10),"",0}) ]); 
             else 
             { 
                     tell_object(me,"此本票已经上市。\n"); 
                    return 0; 
            } 
      
             //发布上市信息 
             tell_object(me,"OK!\n"); 
             return 1; 
     } 
      
     //买入 
     int buy_stock(object me,string arg,int index) 
            { 
             mapping info,oldBuy; 
             int size,j,i,zs,size2,code=1,buy_money,geshu=0; 
             mixed keys,key; 
             string ip = query_ip_number(me); 
             zs = me->query("zhuanshi/times");
      
            if(!arg || !index || index < 1 || index > 50000)
	        {
	          	tell_object(me,"你要购买哪只股票，多少股本？\n");
		            return 0;
	        }
             if(!buy_name) buy_name = ([]); 
             
             if ( zs < 8 )
             {
             tell_object(me,"您想买股票需要8转!\n");
                     return 0;
             }
             
             if(undefinedp(td_name[arg])) 
             { 
                     tell_object(me,"没有这支股票。\n"); 
                     return 0; 
             } 
             //检查是否过多购买 
            if(index > td_name[arg][0] && index > td_name[arg][0]) 
             { 
                     tell_object(me,"东家没有那么多股票出售！\n"); 
                     return 0; 
             } 
             //检查没有买入退市股票 
             if(td_name[arg][2] <= 0) 
             { 
                     tell_object(me,"无法完成交易！\n"); 
                     return 0; 
             } 
             //检查玩家等级
             if(td_name[arg][0] >= 1 && me->query_level()*500 < index) 
             { 
                     tell_object(me,"你等级不足买那么多股。\n"); 
                     return 0; 
             } 
             //检查是否垄断购买 
          if(td_name[arg][0] > 2 && index > td_name[arg][0]/2 ) //可购买总数上限为1/4 
         { 
                  tell_object(me,"禁止垄断购买！\n"); 
                   return 0; 
         } 
             //检查是否有钱买 
             buy_money = td_name[arg][2]*index; 
                  if(me->query("rmb") < buy_money) 
             { 
                     tell_object(me,"你的钱不够买那么多。\n"); 
                     return 0; 
             } 
             //检查是否合法购买 
             if(!undefinedp(buy_name[arg]) && buy_name[arg]) 
             { 
                     keys = keys(buy_name[arg]); 
                     size = sizeof(keys); 
                     for(j=0;j<size;j++) 
                     { 
                             if(keys[j] != me->query("id") && buy_name[arg][keys[j]] && buy_name[arg][keys[j]][1] == ip) 
                             { 
                                     tell_object(me,"补仓手段不合法！\n"); 
                                     return 0; 
                             } 
                     } 
             } 
             //检查购买上限 
             key = keys(buy_name); 
             size2 = sizeof(key); 
             for(i=0;i<size2;i++) 
             { 
                     if(!buy_name[key[i]]) continue; 
                     keys = keys(buy_name[key[i]]); 
                     size = sizeof(keys); 
                     for(j=0;j<size;j++) 
                     { 
                             if(buy_name[key[i]][keys[j]] && keys[j] == me->query("id")) 
                             { 
                                     geshu ++; 
                             } 
                     } 
             } 
             if(geshu >= 5) 
             { 
                     tell_object(me,"超过购买上限！\n"); 
                     return 0; 
             } 
		
             
           if(time() < me->query("stock_time")+60) 
           { 
                   tell_object(me,"一分钟内不能连续补仓。\n"); 
                   return 0; 
           } 
           me->delete("stock_time"); 
             info = td_name[arg]; 
             if(buy_name[arg] == 0) buy_name[arg] = ([]); 
             if(undefinedp(buy_name[arg])) buy_name += ([ arg : ([me->query("id") : ({ index,ip,time(),td_name[arg][2] }) ]) ]); 
             else if(undefinedp(buy_name[arg][me->query("id")])) buy_name[arg] += ([me->query("id") : ({ index,ip,time(),td_name[arg][2] })]); 
             else 
             { 
                     oldBuy = buy_name[arg][me->query("id")]; 
                    if(!oldBuy) 
                     { 
                             buy_name[arg][me->query("id")] = ({ index,ip,time(),td_name[arg][2] }); 
                     } 
                     else 
                     { 
                             if(oldBuy[1] == ip && time() < oldBuy[2]+60) 
                             { 
                                   tell_object(me,"1分钟内不能连续补仓。\n"); 
                                     return 0; 
                             } 
                             buy_name[arg][me->query("id")] = ({ index+oldBuy[0],ip,time(),td_name[arg][2] }); 
                     } 
                     code = 2; 
             } 
             //影响股票价格 
           if(buy_money > 10000) 
           { 
                   td_name[arg][2] += 1; 
                  td_name[arg][1] += 1; 
           } 
            //扣除股票可交易数量 
            td_name[arg][0] -= index; //不减少股票总量
             //扣除购买花费 
             me->add("rmb",-buy_money); 
             //交易标记 
           me->set("stock_time",time()); 
             save(); 
             return code; 
     } 
      
     //卖出股票 
     int sell_stock(object me,string arg,int index) 
     { 
             mapping info; 
             string ip = query_ip_number(me); 
             int j,size,money,zs; 
             mixed keys; 
             zs = me->query("zhuanshi/times");

              if(!arg || !index || index < 1)
	        {
	          	tell_object(me,"你要购买哪只股票，多少股本？\n");
		            return 0;
	        }
             
            
             if(!buy_name) return 0; 
             
                   if ( zs < 8 )
             {
             tell_object(me,"您想卖股票需要8转!\n");
                     return 0;
             }

             if(undefinedp(td_name[arg])) 
             { 
                     tell_object(me,"没有这支股票。\n"); 
                     return 0; 
             } 
             if(buy_name[arg] == 0) buy_name[arg] = ([]); 
             info = buy_name[arg][me->query("id")]; 
             //检查是否有库存 
             if(!info) 
             { 
                     tell_object(me,"你没有购买过这支股票！\n"); 
                     return 0; 
             } 
             //检查是否购出售 
             if(index > info[0]) 
             { 
                     tell_object(me,"你没有那么多股出售！\n"); 
                     return 0; 
             } 
             //检查是否合法卖出 
             if(!undefinedp(buy_name[arg])) 
             { 
                     keys = keys(buy_name[arg]); 
                     size = sizeof(keys); 
                     for(j=0;j<size;j++) 
                    { 
                             if(keys[j] != me->query("id") && buy_name[arg][keys[j]] && buy_name[arg][keys[j]][1] == ip) 
                             { 
                                     tell_object(me,"卖出手段不合法！\n"); 
                                     return 0; 
                            } 
                     } 
} 
           if(time() < me->query("stock_time")+60) 
           { 
                   tell_object(me,"1分钟内不能连续抛售。\n"); 
                   return 0; 
           } 
             if(info[1] == ip && time() < info[2]+60) 
             { 
                     tell_object(me,"1分钟内不能连续抛售。\n"); 
                     return 0; 
            } 
             money = td_name[arg][2]*index; 
             //处理卖出 
             if(info[0]-index <= 0) buy_name[arg][me->query("id")] = 0; 
             else buy_name[arg][me->query("id")] = ({ info[0]-index,ip,time(),td_name[arg][2] }); 
             //影响股票价格 
            if(money > 1000) 
             { 
                     td_name[arg][2] -= 1; 
                     td_name[arg][1] -= 1; 
             } 
             //影响股票数量 
            td_name[arg][0] += index; //不增加股票总量
             //增加自身收益 
             me->add("rmb",money); 
             //交易标记 
           me->set("stock_time",time()); 
             save(); 
             return 1; 
     } 
  
