inherit NPC;

void heart_beat()
{
int i;  
object env,*inv,me = this_player();
env = environment();
inv = all_inventory(env);
for(i=0;i<sizeof(inv);i++)
        {
        if ( inv[i]->is_character() 
           || inv[i]->query("money_id") 
           || inv[i]->query_save_file() 
           || inv[i]->query("board_id") )
                continue;
        say(name()+"拣起一"+inv[i]->query("unit")+inv[i]->name()+"。\n");
        destruct(inv[i]);
        }
::heart_beat(); 
return;
}

void create()
{
string name;
mapping names = NAME_D->random_name("male");
name = names["name"];
name = sprintf("%s",name[0..0]);
set("long",name+"姓小厮，跟着褒国公鞍前马后的侍侯着。\n");
name = name+"小乙";
set_name(name,({"xiao yi"}));
set("age",10+random(20));
setup();
}       
