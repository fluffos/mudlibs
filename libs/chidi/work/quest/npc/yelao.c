// writed by xingyun 22/5/2001
inherit BHNPC;
#include <ansi.h>
#include "chousha.h"   
#include "place_room.h"
#include "haojie.h"
string ask_shengshi();
string ask_haojie();
void load_killer(int num);
int killer_times;

void create()
{
        set_name("天机老人", ({ "wulin yelao", "yelao"}));
        set("gender", "男性");
        set("age", 120);
        set("nickname", HIW"古往今来 " HIM" 无所不知 "HIG" 笑傲江湖 "HIY" 天下无敌" NOR);
        set("long",
"传说中的武林前辈，据说此老乃百年前的武林宿耄，现今已百岁高龄。\n"
"他笑傲武林数十载，天下的武功，各门各派奇闻轶事，古往今来武林\n"
"典故，号称是“无所不知，无所不晓”。一身武功是出神入化，罕逢\n"
"敌手，至今数十年未曾与人动手。多年来一直隐居扬州城中评书为生，\n"
"每日在此讲述武林典故。\n");

        set("combat_exp", 15000000);
        set("shen_type", 1);
        set("max_neili", 40000);
        set("neili", 40000);
        set("max_qi",10000);
        set("max_jing",5000);
        set("max_jingli",10000);
        set("jingli",10000);
        set("per",25);
        set("jiali", 400);

        set_skill("xiantian-gong", 500);     
        set_skill("force", 500);
        set_skill("tiangang-zhengqi", 500);
        set_skill("dodge", 500);
        set_skill("qixing-huanwei", 500);
        set_skill("unarmed", 500);
        set_skill("kongming-quan", 500);
        set_skill("parry", 500);
        set_skill("sword", 500);
        set_skill("quanzhen-jianfa", 500);
        set_skill("qixing-array", 500);
        set_skill("taoism", 500);
        set_skill("finger",500);
        set_skill("yiyang-zhi",500);
        set_skill("literate", 400);
        map_skill("finger","yiyang-zhi");
        map_skill("force", "tiangang-zhengqi");
        map_skill("dodge", "qixing-huanwei");
        map_skill("unarmed", "kongming-quan");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");

        prepare_skill("finger", "yiyang-zhi");

        set("inquiry", ([
                "武林浩劫" : (: ask_haojie:),
                "浩劫" : (: ask_haojie :),
                "生死状" : (: ask_shengshi:),
                "生死" : (: ask_shengshi :)
             ]) );

        set("chat_chance", 1);
        set("chat_msg", ({  
CYN"天机老人捋了捋长须，哈哈大笑道：“张三丰那小道士，现在算起来"
    +"也该有些出息了！”\n"NOR,
CYN"天机老人轻抚掌中剑匣，无不得意地说道：“老夫纵横江湖百余载，"
    +"还真没遇到过对手！”\n"NOR,
CYN"天机老人微显扭捏之色，叹道：“林朝英那丫头，现在也不知道怎么样了。” \n"NOR, 
    }));  
        set("no_clean_up",1);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "finger.yizhi":),
                (: exert_function, "recover" :),
        }) );
        set("family/family_name","全真教");
        setup();

        carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        
}

void init()
{
        object ob=this_object();
        
        if( interactive (ob) )
        {
        remove_call_out("story_check");
        remove_call_out("check_time");
        }

        if( !ob->query_temp("story_start") )
        {
        call_out("story_check",2);
        ob->set_temp("story_start",1);
        }          
        
        if( !ob->query_temp("check_time") )
        {
        call_out("check_time", 1);
        ob->set_temp("check_time",1);
        }
}

