inherit NPC;inherit F_DEALER;

void create()
{
  ("jisaiguo_doctor_jsg");
  set_name("柳妙手", ({"liu miaoshou","liu"}));
  set("shop_id", ({"doctor"}));
  set("shop_title", "妙手回春");
  set("gender", "男性" );
  set("age", 62);
  set("per", 18);
  set("long", "一位老大夫，好象很有学问的样子。\n");
  set("combat_exp", 1000);
  set("max_qi", 300);
  set("max_jing", 300);
  set("attitude", "friendly");
  set("vendor_goods", ({
       "/d/obj/drug/dieda",
        "/d/obj/drug/hunyuandan",
      }));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/obj/cloth/changpao")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) { 
                case 0:
                say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，那里不舒服啊？\n");
                        break;
		case 1:
		say(name()+"抬头看了看你，叹了口气，说道：没救了。。。\n");
		break;
        }
}

