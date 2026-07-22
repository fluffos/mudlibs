// Room: /d/wudang/liandanfang.c
// Update by lius 99/8
// Modify By River@SJ
#include <ansi.h>
#include <job_mul.h>
inherit ROOM;

void create()
{
        set("short", "炼丹房");
        set("long", @LONG
这里是间药香弥漫的大屋，屋四周堆满了各式各样的药材，房子中间摆放
着一只炼丹用的特制铜鼎(tongding)。墙边还有各种工具，切药，研药....一
应具全。道童们正全神灌注的协助炼丹者，扇风担水，一切都井然有序，显然
是训练有素。因为长期炼丹的缘故，这屋子四季如春！
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang2",
        ]));

        set("objects",([
                CLASS_D("wudang") +"/yudaiyan" : 1,
                __DIR__"npc/daotong" : 1,
        ]));

        set("item_desc", ([
                "tongding" : "    这是由青铜铸成的炼丹铜鼎，重约二百多斤，鼎身纹有九龙戏珠\n"+
                             "的图案。鼎内火势正旺，正是炼丹的紧要关头! 为了保持火势，必须\n"+
                             "不停地向鼎口扇(shan)风。\n",
        ]));

        set("dan_count", 3);
        setup();
}

void init()
{
        add_action("action", ({
                "du",
                "lian",
                "practice",
                "study",
        }));
        add_action("do_quit", "quit");
        add_action("do_kanshou", "kanshou");
        add_action("do_leave", "leave");
        add_action("do_shan", "shan");
        add_action("do_yan",({"yan", "mo"}));
        add_action("do_lianyao", ({"lianyao","aoyao"}));
        add_action("do_kan", ({"kan","look"}));
        add_action("do_yunqi", "yunqi");
        add_action("do_qilu", "qilu");
}

int action()
{
        write("丹房重地，不能如此！\n");
        return 1;
}

int do_quit()
{
        write("这里不能退出游戏。\n");
        return 1;
}

int do_shan(string arg)
{
	mapping fam;
        object me;
        int costj, costq;
        me = this_player();

        if( me->query_temp("wd_job1")) 
            {write("你还是专心看守铜鼎吧！\n");return 1;}

        if (me->is_busy()) return notify_fail ("你现在正忙着呢！\n");

        if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心干活！\n");

        if ( ! arg || arg != "tongding" ){
      	    message_vision("$N摆了摆手，象是在扇凉！\n",me);
            return 1;
        }
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
               return notify_fail("你与本派素无来往，不必在此浪费体力！\n");

        costj = 1000 / (int)me->query("con");
        costj = random(costj);
        costq = 1500 / (int)me->query("str");
        costq = random(costq);

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
             message_vision("$N用力过猛，一不留神头嗑到香炉上！\n",me);
             me->unconcious();
             return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->receive_damage("qi", costq);       

        tell_object(me,"你用力呼哧呼哧地扇着火。\n");

        if ( (int)me->query_skill("cuff", 1) < 31){
              write(HIY"你手臂来回用力，进退之中似乎对基本拳法有些领悟。\n"NOR);
              me->improve_skill("cuff", (int)(me->query("int") / 2));
        }
        if ( (int)me->query_skill("hand", 1) < 31){
              write(HIY"你手臂来回用力，进退之中似乎对基本手法有些领悟。\n"NOR);
              me->improve_skill("hand", (int)(me->query("int") / 2));
        }
        return 1;
}

int do_kanshou()
{
       mapping fam;
       int exp;
       object me;
       object ob = this_player();

       if(!present("yu daiyan",  environment(ob) ) )
                return notify_fail("什么？\n");

       me = present("yu daiyan",  environment(ob) );
       fam = ob->query("family");
       exp = ob->query("combat_exp");

       if(ob->is_busy()) return notify_fail("你现在正忙着呢。\n");

       message_vision(CYN"$N想看守铜鼎丹炉。\n"NOR,ob);

       if (!fam || fam["family_name"] !="武当派")
             return notify_fail(GRN"俞岱岩告诉你："+RANK_D->query_respect(this_player())+"与本派素无来往，我看还是不必劳您大驾了！\n"NOR);

       if (exp < 100000)
             return notify_fail("你的实战经验不足，还是先去采药吧！\n");

       if (exp > 500000)
             return notify_fail("你都这么厉害了，还是去找找其他事情做吧！\n");

       if(ob->query_condition("wd_job") > 0 )
             return notify_fail("你正忙着做其他任务呢。\n");

       if(ob->query("job_name") == "看守铜鼎"){
            message_vision(CYN"俞岱岩说道："+ob->name()+"，你还是先去歇息片刻再来吧！\n"NOR,ob);
            return 1; 
       }
       
       if(ob->query_condition("job_busy") >= 1){
            message_vision(CYN"俞岱岩说道："+ob->name()+"，你还是先去歇息片刻再来吧！\n"NOR,ob);
            return 1; 
       }

       if( me->query("guard_count") >= 3){
            message_vision(CYN"俞岱岩说道：现在人手已经够了，"+ob->name()+"，你还是去找找其他事情做吧！\n",ob);
            return 1;
       }

       if (ob->query_temp("wd_job1"))
             return notify_fail("你正在看守铜鼎。\n");

        me->add("guard_count",1);
        ob->set_temp("wd_job1",1);
        ob->set_temp("apply/short", ({HIC"铜鼎守卫"NOR+" "+ob->name()+"("+capitalize(ob->query("id"))+")"}));
        message_vision(CYN"俞岱岩说道：好吧，"+ob->name()+"，你来的正是时候，我这儿正缺人手。\n"NOR,ob);
        message_vision(CYN"俞岱岩说道：此铜鼎丹炉乃武当至宝，你一定要小心看护。\n"NOR,ob);
        call_out("give_reward",240+random(60),ob);
        ob->add_busy(1);
        ob->set("job_name", "看守铜鼎");
        call_out("do_attack",120+random(80),ob);
        if(random(10) > 2) {
		call_out("do_attack",20+random(40),ob);
		return 1;
        }
        return 1;   
}

