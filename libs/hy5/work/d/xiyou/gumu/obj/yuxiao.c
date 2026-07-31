// created 4/5/1997 by snowcat


inherit ITEM;
inherit F_UNIQUE;
void init();

void create()
{
  set_name("翡翠玉箫" , ({ "yu xiao"})); 
  set_weight(1000);
        set("unique", 1);
  set("long","这是一支用蓝田美玉制做的箫，看起来温润光洁。\n令人爱不释手,你可以吹吹(blow)看\n");
  set("unit", "根");
  setup();
}
