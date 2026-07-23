// huiyue.c 辉月使
// Modify By River@sj 99.06
// Modified by caiji@SJ 5/17/2001
#include <ansi.h>
inherit NPC;
int p();
void create()
{
        object ob;
        set_name("辉月使", ({ "huiyue shi", "huiyue", "shi"}) );
        set("title", "明教波斯三使");
        set("gender", "女性");
        set("attitude", "friendly");
        set("age",38);
        set("long","她一头黑发，和华人无异，但眸子极淡，几乎无色，瓜子脸型。\n");
        set("rank_info/respect","使者");
        set("str", 23);
        set("int", 24);
        set("con", 23);
        set("dex", 26);
        set("per", 24);
        set("unique", 1);
        set("shen_type",0);
        set("combat_exp", 680000);
        set_skill("dagger",110);//change blade to dagger by caiji
        set_skill("parry",110);
        set_skill("force",110);
        set_skill("cuff",110);
        set_skill("literate",70);
        set_skill("dodge",100);
        set_skill("piaoyi-shenfa",110);
        set_skill("shenghuo-shengong",110);
        set_skill("shenghuo-lingfa",110);
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","piaoyi-shenfa");
        map_skill("dagger","shenghuo-lingfa");//change blade to dagger by caiji
        map_skill("cuff","shenghuo-lingfa");
        map_skill("parry","shenghuo-lingfa");
        prepare_skill("cuff","shenghuo-lingfa");
        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({ (: p :) }));
        set("max_qi",2200);
        set("max_jing",1700);
        set("neili",2800);
        set("max_neili",2800);
        set("jiali",50);
        set("eff_jingli",1500);     
        setup();

        if (clonep()) {
                ob = unew(BINGQI_D("shenghuo-ling"));
                if (!ob) ob = unew(BINGQI_D("tieling"));
                ob->move(this_object());
                ob->wield();        
                carry_object(ARMOR_D("changpao"))->wear();
        }                   
}

void kill_ob(object me)
{     
       object ob;
       if(!this_object()->is_killing(me->query("id"))){  
          command("sneer");     
          if(objectp(ob = present("liuyun shi", environment(this_object())))
           && !ob->is_killing(me->query("id"))){
             message_vision(HIY"长笑声中$n身形晃动，越过辉月使站到$N左边，将$N夹在中间！\n", me, ob);
             ob->kill_ob(me); 
          }
          if(objectp(ob = present("miaofeng shi", environment(this_object())))
           && !ob->is_killing(me->query("id"))){
             message_vision(HIY"长笑声中$n身形晃动，越过辉月使站到$N左边，将$N夹在中间！\n", me, ob);
             if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);  
          }
       }
       ::kill_ob(me);   
}

int p()
{          
       object ob;
       if(random(3) == 2 && objectp(ob = present("liuyun shi", environment(this_object())))){
          command("yun chuangong liuyun shi");
          return 1;
       }
       else{
          command("yun tougu");
          return 1;
       }
}
