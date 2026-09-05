// laozu.c 血刀老祖
// by iceland

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

string get_place(string str);

string ask_job();
string ask_xuedao();
string ask_times();
string ask_fail();
string ask_offer();

void create()
{
        object weapon;
        set_name("血刀老祖", ({ "xuedao laozu", "laozu","xuedaolaozu" }));
        set("long",@LONG
他身材高瘦，眼窝深陷，一双眼睛射出凶狠的光芒，令人不敢直视。他在江湖
中以残忍好色而著称，曾凭一手血刀经的功夫斗败无数中原的武林豪杰。
LONG
        );
        set("title", HIR "大轮寺血刀门掌门" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 6000);
        set("max_jing",5000);
        set("max_jingli", 3000);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 150);
        set("combat_exp", 2900000);
        set("score", 500000);
        set("shen", -190000);
        set("unique", 1);

         set_skill("huanxi-chan", 300);
        set_skill("literate", 300);
        set_skill("force", 400);
        set_skill("longxiang-boruo", 400);
        set_skill("dodge", 400);
        set_skill("yuxue-dunxing", 400);
        set_skill("claw", 400);
        set_skill("tianwang-zhua", 400);
        set_skill("hand", 400);
        set_skill("dashou-yin", 400);
        set_skill("blade",400);
        set_skill("xuedao-jing",400);
        set_skill("parry", 400 );
        set_temp("apply/force",60);
        set_temp("apply/blade",80);
        set_temp("apply/claw",80);
        set_temp("apply/hand",80);
        set_temp("apply/dodge",90);

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xuedao-jing");
        map_skill("claw", "tianwang-zhua");
        map_skill("blade", "xuedao-jing");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 10, "弟子");
        set("class", "huanxi");

        set("env/jixue",10);
        set_temp("xs/shield",1);
        set_temp("xs/longxiang",1);
        set("chat_chance", 2);
        set("chat_msg", ({
"血刀老祖抬起头，若有所思的自言自语：“月亮快圆了，得下山杀个人祭祭刀了。”\n",
"血刀老祖恨恨的说：“什么时候再入中原，再闹个天翻地覆！”\n",
"血刀老祖咬牙切齿，眼露凶光的说：“下次来个斩草除根，一个活口也不留！”\n",
"血刀老祖自言自语道：“年纪大了，体力可一点也不含糊。”言下甚为得意。\n",
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jixue" :),
                (: perform_action, "blade.shendao" :), 
        }));

        set("inquiry", ([
                "工作"  : (: ask_job :),
                "job"   : (: ask_job :),
                "次数"  : (: ask_times :),
                "供奉"  : (: ask_times :),
                "美女"  : "我最喜欢美女啦，你要是能弄几个来孝敬爷爷，hehehe...",
                "girl"  : "我最喜欢美女啦，你要是能弄几个来孝敬爷爷，hehehe...",
                "beauty":"我最喜欢美女啦，你要是能弄几个来孝敬爷爷，hehehe...",
                "beast": "哇噻，给你看出来。我当然就是beast了，快去把我的beauty弄来！",
                "血刀"  : (: ask_xuedao :),
                "xuedao":(: ask_xuedao :),
                "放弃" :(: ask_fail :),
                "fangqi":(: ask_fail :),
                "奖励":(: ask_offer :),
       ]));

        setup();
	carry_object("/d/dalunsi/npc/obj/longxiang-jiasha")->wear();
        if (clonep()){
		if(!weapon) weapon=new("/d/dalunsi/npc/obj/xinyuedao");
                weapon->move(this_object());
                weapon->wield();

weapon=new("/d/dalunsi/npc/obj/xinyuedao");
                weapon->move(this_object());
weapon=new("/d/dalunsi/npc/obj/xinyuedao");
                weapon->move(this_object());
        }

        add_money("gold",5);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) + "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
                command("say 我大轮寺各种武功均和内功相辅相成。");
                command("say"+ RANK_D->query_respect(ob) + "再熬几个通宵，多多钻研钻研本门的心法吧。");
                return;
        }

        if( (string)ob->query("gender") == "无性" ) {
                command("say"+ RANK_D->query_respect(ob)+ "身体残缺，如何随我修炼？\n");
                return;
        }
        if ((int)ob->query("shen") > -100000) {
                command("hmm");
                command("say 我血刀老祖声名远扬，那些所谓的江湖大侠哪个不是望风而逃？");
                command("say 以你现在的资历，如果收你为徒，恐怕会被人耻笑。");
                return;
        }
        command("say 老祖我就喜欢你这样的年轻人。好，就收你为我弟子吧。");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "大轮寺血刀老祖亲传弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, HIR "大轮寺血刀老祖亲传弟子" NOR);
}

