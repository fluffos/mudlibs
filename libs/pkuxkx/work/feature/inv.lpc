nosave int inventory_count = 0;
nomask int query_inventory_count() { return inventory_count;}
nomask void add_inventory_count(int count) 
{ 
	inventory_count += count;
	if(environment()) environment()->add_inventory_count(count);
}