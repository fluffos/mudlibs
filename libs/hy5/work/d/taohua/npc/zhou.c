// zhou.c 周伯通

#include <ansi.h>
#include <skill.h> 
inherit NPC;
string *questions = ({
	"西毒欧阳峰的绝技是什么？",
	"洪老叫花那个最具威力的掌法是什么？",
	"黄老邪打赌赢我用的功夫是什么？",
	"老哥哥我左手右手打着玩的功夫是什么？",
	"我师兄的无上内功心法是什么？",
	"我教最神奇的剑阵是什么？",
	"铁掌裘千仞的轻功是什么？",
	"西毒蛤蟆功的克星是什么？",
	"黄老邪是用什么奇学把我关在这里的？",
	"洪老叫花的打狗棒法中最具威力的一式是什么？",
	"杨过小兄弟自创的功夫是什么？",
	"天龙寺的镇寺武学是什么？",
	"逍遥派的那个能吸敌人内力的功夫是什么？",
	"段誉最拿手的轻功是什么？",
	"风老头教令狐冲的剑法是什么？",
	"明教的镇教武学是什么？",
	"洪老叫化的降龙十八掌中最具威力的一招是什么？",
	"白猿腹中的经书里记载的是什么武学？",
	"黄老邪的两个小徒弟偷学了九阴真经里什么武功？",
	"老哥哥我自创的独门拳法是什么？"});
int ask_jieyi();
int ask_hubo();
int do_fangyuan();
int do_learn(string arg);
int ask_jiuyin();
int ask_story();
int ask_story2();
int ask_quest();
int do_answer(string arg);
int ask_kungfu();

void create()
{
        set_name("周伯通", ({ "zhou botong", "zhou", "bo tong" }));
        set("gender", "男性");
        set("nickname", CYN "老顽童" NOR ) ;
        set("title", "全真教第一代弟子") ;
        set("age", 45);
        set("long",
        "他就是人称「老顽童」的周伯通。\n"
        "他本来是全真教掌门人的师弟，武功高强，但现在却被人囚禁在\n"
        "这小小山洞之中，头发胡子长长的，毛茸茸的象一个野人。\n",
        );

        set("no_get",1);
        set("combat_exp", 9000000);
        set("shen_type", 1);
        set("double_attack", 1);
        set("max_neili", 35000);
        set("neili", 35000);
        set("jiali", 0);
        set("qi", 36500);
        set("max_qi", 36500);
        set("jing", 35400);
        set("max_jing", 35400);
        set("neili", 59000);
        set("max_neili", 59000);
        set("jiali", 100);

        set("combat_exp", 8000000);
        set("score", 500000);
        set_skill("cuff", 300);
        set_skill("strike", 300);
        set_skill("force", 300);
        set_skill("sword", 300);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hubo" ,300);
        set_skill("qixing-array",380);
        set_skill("kongming-quan",380);
        set_skill("quanzhen-jian",350);
        set_skill("xiantian-qigong", 380);    //先天气功
        set_skill("haotian-zhang", 380);    //昊天掌
        set_skill("jinyan-gong", 380);   //金雁功
        map_skill("unarmed","kongming-quan");
        map_skill("parry","kongming-quan");
        map_skill("dodge","jinyan-gong");
        map_skill("force","xiantian-qigong");
        set("double_attack", 1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.ruo" :),                	                	
                (: exert_function, "powerup" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                
        }));
        set_temp("apply/attack", 200);
        set_temp("apply/defense",200);
        set_temp("apply/armor", 550);
        set_temp("apply/damage", 620);

        set("inquiry", ([
                "东邪": "是黄药师这个无耻的家伙，骗了我的九....去看。",
                "黄药师": "这个无耻的家伙，骗了我的九....去看。",
                "中神通": "我的师兄是天下武功最高的，第一次华山论剑时公推为第一高手。",
                "王重阳": "我的师兄是天下武功最高的，第一次华山论剑时公推为第一高手。",
                "周伯通": "找我有什么事吗？",
                "瑛姑": "四张机，鸳鸯织就欲双飞....",
                "刘瑛": "四张机，鸳鸯织就欲双飞....",
                "段皇爷": "老顽童做事对不起他，没脸再见他了。",
                "段智兴": "老顽童做事对不起他，没脸再见他了。",
                "南帝": "老顽童做事对不起他，没脸再见他了。",
                "老顽童": "我就是啊，找我有什么事吗？",
                "空明拳": "空明拳共七十二路，口诀是：空朦洞松、风通容梦、冲穷中弄、童庸弓虫。",
                "kongming-quan": "空明拳共七十二路，口诀是：空朦洞松、风通容梦、冲穷中弄、童庸弓虫。",
                "黄蓉": "是几个月前来陪我聊天的那个小姑娘吗？",
                "郭靖": "那是我的结义兄弟，人虽然傻，心肠倒好。",
                "方": "方要正方！",
                "fang": "方要正方！",
                "圆": "圆要浑圆！",
              	"九阴真经": (: ask_jiuyin :),
                "双手互搏": (: ask_hubo :),
                "左右互搏": (: ask_hubo :),
                "结义": (: ask_jieyi :),
                "结拜": (: ask_jieyi :),
                "故事": (: ask_story :),
                "后来怎样": (: ask_story2 :),
		"问题": (: ask_quest :),
		"功夫": (: ask_kungfu :),

        ]) );

        create_family("全真教", 1, "弟子");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob = this_player();
        add_action("do_fangyuan","fangyuan");
        add_action("do_draw","draw");
        add_action("do_draw","hua");
        add_action("do_learn","learn");
        add_action("do_learn","xue");
        add_action("do_answer","answer");
        ::init();
        if (ob->query("family/family_name") == "全真教") {
                command("angry " + ob->query("id"));
                command("say 怎么你到今天才来找我？！明天我就去和处机说让他打你屁股。");
        }
}

