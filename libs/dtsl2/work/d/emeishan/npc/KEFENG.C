
inherit NPC;

void create()
{
   set_name("可风道人",({ "ke feng","ke","feng" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "他就是[老君观]的道人可风道人,他也是王世充的手下。\n");
       
   set("combat_exp", 400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/daopao")->wear();
   carry_object(__DIR__"obj/fuchen")->wield();
  
}

