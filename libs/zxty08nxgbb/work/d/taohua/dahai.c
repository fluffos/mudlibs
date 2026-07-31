inherit ROOM;
 
void create()
{
        set("short", "大海");
        set("long",@LONG
你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。
耳边只有海浪的拍打声。
LONG);   
    set("exits", ([
       "out" : __DIR__"dahai",
    ]));
        setup();
}
int do_check()
{
	object *obj;
	int	i;
	obj=all_inventory(this_object());
	if (!sizeof(obj))	return 1;
	for (i=0;i<sizeof(obj);i++)
		if (userp(obj[i]))	return 0;
	return 1;
}
