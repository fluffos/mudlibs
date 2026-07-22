inherit NPC;

void create()
{
  set_name("禁军教头", ({"jinjun jiaotou", "jiaotou"}));
  set("title", "傲来国");
  set("gender", "男性");
  set("age", 45);
  set_level(25);
  set_skill("unarmed", 250);
  set_skill("spear", 250);
  set("force_factor", 40);
  set_skill("dodge", 250);
  set_skill("parry", 250);
  setup();
        carry_object(0,"spear",0)->wield();
        carry_object(0,"armor",0)->wear();
        carry_object(0,"kui",0)->wear();
        carry_object(0,"cloth",0)->wear();
        carry_object(0,"pifeng",0)->wear();
        carry_object(0,"shield",0)->wear();
        carry_object(0,"shoes",0)->wear();
        carry_object(0,"hand",0)->wear();
        carry_object(0,"wrists",0)->wear();
        carry_object(0,"waist",0)->wear();
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{	
  string *ans=({"比武","看热闹","捣乱","从军", });
  int ans1;



        if( !arg ) return notify_fail("你说什么？\n");
        if (arg=="0"|| arg=="1"|| arg=="2"|| arg=="3") 
           {sscanf(arg,"%d",ans1); arg=ans[ans1];}
        message_vision("$N答道：" + arg + "。\n", this_player());
        if( arg== "看热闹" ) 
          {
          command("consider");
          command("say 看热闹可以，但不准大声喧哗，扰乱训练。\n");
          this_player()->set_temp("donghai", 1);
          } 
        else 
          {
          command("say 你胡说什么？别来捣乱！\n");
          }
        return 1;
}

void unconcious ()
{
  object me = this_object();
  message_vision ("\n$N喊到：＂好啊，你敢到这行凶！看我们怎么收拾你！＂说罢跌跌撞撞勉强爬回演武场。\n",me);
  message_vision ("\n又一个$N走了过来。\n",me);
  powerup(0,1);
  remove_all_killer();
  all_inventory(environment())->remove_killer(me);}

void die ()
{
  unconcious();  
}