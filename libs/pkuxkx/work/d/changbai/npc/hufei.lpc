// hufei.c  增加两个谜题by kiden
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_book();
int do_answer(string arg);
int ask_miaorf();
void do_kill(object ob);

void create()
{
        set_name("胡斐", ({"hu fei", "hu", "fei"}));
        set("gender", "男性");
        set("nickname", "雪山飞"HIG"狐"NOR);
        set("age", 25);
        set("long",
                "他就是胡一刀之子，因其武功高强神出鬼没。\n"
                "在江湖上人送外号「雪山飞狐」。\n"
                "他身穿一件白色长衫，腰间别着一把看起来很旧的刀。\n"
                "他满腮虬髯，根根如铁，一头浓发，却不结辫。\n");
        set("attitude", "peaceful");
        set("no_get", 1);
        set("xsfh",1);
        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("chat_chance", 20);
        set("chat_msg", ({
                "胡斐叹了口气道：“不知什么时候还能再见到若兰姑娘。\n",
                "胡斐恨恨道：“苗人凤是我杀父仇人，我必报此仇！”\n",
                "胡斐切齿恨道：“阎基老贼暗中下毒，我必手刃此獠！”\n",
        }));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                (: perform_action, "blade.lian" :),
                (: perform_action, "blade.lian" :),
        }) );
        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 100);
        set("combat_exp", 8900000);
        set("score", 20000);
        set_skill("force", 350);             // 基本内功
        set_skill("hujia-daofa", 450);       // 胡家刀法
        set_skill("blade", 400);             // 基本刀法
        set_skill("hunyuan-yiqi", 350);      // 混元一气功
        set_skill("dodge", 300);             // 基本躲闪
        set_skill("shaolin-shenfa", 300);    // 少林身法
        set_skill("parry", 350);             // 基本招架
        map_skill("force", "hunyuan-yiqi");
        map_skill("blade", "hujia-daofa");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "hujia-daofa");
        set_temp("apply/defense", 220);
        set_temp("apply/armor", 420);

        set("chat_chance", 20);
        set("chat_msg", ({
                "胡斐切齿恨道：“阎基这个狗贼我非杀了他不可。”\n",
                "胡斐叹道：“闯王宝藏究竟卖藏于何处？”\n",
                "胡斐幽幽道：“不知什么时候还能再见到若兰姑娘！”\n",
        }));
        set("inquiry",([
                "宝刀":     (: ask_me :),
                "闯王宝刀":     (: ask_me :),
//              "刀谱":     (: ask_book :),
//              "胡家刀谱": (: ask_book :),
                "阎基":     "阎基这个狗贼我非杀了他不可。\n",
                "胡一刀":   "辽东大侠胡一刀是我爹。不过我从没见过他。\n",
                "雪山飞狐":  "苗人凤害死我父亲，此仇到底要不要报呢？",
                "飞狐外传":  "你如果能帮我二妹找回“七心海棠”，我便赠送给你。",  

                "苗人凤":   (:ask_miaorf:),
                "苗若兰":   "不知什么时候还能再见到若兰姑娘。\n",
                "若兰":   "不知什么时候还能再见到若兰姑娘。\n",
                "若兰姑娘":   "不知什么时候还能再见到若兰姑娘。\n",
                "程灵素":   "听说二妹现在在襄阳。\n",
                "二妹":   "听说二妹现在在襄阳。\n",
                "赵半山":   "你见我赵三哥了? \n",
                "袁紫衣":   "算了，别提这伤心事了。\n"
        ]));
        set("baodao_count",random(4)-2);
        set("book_count",1);
        set("shen_type",1);set("score",50000);setup();
        carry_object("/d/city/npc/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        ob = this_player();

        if(userp(ob) && ob->query("shen") < - 100000)
        {
                say( "胡斐说道：邪魔歪道怎么混到这里来的？\n");
                this_object()->kill_ob(ob);
                return;
        }
       add_action("do_answer","answer");
}

