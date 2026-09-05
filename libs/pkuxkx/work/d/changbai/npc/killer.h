//fix by yhzzyahoo
void delete_init_num(object me)
{
        me->delete("init_num");
        return;
}

void init()
{
        object stage,env,where;
        object me=this_player();
        string exit_place;
        if (this_object()->query("uni_target")==me)
        {
            switch (random(10-this_object()->query("hyd/step")))
                {
                    case 0:
                        break;
                    case 1:
                        message_vision("$N看见$n，阴笑一声：天堂有路你不走，地狱无门你来投！\n",this_object(), me);
                        kill_ob(me);
                        break;
                    default:
                        break;
                }
        }        
}

void do_leave()
{
        if(!this_object())
                return;
        message_vision("$N看了看天色，自言自语道：“天色不早了，得去干活了。”\n", this_object());
        destruct(this_object());
}

int ask_fight()
{
        if (this_object()->query("uni_target")==this_player()) {
        	if (environment(this_object())->query("no_fight")) 
        	{
        		command("say 此处比武多有不便，你且随我来！");
        		random_move();
        	}
        	else command("say 要打便打，不必多言！");
        } else command("say 就你也配跟我讨教功夫？！");
        return 1;
}

int ask_rumors()
{
        if (this_object()->query("uni_target")==this_player())
                command("say 听说有个叫"+this_player()->query("name")+"的会来找我麻烦，就是你么？");
        else
                command("say 听说闯王宝藏里面有不少好东西，嘿嘿～～嘿嘿～～");
        return 1;
}

int generate(object where)
{
    where = MAP_D->random_place();
    return 1;
}

void die()
{
        object map,killer,where;
        object me = query("uni_target"); 
      // object who = this_player();      
        object mykiller;//盗宝人的killer
        int newkiller,i,num;
        object thisroom;
        if(!me || me->query_temp("yidao/target_ob")!=this_object())
        {
                ::die();
                return;
        } 
        if( !objectp(mykiller = get_damage_origin_object()) || mykiller->query("id")!= me->query("id"))
        {
        	     message_vision(HIC"$N说道：“你...”，话没说完，两眼翻白，腿儿蹬了几下，脑袋一歪，死了。\n",this_object());
               ::die();
               return;
        }
        map=new("/d/changbai/npc/obj/map"+this_object()->query("hyd/step")+".lpc");
        num = ((int)this_object()->query("hyd/step"));
        me->set("yidao/done",num);
        me->add("yidao/hard", query_temp("advanced_quest") );

        thisroom=environment(me);
        if (me->query("yidao/done")==1 && thisroom)  //加入地图查询功能，鼓励手动。Zine Nov 13 2010
        {
            me->set_temp("huyidaomap1",thisroom->query("short"));
        }
        if (me->query("yidao/done")==2 && thisroom)
        {
            me->set_temp("huyidaomap2",thisroom->query("short"));
        }
        if (me->query("yidao/done")==3 && thisroom)
        {
            me->set_temp("huyidaomap3",thisroom->query("short"));
        }
        if (me->query("yidao/done")==4 && thisroom)
        {
            me->set_temp("huyidaomap4",thisroom->query("short"));
        }
        if (me->query("yidao/done")==5 && thisroom)
        {
            me->set_temp("huyidaomap5",thisroom->query("short"));
        }
        map->set("owner",me->query("id"));
        if(!map->move(me))
		{
			map->move(environment(this_object()));
		}
        if (random(2)) GEM_D->drop(this_object(),me);
        if (this_object()->query("hyd/step") != 5)
        {
        		newkiller = this_object()->query("hyd/step") + 1;
		        killer=new(__DIR__"killer"+newkiller);
		        killer->do_copy(me);
//过滤非法任务地点和不明区域 by segate@pkuxkx
            me->set_temp("map/keepsameregion",1);
            where = MAP_D->random_place_ex(me);
            if (this_object()->query("dbr_place"))
            {
                  where=load_object(this_object()->query("dbr_place"));
            }
            
            while (!objectp(where) || 
                   !where->isroom()||
                   MAP_D->place_belong(where)=="不明区域"||
                   base_name(where) == "/adm/daemons/taskd")
            {
              me->set_temp("map/keepsameregion",1);
              where = MAP_D->random_place_ex(me);
            }
                   
            me->set_temp("yidao/where",MAP_D->place_belong(where));
		        me->set_temp("yidao/killer",killer->query("name"));
		        me->set_temp("yidao/target_ob",killer); //加一个判断
            message_vision("$N说道：“你有种去"+MAP_D->place_belong(where)
                        +"找我兄弟"+killer->query("name")+"("+killer->query("id")
                        +")，他会给我报仇的！”\n",this_object());
            if (thisroom->query("least_msg"))
            {
              whisper_to_me(me,killer);
            }
		            
            killer->move(where);
	          for (i=0;i<3;i++) 
		        	killer->random_move();
		    }
		    else   
		 	    message_vision("$N长叹道：“人算不如天算，想不到我兄弟五人都栽在你的手中！”\n",this_object());

        //::die();
		destruct(this_object());
}

