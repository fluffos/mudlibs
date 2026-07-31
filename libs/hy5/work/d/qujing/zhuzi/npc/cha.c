// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("zhuzi_chahua_niangzi");
  set_name("茶花娘子", ({"chahua niangzi", "chahua", "niangzi"}));
  set("shop_id", ({"niangzi"}));
  set("gender", "女性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ({
        "/d/obj/food/chahu",
        "/d/qujing/zhuzi/obj/chagan",
       "/d/qujing/zhuzi/obj/guazi",
        "/d/qujing/zhuzi/obj/huasheng",
      }));

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
  remove_call_out ("smiling");
  call_out ("smiling",2+random(10),this_object());
}

void smiling (object who)
{
  if (random(2))
    command("smile");
  else
    command("smile "+who->query("id"));
}