void kill_ob(object me)
{
        command("chat* crazy " + me->query("id"));
        ::kill_ob(me);
}

void unconcious()
{
        command("chat 叹道：老顽童今日是要归天了，到阴世玩玩两只鬼打架，那些大头鬼、无常鬼一定瞧得莫名其妙，鬼色大变。");
        ::unconcious();
}

int ask_story()
{
        object me = this_player();
        string msg;
	if (me->query_temp("jiuyin/fanhe") && !me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/shang-failed") < 3) {
	        msg = HIY"周伯通听到$N要他讲故事，登时兴高采烈。\n"NOR;
	        msg+= HIY"周伯通开始讲起九阴真经和黄裳的故事。\n"NOR;
	        msg+= HIW"周伯通看$N不问后来怎样，便赌气不说了。\n"NOR;
	        message_vision(msg, me);
	        me->delete_temp("jiuyin/fanhe");
	        me->set_temp("jiuyin/story",1);
	        return 1;
	}
        return 0;
}

int ask_story2()
{
        object me = this_player();
        string msg;
        if (me->query_temp("jiuyin/story")==1)
        {
                msg = HIY"周伯通一听$N问他后来怎样，又口沫横飞的说起来。\n";
                msg+= HIY"周伯通讲完又开始对$N说起他和全真教的故事。\n";
                msg+= HIW"$N听着，也学到了些全真教练气的皮毛。\n"NOR;
                msg+= HIC"周伯通说完故事，又无聊的问道：“兄弟，我来考你几个问题吧！\n"NOR;
                message_vision(msg, me);
                me->set_temp("jiuyin/story",2);
                return 1;
        }
        return 0;
}

