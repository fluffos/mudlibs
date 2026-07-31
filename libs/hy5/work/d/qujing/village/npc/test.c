//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit ITEM;

void init()
{
    //set("no_get", "ÄãÄÃ²»ÆğÀ´ÕâÑù¶«Î÷¡£ÊÔÊÔÍÚÍÚ(dig)¡£\n");
    // set("no_give","ÕâÃ´Õä¹óµÄÒ©£¬ÄÄÄÜËæ±ã¸øÈË£¿\n");
    //set("no_drop","ÕâÃ´±¦¹óµÄµ¤Ò©£¬ÈÓÁË¶à¿ÉÏ§Ñ½£¡\n");
    //set("no_sell","·²ÈËÄÄÀïÖªµÀ"+this_object()->query("name")+"µÄ¼ÛÖµ£¿»¹ÊÇ×Ô¼ºÁô×Å°É¡£\n");

    add_action("do_dig", "dig");
    add_action("do_eat", "eat");
}

void create()
{
  set_name(RED "ÆßÒ¶ÇíÖ¥²İ" NOR, ({"qiong cao","cao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¿Å");
    set("long", "Ò»¿Å×ÏºìÉ«µÄĞ¡²İ¡£\n");
    set("value", 0);
    set("drug_type", "²¹Æ·");
  }
  
  // the following line is added by snowcat
  set("is_monitored",1);
  setup();
}
int do_dig(string arg)
{
   object baihe, who, me, where;
   who=this_player();
   me=this_object();
   where=environment(me);

   if( me->query("can_eat"))
     return notify_fail("Ê²Ã´£¿\n");

   if( !arg || (arg!="qiong cao" && arg!="cao"))
     return notify_fail("ÄãÒªÍÚÊ²Ã´£¿\n");

   if(who->is_fighting() && who->is_busy())
     return notify_fail("ÄãºÜÃ¦£¬Ã»Ê±¼äÎÕ²İ¡£\n");



     message_vision("$NÇáÇá½«$nÍÚÁËÆğÀ´¡£\n", who, me);
     me->set("can_eat", 1);
     me->move(who);
     remove_call_out("grow_a");
     remove_call_out("grow_b");
                remove_call_out("grow_c");
                remove_call_out("grow_d");
                remove_call_out("grow_e");
                remove_call_out("grow_f");
                remove_call_out("grow_g");
     where->delete("grow_grass");


   return 1;
}

int do_eat(string arg)
{
   object me=this_object();
   object who=this_player();
   int force_add, mana_add, howold;
   
     if (!id(arg))
         return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
   if( !me->query("can_eat"))
     return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");


   howold = (int)who->query("mud_age") + (int)who->query("age_modify");

   who->set("food", (int)who->max_food_capacity());
     who->set("water", (int)who->max_water_capacity());

   if( !me->query("eatable")){
     message_vision("$NÀÇÍÌ»¢ÑÊ°ãµØ½«Ò»¿Å$n³ÔÁËÏÂÈ¥¡£\n", who, me);
     destruct(me);
     return 1;
   }

   force_add=5;
   mana_add=5;
   
   message_vision("$N½«Ò»¿Å$nÇáÇá½À×ÅÑÊÏÂÁË¶Ç£¬Á³ÉÏ·ºÆğÕóºìÔÎ¡£\n", who, me);
   tell_object(who, "Äã¾õµÃÒ»ÕóÈÈÆøÖ±Í¨ÆßÇÏ£¬»ëÉíÉÏÏÂºÃÏóÓĞÊ¹²»ÍêµÄÁ¦Æø¡£\n");

  who->set("eff_jing", (int)who->query("max_jing"));
  who->set("jing", (int)who->query("max_jing"));
  who->set("eff_jing", (int)who->query("max_jing"));
  who->set("jing", (int)who->query("max_jing"));
  who->set("eff_qi", (int)who->query("max_qi"));
  who->set("qi", (int)who->query("max_qi"));
   

     destruct(me);
     return 1;
}



void invocation()
{
   object me=this_object();
   int i=200+random(200);
   call_out("grow_a", i, me);
}

int grow_a(object me)
{
   int i=400+random(400);
   tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
   set_name(RED "Ò»Ò¶Çí²İ" NOR, ({"qiong cao","cao"}));
   call_out("grow_b", i, me);
   return 1;
}

int grow_b(object me)
{
        int i=600+random(600);
        tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
        set_name(RED "¶şÒ¶Çí²İ" NOR, ({"qiong cao","cao"}));
        call_out("grow_c", i, me);
        return 1;
}

int grow_c(object me)
{
        int i=800+random(800);
        tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
        set_name(RED "ÈıÒ¶Çí²İ" NOR, ({"qiong cao","cao"}));
        call_out("grow_d", i, me);  
        return 1;
}

int grow_d(object me)
{
        int i=1000+random(1000);
        tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
        set_name(RED "ËÄÒ¶Çí²İ" NOR, ({"qiong cao","cao"}));
        call_out("grow_e", i, me);  
        return 1;
}

int grow_e(object me)
{
        int i=1200+random(1000);
        tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
        set_name(RED "ÎåÒ¶Çí²İ" NOR, ({"qiong cao","cao"}));
        call_out("grow_f", i, me);  
        return 1;
}

int grow_f(object me)
{
        int i=1500+random(1000);
        tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
        set_name(RED "ÁùÒ¶Çí²İ" NOR, ({"qiong cao","cao"}));
        call_out("grow_g", i, me);  
        return 1;
}

int grow_g(object me)
{
        int i=2000+random(1000);
        tell_room(environment(me), me->name()+"ÂıÂıµØ³¤³öÁËÒ»¸öĞ¡Ò¶¡£\n", ({me, me}));
   tell_room(environment(me), me->name()+"ÖÜÎ§½¥½¥ÁıÆğÒ»¹Éºì¹â¡£\n", ({me, me}));
        set_name(RED "ÆÒ¶ÇíÖ¥²İ" NOR, ({"qiong cao","cao"}));
   set("eatable",1);
        return 1;
}

