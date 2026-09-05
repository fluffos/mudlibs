// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
//Modified by whuan to add dunno/all
// Modified by iszt@pkuxkx, 2007-01-18, added zhutou & id
// Modified by iszt@pkuxkx, 2007-03-11, added set env/answer_* *
// Modified by iszt@pkuxkx, 2007-03-12, changed from message_vision to command("say")
//

#include <ansi.h>
int check_en(string id);
inherit F_CLEAN_UP;

string *msg_dunno = ({
        CYN"$n"+CYN"摇摇头，说道：没听说过。\n"NOR,
        CYN"$n"+CYN"看着你，说道：我从没听说过这事。\n"NOR,
        CYN"$n"+CYN"皱了皱眉头，说道：你去问别人吧。\n"NOR,
        CYN"$n"+CYN"睁大眼睛望着$N"+CYN"，显然不知道$P在说什么。\n"NOR,
        CYN"$n"+CYN"耸了耸肩，很抱歉地说：无可奉告。\n"NOR,
        CYN"$n"+CYN"说道：嗯....这我可不清楚，你最好问问别人吧。\n"NOR,
        CYN"$n"+CYN"想了一会儿，说道：对不起，你问的事我实在没有印象。\n"NOR,
        CYN"$n"+CYN"看了$N"+CYN"一眼，说道：对不起。又接着忙自己的事去了。\n"NOR,
        CYN"$n"+CYN"不耐烦的瞪了$N"+CYN"一眼，说道：没看我正忙着吗？\n"NOR,
        CYN"$n"+CYN"耸了耸肩，很抱歉地说：我对闲谈不感兴趣。\n"NOR
});

string *msg_dunno1 = ({
        CYN"$n嘻嘻笑道：你说什么鸟语啊？\n"NOR,
        CYN"$n说道：才阿八热古里古鲁。你看，我也能假装会说外国话。\n"NOR,
        CYN"$n说道：你在说外国话吧？我不会，你最好带个翻译来。\n"NOR
});

int fix_weapon(object me)
{
    int fixed = 0;
    int cost = 0;

    object* inv = all_inventory(me);
    object ob, uitem;
    
    uitem=new(UITEM_OB);
    uitem->set("id", me->query("id"));
//    if ( uitem->check_save() )
      uitem->restore();
    
    for(int i =0;i<sizeof(inv);i++)
    {
      ob = inv[i];
      
      if(!ob->is_gems())
        continue;
      
      if(!ob->query("weapon_prop"))
        continue;
                
      if(ob->query("max_rigidity") < 2)
        continue;
    
      if(ob->query("max_rigidity") < ob->query("rigidity"))
      {
          //bug weapon
          ob->set("max_rigidity", ob->query("rigidity"));
          if(ob->query("gem_ob_autoloaded") == 1)
          {
            if ( ob->query("autoload_serial") )
              uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
          }                            
      }
                              
      if(ob->query("rigidity") == ob->query("max_rigidity"))
        continue;
        
      cost = (ob->query("max_rigidity") - ob->query("rigidity")) / 100;
      if(ob->query("forge/material1_level"))
      {
        cost += 1 * ob->query("forge/material1_level");
      }
      if(ob->query("forge/material2_level"))
      {
        cost += 1 * ob->query("forge/material2_level");
      }
      if(ob->query("forge/material3_level"))
      {
        cost += 1 * ob->query("forge/material3_level");
      }  
      if(ob->query("forge/material4_level"))
      {
        cost += 1 * ob->query("forge/material4_level");
      }
    
      if(cost < 1) cost = 1;
      
      me->add("score",-cost);
      
                
      if(random(5000) < (ob->query("max_rigidity") - ob->query("rigidity")))
      {
        write("由于常年使用，你的武器耐久永久性的下降了1点。\n");
        ob->add("max_rigidity",-1);
      }
    
      ob->set("rigidity",ob->query("max_rigidity"));
    
      if(ob->query("gem_ob_autoloaded") == 1)
      {
        if ( ob->query("autoload_serial") )
          uitem->update_autoload(ob->query("autoload_serial"), "set", ([ "rigidity": ob->query("max_rigidity") , "max_rigidity":ob->query("max_rigidity") ]));
      }    
      
      fixed = 1;        
    } 
    
    uitem->save();
    destruct(uitem);
    return fixed;            
}

