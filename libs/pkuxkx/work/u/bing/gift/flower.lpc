// 鲜花	
//modified by bing

#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIR +"名字"+ NOR, ({ "ＩＤ" }));
	set("long","LONG\n");
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("no_get", 1);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
		set("value",40000);
		set("owner", "OWNER");
		set("no_store",1);
		set("auto_load", 1);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	


int init ()
{
	if (this_player()->query("id")!=query("owner"))
	{
		message_vision(query("name")+"委屈地叫到：「你不是我的主人！」\n",this_player());
		message_vision(query("name")+"从$N的手指上掉了下来，在地上滚了滚，不见了。\n",this_player());
		destruct(this_object());
            return 1;
	}
	add_action ("do_wear", "wear");
	add_action ("do_wear", "dai");
	add_action ("do_remove", "remove");
	add_action ("do_smell", "smell");
	add_action ("do_smell", "wen");
	add_action ("do_water", "water");
	add_action ("do_fix", "fix");
	if ( this_player()->query( "id" ) != "trill" )
		call_out("need_water", 10+random(10), environment(this_object()));
	return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N戴上一朵"+name+"，不禁想起年少时曾经的梦中人。\n"; break; }
    case 1:
      { msg = "$N戴上"+name+"，沉默几许……低首往事如烟。\n"; break; }
    case 2:
      { msg = "$N拿起"+name+"插在发际，婉尔一笑。\n"; break; }
    case 3:
      { msg = "$N将一朵"+name+"别在胸前，禁不住泪如雨下。\n"; break; }
    case 4:
      { msg = "$N将"+name+"别在胸前，那个熟悉的名字脱口而出。\n"; break; }
    case 5:
      { msg = "$N将"+name+"插在胸前，心里不禁一热。\n"; break; }
    case 6:
      { msg = "$N将"+name+"拿起来，忘情地一吻，然后插在胸前。\n"; break; }
    case 7:
      { msg = "$N小心地把"+name+"别在发鬏上。\n"; break; }
    case 8:
      { msg = "$N将长发轻轻一甩，将"+name+"别在上面。\n"; break; }
  }
  //message_vision (msg,me);
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  //message_vision (msg,me);
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N闻了闻"+name+"，想起当年那好熟悉的清香味。\n"; break; }
    case 1:
      { msg = "$N低头嗅了一下"+name+"，扭过头去打了一个香香喷。\n"; break; }
    case 2:
      { msg = "$N捧着"+name+"一嗅，泪水滴在花瓣上。\n"; break; }
    case 3:
      { msg = "$N将一朵"+name+"放在鼻子下，想啊想啊……\n"; break; }
    case 4:
      { msg = "$N捧着"+name+"闻了一下：唉，今夕是何夕。\n"; break; }
    case 5:
      { msg = "$N将"+name+"捧起闻了闻，又惦记起昨天的故人。\n"; break; }
    case 6:
      { msg = "$N不禁将"+name+"轻轻一闻，思绪绵绵如窗外的细雨。\n"; break; }
    case 7:
      { msg = "$N闻了闻"+name+"，痴痴地听着窗外飘过的小雨。\n"; break; }
    case 8:
      { msg = "$N将"+name+"轻轻一嗅，不禁念道：明日天涯何处……\n"; break; }
  }
  message_vision (msg,me);
  return 1;
}

int do_fix (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N将"+name+"小心地用湿润的丝绢包好。\n";
  flower->set("fixed",1);
  message_vision (msg,me);
  return 1;
}

void need_water (object where)
{
  object flower = this_object();
  object who = environment(flower);
  string name = flower->query("name");
  string msg;

  if (!who || !living(who))
    return;

  if (flower->query("fixed"))
    return;
    if (flower->query("water") > 5)
        return;


  switch (flower->query("water"))
  {
    case 0:
      { msg = "风吹过，"+name+"在$N的眼前轻晃了一下。\n"; break; }
    case 1:
      { msg = name+"有点干了，哦，该淋一点水了。\n"; break; }
    case 2:
      { msg = name+"慢慢低下头。\n"; break; }
    case 3:
      { msg = name+"抬起头，无声地看着$N。\n"; break; }
    case 4:
      { msg = name+"艰难地重新伸直腰杆：“水”……\n"; break; }
    case 5:
        { msg = name+"终于干枯了。\n"; break; }
  }
  message_vision (msg,who);
  flower->set("water",flower->query("water")+1);
  call_out ("need_water",random(50)+50,where);
}

int do_water (string arg)
{
  object flower = this_object();
  object who = this_player();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  if (flower->query("water") >= 5)
  {
    message_vision ("$N的泪水一滴滴流在"+name+"上。\n",who);
    return 1;
  }

  switch (random(9))
  {
    case 0:
      { msg = "$N口含清水，喷在"+name+"的花瓣上。\n"; break; }
    case 1:
      { msg = "$N将一点清水洒在"+name+"上。\n"; break; }
    case 2:
      { msg = "$N伸出手抓住细细的小雨，淋在"+name+"上。\n"; break; }
    case 3:
      { msg = "$N小心地捧起一点点露水，滴在"+name+"的花蕾上。\n"; break; }
    case 4:
      { msg = "$N一阵心痛，泪水流在"+name+"的花瓣上。\n";break; }
    case 5:
      { msg = "$N双手捧着"+name+"，伸到窗外的小雨中……\n";break; }
    case 6:
      { msg = "$N仔细地拿起一只小杯子，将水滴在"+name+"上。\n";break; }
    case 7:
      { msg = "$N捧起从野外采来的晨露，洒在"+name+"的花瓣上。\n";break; }
    case 8:
      { msg = "$N用手指蘸着清水，一点点滴在"+name+"的花瓣上。\n";break; }
  }
  message_vision (msg,who);
  message_vision (name+"重新露出了天真的笑容。\n",who);
  flower->set("water",0);
  return 1;
}
