// by snowcat 12/8/1997         

inherit NPC;

void create()
{
  set_name("方丈", ({"fang zhang", "zhang"}));
  set("title", "布金禅寺");
  set("gender", "男性");
  set_level(10);

  set("age", 70);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",2);
  set_skill("unarmed", 10+random(90));
  set_skill("dodge", 10+random(90));
  set_skill("parry", 10+random(90));
  set("inquiry", ([
    "name" : "布金禅寺方丈也。",
    "here" : "布金禅寺也。",
    "布金禅寺" : "布金禅寺乃布金禅寺也。",
    "公主" : "公主？这个……",
  ]));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/obj/cloth/sengxie")->wear();
  set_temp("no_return",1);
}

void check_room ();

void init ()
{
  call_out ("check_room",6);
}

void check_room ()
{
  object me = this_object();
  object where = environment (me);

  if (where->query("short") != "后院")
    return;

  if (where->query("is_open"))
    return;

  remove_call_out ("opening");  
  call_out ("opening",1,me,where);  
}

void opening (object me, object where)
{
  if (environment(me) != where)
    return;
  if (where->query("is_open"))
    return;
  where->set("is_open",1);
  where->set("exits", ([
              "north"   : "/d/qujing/tianzhu/siyuan",
              "south"   : "/d/qujing/tianzhu/zhaifang",
              "northwest"   : "/d/qujing/tianzhu/baodian",
              "southeast"   : "/d/qujing/tianzhu/chanfang",
            ]));
  message_vision ("$N用颤抖的老手拨开一丛青藤。\n",me);
  message_vision ("$N小心地将小木门打开。\n",me);
}
