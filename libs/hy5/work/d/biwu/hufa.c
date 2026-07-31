#include <ansi.h>

inherit NPC;

void create()
{
   set_name(HIR"盟主护法"NOR, ({ "baobiao" }) );
   set("long", "这是盟主身边的一位护法。\n");
   set("attitude", "friendly");
   set("class", "fighter");

	set("max_neili", 10000);
	set("neili", 10000);
	set("max_jing", 9000);
	set("max_qi", 9000);
	set("str", 60);
	set("dex", 60);

	set("combat_exp", 800000);
	set_skill("sword", 170);
	set_skill("parry", 170);
	set_skill("dodge", 170);
       set("str", 33);
        set("con", 36);
        set("int", 30);
        set("dex", 33);
        set("combat_exp", 180000 + random(40000)); 
        set("attitude", "friendly");
	set_skill("taiji-shengong", 150);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 100);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("array",100);
	set_skill("taoism", 150);
	set_skill("blade", 150);
	set_skill("shiren-jianfa", 150);
	set_skill("shiren-quanfa", 150);
	set_skill("wuxing-dun", 150);
	map_skill("unarmed", "shiren-quanfa");
	map_skill("parry", "shiren-jianfa");
	map_skill("blade", "shiren-jianfa");
	map_skill("dodge", "wuxing-dun");
	map_skill("force", "taiji-shengong");


        set_temp("apply/defense", 50);
        set_temp("apply/armor", 500);

        set("eff_qi", 8500); 
        set("qi", 8500); 
        set("max_qi", 8500); 
        set("eff_jing", 8500); 
        set("jing", 8500); 
        set("max_jing", 4500); 
        set("eff_jingli", 4000); 
        set("neili", 5000); 
        set("max_neili", 5000);
   setup();
 	carry_object("/quest/weiguo/japan/obj/japanblade")->wield();
	carry_object("/clone/cloth/male3-cloth")->wear();	 
}

void leave()
{ object owner;
   message("vision", name() + "四周张望了一下,说道：既然无事，属下先行告退。\n", environment(), this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("number",-1);
   destruct(this_object());
}

void show(object who)
{
   string *cname = ({"左护法", "右护法"});
   string *ename = ({"-left", "-right"});



   //this_object()->set_name(cname[current-1], ({ (string)who->query("id")+ename[current-1] }) );   

   message_vision("一阵黑风刮过，从中走出一个人，到$N面前行了个礼，大声说道：在下随时听调！\n", who);

    //set the leader of this bing.
   set("owner_id", (string)who->query("id")); 
   set_leader(who);
}

void relay_whisper(object me, string msg)
{
   if (query("owner_id") != me->query("id"))
   {
     message_vision((string)this_object()->query("name") 
        + "对着$N冷哼了一声。\n", me);
     return;
   }
   
   //note, do not allow the order contain "chat", "tell"...
   //may need disable more later...
   if( strsrch(msg, "chat") != -1 ||
       strsrch(msg, "tell") != -1 ||
       strsrch(msg, "apprentice") != -1 ||
       strsrch(msg, "recruit") != -1 ) 
     return;

   message_vision((string)this_object()->query("name") + "对着$N点了点头。\n", me);
   if (msg)
   {
     
     call_out ("relaying", 1+random(3), msg);
   }
}

void relaying (string msg)
{//execute the order.
   command (msg);
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 60);
		return 1;
	}
	return ::heal_up() + 1;
}


void init()
{
   object me=this_player();
   object owner;
   int i;
   ::init();


//make sure this bing always follow his owner.
   if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
   {
     this_object()->set_leader(me);
   }

   //if owner leaves, let this bing have chance to disappear.
   if( this_object()->query("owner_id") != 0 )
   {
     owner = find_player( (string)this_object()->query("owner_id") );
     if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
     if( !owner )
     {

        call_out ("leave", 1);
     }
   }
   
}
void die()
{
object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("number",-1);
	::die();
}