int ask_jieyi()
{
        object ob=this_player();
        if (ob->query("zhou/jieyi")) {
                command("? " + ob->query("id"));
                command("say 咱俩不是结拜过了吗？");
                return 1;
        }
        if (ob->query("zhou/fail") >=3 ){
                command("hmm");
                command("say 我不是说了，我没兴趣和你结拜啊！");
                return 1;
        }
//        if (ob->query("age") > 30){
//                command("shake");
//                command("say 我老顽童只喜欢和青年人玩，和你结拜？没意思，没意思！");
//                return 1;
//        }
        if (ob->query("gender") != "男性" && ob->query("gender") != "女性") {
                if (ob->query("age") > 45) 
                        command("say 我本来也想与你结拜，就是不知是兄弟相称还是姐弟相称？");
                else
                        command("say 我本来也想与你结拜，就是不知是兄弟相称还是兄妹相称？");
                command("laugh");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ( ob->query("class") =="bonze" ){
                command("monk "+ ob->query("id"));
                command("say "+RANK_D->query_respect(ob)+"，老顽童我可没有兴趣和你结拜。");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ( ob->query_skill("literate", 1) > 100) {
                command("shake");
                command("say 你这个人鬼灵精，保不准打着什么主意呢。");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ((int)ob->query("shen") <= -1) {
                command("shake");
                command("say 我虽然天性随便，但师尊教诲不敢忘，于正邪之道还是要分清的。");
                ob->add("zhou/fail", 1);
                return 1;
        }
        if ( ob->query("combat_exp") < 100000){
                command("shake "+ ob->query("id"));
                command("say 这位"+RANK_D->query_respect(ob)+"你的武艺实在太糟糕了，我可没兴趣和你结拜。");
                return 1;
        }
        if (random(ob->query("kar")) < 20){
                command("shake");
                command("say 我现在没有空，要不你先陪我玩玩？");
                ob->add("zhou/fail", 1);
                return 1;
        }
        command("nod " + ob->query("id"));
        if (ob->query("gender") == "男性") {
                command("say 好吧，你我就结拜为兄弟吧。");
        }
        else if (ob->query("gender") == "女性") {
                if (ob->query("age") > 48) 
                        command("say 好吧，你我就结拜为姐弟吧。");
                else
                        command("say 好吧，你我就结拜为兄妹吧。");
        }
        message_vision("周伯通与$N并肩而跪，朗声说道：“老顽童周伯通，今日与" + ob->name() +"义结金兰，日后有福共享，有难共当。\n"+
                       "若是违此盟誓，教我武功全失，连小狗小猫也打不过。”\n", ob);
//        log_file("ZHOU",sprintf("%s(%s)与周伯通结拜于： %s\n",ob->name(1), getuid(ob), ctime(time())));
        ob->set("zhou/jieyi", 1);
        return 1;
}

int ask_jiuyin()
{
        object me=this_player();
	object ob;

	if (me->query("jiuyin/full")) {
		if(present("jiuyin zhenjing", me)) {
	                command("? " + me->query("id"));
	                command("say 不是已经给你了吗？");
	                return 1;
	        } else {
			ob = new("/clone/book/jiuyin-book.c");
			ob->move(me);
			message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到《九阴真经》啦。\n"NOR, users());
	                command("say 好好保管，掉了可别再来找我了。");
			return 1;
		}
	}
        command("say 你打听这个干什么？！");
        return 1;
}

int ask_hubo()
{
        object ob=this_player();
        int hubo;
        if(!ob->query("zhou/jieyi")){
                tell_object(ob,"周伯通正盯着你看，不知道打些什么主意。\n");
                command("say 你是谁啊，怎么莫名其妙地问我双手互搏的事啊？");
                return 1;
        }               
        if (ob->query("double_attack")) {
                command("? " + ob->query("id"));
                command("say 你不是已经学会了吗？");
                return 1;
        }
        if(ob->query("zhou/failed") >= 3){
                command("disapp " + ob->query("id"));
                command("say 已经试了这么多次，看来你一辈子也练不会这门功夫了。");
                return 1;
        }
        hubo = ob->query_temp("zuoyou_hubo");
        if (hubo == 22) {
                command("say 接着练第一课！");
                return 1;
        }
        if (hubo == 1) {
                command("say 让你练你就快练嘛！");
                return 1;
        }
        if (hubo > 1 && hubo <= 21) {
                command("say 怎么样，练不会吧？就象黄蓉那女孩儿玲珑剔透，一颗心儿上生了十七八个窍，可是这门功夫她便始终学不会！");
                return 1;
        }
        if (ob->query_skill("force") < 100 || ob->query("max_neili") < 500 || ob->query("combat_exp") < 10000) {
                command("say 你还是先打好武学基础再说吧。");
                return 1;
        }
        command("say 这门功夫是我在洞中无聊之时想出来的玩意儿，说难是难到极处，说容易也容易之至。\n"+
                "有的人一学便会，有的人一辈子也学不了，越是聪明，越是不成。");
        command("say 你先练练这第一课：左手画方(fang)，右手画圆(yuan)。");
        ob->set_temp("zuoyou_hubo", 1);
        return 1;
}


int do_fangyuan()
{
        object ob=this_player();
        int hubo;
        if (ob->is_busy() || ob->is_fighting()) return notify_fail("你正忙着呢！\n");
        hubo = ob->query_temp("zuoyou_hubo");
        ob->start_busy(1);
        if (!hubo) return 0;
        if (hubo < 21) {
                message_vision("$N伸出两根食指在地上划画，但画出来的方块有点象圆圈，圆圈又有点象方块。\n", ob);
                ob->add_temp("zuoyou_hubo", 1);
                return 1;
        }
        if (hubo == 21) {
                message_vision("$N伸出两根食指在地上划画，但画出来的方块有点象圆圈，圆圈又有点象方块。\n", ob);
                command("haha " + ob->query("id"));
                command("say 是么？你这一下便办不到！");
                ob->add_temp("zuoyou_hubo", 1);
                return 1;
        }
        if (hubo == 22) {
                if ( ob->query("kar") > 40 ){
                    if( random(ob->query("kar")) > 30 && random(20)==0){
                        message_vision("$N微微一笑，凝神守一，心地空明，随随便便的伸出双手手指，左手画了一个方块，右手画了一个圆圈，\n"+
                                       "方者正方，圆者浑圆。\n", ob);
                        say("周伯通大吃一惊，过了半晌才道：“这定是你从娘胎里学来的本领，那便易办了。”\n");
                        message_vision("周伯通将他领悟出来的这门天下无比的奇功，一古脑儿都教给了$N。\n", ob);
                        ob->delete_temp("zuoyou_hubo");
//                        log_file("ZHOU",sprintf("%s(%s)从周伯通处领悟到双手互搏于： %s\n",ob->name(1), getuid(ob), ctime(time())));
                        ob->set("double_attack", 1);
                        return 1;
                    }
                    else {
                        ob->delete_temp("zuoyou_hubo");
                        message_vision("$N又伸出两根食指在地上划画，但画出来的仍旧是方块有点象圆圈，圆圈又有点象方块。\n", ob);
                        write("看来并不是这么简单。\n");
                        ob->add("zhou/failed", 1);
                        return 1;
                    }
                }
                message_vision("$N又伸出两根食指在地上划画，但画出来的仍旧是方块有点象圆圈，圆圈又有点象方块。\n", ob);
                message_vision("$N终于发现自己是一辈子也练不会这门功夫了。\n", ob);
                ob->delete_temp("zuoyou_hubo");
                ob->add("zhou/failed", 1);
                command("disapp " + ob->query("id"));
                return 1;
        }
        return 0;
}

int do_draw(string arg)
{
        object ob=this_player();

        if (!ob->query_temp("zuoyou_hubo")) return 0;
        if (arg == "fang" || arg == "方" || arg == "yuan" || arg == "圆") return notify_fail("周伯通怒道：让你同时画方圆！\n");
        if (arg == "fang yuan" || arg == "方圆") return do_fangyuan();
        return 0;
}

int do_learn(string arg)
{
        object me=this_player();
        string skill, teacher, skill_name;
        object ob;
        int master_skill, my_skill, gin_cost, rand;

        if (me->is_busy())
                return 0;

        if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
                return 0;

        if (teacher != "zhou" && teacher != "botong")
                return 0;

        if( me->is_fighting() )
                return 0;

        if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
                write("你要向谁求教？\n");
                return 1;
        }

        if( !living(ob) ) {
                write("嗯....你得先把" + ob->name() + "弄醒再说。\n");
                return 1;
        }

        if( !me->query("zhou/jieyi")) {
                write("周伯通奇怪地看着你，问道：你是谁呀？\n");
                return  1;
        }

        if (skill != "kongming-quan" && skill != "空明拳") {
                write("这项技能你恐怕必须找别人学了。\n");
                return 1;
        }

        my_skill = me->query_skill(skill, 1);
        master_skill = ob->query_skill(skill, 1);
        if( my_skill >= master_skill ) {
                write("你在空明拳上的造诣已经不下老顽童了！\n");
                return 1;
        }

        if( !SKILL_D(skill)->valid_learn(me) ) {
                write("你必须是空手并且有足够的内功和内力才可以学习空明拳。\n");
                return 1;
        }

        gin_cost = 150 / (int)me->query("int");

        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }

        rand = random(20);
        if (rand == 4)
                gin_cost *= 2;
        else if (rand == 15)
                gin_cost += 4;
        if( (int)me->query("potential") < 1 ) {
                write("你的潜能已经发挥到极限了，没有办法再学了。\n");
                return 1;
        }

        message_vision("$N向$n请教有关「空明拳」的问题。\n", me, ob);

        if( (int)me->query("jing") > gin_cost ) {
        write("周伯通念道：老子《道德经》里有句话道：“埏植以为器，当其无，有器之用。凿户牖以为室，当其无，有室之用。”\n");
                write("周伯通吟口诀道：大成若缺，其用不弊，大盈若冲，其用不穷。\n");
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        write("也许是缺乏实战经验，你对老顽童的讲解总是无法领会。\n");
                } 
                else {
                        if (rand == 13) {
                                write("就在你试图领悟其中道理的时候，老顽童忽然在你旁边大做鬼脸，又故意放了个屁来捣乱，搞得你心烦意乱。\n");
                                write("结果你什么都没学到。\n");
                                return 1;
                        }
                        else if (rand == 5) {
                                write("周伯通讲解了两句，忽然不耐烦起来，拉着你道：“咱俩玩四个人打架可好？”\n");
                                write("结果你只好陪他玩耍了一阵。\n");
                                return 1;
                        }
                        else if (rand == 4) {
                                write("就在你试图领悟其中道理的时候，老顽童忽然在你旁边大做鬼脸，又故意放了个屁来捣乱，搞得你心烦意乱。\n");
                                write("结果你花了比平常多一倍的精力。\n");
                        }
                        else if (rand == 15) {
                                write("就在你试图领悟其中道理的时候，老顽童忽然在你旁边大做鬼脸，又故意放了个屁来捣乱，搞得你心烦意乱。\n");
                                write("结果你花了比平常多得多的精力。\n");
                        }
                        if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                                write("你听了老顽童的指导，对「" + skill_name + "」这一招似乎有些心得。\n");
                        else
                                write("你听了老顽童的指导，似乎有些心得。\n");
                        me->add("potential", -1);
                        me->improve_skill(skill, random(me->query_int()));
                }
	}
        else {
                gin_cost = me->query("jing");
                write("你今天太累了，结果什么也没有学到。\n");
        }

        me->receive_damage("jing", gin_cost );

        return 1;
}

