inherit NPC;
#include <ansi.h>
#include "notice.h"

void create()
{
        set_name(HIW"北大侠客行"NOR, ({"pkuxkx"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", "北侠新闻发言人");
        set("env/invisibility",1);
        set("long", "一个可爱的小童，每天负责在这里迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_qi", 1500000);
        set("qi",1500000);
        set("jing",1500000);
        set("max_jing", 1500000);
        setup();
        remove_call_out("pkumsg");
        call_out("pkumsg",1);
        remove_call_out("speweek");
        call_out("speweek",1);   
        remove_call_out("feizei");
        call_out("feizei",1);               
}

void pkumsg()
{
        if (environment(this_object()))
        {
        CHANNEL_D->do_channel( this_object(), "jh", HBRED+msg[random(sizeof(msg))], -1);
        remove_call_out("pkumsg");
        call_out("pkumsg",300);
        }
}
void speweek()
{
        if (environment(this_object()))
        {
              object speweek;
              speweek=load_object("/adm/daemons/speweek");
              if(speweek) speweek->start();
        remove_call_out("speweek");
        call_out("speweek",7000+random(400));         
              }
}
void feizei()
{
        if (environment(this_object()))
        {
         FEIZEI_D->random_feizei();
         if (random(5)) FEIZEI_D->random_feizei();
         if (random(4)) FEIZEI_D->random_feizei();
         if (random(3)) FEIZEI_D->random_feizei();
         remove_call_out("feizei");           
         call_out("feizei",1400+random(80));          
         }
}

void feizei1()
{       
        object ob, where;
        object ob1;
        if (!environment(this_object())) 
               return;        
        remove_call_out("feizei1");                   
        call_out("feizei1",1400+random(80));          
        if(random(4))
               return;
        ob = new("/d/wizard/npc/feizei");
//过滤非法任务地点和不明区域 by segate@pkuxkx
        while (!objectp(where) || 
               !where->isroom()||
               TASK_D->place_belong(where)=="不明区域"||
               base_name(where) == "/adm/daemons/taskd")
        {
          where = TASK_D->random_place();
        }
//        where = TASK_D->random_place();
        ob->move(where);
        CHANNEL_D->do_channel( this_object(), "jh", HIR"听说"HIY+TASK_D->place_belong(where)+HIR"有飞贼横行，据说身携重宝！", -1);        
        if(random(3)) return;
        ob1=new("/d/reborn/jinyong/npc/sj_huo");
        ob1->move("/d/xingxiu/saimachang");
}
