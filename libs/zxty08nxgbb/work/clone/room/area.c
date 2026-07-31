inherit ITEM;
inherit F_SAVE;

void create(string name)
{
if( name) set("area",name);
if(!restore())
{
set_name("无效城市", ({ "city" }));
set("no_use",1);
}else {
set_name("城市"+name, ({ "city" }));
set("no_use",0);
        
        }
        setup();
}
string query_save_file()
{
return "/p/residence/"+query("area"); 
}

