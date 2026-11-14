inherit "std/room";

mapping PLACES = ([]);
mapping HARBOURS;
mapping PLACE_COORD= ([]);
object *FERRYS = ({});
string START;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  add_property("no_clean_up");
} /* reset */

add_place(file,name,X,Y) {
  PLACES[file]=name;
  PLACE_COORD[file]=({X,Y});
} /* add_place */

add_ferry(file) {
  FERRYS+=({file});
} /* add_ferry */

set_start(file) {
  START=file;
} /* set_start */

lcase(str) {
  if(!str) return "";
  return lower_case(str);
} /* lcase */

start_ferrys() {
  int i;
  HARBOURS=mkmapping(map_array(m_values(PLACES),"lcase",this_object()),m_indices(PLACES));
  i=0;
  for(i=0; i<sizeof(FERRYS); i++) {
    FERRYS[i]->set_up(this_object(),START);
  }
} /* start_ferrys */

read_sign() {
  string *whereto;
  int i;
  write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  write("sail <place>  - Sail to any of the following places:\n");
  whereto=m_values(PLACES);
  i=0;
  while(i<sizeof(whereto)) {
    write("  "+whereto[i]+"\n");
    i++;
  }
  write("arrival - Ask how long the journey will last.\n");
  write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  return 1;
} /* read_sign */


info(str) {
  if (find_player("anna") )
    tell_object(find_player("anna"),str);
  return;
}

query_info() { /* for debugging only */
  return PLACE_COORD;
}

query_ferry() {
  return FERRYS;
}

call_ferry(where_to) {
  int i;
  object *available;
  i=0;
  while(i<sizeof(FERRYS)) {
    if (FERRYS[i]->where_is()==where_to) {
      if (FERRYS[i]->query_sailing()) {
        write("A "+FERRYS[i]->query_boat_type()+" is on its way already.\n");
	return 1;
      }
      write("There is already a "+FERRYS[i]->query_boat_type()+" here.\n");
      return 1;
    }
    i++;
  }
  i=0;
  available=({});
  while(i<sizeof(FERRYS)) {
    if (!FERRYS[i]->query_sailing()) {
      available+=({FERRYS[i]});
    }
    i++;
  }
  i=sizeof(available);
  if (!i) {
    write("You failed to signal any boat.\n");
    return 1;
  }
  i=random(i);
  FERRYS[i]->sail(where_to);
  write("A "+FERRYS[i]->query_boat_type()+" is signaled and will arrive soon.\n");
  return 1;
} /* call_ferry */


time_to_sail(from,to) {
  int *coord1, *coord2;
  int x_diff, y_diff, dist_quad;
  coord1=PLACE_COORD[from];
  coord2=PLACE_COORD[to];
  if (!coord1 || !coord2) return 0;
  x_diff=coord1[0]-coord2[0];
  y_diff=coord1[1]-coord2[1];
  dist_quad=x_diff*x_diff+y_diff*y_diff;
  switch(dist_quad) {
    case 0..16: return 4;
    case 17..36: return 6;
    case 37..64: return 8;
    case 65..100: return 10;
    case 101..144: return 12;
    case 145..196: return 14;
    case 197..256: return 16;
    case 257..324: return 18;
    case 325..400: return 20;
    case 401..576: return 24;
    case 577..784: return 28;
    case 785..1156: return 34;
    case 1157..1600: return 40;
    case 1601..2500: return 50;
    default : return 60;
  }
} /* time_to_sail */

place_name(str) {
  return PLACES[str];
} /* place_name */

is_harbour(str) {
  if(!str) return 0;
  return HARBOURS[lower_case(str)];
} /* is_harbour */


