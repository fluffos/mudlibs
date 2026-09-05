// corpse.c

inherit ITEM;

int decayed;

void create()
{
	set_name("无名尸体", ({ "corpse" }) );
	set("long", "这是一具无名尸体。\n");
	set("unit", "具" );
	decayed = 0;
	if( clonep(this_object()) ) 
	{
	  call_out("init_task",1);
	  call_out("decay", 15, 1);
	}
}

int is_skeleton() { return decayed >= 2; }
int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }
int re_make()
{
	set("re_maked",1);
	remove_call_out("decay");
	call_out("decay",180,1);
	return 1;
}
void decay(int phase)
{
	decayed = phase;
	switch(phase) {
		case 1:
			message_vision("$N开始腐烂了，发出一股难闻的恶臭。\n",this_object());
			switch(query("gender")) {
				case "男性":
					set_name("腐烂的男尸", ({ "corpse", "尸体" }) );
				case "女性":
					set_name("腐烂的女尸", ({ "corpse", "尸体" }) );
				default:
					set_name("腐烂的尸体", ({ "corpse", "尸体" }) );
			}
			set("long",	"这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n");
			call_out("decay", 5, phase + 1);
			break;
		case 2:
			message_vision("$N被风吹乾了，变成一具骸骨。\n",this_object());
                          set_name("枯乾的骸骨", ({ "skeleton", "骸骨" }) );
			set("long", "这副骸骨已经躺在这里很久了。\n");
			call_out("decay", 5, phase + 1);
			break;
		case 3:
			message_vision("一阵风吹过，把$N化成骨灰吹散了。\n",this_object());
			if( environment() ) {
				object *inv;
				int i;
				
				inv = all_inventory(this_object());
//                                for(i=0; i<sizeof(inv); i++) inv[i]->move(environment());
                                for(i=0; i<sizeof(inv); i++) {
                                    if (inv[i]->query("no_get")) 
                                         destruct(inv[i]);
                                    else if (!inv[i]->query("value") && !inv[i]->value() && !inv[i]->query("task_owner"))
                                         destruct(inv[i]);
                                    else 
                                         inv[i]->move(environment());
                                }
			}
			destruct(this_object());
			break;
	}
}

void init_task()
{
  object *inv=all_inventory(this_object());
  
  for(int lp=0;lp<sizeof(inv);lp++)
    if ( inv[lp]->is_task() )
      inv[lp]->ext_calldest();
}