int gb_newbie_ask(object me,object ob)
{
        int pin,count,i;
        object target,where,*inv,*all_player;
        ob->delete_temp("gb_newbie_extra");
        me->delete_temp("gb_newbie_extra");
        while(!target && count < 5)
        {
            where = TASK_D->random_place();
            inv = all_inventory(where);
            for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(!living(inv[i]) || userp(inv[i]) || inv[i]->query("race")!="人类"||inv[i]->query("CantQuery"))
                    continue;
                if(inv[i]->query("uni_target") || inv[i]->query("random_npc")||inv[i]->query("inquiry/rumors"))
                    continue;
                target = inv[i];
            }
            count++;
        }
        if (me->query_temp("gb_newbie_degree")>2)
        {
            me->delete_temp("gb_newbie_extra");
            me->delete_temp("gb_newbie_degree");
            all_player = filter_array(children(USER_OB), (: userp :));
            all_player = filter_array(all_player, (: environment :));
            target=all_player[random(sizeof(all_player))];
            me->set_temp("gb_newbie_finish",target->query("id"));
            tell_object(me,CYN+ob->query("name")+CYN+"道：『事情的真相其实是"+target->name()+CYN+"("+target->query("id")+")干的好事，你回到丐帮长老面前，说出(answer)他的英文名字即可。』\n"+NOR);
            return 1;
        }
        if (target)
        {
            tell_object(me,CYN+ob->query("name")+CYN+"道：『这个事情我真不清楚。』\n");
            tell_object(me,CYN+ob->query("name")+CYN+"道：『不过我想"+TASK_D->place_belong(where)+where->query("short")+CYN+"的"+target->query("name")+CYN+"应该了解情况。(ask "+target->query("id")+" about rumors)』\n"+NOR);
            pin=random(10000)+1;
            target->set_temp("gb_newbie_extra",pin);
            me->set_temp("gb_newbie_extra",pin);
            me->add_temp("gb_newbie_degree",1);
        }
        else
        {
            me->delete_temp("gb_newbie_extra");
            me->delete_temp("gb_newbie_degree");
            all_player = filter_array(children(USER_OB), (: userp :));
            all_player = filter_array(all_player, (: environment :));
            target=all_player[random(sizeof(all_player))];
            me->set_temp("gb_newbie_finish",target->query("id"));
            tell_object(me,CYN+ob->query("name")+CYN+"道：『事情的真相其实是"+target->name()+CYN+"("+target->query("id")+")干的好事，你回到丐帮长老面前，说出(answer)他的英文名字即可。』\n"+NOR);
            return 1;
        }
}
string relative_bless(object me,object target)//亲戚祝福
{
  mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
  object npc,place;
  if((target->query("name")==me->query("relationship/target_name")
        &&target->query("id")==me->query("relationship/target_id")
        &&target->query("combat_exp")==me->query("relationship/target_exp"))||base_name(target)==me->query("relationship/target_basename"))
  {
    if (me->query("relationship/daily_bless")==date)
    {
      return CYN"$n"+CYN+"道：“还好有你在啊，家族总算不是没救。”\n"NOR;
    }
    else
    {
      npc=new("/clone/npc/badguy");
      npc->player_name(me);
      while (!objectp(place) || 
      !place->isroom()||
      TASK_D->place_belong(place)=="不明区域"||
      TASK_D->place_belong(place)=="未知区域"||
      base_name(place) == "/adm/daemons/taskd")
		place=TASK_D->random_place();
      npc->move(place);
      if (!npc)  //killer在移动期间晕倒或被房间call die了
      {
        return CYN"$n"+CYN+"道：“听说咱们老"+COLOR_D->uncolor(me->query("name"))[0..0]+"家出了个败类，具体什么我再打听呢，你过会再来。”\n"NOR;
      }
      me->set_temp("relationship/daily_task",npc);
      npc->set("relative",me);
      me->set("relationship/daily_bless",date);
/*      for (int i=0;i<3;i++)  家门不幸任务的NPC随机移动没啥实际意义，又老出问题，注销掉。by lordstar
		if (npc&&living(npc))  
			npc->random_move(); */
      return CYN"$n"+CYN+"道：“"+COLOR_D->uncolor(me->query("name"))+"，你来的可正好，咱们老"+COLOR_D->uncolor(me->query("name"))[0..0]+"家出了个败类啦。\n"
      +npc->query("name")+"在"+TASK_D->place_belong(environment(npc))+"的"+environment(npc)->query("short")+CYN+"欺男霸女，为恶一方，你快去清理门户吧。”\n"NOR;
    }
  }
  else
  {
    return CYN"$n"+CYN+"道：“哦，你家门不幸啊？节哀节哀。但是，和我有什么关系？”\n"NOR;
  }
}
int main(object me, string arg)
{
        string dest, topic, msg, str,area_info;
        string *idea;
        int ok;
        string msg_normal;
        object ob;
        mapping inquiry;
        mapping *inq;
        string tmp;

        seteuid(getuid());
    if (time()>1367150400&&time()<1367151300)
        return notify_fail("北侠现在正在为震区默哀，任务将在"+CHINESE_D->chinese_period(1367151300-time())+"后重新开放。\n");
        if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
                return notify_fail("你要问谁什么事？\n");

        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("这里没有这个人。\n");

        if( !ob->is_character() ) {
                message_vision("$N对着$n自言自语....\n", me, ob);
                return 1;
        }
    if (ob->query("NoBusyAsking")&&me->is_busy())//busy时候不让ask，有玩家反复刷屏。
      return notify_fail("你正忙着呢。\n");
         if(topic == "all" && !userp(ob) && !ob->query("no_ask"))   //给npc加上no_ask标志，要不然有些谜题太容易了  by boost 2008.09.18
         {
                if(me->query("age") < 18)
           {
             ok = 1;
             
           }
           else {
             if(me->query("balance") < 10000)
             {
               ok = 0;
                                 tell_object(me,"你的存款不足一两黄金，无法支付咨询费用。\n"NOR);
             }
             else
             {
               
               ok = 1;
                                tell_object(me,"你从存款中划出一两黄金作为咨询费用交给" + ob->query("name") + "。\n"NOR);
               me->set("balance",me->query("balance")-10000);
             }  
             
             
           }
             if(ok)
           {
             inquiry = ob->query("inquiry");
             if(!mapp(inquiry))
             {  
               message_vision( CYN "$N说道：对不起，我啥也不知道呀...\n" NOR, ob);
               return 1;
             }
             idea = keys(inquiry);
             msg = "";
             for(int ii = 0;ii < sizeof(idea);ii++)
             {
                                if(ii < sizeof(idea)-1)
                                        msg += HIC+idea[ii]+NOR+"，";
                                else msg += HIC+idea[ii]+NOR;
             }
      tell_object(me,CYN+ob->name()+"对你说道：你可以向我打听有关"+msg+CYN"的内容！\n"NOR);  
      
    }
    return 1;
        }
/*
        if( topic=="?" )
        {
                if ( wiz_level(me) == 0 )
                {
                        tell_object( me,"对不起，只有巫师可以问这件事！\n");
                        return 1;
                }
                inq = ob->query("inquiry");
                if (sizeof(inq) == 0)
                {
                        tell_object( me, ob->query("name") + "什么也不知道！\n");
                        return 1;
                }
                
                str=sprintf("%O\n",inq); 
                write(ob->query("name") + "知道的事情如下：\n" + str);
                
                return 1;
        }
*/


        if( !ob->query("can_speak") ) {
                message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
                return 1;
        }

        if( !INQUIRY_D->parse_inquiry(me, ob, topic) &&ob->query("CustomizedAskMode")!=topic)
                message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);
    //有些场景下，玩家向npc问东西，希望体现更自然的描述，而不是xx向xxx打听关于做人的消息。这样 Zine@pkuxkx 2014
        if( !living(ob) ) {
                message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
                        me, ob);
                return 1;
        }
        //在环境变量中查询成功
        msg = ob->query("env/answer_" + topic);
        if( stringp(msg) && strsrch(msg, "$N") != -1)
                if(strsrch(msg, "$n") != -1)
                        message_vision(msg + "\n"NOR, ob, me);
                else
                        message_vision(msg + "\n"NOR, ob);
        if( userp(ob) )
                return 1;

        //在inquiry中查询成功
        if( msg = ob->query("inquiry/" + topic) )
        {
                if(stringp(msg) && objectp(ob))
                        ob->force_me("say " + msg);
                return 1;
        }
    
    
        //查询失败
        if ( ob->query("gender")=="半人半兽" )
        {
                message_vision("$n面无表情地看着别处，应该是听不懂$N的话。\n", me, ob);
                return 1;
        }
        if (topic == "here")
            {
                area_info=AREA_INFO->get_area_info(ob);
                if (!area_info)
                {
                    msg_normal=CYN"$n看了看$N奇道：「这里就是"+environment(ob)->query("short")+CYN"啊，你不会自己看啊？」\n"NOR;
                }
                else
                {
                    msg_normal=CYN"$n道："+area_info+"\n"NOR;
                }
            }
        else if(topic == "name")
                msg_normal=CYN"$n抱拳道：「不敢，" + RANK_D->query_self(ob) + CYN "就是"+ob->query("name")+CYN"。」\n"NOR;
        else if(topic == "rumors")
        {
            if (!me->query_temp("gb_newbie_extra")||!ob->query_temp("gb_newbie_extra")||me->query_temp("gb_newbie_extra")!=ob->query_temp("gb_newbie_extra"))
            {
                msg_normal=CYN"$n不屑一顾的看了$N一眼说道：「输入"+HIR"news"NOR+CYN"命令看去，别烦我！」\n"NOR;
            }
            else
            {
                gb_newbie_ask(me,ob);
                return 1;
            }
        }
        else if(topic == ob->query("name") || ob->id(topic))
                msg_normal=CYN"$n说道：「便是" + RANK_D->query_self(ob) + CYN "。」\n"NOR;
        else if(topic == me->query("name") || me->id(topic))
                msg_normal=CYN"$n说道：「便是" + RANK_D->query_respect(me) + CYN "你了，问这作甚？」\n"NOR;
        else if(topic == "猪头" || topic == "zhutou")
                msg_normal=CYN"$n偷偷的指了指$N的脑袋。\n"NOR;
    else if(topic == "家门不幸" || topic == "mishap")
        {
      msg_normal=relative_bless(me,ob);
    }
        else if(topic == "修理")
        {
          if(FAMILY_D->get_dadizi(me->query("family/family_name")) == me->query("id") && ob->query("family/family_name") == me->query("family/family_name") && ob->query("family/generation") >= me->query("family/generation"))
          {
            if(fix_weapon(me) == 1)
            {
              msg_normal=CYN"$n恭敬的说道，掌门大弟子要修理兵器，吩咐一声就是。您看，已经修好了。请过目。\n"NOR;
            }
            else
            {
              msg_normal=CYN"$n恭敬的说道，掌门大弟子要修理兵器，随时吩咐。不过...您的兵器都很好啊。\n"NOR;
            }
            
          }
          else
          {
            msg_normal=CYN"$n扭过头去，对$N不理不睬。\n"NOR;
          }
        }
        else
        {
                if (check_en(topic)==1)
                        message_vision(msg_dunno1[random(sizeof(msg_dunno1))], me, ob);
                else
                        message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
                return 1;
        }
        message_vision(msg_normal, me, ob);

        return 1;
}

int check_en(string id)
{
        int i;

        i = strwidth(id);

        while(i--)
                if( (id[i]>'a' && id[i]<'z') || (id[i]>'A' && id[i]<'Z') )
                        return 1;

        return 0;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
