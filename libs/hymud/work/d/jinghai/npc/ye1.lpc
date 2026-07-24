// /d/jinghai/npc/ye1.c 

inherit NPC;
void create()
{
      set_name("野狼",({"wolf"}));
      set ("long","一只长着灰栗色皮毛，面露凶光的狼。\n");

      set ("race","野兽");
      set ("age",8);
      set ("cor",30);
      set ("con",30);
      set ("str",50);
      set ("max_sen",450);
      set ("max_qi",500);
      set ("max_jing",450);

      set("chat_chance", 10);
      set ("chat_msg",({
      "黑狼绿油油的眼睛直盯着你。\n",
      "黑狼发出一声令人毛骨耸然的嗥叫。\n",
      (: random_move :),
}));

      set_skill("unarmed",1);
      set_skill("dodge",1);
      set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
      set ("verbs",({"bite"}));
      set ("combat_exp",500000+random(100000));

      set("attitude", "killer");
      set_temp("apply/attack",30);
      set_temp("apply/defense",40);

      setup();
}

