// orange.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(HIY "橙衣少女" NOR, ({ "orange girl","girl" }) );
        set("long", "她身穿轻纱柔丝，白足如霜，青丝飘扬。\n");
        set("age", 16);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", random(500000));  
	set("kee", 3000);
        set("eff_kee", 3000);
        set("max_kee", 3000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "\n",
        }) );
        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(HIY "橙衣" NOR,({"orange cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(HIY "橙镯" NOR,({"orange bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(HIY "橙带" NOR,({"orange belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(HIY "橙帽" NOR,({"orange hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(HIY "橙鞋" NOR,({"orange boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(HIY "橙巾" NOR,({"orange ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
   mixed foo;
   object *inv;
   object dress; 
   int i; 
   //foo = ::hit_ob(me,victim,damage_bonus);
     if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
              //message_vision(YEL "$n身上的"+dress->name()+"被$N脱了下来。\n" NOR,me,victim);
              dress->move(environment());
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "身上的"+dress->name()+"被$N脱了下来。\n" NOR;
           } 
          };

            
           
        return;
}
