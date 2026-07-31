

inherit ITEM;

void create()
{
   set_name("铁块", ({ "tie kuai","tie","kuai"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
	 set("long","这是一个铁块，铁匠可以用来打造兵器。\n");
     set("unit", "块");
     set("value", 1000);
	 set("weapon",([
		 "damage":30,
		 "strong":80,
		 ]));
    
   }
   setup();
}
