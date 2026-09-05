inherit ITEM;

void create()
{
	set_name("test1", ({ "test1"}) );	
}
void remove_effect(object me)
{
	tell_object(me,"test1 remove_effect!\n");
}
void test1()
{
	remove_call_out("remove_effect");
	tell_object(this_player(),"test1 begins call_out!\n");
	call_out("remove_effect",10,this_player());
}
void init()
{
	add_action("test1","test1");	
}
