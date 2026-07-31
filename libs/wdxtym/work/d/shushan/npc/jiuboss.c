//【蜀山派】mhxy-yushu 2001/2
inherit F_DEALER;
inherit NPC;
void create()
{
  set_name("马老板", ({"ma laoban", "laoban","boss"}));
  set("gender", "男性");
  set("title", "酒店老板");
  set("combat_exp", 10000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
           set_temp("apply/damage", 4);
        set("vendor_goods", ({
"/d/city/obj/peanut",
"/d/city/obj/tofu",
//  "/d/city/obj/xhw",
"/d/city/obj/chahu",
"/clone/food/xiandan",
        }));
  setup();
  carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
        ::init();
 add_action("do_vendor_list", "list");
  add_action("do_vendor_buy", "buy");
/*
        if (base_name(environment())!=query("startroom")) return;
        if (interactive(ob = this_player()) && !is_fighting()) {
                if(nature!="event_dawn"
                && nature!="event_night"
                && nature!="event_midnight"){
                remove_call_out("greeting");
                call_out("greeting", 1, ob);}
                else owner->command("zzz "+owner->query("id"));
        }
*/
}
void heheing (object who)
{
  if (random(2))
    command("hoho");
  else
    command("smile");
}
void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        }
