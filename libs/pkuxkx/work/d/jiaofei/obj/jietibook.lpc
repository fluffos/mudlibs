inherit ITEM;

void create()
{
	set_name("天魔秘籍", ({ "tianmo miji","shu","miji"}) );
	set("long","一本残破的古书，上面描绘的古怪的图案。\r\n");	
	set_weight(1000);	
	set("unit","本");
   	set("no_sell",1);	
	setup();
}

void init()
{
    add_action("do_read","read");
    add_action("do_read","du");
}

int do_read(string arg)
{
    if(arg == "tianmo miji" || arg == "shu" || arg == "miji")
    {
        tell_object(this_player(),"你翻看天魔秘籍，立刻有所顿悟！\n");
        this_player()->improve_skill("tianmo-jieti",random(this_player()->query("int")) + 1);
        tell_object(this_player(),"天魔秘籍已经残破不堪，经你翻动，立刻化成了片片粉尘。\n");
        
        tell_object(this_player(),"set tianmo-jieti <任何内容>，在死亡时会自动发动天魔解体大法。unset tianmo-jieti则关闭。\n");
        destruct(this_object());
        return 1;
    }
    return 0;
}