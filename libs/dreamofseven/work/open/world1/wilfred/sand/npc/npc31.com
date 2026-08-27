#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;

int quest();

void create()
{
  set_name("馬商", ({ "horse trader","trader" }) );
  set("gender", "男性" );
  set("long",@LONG
一位販馬的商人。
你可以問問他有賣那種馬(list)，或是向他購買各種品種的馬(buy)。
LONG
);      
  set("age",35);
  set("level",12);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"馬商稍微清理了一下地面。\n",
(: command("say 本店的馬是萬中選一，而且價錢公道！一匹 500 文錢！") :),
(: command("say 所謂良馬難尋，伯樂卻更加的少有，世間人總視璞\玉為頑石，唉！") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  set("sell_list",([
__DIR__"obj/obj25" : 1,
]));
  setup();
  set("mirror_number",8);
  call_out("re_quest",900);
}

void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_no_ask","ask");
  add_action("do_buy","buy");
  add_action("do_list","list");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  command("say 客倌，買匹馬如何？");
  return;
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    command("say 嗯，最近生意稍嫌清淡，但還算過得去。");
  else command("say 唉，最近要去磐龍城一趟，但身上盤纏尚未足夠來回，這可怎麼辦才好。");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if((strsrch(str,"非") !=-1 ||
      strsrch(str,"不是") !=-1 ||
      strsrch(str,"才怪") !=-1 ||
      strsrch(str,"給") !=-1 ||
      strsrch(str,"要") !=-1) && strsrch(str,"良馬") !=-1)
  {
    remove_call_out("best_horse");
    call_out("best_horse",2);
    return;
  }

  if(strsrch(str,"良馬") !=-1 )
    command("say 本店的馬是萬中選一，而且價錢公道！一匹 500 文錢！");

  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 唉呀！給我"+ob->name(1)+"是嗎？真是多謝你啦。");
    if( ob->query_amount() > (random(300)+300) && !this_object()->query_temp("pass_quest"))
    {
      command("say 你真是個好人，前幾天在黃沙道上撿到這個，銀光閃閃，送你吧。");
      new(__DIR__"obj/obj15")->move(this_object());
      command("give " +who->query("id")+ " mirror");
      this_object()->set_temp("pass_quest",1);
      command("say 太好了，有了這筆錢，我可以動身了。");
      call_out("dest_temp",3);
      return 1;
    }
    return 1;
  }
  command("oh");
  command("thank");
  return 1;
}

void dest_temp()
{
  tell_room(environment(this_object()),this_object()->name(1)+"急忙的走了。\n");
  destruct(this_object());
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  call_out("re_quest",900);
  return 1;
}

int best_horse()
{
  string accept = "no";
  object obj;
  int index;
  
  this_player()->add_temp("get_best_horse",1);
  index = this_player()->query_temp("get_best_horse");
  if(this_object()->query_temp("item_give")) index = 99;

  switch(index)
  {
    case 5 : command("say 這些確實是萬中選一的良馬呀，難道客倌您不滿意麼？");
             break;
    case 9 : command("sob");
             command("say 客倌，您多心了吧，這些馬都是上上之選呢。");
             break;
    case 12 : message_vision(WHT"[$N很緊張的搓著手]\n"NOR,this_object());
              command("say 客倌，我們這裡就這些馬了啊，如果您不想買，就別妨礙我們作生意呀。");
              break;
    case 14 : command("say 蠢貨！滾出去吧！我們這裡沒有可以賣給你的馬！！");
              message_vision("[$N被$n一腳踢了出去]\n",this_player(),this_object());
              break;
    case 15 : command("sigh");
              command("say 客倌，您果然是識馬的伯樂呀... 好吧，我把我的愛馬牽出來給您看....");
              message_vision(HIC"[$N轉身進去牽了匹馬出來，只見此馬神駿非凡，的確是匹千里馬]\n"NOR,this_object());
              command("say 10000 文錢，如何？此馬本是無價，但我需要這些錢回磐龍城一趟，算是結個緣，將此馬讓與你。");
              write(HIW"\n[買下牠嗎？ yes / no]\n\n"NOR);
              input_to("get_horse",accept);
              break;
    default : command("say 良馬都在這裡了啊，您就挑個幾匹吧。");
  }
  return 1;
}

