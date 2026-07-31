// linzhennan.c 林震南
// modified by Jay 4/7/96

#include <ansi.h>
int potential_lv(int exp);
inherit NPC;
//#define CART_PATH "cart"
//string do_quest();

string* dart_area=({"/d/beijing/dangpu","/d/beijing/qianzhua","/d/city/qianzhuang",
"/d/foshan/dangpu","/d/xiangyang/dangpu","/d/suzhou/dangpu","/d/cangzhou/bank","/d/city4/qianzhuang",
"/d/chengdu/qianzhuang","/d/jinling/qianzhuang","/d/jinling/dangpu","/d/tanggu/dangpu","/d/kunming/dangpu","/d/jingzhou/qianzhuang"});
string* dart_short=({"北京当铺","北京钱庄","扬州钱庄",
"佛山英雄典当","襄阳当铺","苏州宝和记","沧州天音阁","长安相记钱庄",
"成都川号钱庄","金陵穆记钱庄","金陵天马当铺","塘沽万福典当","昆明当铺","荆州钱庄"});
string* dart_id=({"jia laoliu","qian laoben","qian yankai","lao chaofeng","qiu hang",
"wang heji","jiang tiaohou","tie suanpan","ma youcai","banker","xia tian","yin laoban","liu tong","qian defa"});
string* dart_name=({"贾老六","钱老本","钱眼开","老朝奉","邱航","王合计","蒋调侯","铁算盘","马有财","穆守财","夏天","殷老板","刘通","钱得发"});

string do_job();
string do_give();
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
        set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "男性");
        set("age", 45);
        set("title", "福威镖局总镖头");
        set("long", "他就是「福威镖局」的总镖头－－林震南。\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);
        set_skill("force", 40);
        set("per",19);
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
                "运镖" : (: do_job :),
                "镖"   : (: do_job :),
                "工作" : (: do_job :),
                "job"  : (: do_job :),
                "领赏" : (: do_give :),
                "over" : (: do_give :),
        ]) );
        set_temp("no_get",1);
        set_temp("no_kill",1);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 400);
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
                message("vision", HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"
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

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "天";
        else time = "";
        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return time;
}

string do_job()
{   int n;
    object ob,cart;
    ob=this_player();
    n=random(sizeof(dart_area));

    if ( ob->query_temp("in_dart"))
       return "你不是才要了任务吗？\n";
    if (environment(ob)->query("short")!="正厅")
       return "这里是什么地方？\n";
    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "你好象没完成任务吧。\n";
    if ((int)ob->query_condition("menpai_busy"))
       return "护镖是件危险工作，我看"+ob->query("name")+"需要休息一会！\n";
    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";

    if ( (int)ob->query("combat_exp") < 1000000 )
       return "护镖是件危险工作，我看"+RANK_D->query_respect(ob)+"似乎没有这能力！\n";

    if ( (int)ob->query_skill("force",1) < 100 )
       return "护镖是件危险工作，我看"+RANK_D->query_respect(ob)+"的基本内力不足！\n";

    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
	ob->set_temp("dart_short",dart_short[n]);
    ob->apply_condition("dart_limit", 1800);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/d/fuzhou/biaojuzt");
    command("nod");
    message_vision(CYN "几个伙计将镖推了出来。\n" NOR,ob);
    message("channel:chat",HIW"【小道消息】："HIW"据说"+ob->query("name")+HIW"接了批运往"+dart_short[n]+HIW"的镖。\n"NOR,users());
    return "你把这批红货送到"+dart_short[n]+"的"+dart_name[n]+"手中。\n";

}

string do_give()
{
int bonus;
  object ob,obj;
 int max_pot;

  ob=this_player();
   max_pot=20000+random(20000);

  if ( !ob->query_temp("in_dart"))
    return "我没让你走镖啊？\n";

  if (environment(ob)->query("short")!="正厅")
       return "这里是什么地方？\n";

  if ( !ob->query_temp("over_dart") )
    return "镖车没有送到地头，莫非是你吞了！？\n";

  ob->delete_temp("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  ob->delete_temp("dart_short");

    ob->add("combat_exp",max_pot);
    ob->add("potential",max_pot/2);
  obj=new("/clone/money/gold");
  obj->set_amount(5+random(5));
  obj->move(ob);
  write("本次运镖奖励了"+max_pot+"点修为和"+max_pot/2+"点潜能和些许黄金。\n");
  command("pat "+ob->query("id"));
  return RANK_D->query_respect(ob)+"果然是栋梁之才！\n";
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}

