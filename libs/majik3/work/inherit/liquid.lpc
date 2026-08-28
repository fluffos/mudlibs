inherit ITEM;

int liters = 0;
int poison_flag = 0;
string liquid_type = "water";
int no_empty = 0;

is_liquid() { return 1; }

create ()
{
  ::create();

  set_liquid ("water");
}

set_liquid (string str)
{
  liquid_type = str;
}

int
set_liters (int n) {
  return THOB->add_liters (n);
}
int
query_liters () {
  return liters;
}

int
add_liters (int n) {
int max_liters;

  if (n < 0 && no_empty)
    n = 0;

  max_liters = (THOB->query_dimensions()[0] *
                THOB->query_dimensions()[1] *
                THOB->query_dimensions()[2]) *
                THOB->query_hollow()/100;

  max_liters *= 0.01;

  if (n > max_liters)
    n = max_liters;

  if (!liters)
    liters = n;
  else
    liters += n;

  if (liters < 0)
    liters = 0;

  return liters;
}

int
set_no_empty (int i) {
  return no_empty = i;
}

int
query_no_empty () {
  return no_empty;
}

int
set_poison (int i) {
  return poison_flag = i;
}

int
query_poison () {
  return poison_flag;
}


int
query_max_liters () {
  int max_liters;
    
  max_liters = (THOB->query_dimensions()[0]*
                THOB->query_dimensions()[1]*
                THOB->query_dimensions()[2]) *
                THOB->query_hollow()/100;
  
  max_liters *= 0.01;
  
  return max_liters;
}

string query_liquid_type () {
  return liquid_type;
}

string query_liquid() { return liquid_type; }

short () {
string str = "";

  switch (to_int ((100.0*liters/THOB->query_max_liters())))
    {
      case 0:
        str += " (empty)";
        break;
      case 1..15:
        str += " (almost empty)";
        break;
      case 16..40:
        str += " (quarter full)";
        break;
      case 41..65:
        str += " (half full)";
        break;
      case 66..85:
        str += " (three-quarters full)";
        break;
      case 86..99:
        str += " (almost full)";
        break;
      case 100:
        str += " (full)";
        break;
    }

  return "" + ::short() + str;
}

long () {
  string str = "";

  switch (to_int ((100.0*liters/THOB->query_max_liters())))
    {
      case 0:
        str += "There is no liquid in it.\n";
        break;
      case 1..15:
        str += "There is not much "+liquid_type+" in it.\n";
        break;
      case 16..40:
        str += "It is about one quarter full of "+liquid_type+".\n";
        break;
      case 41..65:
        str += "It is half full of "+liquid_type+".\n";
        break;
      case 66..85:
        str += "It is three-quarters full of "+liquid_type+".\n";
        break;
      case 86..99:
        str += "It is almost full of "+liquid_type+".\n";
        break;
      case 100:
        str += "It is completely full of "+liquid_type+".\n";
        break;
    }

  return "" + ::long() + str;
}
