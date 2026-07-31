// long.c ÁúÓê½¿¢
// marry 99.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ÁúÓê½¿", ({ "long yujiao","long","jiao" }));
        set("nickname", MAG "Æ®ÏãÅ®" NOR);
        create_family("³ÕĞÄÍıÏëÃÅ", 3,"µÜ×Ó");
        set("jihao",1);
        set("long","Ëı¾ÍÊÇ³ÕĞÄÍıÏëÃÅµÄĞ¡Ê¦ÃÃ¡°Æ®ÏãÅ®¡±ÁúÓê½¿¡£");
        set("gender", "Å®ĞÔ");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("per", 30);
        set("dex", 30);
set("no_suck",1);
        
        set("max_qi", 50000);
        set("max_jing", 50000);
        set("neili", 50000);
        set("max_neili", 20000);
        set("jiali", 100);
        set("combat_exp", 10000000);
        set("score", 100000);
        set("zjb_dj/dj",5);

        set_skill("force", 240);
        set_skill("dodge", 220);
        set_skill("unarmed",240);
        set_skill("parry", 230);
        set_skill("whip", 250);
        set_skill("literate", 300);
        set_skill("chixin-bianfa", 250);
        set_skill("shuiyue", 290);
        set_skill("wangran-xinfa", 300);
        set_skill("cxwx-quan", 200);
    
        map_skill("force", "wangran-xinfa");
        map_skill("whip", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
        map_skill("parry", "chixin-bianfa");
        map_skill("dodge", "shuiyue");
               
        set("chat_chance_combat", 60);
        setup();
        carry_object("/d/cxwxm/obj/whip.c")->wield();
        carry_object("/d/cxwxm/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        int n;
        n = ob->query("combat_exp");
        if ((int)ob->query("shen") < 0) {
                command("say ±¾ÃÅ×î¼ÉÎŞ³ÜÖ®Í½£¬¿ì¹ö°É£¡");
                command("say ÄãÕâÖÖ°ÜÀà£¬" + RANK_D->query_respect(ob) +
                        "¿ì¹ö°É£¡");
                return;
        }
/*
        if ((!ob->query("lunhui"))&&(n > 500000))
       {        command("say ¶Ô²»Æğ£¡±¾ÃÅ²»ÊÕ½­ºşÈËÎï£¡");
                return;
        }
         if ((ob->query("lunhui"))&&(n > 10000000))
       {        command("say ¶Ô²»Æğ£¡±¾ÃÅ²»ÊÕ½­ºşÈËÎï£¡");
                return;
        }
*/
       if ((string)ob->query("family/family_name",1)) 
       {
                command("say " + RANK_D->query_respect(ob) + "¼ÈÈ»ÒÑÓĞÃûÊ¦Ö¸µã£¬ºÎ±ØÓÖÀ´°İÎÒÄØ£¿");
                return;
        }
        if ((int)ob->query("per") < 30) {
                command("say ±¾ÃÅÎä¹¦·Ç¾øÊÀÈİÃ²²»¿ÉÏ°µÃ£¡");
                command("say Äã»¹ÊÇÈ¥ÃÀÈİºóÔÙÀ´°É!");
                return;
        }
 
        if (ob->query_int() < 25) {
                command("say ±¾ÃÅÎä¹¦È«Æ¾³ÕĞÄÍıÏë¡£");
                command("say ÒªÏëĞŞµ½×î¸ß¾³½ç£¬ÄãµÄÎòĞÔ»¹²»¹»");
                command("say " + RANK_D->query_respect(ob) + "µÄÎòĞÔ»¹´óÓĞÇ±Á¦¿ÉÍÚ£¬»¹ÊÇÇë»Ø°É¡£");
                return;
        }
   if ((string)ob->query("gender")=="Å®ĞÔ")
   {
                message_vision("ÁúÓê½¿×ĞÏ¸µÄÍûÁËÄãÆ¬¿Ì, ËµµÀ£º¡°ºÃ°É, ÎÒ¾ÍÊÕÏÂÄãÁË¡£¡±\n",ob);
       command("recruit " + ob->query("id"));
                 ob->set("yujiao",1);
                       return;}
   else
      {
                message_vision("¶Ô²»Æğ£¡ÎÒÖ»ÊÕÅ®Í½¡£\n",ob);
       return;}
        

}