int do_leave(object ob)
{
        object me;
        ob = this_player();
        me = present("yu daiyan",  environment(ob));

        if( ob->query_temp("wd_job1")<1 )
            return notify_fail("你并没有在看守铜鼎。\n");

        ob->delete_temp("wd_job1");
        if (!me) return notify_fail("你想趁俞岱岩不在时开溜？这可不行。\n");
        me->add("guard_count",-1);
        if (me->query("guard_count") < 0) me->set("guard_count",0);
        ob->delete_temp("apply/short");
        ob->apply_condition("job_busy",16);//add by caiji@SJ
        // busy must > 15,because of a bug
        ob->apply_condition("wd_job",16);// add by caiji@SJ
        //busy must > 15,because of a bug
        message_vision(CYN"$N打算放弃这轮看守铜鼎丹炉的任务。\n"NOR,ob);
        message_vision(CYN"俞岱岩说道：唉…，"+ob->name()+"，既然你干不了我也不勉强你，下次好好干吧！\n"NOR,ob);
        return 1;
}

int do_attack(object ob)
{
        mapping skills;
        string *sk;
        int exp,i,lv;
        object att;
        if(!ob || !ob->query_temp("wd_job1")) return 1;
        if(!present("yu daiyan",environment(ob))) {
             tell_object(ob,"任务失败。\n");
             ob->delete_temp("wd_job1");
             return 1;
        }
        exp = ob->query("combat_exp");
        lv = ob->query("max_pot") - 90 + random(10);
        lv = ob->query("max_pot") - 110 + random(10);
        if( ob->query("combat_exp")<500000) lv-=20;
        else if (ob->query("combat_exp") < 1000000) lv-=15;
        else if (ob->query("combat_exp") < 1500000) lv-=10;
        att = new(__DIR__"npc/attecker");
        att->set("qi",(int)ob->query("qi"));
        att->set("max_qi", (int)ob->query("max_qi") );
        att->set("eff_qi", (int)ob->query("max_qi") );
        att->set("jing",(int)ob->query("jing"));
        att->set("eff_jing",(int)ob->query("max_jing"));
        att->set("neili",(int)ob->query("max_neili") );
        att->set("max_neili",(int)ob->query("max_neili") );
        att->set("jingli",(int)ob->query("jingli"));
        att->set("eff_jingli",(int)ob->query("eff_jingli"));
        att->set("combat_exp", exp*3/2);
        skills = att->query_skills();
        if (mapp(skills)){
             sk = keys(skills);
             for (i=0;i<sizeof(sk);i++)
             skills[sk[i]] = lv;
        }
        message_vision(HIR"\n只听「哐」的一声巨响，一名"+att->name()+"破门而入，对$N发起猛烈的攻击！\n\n"NOR,ob);
        att->move(environment(ob));
        att->kill_ob(ob);
        return 1;
}

