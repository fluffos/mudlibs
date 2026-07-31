inherit NPC;
void create()
{
     set_name("张山",({"zhang san","zhang"}));
     set("gender","男性");
     set("title","砍竹工");
     set("long","附近山中的村民，以卖竹为生!\n");
     set("age",34);
     set("shen_type",1);
     set("score",100);
     set("combat_exp",50000);
     set("inquiry",([
       "砍竹刀":"这是我祖传的东西，怎能随便给人!\n",
       "翠竹":"哈哈，我在那边作了个圈套，看哪个傻瓜会上当!",
       ]));
      set("chat_chance",10);
      set("chat_msg",({
           "张山撩起破衣擦了擦头上的汗水!\n",
           "张山狐疑的看了你一眼，又朝东面看看!\n",
           "张山看了看手中的砍竹刀，又用手在刃口上摸了一遍!\n",
           "张山举起手中的刀，咔咔地砍起绿竹来!\n",
          }));
       setup();
  carry_object("/d/sandboy/obj/bamboo_blade")->wield();
}