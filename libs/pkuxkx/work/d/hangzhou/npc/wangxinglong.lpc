// wangxionglong.c  by hubo

#include <ansi.h>
inherit NPC;
int ask_me();
inherit F_DEALER;
void create()
{
	set_name("王兴隆", ({ "wang xinglong","wang"}) );
	set("gender", "男性" );
	set("age", 35);
	set("long",
		"他是炮仗店的老板，据说也是红花会成员\n"
                "他一边喝着茶，眼睛不断的往提督府方向观望着\n");
	set("combat_exp", 500000);
     set("start_room","/d/hangzhou/paozhang");
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
	set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 30);
        set("dex", 20);

        set("max_qi", 500);
        set("max_jing", 400);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("combat_exp", 500000);
        set_skill("force", 75);
        set_skill("dodge", 75);
           set_skill("strike", 75);
        set_skill("parry", 75);
        set_skill("sword", 75);
        set_skill("cuff",75);
	
  set("inquiry", ([
                "红花会" : "您是总舵主派来的吗？",
                "文泰来" : "那是我们四当家的，你是总舵主派来救人的吗？",
                "救人" :  (: ask_me :),
        ]) );
      	
	setup();
	carry_object("clone/cloth/male6-cloth")->wear();
}

int ask_me()
{
        object me,room;
        me = this_player();

        if( me->query_temp("hhh_wt1") != 4 ) 
             {
             write(HIM"王兴隆对你冷笑一声说：别怪我太坦白，就凭你还想救人，省省吧。\n"NOR);
             return 1;
             }
        if( me->query_temp("hhh_wt1") == 4)
             {
               write(HIY"王兴隆双眼放光说道：您就是总舵主派来救人的，太好了！ \n"NOR);
        
               write(HIY"要想救人，千万不能从正门杀进去，那里必死无疑。我这有个捷\n"NOR);
               write(HIY"径，可直通提督府后门，从这里可走到后门，您老在后门稍等，\n"NOR);
               write(HIY"我在前门放火引开那些兵，您从后门就可进去救人了。提督府里\n"NOR);
               write(HIY"面有不少咱们的人，要找他们接应好办事，大侠小心了。\n"NOR);
               write(HIY"说完，把身子一侧说：里边请。\n"NOR);
               me->set_temp("hhh_wt1",5);
                     
        return 1;
             }
}
    
