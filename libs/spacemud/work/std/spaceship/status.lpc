/* Do not remove the headers from this file! see /USAGE for more info. */

// Ship status


#define MAX_FUEL 0
#define CUR_FUEL 1
#define MAX_WARP_FUEL 2
#define CUR_WARP_FUEL 3
#define MAX_ARMOUR 4
#define CUR_ARMOUR 5

private int *status = ({0,0,0,0,0,0});

int query_max_fuel()
{
   return status[MAX_FUEL];
}

void set_max_fuel(int f)
{
   status[MAX_FUEL] = f;
}

int query_current_fuel()
{
   return status[CUR_FUEL];
}

int query_max_warp_fuel()
{
   return status[MAX_WARP_FUEL];
}

void set_max_warp_fuel(int wf)
{
   status[MAX_WARP_FUEL] = wf;
}

int query_current_warp_fuel()
{
   return status[CUR_WARP_FUEL];
}

int query_max_armour()
{
   return status[MAX_ARMOUR];
}

void set_max_armour(int a)
{
   status[MAX_ARMOUR] = a;
}

int query_current_armour()
{
   return status[CUR_ARMOUR];
}
