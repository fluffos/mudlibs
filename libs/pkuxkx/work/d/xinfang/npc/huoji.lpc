// huoji        驿站伙计
// by bing
// jason add send mail quest here
// 2001-5-6
inherit NPC;

mapping mail_list=([
"衙役":"ya yi",
"管家":"guan jia",
"家丁":"jia ding",
"崔员外":"cui yuanwai",
"朱熹":"zhu xi",
"平一指":"ping yizhi",
"胡金科":"hu jinke",
"沈千盅":"shen qianzhong",
"陈震骐":"chen zhenqi",
"谢一绝":"xie yijue",
"尹霜叶":"yin shuangye",
"钟茗":"zhong ming",
"推销小姐":"girl",
"阿庆嫂":"aqing sao",
"韦春芳":"wei chunfang",
"唐楠":"tang nan",
"史青山":"shi qingshan",
"林平之":"lin pingzhi",
"钱眼开":"qian yankai",
"鲍大楚": "bao dachu",
"陆大有":"lu dayou",
"庄铮":"zhuang zheng",
"摘星子":"zhaixing zi",
"李斧头":"li futou",
"谷虚道长":"guxu daozhang",
"孙不二":"sun buer",
"杨女":"yang nu",
"枯荣大师":"kurong dashi",
"道象禅师":"daoxiang chanshi",
"王八衰":"wang bashuai",
"小兰":"xiao lan",
"阿紫":"a zi",
]);
int* base_value=({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,3,2,2,2,2,2,2,4,4,4,5});

int ask_xin();
int ask_sendmail();
int ask_fail();

void create()
{
        set_name("驿站伙计", ({ "huo ji", "huo", "ji" }));
        set("str", 30);
        set("gender", "男性");
        set("age", 25);
        set("long",
                "这是驿站里负责传递邮件的伙计。他身上穿着一件旧衣服，手里拿\n"
"着一大摞的邮件正在分拣。你如果想看信或者写信可以问他「信」。\n");
        set("combat_exp",  50000);
        set("attitude", "friendly");
        set("inquiry", ([
                "信" : (: ask_xin :),
                "送信":(:ask_sendmail:),
                "你是谁":"我就是大名鼎鼎的邮差--XXX啦！！！\n",
                "失败":(:ask_fail:),
        ]));
        
        set("shen_type",1);set("score",200);setup();
}

void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
/*
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
*/
        if(random(2))
        command("say 这位" + RANK_D->query_respect(ob) +"是不是来看信的呀？");
        else
        command("say 一个人送这么多信，真累，要是有人来帮忙送信就好了。");
        }
}

void greeting(object ob)
{
        if(random(2))
        command("say 这位" + RANK_D->query_respect(ob) +"是不是来看信的呀？");
        else
        command("say 一个人送这么多信，真累，要是有人来帮忙送信就好了。");
}

int ask_xin()
{
        object mbx;
        if ( present("mailbox", this_player()) )
        {
                write("邮差诧异地说道：您的邮箱已经给您了，还麻烦小的干吗？\n");
                return 1;
        }
        
        mbx = new("/clone/misc/mailbox");
        mbx->move(this_player());
        message_vision("驿站伙计给了" + this_player()->query("name") + "一个邮箱。\n",this_player());
        write ("邮差说道：这是您的邮箱，您可以用它写信，也可以看信。\n");
        return 1;
}

int ask_sendmail()
{
        int i,times,min,sec,delay;
        string *key,*value;
        object ppl=this_player(),mail;
    this_object()->start_busy(random(6));
        if(ppl->query("songxin")&&!ppl->query("songxin/ok"))
        {
                write ("邮差说道：你的信还没有送到吧？\n");
                return 1;
        }
        if(ppl->query("songxin/ok")==1) delay=20; //old 60
        else if(ppl->query("songxin/ok")==2) delay=120; //old 180
        else if(ppl->query("songxin/ok")==3) delay=300; //old 600
        else delay=0;
        if(time()-ppl->query("songxin/start_time")<delay)
        {
                write ("邮差说道：我这里没有什么信了，你先去干别的吧。\n");
                return 1;
        }
        if(ppl->query("combat_exp")>10000)
        {
                write ("邮差说道：哎呀呀，这位"+RANK_D->query_respect(ppl)+",小的可不敢麻烦您阿。\n");
				ppl->delete("songxin");
                return 1;
        }
        if(ppl->query("mud_age")>86400*2)
        {
                write ("邮差说道：这位"+RANK_D->query_respect(ppl)+",当今乱世，群雄竟起，您也该\n"+
                "到江湖中一展身手，上效天子，下安黎民啊。小的多嘴了。\n");
				ppl->delete("songxin");
                return 1;
        }
        key=keys(mail_list);
        value=values(mail_list);
        i=random(sizeof(key));
        //女的不用去少林
        if (ppl->query("gender") == "女性")
        while (value[i] == "daoxiang chanshi")
            i = random(sizeof(key));
        times=(60+random(60)*base_value[i]);
        min=times/60;
        sec=times%60;
        write ("邮差说道：这里有一封给"+key[i]+"("+value[i]+")的书信，你赶快送过去吧。\n");
        write("这封书信必须在"+chinese_number(min)+"分"+
        chinese_number(sec)+"秒内送到。\n");
        ppl->set("songxin/start_time",time());
        ppl->set("songxin/all_time",times);
        ppl->set("songxin/target_id",value[i]);
        ppl->set("songxin/target_name",key[i]);
        ppl->set("songxin/ok",0);
		ppl->set("songxin/base_v",base_value[i]);
        message_vision("$N递给$n一个裱好的信封。\n",this_object(),ppl);
        mail=new(__DIR__"obj/mail");
        mail->start_decay(times+random(180*base_value[i]));  //old 300+random(200));
        mail->set("long","送给"+key[i]+"的信件。\n");
        mail->set("songxin/start_time",time());
        mail->set("songxin/all_time",times);
        mail->set("songxin/target_id",value[i]);
        mail->set("songxin/target_name",key[i]);
        mail->move(ppl);
        command("pat "+ppl->query("id"));
        write("快去吧。\n");
        return 1;
}

int ask_fail()
{
        object ppl=this_player(),me=this_object();
        int money;
        if(!ppl->query("songxin"))
        {
                write ("我没有让你去送信啊，你记错了吧？\n");
                return 1;
        }
        if(ppl->query("songxin/ok"))
        {
                write("你不是把信送到目的地了么？\n");
                return 1;
        }
        write("邮差叹了口气，说道：算了，以后不找你帮忙了，你走吧！\n");
        ppl->set("songxin/ok",3);
        return 1;
}

