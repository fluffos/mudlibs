int checking();
string stop();
string follow();
string leave();
string ask_shi();

string stop()
{
        object ob, me;
        me = this_player();
        ob = this_object();

        if(me->query("id") != ob->query("master")) 
             return RANK_D->query_self_rude(ob)+"没空理你这个"+RANK_D->query_rude(me)+"，还不个我滚开！？";
        if(ob->is_fighting()){
                   command("halt");
                   ob->remove_all_killer();
                   return "遵命。";
                   }
        ob->set_leader(0);
        return RANK_D->query_self(ob)+"遵命，在此等候大人。";
}

string follow()
{
        object ob, me;
        me = this_player();
        ob = this_object();

        if(me->query("id") != ob->query("master")) 
             return me->name()+RANK_D->query_rude(me)+"你是嫌活得不耐烦了？敢来命令大爷我！？";
        command("follow "+me->query("id")); 
             return RANK_D->query_self(ob)+"恭候大人差遣。";
}

void dest(object ob)
{    
  if(ob==this_object())
        tell_room(environment(ob), ob->name()+"转身几个起落就不见了。\n", ({ ob }));	
  destruct(ob);        
}

string leave()
{
        object ob, me;
        me = this_player();
        ob = this_object();

        if(me->query("id") != ob->query("master")) 
             command("say "+me->name()+RANK_D->query_rude(me)+"你是嫌活得不耐烦了？敢来对大爷我指手画脚！");
        command("bow "+me->query("id")); 
        call_out("dest", 3, ob);
        return "遵命，在下这就回报南院大王。";
}

