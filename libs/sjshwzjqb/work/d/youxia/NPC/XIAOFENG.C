// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 //created 23-06-2001 º£ÉÏÆ®(piao)

//yegucheng.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string give_map(object me);
string ask_mieyao(object me);
string ask_cancel();
// string expell_me(object me);
int do_yes(string arg);


void create()
{
       set_name("Â½Ğ¡·ï", ({ "lu xiaofeng", "xiaofeng", "lu" }) );

       set("long", "ËÄÌõÃ¼Ã«µÄÂ½Ğ¡·ï£¬´ËÈËÒ»ÕĞ¡°·ïÎè¾ÅÌì¡±ÃûÑïÌìÏÂ¡£\n");
      set("faith",4000);
       set("gender", "ÄĞĞÔ");
     set("title", HIM "ĞÄÓĞÁéÏ¬Ò»µãÍ¨"NOR);
   set("class", "youxia");
       set("age", 34);
       set("attitude", "friendly");
        create_family("½­ºşÀË×Ó", 1, "ÂÌ");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 2000);
       set("max_gin", 1100);
       set("max_sen", 2000);
       set("force", 8000);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set("daoxing", 2000000);
        set("eff_dx", 250000);
        set("nkgain", 400);
            set("chat_chance", 10);
        set("chat_msg", ({
            "Â½Ğ¡·ïËµµÀ£ºËÀÎ÷ÃÅ´µÑ©£¬ËµºÃ½ñÌì»¹Ç®£¬²»ÖªÓÖÒªË£Ê²Ã´»¨Ñù£¬ÈÃÎÒÕ¾×ÅÕâÏëÏëÔÚ½øÈ¥¡£\n",
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :),
(: random_move :)
  }) );

       set_skill("unarmed", 280);
       set_skill("dodge", 280);
       set_skill("lingxiyizhi", 300);
     map_skill("unarmed", "lingxiyizhi");
        

        set("inquiry", ([
//      "Àë¿ª": (: expell_me :),
//      "leave": (: expell_me :),
        "ÁéÏ¬Ò»Ö¸" : (: give_map :),
        "ÃğÑı": (: ask_mieyao :),
      "cancel": (: ask_cancel :),

]) );

setup();
        carry_object("/d/youxia/obj/cfblade");
        carry_object("/d/youxia/obj/wushicloth")->wear();
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("Ã»ÓÃµÄ¶«Î÷£¡");
}
else
{
     return ("ÄãÓĞÈÎÎñÂğ£¿£¡");
}
}
string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="½­ºşÀË×Ó") {
   tell_room(environment(me),"Â½Ğ¡·ï¾ÙÆğÊÖÒ»Ö¸£¬¶ÙÊ±Ò»µÀ¹âÃ¢Éä³ö¡£\n");
    return "/d/obj/mieyao"->query_yao(me);
    }
    return ("ºÃ°É£¡²»ÖªµÀ!¹ş¹ş!¡£");
}



void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="½­ºşÀË×Ó") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say ÕâÎ»"+ RANK_D->query_respect(ob) + "ÄãÎä¹¦µÍÎ¢£®£®£®£®»¹ÊÇ¼¸ÄêºóÔÙÀ´ÕÒÎÒ°É¡£\n");
   return;
   }
        command("smile");
   command("say ºÜºÃ£¬Ô­À´ÕâÎ»"  + RANK_D->query_respect(ob) +"ÊÇÓÎÏÀ¶ùµÄÍ½µÜ£¬ºÃ°É£¬±¾³ÇÖ÷¾ÍÊÕÄãÎªÍ½£¡\n");
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) + "¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓĞ³É¡£\n");
       command("recruit " + ob->query("id") );
  ob->set("title", HIM"Â½Ğ¡·ïÇ×ÊÚµÜ×Ó"NOR);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "¼ÈÈ»ÒÑ¾­ÅÉÈëËûÃÅ,»¹ÊÇÁíÑ°ËûÈË°É£¡\n");
        return;
}
/*
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="½­ºşÀË×Ó") {
                command("say Äã¼ÈÊÇ²»¿ÏÔÙ×öÓÎÏÀ£¬ÎªÊ¦È´ÓĞ¼¸¾ä»°Ëµ¡£");
                me->set_temp("betray", 1);
     command("say ÎÒÃÇËä²»ÊÇÕıÊ½µÄÃÅÅÉ£¬µ«¹úÓĞ¹ú·¨£¬ÏÀÓĞÏÀ¹æ£¡");
                return ("¼ÈÊÇÒªÀëÈ¥£¬È´ĞèÊÜ±¾³ÇÖ÷µÄ³Í·££¬Äã¿ÉÔ¸Òâ(agree)?");
        }
        return ("±¾ÈË²»Öª¡£");
}
*/
void init()
{
      ::init();
//      re_rank(this_player())
//       add_action("do_agree", "agree");
      add_action("do_fuming","fuming");
      add_action("do_yes", "yes");
}


/*
int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ğµÀ£ºµÜ×ÓÔ¸Òâ¡£\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("betray/fangcun", 1);
                command("say ¼ÈÊÇÎÒÓÎÏÀÖ®ÖĞÈİ²»ÏÂÄã£¬±ã×ÔĞĞÀëÈ¥°É£¡");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("combat_exp", this_player()->query("daoxing")*80/100);
                this_player()->delete_skill("piaoxiang");
                this_player()->delete_skill("wuji-force");
                this_player()->delete_skill("tianjijue");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
             this_player()->set("faith",0);
     this_player()->save();
                command("say ½­ºş·ç²¨£¬ÉÆ¶ñÎŞĞÎ£¬ºÃ×ÔÎªÖ®¡£¡£¡£\n");
                return 1;
                }
        return 0;
}

*/
string give_map(object me)
{
        me=this_player();
        me->set_temp("need_map", 1);
        return "Èç½ñÎÒÂäÄÑÔÚ´Ë£¬"HIW"¡¼ÁéÏ¬Ò»Ö¸¡½"HIC"ÊÇÎÒ±ÏÉúÎä¹¦µÄ¾«»ª,ÄãÏëÒªÂğ(yes)£¿"NOR"\n";
}


int do_yes(string arg)
{
        object me;
        object item;
        me=this_player();
        
        if(me->query_temp("need_map")) 
        {
                message_vision("$N´ğµÀ£ºÏëÒª£¡\n\n", me);

               if(me->query("family/family_name") != "½­ºşÀË×Ó" )
                return notify_fail("Â½Ğ¡·ïËµµÀ£ºÏëÆ­±¾ÃÅÅÉµÄÃØ¼®£¬Ã»ÃÅ£¡\n");

                if( query("no_map") == 0 )
                {
                        message_vision("Â½Ğ¡·ïËµµÀ£ººÃ£¡ÄÇÎÒ¸øÄãÕâ±¾ÃØ¼®°É£¡\n", me);
                        me->set_temp("need_map", 0);
                item=new("/d/youxia/obj/lingxi");
                item->move(me);

//                        carry_object("/d/youxia/obj/lingxi");
//                        command("give book to " + me->query("id"));
                        set("no_map", 1);
                        call_out("regenerate", 480);
                }
                else
                {
                        message_vision("Â½Ğ¡·ïËµµÀ£ºÎÒ±¾À´Ïë¸øÄãÒ»±¾µÄ£¬µ«ÊÇ¸Õ²Å±»ÈËÒª×ßÁË¡£\n", me);
                }

                return 1;
        }
        return 0;
}

int regenerate()
{
        set("no_map", 0);
        return 1;
}


