monster_died(ob){
object a, b;

  if(!present("dead_a", this_player())){
    a = clone_object("obj/treasure");
    a ->set_id("dead_a");
    a ->set_value(0);
    a ->set_weight(0);
    transfer(a, this_player());
	}
  else if(!present("dead_b", this_player())){
	b=clone_object("obj/treasure");
	b->set_id("dead_b");
	b->set_value(0);
	b->set_weight(0);
   	   transfer(b, this_player());
	}
}
