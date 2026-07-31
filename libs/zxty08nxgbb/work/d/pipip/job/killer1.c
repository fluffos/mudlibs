#include <ansi.h>
inherit NPC;
#include "npcskill.c";
int do_copy(object me,int flag);
int do_back(object me);
string *first_name = ({ "郑","王","张","陈","金","姑苏","钱","孙","李","周","吴",
        "刘","林" });
string *name_words = ({ "志","忠","良","志","忠","大","彦","良","勇","元","华","宏",
        "孝","雄","龙","明","文","武","斌","来","胜","进","铭","彬","东","伟" });
  string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she","ng","gh","ss","le","ck","tte"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *name_wordss = ({ "英","媚","珍","华","盈","小","红","婷","娴","小","娩","妙",
        "娟","如","絮","妲","妮","妹","姑","娥","娜","媸","妯","芳","芬","香" });


void create()
{
         string name, id,weapon;
        name = first_name[random(sizeof(first_name))];

            set("gender", "男性");
            if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
        id = rnd_id[random(sizeof(rnd_id))];

          set_name(name, ({ id+" jianxi", "jianxi" }) );
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("combat_exp", 2000000 + random(400000)); 
        set("attitude", "friendly");
          
        set("max_qi", 10000); 
        set("qi", 10000); 
        set("max_jing", 3000); 
        set("jing", 3000); 
        set("neili", 700); 
          set("max_neili", 7000);
            set("max_jingli", 16000);
            set("jingli", 16000);
        set("jiali", 200);
   set("no_suck",1);
        weapon = "/clone/weapon/gangzhang";
        setup();
       ;
        carry_object("/clone/cloth/cloth")->wear();
}
int do_copy(object me,int flag)
{
        int i,j;
        object ob;
        ob = this_object();

        i = me->query_skill("dodge",1);
        j = me->query_skill("force",1);
        i = i>j?i:j;
         i=i+i/20;
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/5);
        
        switch (random(7))
        {
         case 0:set_gumu_npc(i,ob);break;
         case 1:set_emei_npc(i,ob);break;
         case 2:set_wudang_npc(i,ob);break;
         case 3:set_shaolin_npc(i,ob);break;
         case 4:set_baituo_npc(i,ob);break;
         case 5:set_huashan_npc(i,ob);break;
         case 6:set_xingxiu_npc(i,ob);break;      
         default:set_xueshan_npc(i,ob);break;
      
        }
                ob->set("max_qi",  me->query("max_qi")*3); 
                ob->set("eff_qi",  ob->query("max_qi")); 
     ob->set("eff_jing",  me->query("max_jing")); 
        ob->set("max_jing",  me->query("max_jing")); 
   ob->set("jing",  me->query("jing")); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("jiali", ob->query_skill("force",1)/6);
        ob->reincarnate(); 
          ob->set("qi",me->query("max_qi")*2);
          ob->set("neili",300);
        call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me})); 
  destruct(me); 
  return 1;
}
void die()
{
        object corpse;
        mixed killer;
        if( !living(this_object()) ) revive(1);
        else delete_temp("faint_by");
        COMBAT_D->announce(this_object(), "dead");
        if( !(killer = query_temp("last_damage_from")) )
        killer = "莫名其妙地";
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
        corpse->move(environment());
        set_temp("last_damage_from", "莫名其妙地");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}

