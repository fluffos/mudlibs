void delete_init_num(object me)
{
        me->delete("init_num");
        return;
}

void init()
{
/************
				//以下有关random_move的修改为防止出现类似init(random_move(init(random_move(....类型的递归调用
				//1秒钟内最多出发2次init
				if (!this_object()->query("init_num"))
  		    	call_out("delete_init_num",1,this_object());
				this_object()->add("init_num",1);
        if (environment(this_object())->query("no_fight") && (this_object()->query("init_num") < 2))
        	::random_move();
*************/        	
        if (this_object()->query("uni_target")==this_player()){
        switch (random(11-this_object()->query("hyd/step"))){
                case 0:
/**********
                				if (this_object()->query("init_num") < 2)
                				{
	                        message_vision("$N看见$n，心里打着小鼓，一声不吭的就溜走了！\n",this_object(), this_player());
  	                      ::random_move();
  	                    }
***********/  	                    
                        break;
                case 1:
                  message_vision("$N看见$n，阴笑一声：天堂有路你不走，地狱无门你来投！\n",this_object(), this_player());
                  kill_ob(this_player());
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
varargs void wield_weapon(string weapon)
{
        if(!weapon && query("use_weapon1"))
                wield_weapon(query("use_weapon1"));
        if(!weapon && query("use_weapon2"))
                wield_weapon(query("use_weapon2"));
        if(!weapon)
                return;
        switch(weapon)
        {
        case "sword":
                carry_object("/clone/weapon/changjian")->wield();
                break;
        case "blade":
                carry_object("/clone/weapon/gangdao")->wield();
                break;
        case "staff":
                carry_object("/clone/weapon/gangzhang")->wield();
                break;
        case "whip":
                carry_object("/clone/weapon/changbian")->wield();
                break;
        case "zhen":
                set("gender", "无性");
                carry_object("/d/city/obj/flower_shoe")->wear();
                carry_object("/d/city/obj/pink_cloth")->wear();
                carry_object("/d/city/obj/goldring")->wear();
                carry_object("/d/city/obj/necklace")->wear();
                carry_object("/d/quanzhou/obj/xiuhua")->wield();
                carry_object("/d/riyuejiao/obj/xiuhuajia");
                break;
        case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
                break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
        case "hammer":
                carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
                break;
        default:
        }
        return;
}

void die()
{
        object map,killer,where;
        object me = query("uni_target"); 
      // object who = this_player();      
        object mykiller;//盗宝人的killer
        int newkiller,i,num;
        
        if(!me || me->query_temp("yidao/target_ob")!=this_object())
        {
                ::die();
                return;
        } 
        if( !objectp(mykiller = query_temp("last_damage_from")) || mykiller->query("id")!= me->query("id"))
        {
        	     message_vision(HIC"$N说道：“你...”，话没说完，两眼翻白，腿儿蹬了几下，脑袋一歪，死了。\n",this_object());
               ::die();
               return;
        }
        map=new("/d/changbai/npc/obj/map"+this_object()->query("hyd/step")+".lpc");
        num = ((int)this_object()->query("hyd/step"));
        me->set("yidao/done",num);
        map->set("owner",me->query("id"));
        map->move(this_object());
        if (random(2)) GEM_D->drop(this_object(),me);
        if (this_object()->query("hyd/step") != 5)
        {
        		newkiller = this_object()->query("hyd/step") + 1;
		        killer=new(__DIR__"killer"+newkiller);
		        killer->do_copy(me);
		        where = TASK_D->random_place();
		        me->set_temp("yidao/where",TASK_D->place_belong(where));
		        me->set_temp("yidao/killer",killer->query("name"));
		        me->set_temp("yidao/target_ob",killer); //加一个判断        
		        message_vision("$N说道：“你有种去"+TASK_D->place_belong(where)
		        +"找我兄弟"+killer->query("name")+"("+killer->query("id")
		        +")，他会给我报仇的！”\n",this_object());
		        killer->move(where);
		        for (i=0;i<3;i++) 
		        	if (killer)  killer->random_move();
		    }
		 		else   message_vision("$N长叹道：“人算不如天算，想不到我兄弟五人都栽在你的手中！”\n",this_object());		 		
        
        ::die();
}

void unconcious()
{        
        object ob = this_object();
        if(ob->query("qi")>=100 && random(2)==1)
                return;
        call_out("die",1);
}

int do_copy(object me)  
{                       
        int exp;
        int skill;
        int index;
        int factor;
        if(!objectp(me)) return 0;
        exp=me->query("combat_exp");
        index=me->query("yidao/times")/250;
        //family_skill会set npc的chat_chance_combat为100，这个变态！
        //必须把family_skill放在最前面！ 
        if (this_object()->query("hyd/step") != 5)
        {
        		factor=(5+this_object()->query("hyd/step")+random(index));
        		if (factor > 20) factor = 20; //2倍封顶，否则太高，到3倍多，会溢出。
                     if (2140000000/factor < me->query("combat_exp")/10)
                     	exp=2140000000;
                     else
                     	exp = me->query("combat_exp")/10 * factor;
		        skill=pow(exp/100.0,1.0/3)*10;
		        family_skill(this_object(), "shenlongjiao", skill, 1);
		        set("chat_chance_combat", 10+this_object()->query("hyd/step")*5);
		    }
        else
        {
        		exp=exp/5*4;
		        skill=pow(exp/100.0,1.0/3)*10;
		        family_skill(this_object(), "shenlongjiao", skill, 1);
        		set("chat_chance_combat", 40);
        }
        set("combat_exp",exp);    
        set("level",me->query("level")+random(5));
        set("max_qi", me->query("max_qi") * 2);
        set("eff_qi", me->query("max_qi") * 2);
        set("qi", me->query("max_qi") * 2);
        set("max_jing", me->query("max_jing") * 2);
        set("eff_jing", me->query("max_jing") * 2);
        set("jing", me->query("max_jing") * 2);
        set("max_neili", me->query("max_neili") * 3/2);
        set("neili", me->query("max_neili") * 3/2);
        set("max_jingli", me->query("max_jingli") * 3/2);
        set("jingli", me->query("max_jingli") * 3/2);
        set("jiali",skill);
        set("uni_target", me);
        set("killer",me->query("id"));
        wield_weapon();
}
