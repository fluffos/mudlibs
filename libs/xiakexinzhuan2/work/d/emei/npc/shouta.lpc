// /kungfu/class/emei/shouta.c
// Make by jackie 98.2

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("守塔弟子", ({ "shouta dizi", "dizi"  }));
        set("long","这是个专门守塔的峨嵋派女弟子，她一见你身上带着铁指环，立刻上前阻止你。\n");
        
        set("gender", "女性");
        set("attitude", "aggressive");
        set("class", "bonze");

        set("age", 30);
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("eff_jingli", 1500);
        set("jing", 1500);
        set("jingli", 1500);
        set("eff_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 400000);
        set("score", 100);

        set_skill("dacheng-fofa", 120);
        set_skill("linji-zhuang", 150);
        set_skill("huifeng-jian", 135);
        set_skill("sword", 135);
        set_skill("parry", 135);
        set_skill("dodge", 135);
        set_skill("force", 135);
        set_skill("anying-fuxiang", 135);

        map_skill("force", "linji-zhuang");
        map_skill("sword", "huifeng-jian");
        map_skill("parry", "huifeng-jian");
        map_skill("dodge", "anying-fuxiang");
        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/d/emei/obj/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();

}
void init()
{
        int i;
        object *ob, me;
        me = this_object();
        ob = all_inventory(environment(me));
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
  room = load_object("/d/emei/wanfoding");
  room->set("exits", ([
              "west" : "/d/emei/zhulin",          
	      "enter" : "/d/emei/wanfota",
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