string ask_me()
{
        object ob, me;

        me = this_player();
        if((int)(me->query("shen") < 100000))
                return "以你目前的作为是不能拿这把刀的,宝刀只赠给行侠仗义的英雄好汉。";
        else if((int)(me->query("repute") < 100000))
                return "以你目前的江湖声望不配拿这把刀, 宝刀不赠给无名鼠辈。";
        else if (!me->query_temp("marks/cwbaodao"))
                return "大侠若能为我擒来阎基狗贼，胡某一定宝刀赠英雄。";
        else if(me->query_temp("marks/cwbaodao"))
        {
                if(query("baodao_count") > 0)
                {
//                      call_out("waiting",0,me,ob);
                        add("baodao_count", -1);
                        ob = new ("/d/changbai/obj/cwbdao");
                        ob->move(me);
//                      command("rumor " + me->query("name") + "拿到闯王军刀啦。\n");
                        return " 好吧，这把闯王宝刀就赠与你，希望你好好利用它。";
                }
                else return "你来晚了，这把刀已不在此处。";
        }

}

int accept_object(object me, object ob)
{
        int i;
        object book;
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
        if ( (string)ob->query("id") == "yan ji")
        {
                write(HIC "\n胡斐说道：这位" + RANK_D->query_respect(me)+"，如此大恩大德，在下实不知何以为报。\n");
                write(HIC "\n胡斐大喜道：狗贼！想不到你也有今天！！手起刀落，将阎基剁为两段。\n"NOR);
                call_out("destroying", 1, this_object(), ob);
                me->set_temp("marks/cwbaodao",1);
                return 1;
        }
        else if ( (string)ob->query("id") == "qixin haitang")
        {
                write(HIC "\n胡斐大喜道：多谢你为我二妹找回七心海棠，这本《飞狐外传》赠送给你做个纪念。\n"NOR);

                book=new("/d/reborn/jinyong/obj/fhwz");
                book->move(me);                
                call_out("destroying", 1, this_object(), ob);
                return 1;
        }        
        return 0;
}
/*
string ask_book()
{
        object ob, me;

        me = this_player();
        if (!me->query_temp("marks/hujiadaopu",1)) return "你说什么? \n";
        if((int)(me->query("shen") < 100000))
                return "刀谱落入宵小之手，难免是阎基第二。\n";

        else
== 未完继续 88% == (q 离开，b 前一页，其他继续下一页)

        {
                if(query("book_count") > 0)
                {
                write(HIC "胡斐说着转身从阎基尸身上搜出一本破旧书本，递了给你。\n");
//                      call_out("waiting",0,me,ob);
                        add("book_count", -1);
                        ob = new ("/d/changbai/obj/blade_book");
                        ob->move(this_player());
                        command("rumor " + me->query("name") + "拿到胡家刀谱啦。\n");
                        return "这本刀谱被这狗贼霸占多时了，现在就赠与你吧。\n";
                }
                else return "你来晚了，现在刀谱已不在此处。\n";
        }

}
*/
void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
int ask_miaorf()
{
        object player=this_player();
        if (player->query("combat_exp")<50000000)
     {
        command("say 苗人凤虽和家父齐名，家父却死在他的剑下。");
        return 1;
        }       
   command("say 苗人凤虽和家父齐名，家父却死在他的剑下。");
   command("say 他是我的杀父仇人，可是他又是若兰的父亲。");
   command("sigh");     
   if(random(100)>90)
        {
   command("say 这刀砍还是不砍呢？");
   player->set_temp("xsfh",1);
                }
    return 1;           
}
int do_answer(string arg)
{
        object player=this_player();
        object me=this_object();
        object book;
        if (player->query_temp("xsfh")<1)
                return 0;
        if (arg=="砍")
                {
                command("say 听平四叔说，他豪侠仗义，始终没对不起我的爹妈。");  
          return 1;
           }
        else if (arg=="不砍")
                {
                command("say 可是他～～他害得我一生孤苦！");
                return 1;
          }
        else if (arg=="不知道")
                {
                command("sigh");
                command("say 我也不知道！");
                if (query("xsfh")>0)
                        {
                command("say 那就将这本书送与你仔细研究吧。");
                book=new("/d/reborn/jinyong/obj/xsfh");
                book->move(player);
                me->add("xsfh",-1);     
         }
         return 1;      
            }
         else
                return 0;                                       
}