void finish(object me)
{
	me->delete_temp("jiuyin/asking");
	me->delete_temp("jiuyin/question");
	me->delete_temp("jiuyin/story");
	if (me->query_temp("jiuyin/count") > 0 && random(me->query_temp("jiuyin/count")) > 10 && !random(20)) {
		me->delete_temp("jiuyin/count");
		me->set_temp("jiuyin/passed", 1);
		command("admire " + me->query("id"));
		command("say 原来我们是同道中人啊。");
		command("hoho");
		message_vision("\n", me);
		command("say 你陪我陪了这么久，一定很无聊吧？");
		command("hmm");
		command("ah " + this_object()->query("id"));
		command("say 这样吧，我教你点好玩的功夫！");
		command("grin");
	} else {
		me->delete_temp("jiuyin/count");
		me->add("jiuyin/shang-failed", 1);
		command("disapp");
		command("say 真可惜，你的见闻实在太差，下次再来陪我玩吧。");
	}
}

int ask_quest()
{
        object me = this_player();
        if (me->query_temp("jiuyin/story") == 2)
        {
		if (me->query_temp("jiuyin/asking")) {
			command("say 我们不是正在玩么？专心点！");
			command("kick " + me->query("id"));
	                return 1;
		}
		me->set_temp("jiuyin/asking", 1);
		me->set_temp("jiuyin/count", 0);
		command("say 准备好，我们开始啦！");
	 	call_out("ask_question", 1, me);
	 	call_out("finish", 60, me );
		return 1;
        }
        return 0;
}

