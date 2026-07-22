// by snowman@SJ 04/06/1999
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("华辉", ({ "hua hui", "hua", "hui"}));
        set("gender", "男性");
        set("nickname", "一指震江南");
        set("age", 65);
        set("long", "
这人是个老翁，身形瘦弱，形容枯槁，愁眉苦脸，身上穿的是
汉人装束，衣帽都已破烂不堪。但他头发卷曲，却又不大像汉人。\n");
        set("attitude", "aggressive");
        set("combat_exp", 960000);
        set("shen", -9600);
        set("str", 40);
        set("per", 18);
        set("int", 27);
        set("con", 29);
        set("dex", 28);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("eff_jingli", 2500);
        set("jiali", 50);
        set_skill("qianzhu-wandushou", 160);
        set_skill("xinyuegong", 160);
        set_skill("finger", 160);
        set_skill("force", 160);
        set_skill("literate", 160);
        set_skill("poison", 160);
        set_skill("taiji-shengong", 160);
        set_skill("hammer", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        map_skill("force", "taiji-shengong");
        map_skill("hammer", "xinyuegong");
        map_skill("dodge", "xinyuegong");
        map_skill("parry", "xinyuegong");
        map_skill("finger", "qianzhu-wandushou");
        prepare_skill("finger", "qianzhu-wandushou");         
        setup();
        carry_object(BINGQI_D("chui"))->wield();
        carry_object(ARMOR_D("yangao"))->wear();
}

void init()
{        
	kill_ob(this_player()); 
        remove_call_out("unconcious");
        call_out("unconcious", 900);  
}

void unconcious()
{    
      object room, me;
      
      me = this_object();
      command("faint");  
      room = load_object("/d/hj/tianjin");
      room->set("exits", ([
              "north" : "/d/hj/mg-room1",          
      ]));  
      tell_room(environment(me), me->query("name")+"几个起落，闪身不见了。\n", ({me}));	
      destruct(me);        
}

void die()
{
      unconcious();       	
}