mapping Profile_Data;
int Current_Exec_ID;
mixed Last_Exec_Data;

void finish_prof(string fname, string profpoint, int cost, int *tdelta) {
  Last_Exec_Data = ({ fname, profpoint, cost, tdelta });
}

void init_prof() { Last_Exec_Data = 0; }

mixed query_last_exec_data() { return Last_Exec_Data; }

string tdelta_to_string(int *tdelta) {
  int size;
  string temp;

  if(!sizeof(tdelta) == 2) return 0;
  if(tdelta[1] > 999999) {
    tdelta[0] += tdelta[1] / 1000000;
    tdelta[1] %= 1000000;
  }
  return sprintf("%d.%06d",tdelta[0],tdelta[1]);
}
