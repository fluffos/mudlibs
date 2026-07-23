// Jay 3/17/96
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("华辉", ({ "hua hui", "hua", "hui"}));
        set("gender", "男性");
        set("nickname", "一指震江南");
        set("age", 60);
        set("long", "
这人是个老翁，身形瘦弱，形容枯槁，愁眉苦脸，身上穿的是
汉人装束，衣帽都已破烂不堪。但他头发卷曲，却又不大像汉人。\n");
        set("attitude", "friendly");
        set("combat_exp", 700000);
        set("shen", -7000);
        set("str", 30);
        set("int", 22);
        set("con", 24);
        set("dex", 25);
        set("max_qi", 1400);
        set("max_jing", 1200);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set_skill("tanzhi-shentong", 110);
        set_skill("xinyuegong", 120);
        set_skill("finger", 110);
        set_skill("force", 110);
        set_skill("taiji-shengong", 110);
        set_skill("hammer", 110);
        set_skill("parry", 110);
        set_skill("dodge", 110);
        map_skill("force", "taiji-shengong");
        map_skill("hammer", "xinyuegong");
        map_skill("dodge", "xinyuegong");
        map_skill("parry", "xinyuegong");
        map_skill("finger", "tanzhi-shentong");
        prepare_skill("finger", "tanzhi-shentong");         
        setup();
        carry_object(__DIR__"obj/chui")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
}
void init()
{
        int i;
        object *ob, me;
        me = this_object();
        ob = all_inventory(environment(me));
        message_vision(HIY"只见一只白影闪身拦在了你的面前！\n"NOR,me); 
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue; 
                if( !me->is_killing(ob[i]) ) me->kill_ob(ob[i]);
                call_out("checking", 3,  me);
        }     
        remove_call_out("do_back");
        call_out("do_back", 900,  me);  
}

int checking(object me)
{
	object ob;
        if(objectp(ob = present("corpse", environment(me)))){
	   destruct(ob);       
           tell_room(environment(me), me->query("name")+"嘿嘿一笑，将尸体一脚踢开。\n", ({me}));
           call_out("checking", 2, me);
           return 1;
           }
        if (me->is_fighting()){
 	   call_out("checking", 1, me);
           return 1;
	   }
        remove_call_out("do_back");
  	call_out("do_back", 15, me);
	return 1;
}

void do_back(object me)
{                       
  object room;
  room = load_object("/d/hj/tianjin");
  room->set("exits", ([
              "north" : "/d/hj/mg-room1",          
         ]));  
  tell_room(environment(me), me->query("name")+"几个起落，闪身不见了。\n", ({me}));	
  destruct(me); 
  return;
}
void unconcious()
{    
      command("faint");        
      do_back(this_object());       
}
void die()
{
      do_back(this_object());       	
}