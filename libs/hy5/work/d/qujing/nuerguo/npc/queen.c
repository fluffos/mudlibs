// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "Î÷ÁºÅûËªÏÉºó"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "³¿êØÅ®Éñ");
  set("gender", "Å®ĞÔ");
  set("age", 23);
  set("long", "Î÷ÁºÅûËªÏÉºó³¿êØÅ®Éñ¡£\n");
  set("combat_exp", 1000000);
  set("combat_exp", 1000000);

  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("neili", 900);
  set("max_neili", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{//disabled announce and reward...
  int i;

  i = random(800);
if (who->query("obstacle/nuerguo") == "done")
return;
  who->add("obstacle/number",1);
  who->set("obstacle/nuerguo","done");
  who->add("combat_exp",i+28000);
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+reason+"£¬Ë³Àû´³¹ıÎ÷ĞĞÒ»¹Ø£¡");
  command("chat Î÷ÁºÉÏÏÂ±¼×ßÏà¸æ£¡");
tell_object(who,"ÄãÓ®µÃÁË"+chinese_number(i+28000)+"µã¾­Ñé"+
               chinese_number(i*8)+"µãÇ±ÄÜ"+"Ê®µãÃÅÅÉ¹±Ï× ¶şµã³É³¤ÉÏÏŞ£¡£¡\n");
  who->save();
  message_vision (HIY NAME+"ÔÚÒ»Õó°×ÎíÖĞĞìĞìÏûÊ§¡£\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"Í»È»´Ó°×ÎíÖĞÉÁ³öÏò$NÒ¡Ò¡Í·£º"+
                  "ÄúÒÑ´³¹ıÎ÷ÁºÕâÒ»¹ØÁË¡£¿ìÈ¥Î÷ÌìÈ¡¾­°É¡£\n" NOR,who);
  message_vision (HIY "Ëµ°Õ"+NAME+"ÔÚÒ»Õó°×ÎíÖĞĞìĞìÏûÊ§¡£\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"´ÓÒ»ÍÅ°×ÎíÖĞÏÔ³ö£¬¸æËß$N£º"+
                  "ÄúÉĞÎ´´³¹ıÎ÷ÁºÕâÒ»¹Ø£¬¶Ô²»Æğ¡£\n" NOR,who);
  message_vision (HIY "Ëµ°Õ°×ÎíÓµ×Å"+NAME+"ÔÚ¿ÕÖĞÂıÂıµØÏûÊ§¡£\n" NOR,who);
}
ÿ
