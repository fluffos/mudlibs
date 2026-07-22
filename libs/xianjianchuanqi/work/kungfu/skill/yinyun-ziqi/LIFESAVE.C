// 鹤嘴劲点龙跃窍yinyun-ziqi/lifesave.c
// Write by Cht 1999.9.2
// Modify by snowman@SJ 20/01/2000
// exp 只恢复一半。

#include <ansi.h>

int exert(object me,object corp)
{
        object obj;
        object where;
        mapping myfam;

        myfam = (mapping)me->query("family");

        where = environment(me);

        if ( !present(corp,where) )
                return notify_fail("指令格式：yun lifesave corpse\n");

        if( !corp )
                return notify_fail("指令格式：yun lifesave corpse\n");

        if ( corp==me )
                return notify_fail("你现在还不能救自己！\n");

        if ( userp(corp) )
                return notify_fail("你看清楚，那是活人！！！\n");
      
        if ( !corp->is_corpse() )
                return notify_fail("那不是尸体耶，脑子有毛病啊？\n");

        if ( (string)corp->query("name") == "腐烂的男尸" || (string)corp->query("name") == "腐烂的女尸")
                return notify_fail("都烂了，你就打消这个念头吧。\n");    

        if(userp(me) && ((string)me->query_skill_mapped("force") != "yinyun-ziqi"))
                return notify_fail("你的内功不对。\n");    
        if((int)me->query_skill("yinyun-ziqi", 1) < 180 )
                return notify_fail("你的「氤氲紫气」级别不够，不能运用「鹤嘴劲点龙跃窍」救人。\n");
        if((int)me->query_skill("taoism", 1) < 180 )
                return notify_fail("你对「道学心法」领悟不深，不能运用「鹤嘴劲点龙跃窍」救人。\n");
        if((int)me->query_skill("medicine", 1) < 120 )
                return notify_fail("你还得多学点草木药理。\n");
        if( (int)me->query("max_neili", 1) < 3000 )
                return notify_fail("你的内力修为太弱，还不能运用「鹤嘴劲点龙跃窍」救人。\n"); 
        if( myfam["family_name"] != "武当派")
                return notify_fail("大胆！敢偷学武当绝技。去死吧……！\n");
                
        obj = find_player(corp->query("victim_id"));

        if ( !obj || !corp->query("victim_user") )
                return notify_fail(corp->query("victim_name")+"的魂魄不在游戏里。\n");

        if( !obj->is_ghost() ) 
                return notify_fail(obj->name() + "已经活过来了，不用你救。\n");

        me->start_busy(5);

        message_vision(HIY"只见$N双手食指和拇指虚拿，成“"HIW"鹤嘴劲"NOR""HIY"”势，以食指指尖点在$n耳尖三分处的“龙跃窍”，\n"
"运起内功，微微摆动。这“"NOR""HIW"鹤嘴劲点龙跃窍"NOR""HIY"”使将出来，便是新断气之人也能还魂片刻。。。\n"NOR, me, corp);       
                
        call_out("do_save",3,me,corp,obj);
        return 1;
}

void do_save(object me,object corp,object obj)
{
        mapping skills,learned;
        int i,j,yyzq_drop,yyzq_lvl;
        string *sk;

        if (!me || !corp || !obj) return;
        if (!present(corp, environment(me))) return;
        if (!obj->is_ghost()) return;
        
        j = 10 + random(me->query_skill("taoism"));
        yyzq_lvl = me->query_skill("yinyun-ziqi",1);
        yyzq_drop = yyzq_lvl*yyzq_lvl / 3;
        learned = me->query_learned();
        
        tell_object(obj, HIY "\n一道天罡阳气击中你，痛得你几乎晕死过去！\n\n" NOR);
        
        message_vision(HIC"\n不一会，$N额头上冒出豆大汗珠，$n也似乎动了一下……\n\n"NOR,me,corp);
        
        me->add("max_neili",-j );
        learned["yinyun-ziqi"] -= yyzq_drop;
        me->add("shen",yyzq_drop / 10);
                
        if( learned["yinyun-ziqi"]<0) {
                me->set_skill("yinyun-ziqi",yyzq_lvl-1);
                me->improve_skill("yinyun-ziqi", yyzq_lvl*yyzq_lvl, 1);
        }
        
        if( me->query("neili") < 2000 || random(me->query_skill("taoism", 1)) < 50){
                me->set("neili", 0);
                tell_object(me, HIR"猛然，你发现自己已经内力消耗殆尽，无法再支持了！\n"NOR);
                log_file("skills/lifesave",sprintf("%s 于 %s 耗费了 %d 点最大内力，但没有救活%s。\n",
                me->name(1)+"("+me->query("id")+")",  ctime(time()) ,j, obj->name(1)+"("+obj->query("id")+")"));
                me->unconcious();
                return;
        }
        
        me->add("neili",-2000);
        if( me->query("last_lifesave") == obj->query("id")){
                write(HIR"突然你全身一震，一下子失去了"+obj->name()+"的魂魄！\n"NOR);
                tell_object(me, HIR"你觉得四周天罡阳气越来越盛，突然凭空传来一声厉鬼巨喝：“此人不得再离开此地！”\n"NOR);
                obj->unconcious();
                return;
        }        
        
        if ( obj->query("g_name") && !present("lingpai",obj))
                new("/data/group/obj/ling")->move(obj);
        obj->unconcious();
        message("vision", HIY +me->name(1)+"化作一道天罡阳气消失了！\n"NOR, environment(me), me);
        message_vision("一缕魂魄归到尸体上，$n竟然晃晃悠悠地站起来！\n\n", me, corp);
        destruct(corp);
        obj->move(environment(me));
        skills = obj->query_skills();
        if (mapp(skills)) {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]]++;
        }
        obj->add("combat_exp",obj->query("combat_exp")/198 + 1);
        obj->add("shen", obj->query("shen")/18);
        obj->set_ghost(0);
        obj->set("eff_qi", 1);
        obj->set("eff_jing",1);
        i = obj->query("death_count") - 1;
        if (i < 0) i = 0;
        obj->set("death_count", i);
        if (i < obj->query("death_times")) obj->set("death_times", i); 
       
        tell_object(me, "你此次救人共耗费了"+CHINESE_D->chinese_number(j)+"点最大内力，「氤氲紫气」下降了"+CHINESE_D->chinese_number(yyzq_drop)+"点。\n");
        me->set("last_lifesave", obj->query("id"));

        log_file("skills/lifesave",sprintf("%s 救活 %s 于%s，耗费了 %d 点最大内力。\n",
                                me->name(1)+"("+me->query("id")+")",obj->name(1)+"("+obj->query("id")+")", ctime(time()) ,j));

        return;
}

int help(object me)
{
	write(WHT"\n氤氲紫气「鹤嘴劲点龙跃窍」："NOR"\n");
	write(@HELP
	武当一派，擅长救死扶伤，即便是新断气人，用鹤嘴劲点龙跃窍的功夫，未
	必不可还魂，此法虽妙，但对救人者大伤真元，被救者亦需休养生息。

	要求：氤氲紫气等级 180 以上；
              道学心法等级 180 以上；
              本草术理等级 120 以上；
              最大内力 3000 以上。
+
HELP
	);
	return 1;
}