int do_answer(string arg)
{
        object me = this_player();
        string answer;

	if (!me->query_temp("jiuyin/asking") || !me->query_temp("jiuyin/question"))
		return 0;
        if( !arg || arg=="" ) {
           write("想好答案再回答。\n");
           return 1;
        }
        switch ((int) me->query_temp("jiuyin/question")) {
          case 1: answer="hamagong"; break;
          case 2: answer="xianglong-zhang"; break;
          case 3: answer="tanzhi-shentong"; break;
          case 4: answer="hubo"; break;
          case 5: answer="xiantian-qigong"; break;
          case 6: answer="qixing-array"; break;
          case 7: answer="shuishangpiao"; break;
          case 8: answer="yiyang-zhi"; break;
          case 9: answer="qimen-wuxing"; break;
          case 10: answer="wugou"; break;
          case 11: answer="anran-zhang"; break;
          case 12: answer="six-finger"; break;
          case 13: answer="beiming-shengong"; break;
          case 14: answer="lingboweibu"; break;
          case 15: answer="lonely-sword"; break;
          case 16: answer="qiankun-danuoyi"; break;
          case 17: answer="kanglongwuhui"; break;
          case 18: answer="jiuyang-shengong"; break;
          case 19: answer="jiuyin-baiguzhua"; break;
          case 20: answer="kongming-quan"; break;
        }
	if (arg == answer) {
		me->add_temp("jiuyin/count", 1);
		command("say 不错不错，有点头脑嘛。");
		command("praise " + me->query("id"));
	} else {
		me->add_temp("jiuyin/count", -1);
		command("say 错！");
		command("papaya " + me->query("id"));
	}
	command("say 再来一题吧。");
	me->delete_temp("jiuyin/question");
 	call_out("ask_question", 1, me);
        return 1;
}

