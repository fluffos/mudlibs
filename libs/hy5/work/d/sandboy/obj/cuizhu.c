#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIG+"翠竹"+NOR, ({ "cuizhu" }));
  set_weight(8000);
  set("long","一根颜色"+HIG+"碧绿"+NOR+"的翠竹.\n");
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("material", "bamboo");
    set("no_get",1);
       set("no_drop",1);
  }
  setup();
}

void init ()
{
  	int i;
	object ob,*inv;
       string str;
       ob=load_object("/d/sandboy/zhushao");
	inv=all_inventory(ob);
	if(!sizeof(inv))	return;
str="一根颜色"+HIG+"碧绿"+NOR+"的翠竹.上面悬挂着\n";
str+=
"----------------------------------------------------------------------------------------\n";
	for(i=0;i<sizeof(inv);i++)	{
         str+=RANK_D->query_rank(inv[i])+inv[i]->short()+"\n";
                 }
   set("long",str);
}
