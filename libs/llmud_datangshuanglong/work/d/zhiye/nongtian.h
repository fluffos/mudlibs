// nongtian.h
// by augx@sj  10/17/2001

// Modified by mxzhao 2004/03/06 caiji => nongsang

#include <ansi.h>
#include <job_mul.h>

#define EXAM_TICK       30
#define FINISH_TICK     1800
#define TIMEOUT_TICK    120
#define DEBUGMODE       0

string* have_items =
	({"mian hua","ya ma","da ma","zhu ma","mu mianhua",});
string* have_items_c =
	({HIW"棉花",YEL"亚麻",YEL"大麻",HIY"苎麻",HIY"木棉花",});

void init()
{
	int fib=0;
	int i;
	string biaoji;	
	if(query("outdoors")=="长安郊外"){
		biaoji = "长安农政司布告";
		fib = 5;
	}
	if(query("show_msg")!=1 && fib>0)
        {
        	biaoji = CHINESE_D->get_title(biaoji)+"    此地适宜种植：\n";
		for(i=0;i<fib;i++)
        		biaoji += "\t"+have_items_c[i]+NOR+"("+capitalize(have_items[i])+")"+"\n";
        	biaoji += "\n\t请与城中采购种子。\n\t农家以zhongzhi xxxx 开始种植。\n";
        	set("show_msg",1);
        	set("long",query("long")+"    田埂边还有一方标记(biaoji)。\n");
        	set("item_desc/biaoji",biaoji);
        	set("no_fight",1);
        }
        add_action("do_zhongzhi","zhongzhi");
        add_action("do_jiaoshui","jiaoshui");
        add_action("do_shifei"  ,"shifei"  );
        add_action("do_shouge"  ,"shouge"  );
        //add_action("do_wah", "wah");
}

int clean_up()
{
        return 1;
}

void decide_action(string u)
{
        if( !mapp(query("user/"+u)) ) return;
        set("user/"+u+"/action" , 1 + random(2) );
        if( !DEBUGMODE ) {
                set("user/"+u+"/atime"  , time() + 2*60 + random(2*60) );
                if( query("user/"+u+"/atime") > (query("user/"+u+"/start")+FINISH_TICK) )
                        set("user/"+u+"/action" , 3);
        }
        else {
                set("user/"+u+"/atime"  , time() + 10 + random(20) );
                if( query("user/"+u+"/atime") > (query("user/"+u+"/start")+180) )
                        set("user/"+u+"/action" , 3);
        }
}

void exam()
{
        mapping mp;
        mapping * mpv;
        string  * mpk, *overtime;
        object me;
        int i,count;
        
        remove_call_out("exam");
        
        if( !mapp(mp = query("user")) || (count=sizeof(mp))<1 ) {
                set("exam",0);
                return;
        }       
        mpv = values(mp);
        mpk = keys(mp);
        
        overtime = ({ });
        for(i=0;i<count;i++) {
                if( time() < mpv[i]["atime"] ) continue;
                
                me = present(mpk[i], this_object());
                if( time() > (mpv[i]["atime"]+TIMEOUT_TICK) ) {
                        if(mpv[i]["action"]==3) {
                                if(me && userp(me)) 
                                        tell_object(me,RED"你错过了收割的时机，心血都浪费掉了！\n"NOR);
                                overtime += ({ mpk[i] });
                                continue;
                        }
                        else {
                                if(me && userp(me))
                                        tell_object(me,HIR"你错过了" + (mpv[i]["action"]==1?"浇水":"施肥") + "的时机，植物长势受到影响。\n"NOR);
                                mpv[i]["lost"]++;
                                decide_action(mpk[i]);
                        }
                }
                else {
                        if(me && userp(me)) {           
                                switch (mpv[i]["action"]) {
                                        case 1: tell_object(me,GRN"你该给你所种植的作物浇水了。\n"NOR); break;
                                        case 2: tell_object(me,GRN"你该给你所种植的作物施肥了。\n"NOR); break;
                                        case 3: tell_object(me,HIG"你所种植的植物已经成熟，你可以开始收割了。\n"NOR); break;
                                }                                       
                        }
                }
        }
        
        for(i=0;i<sizeof(overtime);i++)
                delete( "user/" + overtime[i] );
        
        if( !mapp(mp=query("user")) || sizeof(mp)<1 )
                set("exam",0);
        else
                call_out("exam",EXAM_TICK);
}