void ask_question(object me)
{
	int quest;
	if (me->query_temp("jiuyin/asking")) {
		message_vision("\n", me);
		command("say 注意听好了！");
		message_vision(HIW"用 answer 来回答，回答请使用拼音输入，不要用汉字。\n"NOR, me);
		quest = random(20);
		command("say " + questions[quest]);
		message_vision("\n", me);
		me->set_temp("jiuyin/question", quest+1);
	}
	return;
}

int accept_object(object who, object ob)
{
	if ((string)ob->query("id") == "fan he") {
		command("say 是黄老邪的小丫头叫你帮忙送饭来么？");
		message_vision(HIC"周伯通不等$N回答，已经开始将食物塞进嘴中。\n"NOR, who);
		message_vision(HIC"周伯通吃完，干笑了一下，才对$N问道：“不知道你吃过了没有？\n"NOR, who);
		command("say 黄老邪想要我的九阴真经，把我关了十五年啦。");
		command("sing3");
		command("say 你想不想听听我说故事？");
		call_out("destroying", 1, ob);
		who->set_temp("jiuyin/fanhe", 1);
		return 1;
	}
	if (who->query("jiuyin/xia") && (string)ob->query("id") == "jiuyin xiajuan") {
		command("ah " + who->query("id"));
		command("say 这正是我被黄老邪骗去的九阴真经下卷。");
		command("say 不知道你有没有拿到上卷呢？");
		call_out("destroying", 1, ob);
		who->set_temp("jiuyin/give", 1);
		return 1;
	}
	if (who->query("jiuyin/shang") && (string)ob->query("id") == "jiuyin shangjuan") {
		if (!who->query_temp("jiuyin/give")) {
			command("say 这本九阴真经上卷你不想要了？");
			return 0;
		}
		who->delete_temp("jiuyin/give");
		call_out("destroying", 1, ob);
		message_vision(HIC"周伯通将手上的九阴真经的上卷和下卷合而为一。\n"NOR, who);
		command("say 兄弟，我就把这本九阴真经交给你了，你可要好好保管它！");
		who->delete("jiuyin/shang");
		who->delete("jiuyin/xia");
		who->set("jiuyin/full", 1);
		new("/clone/book/jiuyin-book.c")->move(who);
		message("channel:rumor", MAG"【谣言】某人："+who->query("name")+"拿到《九阴真经》啦。\n"NOR, users());
		return 1;
	}
	return 0;
}

void destroying(object obj)
{     
	if (!obj) return;
	destruct(obj);
}

int ask_kungfu()
{
        object me = this_player();
	if (me->query_temp("jiuyin/passed")) {
		me->delete_temp("jiuyin/passed");
		command("say 这些功夫是我自己的创作，可厉害的很啊。");
		if (me->query("kar") > 40 && random(10) == 0) {
			command("say 上次我碰巧误闯入黄老邪的五行阵，就把书藏在那里了。");
			command("say 本来想自己去拿的，谁知道那个五行阵很邪，差点把老命送在那里了。");
			command("say 我看小兄弟的运气好象不错，你自己去试试吧！");
			me->delete("jiuyin/shang-failed");
			me->set("jiuyin/shang", 1);
		} else {
			command("heihei " + this_object()->query("id"));
			message_vision(HIC"周伯通却只是告诉$N如何施展，完全不演练给$N看。\n", me);
			message_vision("$N无论怎么练习就是无法成功。\n"NOR, me);
			command("sigh");
			command("say 我这高深武功，你大概别想学了吧。");
			me->add("jiuyin/shang-failed", 1);
		}
		return 1;
	}
	return 0;
}