int accept_object(object me, object ob, object who)
{
        int e,p,shen,count;

        if(ob->query("id") != "beauty"){
                command("? "+ (string)me->query("id"));
                command("say 你给我这个干什么？");
                call_out("destroying", 1, ob);
                return 1;
        }

        if( !me->query("xs/girl")) {
                command("? "+ (string)me->query("id"));
                call_out("destroying", 1, ob);
                return 1;
        }

        if(me->query("xs/girl_ob") != ob){
                command("kick "+ (string)me->query("id"));
                command("disapp "+ (string)me->query("id"));
                command("say 这不是我要你抓的女人，你这个蠢货！");
                call_out("destroying", 1, ob);
                return 1;
        }

        if( !ob->query("hhs") ){
                command("kick "+ (string)me->query("id"));
                command("consider "+ (string)me->query("id"));
                command("say 你似乎在利用BUG!!!");
                call_out("destroying", 1, ob);
                write_file( "/log/job/xs_job",sprintf("%s %s(%s)似乎在利用BUG！\n",
                        ctime(time())[4..19],me->name(),me->query("id")));
                return 1;
        }

        command("hehe");
        command("say 不错不错，今天又有事情干了。你给爷爷做事，爷爷也不会亏待你的。");
        call_out("destroying", 1, ob);

        count = me->query("xs_job",1);
        if(count < 100)     e = 300 + random(20);
        else if(count < 200)     e = 310 + random(30);
        else if(count < 500)     e = 320 + random(40);
        else if(count < 1000)    e = 340 + random(60);
        else if(count < 2000)    e = 360 + random(70);
        else if(count < 3000)    e = 380 + random(75);
        else if(count < 4000)    e = 400 + random(85);
        else if(count < 5000)    e = 430 + random(80);
        else if(count < 10000)   e = 460 + random(99);
        else e = 400 + random(120);
        if (me->query("xs/girl_super"))
                e = e * (120+random(140)) / 100;
        if(e>500) e = 480 + random(100);
        p = e/4 + random(e/4);
        shen = -e*10;

        me->delete("xs/girl");
        me->delete("xs/girl_place");
        me->delete("xs/girl_time");
        me->delete("xs/girl_ob");
        me->delete("xs/girl_super");

        me->add("xs_job",1);
        me->add("xs_jobe",e);
        me->add("xs_jobp",p);
        me->add_temp("xs/xs_job",1);
        if( me->query("shen") > -10000 ) {
                me->add("shen",shen);
                command("hehe");
                command("say 好样的，可惜你不是我道中人。");
                return 1;
        }
        me->add("shen",shen);
        me->add("combat_exp",e);
        me->add("potential",p);
        if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
                me->set("potential" , me->query("max_pot", 1) );

        tell_object(me, 
HIC"你被奖励了"+CHINESE_D->chinese_number(e)+"点经验，"+CHINESE_D->chinese_number(p)+"点潜能！你感觉邪恶之气更胜从前！\n"NOR);
        write_file( "/log/job/xs_job",sprintf("%s %s(%s)第%d次任务，经验：%d，潜能：%d；总计e：%d，p：%d；exp：%d\n",
                ctime(time())[4..19],me->name(),me->query("id"),me->query("xs_job"),e,p,me->query("xs_jobe"),me->query("xs_jobp")
                ,me->query("combat_exp")));
        me->apply_condition("xs_job",2 + random(4) );

        return 1;     
}

string ask_offer()
{      
        object ob;
        if ( this_player()->query("xs_job" ) < 12)
           return RANK_D->query_rude(this_player())+"你给我做了几次任务，就想来要奖赏？";
         
        if ( this_player()->query("xs_offer" ) + 10 >= this_player()->query("xs_job" ))
           return RANK_D->query_rude(this_player())+"你还是先做点任务再来我这里领赏吧。"; 

        this_player()->set("xs_offer",this_player()->query("xs_job" ));

        
        
        ob=new("/clone/gem/gem");
        message_vision("老祖给了$N一颗"+ob->query("name")+""NOR"。\n",this_player());
        ob->move(this_player());        
        return RANK_D->query_respect(this_player())+"这是你的奖励。";
}