//////////////////////////////////////////////////////////////////////////////
int do_zhongzhi(string arg)
{
        object me = this_player() ,weapon ,zhongzi;
        int level,delay;
        
        if( !arg ) return notify_fail("你要种植什么？\n");      
        if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tieqiao" )
                return notify_fail("你必须装备铁锹才能种植。\n");
        if ( me->is_busy() )
                return notify_fail("你正忙着呢！\n");   
        level = (int)me->query_skill("nongsang",1);
        if ( level<1 ) return notify_fail("你根本就不会农桑技能啊！是不是先学习一些农桑技能(nongsang)再来种植啊？！\n");
        if ( mapp(query("user/"+me->query("id"))) )
                return notify_fail("你已经开始种植了呀！\n");
        if ( !objectp(zhongzi = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");
        if( !(int)zhongzi->query("zhongzi") )
                return notify_fail("你不能用这样东西来种植。\n");
                
        switch( zhongzi->query_level() ) {
                case 1: break;
                case 2: if(level<40)  return notify_fail("你的农桑技能不够！\n"); break;
                case 3: if(level<80)  return notify_fail("你的农桑技能不够！\n"); break;
                case 4: if(level<120) return notify_fail("你的农桑技能不够！\n"); break;
                case 6: if(level<220) return notify_fail("你的农桑技能不够！\n"); break;
                default: return notify_fail("你不能种植这样植物！\n"); break;
        }
                
        set("user/"+me->query("id")+"/start", time());
        set("user/"+me->query("id")+"/product", zhongzi->query_level());
        set("user/"+me->query("id")+"/lost", 0);
        decide_action(me->query("id"));
        if( !query("exam") ) {
                call_out("exam",EXAM_TICK);
                set("exam",1);
        }

        destruct(zhongzi);      
        message_vision(HIY"$N开始用铁锹松土......\n\n"NOR, me);
        delay = 10 + random(20);
        if(wizardp(me) && (int)me->query("env/test")) delay = 6;
        me->start_busy(delay+1);
        call_out("zhongzhi_finish",delay/3,me,1,delay);
        
        return 1;
}

void zhongzhi_finish(object me,int step,int delay)
{
        object tools;
        int i;
        
        if(!me) return;
        switch (step) {
                case 1: message_vision(HIY"然后$N用铁锹挖了一个坑......\n"NOR, me); break;
                case 2: message_vision(HIY"$N把种子放到坑里......\n"NOR, me); break;
                case 3: message_vision(HIY"$N小心的把坑埋好......\n"NOR, me); break;
                case 4: message_vision(HIY"$N开始在种子上浇水......\n"NOR, me); break;
                case 5: message_vision(HIY"$N开始在种子上施肥......\n"NOR, me); break;
                case 6: message_vision(YEL"$N总算种好了！\n"NOR, me); 
                        me->start_busy(-1);
                        me->interrupt_me();
                        for(i=0;i<3;i++) {
                                if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="tieqiao" )
                                        tools->use();
                        }
                        return;
        }
        call_out("zhongzhi_finish",delay/3,me,step+1,delay);
}

//////////////////////////////////////////////////////////////////////////////
int do_jiaoshui(string arg)
{
        object me = this_player();
        int delay;
        
        if( objectp( me->query_temp("weapon") ) )
                return notify_fail("你必须空手才能浇水啊。\n");         
        if( me->is_busy() )
                return notify_fail("你正忙着呢！\n");
        if( !mapp(query("user/"+me->query("id"))) )
                return notify_fail("你还没有开始种植，乱浇什么水啊！\n");
        if( query("user/"+me->query("id")+"/action") != 1
         || query("user/"+me->query("id")+"/atime") > time() )
                return notify_fail("你现在不需要浇水。\n");
                
        decide_action(me->query("id"));

        message_vision(HIW"$N从田地旁的水沟里挑了些水，开始浇地......\n\n"NOR, me);
        delay = 10 + random(20);
        if(wizardp(me) && (int)me->query("env/test")) delay = 2;
        me->start_busy(delay+1);
        call_out("jiaohua_finish",delay*2-1,me);
        
        return 1;
}

void jiaohua_finish(object me)
{
        if(!me) return;
        me->start_busy(-1);
        me->interrupt_me();
        message_vision(HIW"$N累地满头大汗，总算浇完了地。\n"NOR, me);
}

//////////////////////////////////////////////////////////////////////////////
int do_shifei(string arg)
{
        object me = this_player(),weapon;
        int delay;
        
        if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tieqiao" )
                return notify_fail("你必须装备铁锹才能施肥。\n");
        if( me->is_busy() )
                return notify_fail("你正忙着呢！\n");
        if( !mapp(query("user/"+me->query("id"))) )
                return notify_fail("你还没有开始种植，乱施什么肥啊！\n");
        if( query("user/"+me->query("id")+"/action") != 2
         || query("user/"+me->query("id")+"/atime") > time() )
                return notify_fail("你现在不需要施肥。\n");
                
        decide_action(me->query("id"));

        message_vision(HIY"$N从田地旁的肥料坑里铲了些肥料，开始施肥......\n\n"NOR, me);
        delay = 10 + random(20);
        if(wizardp(me) && (int)me->query("env/test")) delay = 2;
        me->start_busy(delay+1);
        call_out("shifei_finish",delay*2-1,me);
        
        return 1;
}

void shifei_finish(object me)
{
        object tools;
        if(!me) return;
        me->start_busy(-1);
        me->interrupt_me();
        message_vision(HIY"$N累地满头大汗，总算完成了施肥的工作。\n"NOR, me);
        if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="tieqiao" )
                tools->use();   
}

