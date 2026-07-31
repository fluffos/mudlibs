// Creator : Numa@Sj 2000-5-4 12:29

void clean_item(object ob)
{
	object *obj;
	int i;
	
	obj = deep_inventory(ob);
	if (sizeof(obj)>=1) {
		for(i=0;i<sizeof(obj);i++) {
			if (objectp(obj[i]))
				call_out("dest",1,obj[i]);
		}
	}
}

void dest(object ob)
{
	destruct(ob);
}

void init()
{
	object ob = this_object();
	object local;
//	object *obj;
//    int i;
	
	local = load_object(__DIR__"ctrl");
/*	
	obj = inventory(ob);
	if (sizeof(obj)>=1) {
		for(i=0;i<sizeof(obj);i++) {
			if (userp(obj[i]) && !wizardp(obj[i]))
				call_out("start_trace",1,obj[i]);
		}
	}
*/
	if (local->query("bw/set_item") == "no")
		call_out("clean_item",1,ob);
}