void unconcious()
{        
        object ob = this_object();
        if( ob->query("qi")>=100 )
          return;
        call_out("die",1);
}

int do_copy(object me)  
{                       
        int exp;
        int skill, str, rw_lv;
        int index;
        int factor, jl_fact, qx_fact, nl_fact;
        int tf_mi, tf_ma;
        if(!objectp(me)) return 0;
        exp=me->query("combat_exp");
        index=me->query("yidao/times")/250;
		if ( me->query("yidao/times") < 500)
		{
          jl_fact=10;
          qx_fact=80;
          nl_fact=40;
          tf_mi=10;
          tf_ma=30;
		}
        else if ( me->query("yidao/times") < 1000 )
        {
          jl_fact=20;
          qx_fact=100;
          nl_fact=50;
          tf_mi=10;
          tf_ma=30;
        }
        else if ( me->query("yidao/times") < 5000 )
        {
          jl_fact=50;
          qx_fact=200;
          nl_fact=100;
          tf_mi=15;
          tf_ma=35;
        }
        else if ( me->query("yidao/times")/25 <= 500 )
        {
          jl_fact=67;
          qx_fact=me->query("yidao/times")/25;
          nl_fact=me->query("yidao/times")/50;
          tf_mi=20;
          tf_ma=40;
        }
        else 
        {
          jl_fact=100;
          qx_fact=500;
          nl_fact=250;
          tf_mi=25;
          tf_ma=45;
        }
        
        //family_skill会set npc的chat_chance_combat为100，这个变态！
        //必须把family_skill放在最前面！ 
        factor=(5+this_object()->query("hyd/step")+random(index));
       	if ( factor>20 )
        	  factor=20+(factor-20)/3;
      	if (factor > 30) factor = 30;

        if (this_object()->query("hyd/step") != 5)
        {	
				es_copy1( me, "shenlongjiao", factor*10, 100, jl_fact);
		        set("chat_chance_combat", 20+this_object()->query("hyd/step")*5);
		    }
        else
        {		if(factor<12)
			        es_copy1( me, "shenlongjiao", 115, 100, jl_fact);
				else
					es_copy1( me, "shenlongjiao", factor*10, 100, jl_fact);
        		set("chat_chance_combat", 50);
        }
		rw_lv=me->query("level");
        set("level",me->query("level")+random(20));

        if ( query_temp("advanced_quest") )
		{
			set("name", HIR+query("name")+NOR);
			if(random(2)==0)set("per",rw_lv*2);

		}
		else
		{
			if(random(4)==0)set("per",rw_lv+random(rw_lv));
		}
        
        str=me->query_str();
        if ( str > 200 )
        	str=200;
        
        if ( str <= 50 )
          nl_fact=nl_fact*2;
        
        qx_copy2( str, qx_fact, nl_fact);
        tf_set( tf_mi, tf_ma );
        
        set("qi", me->query("max_qi") * 2);
        set("jing", me->query("max_jing") * 2);
        set("uni_target", me);
        set("killer",me->query("id"));
        wield_weapon();
}