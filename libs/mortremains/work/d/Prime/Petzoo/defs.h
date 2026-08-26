#define BASE_TOWN "/d/Prime/Petzoo/"
#define ROOMS(x) BASE_TOWN + "rooms/" + "x"
#define MON(x) BASE_TOWN + "mon/" + "x"
#define OBJ(x) BASE_TOWN + "obj/" + "x"
#define WEAPONS(x) BASE_TOWN + "weapons/" + "x"
#define ARM(x) BASE_TOWN + "armor/" + "x"

void fill_room(int p);
string get_animal();

void fill_room(int p) {
  int i, j; 
  if (p) j = 2;
  else j = 1;
  for(i=0;i<j;i++) 
    clone_object(BASE_TOWN+"mon/"+(string)get_animal())->move(this_object());
}

string get_animal() {
  int i;
  string str;
  i = random(18) + 1 ;
  switch(i) {
    case 1: str = "kitten"; break ;
    case 2: str = "puppy"; break;
    case 3: str = "cow" ; break;
    case 4: str = "dog" ; break;
    case 5: str = "cat" ; break;
    case 6: str = "duck" ; break;
    case 7: str = "pig" ; break;
    case 8: str = "chicken" ; break;
    case 9: str = "pony" ; break ;
    case 10: str = "lamb"; break ;
    case 11: str = "goose"; break ;
    case 12: str = "mouse"; break;
    case 13: str = "gerbil" ; break ;
   case 14: str = "camel1" ; break ;
    case 15: str = "camel2" ; break ;
    default: str = "child"; break;
  } 
  return str;
}
