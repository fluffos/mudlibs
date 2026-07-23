// song.c 宋远桥

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "/kungfu/class/wudang/place.h"
string ask_me();

string ask_me1();

string ask_me2();

string ask_me3();

string ask_me4();
void create()
{
       set_name("宋远桥", ({ "song yuanqiao", "song" }));
       set("nickname", "武当首侠");
       set("long", 
               "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
               "身穿一件干干净净的灰色道袍。\n"
               "他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
       set("gender", "男性");
       set("unique", 1);
       set("age", 61);
       set("attitude", "peaceful");
       set("shen", 10000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
set("no_get","宋远桥对你而言太重了。");
       
       set("max_qi", 1500);
       set("max_jing", 1000);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 50);
       set("combat_exp", 1000000);
//     set("score", 60000);
       set_skill("force", 130);
       set_skill("yinyun-ziqi", 130);
       set_skill("dodge", 130);
       set_skill("wudang-quan", 130);
       set_skill("tiyunzong", 130);
       set_skill("strike", 180);
       set_skill("zhenshan-mianzhang", 180);
       set_skill("parry", 130);
       set_skill("literate", 100);
       set_skill("xuanxu-daofa", 140);
       set_skill("sword", 180);
       set_skill("taiji-jian", 180);
       map_skill("sword", "taiji-jian");
       set_skill("wudang-quan", 140);
       map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "zhenshan-mianzhang");
       map_skill("parry", "zhenshan-mianzhang");
       prepare_skill("strike", "zhenshan-mianzhang");
       create_family("武当派", 2, "弟子");

       set("inquiry", ([
                "秘籍" : (: ask_me :),
                "概要" : (: ask_me1 :),
                "工作" : (: ask_me2 :),
                 "job" : (: ask_me2 :),
                "巡山" : (: ask_me2 :),
              "fangqi" : (: ask_me3 :),
                "放弃" : (: ask_me3 :),
             "abandon" : (: ask_me3 :),
                "贡献" : (: ask_me4 :),
                "次数" : (: ask_me4 :),
                "功劳" : (: ask_me4 :),

       ]));
       set("book_count1", 1);
       set("book_count2", 1);
       setup();
//     carry_object("/clone/weapon/changjian")->wield();
       carry_object("/d/wudang/obj/white-robe")->wear();

}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }       
     
}

