// linzhennan.c 林震南
// modified by Jay 4/7/96

#include <ansi.h>


inherit NPC;
//inherit F_SKILL;
string ask_me();
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
        set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "男性");
        set("age", 45);
        set("long", "他就是「福威镖局」的总镖头－－林震南。\n");

        set("combat_exp", 30000);
        set("shen_type", 1);

        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 40);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set("inquiry", ([
                "向阳老宅" : "林震南说道：那是我从前在福建时住的家院，已经破败了。\n",
                "福威镖局" : (: ask_fuwei :),
                "远图公" : (: ask_yuantu :),
                "林远图" : "林震南大怒：小孩子这么没礼貌，直呼先人名讳！\n",
                "辟邪剑法" : (: ask_pixie:),
                "铜钱" : (: ask_tong:),
                "铜板" : (: ask_tong:),
                "镖"   : (: ask_me :),
                "biao"   : (: ask_me :),
                "quest"   : (: ask_me :),
                "运镖" : (: ask_me :),
                "任务" : (: ask_me :),
                "工作" : (: ask_me :),
        ]) );


        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_fuwei()
{
 say("林震南炫耀地说：我们林家三代走镖，一来仗着先祖远图公当年闯下的威名，二\n"
     "来靠著我们林家家传的玩艺儿不算含糊，这才有今日的局面，成为大江以南首屈\n"
     "一指的大镖局。江湖上提到『福威镖局』四字，谁都要翘起大拇指，说一声：『\n"
     "好福气！好威风！』哈哈，哈哈！\n");
 this_player()->set_temp("marks/林1", 1);
 return 1;
}

int ask_yuantu()
{
  if ((int)this_player()->query_temp("marks/林1")) {
 say("林震南磕一磕烟斗，说道：远图公是我的祖父，福威镖局是他一手创办的。当年\n"
     "祖父以七十二路辟邪剑法开创镖局，当真是打遍黑道无敌手。其时白道上英雄见\n"
     "他太过威风，也有去找他比试武艺的，青城派掌门余观主的师父长青子少年之时\n"
     "便在他辟邪剑法下输了几招。\n");
 this_player()->set_temp("marks/林2", 1);
 return 1;
  }
  else {
 say("林震南说道：远图公是我的祖父。\n");
 return 1;
  }
}

int ask_pixie()
{
  int p1, p2, p3, p4;

  if ((int)this_player()->query("passwd")) {
 say("林震南不悦地说道：我不是都告诉你了吗？我的剑法不及先祖。\n");
  }
  else if ((int)this_player()->query_temp("marks/林2")) {
 say("林震南一惊，说道：你怎么知道的？噢，我刚才说露嘴了。嗨，在下的功夫外人\n"
     "不知底细，其实及不上先祖。。\n");
 write("林震南顿一顿，接着对你低声说：先祖去世前，曾给家父留下");
 p1=random(4)+1;
 p2=random(4)+1;
 p3=random(4)+1;
 p4=random(4)+1;
 this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
 write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
       "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
 write("个\n铜钱，我一直未解其中奥秘。\n");
  }
  else {
   message("vision",
   HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"
   NOR, environment(), this_object() );
   kill_ob(this_player());
  }
  this_player()->delete_temp("marks/林1");
  this_player()->delete_temp("marks/林2");
  return 1;
}

int ask_tong()
{
  int p, p1, p2, p3, p4;

  if (!(p=(int)this_player()->query("passwd"))) {
 say("林震南一脸讥笑的样子，说：怎么混到这一步了到处要钱？\n");
  }
  else {
 write("林震南低声说：先祖去世前，曾给家父留下");
 p1=(int)p/1000;
 p2=(int)(p-p1*1000)/100;
 p3=(int)(p-p1*1000-p2*100)/10;
 p4=(int)(p-p1*1000-p2*100-p3*10);
 write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
       "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
 write("个\n铜钱，我一直未解其中奥秘。\n");
  }

  return 1;
}
//quest
string ask_me()
{
        string *target=({
"xu zhu",
"tong lao",
"hong antong",
"jiumo zhi",
"miejue shitai",
"song yuanqiao",
"fang bilin",
"ling huchong",
"zhang sanfeng",
"zhang wuji",
"ouyang feng",
"ding chunqiu",
"yue wife",
"su xinghe",
"huang yaoshi",
"zhaixing zi",
"xuanku dashi",
"xuannan dashi",
"qian yankai",
"tang nan",
"jia laoliu",
"guan anji",
"li lishi",
});
        string *dest=({
"「梦郎」虚竹",
"「唯我独尊」天山童姥",
"「永享仙福」洪安通",
"「大轮明王」鸠摩智",
"「峨嵋派第三代掌门」灭绝师太",
"「武当首侠」宋远桥",
"峨嵋派第四代弟子 方碧琳",
"「大师兄」令狐冲",
"「邋遢真人」张三丰",
"明教教主 张无忌",
"「西毒」欧阳锋",
"「星宿老怪」丁春秋",
"华山派第十三代弟子 宁中则",
"「聪辩老人」苏星河",
"「东邪」黄药师",
"「星宿派大师兄」摘星子",
"「罗汉堂首座」玄苦大师",
"「般若堂首座」玄难大师",
"「铁公鸡」钱眼开",
"当铺老板 唐楠",
"贾老六",
"关安基",
"李力世",
});
        int i,num,ran,t,time;
        object ob,who;

        who=this_player();

        t=time()-who->query("biao_start");
        time=who->query("biao_time");

        if( t <= time ) 
                return RANK_D->query_respect(who)+"似乎还有任务在身吧？\n";

        if( t > time && t < (time+300) ) {
                if(ob=present("biao yin",who) ) destruct(ob);
                who->set("biao_failed",1);
        }
        if( t >= (time+300) ) 
                who->delete("biao_failed");

        if ((int)who->query_condition("zzz_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：现在没有镖要送,等会再来!\n", this_object(), who);
             return  "这位"+RANK_D->query_respect(who)+"还是另寻门路去吧。\n";
            }

   if((int)who->query("combat_exp") > 1000000)
{
message_vision("林震南对$N说道：“这点小事，怎么能叫大侠动手！”\n",who);
                return  "我可不敢让您来做这种小事，"+RANK_D->query_respect(who)+"还是另寻门路去吧。\n";
//return 1;
}
        if(who->query("biao_failed") ) {
                command("sigh "+who->query("id"));
                return  "我可不敢再冒这个险了，"+RANK_D->query_respect(who)+"还是另寻门路去吧。\n";
        }

        command("say 正好，我这里有宗镖要你来送。");
        i=10+random(10);
        num=(10+random(10))*100;
        ran=random(sizeof(target));
        command("say 请你在"+chinese_number(i)+"天内把这"+chinese_number(num)+"两镖银送去"+dest[ran]+"的手中。");

        ob=new(__DIR__"biao");
        ob->set("target",target[ran]);
        ob->set("amount",num);
        who->set("biao_start",time());
        who->set("biao_time",10*i);
        who->start_busy(3);
        ob->move(who);
        return  "快快动身吧！\n";
}
