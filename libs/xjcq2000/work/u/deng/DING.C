// /d/xingxiu/npc/ding.c
// ding.c 丁春秋
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

#define TIME_TICK (time()*60)

string *drugs = ({
       "/obj/yao",
       "/obj/yao1",
       "/obj/yao",
       "/obj/yao2",
       "/obj/yao",
       "/obj/yao3",
       "/obj/yao",     
});

int give_drug();
string ask_job();
string ask_gou();

void create()
{
        object ob;
        
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("nickname", "星宿老怪");
        set("long", 
        "星宿派开山祖师、令中原武林人士深恶痛绝的星宿老怪丁春秋。\n"
        "他脸色红润，满头白了，颏下三银髯，童颜鹤发。\n"
        "当真便如图画中的神仙人物一般。\n");
        set("gender", "男性");
        set("age", 60);
        set("per", 24);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 27);
        set("con", 28);
        set("dex", 32);
        set("max_qi", 6000);
        set("max_jing", 5000);
        set("eff_jingli", 3500);
        set("max_neili", 11000);
        set("jiali", 120);
        set("combat_exp", 2700000);
        set("shen", -200000);

        set_skill("force", 260);
        set_skill("huagong-dafa", 255);
        set_skill("dodge", 260);
        set_skill("zhaixingshu", 260);
        set_skill("strike", 260);
        set_skill("chousui-zhang", 260);
        set_skill("parry", 260);
        set_skill("claw", 260);
        set_skill("zhuihun-gou", 260);
        set_skill("hook", 260);
        set_skill("sanyin-zhua", 260);
        set_skill("staff", 260);
        set_skill("tianshan-zhang", 260);
        set_skill("literate", 130);
        set_skill("poison", 260);
        map_skill("force", "huagong-dafa");
        map_skill("hook", "zhuihun-gou");
        map_skill("dodge", "zhaixingshu");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "chousui-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");
        create_family("星宿派", 1, "开山祖师");
        set("inquiry", ([
               "星宿派" : "我老仙乃是星宿派开山祖师, 还不赶快磕头。", 
               "星宿海" : "你瞎了眼啦, 这儿就是。",
                 "星宿" : "这儿方圆几百里都是老仙的练功房。",
               "丁春秋" : "没大没小的。再叫我废了你。",
                 "老仙" : "我星宿老仙比起古往今来的圣人怎么样啊？",
             "星宿老仙" : "以后叫老仙。",
                 "吹捧" : "本来就是麽。",
                 "毒药" : (: give_drug :),
                "心情"  : (: ask_job :),
//               "寒玉钩" : (: ask_gou :),
             "神木王鼎" : "你敢偷，就废了你。",
                 "木鼎" : "抓虫子练毒用的。",
     ]));

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: exert_function, "huagong" :),
                (: perform_action, "strike.huoqiu" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "hook.luanpifeng" :),
        }));

        set("drug_count",15);
        set("class", "taoist");

        set_temp("apply/damage", 20);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 60);
        setup();
        
        }          
}

void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }       
        add_action("do_flatter", "flatter");
        add_action("do_xian", "xian");
        add_action("do_da", "da");
}

void greeting(object me)
{
        mapping myfam;
        int shen;
        
        if(!me || environment(me) != environment(this_object())) return;
        
        shen = me->query("shen");

        if(!myfam = (mapping)me->query("family")) 
                command("say 你千里迢迢来天山, 莫不是想加入我星宿派？");
        else if(myfam["family_name"] != "星宿派" ){
                if(!me->query_temp("xx_job"))
                        command("say 你千里迢迢来到天山，是仰慕本老仙我的仁德吧？");
                else    command("nod " + me->query("id"));
        }
        
        else if(shen > -1000 && shen < 0) 
                command("say 你怎么搞的？搅和了一身的白道气息！");
        else if(shen > 0 && shen < 100000) 
                command("say 好哇！你敢和白道的人搅和，不想活了是不是？");
        else if(shen > 100000){
                command("say 你竟敢和白道的人搅和！从我这里滚出去吧！");
                command("expell " + me->query("id"));
        }
        else command("say 好徒儿，功夫练得怎么样了？");
}

