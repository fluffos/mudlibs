inherit F_AUTOLOAD;
inherit F_CLEAN_UP;
inherit F_SAVE;
inherit POTION;
#define KIND "mp"
#define CKIND "精神"
void create()
{
set_name("[1;32m純喫茶[0m",({"green tea","tea"}));
set_weight(100);
set("value",300);
set_amount(1);
set("amount",1);
if(!restore())
{
set("unit","罐");
set("long","一罐由綠藻提煉而成的茶, 可以迅速恢復你的精神狀態.\n");
set("kind",KIND);
set("usage","恢復玩家700點的魔力");
set("cure",700);
}
}


void init()
{
add_action("drink_potion","drink");
}
int drink_potion(string arg)
{
int num
;
object ob,me;
me=this_player();
num = query_amount();            
if(!arg)
return 0;
if(this_player()->query("hp")<0)
return 0;
if(arg=="tea" || arg=="green tea")
{
if(!ob=present(arg,this_player()))        
return notify_fail("你要喝什麼??\n");
if(ob->query_amount()<1)
return notify_fail("你已經喝完了\n");
if( me->query(KIND)>=me->query("max_"+KIND) )
{
write("你"+CKIND+"已經非常飽滿了!\n");
return 1;
}
if(this_player()->query(KIND)+700>this_player()->query("max_"+KIND))
this_player()->set(KIND,this_player()->query("max_"+KIND));
else this_player()->add(KIND,700);
message_vision("\n$N咕嚕咕嚕的喝下了一罐[1;32m純喫茶[m.\n",this_player());
write("你感覺"+CKIND+"變好了一些!!\n");
this_player()->start_busy(1);
num--;
if(num>0)
{ 
set_weight(this_object()->query_weight()-100);
//me->set_encumbrance(me->query_encumbrance()-100);
set_amount(num);
} else destruct(this_object());
return 1;
}
}

