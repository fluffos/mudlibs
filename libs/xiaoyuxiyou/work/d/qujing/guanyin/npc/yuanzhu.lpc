// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit NPC;

void create()
{
	set_name("金池上人", ({"lao yuanzhu", "yuanzhu"}));
        set("gender", "男性");
	set("title", "老院主");
	set("long", "观音院的主持。\n");
	set("attitude", "heroism");
	set("class", "yaomo");
	set("bellicosity", 800);
	set_level(79);
	set("per", 18);
	set("age", 270);
	set("str", 25);
	set("looking", "满面皱纹，一双昏眼，牙齿脱落，腰驼背屈。\n");
	set_skill("unarmed",790);
	set_skill("dodge",790);
	set_skill("blade",790);
	set_skill("parry",790);
	set_skill("force",790);
	set_skill("spells",790);
	set_skill("moshenbu",790);
	set_skill("cuixin-zhang",790);
	map_skill("unarmed", "cuixin-zhang");
        map_skill("parry", "cuixin-zhang");
        map_skill("dodge", "moshenbu");
        set("force_factor", 30);
	set("chat_chance",10);
  	set("chat_msg",({
        	"老院主嘴里嘀咕道：老衲一生最喜爱袈裟...\n",
  	}));
   	set("mana_factor", 20);
	setup();
   	carry_object("/d/qujing/guanyin/obj/jinshan")->wear();
   	carry_object("/d/qujing/guanyin/obj/sengpao")->wear();
   	carry_object("/d/qujing/guanyin/obj/guaizhang")->wield();
}

void unconcious()
{
	object me = this_object();
	message_vision("$N一个趔趄，栽倒在地，死了。\n\n",me);
	message_vision("一阵风吹过，老院主的尸体顿时化作灰烬。\n\n",me);
	destruct(me);
}

void die()
{
  unconcious();
}
