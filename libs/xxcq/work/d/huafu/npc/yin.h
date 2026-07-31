int ask_kungfu()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
           skills=me->query_skill("poshan-dao",1);

           if ( (!myfam || myfam["family_name"]!="发梦二党") && (!myparty || myparty["party_name"]!=HIG"发梦二党"NOR) )
           {
                   command("say 你与本门毫无瓜葛，此话从何谈起？");
                   return 1;
           }

           if ( me->query_temp("kungfu_asked") )
           {
                command("hmm");
                command("say 这套绝学我只教一遍，学成与否就看你自己的造化了。");
                return 1;
           }

            if (myfam && myfam["family_name"]=="发梦二党")
{
           if ( me->query("combat_exp")<80000)
           {
                command("say 你的实战经验太低，学不了我的绝学。");
                return 1;
           }
            if ( me->query_skill("blade",1)<80)
           {
                command("say 你的刀法还欠火候，学不了我的绝学。");
                return 1;
           }
           if ( me->query("max_neili")<200)
           {
                command("say 你的内力基础太差，学不了我的绝学。");
                return 1;
           }

             if (skills>=this_object()->query_skill("poshan-dao",1))
             {
                       command("say 我已经没什么可教的啦。");
                       return 1;
             }
                if ((skills*skills*skills/7)>me->query("combat_exp"))
             {
                       command("say 你的经验不够，说了你也听不懂。");
                       return 1;
             }
            if (me->query("jingli")<20)
             {
                       command("say 你太累了，休息会吧。");
                       return 1;
             }
                 
            me->improve_skill("poshan-dao",random(10*me->query("int")));
            tell_object(me,"你向银盛雪请教了一些关于破山刀法的疑问。\n");
            me->receive_damage("jingli",25-(me->query("int")/5));
            
            return 1;

           }
           
            if (myparty && myparty["party_name"]==HIG"发梦二党"NOR)
           {
                  if ( myparty["level"]<4 )
                  {
                       command("say 这套绝学我不能教你，对不起。");
                       return 1;
                  }
            if ( me->query_skill("blade",1)<80)
                  {
                       command("say 你的刀法还欠火候，学不了我的绝学。");
                       return 1;
                  }
                  if ( me->query("max_neili")<200 )
                  {
                       command("say 你的内力还欠火候，学不了我的绝学。");
                       return 1;
                  }
          command("say 好吧，你看仔细了，我只演练一遍。");
           message_vision("$N摆开架势，在原地耍弄起他的绝学来。\n",this_object());
             me->improve_skill("poshan-dao",20);
           if ( me->query("int")<18 )
           {
                 message_vision("$N看了半天，毫无所得，想必你的资质太差了，掌握不了精髓。\n",me);
                     return 1;
           }
                 message_vision("$N看了半天,掌握了这套绝学的精髓。\n",me);
                      me->set_temp("kungfu_asked",1);
                     return 1;
           }

           return 0;
}

int ask_kungfu1()
{
           object me;
           mapping myparty;
           mapping myfam;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");

           if ( (!myfam || myfam["family_name"]!="发梦二党") && (!myparty || myparty["party_name"]!=HIG"发梦二党"NOR) )
           {
                   command("say 你与本门毫无瓜葛，此话从何谈起？");
                   return 1;
           }
           
           command("smile");
           command("say 我比较精通刀法，你可以向我请教刀法的疑问。");
           
           return 1;
           
}

int ask_kungfu2()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
           skills=(int)me->query_skill("blade",1);

           if ( (!myfam || myfam["family_name"]!="发梦二党") && (!myparty || myparty["party_name"]!=HIG"发梦二党"NOR) )
           {
                   command("say 你与本门毫无瓜葛，此话从何谈起？");
                   return 1;
           }
           
             if (skills>=this_object()->query_skill("blade",1))
             {
                       command("say 我已经没什么可教的啦。");
                       return 1;
             }

                if ((skills*skills*skills/7)>me->query("combat_exp"))
            {
                      command("say 你的经验不够，说了你也听不懂。");
                      return 1;
            }
           if (me->query("jingli")<20)
            {
                      command("say 你太累了，休息会吧。");
                      return 1;
            }
                
           me->improve_skill("blade",random(10*me->query("int")));
           tell_object(me,"你向银盛雪请教了一些关于刀法的疑问。\n");
          me->receive_damage("jingli",25-(me->query("int")/5));
           
           return 1;
           
}