string ask_job()
{
        object target, *living ,me=this_player() , ob , beauty;
        int i,j;

        if( me->query("combat_exp") < 200000 )
                return "你的实战经验太少了点吧，派你去我可实在不大放心！";

        if( !wizardp(me) && me->query_condition("xs_job")>0 ) {
                command("slap "+(string)me->query("id"));
                if (random(2) )
                        return "你要累死你爷爷啊！爷爷虽然是XX超人，但也不能连着干呀！";
                else
                        return "你要累死你爷爷啊！你当我是S?x Mechine啊?！";
        }

        if( me->query("xs/girl") && ((time()-(int)me->query("xs/girl_time"))<((10+random(10))*60)) )
                return "我不是叫你到"+me->query("xs/girl_place")+"去给我抢美女了嘛！";

        if( me->query("shen") > -10000 ) {
                command("say 你去是可以，可没有报酬哦。");
                command("hehe");
        }

        living = livings();
        for (i=0;i < sizeof(living);i++){
                j = random(sizeof(living));
                if (j <= 1 || j == sizeof(living)-1) continue;
                if(TASK_D->check(living[j], 0, "aaa", "aaa", "aaa", 0) ){
                        target = living[j];
                        if( get_place(base_name(environment(target)))!="" ) 
                                break;
                }
        }

        if( !target )
                return "我最近没听说有什么出名的美女，你过一会儿再来吧。";

        me->set("xs/girl",1);
        me->set("xs/girl_time",time());
        me->set("xs/girl_place",get_place(base_name(environment(target)))+environment(target)->query("short"));
        if(wizardp(me)) tell_object(me,base_name(environment(target)));

        beauty = new("/d/dalunsi/npc/gbeauty");
        beauty->set("place", environment(target));
        me->set("xs/girl_ob",beauty);
        beauty->move("/d/xueshan/emptyroom");

        ob = new(__DIR__"guard");
        ob->set("target", me->query("id"));
        ob->set("place", environment(target));
        ob->set("beauty", beauty);
        if(random(4) != 1) {
                ob->do_copy(me,0);
                me->set("xs/girl_super",0);
        } 
        else {
                ob->do_copy(me,1);
                me->set("xs/girl_super",1);
        }
        beauty->set("guard", ob);
        ob->move("/d/xueshan/emptyroom");

        if( !objectp( present("hehan san", me)) ) {
                ob = new(__DIR__"hhs");
                ob->move(me);
                command("emote 给你一包阴阳合欢散。");
        }

        command("walkby");
        return "听说最近"+me->query("xs/girl_place")+CYN"附近来了个漂亮的小妞，你去给我弄来。";
}

string ask_fail()
{
        object me = this_player();

        if( !me->query("xs/girl") )
                return "你根本就没任务，放弃什么呀？";

        if( !me->query("xs/girl_super") )
                return "这么简单的任务你怎么可以放弃呢！快去干！";

        me->delete("xs/girl");
        me->delete("xs/girl_place");
        me->delete("xs/girl_time");
        me->delete("xs/girl_ob");
        me->delete("xs/girl_super");

        write_file( "/log/job/xs_job",sprintf("%s %s(%s)放弃了第%d次困难任务。\n",
                ctime(time())[4..19],me->name(),me->query("id"),me->query("xs_job")));

        return "这个任务是比较困难，你完不成也不能全怪你。";
}

string ask_times()
{
        object ob = this_player();

        if(!ob->query("xs_job"))
                return "对不起，"+ob->name()+"，你好象还没有在我这里领过任务呢，加油干吧！";

        return ""+ob->name()+"，你已经供奉给爷爷"+CHINESE_D->chinese_number((int)ob->query("xs_job"))+"名美女！";
}

string ask_xuedao()
{
        object me=this_player() , weapon;
        int i;

        if( !objectp( weapon=present("xue dao", this_object())) )
                return "血刀现在不在我手里。";  

        if ((string)me->query("family/family_name") != "大轮寺")
                i = 3;
        else
                i = 1;

        if(me->query_temp("xs/xs_job") > 3*i) {
                command("unwield xue dao");
                weapon->move(me);
                command("wield dao");
                command("emote 给你一把血刀。");
        }
        else
                return "你想要这把刀？你想要就说嘛，虽然你很有诚意的看着我，但还是要说话呀，
你说了我肯定会给你的，不可能你说了我不给你，而你不说我偏要给你吧。\n";

        return "好，这把血刀你拿去吧，记着多杀几个人来祭刀啊！";
}

void destroying(object obj)
{     
        if (!obj) return;
        if (userp(obj)) 
                command("drop "+obj->parse_command_id_list()[0]);
        else 
                destruct(obj);
}

string get_place(string str)
{ 
        string *place = explode(str, "/");

        str = "";
        if(place[0] == "d")
                switch(place[1]){
                        case "baituo":  str = "西域白陀山"; break;
                        case "mingjiao":        str = "西域明教"; break;
                        case "shaolin": str = "河南嵩山少林"; break;
                case "wudang":  str = "湖北武当山"; break;
                        case "xingxiu": str = "西域星宿海"; break;
                        case "city":            str = "扬州城"; break;
                        case "emei":            str = "四川峨嵋山"; break;
                        case "quanzhou":        str = "泉州城"; break;
                        case "taishan": str = "山东泰山"; break;
                        case "dali":            str = "西南大理国"; break;
                        case "gumu":            str = "终南山古墓"; break;
                        case "huashan": str = "华山"; break;
                        case "xiangyang":       str = "襄阳"; break;
                        case "dalunsi": str = "大轮寺"; break;
                        case "gaibang": str = "丐帮"; break;
                        case "suzhou":  str = "江南苏州"; break;
                        case "village": str = "陕西小村"; break;
                        case "taohua":          str = "东海桃花岛"; break;
                        case "guiyun":  str = "太湖归云庄"; break;
                        case "murong":          str = "苏州燕子坞"; break;
                        case "beijing": str = "北京城"; break;
                        case "shenlongdao":             str = "北海神龙岛"; break;
        }
        return str;
}