void attempt_apprentice(object me)
{
        if(me->query("family/family_name") != "星宿派"){
                say("老仙对"+me->name()+"理都不理。\n");
                return;
        }
        if ((int)me->query("shen") > -50000) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }
        
        if ((int)me->query("xx_points") < 500) {
                command("say 你应该多多为老仙我分担分担忧愁才是。");
                return;
        }
        
        if(me->query_skill("huagong-dafa",1) < 180){
                command("say 看来你的化功大法基础还不够啊，先去跟我徒儿学学吧。");
                return;
        }
        
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        }
         
        else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等$N拍马(flatter)的样子。\n", me);
                me->set_temp("pending/flatter", 1);
        }
              
}
int do_flatter(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        
        if( !arg ) return notify_fail("你要赞扬老仙的什么丰功伟绩？\n");
        if(me->query_condition("gb_mission") || me->query_condition("gb_busy"))
                return notify_fail("老仙最讨厌臭叫化子，先扔掉你的丐帮帮务再说！\n");
        if(this_player()->query("jing") < 10)
                return notify_fail("你太累了，等等再拍吧！\n");
                
        switch(random(5)) {
                case 0 : message_vision("\n$N对$n大声赞道：您老人家一蹬足天崩地裂，一摇手日月无光！\n", me,ob); break;
                case 1 : message_vision("\n$N对$n大声赞道：星宿老仙大袖摆动，口吐真言，叫旁门左道牛鬼蛇神，一个个死无葬身之地！\n", me,ob); break;
                case 2 : message_vision("\n$N对$n大声赞道：这天下武林盟主一席，非老仙莫属。只须老仙下令动手，小人赴汤蹈火，万死不辞！\n", me,ob); break;
                case 3 : message_vision("\n$N对$n大声赞道：日月无老仙之明，天地无老仙之大，自盘古氏开天辟地以来，更无第二人能有老仙的威德！\n", me,ob); break;
                case 4 : message_vision("\n$N对$n大声赞道：老仙神功盖世，天下第一，战无不胜，功无不克！\n", me,ob); break;
        }
       
        message_vision(HIY"$N大声唱道：" + arg + "\n"NOR, this_player());
        this_player()->set("jing", 1);
        if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
         && strsrch(arg, "威震寰宇") >=0 && strsrch(arg, "古今无比") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                if(this_player()->query_temp("pending/flatter")){
                        this_player()->delete_temp("pending/flatter");
                        command("recruit " + this_player()->query("id"));
                        CHANNEL_D->do_channel(this_player(), "chat",  "星宿老仙，德配天地，威震寰宇，古今无比！");
                        return 1;
                }
                else{
                        command("say 你对老仙我这么恭敬，今后前途不可限量啊！\n");
                        this_player()->set_temp("ding_flatter", 1);
                        return 1;
                }       
        }
         
        else command("say 没有了吗？");
        return 1;
}

int give_drug()
{
        object drug, me, ob;

        me = this_object();
        ob = this_player();
       
        if(ob->query("family/family_name") == "星宿派" && (ob->query_skill("huagong-dafa", 1) > 79)){
                if(me->query("drug_count") >= 1 && !ob->query_temp("drug_give")){
                        add("drug_count", -1);
                        drug = new("/d/xingxiu" + drugs[random(sizeof(drugs))] );
                        drug->move(ob);
                        ob->set_temp("drug_give", 1);
                        message_vision("$N对$n点了点头，交给$n一小包药粉。\n", me, ob);
                        return 1;
                }
                if(ob->query_temp("drug_give")) 
                        command("say 我不是给过你了吗？");
                else command("say 你来晚啦，都被你师兄们拿走了。");
                return 1;
        }
        else return 0;
}

string ask_gou()
{
        object me=this_player();
        if(me->query("family/family_name") != "星宿派")
           return "寒玉钩乃我派至宝，岂能胡乱给人，你还是速速离去吧！";

        if (present("hanyu gou", me))
            return "寒玉钩不就在你身上吗！";

        if(me->query_temp("xx/pass") > 0 )
           return "你已经通过测试了，还不快去给我办妥那件事！";

        if(me->query_temp("xx/lost") > 0 )
           return "你都接不了我三招，我岂能把这么贵重的宝物交给你！";

        if(me->query("combat_exp") < 600000)
           return "你武功未成，还是再多练几年吧！";

        if(me->query_skill("huagong-dafa",1) < 180)
           return "你的化功大法基础还不够啊，我可不放心给你！";

        me->set_temp("xx/test",1);
        command("say 好吧，如果你真想要寒玉钩，需接我三招，再为我做一件事情，你愿意吗？(da 愿意)");
        return "但是你可得想好了，要是被我打死可得你自己负责哦！";
}
int do_da(string arg)
{
        object weapon,me,target;
        me = this_object();
        target = this_player();
        weapon = me->query_temp("weapon");
        
        if(!target->query_temp("xx/test") )
             return notify_fail("什么？\n"); 
        if(!arg || arg != "愿意") 
             return notify_fail("什么？\n");
              
        else{
        	message_vision(CYN"丁春秋发出一阵阴笑，接着飞起一脚踢中$N的屁股！\n"NOR,target);
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        }

        if(target->query("eff_qi")>target->query("max_qi")/3
         &&target->query("qi")>target->query("max_qi")/3){
              	command("say 噢... 你武功还马马乎乎！");
              	command("say 这样吧，你去把宋远桥杀了，尸体带回来给我，然后...");
              	target->set_temp("xx/pass",1);
              	target->delete_temp("xx/test");
        }
        else{ 
             	target->set_temp("xx/lost",1);
             	target->delete_temp("xx/test",1);
             	command("say 呸...！什么玩意儿嘛，再去给我多练练！");
        }
        return 1;        
}

