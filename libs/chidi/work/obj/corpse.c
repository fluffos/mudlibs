// corpse.c

inherit ITEM;

int decayed;

void create()
{
        set_name("无名尸体", ({ "corpse" ,"shiti" }) );
        set("long", "这是一具无名尸体。\n");
        set("unit", "具" );
	decayed = 0;
//	decayed = 1;
        if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	string msg;
        decayed = phase;
        switch(phase) {
                case 1:
			msg=query("name") +
"开始腐烂了，发出一股难闻的恶臭。\n";
			message("say",msg,environment(this_object()),this_object());
                        switch(query("gender")) {
                                case "男性":
                                        set_name("腐烂的男尸", ({ "corpse", 
"尸体" }) );
                                case "女性":
                                        set_name("腐烂的女尸", ({ "corpse", 
"尸体" }) );
                                default:
                                        set_name("腐烂的尸体", ({ "corpse", 
"尸体" }) );
                        }
                        set("long",     
"这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 2:
			msg=query("name") + "被风吹乾了，变成一具骸骨。\n";
			message("say",msg,environment(this_object()),this_object());
                        set_name("一具枯乾的骸骨", ({ "skeleton", "骸骨" }) 
);
                        set("long", "这副骸骨已经躺在这里很久了。\n");
                        call_out("decay", 60, phase + 1);
                        break;
                case 3:
			msg="一阵风吹过，把" + query("name") +
"化成骨灰吹散了。\n";
			message("say",msg,environment(this_object()),this_object());
                        if( environment() ) {
                                object *inv;
                                int i;
                                
                                inv = all_inventory(this_object());
                                for(i=0; i<sizeof(inv); i++) 
        {
        if(inv[i]->query("no_get")) continue;
        if(inv[i]->query("no_drop")) continue;
        if(inv[i]->query("no_sell")) continue;
	inv[i]->move(environment());
        }
                        }
                        destruct(this_object());
                        break;
        }
}

object animate(object who, int time)
{
        object zombie;

        if( !environment() ) return 0;

        seteuid(getuid());
        zombie = new("/obj/npc/zombie");
        zombie->set_name( (string)query("victim_name") + "的僵尸", ({ 
"zombie" }) );
        zombie->move(environment());
        zombie->animate(who, time);

        destruct(this_object());
        return zombie;
}
 
