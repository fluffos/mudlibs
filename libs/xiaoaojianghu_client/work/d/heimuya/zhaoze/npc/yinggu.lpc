//yinggu.c
inherit NPC;

string ask_tu();
string ask_huang();

void create()
{
        set_name(MAG "瑛姑" NOR, ({"ying gu", "ying" }));
        set("title", HIW "黑沼灵狐" NOR);
        set("shen_type", 5);
        set("gender", "女性");
        set("per",48);
        set("long",
                "她就是人称黑沼灵狐的瑛姑。\n");
        set("age", 42);
        set("attitude", "friendly");
        set("inquiry", ([
                "周伯通" : "不要提那负心汉。\n",
          "老顽童周伯通" : (: command("say 老顽童?"),command("laugh ying gu") :),
                  "海图" : (: ask_tu :),
                "段皇爷" : (: ask_huang :),
                  "一灯" : (: ask_huang :),
        ]));
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("qimen-wuxing", 250);
        set_skill("yiyang-zhi", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 1000);
        set_skill("force", 100);
        set_skill("kumu-shengong", 100);
        map_skill("force", "kumu-shengong");
        map_skill("unarmed", "yiyang-zhi");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
         carry_object("/clone/misc/ma_cloth")->wear();
}

string ask_tu()
{
      object me;
      me = this_player();
      if ((int)me->query_temp("tmark/令2")) {
          me->set_temp("tmark/令2", 0);
          me->set_temp("tmark/令3", 1);
          return "你想要海图，那就帮我杀了段皇爷吧！\n"; 
      }
}

string ask_huang()
{
      object me;
      me = this_player();
      if (!(int)me->query_temp("tmark/令3")) {
          return "他以为变成秃驴我就认不出他了，"+me->name()+"，若想讨好我，提他的头来见我。\n";
      } else {  
          new(__DIR__"obj/hongjuan")->move(me);
          me->set_temp("tmark/令3", 0);
          me->set_temp("tmark/绢", 1);
          message_vision("瑛姑给了$N一条红手绢。\n",me);   
          return "你把这给他吧！";
      }                                               
}

void do_yidang(object ob)
{
    int p1, p2, p3, p4;
    object me=this_object();
    object obj;
    if (environment(ob)!=environment(me)) return;
    if ((int)ob->query_temp("tmark/绢1")) {
    p1=random(5)+1;
    p2=random(5)+1;
    p3=random(5)+1;
    p4=random(5)+1;
    ob->set_temp("passwd",p1*1000+p2*100+p3*10+p4);
    message_vision("$N"+CYN+"对着$n大骂：你这挨"+CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
    "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4)+"刀的，给我滚开。\n"+NOR,me,ob);
    }
     ob->delete_temp("tmark/绢1");
}
void init()
{
    ::init();
    call_out("do_yidang",5,this_player());
}
