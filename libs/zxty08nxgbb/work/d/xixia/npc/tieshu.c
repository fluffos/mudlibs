//Cracked by Roath
// modified by daniel 2005/07/07
#include <ansi.h>

inherit NPC;
static string *c_digit = ({ "零","十","百","千","万","亿","兆" });
static string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
static string *c_random = ({"","零","一十","二百","","三千","","十四","零五","","六","七","七","八","六百十","","十","百","千","万","亿","兆"});
static mapping *se_random = ({ 
([     "yanse":       HIC    ]), 
([     "yanse":       HIW    ]), 
([     "yanse":       HIG    ]), 
([     "yanse":       HIR    ]), 
([     "yanse":       HIM    ]), 
([     "yanse":       HIB    ]), 
([     "yanse":       HIY    ]), 
([     "yanse":       NOR    ]), 
([     "yanse":       CYN    ]), 
});
int k;
int ask_me();
int ask_guess();
// updated by Zjb@TY
string yanse(int a)
{
     int c = 7;

     while( c == a )
     c = random(8);

     return se_random[c]["yanse"];
}
// updated by Zjb@TY
string chinese_ty(int i)
{
        if (i < 0)
                return "负" + chinese_ty(-i);
        if (i < 11)
                return se_random[k]["yanse"]+c_num[i]+yanse(k)+c_random[random(20)];
        if (i < 20)
                return se_random[k]["yanse"]+c_digit[1] +yanse(k) + c_random[random(20)]+se_random[k]["yanse"]+ c_num[i - 10]+yanse(k)+c_random[random(20)];
        if (i < 100) {
                if (i % 10)
                        return se_random[k]["yanse"]+c_num[i / 10] +yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
c_digit[1] +yanse(k)+ c_random[random(20)]+se_random[k]["yanse"]+ c_num[i % 10] +yanse(k)+c_random[random(20)];
                else
                        return se_random[k]["yanse"]+c_num[i / 10] +yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[1]+yanse(k)+c_random[random(20)];
        }
        if (i < 1000) {
                if (i % 100 == 0)
                        return se_random[k]["yanse"]+c_num[i/100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[2]+yanse(k);
                else if (i % 100 < 10)
                        return se_random[k]["yanse"]+c_num[i/100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[2]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+chinese_ty(i % 100);
                else if (i % 100 < 10)
                        return se_random[k]["yanse"]+c_num[i / 100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[2]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[1]+yanse(k)+c_random[random(20)]+chinese_ty(i % 100);
                else
                        return se_random[k]["yanse"]+c_num[i / 100]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[2]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 100);
        }
        if (i < 10000) {
                if (i % 1000 == 0)
                        return se_random[k]["yanse"]+c_num[i / 1000]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[3]+yanse(k);
                else if (i % 1000 < 100)
                        return se_random[k]["yanse"]+c_num[i / 1000]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[3]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+ chinese_ty(i % 1000);
                else
                        return se_random[k]["yanse"]+c_num[i / 1000]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[3]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 1000);
        }
        if (i < 100000000) {
                if (i % 10000 == 0)
                        return chinese_ty(i / 10000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[4]+yanse(k);
                else if (i % 10000 < 1000)
                        return chinese_ty(i / 10000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[4]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+ chinese_ty(i % 10000);
                else
                        return chinese_ty(i / 10000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[4]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 10000);
        }
        if (i < 1000000000000) {
                if (i % 100000000 == 0)
                        return chinese_ty(i / 100000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+ c_digit[5]+yanse(k);
                else if (i % 100000000 < 1000000)
                        return chinese_ty(i / 100000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[5]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                        c_num[0]+yanse(k)+c_random[random(20)]+chinese_ty(i % 100000000);
                else
                        return chinese_ty(i / 100000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[5]+yanse(k)+c_random[random(20)]+
                        chinese_ty(i % 100000000);
        }
        if (i % 1000000000000 == 0)
                return chinese_ty(i / 1000000000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[6]+yanse(k);
        else if (i % 1000000000000 < 100000000)
                return chinese_ty(i / 1000000000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[6]+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+
                c_num[0]+yanse(k)+c_random[random(20)]+ chinese_ty(i % 1000000000000);
        else
                return chinese_ty(i / 1000000000000)+yanse(k)+c_random[random(20)]+se_random[k]["yanse"]+c_digit[6]+yanse(k)+c_random[random(20)]+
                chinese_ty(i % 1000000000000);
}


void create()
{
        set_name("赫连铁树", ({ "helian tieshu", "helian", "tieshu" }) );
        set("nickname", "西夏王爷");
        set("title", "征东大将军");
        set("gender", "男性");
        set("age", 45);
        set("long",
                "此人身穿大红锦袍，鹰钩鼻、八字须。\n");
        set("combat_exp", 50000000);
        set("shen_type", -1);
        set("no_get", 1);
        set("attitude", "heroism");
        set("zjb_dj/dj",10);

        set("str", 126);
        set("con", 122);
        set("int", 120);
        set("dex", 124);

        set("max_qi", 80000);
        set("eff_qi", 20000);
        set("qi", 80000);
        set("max_jing", 50000);
        set("jing", 50000);

        set_temp("apply/attack",  60);
        set_temp("apply/defense", 60);

        set_skill("parry", 1060);
        set_skill("unarmed", 1060);
        set_skill("dodge", 1060);
        set("inquiry",
        ([
                "效命" : (: ask_me :),
                "guess" : (: ask_guess :),
        ]));


        setup();

        carry_object("/d/city/obj/xiupao")->wear();
}
void init()
{
        add_action("do_kill", "kill");
}
int do_get_gift(string arg, object me)
{ 
int a = me->query_temp("xixia/guess_a");
int b = me->query_temp("xixia/guess_b");
int c = me->query_temp("xixia/guess_c");
  int str;
 
  sscanf(arg,"%d",str);

   if( !arg ) {
         tell_object(me,HIC"\n ----------------〖问题〗……〖~^"+ chinese_ty(a) +"〗加上~〖"+ chinese_ty(b) +HIC+"〗，得到的值是多少？----------------\n"NOR);
   tell_object(me,HIY" ----------------  回答请直接输入问题答案  ----------------\n"NOR);
        input_to((:do_get_gift:), me);
   return 1;
    }


    if( str == c) 
{

    tell_object(me,HIC"----------------恭喜你，你答对了，可以要任务了!----------------\n"NOR);
me->set_temp("xixia/okguess",1);
                      me->set_temp("xixia/guess2",time());
                       me->set_temp("xixia/guess3_2",time());
   if (!me->query_temp("xixia/guess3_3",1)){ me->set_temp("xixia/guess3_3",(me->query_temp("xixia/guess3_2",1) - me->query_temp("xixia/guess3_1",1)));}


//      return 1;    
 /*
    if((me->query("xixia/guess3_2") - me->query("xixia/guess3_1"))!=me->query("xixia/guess3_3"))
{
me->set_temp("xixia/okguess",1);
} 
*/
       return 1;    

}
      tell_object(me,HIC"\n ＷＲＯＮＧ！----------------\n"NOR);

   return 1;
  
}
int ask_guess()
{
        object me = this_player();
        int a, b, c, d;
        if ( me->query_temp("xixia/guess") > time() )
        {
                 tell_object(me, HIR "你刚进行过智力测验，请等一下再来测验吧!!~~\n" NOR);
                 return 1;
        }
        if (  (int)me->query("yipin/done3") >3 ) {
                say("赫连铁树冷笑道：不错嘛，好样的。\n");
                me->delete_temp("xixia/guess3_3");
                me->delete("yipin/done3");

        }
/*
     if ( me->query("id") =="zisha" )
  {
             tell_object(me, HIR "你刚进行过智力测验，请等一下再来测验吧!!~\n" NOR);
           return 1;
   }
*/
a = random(9999)+100;
b = random(9999)+100;
c = a+b;
d = random(7);

k = d;
        

        {
//                 tell_object(me, HIR "----------------OK,现在请输入任意键开始作答！----------------\n" NOR);
         tell_object(me,HIC"\n ----------------〖问题〗……〖~^"+ chinese_ty(a) +"〗加上~〖"+ chinese_ty(b) +HIC+"〗，得到的值是多少？----------------\n"NOR);
   tell_object(me,HIY" ----------------  回答请直接输入问题答案  ----------------\n"NOR);

                     me->set_temp("xixia/guess_a",a);
                     me->set_temp("xixia/guess_b",b);
                     me->set_temp("xixia/guess_c",c);
                       me->set_temp("xixia/guess",time()+8);
                       me->set_temp("xixia/guess1",time()+60);
                       me->set_temp("xixia/guess3_1",time());


         input_to((:do_get_gift:), me);    
              return 1;
        }
}

int do_kill(string arg)
{
        object ob;
        int i;

        if (!arg || !id(arg)) return 0;

        if (present("wu shi", environment(this_object()))){

                command("say 你想谋害本官，当真是自找死路！ 左右何在！");
                message_vision("赫连铁树左右的武士对$N发动攻击！\n", this_player());

                for(i=0; i<2; i++) {
                        if( objectp( ob = present("wu shi " + (i+1), environment(this_object())) ) )
                                ob->kill_ob(this_player());
                }
                this_player()->apply_condition("xakiller", 100);
        }
        return 0;
}

int ask_me()
{
        object ob, room, me=this_player();
/*
        if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");

        if (userp(me) && me->query("id") == room->query("winner") ) {
                command("say 阁下是武林盟主，本堂可担待不起！");
                return 1;
        }
*/
        if ((int)me->query("combat_exp") > 280000000){
                   say("赫连铁树大怒道：去升级了再来见我！\n");
                return 1;
        }
        if ((int)me->query_condition("ypjob") > 0) {
                say("赫连铁树大怒道：他妈的，颁给你的活还没完成，居然敢有脸来见我！\n");
                command("slap " +me->query("id"));
                return 1;
        }

        if ((int)!me->query_temp("xixia/okguess")) {
                say("赫连铁树大怒道：没测试智力就想要任务,我可不要白痴小弟弟！\n");
                command("slapslap " +me->query("id"));
                return 1;
        }


    if((me->query_temp("xixia/guess3_2",1) - me->query_temp("xixia/guess3_1",1))==me->query_temp("xixia/guess3_3",1)&& me->query("yipin/done3")>0)
{
                say("赫连铁树大怒道：没测试智力就想要任务,我可不要白痴小弟弟！\n");
                command("slapslap " +me->query("id"));
                me->delete_temp("xixia/okguess");
                me->add_temp("xixia/robot",1);
                return 1;
}

        if (  (int)me->query("yipin/failure") >10 ) {
                command("sneer " +me->query("id"));
                say("赫连铁树冷笑道：你先歇几天吧，我手头这几桩差事可信不过让你去做。\n");
                me->delete_temp("xixia/testpass");
                me->delete_temp("xixia/一品堂");
                me->delete_temp("apply/short");
                me->apply_condition("ypjob", 100);
                return 1;
        }

        if (me->query_temp("xixia/一品堂")) {
                command("nod " +me->query("id"));
                me->apply_condition("ypjob", 70);
                if (me->query_condition("xakiller") > 0)
                me->apply_condition("xakiller", 0);
                if (me->query_temp("xixia/robot") > 3)
                me->set_temp("xixia/robot",2);
                call_out("assign_job", 1, me);
                return 1;
        }

        if ((int)me->query_temp("xixia/testpass")) {
                say("赫连铁树哈哈大笑道；好！今天起你就在我西夏一品堂下任事吧！\n");
                me->set_temp("xixia/一品堂",1);
                me->delete_temp("xixia/testpass");
                me->set_temp("apply/short",
     ({ HIW"西夏一品堂武士 "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
                me->apply_condition("ypjob", 70);
                if (me->query_condition("xakiller") > 0)
                me->apply_condition("xakiller", 0);
                call_out("assign_job", 1, me);
                return 1;
        } else {
                return notify_fail ("赫连铁树说道：你去问努儿海吧。\n");
        }
}

private int is_suitable(object victim, object killer)
{
        string *no_kill_list = ({
                "mu ren",
                "mengzhu",
                "shangshan shizhe",
                "fae shizhe",
                "xuantong dashi",
                "feng qingyang",
                "huang zhen",
                "juexin dashi",
                "yideng dashi",
                "ren woxing"

        });

        if( //   || victim->query("combat_exp") > killer->query("combat_exp")*7/4
          !clonep(victim) || userp(victim) 
         || victim->query("race") != "人类"
//       || victim->query("shen") < 0
//       || victim->query("winner")
         || strsrch(base_name(victim), "/kunfu/skill") == 0
         || strsrch(base_name(victim), "/d/xiakedao/") == 0
         || strsrch(base_name(victim), "/d/beijing/") == 0
         || strsrch(base_name(victim), "/clone/user") == 0
         || strsrch(base_name(victim), "/u/") == 0
         || strsrch(base_name(victim), "/d/player/") == 0
         || strsrch(base_name(victim), "/d/xiangyang/") == 0
          || strsrch(base_name(victim), "/d/city/") == 1
         || member_array(victim->query("id"), no_kill_list) != -1 ) 
        {
                return 0;
        } 
        return 1;
}

void assign_job()
{
object me = this_player();
        object ob, ob2;
        string str;
                mapping quest;
        quest = (__DIR__"where")->query_quest();
                ob2 = new(__DIR__"killer1");
     if ( (int)me->query("yipin/done1")>4)    { quest = (__DIR__"where1")->query_quest(); me->delete("yipin/done1");}
                
                ob2->do_copy(me,1);
                ob2->set_temp("must_killby",me->query("id"));
                ob2->set("quest_npc",1);
                  me->set_temp("job2_target", quest["short"]);
                ob2->move(quest["place"]);

tell_object(me,HIW"我听说『"+ob2->query("id")+"』近日一直跟我们西夏国作对,你去帮我把他杀了!\n"NOR);
tell_object(me,HIY"据说他在『"+quest["short"]+"』一带出现\n"NOR);
        tell_object(me,"赫连铁树说完扔给你一块青铁令。\n");
        ob=new(__DIR__"obj/ypling");
         ob->set("long", "这是一块西夏一品堂堂主令。上面写着“"+ob2->query("id")+"”。\n");
        ob->set("victim", ob2->query("id"));
        ob->set("owner", me->query("id"));
        ob->move(me);
}

int accept_object(object who, object ob)
{
        string *award_list = ({
        "渡难",
        "渡劫",
        "渡厄",
        "洪七公",
        "黄药师",
        "周芷若",
        "张三丰"
        });

        int gain, pot;


        if ( ob->query("owner") != who->query("id")){
                command("say 你给我这个干吗??");
                return 0;
        }
        if (ob->query("id") != "head" ){
                command("say 你给我这个干吗?");
                return 0;
        }


  if (time() - who->query_temp("xixia/guess1") <2){
              command("say 别急，这里忙着呢?");
              return 0;
       }


        if (who->query_temp("xixia/一品堂")){
//      if (who->query_temp("xixia/guess") < who->query_temp("xixia/guess2")){
            gain = who->query_condition("ypjob")*2500+105000; 
        pot = who->query_condition("ypjob")*500+1000;
//  }
           if (who->query_temp("xixia/robot")>0 ){
            gain = 8000; 
        pot = 2000;
tell_object(who,HIW"由于你使用了机器人作业，系统将你的奖励下降了!\n"NOR);
}
                if (who->query_condition("ypjob") > 0){
                who->add("combat_exp", gain);
                who->add("potential", pot);
                who->delete_temp("xixia/okguess");
//                if (who->query("potential") > who->query("max_potential"))
//                        who->set("potential", who->query("max_potential"));
tell_object(who,HIW"恭喜你,你得到了『"+gain+"』的经验和『"+pot+"』的潜能奖励!\n"NOR);
                command("u&me "+who->query("id"));
                command("say 凭青铁令去努尔海那里领工钱吧。");
                who->add("yipin/done", 1);
                who->add("yipin/done1", 1);
                who->add("yipin/done3", 1);
           if (who->query_temp("xixia/robot")>0 ){
                who->add_temp("xixia/robot", -1);
 }

                who->apply_condition("ypjob", 0);
        call_out("destroy_it", 1, ob);

           if (random(9999) < 2 && who->query("yipin/done")>20)
{
tell_object(who,HIG"你有机会获得终极终极矿物,请赶快到矿区挖啊!\n"NOR);
        who->add("canwazhongji",1);
        who->delete("yipin/done");
//     if (who->query_temp("xixia/guess") < who->query_temp("xixia/guess2")){
}


        if (member_array(ob->query("victim_name"), award_list) >= 0  
        && ob->query("combat_exp") > who->query("combat_exp")*3/2)
                who->add("combat_exp", gain*30);                
        }
        else {
                command("kick "+who->query("id"));
                say("赫连铁树大怒道：没用的东西，这麽半天才干完活，亏你还有脸回来见我！\n");
                who->add("yipin/failure", 1);
                who->delete_temp("xixia/okguess");
        }               
        call_out("destroy_it", 1, ob);
        return 1;
        }
}

  void destroy_it(object obj)
{
          destruct(obj);
        return;
}

void unconcious() 
{ 
         reincarnate(); 
         set("eff_qi", query("max_qi")); 
          set("qi", query("max_qi")); 
           set("eff_jing", query("max_jing")); 
          set("jing", query("max_jing")); 
             set("jingli", query("eff_jingli"));
          say( "蠢小蛋突然出现在你的面前，说道你怎么可以杀死我的手下呢 ？！\n"); 
       } 
 void die() 
 { 
        unconcious(); 
 } 


