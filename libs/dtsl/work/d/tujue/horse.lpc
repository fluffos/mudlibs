
inherit NPC;

void create()
{
     set_name("汗血宝马",({ "hanxue baoma","ma","baoma","horse"}) );
     set("race", "野兽" );
     set("long", "这是一只汗血宝马。\n");
     set("verbs",({"hoof"}));
     set("limbs",({"头","腹部"}));
     set("perform_quest_kun_obj",1);
     setup();

}

void die()
{
   unconcious();
}

int set_status(object ob)
{
  set("owner_ob",ob);
  set("long","这是一只汗血宝马，据说颉利大汗已经派"+ob->name()+"来捉拿它。\n");
  return 1;
}