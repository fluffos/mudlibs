
inherit ITEM;

string *vision=({
"$N把水车踩得飞快,",
"$N有气没力地踩动水车,",
"水车在$N的踩动下转了起来,",
"$N一脚高,一脚低地踩起水车来,",
"$N脸挣得通红,脚下的水车却转得越来越慢,",
"水车在$N的踩动下转得飞快,",
"$N吱吱扭扭地踩动水车,",
"$N抹了下脸上的汗水,踩起水车,"
});
void create()
{
        set_name("水车", ({"watercart"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "架");
        set("long", "抽水工具,一半浸在水中,一半伸入田中
如果有人踏动(tread watercart)的话,就可以抽水到田中．\n"),
   set("no_get", 1);
   }
   setup();
}
void init()
{
  add_action("do_tread","tread");
}
int do_tread(string arg)
{
  object player,obj;
  string str;
 player=this_player();
 obj=this_object();
if (!arg||arg!="watercart") return 0;
if (living(player)&&environment(player)==environment())
    {
      if (player->query_skill("dodge",1)>30)
     {    tell_object(player,"你已经不能从踩水车中学到什么了!\n");
          return 1;
     }
       str=vision[random(sizeof(vision))];
  message_vision(str+"河水灌入稻田.\n",player);
      player->improve_skill("dodge",random(3));
      player->receive_damage("qi",random(20));
      player->receive_damage("jing",random(3));
   return 1;
  }
return 1;
}
       