// COMBINED_ITEM (for inherit)
// /inherit/item/conbined.c
// change by bibi
// change for 修改由于set_amount中使用了call_out而带来的bug
// change on 4,12 1998

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

nosave int amount;

void setup()
{
}

int query_amount() { return amount; }

void destruct_me() { destruct(this_object()); }

void set_amount(int v)
{
	if( v < 0 ) error("combine:set_amount less than 1.\n");
	if( v==0 ) destruct_me();
	else {
		amount = v;
		this_object()->set_weight(v * (int)query("base_weight"));
	}
}

void add_amount(int v) { set_amount(amount+v); }

string short()
{
  if ( query("base_unit") )
	  return chinese_number(query_amount()) + query("base_unit")
		  + ::short();
  else
    return chinese_number(query_amount()) + query("unit")
		  + ::short();
}

varargs int move1(mixed dest, int silent)
{
	object env, *inv;
	int i, total;
	string file;

	if( ::move(dest, silent) ) {
		if( living(env = environment()) ) {
			file = base_name(this_object());
			inv = all_inventory(env);
			total = (int)query_amount();
			for(i=0; i<sizeof(inv); i++) {
				if( inv[i]==this_object() ) continue;
				if( base_name(inv[i])==file ) {
					total += (int)inv[i]->query_amount();
					destruct(inv[i]);
				}
			}
			set_amount(total);
		}
		return 1;
	}
}
varargs int move(mixed dest, int silent)
{
	object env, *inv;
	int i, total, total0, result;
	string file;

	result= ::move(dest, silent);
	if(env = environment()) {
		file = base_name(this_object());
		inv = all_inventory(env);
		total = (int)query_amount();
		total0=total;
		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]==this_object() ) continue;
			if( base_name(inv[i])==file ) {
				total += (int)inv[i]->query_amount();
				destruct(inv[i]);
			}
		}
		if(total!=total0)
		  set_amount(total);
	}
	return result;
}

