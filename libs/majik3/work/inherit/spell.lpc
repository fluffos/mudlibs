int level = 1;
int casting_time = 1;
int *components = ({ 0, 0 });
int offensive = 0;
string *materials;

int
query_offensive ()
{
  return offensive;
}

int
query_casting_time ()
{
  return casting_time;
}

int
query_level ()
{
  return level;
}

int *
query_components ()
{
  return components;
}

string *
query_materials ()
{
  return materials;
}

int
set_offensive (int i)
{
  return offensive = i;
}

int *
set_components (int i, int j, mixed s)
{
  components = ({ i, j });

  if (arrayp(s))
    materials = s;    

  if (stringp(s))
    materials = ({ s });

  return components;
}

int
set_level (int i)
{
  return level = i;
}
 
int
set_casting_time (int i)
{
  return casting_time = i;
}

create ()
{
  THOB->create_spell();
}
