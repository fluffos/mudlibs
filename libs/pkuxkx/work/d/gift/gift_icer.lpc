#include <ansi.h>
inherit NPC;

int bonus_who();
void create()
{
                
        set_name(HIC"冰冰"NOR, ({ "icer","bing bing" }));
        set("long", @LONG
        
纵然烈日炎，风霜险，积雪千年，也要等待那春到人间；
明知情思牵，情愁添，情火难遣，也要坚持这一身冷艳。
        
LONG);
        
        
        set("title",HIY"仙子"NOR);
        set("gender", "女性");
        set("age", 21);
        set("attitude", "friendly");
        set("str", 18);
        set("int", 30);
        set("con", 30);
        set("per" ,50);
        set("combat_exp", 7344114);
        set("max_qi",2947);
        set("qi",2947);
        set("max_jing",2165);
        set("jing",2165);
        set("max_jingli",4470);
        set("jingli",5957);
        set("max_neili",5200);
        set("neili",5200);
        set("no_arrest",1);
        set_skill("literate",301);
        set_skill("music",301);
        set_skill("unarmed",301);
        
        set("inquiry",([
           "gift":  (: bonus_who :),
           "元旦":  (: bonus_who :),
         ]));
        setup();
           
}
int bonus_who()
{
   object who,ob;

   who=this_player();
   if(!who) return 0;
   {
      tell_object(who, "冰冰轻轻拍了拍你的头，说道：新年都过去啦，下次早点来吧。\n");
      return 1;
   }
   if(who->query("gift/newyear2007") )
   {
       tell_object(who,"节日礼物只可以领取一次哦!\n");
       return 1;
    }
   if (who->query("mud_age")<36000 || who->query("combat_exp")<10000)
   	{
   		 tell_object(who,"你太小了，还是四处晃晃吧！\n");
       return 1;
   	}
   command("kiss "+who->query("id"));
   command("say 新年快乐!");
   tell_object(who,"冰冰低头开始沉思,忽然,迅疾地念了一段咒语,$@*#*@&*!##@$&^@!\n啪! 一个什么东西掉在了你脚下!\n");
   ob=new(__DIR__"rsbb");
   ob->move(environment(this_object()));
   ob->set("owner",who->query("id"));
   ob->set("title",who->query("name")+"的");
   ob->call_out("disappear",600);
   who->set("gift/newyear2007",1);
   return 1;
}