int accept_object(object who, object ob)
{
        object gou, me,weapon;
        mapping fam;
        who = this_player();
        me = this_object();
        fam = who->query("family");
        weapon = me->query_temp("weapon");
        if (!fam || fam["family_name"] !="星宿派"){
             	command("? "+ (string)who->query("id"));
             	call_out("dest", 1, ob);
             	return 1;
        }
        if(ob->query("id") == "hanyu gou"){
             	command("pat "+ (string)who->query("id"));
             	return 1;
        }

        if(ob->query("id") != "corpse"){
             	command("? "+ (string)who->query("id"));
             	command("say 你给我这个干什么？");
             	call_out("dest", 1, ob);
             	return 1;
        }
        if( !who->query_temp("xx/pass")) {
             	command("? "+ (string)who->query("id"));
             	call_out("dest", 1, ob);
             	return 1;
        }
        if ( ob->query("victim_id") != "song yuanqiao" ){
             	command("? "+ (string)who->query("id"));
             	call_out("dest", 1, ob);
             	return 1;
        }
        if(ob->query("kill_by") != who){
             	command("kick "+ (string)who->query("id"));
             	command("say 哼…！这个人不是你杀的，休想我给你寒玉钩！");
             	call_out("dest", 1, ob);
             	return 1;
        }
        if ( ob->query("victim_user") ){
             	command("consider "+ (string)who->query("id"));
             	command("say 小子活得不耐烦了？");
             	COMBAT_D->do_attack(me, who, me->query_temp("weapon"), 1);
             	call_out("dest", 1, ob);
             	return 1;
        }
        command("nod "+who->query("id"));
        
        if (present("hanyu gou", me)){
                command("give gou to "+(string)who->query("id"));
                command("say 拿去吧，小心保管！");
                who->delete_temp("xx/pass");
                call_out("dest", 1, ob);
                return 1;
        }
        else{
                gou = unew("/clone/weapon/hanyu-gou");
                if (!clonep(gou)) {
                    	command("say 寒玉钩现在不在我手上。");
                    	call_out("dest", 1, ob);
            		return 1;
                }
                gou->move(this_player());
                command("say 要是丢了，小心你的性命！");
                who->delete_temp("xx/pass");
                call_out("dest", 1, ob);
                return 1;
       }
}

string ask_job()
{
        object me, ob;
        me = this_player();
 
        if (me->query("family/family_name") == "武当派"
         || me->query("family/family_name") == "天龙寺"
         || me->query("family/family_name") == "娥眉派"
         || me->query("family/family_name") == "华山派"
         || me->query("family/family_name") == "少林派")
                return "你是白道来卧底的吧，还不快给我滚出去！！！";
        if (!me->query("family") || me->query("family/family_name") != "星宿派") 
                return "看你对老仙态度恭敬，何不加入我星宿派呢？";
        if( me->query("combat_exp") < 1000000) 
                return "哈哈哈，你再加把力练功，很快就可以为老仙我分忧了。";
        if(me->query("shen") >= 0 || me->query("shen") > -(me->query("combat_exp")/10)) 
                return "徒儿，看来你的心肠还不够黑啊，有些事你不问也罢。";
        if(interactive(me) && me->query_temp("job_busy")) 
                return "你说要替老仙分忧，怎么还在这里发呆？";
        if (interactive(me) && me->query_condition("wait_xx_task")) 
                return "老仙现在心情还好，不用你来为我分忧。";

        ob = new("/d/xingxiu/obj/di");
        ob->move(me);
        ob->set("name", BLU"蓝玉短笛"NOR);
        ob->set("long", BLU"这玉笛短得出奇，只不来七寸来长、通体碧蓝，晶莹可爱。\n" NOR);
        ob->set("xx_user", getuid(me));
        me->set_temp("xx_job", 1);
        message_vision("$N拿出一只玉制短笛，交给$n。\n", this_object(), me);
        return "老仙我最近心情不佳，徒儿你要多多为我分忧才是！\n";    
}

