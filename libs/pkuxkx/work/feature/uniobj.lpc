// taozhuang.c by becool 07/2009

#include <ansi.h>

int reset_attribute(object me, object ob, int attribute)
{
// 龙套装 by becool
if (ob->query("id") == "long ya")
  {
  	ob->set("weapon_prop/magic",attribute);
  	ob->set("weapon_prop/damage",100+attribute);
  	ob->set("attribute",attribute);
  	ob->set("long", "一把泛着微弱光芒的巨剑，看似厚重，握在手中竟是轻巧之极。\n剑柄上用隶书刻着几个字：虫牙第"+attribute+"号，甚是怪异。\n"NOR);
  }

if (ob->query("id") == "long lin")
  {
  	ob->set("armor_prop/magic",attribute);
  	ob->set("armor_prop/armor",500+attribute);
  	ob->set("attribute",attribute);
  	ob->set("long", "一件很轻极具质感的的贴身防具，由无数泛着微光的鳞片织成，显然来历不凡。\n右下角不起眼的地方刻有一行小字：虫皮第"+attribute+"号，不知道是什么意思。\n");
  }

if (ob->query("id") == "long xin")
  {
  	ob->set("armor_prop/magic",attribute);
  	ob->set("armor_prop/armor",100+attribute);
  	ob->set("attribute",attribute);
  	ob->set("long", "一条沉甸甸的项链，坠子呈心形，像是纯金打造而成。\n吊坠的背面有几个蝇头小字：虫心第"+attribute+"号，莫名其妙。\n");
  }
 
//其它套装，待添加。

return 1;
}