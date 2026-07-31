#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include "killer_skill.h"

void create()
{
        set_name("江湖豪客",({"jianghu ke","ke","haoke"}));
        set("gender", "男性");
        set("long",
              "这人身穿黑色紧装，面上蒙着一块黑布，只露出一双眼睛，精光四射。\n");
        set("age", random(20)+25);      
        set("str", 15+random(5));
        set("int",15+random(5));  
        set("con",15+random(5));     
        set("dex",15+random(5));
        
        set_skill("force", 100); 
        set_skill("dodge", 100);
        set_skill("parry", 100);
        
        set("shen_type", -1);
        set("attitude", "friendly");
        set("max_qi",500);
        set("max_jing",1200);
        set("neili",300);
        set("max_neili",300);
        set("score", 100);

        
        set_skill("force", 100); 
        set_skill("dodge", 100);
        set_skill("parry", 100);

        setup();  
        add_money("silver", random(10)+5);
}

void init()
{
        object me, ob;
        mapping killerskill1;   
        int number,k_qi,k_neili,k_jing;
        string t_force,t_dodge;
        string t_name;
        
        ::init();

        ob = this_player();
        me = this_object(); 
        t_name = ob->query("id");
        
        if(t_name != (string)me->query_temp("target"))
                return;
        
        if((int)me->query_temp("setok")==1)
                return;
        
        number = (int)ob->query("max_pot");
        number = number - 115;
        k_qi = (int)ob->query("max_qi")*2/3;          // 豪客的气
        k_jing = (int)ob->query("max_jing")*2/3;      // 
        k_neili = (int)ob->query("max_neili")*2/3;    // 内力

       /*set haoke's skill*/
        killerskill1 = skill1[random(sizeof(skill1))];
        t_force = k_force[random(sizeof(k_force))];
        t_dodge = k_dodge[random(sizeof(k_dodge))];       

        me->set_skill("force",number);
        me->set_skill("dodge",number);
        me->set_skill("parry",number);
        me->set_skill(t_force,number);
        me->set_skill(t_dodge,number);
        me->set_skill(killerskill1["t_skill"],number);
        me->set_skill(killerskill1["b_skill"],number);
//      me->set_skill(killerskill2["t_skill"],number);
        me->set_skill(killerskill1["b_skill"],number);
//      me->set_skill(killerskill2["b_skill"],number);
              
        

       /* set killer's  skill maps */

       me->map_skill("force",t_force);
       me->map_skill("dodge",t_dodge);
       me->map_skill("parry",killerskill1["t_skill"]);
       me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
  //   me->map_skill(killerskill2["b_skill"],killerskill2["t_skill"]);
     
        
      /* set killer's skill prepares */

        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

      /* copy entire dbase values */

       me->set("max_qi",k_qi);
       me->set("eff_qi",k_qi);
       me->set("qi",k_qi);
       me->set("max_jing",k_jing);
       me->set("eff_jing",k_jing);
       me->set("jing",k_jing);
       me->set("max_neili",k_neili);
       me->set("neili",k_neili);
       me->set("jiali",(int)(number*3/4)-random(40));

       me->set("combat_exp",ob->query("combat_exp")*2/3);
       me->set_temp("seok",1);  
       return;
}
