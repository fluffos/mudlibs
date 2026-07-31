//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"

int send_me();
int work_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("ÑÖÂŞÍõ", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "Éí´©´óºìòşÅÛ£¬Í·´÷ºÚ³ñÈí½í£®
ÃæÈç¹øµ×£¬ĞëÈô¸ÖÕë£¬Õâ¾ÍÊÇÑÖÂŞÍõ£®\n");
       set("title", "Òõ¼äÊ®ÍõÖ®");
        set("class", "youling");
       set("gender", "ÄĞĞÔ");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
      

set("inquiry", ([
"name": "ºß£¡Á¬ÀÏ·ò¶¼²»ÈÏµÃ£¬ÏëÀ´ÊÇ»îµÄÌ«¾ÃÁË£¡\n",
"here": "Õâ±ãÊÇÑÖÂŞµØ¸®£¬µ½Ñô¼äÒ»Ì¸£¬ºÙºÙ£¬Ã»ÈË²»ÅÂ£¡\n",
"Ñô¼ä": "ÈËËµÒõÑôÊâÍ¾£¬ÆäÊµ²»È»£¬ÒõÑô¼äÓĞÎåµãÏà½»£¬À´È¥ÏàÍ¨£¡\n",
"Îåµã": "¹ş¹ş£¬ÒªËµÖªµÀµÄÈËÈ´Ò²²»¶à£¬ÄÇ±ãÊÇÄê£¬ÔÂ£¬ÈÕ£¬Ê±ºÍ³¤°²ãşË®ÇÅ£¡\n",
"Áõ¸¸": (: obstacle_sc :),
"Áõ²®ÇÕµÄ¸¸Ç×": (: obstacle_sc :),

]) );


create_family("ÑÖÂŞµØ¸®", 2, "ÄãºÃ");
setup();
initlvl((500+random(500)),3);
        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
string obstacle_sc()
{
        object me = this_player();
        int i;
        if( me->query("obstacle/sc") == "done" )
        return("ÎÒ²»Ì«Çå³ş¡£\n");
  if (me->query("combat_exp",1) < 1000000)
    return("ÎÒ²»Ì«Çå³ş¡£\n");            
        if( ! me->query_temp("can_ask") )
          return("ÎÒ²»Ì«Çå³ş¡£\n");

  i = random(800)+100;
  me->add("obstacle/number",1);
  me->set("obstacle/sc","done");
    me->add("combat_exp",i+7000);
    me->add("potential",i*8);
    me->add("mpgx",10);me->add("expmax",2);
  command("chat "+me->query("name")+"Ë«²æÆÂÃğ»¢£¬³¬¶ÈÁõ¸¸Áé»êÏÔ¹¦ÀÍ£¡");
message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+me->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚ¶ş¹Ø£¡\n"NOR,users());
  me->save();
me->move("/d/qujing/shuangcha/sleeproom");

  return("ÄãÓ®µÃÁË"+chinese_number(i+7000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+"Ê®µãÃÅÅÉ¹±Ï× ¶şµã³É³¤ÉÏÏŞ£¡£¡\n");

}

