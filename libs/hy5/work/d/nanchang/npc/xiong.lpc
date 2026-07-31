
inherit NPC;

void create()
{
   set_name("大狗熊",({ "da gouxiong","gouxiong","bear"}) );
        set("race", "野兽" );
        set("combat_exp",800000);
        set("max_qi",4000);
        set("max_jing",4000);
        set("max_sen",4000);
     set("long", "这是一只到处游荡的大狗熊，正凶狠地看着你。\n");
	 set("verbs",({"bite","claw","hoof"}));
    set("limbs",({"头","尾巴","腹部","腰部"}));
    set("attitude","aggressive");
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/xiongpi");
   ob->move(environment(this_object()));
   message_vision("$N仰头叫了一声，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

