#define ROOM_SMELL_NUM 1
#define ROOM_FEEL_NUM  2
#define ROOM_SOUND_NUM 3
#define ROOM_TASTE_NUM 4

string *odors_msg, *feels_msg, *sounds_msg, *tastes_msg;

string locate_sense(string item, string *arr)
{
  int arrLocation;

  if(!arr || sizeof(arr) < 2 || 
     (arrLocation = member_array(item, arr)) == -1)
    return 0;

  return arr[arrLocation + 1];
}

string * query_odors() { return odors_msg; }
string * query_feels() { return feels_msg; }
string * query_sounds() { return sounds_msg; }
string * query_tastes() { return tastes_msg; }

string query_smell(string item)
{
  return locate_sense(item, odors_msg);
}

string query_feel(string item)
{
  return locate_sense(item, feels_msg);
}

string query_sound(string item)
{
  return locate_sense(item, sounds_msg);
}

string query_taste(string item)
{
  return locate_sense(item, tastes_msg);
}

private status add_sense(mixed item, string msg, int senseType)
{
  int    arrLocation;
  int da, df;
  string *arr, *tmp;
  switch(senseType)
  {
    case ROOM_SMELL_NUM:
      arr = odors_msg;
      break;
    case ROOM_FEEL_NUM:
      arr = feels_msg;
      break;
    case ROOM_SOUND_NUM:
      arr = sounds_msg;
      break;
    case ROOM_TASTE_NUM:
      arr = tastes_msg;
      break;
  }
  if(pointerp(item)) tmp = item;
  else tmp = ({ item });
  if(!arr)
    arr = ({ });
  df = sizeof(tmp);
  msg = strip_prepending_spaces(msg, 0, 1);
  for(da = 0; da < df; da ++)
  {
    if((arrLocation=member_array(tmp[da],arr)) > -1)
      arr[arrLocation+1] = msg;
  else
    arr += ({ tmp[da], msg });
  }
  switch(senseType)
  {
    case ROOM_SMELL_NUM:
      odors_msg = arr;
      break;
    case ROOM_FEEL_NUM:
      feels_msg = arr;
      break;
    case ROOM_SOUND_NUM:
      sounds_msg = arr;
      break;
    case ROOM_TASTE_NUM:
      tastes_msg = arr;
      break;
  }
  return 1;
}

status add_smell(string item, string msg)
{
  return add_sense(item, msg, ROOM_SMELL_NUM);
}

status add_feel(string item, string msg)
{
  return add_sense(item, msg, ROOM_FEEL_NUM);
}

status add_touch(string item, string msg)
{
  return add_feel(item, msg);
}


status add_sound(string item, string msg)
{
  return add_sense(item, msg, ROOM_SOUND_NUM);
}

status add_taste(string item, string msg)
{
  return add_sense(item, msg, ROOM_TASTE_NUM);
}

status add_listen(string item, string msg)
{
  return add_sound(item, msg);
}


private status delete_sense(string item, int senseType)
{
  int    arrLocation;
  string *tmp;
  switch(senseType)
  {
    case ROOM_SMELL_NUM:
      tmp = odors_msg;
      break;
    case ROOM_FEEL_NUM:
      tmp = feels_msg;
      break;
    case ROOM_SOUND_NUM:
      tmp = sounds_msg;
      break;
    case ROOM_TASTE_NUM:
      tmp = tastes_msg;
      break;
  }
  if(!tmp || sizeof(tmp) < 2 || 
    (arrLocation = member_array(item, tmp)) == -1)
    return 0;
  else
    tmp -= ({ tmp[arrLocation], tmp[arrLocation+1] });
  switch(senseType)
  {
    case ROOM_SMELL_NUM:
      odors_msg = tmp;
      break;
    case ROOM_FEEL_NUM:
      feels_msg = tmp;
      break;
    case ROOM_SOUND_NUM:
      sounds_msg = tmp;
      break;
    case ROOM_TASTE_NUM:
      tastes_msg = tmp;
      break;
  }
  return 1;
}

status delete_smell(string item)
{
  return delete_sense(item, ROOM_SMELL_NUM);
}

status delete_feel(string item)
{
  return delete_sense(item, ROOM_FEEL_NUM);
}

status delete_sound(string item)
{
  return delete_sense(item, ROOM_SOUND_NUM);
}

status delete_taste(string item)
{
  return delete_sense(item, ROOM_TASTE_NUM);
}