int get_horse(string accept)
{
  object only_check;
  if(accept == "no" || accept == "n")
  {
    command("sigh");
    command("say 那麼，算了。");
    message_vision("$N把馬牽進去了...\n",this_object());
    return 1;
  }
  if(accept == "yes" || accept == "y")
  {
    command("say 其實我根本不想收你錢，只是試試你的誠意罷了。");

    only_check = filter_array( children(__DIR__"obj/obj7"), (: clonep :) );
    if(sizeof(only_check) > 0)
      new(__DIR__"obj/obj8")->move(environment(this_object()));
    else
      new(__DIR__"obj/obj7")->move(environment(this_object()));
    command("say 乖馬兒，以後可要好好的聽主人的話。");
    command("pat horse");
    message_vision(HIW"\n\t[說完$N便轉身出馬槽了。]\n\n"NOR,this_object());
    random_move();
    destruct(this_object());
    return 1;
  }
  command("say 你說什麼？我聽不懂，你真沒誠意，算了，我的愛馬不能讓給你。");
  return 1;
}

// ----- 分隔島(以下 code 取自 cominging 的周詳連 :P) (借我用喔 cominging *_^) ------

int do_buy_amount()
{

}

string item_list(object ob)
{
  int b;
  b=ob->query("value");
  return sprintf(" %7d ────────  %-26s",b,ob->short());
}

int do_list(string arg)
{
  object goods,me;
  mapping item;
  string list, *file;
  int i,*supply_cost,debug;

  me=this_player();

  if(wizardp(me) && me->query("env/debug")) debug=1;
    else debug=0;

  if( ! mapp( item = query("sell_list") ) )
  {
    write("這位小販沒有物品列表！\n");
    return 0;
  }

  file =  keys(item);
  supply_cost = values(item);
  list = "\n\n\n┌─────────────────────────────┐\n"
              +"│ 馬 價                          目前可以購買的馬種清單    │\n"
              +"└─────────────────────────────┘\n";
  for( i=0 ; i<sizeof(file) ; i++)
  {
    goods = load_object(file[i]);
    if(goods) list+= item_list(goods);
    if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
      else list+="\n";
    list +="\n";
  }
  list +="\n";
  if( i==0 ) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..馬都賣完了。\n");
  else
  {
    tell_object(me,"\n");
    me->start_more(list);
  }
  return 1;       
}

int do_buy(string arg)
{
  int valus,j,world;
  object goods,ob,me;
  string item,*file;
  mapping items;
        
  items = query("sell_list");
  me = this_player();

  if( arg!="horse" ) return notify_fail("你要買什麼東西？\n");

  file = keys(items);
  goods = load_object(__DIR__"obj/obj25");
  valus=goods->query("value");

  if( !me->can_afford( valus ) ) return notify_fail("你身上的錢不夠。\n");

  me->receive_money(-valus);
  me->add("supply_point",-50);

  world = me->money_type();
  message_vision("$N花了 "+price_string(valus,me->money_type())+
                 " 向$n買了一"+goods->query("unit")+goods->name()+"。\n", me , this_object() );

  ob = new(__DIR__"obj/obj25");
  call_out("buy1",0,me,ob);
  call_out("buy2",4,me,ob);
  me->save();
  return 1;
}

void buy1(object me,object ob)
{
  message_vision("馬商對著$N說﹕$n，好，馬上來！\n",me,ob);
  command("hehe");
  return;
}

void buy2(object me,object ob)
{
  message_vision("馬商對著$N說：客倌，您的$n來了！\n[馬商把$n牽到$N面前。]\n",me,ob);
  ob->move(environment(me));
  me->save();
  return;
}