int give_reward(object ob)
{
        int p,e;
        object me,here;

        if (!ob) return 1;
        me = present("yu daiyan",  environment(ob));
        here=environment(ob);
	e = 100 + random(50)+ random(ob->query("combat_exp"))/10000;	
	ob->delete_temp("apply/short");
	if(!ob->query_temp("wd_job1")) return 1;
	if(ob->query_condition("wd_job")||  //add by caiji@SJ
           ob->query_conditon("job_busy")) return 1;// add by caiji@SJ
	else if((string)here->query("short") != "炼丹房"){
		ob->delete_temp("wd_job1");
		ob->delete_temp("guard");
		tell_object(ob,CYN"看守时限已到，但是你擅离职守，任务失败了！\n"NOR);
		return 1;
        }
	else if(!present("yu daiyan",  environment(ob)) 
	      && here->query("short") == "炼丹房")
		tell_object(ob,CYN"你看守铜鼎任务顺利完成！\n"NOR);
	else {    
		message_vision(CYN"俞岱岩说道：好，时间到了！"+ob->name()+"，你下去休息吧！\n"NOR,ob);
		me->add("guard_count",-1);
		if (me->query("guard_count") < 0) me->set("guard_count",0);
	}
	
	e = ob->add_exp_combat(e,"俞岱岩","看守铜鼎");
	//ob->add("combat_exp",e);
	//ob->add("job_time/看守铜鼎",1);
	//GIFT_D->check_count(ob,"俞岱岩","看守铜鼎");
	p = e/5 + random(e/10);
		
	ob->add("potential",p);
	ob->delete_temp("wd_job1");
	ob->delete_temp("guard");
	if ( (int)ob->query("potential", 1) > (int)ob->query("max_pot", 1))
		ob->set("potential" , ob->query("max_pot", 1));
	tell_object(ob, GRN"你此次看守共得到"+CHINESE_D->chinese_number(e)+"点经验，"+CHINESE_D->chinese_number(p)+"点潜能！\n"NOR);
	log_file("job/kanshou",sprintf("%8s%-10s看守铜鼎获得了%3d点经验，%2d点潜能，现经验：%d。\n",
		ob->name(),"("+ob->query("id")+")",e,p, ob->query("combat_exp")), ob);
	remove_call_out("do_attack");
	ob->apply_condition("job_busy",3+random(3));
	ob->apply_condition("wd_job",6);
	ob->add("job_time/武当",1);	
	return 1;
}

int do_yan(string arg)
{
	object me;
	me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");
        if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");
	if ( arg != "yao" ) 
		return notify_fail("你需要把什么研磨细呢\n");

	if (!me->query_temp("yao_get"))
		return notify_fail("你身上没有需要研磨的药材！！\n");

	if (me->query_temp("yanyao_ok"))
		return notify_fail("你已经把药材研磨好了！！\n");  

	message_vision("$N将药放入一个铁制药研里面，细细地研磨起来。\n", me);
	me->add_busy(2);
	me->delete_temp("yao_get");
	me->set_temp("yanyao_ok",1);
	message_vision(HIY"$N研磨完药材，满意地站了起来。\n"NOR,me);
	return 1;
}

int do_lianyao(string arg)
{
        object me, ob_yd;
        me = this_player();
        ob_yd = present("yao dai",me);

        if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

        if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");

	if ( arg != "tongding" ) 
		return notify_fail("你用什么来炼药？\n");

        if (me->query("jingli",1) < 600)
		return notify_fail("你精力不够了！！！\n");

        if (!me->query_temp("yanyao_ok") || !( present("yao dai", me)))
		return notify_fail("在炼药之前，你需要先把药袋里的药研细！！\n");

        if (me->query_temp("lianyao"))
		return notify_fail("你现在正在炼药！！！\n");

        if (!(present("yu daiyan", environment(me))))
		return notify_fail("\n你正要炼药，突然发现俞岱岩师兄不在身边，不禁心里打起鼓来。\n");  
	message_vision("\n$N招了招手，将精心研细的药物放入铜鼎，道童们立即围上去添水扇风协助炼丹。\n", me);
	write(HIG"\n俞岱岩突然大声说道：“炉火初起，你且专心炼药，我来指挥道童协助。你可用\n"+
		"["HIY"kan yao"HIG"]来看药物的成色，用["HIY"yunqi tongding"HIG"]来加快火势，一挨炉火纯青，\n"+
		"当是丹成启炉["HIY" qilu tongding "HIG"]之时。\n"NOR);
	me->add_busy(3);
	me->delete_temp("yanyao_ok");
	me->set_temp("lianyao",1);
	me->apply_condition("lian_time",50+random(20));
	me->set_temp("finish_time",15+random(5));
	destruct(ob_yd);
	return 1;
}

