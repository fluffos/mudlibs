#include <ansi.h>

inherit NPC;

int do_qingtie();

void create()
{
        set_name("伙计", ({ "huo ji", "huo" }));
        set("long", 
                "发礼物的小伙计。\n");
        set("gender", "男性");
        set("age", 16);
        set("no_clean_up",1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 3000);
        set("shen_type", 1);
        set("inquiry", ([
                "礼物"    : (: do_qingtie :),
        ])); 
        setup();

}
int do_qingtie()
{
       object me, tie, ob, *all, ke, ma;
       
       int i;

       me=this_player();

       ob=this_object();
       
       all = users();
      
       if (ob->query("qingtie")) 
       {
        say ("伙计说：“礼物已经发过了。”\n");
        return 1;
       }

       
       message_vision(HIW "$N嘴中念念有词，数十道光芒冲天而起。\n" NOR,this_object()); 

       for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];


              { tie =clone_object("/u/lsg/liwu");
tell_object(ke,HIR"祝新春快乐，事事如意。。\n\n"NOR); 
                tie->move(ke);}
        }
       return 1;
}

