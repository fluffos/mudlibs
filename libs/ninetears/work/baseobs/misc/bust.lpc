// 100% Tyrael made
inherit "/std/object";

string who;

void setup() {
  set_name("estatua sagrada");
  set_short("estatua");
  add_alias("estatua");
  set_weight(100000);
  reset_get();
//  set_max_weight(100000);
}

void subject(string theplayer, int gender)
{
	set_short("La estatua de "+capitalize(theplayer));
	set_long("Esta estatua es el honor que los dioses hacen a sus "
	"elegidos. Es de marmol puro, y de formas "+ ((gender == 1) ?
	"masculinas" : "femeninas") + ".\n");
	who = theplayer;
}

string query_who()
{
	return who;
}
