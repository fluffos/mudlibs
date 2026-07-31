inherit NPC;

void create()
{
   set_name("胡小仙",({ "hu xiaoxian","hu"}) );
        set("gender", "女性" );
        set("age",21);
   set("long", "她就是胡佛的女儿胡小仙。她头梳盘龙髻，\n"+
               "面饰朱色花铀，身穿粉绿色紧袖糯衫，紫红\n"+
               "色的披巾，乳白色窄长裙，脚穿尖头履，尽\n"+
               "显其优美的身形体态。\n");       
   set("combat_exp",80000);
   set("str",22);
   set("per",25);
   set_skill("parry",60);
   set_skill("unarmed",60);
   set_skill("dodge",60);
   set_skill("cuff",60);

   set("inquiry",([
    "胡佛":"他是我爹爹啊，他在长安呢，我也很久没见他了。\n",
    "寇仲":"这个坏小子，可惜近来一直没看到他。\n",
    "徐子陵":"子陵英俊潇洒，可惜现在几乎没有人能找到他了。\n",
    "赌博":"我的赌术是我爹爹亲传的，你赌不过我的！\n",
    ]));
   
   setup();
   carry_object(__DIR__"obj/pijin")->wear();
   carry_object(__DIR__"obj/changqun")->wear();
   carry_object(__DIR__"obj/male-shoe")->wear();
   carry_object(__DIR__"obj/rushan")->wear();
  
}
void init()
{
  object ob;
  ob=previous_object();
  if(userp(ob)&&!ob->is_fighting()&&living(ob))
   call_out("welcome",0,ob);
}

void welcome(object ob)
{
  if(!ob||!living(ob)||ob->is_fighting())
  return;
  switch(random(5)){
  case 0:command("smile");break;
  case 1:command("nod");break;
  case 2:command("hi");break;
  case 3:command("xixi");break;
  case 4:command("poor");break;}
  return;
}
  