int check_time()
{
        object *ulist;
        int num,n,chousha_count;
        object me=this_object();
        string temp;

        ulist=users();
        num=sizeof(ulist);
        num=num/2+random(num/2);
        if(num > 40) num=40;

        if((time()-query("shanzhuang_open")) > 1800)
        {
        message("channel:rumor", 
        HIY"【典故】天机老人：欢迎大家光临【江湖】！\n",users());
        me->set("shanzhuang_open",time());
        DYNAMIC_D->regenerate_map();
        }

        if((time()-query("chousha_begin")) > 5400 && num>9 && !query("chousha"))
        {
           temp=read_file("/quest/chousha/chousha_count",1,1);
           chousha_count=atoi(temp);
           if( chousha_count >= 2 && haojie_times < 1 )
           {
              set("chousha_begin",time()); 
              temp=sprintf("%d",time());
              write_file("/quest/chousha/time_begin",temp,1);   

              haojie_times=1;
              message("channel:rumor", HIR"【武林浩劫】"NOR+
              HIY"杀手帮"+HIR"阴谋称霸武林，浩劫已无可避免，"
              +"望各位武林同道同心协力，\n共御此次"
              +BLINK+HIW"  武 林 浩 劫  \n"NOR,users());

              call_out("haojie_begin",180,num);  
              call_out("haojie_close",3600);
           } else 
         {
           chousha_count++;
           temp=sprintf("%d",chousha_count);
           write_file("/quest/chousha/chousha_count",temp,1);

           message("channel:rumor",
           MAG"【江湖仇杀】"NOR+
           HIB"据说江湖中某两大门派为解宿怨，一个时辰内要以武力解决。\n"NOR,users());
           set("chousha_begin",time());
           set("chousha",1);
           temp=sprintf("%d",time());
           write_file("/quest/chousha/time_begin",temp,1);
           call_out("chousha_begin",60);
         }
        }

        if((time()-query("chousha_begin")) > 10 && query("chousha")
           && (time()-query("chousha_begin")) < 60)    
        message("channel:rumor", MAG"【江湖仇杀】"NOR+
        HIB"据可靠消息，会有两大门派在不久以后大火拼。\n"NOR,users());
        if((time()-query("chousha_begin")) > 70 && query("chousha") 
           && query("chousha")<4)
        {
         add("chousha",1);
         message("channel:rumor", MAG"【江湖仇杀】"NOR+HIR+fam1
         +HIC"与"+HIR+fam2
         +HIC"两大门派积怨已久，此刻正在北京城正相互仇杀。\n"NOR,users());
        }

        if( query("chousha") == 4 )
        {
             add("chousha",1);
             load_killer(num);
        }

        remove_call_out("check_time");
        call_out("check_time",30);
        return 1;
}

void load_killer(int num)
{
         object killer1,killer2;
         int n,time,exp_rate;
         string temp;

         if( killer_times >= 4 )
         {
             killer_times=1;
             remove_call_out("load_killer");
             exp_rate=6;
             temp=sprintf("%d",exp_rate);
             write_file("/quest/chousha/exp_rate",temp,1); 
             return;
         }

         killer_times++;
         for(n=0;n<num;n++)
         {
             time=query("chousha_begin")+1800-time();
             killer1=new("/quest/chousha/killer1");
             place_room("西城",killer1);
             killer2=new("/quest/chousha/killer2");
             place_room("东城",killer2);
             killer1->start_escape(time);    
             killer2->start_escape(time);
         } 

         remove_call_out("load_killer");
         call_out("load_killer",10,num);
         return;
}

int story_check()
{
        string *story_msg=({}),str;
        int story_msg_len;

        story_msg+= ( {"欢迎光临〖江湖〗(220.161.4.202 : 9000)。\n"
"                          〖江湖〗(QQ群: 328647723)。\n"} );
        story_msg+= ( {"欢迎光临〖江湖〗(220.161.4.202 : 9000)。\n"
"                          〖江湖〗(QQ群: 328647723)。\n"} );
        story_msg+= ( {"欢迎光临〖江湖〗(220.161.4.202 : 9000)。\n"
"                          〖江湖〗(QQ群: 328647723)。\n"} );
        story_msg+= ( {"欢迎光临〖江湖〗(220.161.4.202 : 9000)。\n"
"                          〖江湖〗(QQ群: 328647723)。\n"} );

        story_msg_len=sizeof(story_msg);
        str=story_msg[random(story_msg_len)];

        message("channel:es",sprintf(HIY"\n【江湖】天机老人：%s\n" NOR, str),users());
        remove_call_out("story_check");
        call_out("story_check",300);
}

