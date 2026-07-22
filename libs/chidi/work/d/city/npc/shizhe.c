#include <ansi.h>
inherit BHNPC;
string ask_me();
string ask_toutai();
string ask_liwu();

void create()
{
    set_name(HIR"江湖使者"NOR, ({ "mud shizhe", "shizhe" }) );
         set("nickname", HIY"不知情愁枉少年"NOR);
        set("gender", "男性" );
        set("age", 18);
        set("long", YEL"这位是〖江湖〗的使者，向他打听“江湖”，他会带给您想不到的惊喜。\n"NOR);
        set("shen_type", 1);
        set("combat_exp", 999999999);
        set("str", 300);
        set("dex", 300);
        set("con", 300);
        set("int", 30);
        set("per", 30);
        set("attitude", "friendly");
        set("max_qi", 100000);
        set("neili", 100000);
       set("jingli",21000000);
        set("score", 100000);

        set("inquiry", ([
                       "江湖" : (: ask_me :),
                        "投胎" : (: ask_toutai :),
        ]));
        setup();
}

void init()
{
        object ob=this_object();
        
        if( interactive (ob) )
        {
        remove_call_out("story_check");
        //remove_call_out("check_time");
        }

        if( !ob->query_temp("story_start") )
        {
        call_out("story_check",2);
        ob->set_temp("story_start",1);
        }          
       /* 
        if( !ob->query_temp("check_time") )
        {
        call_out("check_time", 1);
        ob->set_temp("check_time",1);
        }
       */
        ob = this_player();     
        ::init();
        /*if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        */
}

void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
  command("whisper " + ob->query("id") + " "HIW"欢迎光临〖本MUD〗"+HIR+"(ask shizhe about 江湖)\n"+NOR+HIW+"， 小的助您行走江湖．"NOR);


}

string ask_me()
 {
        object me = this_player();
        object ob1;
        object ob2;
        object ob3;
        object liwu;
        mapping fam; 
        
         if ((int) me->query("welcomexhc"))
                return "呵呵～这就是您的不是了！小的已经对您施过法力了！";
               else
        {
                me->set("welcomexhc", 1);
                me->set("max_neili", 100000);
                me->add("neili", 10000);
                me->add("jingli", 10000);
                me->set("max_jingli", 50000);
                me->add("potential", 1000000);
                me->add("food", 15000);
                me->add("water", 15000);
//      me->set("int", 530);
                me->set("per", 30);
                me->set("kar", 30);
        
                
                  me->add("combat_exp",2000000);
                  me->set_skill("literate",1000);
                  me->set_skill("force",300);
                  me->set_skill("dodge",300);
                  me->set_skill("unarmed",300);
                  me->set_skill("sword",300);
                  me->set_skill("parry",300);
                  me->set_skill("blade",300);
 ob1 = new("/d/jh/weapon/jue/jue1");
ob2 = new("/d/jh/weapon/jue/jue1");
            //    ob3 = new("/clone/shoufei/item/roombox"); 
 ob1->move(me); 
  ob2->move(me); 
            //    ob3->move(me); 


/*--------------------------------------------------------------------------------
                  me->set_skill("literate",me->query_skill("literate",1)+1000);
                  me->set_skill("force",me->query_skill("force",1)+300);
                  me->set_skill("dodge",me->query_skill("dodge",1)+300);
                  me->set_skill("unarmed",me->query_skill("unarmed",1)+300);
                  me->set_skill("sword",me->query_skill("sword",1)+300);
                  me->set_skill("parry",me->query_skill("parry",1)+300);
                  me->set_skill("blade",me->query_skill("blade",1)+300);
---------------------------------------------------------------------------------*/

      CHANNEL_D->do_channel(me, "es", sprintf("在下%s今日光临〖江湖〗 现已得到江湖使者的帮助和奖励！即日起开始行走江湖了！", me->name(1)));
               return "欢迎光临"NOR+HIR"〖江湖〗"NOR"，小的护架来迟，罪该万死！在下可助您行走江湖！\n"
HIW"突然天空中一道"HIM"七"HIY"彩"HIR"霞"HIC"光"HIW"笼罩四方，转瞬即逝！"NOR;
        }
}

string ask_toutai()
 {
        object me = this_player();
        mapping fam; 
        
         if ((int) me->query("tt"))
                return "投胎一次够了!";
               else
        {    
                me->set("tt",1);
                me->move("/d/register/entry");
              
        }
}

string ask_liwu()
 {
       object me = this_player();
       object liwu,liwu2,liwu3,liwu4;

       mapping fam; 
        
        
         if ((int) me->query("5.1liwu"))
                return "你已经领取过五一劳动节礼物了!";
               else
        {    command("say 好的！你拿好您的五一劳动节礼物，祝你新春快乐！吉祥如意！");
CHANNEL_D->do_channel(me, "es", sprintf("%s祝〖江湖〗的所有玩家五一劳动节快乐！万事如意！心想事成！", me->name(1)));
                me->set("5.1liwu",1);
       liwu=new("/clone/gift/gift/karwan");       
       liwu2=new("/clone/gift/gift/unknowdan");
       liwu3=new("/clone/gift/gift/xiandan");      
       liwu4=new("/clone/gift/gift/xisuidan");
       liwu->move(me);                                        
       liwu2->move(me);         
       liwu3->move(me);  
       liwu4->move(me);  
        }

}

int story_check()
{
        string *story_msg=({}),str;
        int story_msg_len;
        story_msg+= ( {"新手请◇fly yz◇【ask shizhe about 江湖】领取丰富的奖励后，开始您的冒险旅程！\n"});
        story_msg+= ( {"奖励内容:福缘30★容貌30★内力10万★精力5万★基本技能300级★读书写字1000级★经验200万★潜能100万★！\n"});
        story_msg+= ( {"为了避免选双特技号而浪费你的时间，这里增大出现了双特技几率，祝你在游戏愉快！\n"});
        story_msg+= ( {"转世、升级系统、练药、杨公宝藏、终级技能，王朝任务等你归来！\n"});
        story_msg+= ( {"本站IP地址:220.161.4.202 9000\n"});
        story_msg+= ( {"本站QQ群： 328647723   欢迎您的加入！\n"});
        story_msg_len=sizeof(story_msg);
        str=story_msg[random(story_msg_len)];

        message("channel:rumor",sprintf(HIM"【系统】："HBMAG+HIG"%s\n" NOR, str),users());
        remove_call_out("story_check");
        call_out("story_check",300);
}
