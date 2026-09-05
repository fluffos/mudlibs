inherit ITEM;

void create()
{
	set_name("test2", ({ "test2"}) );	
}
void remove_effect(object me)
{
	tell_object(me,"test2 remove_effect!\n");
}
void test2()
{
	remove_call_out("remove_effect");
	tell_object(this_player(),"test2 begins call_out!\n");
	call_out("remove_effect",10,this_player());
}
void init()
{
	add_action("test2","test2");	
}
