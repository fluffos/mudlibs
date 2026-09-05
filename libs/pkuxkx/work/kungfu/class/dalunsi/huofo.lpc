inherit NPC;
#include "ansi.h"

string ask_job();
void create()
{
    set_name("哲布尊巴丹",({"huofo","foye"}));
  set("title", RED"大活佛"NOR);
    set("gender", "男性" );
    set("class","huznxi");
    set("age", 80);
    set("long",
        "哲布尊巴丹活佛是一位著名的藏密经史大家，熟识各种藏密佛咒。\n");
    set("attitude", "peaceful");
    set("combat_exp", 5000000);
          set("inquiry", ([
                "密宗" : "密宗是佛教中最神秘的修炼方法！\n",
                "name" : "老僧是哲布尊巴丹。\n",
                "修持"  : (: ask_job :),
                       ]));
          set("shen_type",1);set("score",200);setup();
  }
int init()
{
      add_action("Do_xiuchi","xiuchi");
    }
int Do_xiuchi()
{
    object me;  
    int i,j;
    me=this_player();
    if (!(me->query_temp("job_name"))||me->query_temp("job_name")!="修持")
    return notify_fail("你要干什么？\n");
    i=random(10)+20;
    j= random((100-(int)me->query("int"))/2);
        if ((int)me->query("jing") < j ) {
                me->unconcious();
                return 1;
        }
    me->receive_damage("jing",j);
    if ((int)me->query_temp("xiuchi",1)>i)
    {
    me->add("potential",30+random(10));
    me->add("combat_exp",(int)(me->query_skill("huanxi-chan",1)/3)+80); 
    me->delete_temp("job_name");
    me->delete_temp("xiuchi");
    tell_object(me,"活佛将手在你头上一拍，你簌然一惊，似有所悟。\n");
   }
    switch (random(5))
    {
      case 0:
      message_vision(HIW"\n$N朗声颂道：" +"
      诸佛正法贤圣三宝尊
      从今直至菩提永皈依 
      我以所修施等诸资粮 
      为利有情故愿大觉成\n\n"NOR,me);           
      break;
      case 1:
      message_vision(HIY"\n$N悄声念道：" +" 
      嗡班札阿弥达，滚札利，哈那哈那哄呸。\n\n"NOR,me);
      break;
      case 2:
      message_vision(RED"\n$N悄声念道：" +" 
      嗡梭巴瓦许达，萨尔瓦达马，梭巴瓦许多杭。\n\n"NOR,me); 
      break;
      case 3:
      message_vision(CYN"\n$N悄声念道：" +" 
      诸法自性虚空藏 空中生起莲日轮 
      上现自心蓝哄字 放光普照十方刹 \n\n"NOR,me);
      break;
      case 4:
      message_vision(GRN"\n$N朗声念道：" +" 
      白身三眼金刚喙 剑翅双扬璁角中 
      如意至宝顶庄严 金刚双爪抓四龙 \n\n"NOR,me);
      break;
    }
     me->add_temp("xiuchi",1);
     me->start_busy(1);    
     return 1;    
   }
string ask_job()
{
        object me;
        int exp;
         me = this_player();
        exp = (int)me->query("combat_exp",1);
        if (!me->query("family/family_name")
        && me->query("family/family_name") != "大轮寺") 
         return ("你不是我密宗传人。\n");
       if (exp<=30000)
          return ("你的修为还太差，练练再来吧。\n");
        if ((int)me->query_skill("huanxi-chan",1)<30)
          return ("你对密宗的领悟力太差，还是回去多读读经吧。\n");   
       if (exp>=100000)
          return ("你的佛法修为已经有了基础，不需要老僧再指点了。\n");
       if (me->query_temp("job_name"))
         return ("你已经领了工作了，快去做吧。\n");  
          me->set_temp("job_name","修持");   
          me->set_temp("xiuchi",1);
        return ("好，你就跟着老僧一起修持(xiuchi)金刚乘藏密佛法吧。\n");               
}

