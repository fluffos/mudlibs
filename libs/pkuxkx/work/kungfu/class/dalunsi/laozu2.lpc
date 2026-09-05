// laozu.c 血刀老祖
// by iceland
// by emnil

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

string get_place(string str);
int check(object ob);

string ask_job();
string ask_xuedao();
string ask_zijindao();
string ask_jiasha();
string ask_times();
string ask_fail();
string ask_fail2();

void create()
{
        object weapon , armor;

        set_name("血刀老祖", ({ "xuedao laozu", "laozu","xuedaolaozu" }));
        set("long",@LONG
他身材高瘦，眼窝深陷，一双眼睛射出凶狠的光芒，令人不敢直视。他在江湖
中以残忍好色而著称，曾凭一手血刀经的功夫斗败无数中原的武林豪杰。
LONG
        );
        set("title", HIR "大轮寺血刀门掌门" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("no_bark",1);
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 39);
        set("int", 30);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 12000);
        set("max_jing",12000);
        set("max_jingli", 8000);
        set("neili", 18000);
        set("max_neili", 18000);
        set("jiali", 250);
        set("combat_exp", 5000000);
        set("score", 500000);
        set("shen", -5000000);
        set("unique", 1);

        set_skill("huanxi-chan", 280);
        set_skill("literate", 150);
        set_skill("force", 220);
        set_skill("longxiang-boruo", 250);
        set_skill("dodge", 200);
        set_skill("yuxue-dunxing", 200);
        set_skill("claw", 250);
        set_skill("tianwang-zhua", 220);
        set_skill("hand", 250);
        set_skill("dashou-yin", 220);
        set_skill("blade",250);
        set_skill("xuedao-jing",280);
        set_skill("parry", 200 );
        set_temp("apply/force",200);
        set_temp("apply/blade",300);
        set_temp("apply/claw",350);
        set_temp("apply/hand",350);
        set_temp("apply/dodge",300);
        set_temp("apply/parry",300);

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
               "血刀老祖自言自语道：“血刀和十三龙象袈裟可是好东西呀,一定要藏藏好。\n",
        }) );

        set("chat_chance_combat", 50);
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
                "紫金刀": (: ask_zijindao :),
                "zijin dao":(: ask_zijindao :),
                "十三龙象袈裟"  : (: ask_jiasha :),
                "jiasha":(: ask_jiasha :),
                "放弃" :(: ask_fail :),
                "fangqi":(: ask_fail :),
                "失败" :(: ask_fail2 :),
                "shibai":(: ask_fail2 :),
       ]));

        setup();
        if (clonep()){
                weapon = unew(BINGQI_D("zijin-dao"));
                if(!weapon) weapon=new(BINGQI_D("xinyuedao"));
                weapon->move(this_object());
                weapon->wield();
                set_temp("apply/damage",180);

                weapon=new(BINGQI_D("xinyuedao"));
                weapon->move(this_object());
                weapon=new(BINGQI_D("xinyuedao"));
                weapon->move(this_object());

                armor=new("/d/xueshan/npc/obj/longxiang-jiasha");
                armor->move(this_object());             
                armor->wear();
                set_temp("apply/armor",300);
        }

}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "大轮寺") {
                command("say"+ RANK_D->query_respect(ob) + "不是本寺弟子，在这里捣什么乱？！");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 160) {
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

        ob->set("title", HIR"大轮寺血刀老祖亲传弟子" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

int accept_object(object me, object ob, object who)
{
        int e,p,shen,count,i;
        string s;

        if(ob->query("id") != "beauty"){
                command("? "+ (string)me->query("id"));
                command("say 你给我这个干什么？");
                return 0;
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
                log_file( "job/xs_job_bug", sprintf("%s %s(%s)似乎在利用BUG！\n",
                        ctime(time())[4..19],me->name(),me->query("id")));
                return 1;
        }

        command("hehe");
        command("say 不错不错，今天又有事情干了。你给爷爷做事，爷爷也不会亏待你的。");
        call_out("destroying", 1, ob);

        count = me->query("xs_job",1);

        e = 250 + random(70);

        if (me->query("xs/girl_super")) {
                e = e * (110 + random(100)) / 100;
                if ( e > 600 ) e = 500 + random(100);
                s = "困难任务";
        }
        else
                s = "任务";

        p = e/5 + random(e/6);

        shen = -e * 6;

        me->delete("xs/girl");
        me->delete("xs/girl_place");

        i = 40 - me->query_condition("xs_job");
        if ( i >= 9 )
          me->apply_condition("job_busy", 1);
        else 
          me->apply_condition("job_busy", 9 - i);

        me->apply_condition("xs_job", e/75 );

        me->delete("xs/girl_time");
        me->delete("xs/girl_ob");
        me->delete("xs/girl_super");
        me->delete("xs/cant");

        me->add_temp("xs/xs_job", 1);

        if( me->query("shen") >- 10000){
                me->add("shen",shen*2);
                me->set("xs/girl_busy", 0 );
                command("hehe");
                command("say 好样的，可惜你不是我道中人。");
                return 1;
        }

        if ((string)me->query("family/family_name") != "桃花岛")
        me->add("shen",shen);

        me->add("xs_job",1);
        me->add("xs_jobe",e);
        me->add("xs_jobp",p);

        me->add("combat_exp",e);
        me->add("potential",p);

        if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
                me->set("potential" , me->query("max_pot", 1) );

        if ((string)me->query("family/family_name")=="大轮寺"
          && me->query_skill("huanxi-chan",1) < 200)
                me->improve_skill("huanxi-chan", e );

        tell_object(me, HIC"你被奖励了"+CHINESE_D->chinese_number(e)+"点经验，"+CHINESE_D->chinese_number(p)+"点潜能！你感觉邪恶之气更胜从前！\n"NOR);
        log_file( "job/xs_job",sprintf("%s %s(%s)第%d次%s，经验：%d，潜能：%d；总计e：%d，p：%d；现exp：%d\n",
                ctime(time())[4..19], me->name(), me->query("id"), me->query("xs_job"), s, e, p,
                me->query("xs_jobe"), me->query("xs_jobp"), me->query("combat_exp")));
        return 1;     
}

string ask_job()
{
        object target, *living ,me=this_player() , ob , beauty;
        int i,j;
        string str;

        if( me->query("combat_exp") < 100000 )
                return "你的实战经验太少了点吧，派你去我可实在不大放心！";

        if( me->query("xs/girl") && ((time()-(int)me->query("xs/girl_time"))<(12*60)) )
                return "我不是叫你到"+me->query("xs/girl_place")+"去给我抢美女了嘛！";

        if( me->query("job_name") == "强抢美女")
                return "你要累死你爷爷啊！一边呆着去！";

        if( me->query_condition("job_busy") || me->query_condition("xs_job")) {
                if ( me->query("job_name") == "强抢美女") {
                    command("slap "+(string)me->query("id"));
                    return "你要累死你爷爷啊！一边呆着去！";
                }
                else 
                    return "身体是革命的本钱啊，同志！你还是先歇息一会儿吧。";
        }
        me->delete("xs/girl_busy");

        if(me->query("shen") > -10000){
                return "我看你不够心狠手辣，爷爷我不喜欢。";
        }

        living = livings();
        for (i=0;i < sizeof(living);i++){
                j = random(sizeof(living));
                if (j <= 1 || j == sizeof(living)-1) continue;
                if(check(living[j]) ){
                        target = living[j];
                        str = environment(target)->query("short");
                        if( str == "武僧堂" 
                         || str == HIR"心禅堂"NOR
                         || str == "金刚伏魔圈" ) continue;
                        if( get_place(base_name(environment(target)))!="" ) 
                                break;
                }
        }

        if( !target )
                return "我最近没听说有什么出名的美女，你过一会儿再来吧。";

        me->set("job_name" , "强抢美女");
        me->apply_condition("job_busy", 40);
        me->apply_condition("xs_job", 40);
        me->set("xs/girl",1);
        me->set("xs/girl_time",time());
        me->set("xs/girl_place",get_place(base_name(environment(target)))+environment(target)->query("short"));

        beauty = new(__DIR__"gbeauty");
        beauty->set("place", environment(target));
        me->set("xs/girl_ob",beauty);
        beauty->move("/d/xueshan/emptyroom");

        ob = new(__DIR__"guard");
        ob->set("target", me->query("id"));
        ob->set("place", environment(target));
        ob->set("beauty", beauty);
        if(wizardp(me)) tell_object(me, base_name(environment(target))+"\n");
        me->set("xs/cant",0);
        if(random(15) != 1 || me->query("combat_exp") < 500000 ) {
                ob->do_copy(me,0);
                me->set("xs/girl_super",0);
        } 
        else {
                ob->do_copy(me,1);
                me->set("xs/girl_super",1);
                if ( (me->query("combat_exp") > 1000000) && (random(3)==1) )
                    me->set("xs/cant",1);
        }
        beauty->set("guard", ob);
        ob->move("/d/xueshan/emptyroom");

        if( !objectp( present("hehuan san", me)) ) {
                ob = new(__DIR__"hhs");
                ob->move(me);
                message_vision("血刀老祖给$N一包阴阳合欢散。\n",me);
        }

        command("walkby");
        command("whisper " + me->query("id")+ " 听说最近"+me->query("xs/girl_place")+GRN"附近来了个漂亮的小妞，你去给我弄来。");
        return "速去速回。";
}

string ask_fail()
{
        int i;
        object me = this_player();

        if( !me->query("xs/girl") )
                return "你根本就没任务，放弃什么呀？";
        if( !me->query("xs/girl_super") )
                return "这么简单的任务你怎么可以放弃呢！快去干！";
        if( me->query("xs/cant") )
                return "拜托，有点专业精神好不好？困难点的任务就不做，你怎么对的起我给你的EXP！";

        me->delete("xs/girl");
        me->delete("xs/girl_place");
        me->delete("xs/girl_time");
        me->delete("xs/girl_ob");
        me->delete("xs/girl_super");
        me->delete("xs/cant");
        i = 40 - me->query_condition("xs_job");
        if ( i >= 9 )        
          me->apply_condition("job_busy", 1);
        else
          me->apply_condition("job_busy", 9 - i);
        me->apply_condition("xs_job", 9);
        log_file( "job/xs_job",sprintf("%s %s(%s)放弃了第%d次困难任务。\n",
                ctime(time())[4..19],me->name(),me->query("id"),me->query("xs_job")));
        return "这个任务是比较困难，你完不成也不能全怪你。";
}

string ask_fail2()
{
        object me = this_player();
        int i;

        if( !me->query("xs/girl") )
                return "你根本就没任务，失败什么呀？";

        command("disapp "+me->query("id"));

        me->delete("xs/girl");
        me->delete("xs/girl_place");
        me->delete("xs/girl_time");
        me->delete("xs/girl_ob");
        me->delete("xs/girl_super");
        me->delete("xs/cant");

        i = 40 - me->query_condition("xs_job");
        if ( i >= 9 )        
          me->apply_condition("job_busy", 1);
        else
          me->apply_condition("job_busy", 9 - i);
        me->apply_condition("xs_job", 9);

        log_file( "job/xs_job",sprintf("%s %s(%s)第%d次任务失败。\n",
                ctime(time())[4..19],me->name(),me->query("id"),me->query("xs_job")));

        return "你好好反省一下去！";
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

        if ((string)me->query("family/family_name") != "大轮寺")
                i = 3;
        else
                i = 1;

        if(me->query_temp("xs/xs_job") >= 1*i) {
                weapon = present("xue dao", this_object());
                if(!objectp(weapon))    weapon = unew(BINGQI_D("xuedao"));
                if(!objectp(weapon))
                        return "血刀现在不在我手里。";  

                command("unwield xue dao");
                weapon->move(me);
                command("wield dao");
                command("emote 给你一把血刀。");
                me->set_temp("xs/xs_job",0);
        }
        else
                return "你想要这把刀？你想要就说嘛，虽然你很有诚意的看着我，但还是要说话呀，\n"+
                       "你说了我肯定会给你的，不可能你说了我不给你，而你不说我偏要给你吧。\n";

        return "好，这把血刀你拿去吧，记着多杀几个人来祭刀啊！";
}

string ask_zijindao()
{
        object me=this_player() , weapon;

        if ((string)me->query("family/family_name") != "大轮寺")
                return "你非我寺中人，这把刀怎么能给你呢！";

        if ((int)me->query("xs_job") < 50 )
                return "心动不如行动，拿点实际成绩来给我看嘛。\n";

        weapon = present("zijin dao", this_object());
        if(!objectp(weapon))    weapon = unew(BINGQI_D("zijin-dao"));
        if(!objectp(weapon))
                return "紫金刀现在不在我手里。";        

        command("unwield zijin dao");
        weapon->move(me);
        command("wield dao");
        command("emote 给你一把紫金刀。");

        return "好，这把紫金刀你拿去吧，记住不要给外人呀！";
}

string ask_jiasha()
{
        object me=this_player() , armor;
        int i;

        if ((string)me->query("family/family_name") != "大轮寺")
                i = 5;
        else
                i = 1;

        if(me->query_temp("xs/xs_job") >= 1*i) {
                armor = present("shisan longxiang", this_object());
                if(!objectp(armor))     armor = unew(ARMOR_D("lx_cloth"));
                if(!objectp(armor))
                        return "十三龙象袈裟现在不在我手里。";  

                command("remove shisan longxiang");
                armor->move(me);
                command("wield jiasha");
                command("emote 给你一件十三龙象袈裟。");
                me->set_temp("xs/xs_job",0);
        }
        else
                return "心动不如行动，拿点实际成绩来给我看嘛。\n";

        return "好，这件十三龙象袈裟你拿去吧，记着多给我找几个姑娘啊！";
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
                        case "baituo":    str = "西域白陀山";  break;
                        case "hj":        str = "西域回疆"; break;
                        case "mingjiao":  str = "西域明教"; break;
                        case "shaolin":   str = "河南嵩山少林"; break;
                        case "songshan":  str = "河南嵩山"; break;
                        case "wudang":    str = "湖北武当山"; break;
                        case "xingxiu":   str = "西域星宿海"; break;
                        case "city":      str = "江南扬州城"; break;
                        case "emei":      str = "四川峨嵋山"; break;
                        case "fuzhou":    str = "南疆福州"; break;
                        case "jiaxing":   str = "江南嘉兴"; break;
                        case "taishan":   str = "山东泰山"; break;
                        case "dali":      str = "西南大理国"; break;
                        case "tls":       str = "大理天龙寺"; break;
                        case "tiezhang":  str = "湖南铁掌山"; break;
                        case "kunlun":    str = "";break;
                        case "fairyland": str = "西域昆仑山"; break;
                        case "gumu":      str = ""; break;
                        case "chengdu":   str = "四川成都"; break;
                        case "huashan":   str = "陕西华山"; break;
                        case "xiangyang": str = "湖北襄阳"; break;
                        case "xueshan":   str = "西番大雪山"; break;
                        case "wizard":    str = ""; break;
                        case "death":     str = ""; break;
                        case "gaibang":   str = "丐帮分舵"; break;
                        case "hz":        str = "江南临安府"; break;
                        case "village":   str = "陕西小村"; break;
                        case "wuguan":    str = "襄阳武馆"; break;
                        case "thd":       str = "东海桃花岛"; break;
                        case "gaibang":   str = "丐帮分舵"; break;
                        case "mr":        str = "苏州燕子坞"; break;
                        case "suzhou":    str = "苏州县城"; break;
                        case "sld":       str = "北海神龙岛"; break;
        }
        return str;
}

string *no_kill_list = ({
         "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
        object room;
        string room_name;
        
        if(!objectp(ob)
         || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
         || ob->query("env/invisibility")
         || ob->query("no_quest")
         || member_array(ob->query("id"), no_kill_list) != -1
         || userp(ob)
         || ob->query("attitude")=="aggressive"
         || ob->query("have_master")
         || !objectp(room=environment(ob))
         || room->query("no_fight") 
         || present("body guard", room)
         || room->query("outdoors") == "昆仑翠谷"
         || strsrch(room_name = file_name(room),"/d/") != 0
         || strsrch(room_name, "/d/wizard/") == 0
         || strsrch(room_name, "/d/wuguan/") == 0
         || strsrch(room_name, "/d/death/") == 0
         || strsrch(room_name, "/d/kunlun/") == 0
         || strsrch(room_name, "/d/mingjiao/lsd/") == 0
         || strsrch(room_name, "/d/mingjiao/bhd/") == 0
         || strsrch(room_name, "/d/xueshan/") == 0
         || strsrch(room_name, "/d/shaolin/liwu") == 0
         || strsrch(room_name, "/d/shaolin/houyuan") == 0
         || strsrch(room_name, "/d/huashan/jiabi") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
         || strsrch(room_name, "/d/shaolin/xinchan") == 0
         || strsrch(room_name, "/d/mingjiao/yuanzi") == 0
         || strsrch(room_name, "/d/mingjiao/wxiang") == 0
         || strsrch(room_name, "/d/baituo/") == 0
         || strsrch(room_name, "/d/thd/") == 0
         || strsrch(room_name, "/d/sld/") == 0) 
         return 0;
        return 1;
}

