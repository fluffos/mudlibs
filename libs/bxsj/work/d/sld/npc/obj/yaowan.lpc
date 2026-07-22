#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void back_rq(object);
void eat_yao(object ob);

void init()
{
	add_action("do_eat", "eat");
        add_action("do_kan", "kan");
        add_action("do_mo", "mo");
        add_action("do_rong", "rong");
        add_action("do_drink", "drink");
        add_action("do_throw", "throw");
}

void create()
{
        set_name(HIG "丹药" NOR, ({"danyao","yao","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "这是一颗神龙教独家特制的丹药。\n");
                set("unit", "颗");
                set("t_unit","颗");
                set("no_sell",1);
        }
}

int do_kan(string arg)
{
        object me=this_player();
        object yao=this_object();
        string* type=({"火","土","金","水","木"});
        string* use=({"补内力","补食水","补精","补气","补精力"});//药的作用
        int i,j,max,types;
        string msg;

        if((me->query_skill("poison",1)<120) || (me->query_skill("shenlong-yaoli",1)<120))
                return 0; 
        if(yao->query("poison")=="全")
        {
                msg=sprintf("这是一%s解毒灵药，可解%d次毒。\n",yao->query("t_unit"),yao->query("zycs"));
                tell_object(me,msg);
        }
        else
        {
                types=yao->query("types");
                for(i=0;i<sizeof(type);i++) 
                {
                        if(yao->query("poison")==type[i])
                        {
                                if(types==1)
                                {
	msg=sprintf("这是一%s毒药，有五行%s毒，可毒发%d次。\n",yao->query("t_unit"),type[i],yao->query("zycs"));
                                }
                                else
                                {
	                                msg=sprintf("这是一%s毒药，有五行%s毒，可毒发%d次，此外还掺杂有一些\n",yao->query("t_unit"),type[i],yao->query("zycs"));
                                        for(j=0;j<sizeof(type);j++)
                                        {
                                                if(j==i)
                                                        continue;
                                                else if(yao->query(type[j])==0)
                                                        continue;
                                                else
                                                {
                                                        msg=sprintf("%s%s(+%d)",msg,use[j],yao->query(type[j]));
                                                }
                                        }
                                        msg+="的药物。\n";
                                }
                                tell_object(me,msg);
                                break;
                        }
                }
                if(i>=sizeof(type))
                {
                        if(types>0)
{
                                max=0;j=0;
                                msg="这是一"+yao->query("t_unit")+"补药，含有";
                                for(i=0;i<sizeof(type);i++) 
                                {
                                        if(yao->query(type[i])==0)
                                                continue;
                                        msg=sprintf("%s%s(+%d)",msg,use[i],yao->query(type[i]));
                                        if(yao->query(type[i])>max)
                                        {
                                                max=yao->query(type[i]);
                                                j=i;
                                        }
                                }
                                msg=msg+"等药物，其中以"+use[j]+"的药物为主。\n";
                                tell_object(me,msg);
                        }
                        else
                        {
                                tell_object(me,"这是一"+yao->query("t_unit")+"骗人用的假药。\n");
                        }       
                }
        }
        tell_object(me,"你可以对其看(kan)、磨(mo)、抛洒(throw XXX)。\n");
        return 1;
}

int do_mo(string arg)
{
        object yao=this_object();
        object me=this_player();

        if(yao->query("t_unit")=="颗")
        {
                yao->set("t_unit","包");
                yao->set("nums",100);
                tell_object(me,"你把"+yao->name(1)+"磨成了粉末。\n");
        }
        else
                tell_object(me,yao->name(1)+"已经不能磨了。\n");
        return 1;
}

int do_drink(string arg)
{
        int jl;
        if( !this_object()->id(arg) || !living(this_player())) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
/*
        if( this_object()->query("t_unit")!="杯")
                return 0;
*/
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
        if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
        jl=((this_player()->query("pur",)*random(20))+(random(this_player()->query("per",)*10)));
        //add("liquid/remaining", -1);
        message_vision("$N拿起" + name() + "咕噜噜地喝了几口" + query("liquid/name")
+ "。\n", this_player());
//        this_player()->add("combat_exp",jl);
        this_player()->add("water", 5*query("liquid/remaining"));
        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        if( !query("liquid/remaining") )
                write("你已经将" + name() + "里的" + query("liquid/name")
                        + "喝得一滴也不剩了。\n");
        eat_yao(this_player());
        if(this_object()->query("nums")<=0)
        {
                set("liquid/type", "water");
                set("liquid/name", "清水");
                set("liquid/remaining", 0);
                // This allows customization of drinking effect.
                if( query("liquid/drink_func") )
                {
                        call_out("back_rq", 1, this_player());
                        return 1;
                }
                switch(query("liquid/type")) {
                        case "alcohol":
                                this_player()->apply_condition("drunk",
                                (int)this_player()->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                                break;
                }

                call_out("back_rq", 1, this_player());
        }       
        return 1;
}

int do_fill(string arg)
{
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( this_object()->query("t_unit")!="杯")
                return 0;
        if( !environment(this_player())->query("resource/water") )
                return notify_fail("这里没有地方可以装水。\n");

        if( query("liquid/remaining") )
                message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", this_player());
        message_vision("$N将" + name() + "装满清水。\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        
        set("liquid/type", "water");
        set("liquid/name", "清水");
        set("liquid/remaining", query("max_liquid"));
        set("liquid/drink_func", 0);
        call_out("back_rq", 1, this_player());
        return 1;
}

void back_rq(object ob)
{
        object rq;

	if(!objectp(rq=new(query("old")))) tell_object(this_player(),name()+"被毁坏了。\n");
        else {
                rq->set("liquid", query("liquid"));
                rq->move(ob);        
        }
        destruct(this_object());
}

int do_rong(string arg)
{
        object rq;
        object me=this_player();
        object ob=this_object();

        if(!objectp(rq=present(arg, me))&&!objectp(rq=present(arg, environment(me))))
                return notify_fail("你要把"+ob->query("name")+"溶于何处？\n");
        if(rq->query("liquid")==0)
                return notify_fail(arg+"好象不能溶化东西的。\n");
        if( !rq->query("liquid/remaining") )
                return notify_fail( rq->name()+"现在是空的，不能溶化任何东西。\n");
        if(rq->query("t_unit")!=0)
                return notify_fail( rq->name()+"里已经溶有药物了。\n");
        if(ob->query("t_unit")!="杯")
        {
                ob->set("t_unit","杯");
tell_object(me,"你把"+ob->name()+"放入"+rq->name()+"中，搅了搅，不一会，就溶化于其中了。\n");
        }
        else
                return notify_fail( ob->name()+"里已经溶有药物了。\n");
        ob->set_name(rq->query("name"),rq->parse_command_id_list());
        ob->set_weight(rq->query_weight());
        ob->set("long", rq->query("long"));
        ob->set("unit", rq->query("unit"));
        ob->set("value", rq->query("unit"));
        ob->set("max_liquid", rq->query("max_liquid"));
        ob->set("liquid", rq->query("liquid"));
        ob->set("liquid/remaining",rq->query("liquid/remaining"));
        ob->set("old",base_name(rq));
        destruct(rq);
        return 1;
}

int do_eat(string arg)
{
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if( this_object()->query("t_unit")=="杯")
                return 0;
        message_vision("$N把"+name()+"一口吞了下去。\n",this_player()); 
        eat_yao(this_player());
        if(this_object()->query("nums")<=0)
        {
                destruct(this_object());
}
        return 1;
}

int do_throw(string arg)
{
        object target,room;
        object me=this_player();
        int yq;

        if( !this_object()->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        if(( this_object()->query("t_unit")!="包") || ( !this_object()->query("poison")) 
          || (this_object()->query("poison")=="全"))
                return notify_fail("你只能抛洒毒粉。\n");
        if(!objectp(target=present(arg, environment(me))) || !living(target) || target->is_ghost())
                return notify_fail("你要向谁抛洒毒粉？\n");
        if(objectp(room=environment(me)))
        {
                if(room->query("no_fight")==1)
                        return notify_fail("你不能在这里抛洒毒粉。\n");
        }
        message_vision("$N把"+name()+"向$n抛洒过去。\n",me,target);
        if((yq=random(me->query("combat_exp")*100/target->query("combat_exp"))+random(me->query_dex()*100/target->query_dex())
          +random(me->query_kar()*100/target->query_kar()))>=300)
        {
message_vision("$n躲闪不及，被抛洒过来的"+name()+"击得满身都是！\n",me,target);
                eat_yao(target);        
        }
        else if((yq<=100) && (target->query_skill("force")>=300) && (target->query("neili")>=350))
        {
                message_vision("$n不慌不忙，运内力向抛来的毒粉猛地一击，结果$N躲闪不及，被反击回来的"+name()+"击得满身都是！\n",me,target);
                eat_yao(me);
                target->add("neili",-300);      
        }
        else
                message_vision("$n一闪身，抛洒过来的"+name()+"擦身而过！\n",me,target); 
        me->start_busy(random(2)+1);
        if(!target->if_fighting(me))
        {
                target->fight_ob(me);
                me->fight_ob(target);
        }
        if(this_object()->query("nums")<=0)
                destruct(this_object());
        return 1;
}

void eat_yao(object ob)
{
        //object du;
        //mixed* files;
        //string dir,fn;
int i,cs,zycs,num,num2,faint;
        string dutype1; 
        string * dus=({"bee_poison","bing_poison","bt_poison","chanchu_poison","cold_poison","dsy_poison","fs_poison",
                       "hb_poison","hot_poison","huagu_poison","juehu_hurt","man_poison","qianzhu_poison","qinghua_poison",
                       "qishang_poison","qtlh_poi","sanxiao","scorpion_poison","sl_poison","slumber_drug","snake_poison",
                       "wh_poison","xx_poison","yysan_poison"});
        string * dun=({"玉蜂毒","冰魄银针毒","白驼怪蛇毒","蟾蜍剧毒","寒毒","大手印毒","腐尸毒","寒冰绵掌毒","热毒",
                       "化骨绵掌毒","绝户剧毒","蔓陀萝花毒","千蛛万毒手毒","情花毒","七伤拳毒","青陀罗花毒","三笑销魂毒",
                       "蝎毒","五彩神龙毒","蒙汗药力","蛇毒","神龙五行毒","星宿掌毒","催情药力"});
        string * dutype=({"金","木","土","水","火","金","木","土","水","火"});

        if(query("poison")=="全")
        {
                if(this_object()->query("nums")>0)
                {
                        zycs=query("zycs")/5;
                        this_object()->add("nums",-20);
                }
                else
zycs=query("zycs");
                for(i=0;i<sizeof(dus);i++)
                {
                        if((cs=ob->query_condition(dus[i],1))>0)
                        {
                                if(zycs>cs)
                                {
                                        ob->apply_condition(dus[i],0);
                                        zycs=zycs-cs;
                                        tell_object(ob,"你的"+dun[i]+"被化解了。\n");
                                }
                                else
                                {
                                        cs=cs-zycs;
                                        ob->apply_condition(dus[i],cs);
                                        tell_object(ob,"你的"+dun[i]+"被化解了一部分。\n");
                                        break;
                                }
                        }
                }
                if((zycs>=150) && (ob->query_skill("shenlong-yaoli",1)<150))
                {
                        i=random(sizeof(dus));
                        ob->apply_condition(dus[i],ob->query_condition(dus[i],1)+zycs);
                        tell_object(ob,"由于"+name()+"的毒性作用过强，你中了"+dun[i]+"！\n");
                }
                else if((zycs>=50) && (ob->query_skill("shenlong-yaoli",1)<200) && (ob->query_skill("poison",1)<200))
                {
                        tell_object(ob,"由于"+name()+"的毒性作用过强，你身受重创！\n");
ob->receive_damage("qi", zycs*2);
                        ob->receive_wound("qi", zycs);
                }
                return;
        }
        if(query("poison")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        zycs=query("zycs")/5;
                        this_object()->add("nums",-20);
                }
                else
                        zycs=query("zycs");
                cs=ob->query_condition("wh_poison",1);
                dutype1=ob->query("poisontype");
                if(!dutype1 || (dutype1==query("poison")) || (cs==0))
                {
                        ob->apply_condition("wh_poison",cs+zycs);
                        ob->set("poisontype",query("poison"));
                        tell_object(ob,"你身中神龙五行"+query("poison")+"毒！\n");
                }
                else
                {
                        for(i=0;i<sizeof(dutype);i++)
                        {
                                if(dutype[i]==query("poison"))
                                        break;
                        }
                        if((dutype1==dutype[i+1]) || (dutype1==dutype[i+4]))
{
                                if(zycs>cs)
                                {
                                        zycs=zycs-cs;
                                        ob->apply_condition("wh_poison",zycs);
                                        ob->set("poisontype",query("poison"));
                                        tell_object(ob,"你身中神龙五行"+query("poison")+"毒！\n");
                                }
                                else if(cs>zycs)
                                {
                                        cs=cs-zycs;
                                        ob->apply_condition("wh_poison",cs);
                                        tell_object(ob,"由于毒毒相克，你身中的神龙五行"+dutype1+"毒被化解了部分！\n");
                                }
                                else 
                                {
                                        ob->apply_condition("wh_poison",0);
                                        ob->delete("poisontype");
                                        tell_object(ob,"由于毒毒相克，你身中的神龙五行"+dutype1+"毒被化解了！\n");
                                }
                        }
                        else if(dutype1==dutype[i+2])
                        {
                                ob->apply_condition("wh_poison",zycs+cs*2);
                                ob->set("poisontype",query("poison"));
                                tell_object(ob,"你身中神龙五行"+query("poison")+"毒！\n");
                        }
else if(dutype1==dutype[i+3])
                        {
                                ob->apply_condition("wh_poison",cs+zycs*2);
                                tell_object(ob,"由于毒毒相生，你身中的神龙五行"+dutype1+"毒加重了！\n");
                        }
                }
        }
        faint=0;
        if(query("金")!=0)
        {
                if(ob->query_temp("maxjing",1)==0)
                        ob->set_temp("maxjing",ob->query("max_jing"));
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("eff_jing")+query("金")/5;
                        this_object()->add("nums",-20);
                }
                else
                        num=ob->query("eff_jing")+query("金");
                if(num>(ob->query_temp("maxjing",1)*2))
                {
                        tell_object(ob,"你突然感到一股极强的热流从下腹部直冲头顶，好象被火烤似地！\n");
                        ob->receive_damage("jing",ob->query("jing"));
                        ob->receive_wound("jing", ob->query("eff_jing")/2);
                        faint=1;
                }
                else
                {
tell_object(ob,"你感到一股暖流从下腹部往头顶流去，舒服极了。\n"); 
                        if(num>ob->query("max_jing"))
                        {
                                if(num>(ob->query_temp("maxjing",1)+ob->query_temp("maxjing",1)/4))
                                        num=ob->query_temp("maxjing",1)+ob->query_temp("maxjing",1)/4;
                                ob->set("max_jing",num);
                        }
                        ob->set("eff_jing",num);
                }
        }
        if(query("土")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("food")+query("土")/10;
                        num2=ob->query("water")+query("土")/10;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("food")+query("土")/2;
                        num2=ob->query("water")+query("土")/2;
                }
                if((num>(ob->max_food_capacity()*3)) || 
                   (num2>(ob->max_water_capacity()*3)))
                {
                        tell_object(ob,"你大概是由于吃喝过多了，肚子涨得很难受！\n");
ob->receive_damage("qi",ob->query("qi")/2);
                        ob->receive_damage("jing", ob->query("jing")/2);
                        ob->set("food",ob->max_food_capacity());
                        ob->set("water",ob->max_water_capacity());
                        ob->start_busy(random(3)+3);
                }
                else
                {
                        tell_object(ob,"你感到肚子饱了不少，嘴里也滋润多了。\n"); 
                        ob->set("food",num);
                        ob->set("water",num2);
                }
        }
        if(query("水")!=0)
        {
                if(ob->query_temp("maxqi",1)==0)
                        ob->set_temp("maxqi",ob->query("max_qi"));
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("eff_qi")+query("水")/5;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("eff_qi")+query("水");
                }
                if(num>(ob->query_temp("maxqi",1)*2))
                {
                        tell_object(ob,"你突然感到全身气血起伏不定，难受之极！\n");
                        ob->receive_damage("qi",ob->query("qi"));
ob->receive_wound("qi", ob->query("eff_qi")/2);
                        faint=1;
                }
                else
                {
                        tell_object(ob,"你感到身上的伤势好了很多。\n"); 
                        if(num>ob->query("max_qi"))
                        {
                                if(num>(ob->query_temp("maxqi",1)+ob->query_temp("maxqi",1)/4))
                                        num=ob->query_temp("maxqi",1)+ob->query_temp("maxqi",1)/4;
                                ob->set("max_qi",num);
                        }
                        ob->set("eff_qi",num);
                }
        }
        if(query("火")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("neili")+query("火")/5;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("neili")+query("火");
                }
                if(num>=(ob->query("max_neili")*7/2))
                {
                        tell_object(ob,"你突然感到内力犹如脱缰之烈马，在身体内左冲右突！\n");
ob->receive_damage("qi",ob->query("qi")*3/4);
                        ob->receive_damage("jing", ob->query("jing")*3/4);
                        ob->set("neili",0);
                        faint=1;
                }
                else if(num>ob->query("max_neili"))
                {
                        tell_object(ob,"你感到内力全部恢复了。\n");
                        ob->set("neili",ob->query("max_neili"));
                }
                else
                {
                        tell_object(ob,"你感到内力恢复不少。\n");
                        ob->set("neili",num);
                }
        }
        if(query("木")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("jingli")+query("木")/5;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("jingli")+query("木");
                }
                if(num>=(ob->query("eff_jingli")*7/2))
                {
                        tell_object(ob,"你感到精力旺盛之极，不由得拼命发泄，力尽方止！\n");
ob->receive_damage("qi",ob->query("qi")*3/4);
                        ob->receive_damage("jing", ob->query("jing")*3/4);
                        ob->set("jingli",0);
                        faint=1;
                }
                else if(num>ob->query("eff_jingli"))
                {
                        tell_object(ob,"你感到精力全部恢复了。\n");
                        ob->set("jingli",ob->query("eff_jingli"));
                        if((time()-ob->query("jl_add"))>3600)
                        {
                                ob->set("old_maxjl",ob->query("max_jingli"));
                                ob->set("old_effjl",ob->query("eff_jingli"));
                                ob->add("eff_jingli",num/ob->query("eff_jingli")); 
                                ob->add("max_jingli",num/ob->query("eff_jingli")); 
                                ob->set("jl_add",time());
                        }
                        else
                        {
                                ob->add("max_jingli",num/ob->query("eff_jingli")); 
                                ob->add("eff_jingli",num/ob->query("eff_jingli")); 
                                if((ob->query("max_jingli")-ob->query("old_maxjl"))>3)
                                {
                                        ob->set("max_jingli",ob->query("old_maxjl")+3);
                                        ob->set("eff_jingli",ob->query("old_effjl")+3);
                                }
                        }
                }
                else
{
                        tell_object(ob,"你感到精力恢复不少。\n");
                        ob->set("jingli",num);
                }
        }
        if(faint)
                ob->unconcious();
}

