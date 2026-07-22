// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("黄眉老佛", ({ "huangmei laofo", "huangmei", "laofo", "fo" }));
  set("title", "小雷音寺");   
  set("long", "一位面无表情却又精神焕发的老佛。\n");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "heroism");
  set("per", 30);
  set_level(80);
  set("force_factor",800);
  set("mana_factor",800);

  set_skill("spells",800);
  set_skill("buddhism",800);
  set_skill("unarmed",800);
  set_skill("jienan-zhi",800);
  set_skill("dodge",800);
  set_skill("lotusmove",800);
  set_skill("parry",800);
  set_skill("force",800);
  set_skill("staff",800);
  set_skill("mace",800);
  set_skill("lotusforce",800);
  set_skill("lunhui-zhang",800);
  set_skill("jinglei-mace",800);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "jinglei-mace");
  map_skill("mace", "jinglei-mace");
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/mace")->wield();
}


void die ()
{
  object me = this_object();
  message_vision ("\n旋风出现，弥勒佛祖走了进来。\n",me);
  message_vision ("\n$N连忙慌着跪了下来，却还身作一黄眉小童。\n",me);
  message_vision ("弥勒佛祖领着黄眉小童走了出去。\n",me);
  destruct (me);
}

void unconcious ()
{
  die ();
}