int do_kan(string arg)
{
	object me;
	int i;
	me = this_player();

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");

	if ( arg != "yao" ) 
		return notify_fail("你要看什么？\n");

	if (!me->query_temp("lianyao"))
		return notify_fail("别人炼药,有什么好看的？\n");

	i = me->query_condition("lian_time",1) - me->query_temp("finish_time",1);
	if ( i <= 2 && i >= -2 ){
		write(HIM"炉火纯青，冻状透明物已完全收拢，成为一颗球形丹丸，药香四溢，丹药已成！！\n"NOR);
		return 1; 
	}
	if ( 2 < i && i <= 10 ){
		write(HIG"火势转温，鼎内药物汁液已收，成为一种冻状透明物，并开始渐渐聚拢。\n"NOR);
		return 1; 
	}
	if ( 10 < i && i <= 25 ){
		write(WHT"火势渐猛，药物已完全融于清泉，“啵啵”有声，开始收汁。\n"NOR);
		return 1; 
	}
	if ( i > 25 ){
		write(YEL"炉火初起，鼎内药物渐渐与清泉相溶。\n"NOR);
		return 1; 
	}
	if (  i < -2 ){
		write(BLU"火势凶猛，鼎内墨黑一团，散发出阵阵焦臭，药物已经熬焦了！！！\n"NOR);
		return 1; 
	}
	return 1;
}

int do_yunqi(string arg)
{
	object me;
	int i;
	me = this_player();

        if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

        if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");

	if (!me->query_temp("lianyao"))
		return notify_fail("别人炼药，你着什么急呀？\n");

	if ( arg != "tongding" ) 
		return notify_fail("\n你盘膝而坐，突然凌空劈出两掌，甚是得意，四周的人都无比惊讶！！\n");

	if (me->query("neili",1) < 200 )
		return notify_fail("你残余的内力已不够你出掌了！！！\n");

	tell_room(environment(me),me->name()+ "盘膝而坐，脸色凝重。\n",({ me }));

	write(HIW"\n你盘膝而坐，间或拍出两掌击向铜鼎，将自身精湛的内力注入鼎内。\n"+
		"铜鼎竟在这一拍一托之下，凌空而起高速旋转起来，而后又稳稳的落了下来。\n"NOR, me); 

	i = me->query_condition("lian_time",1) - (1+random(2));

	me->add_busy(1);
	me->add("neili",-(60+random(50)));
	me->apply_condition("lian_time",i);
	return 1;
}

int do_qilu(string arg)
{
	object ob, me;
	int i;
	me = this_player();

        if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

        if (me->is_fighting())
		return notify_fail("你正在战斗中，无法专心干活！\n");

	if ( !arg || arg != "tongding" ) 
		return notify_fail("你要启开什么？\n");

	if (!me->query_temp("lianyao"))
		return notify_fail("别人炼药，你启什么炉？想偷窃呀？\n");         

	if (!me->query_condition("lian_time")){
		me->delete_temp("lianyao");
		return notify_fail("你行动太慢，已把炼丹搞砸了！！\n");
	}
	if (me->query("neili",1) < 500 )
		return notify_fail("你残余的内力已不能把丹药拍出铜鼎了！！！\n");

	i = me->query_condition("lian_time",1) - me->query_temp("finish_time",1);

	if ( i >= -2 && i <= 2 ) {
		message_vision(YEL"\n$N一跃而起，轻喝一声“起！”，左掌在铜鼎上轻轻一按，一粒色泽斑斓的丹丸,\n"+
				"已“啵”的一声应声而起，$N微一招手，早将丹丸接到手中。\n"NOR, me);
		ob=new(__DIR__"obj/wd_dan");
		ob->set("owner", me->query("id"));
		ob->move(me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");
		return 1; 
	}
	if ( i > 2 && i < 11 ) {
		message_vision(WHT"\n$N左掌在铜鼎上用力一拍，一块冻状物体从铜鼎中弹了出来，掉在地上，$N后悔已极！\n"NOR, me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");
		return 1; 
	}
	if ( i > 10 ){
		message_vision(RED"\n$N左掌在铜鼎上用力一拍，铜鼎内的药水劈头盖脑的泼了出来，\n"+
                               "淋在$N的脸上、身上，剧痛无比。\n"NOR, me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");
		me->receive_damage("qi", me->query("max_qi")/2);
		me->receive_wound("qi", me->query("max_qi") / 2);
		me->unconcious();
		return 1; 
	}
	if ( i < -2 ){
		message_vision(BLU"\n道童们七手八脚的从铜鼎中铲出一些烧的焦黑的药物残渣，再注入清水清洗，\n"+
                               "$N一声不吭，羞愧地退了下来。\n"NOR, me);
		me->clear_condition("lian_time");
		me->delete_temp("finish_time");
		me->delete_temp("lianyao");                 
		return 1; 
	}
	return 1;
}

int valid_leave(object me,string dir)
{
	if ( me->query_temp("wd_job1") && dir == "east" )
		return notify_fail("你正在看守铜鼎，不能离开！\n");

	if (me->query_temp("lianyao") && dir == "east" ){
		me->delete_temp("lianyao");
		me->apply_condition("lian_time",0);
		me->delete_temp("finish_time");
		me->apply_condition("wd_busy",10);
		message_vision(HIY"$N擅离丹房，任务失败！！\n"NOR,me);
	}
	return ::valid_leave(me, dir);
}
