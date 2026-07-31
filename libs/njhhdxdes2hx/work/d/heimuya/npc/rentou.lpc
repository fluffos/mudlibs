inherit ITEM;

int decayed;

void create()
{
        set_name("无名人头", ({ "rentou" }) );
        set("long", "这是一具无名人头\n");
        set("unit", "具" );
	set("value",0);
	set("weight",1000);
}

//string short() { return query("id") + "人头"; }

string query_autoload()
{
        return query("name");
}

void autoload(string arg)
{
 set("name",arg);
}

