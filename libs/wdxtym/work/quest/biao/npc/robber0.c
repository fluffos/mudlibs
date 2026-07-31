// robber for dart
//gemini改于2000.4.4 使得复制时不参考literate等级

#include <ansi.h>
inherit NPC;
#include "robber.h"
void create()
{ 
        set_name(HIW"劫匪"NOR,({"robber"}));
        set("long","这是一位华山派弃徒。\n");
        set("title","拦路抢劫");
        set("gender", "男性" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);

        set("max_qi", 2500);
        set("eff_qi", 2500);
        set("qi", 2500);
        set("str",25);
        set("dex",30);
        set("con",30);
        set("max_jing", 1000);
        set("jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
	set("shen",-10000);
        set("shen_type", -10);
        set("combat_exp", 500000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
     
        setup();
        carry_object(__DIR__"changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player(); 
/*      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
		  if(sname[i]=="force")i++;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }*/

if (!ob->query_skill("force"))
{
temp=10;
}else
temp=(int)ob->query_skill("force",1);

        me->set_skill("huashan-jianfa", temp);
        me->set_skill("strike",temp);
        me->set_skill("hunyuan-zhang",temp);
        me->set_skill("cuff",temp);
        me->set_skill("dodge", temp);
        me->set_skill("sword", temp);
        me->set_skill("parry", temp);
        me->set_skill("zixia-shengong", temp);
        me->set_skill("poyu-quan", temp);
        me->set_skill("huashan-shenfa",temp);
        me->map_skill("sword","huashan-jianfa");
        me->map_skill("dodge","huashan-shenfa");
        me->map_skill("parry","huashan-jinfa");
        me->map_skill("strike","hunyuan-zhang");
        me->map_skill("force", "zixia-shengong");
        prepare_skill("strike", "hunyuan-zhang");

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jm" :),
                (: perform_action, "sword.jianzhang" :),
                (: perform_action, "sword.jie" :),
                (: perform_action, "sword.xian" :),                
                (: perform_action, "dodge.huiyanfeiwu" :),                
                (: exert_function, "powerup" :),
        }) );
/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(2));
        me->set("combat_exp",hp_status["combat_exp"]);
if ((int)ob->query_skill("jiuyin-zhengong",1)>480)
{
me->set("qi",(ob->query("max_qi"))/2);
me->set("eff_qi",(ob->query("max_qi"))/2);
me->set("max_qi",(ob->query("max_qi"))/2);
me->set("max_jing",(ob->query("max_qi"))/2);
me->set("eff_jing",(ob->query("max_qi"))/2);        
me->set("jing",(ob->query("max_qi"))/2);
}
}