//////////////////////////////////////////////////////////////////////////////
int do_shouge(string arg)
{
        object me = this_player(),weapon;
        int delay;
        
        if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="lian dao" )
                return notify_fail("你必须装备镰刀才能收割。\n");
        if( me->is_busy() )
                return notify_fail("你正忙着呢！\n");
        if( !mapp(query("user/"+me->query("id"))) )
                return notify_fail("你还没有开始种植，收割什么！\n");
        if( query("user/"+me->query("id")+"/action") != 3
         || query("user/"+me->query("id")+"/atime") > time() )
                return notify_fail("现在还没有到收割季节呢。\n");

        decide_action(me->query("id"));

        message_vision(YEL"$N兴高采烈的开始收割......\n\n"NOR, me);
        delay = 10 + random(20);
        if(wizardp(me) && (int)me->query("env/test")) delay = 2;
        me->start_busy(delay+1);
        call_out("shouge_finish",delay*2-1,me);
        
        return 1;
}

void shouge_finish(object me)
{
        object tools,obj;
        int i,j,k,level,improve,bu;
        mapping mp;
        float updown;
        
        if( !me ||!userp(me) ) return;
        me->start_busy(-1);
        me->interrupt_me();
        if( !mapp(mp = query("user/"+me->query("id"))) ) return;
        level = (int)me->query_skill("nongsang",1);
        if(level>390) level = 390 + (level-390)*11;
        
        for(i=0;i<3;i++) {
                if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="lian dao" )
                        tools->use();
        }
        
        switch ( mp["product"] ) {
                case 1: i = 40;  break;
                case 2: i = 80;  break;
                case 3: i = 120; break;
                case 4: i = 170; break;
                case 6: i = 270; break;
        }       
        if ( i>(level*2) ) i=level*2;
        
        improve = me->query_int(1)*i/level;
        improve /= 3;
        
        switch( mp["product"] ) {
                case 1: i = 40;  break;
                case 2: i = 80;  break;
                case 3: i = 120; break;
                case 4: i = 180; break;
                case 6: i = 330; break;
        }
        if( level > i ) level = i;
        
        updown = WORKER_D->updown(me,"nongsang");
        bu = to_int((13 * 100 * level / i)*updown) ;
        bu = bu*2/3 + random(bu*2/3);
        if( mp["lost"] ) bu = bu - bu * (1+mp["lost"]*2)/10;
        bu = bu / 100;
        if(bu<1) bu=1;
        
        j = 0;
        for(i=0;i<bu;i++) {
        	obj = WORKER_D->mater_random(me,2,mp["product"]);
		if(!obj) return;
                obj->move(environment(me));
                if( !obj->move(me) ) {
                        j = 1;
                        if( sizeof(all_inventory(environment(me))) > 49 )
                                destruct(obj);
                }
        }
        
        message_vision(YEL"$N总共收获了"+CHINESE_D->chinese_number(bu)+obj->query("unit")+obj->name()+"。\n"NOR, me);
        if(j) message_vision(YEL"但是$N拿不动那么多，只好把几"+obj->query("unit")+obj->name()+"放到地上。\n"NOR, me);
        
        improve *= bu;
        improve = improve*2/3 + random(improve*2/3);
        //improve = improve*ZY_NONGSANG_MUL/100;
        i = improve * 12;
        WORKER_D->check_impove(me,"nongsang",i,2);
        j = random(improve)/2;
                
        j = me->add_exp_combat( j ,0,"农桑",1);
        //me->add("combat_exp", j);
                
        k = random(improve)/4;  me->add("potential", k);
        if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
                me->set("potential" , me->query("max_pot", 1) );

        log_file("job/wnongsang",sprintf("%s(%s)：bu:%d,lvl:%d;cj:%d,exp:%d,pot:%d;ncj:%d,nexp:%d\n", 
                me->name(),me->query("id"),bu,mp["product"],i,j,k,me->query_skill("nongsang",1),me->query("combat_exp")),me);
        delete("user/"+me->query("id"));
}