string ask_shengshi()
{   
    object me;
    string fam1,fam2,temp;
    int exp_rate,exp;

    me=this_player();

    if(me->query_temp("chousha/ask"))
    return CYN"你现在已经加入江湖仇杀了，你的敌对门派是"
           +me->query_temp("chousha/fam")+"赶快去吧！\n"NOR;

    if(query("chousha")<2)
    return CYN"仇杀还没正式开始呢，先等一会吧！\n"NOR;    

    if(query("chousha")>3)
    return CYN"你来太迟了，赶不上这次仇杀了，等下次吧！\n"NOR;

    if(me->query("combat_exp")<1000000)
    return CYN"凭你现在这点本事，不相干的事还是不要多管的好！\n"NOR;

    if(me->query("score")<1000)
    return CYN"你在江湖中的声望太低了，估计没有哪个门派会邀请你！\n"NOR;

    exp=me->query("combat_exp");
    temp=read_file("/quest/chousha/exp_rate",1,1);
    exp_rate=atoi(temp);
    if( !wizardp(me) && (exp_rate*exp_rate/4) < exp/100000 )
    {
              do{
                  exp_rate++;
                } while( (exp_rate*exp_rate/4) < exp/100000 );

              temp=sprintf("%d",exp_rate);
              write_file("/quest/chousha/exp_rate",temp,1);  
    }

    fam1=read_file("/quest/chousha/fam1",1,1);
    fam2=read_file("/quest/chousha/fam2",1,1);

    if(me->query_temp("chousha/fam"))
    {
     me->set_temp("chousha/ask",1);
     command("chat "+me->query("name")+"加入江湖仇杀对付"
            +me->query_temp("chousha/fam")+"，生死由命，立状为凭！\n");

     if(me->query_temp("chousha/fam")==fam2)
     {
       me->set_temp("apply/short", 
           ({HIW+fam1+"同道"NOR+HIG"   江湖义士   "NOR+me->name()
           +"("+me->query("id")+")"}));
     } else
     if(me->query_temp("chousha/fam")==fam1)
     {
      me->set_temp("apply/short", 
           ({BLK+fam2+"助拳"NOR+HIG"   江湖豪客   "NOR+me->name()
           +"("+me->query("id")+")"}));
     }
    
     call_out("heading_for",10,me);  
     return CYN"你立刻前往北京加入此次江湖仇杀，一切好自为之了！\n"NOR;    
    }

    if( me->query("shen") >= 200000
       || ((me->query("shen") > -200000 && random(2))))  
    {
     me->set_temp("chousha/fam",fam2);
     me->delete_temp("apply/short");
     me->set_temp("apply/short", 
     ({HIW+fam1+"同道"NOR+HIG"   江湖义士   "NOR+me->name()+"("+me->query("id")+")"}));
    command("chat "+me->query("name")+"加入江湖仇杀对付"
            +fam2+"，生死由命，立状为凭！\n");
    } else
    {
     me->set_temp("chousha/fam",fam1);
     me->delete_temp("apply/short");
     me->set_temp("apply/short", 
     ({BLK+fam2+"助拳"NOR+HIG"   江湖豪客   "NOR+me->name()+"("+me->query("id")+")"}));
    command("chat "+me->query("name")+"加入江湖仇杀对付"
            +fam1+"，生死由命，立状为凭！\n");
    }

    me->set_temp("chousha/ask",1);
    call_out("heading_for",10,me);  
    return CYN"你立刻前往北京加入此次江湖仇杀，一切好自为之了！\n"NOR;
}

string ask_haojie()
{
    object me;
    int exp_rate,exp;
    string temp;

    me=this_player();
    if(me->query_temp("haojie/ask"))
    return CYN"你现在已经加入对抗浩劫了，赶快去吧！\n"NOR;   
  
    if( haojie_times < 1 )
    return CYN"现在江湖上好好的，你居心何在啊？！\n"NOR;

    if( haojie_times > 1 )
    return CYN"江湖英雄令发完了，正在准备中，你等会吧！\n"NOR;

    if(me->query("combat_exp") < 1000000 )
    return CYN"你还是先学好本领再来吧！\n"NOR;

    if(me->query("score")<1000)
    return CYN"你在江湖中的声望太低了，江湖英雄令你接不起啊！\n"NOR;

    exp=me->query("combat_exp");
    temp=read_file("/quest/chousha/killer_rate",1,1);
    exp_rate=atoi(temp);
    if( !wizardp(me) && (exp_rate*exp_rate/4) < exp/100000 )
    {
            do{
                  exp_rate++;
              } while( (exp_rate*exp_rate/4) < exp/100000 );

              temp=sprintf("%d",exp_rate);
              write_file("/quest/chousha/killer_rate",temp,1);
    }
    
    command("chat "+me->query("name")+"接下了"+HIW"江湖英雄令"
            +HIC"，对抗此次武林浩劫，江湖各路同道共勉！\n"); 

    me->delte_temp("apply/short");
    me->set_temp("apply/short",
          ({HIR"英雄令使  "NOR+me->name()+"("+me->query("id")+")"}));
    me->set_temp("haojie/ask",1);   
    me->set_temp("chousha/reward_exp",0);
    return CYN"呵呵，又是一个不怕死的，武林有望啊，多加小心吧！\n"NOR;
}

int heading_for(object me)
{
    string fam1,fam2;

    fam1=read_file("/quest/chousha/fam1",1,1);
    fam2=read_file("/quest/chousha/fam2",1,1); 

    if(objectp(me) && me->query_temp("chousha/fam"))
    {
     if( me->query_temp("chousha/fam") == fam2)
     me->move("/d/jingcheng/juyi");
     if( me->query_temp("chousha/fam") == fam1)
     me->move("/d/jingcheng/yingxiong");
    }
    message_vision(YEL"$N一路马不停蹄，连夜赶到了紫金城！\n"NOR,me);
    return 1;
}


