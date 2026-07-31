// created by angell 1/1/2001

inherit NPC;
#include "/d/migong/romnpc2.c"
int say_zhu();
int test_jing(object ob);
void announce_start();
void announce_finish(object ob);

void create()
{
  set_name("灵吉菩萨", ({"lingji pusa", "pusa"}));
  set("long", "一位慈眉善目的老人，闻说法力高强，
在此设院讲经传道，渡化世人。\n");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "friendly");
  set("combat_exp", 2000000);
  set("per", 100);
  set_skill("dodge", 200);
  set_skill("force", 200);
  set_skill("spells",190);
  set_skill("unarmed",200);
  set_skill("buddhism", 190);
 
   set("inquiry",([
		  "珠": (: say_zhu :),
		  "定风珠": (: say_zhu :),
                "zhu":(: say_zhu :),
                "name":"老衲灵吉。",
		  "here": "这里是老衲讲经的地方，小须弥山！",
		  "rumors":"说来惭愧，老衲的定风珠竟被妖怪盗了去！",
                "伏魔":(:test_jing:),
                "book":(:test_jing:),
		  ]));

  setup();
initlvl((300+random(300)),8);
  carry_object("/d/qujing/huangfeng/obj/jiasha")->wear();
}

int say_zhu()
{
  object  me=this_player();
  
  if (me->query("obstacle/huangfeng") == "done")
	message_vision("向$N躬身一谢，言道：“施主放心，老衲已将定风珠收妥了，不会再丢。”\n",me);
    else
	{
	command("sigh");
	command("say 三天前，被那怪一阵阴风摄了去，听说藏于他那后园之中了。\n");
	}
return 1;
}

void announce_start()
{
    command("chat 各位施主请了！");
    command("chat 降魔宝籍今年出世，请各位有缘人前来一试。");
}

void announce_finish(object ob)
{
  ob->delete("fumo2_gived");
  remove_call_out("announce_finish");
  command("chat 降魔宝录将于下一个轮回出世，但望到时各位施主前来一试！");
}

int test_jing(object ob)
{     
   object who=this_player();
   object book;
   object where=environment();
      
      if(ob->query("fumo2_gived")) {
          command("sigh "+who->query("id"));
      message_vision("$N叹息道：“施主来晚了，伏魔宝录已经赠与有缘人了，只能等下一次！\n",ob);
             return 1;
          }
   if(!where->query("book_give_can")) {
      message_vision("$N笑道，时候未到，这位施主且等贫僧当众宣布,再来不迟！\n",ob);
             return 1;
      }
   if(who->query_skill("force", 1) < 100 ) {
    message_vision("$N微合双眼，叹了口气：这位施主对伏魔心法的领悟还不够火候，恐怕降不了妖魔。\n", ob,who);
           return 1;
      }
   if (who->query("fumo2") ) {
     message_vision("$N合掌道：施主已经获得过此书了。缘份一说实非虚妄，可遇而不可求也。施主请回吧！\n", ob);
           return 1;
      }
 
       who->set("fumo2", 1);
     ob->set("fumo2_gived",1);
     where->delete("book_give_can");
       message_vision("$N从怀中取出本伏魔心经递给$n，微笑道，但望施主不负所托，降魔卫道！\n", ob,who);
     command("chat "+who->query("name")+"施主福缘深厚，获得伏魔山心经一本！");
     remove_call_out("announce_finish");
     call_out("announce_finish",600,ob);
     return 1;
}

void call_out_announce_success(object who)
{
	call_out("say_hi",1,who);
	call_out("announce_success",2,who);
}

void say_hi(object who)
{
  message_vision ("\n半空中，灵吉菩萨向$N微笑致谢。\n",who);
}

void die()
{
      int i;
      object *inv;
        object me=this_object(); // mudring Oct/11/2002

    if( environment() ) {
             message("sound", "\n灵吉菩萨摇头叹道：大法未彰，归去归去,阿弥陀佛！\n\n", environment());
             command("sigh");
             message("sound", "\n灵吉菩萨跃上八爪金龙，架祥云而往西方去了。。。\n\n", environment());
    inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
              {
	     if (inv[i]->query("no_drop")) continue;
                 inv[i]->move(environment(me));
	   }
          }
      destruct(me);
 }

void unconcious()
{
	die();
}

void announce_success (object who)
{
  int i;
  object zhu;
  if (who->query("combat_exp") < 100000)
   {
     message_vision("半空中，灵吉菩萨对着$N叹了口气，道行不够，亦是枉然！\n",who);
     return;
   }
  if (who->query("obstacle/huangfeng") == "done")
       return;
  if (who->query_temp("obstacle/huangfeng_zhu_getted")==0)
    return;
  if( !(zhu = present("dingfeng zhu", who)) ) 
       return;
  if (who->query_temp("obstacle/huangfeng_huangfengguai_killed")==0)
    return;
  i = random(500);
  message_vision("半空中，灵吉菩萨把手一招，定风珠从$N身上破空而去，稳稳的定在菩萨的手中。\n",who);
   destruct(zhu);
  who->delete_temp("obstacle/huangfeng_zhu_getted");
  who->add("obstacle/number",1);
  who->set("obstacle/huangfeng","done");
  who->add("combat_exp",i+11000);
    who->add("potential",i*8);
  who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"黄风岭降服黄风怪，为佛祖寻回定风珠！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+11000)+"点经验"+
               chinese_number(i*8)+"点潜能"+
               "十点门派贡献 二点成长上限！\n");
  who->save();
}