void greeting(object ob)
{
        int e,p,shen,count;
        mapping fam;
        fam = this_player()->query("family");

        if (!ob) return;        // Yuj 19991111

        count = ob->query("wd_job",1);
             if(count < 100)     e = 80 + random(20);
        else if(count < 200)     e = 110 + random(20);
        else if(count < 500)     e = 130 + random(20);
        else if(count < 1000)    e = 180 + random(30);
        else if(count < 2000)    e = 230 + random(20);
        else if(count < 3000)    e = 250 + random(30);
        else if(count < 4000)    e = 300 + random(40);
        else if(count < 5000)    e = 320 + random(60);
        else if(count < 10000)   e = 340 + random(90);
        else if(count < 1000000) e = 350 + random(150);
        p = e/6 + random(e/10) ;
        shen = e*10 + p*10;
        if(ob->query("wd/wd_job_lost2") )
       {
        command("faint "+ob->query("id"));
        command("say "+ob->name()+"，已经有人帮你把那恶贼给赶跑了！");
        ob->delete("wd/wd_job");
        ob->delete("wd/wd_job_place");
        ob->delete("wd/wd_job_lost2");
        ob->apply_condition("job_busy",3+random(6));
       }
        if(ob->query("wd/wd_job_lost") )
       {
        command("sigh "+ob->query("id"));
        command("say "+ob->name()+"你怎么搞的，居然让那恶贼给跑了！");
        ob->delete("wd/wd_job");
        ob->delete("wd/wd_job_place");
        ob->delete("wd/wd_job_lost");
        ob->apply_condition("job_busy",3+random(6));
       }
        if(ob->query("wd/wd_jobok") ){
        command("thumb "+ob->query("id"));
        command("say 很好，祝贺你完成了任务，下去休息休息吧！");
        ob->add("wd_job",1);
        count += 1;
        ob->add("combat_exp",e);
        ob->add("potential",p);
if( ob->query("family/family_name")!="桃花岛")
            ob->add("shen",shen);
        ob->delete("wd/wd_job");
        ob->delete("wd/wd_job_place");
        ob->delete("wd/wd_jobok");
        if ( (int)ob->query("potential", 1) > (int)ob->query("max_pot", 1) )
        ob->set("potential" , ob->query("max_pot", 1) );
        tell_object(ob, GRN"
你获得了"+CHINESE_D->chinese_number(e)+"点经验，"+CHINESE_D->chinese_number(p)+"点潜能！你的侠义正气增加了！\n"NOR);
        write_file( "/log/job/wd_job",sprintf("%s %s(%s)第%d次任务获得%d点经验，%d点潜能，经验：%d\n",
ctime(time())[4..19],ob->name(),ob->query("id"),count,e,p,ob->query("combat_exp")));
          ob->apply_condition("wd_job",1+random(2)+e/120);
        }
        return;
}

int accept_object(object who, object ob, object me)
{
        int e,p,shen;
        mapping fam;

        who = this_player();
        e = 100 + random((int)who->query("wd_job")/2);
        if(e > 300) e = 280 + random(30);
        p = e/6 + random(e/10) ;
        shen = e*10 + p*10;
        if(ob->query("id") != "corpse"){
             command("? "+ (string)who->query("id"));
             command("say 你给我这个干什么？");
return 0;
}
        if( !who->query("wd/wd_job")) {
             command("? "+ (string)who->query("id"));
             call_out("destroying", 1, ob);
             return 1;
            }
        if(ob->query("kill_by") != who){
             command("kick "+ (string)who->query("id"));
             command("say 这个人又不是你杀的，想从我这里骗取什么？");
             call_out("destroying", 1, ob);
             return 1;
            }
        if ( ob->query("victim_id") != "robber" ){
             command("? "+ (string)who->query("id"));
             call_out("destroying", 1, ob);
             return 1;
            }
        if ( ob->query("victim_user") ){
             command("consider "+ (string)who->query("id"));
             command("say 我最讨厌用别人使用欺骗的手段，还不赶快给我退下！！");
             call_out("destroying", 1, ob);
             return 1;
            }
        command("touch "+who->query("id"));
        command("say 恭喜恭喜！你居然铲除了这个恶贼，真是太好了，下去休息休息吧！");
        call_out("destroying", 1, ob);
        who->add("wd_job",1);
        who->add("combat_exp",e);
        who->add("potential",p);
        fam = this_player()->query("family");
        if (fam["family_name"] != "桃花岛")
            who->add("shen",shen);
        who->delete("wd/wd_job");
        who->delete("wd/wd_job_place");
        who->delete("wd/wd_jobok");
        if ( (int)who->query("potential", 1) > (int)who->query("max_pot", 1) )
        who->set("potential" , who->query("max_pot", 1) );
        tell_object(who, GRN"
你被特别奖励了"+CHINESE_D->chinese_number(e)+"点经验，"+CHINESE_D->chinese_number(p)+"点潜能！你感觉侠义正气猛增！\n"NOR);
        write_file( "/log/job/wd_job",sprintf("%s %s(%s)杀死恶贼特别奖励%d点经验，%d点潜能，目前实战经验：%d\n",
ctime(time())[4..19],who->name(),who->query("id"),e,p,who->query("combat_exp")));
        who->apply_condition("wd_job",2+random(5));
        return 1;    
}

void kill_ob(object me)
{
        //set("combat_exp", 750000);    
        //set("max_qi", 2500);
        //set("max_neili", 2000);
        //set("neili", 2000);
        //set("jiali", 100);
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
               (: perform_action, "strike.bingdi" :),
               (: perform_action, "dodge.zong" :),
        }));
        ::kill_ob(me);       
} 

int accept_fight(object me)
{
        if((int)me->query("shen") < 1) {
           command("say 习武之人应志在锄恶济善，"+RANK_D->query_respect(me)+"目露瘴气，有违武学之本？");
           return 0;
        }
        ::fight_ob(me);
         return 1;
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query("shen") < 10000) {
               command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
               command("say 在德行方面，" + RANK_D->query_respect(ob) +
                       "是否还做得不够？");
               return;
       }
       command("say 好吧，贫道就收下你了。");
       command("recruit " + ob->query("id"));
}

string ask_me()
{
       mapping fam; 
       object ob;
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
               return RANK_D->query_respect(this_player()) + 
               "与本派素无来往，不知此话从何谈起？";
       if(query("book_count2") < 1)
         return "你来晚了，本派的内功心法不在此处。";
       add("book_count2",-1);       
       ob = new(__DIR__"force_book");
       ob->move(this_player());
       return "好吧，这本「太极十三式」你拿回去好好钻研。";
}