void askshi(object ob)
{
   tell_object(ob, GRN"
侍卫在你的耳边悄声说道：

    你可以让我来杀人(sha)，捉拿(na)人。

    你可以给我武器，护具，食物，饮水来改善我的状态。给我金创药使我疗伤。
    
    问我关于“停”或“stop”：我会在原地等你，如果是在战斗中我会停止战斗。
    问我关于“跟”或“follow”：我会继续紧跟着大人您。
    问我关于“离开”或“leave”：我的任务就算完成，回到南院军营。
\n" NOR);
}

string ask_shi()
{
   object ob, me;
        me = this_player();
        ob = this_object();

        if(me->query("id") != ob->query("master")) 
             return "不想死的给我快滚！"; 
        askshi(me);
        return RANK_D->query_self(ob)+"金牌侍卫恭候"+me->name()+"大人令谕。";
}

void init()
{       
    if(this_player()->query("id") == this_object()->query("master")) {
        add_action ("cmd_kill", "sha");
        add_action ("cmd_hit", "na");
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        command("bow "+ob->query("id")); 
        command("say 下官任南院金牌侍卫，今奉命跟随"+ob->name()+RANK_D->query_respect(ob)+"外出公干，愿一切听从"+RANK_D->query_respect(ob)+"指挥。");
        command("follow "+ob->query("id")); 
        askshi(ob);
        set("mastered", 1);
        ob->set_temp("shiwei", 1);
        set("master", ob->query("id"));
        set("name", ob->name()+"的从侍");
}

int cmd_kill(string str)
{
        object ob, me, obj;
        me = this_player();
        obj = this_object();

        if (!str || str=="") return notify_fail ("你想杀掉谁？\n");

        if (!ob=present(str,environment(me)))
             return notify_fail("杀谁？\n");

        if (userp(ob) && !wizardp(obj))
             return notify_fail("目前还不允许用来PK玩家。\n");

        tell_object(me,GRN"你在"+obj->name()+"的耳边悄声说道：给我杀了这个"+ob->name()+"！\n" NOR);
        tell_room( environment(me), me->name() + "在" + obj->name()
		+ "耳边小声地说了些话。\n", ({ me, obj }) );

        if(ob==obj || ob==me){
               command("? "+me->query("id"));
               return 1;
               }
        if(ob->query("南院")){
               command("ah");
               command("whisper "+me->query("id")+" 大人，那人和我们同属南院。");
               return 1;
               }
        command("nod "+me->query("id"));
        remove_call_out("cmd_fighting");
        call_out("cmd_fighting", 1, obj, ob, me, 2);
        return 1;
}

int cmd_hit(string str)
{
        object ob, me, obj;
        me = this_player();
        obj = this_object();

        if (!str || str=="") return notify_fail ("你想让侍卫们捉拿谁？\n");

        if (!ob=present(str,environment(me)))
             return notify_fail("捉拿谁？\n");

        if (userp(ob))
             return notify_fail("目前还不允许用来对付玩家。\n");

        tell_object(me,GRN"你在"+obj->name()+"的耳边悄声说道：给我把这个"+ob->name()+"教训一顿！\n" NOR);
        tell_room( environment(me), me->name() + "在" + obj->name()
		+ "耳边小声地说了些话。\n", ({ me, obj }) );

        if(ob==obj || ob==me){
               command("? "+me->query("id"));
               return 1;
               }
        if(ob->query("南院")){
               command("ah");
               command("whisper "+me->query("id")+" 大人，那人和我们同属南院。");
               return 1;
               }
        command("nod");
        remove_call_out("cmd_fighting");
        call_out("cmd_fighting", 2, obj, ob, me, 1);
        return 1;
}

void cmd_fighting(object obj, object ob, object me, int i)
{     
        if (!present(ob->query("id"),environment(obj))){
             command("sigh");
             command("whisper "+me->query("id")+" 大人，好象对方已经离开了。");
             return;
             }
        if(i >= 2){
             message_vision("$N指着$n一声大喝：来人啊，将这个贱民给我废了！\n", me, ob);
             command("kill "+ob->query("id"));
             }
        else {
             message_vision("$N对着$n一哼：我看这个贱民极不顺眼，谁来给我教训教训$p？！\n", me, ob);
             command("hit "+ob->query("id"));
             }
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(me->query("id") != ob->query("master") && obj->query("id")!="jin shuaijian") return 0; 

   else if(obj->query("money_id")) {
       command("thank " + me->query("id"));
       return 1;
       }   
   else{ 
       remove_call_out("destroying");
       call_out("destroying", 1, obj, ob, me);                       
       return 1;     
       }
}

void destroying(object obj, object ob, object me)
{   
   object weapon, master, *inv;
   int i;
   weapon = ob->query_temp("weapon");

   if(obj->query("id")=="jin shuaijian"){
        if(obj->query("master")!=me->query("id")){
            command("say 竟敢伪传军令！看招！"); 
            command("kill "+me->query("id"));
            dest(obj);
            return; 
            }
        if(ob->query("master")){
            command("say 请恕在下有特殊任务在身。");
            command("give "+obj->query("id")+" to "+me->query("id")); 
            command("sorry");
            return;
            }  
        if(me->query_temp("shiwei")){
            command("say 对不起，要得到更高级的命令你才能同时带领两个或以上的侍卫。");
            command("give "+obj->query("id")+" to "+me->query("id")); 
            return;
            }
        dest(obj);
        remove_call_out("greeting");
        call_out("greeting", 1, me);
        }

   else if(obj->query("heal_up")){
   	      if ((int)ob->query("eff_qi") >= (int)ob->query("max_qi"))
                      command("drop "+obj->query("id"));
              while((int)ob->query("eff_qi") < (int)ob->query("max_qi") && objectp(obj)){
                      if((int)ob->query("eff_qi") >= (int)ob->query("max_qi")){
                              command("drop "+obj->query("id"));
                              return;
                              }
                      else command("fu "+obj->query("id"));
                      if ((int)ob->query("eff_qi") >= (int)ob->query("max_qi")){
                              command("drop "+obj->query("id"));
                              return;
                              }
                      }
              }

   else if(obj->query("armor_type")){
              inv = all_inventory(ob);
	      for(i=0; i<sizeof(inv); i++){
                      if(inv[i]==obj ) continue;
                      if(inv[i]->query("armor_type") == obj->query("armor_type")){
                            command("remove "+inv[i]->query("id"));                 
                            command("drop "+inv[i]->query("id"));
                            }
                      }
              command("wear "+obj->query("id"));
              }

   else if(obj->query("weapon_prop")){
              if(objectp(weapon)){ 
                      command("unwield "+weapon->query("id"));
                      command("drop "+weapon->query("id"));
                      ob->reset_action();
                      }
              command("wield "+obj->query("id"));
              }
   else if(obj->query("food_supply")){
              if((int)ob->query("food") >= (int)ob->max_food_capacity())
                      command("drop "+obj->query("id"));
              while(((int)ob->query("food") < (int)ob->max_food_capacity()) && objectp(obj)){                      
                      if((int)ob->query("food") >= (int)ob->max_food_capacity()){
                              command("drop "+obj->query("id"));
                              return;
                              }
                      else command("eat "+obj->query("id"));
                      if((int)ob->query("food") >= (int)ob->max_food_capacity()){
                              command("drop "+obj->query("id"));
                              return;
                              }
                      }
              }
   else if(obj->query("liquid")){
              if((int)ob->query("water") >= (int)ob->max_water_capacity())
                      command("drop "+obj->query("id"));
              while(((int)ob->query("water") < (int)ob->max_water_capacity())){
                      if(!obj->query("liquid/remaining")){
                              command("drop "+obj->query("id"));
                              return;
                              }    
                      else command("drink "+obj->query("id"));
                      if((int)ob->query("water") >= (int)ob->max_water_capacity()){  
                              command("drop "+obj->query("id"));
                              return;
                              }                   
                      }
              }
   else command("drop "+obj->query("id"));      
   return;
}