void destroying(object obj, object me)
{
        message_vision("$N拿起$n仔细地端详了一会儿，满意地点了点头，脸上露出了笑容。\n", me, obj);
        destruct(obj);
}

void dest(object ob)
{     
    	if (!ob) return;
    	if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
    	else destruct(ob);
}


int do_xian(string arg)
{
        object who, me, ob;
        mapping quest;
        who = this_player();
        me = this_object();

        if(who->is_busy() || who->is_fighting()) 
                return notify_fail("你正忙着呢。\n");
        if(me->is_busy() || me->is_fighting()) 
                return notify_fail("没看见老仙正忙着吗？\n");
        if(!arg || !objectp(ob = present(arg, who))) 
                return notify_fail("你要献给老仙什么东西？\n");
        if(!who->query_temp("xx_job")) 
                return notify_fail("连老仙现在的心情还没摸清楚就乱献东西？\n"); 
           
        message_vision(HIY"\n$n毕恭毕敬地将"+ob->query("name")+HIY"拿出，双手捧上，想要献给$N。\n\n"NOR, me, who);
 

        if(me->is_busy()) {
                command("say 我正忙着呢，你等等。");
                return notify_fail("老仙让你等等。\n");
        }
    
        if(!mapp(quest = who->query_temp("quest")) || !quest["id"]){
                command("say 你拿个"+ob->name()+CYN"给我干嘛？"NOR);
                return notify_fail("老仙对这东西不感兴趣。\n");
        }
         
        if ( quest["time"] < TIME_TICK){
                command("say 嗯，这么久才办完，你干什么去了？给我滚一边去！");
                who->apply_condition("wait_xx_task", 40);
                return notify_fail("完了，老仙生气了。\n");
        }
        
        if(userp(ob)){
                command("stare " + who->query("id"));
                command("say 竟敢用假货来欺骗本老仙，给我滚出去！");
                message_vision("\n说完$N长袖一挥，一股内劲拂出，就将$n扫出洞外！\n\n", me, who);
                who->move("/d/xingxiu/ryd1");
                message("vision","只听“呼”地一声，紧接着"+who->query("name")+"从日月洞里直飞了出来，摔了个四脚朝天！\n", environment(who), who);
                who->receive_wound("jing", 200);
                who->receive_wound("qi", 250);
                who->receive_damage("neili", 600);
                who->receive_damage("jingli", 500);
                who->apply_condition("wait_xx_task", 30);
                who->delete_temp("quest");
                who->set_temp("last_id", quest["last_id"]);  
                who->start_busy(5);
                return notify_fail("糟糕，穿邦了！\n");
        }
        if(ob->query("name") != quest["name"] || ob->query("id") != quest["id"]) {
                command("hmm " + who->query("id"));
                command("say 你拿个"+ob->query("name")+"给老仙我有什么用？");
                return notify_fail("好象是你献错东西了。\n");
        }
        
        ob->move(me);
        me->start_busy(2);
        who->start_busy(2);
        destroying(ob, me);
        call_out("done", 3, who);        
        return 1;
    
}

void done(object me)
{
        if(!me || environment(me) != environment(this_object())) return;
        
        command("pat " + me->query("id"));       
        command("say 不错不错，既然你找到了老仙我想要的东西，我就指点指点你吧。");
        if(me->query("family/family_name") == "星宿派") {
                if(me->query_skill("huagong-dafa",1) < 180) 
                        me->improve_skill("huagong-dafa", me->query("xx_points")*4);   
                if(me->query_skill("poison",1) < 180) 
                        me->improve_skill("poison", me->query("xx_points")*4);
                me->add("xx_points", 1);          
                tell_object(me, "你目前已经为老仙分担了"+chinese_number(me->query("xx_points"))+"次忧愁。\n");
        }
        
        tell_object(me, "你听了老仙的指点，功夫进步了不少！\n"); 
        TASK_D->give_reward(me, me->query_temp("quest"), -1, ABS(me->query("xx_points")/25));
        log_file("job/xx_job",sprintf("%-18s 做星宿JOB于 %s ，得经验 %d，潜能 %d。\n", 
		me->query("name")+"("+getuid(me)+")",  ctime(time()), 
		me->query_temp("quest/exp_reward"), me->query_temp("quest/pot_reward")));
        me->apply_condition("job_busy", 3);  
                       
}