string ask_me1()
{
        mapping fam; 
        object ob,song;        
        song = this_object();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count1") < 1)
           return "你来晚了，刀法概要已经不在此处了。";
        add("book_count1",-1);         
        ob = new(__DIR__"blade_book");
        ob->move(this_player());
        return "这本书中讲述的刀法要领，你会去好好研究一下。";
}
string ask_me2()
{
        object me, ob;
        string *place,objwhere,str,str2;

        me=this_player();
        str2 = me->query("wd/wd_job_place");

        if (me->query("menggu"))
           return "哼，你以身属蒙古，还想做什么？";
        if (me->query("wd/wd_job") && !me->query("wd/wd_job_place"))
           return "啊……，对不起，地点有误，你放弃重新再来吧。";
        if (me->query("wd/wd_job"))
           return "我不是告诉你了吗，有人在"+ str2 +CYN"附近捣乱。你就快去吧！";
        if (((int)me->query("shen")<0) && !wizardp(me) )
  return "我怎么能相信你这等邪恶之士！";
        if ((int)me->query("combat_exp") < 200000 )
           return "这位" + RANK_D->query_respect(this_player()) + "武功未成，还是去俞岱岩那里做看守铜鼎的工作吧！";
        if( me->query_condition("wd_job"))
           return "现在暂时还没有工作让你去做。";
        if ( me->query_condition("dali_songxin")
          || me->query_condition("gb_mission")
          || me->query_condition("gb_busy")
          || me->query_condition("xx_task")
          || me->query_condition("guanfu_task") 
          || me->query_condition("xs_job"))
            return "你现在正忙着做其他任务呢！";

        while (1) {
                objwhere = names[random(sizeof(names))];
                if (load_object(objwhere)) break;
        }
        place = explode(objwhere, "/");
        str = " ";
        if(place[0] == "d")
                switch(place[1]){
                        case "baituo":  str = "西域白陀山"; break;
                        case "hj":      str = "西域回疆"; break;
                        case "mingjiao":str = "西域明教"; break;
                        case "shaolin": str = "河南嵩山少林"; break;
                        case "songshan":str = "河南嵩山"; break;
                        case "wudang":  str = "湖北武当山"; break;
                        case "xingxiu": str = "西域星宿海"; break;
                        case "city":    str = "江南扬州城"; break;
                        case "emei":    str = "四川峨嵋山"; break;
                        case "fuzhou":  str = "南疆福州"; break;
                        case "jiaxing": str = "江南嘉兴"; break;
                        case "taishan": str = "山东泰山"; break;
                        case "dali":    str = "西南大理国"; break;
                        case "tls":     str = "大理天龙寺"; break;
                        case "tiezhang":str = "湖南铁掌山"; break;
                        case "fairyland":str = "昆仑山脉"; break;
                        case "gumu":    str = "终南山古墓"; break;
                        case "chengdu": str = "四川成都"; break;
                        case "huashan": str = "陕西华山"; break;
                        case "xiangyang":str = "湖北襄阳"; break;
                        case "xueshan": str = "西番大雪山"; break;
                        case "gaibang": str = "丐帮分舵"; break;
                        case "hz":      str = "江南杭州"; break;
                        case "village": str = "陕西小村"; break;
                        case "wuguang": str = "襄阳武馆"; break;
                        case "thd":     str = "东海桃花岛"; break;
                        case "gb":      str = "丐帮"; break;
                        case "mr":      str = "姑苏慕容"; break;
                       }
        me->set("wd/wd_job",1);
        me->set("wd/wd_job_place", str);
    me->apply_condition("wd_job",20);
        command("nod "+me->query("id"));
        ob=new("/d/wudang/npc/robber");
        ob->set_temp("target", me->query("id") );
        ob->move(objwhere);
write_file( "/log/job/wd_job",sprintf("%s %s(%s)开始做wd job,目前实战经验：%d\n", ctime(time()),me->name(),me->query("id"),me->query("combat_exp")));
        return "据说有人在"+ str + objwhere->query("short") +CYN"附近捣乱，你马上去给我巡视一圈。";
}

string ask_me3()
{
        object ob;
        ob = this_player();
        if(ob->query("wd/wd_job"))
        {
         ob->delete("wd/wd_job");
         ob->delete("wd/wd_job_place");
         ob->apply_condition("job_busy",10+random(10) );
         ob->apply_condition("wd_job",10+random(10) );
         message_vision(CYN"宋远桥一把鼻涕一把眼泪地哭着，对$N骂道：你这么没出息，叫我怎么对得起你死去的爹娘啊！\n"NOR,ob);
         return ""+ob->name()+"，你太让我失望了，居然这么点活都干不好，先退下吧！";
        }
        return ""+ob->name()+"，你又没在我这里领任务，瞎放弃什么呀！";
}
string ask_me4()
{
        object ob;
        ob = this_player();
        if(!ob->query("wd_job"))
        {
         return "对不起，"+ob->name()+"，你好象还没有在我这里领过任务呢，加油干吧！";
        }
        return ""+ob->name()+"，你已经成功地铲除了"+CHINESE_D->chinese_number((int)ob->query("wd_job"))+"名恶贼！";
}
void destroying(object obj)
{     
    if (!obj) return;
    if (userp(obj)) command("drop "+obj->parse_command_id_list()[0]);
    else destruct(obj);
}

