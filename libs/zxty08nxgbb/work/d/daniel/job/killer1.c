#include <ansi.h>
inherit NPC;
#include "npcskill.c";
int do_copy(object me,int flag);
int do_back(object me);
string *first_name = ({ "Ö£","Íõ","ÕÅ","³Â","½ð","¹ÃËÕ","Ç®","Ëï","Àî","ÖÜ","Îâ",
        "Áõ","ÁÖ" });
string *name_words = ({ "Ö¾","ÖÒ","Á¼","Ö¾","ÖÒ","´ó","Ñå","Á¼","ÓÂ","Ôª","»ª","ºê",
        "Ð¢","ÐÛ","Áú","Ã÷","ÎÄ","Îä","±ó","À´","Ê¤","½ø","Ãú","±ò","¶«","Î°" });
  string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she","ng","gh","ss","le","ck","tte"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *name_wordss = ({ "Ó¢","ÃÄ","Õä","»ª","Ó¯","Ð¡","ºì","æÃ","æµ","Ð¡","Ãä","Ãî",
        "¾ê","Èç","Ðõ","æ§","ÄÝ","ÃÃ","¹Ã","¶ð","ÄÈ","æÊ","æ¨","·¼","·Ò","Ïã" });


void create()
{
         string name, id,weapon;
        name = first_name[random(sizeof(first_name))];

            set("gender", "ÄÐÐÔ");
            if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
     id = this_player()->query("id");

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
        int i,j,dengji;
        object ob;
        ob = this_object();

        dengji = me->query("zjb_dj/dj") / 3 + 1;
         if(dengji<0)    dengji=1;
             ob->set("zjb_dj/dj",dengji);
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
                ob->set("max_qi",  me->query("zjb_dj/dj")*40000); 
                ob->set("eff_qi",  ob->query("max_qi")); 
     ob->set("eff_jing",  me->query("max_jing")); 
        ob->set("max_jing",  me->query("max_jing")); 
   ob->set("jing",  me->query("jing")); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("jiali", ob->query_skill("force",1)/6);
        ob->reincarnate(); 
                ob->set("qi",  me->query("zjb_dj/dj")*40000); 
                ob->set("neili",  me->query("zjb_dj/dj")*80000); 
                ob->set("max_neili",  me->query("zjb_dj/dj")*80000); 
        call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"´Ò´ÒÃ¦Ã¦µÄÀë¿ªÁË¡£\n", ({me})); 
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
        killer = "ÄªÃûÆäÃîµØ";
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
        corpse->move(environment());
        set_temp("last_damage_from", "ÄªÃûÆäÃîµØ");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}

