inherit NPC;

void create_animal(mapping animal_info)
{
    set_name(animal_info["name"], ({ animal_info["id"] }));
    set("long", "这是一只" + animal_info["name"] + "。\n");
    set("combat_exp", 10000);
    set("race", "野兽");
    set("need_time", animal_info["time"]);
    set("is_animal", 1);
    set("meat", animal_info["meat"]);
    set("meat_name", animal_info["meat_name"]);
    
    setup();
}

void receive_damage(string type, int n)
{
	return;
}

void receive_wound(string type, int n)
{
	return;
}