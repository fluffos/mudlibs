// littlefish
// last updated 3/16/96

void wakeup(object,object);

int main(object me, string arg)
{
        mapping fam;
        object room,*inv;
        int i;
        object where = environment(me);
        
        seteuid(getuid());

        if ((me->query("neili")<0)||(me->query("jingli")<0))
               return notify_fail("你精血不足，翻来覆去无法入眠! \n");
        if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("这里不是你能睡的地方！\n");
   
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能睡觉！\n");
        
        if (where->query("hotel") && !(me->query_temp("rent_paid")))
        {
                message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n",me);
                return 1;
        }
 
        if(me->query_condition("sleep")!=0)
                return notify_fail("你刚在三分钟内睡过一觉, 多睡对身体有害无益! \n");

        if (where->query("sleep_room"))
        {
                write("你往床上一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                message("vision", me->name() + "一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n", environment(me), me);
        }
        else { 
                write("你往地下角落一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                message("vision", me->name() + "往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n", environment(me), me);
        }

        where->add("no_fight", 1);
        where->add_temp("sleeping_person", 1);

        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        
        me->apply_condition("sleep", 4);
        if( where->query("hotel") )
                me->delete_temp("rent_paid");

//Modi by win      
        room=new("/adm/single/temproom");
        inv=all_inventory(me);
        for(i=0;i<sizeof(inv);i++)
        {
                 inv[i]->set_temp("no_monitor",1);
                if(stringp(inv[i]->query("equipped"))) inv[i]->set("tmp_equip",inv[i]->query("equipped"));
                inv[i]->move(room);
        }
        me->set_temp("block_msg/all", 1);
          me->move("/clone/misc/tmp_void",1);

        me->disable_player("<睡梦中>");
        me->move(where); //add by win,防止环境内的add_action导致crash
        inv=all_inventory(room);
        for(i=0;i<sizeof(inv);i++)
        {
                inv[i]->move(me);      
                inv[i]->delete_temp("no_monitor");
           
                if (stringp(inv[i]->query("tmp_equip"))) { 
                        if(inv[i]->query("tmp_equip")=="wielded") {
                                inv[i]->wield();
                                inv[i]->delete("tmp_equip");
                        }
                        else {
                                inv[i]->wear();
                                inv[i]->delete("tmp_equip");
                        } 
                }           
        }
        me->delete_temp("block_msg/all");

        call_out("wakeup", random(45 - me->query("con")), me, where);
        
        return 1;
        
}

void wakeup(object me,object where)
{
        object room,obj,*inv;
        int i;
        me->set("qi", me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );

        me->enable_player();         
        me->set_temp("block_msg/all", 1);
          me->move(environment(me),1);
        me->delete_temp("block_msg/all");
             
        room=new("/adm/single/temproom");
        inv=all_inventory(me);
        
        for(i=0;i<sizeof(inv);i++)
        {
                 inv[i]->set_temp("no_monitor",1);
                if(stringp(inv[i]->query("equipped"))) inv[i]->set("tmp_equip",inv[i]->query("equipped"));
                inv[i]->move(room);
        }        
        inv=all_inventory(room);
        for(i=sizeof(inv)-1;i>=0;i--)
        {
                inv[i]->move(me);      
                inv[i]->delete_temp("no_monitor");
           
                if (stringp(inv[i]->query("tmp_equip"))) { 
                        if(inv[i]->query("tmp_equip")=="wielded") {
                                inv[i]->wield();
                                inv[i]->delete("tmp_equip");
                        }
                        else {
                                inv[i]->wear();
                                inv[i]->delete("tmp_equip");
                        } 
                }           
        }        
//

        me->delete("disable_type");
        message_vision("$N一觉醒来，精神抖擞地活动了几下手脚。\n", me);
        me->write_prompt();
  
        if (!where->query("sleep_room") && !where->query("hotel"))
                where->add("no_fight",-1);
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
}
