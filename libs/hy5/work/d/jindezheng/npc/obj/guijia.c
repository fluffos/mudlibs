inherit ITEM;
void create()
{
     set_name("黑色龟甲",({"guijia","jia"}));
     set_weight(3000);
     if (clonep())
       set_default_object(__FILE__);
     else {
                 set("unit","块");
                 set("long","乌黑色的龟甲，上面有些交错的图文.\n");
                 set("material","bone");
                 set("value",10000);
                 set("skill",([
                                   "name":"literate",
                                   "exp_required":100,
                                   "jing_cost":10,
                                   "max_skill":40,
                        ]));
              }
}