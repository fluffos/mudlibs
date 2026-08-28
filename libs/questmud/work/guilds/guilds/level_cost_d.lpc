/* maxlevel -> 300,  9.2001 //Celtron */
/* mod by C 16.6.2004 */

#define BASE_LEVEL_COST 1000

int query_next_cost(int level) {
  int exp_cost, *cost;
  cost = allocate(42);
  cost[0] = 4;
  cost[1] = 100;
  cost[2] = 600;
  cost[3] = 2000;
  cost[4] = 5000;
  cost[5] = 10000;  
  cost[6] = 20000;
  cost[7] = 35000;
  cost[8] = 50000;
  cost[9] = 60000;
  cost[10] = 70000; /* level 100, 70M */
  cost[11] = 80000;
  cost[12] = 90000;
  cost[13] = 100000;
  cost[14] = 120000;
  cost[15] = 150000;
  cost[16] = 200000;
  cost[17] = 250000;
  cost[18] = 300000;
  cost[19] = 310000;
  cost[20] = 320000; /* level 200, 320M */
  cost[21] = 400000;
  cost[22] = 450000;
  cost[23] = 500000;
  cost[24] = 550000;
  cost[25] = 600000;
  cost[26] = 620000;
  cost[27] = 640000;
  cost[28] = 660000;
  cost[29] = 680000;
  cost[30] = 700000; /* level 300, 700M */
  cost[31] = 720000;
  cost[32] = 740000;
  cost[33] = 760000;
  cost[34] = 780000;
  cost[35] = 800000;
  cost[36] = 820000;
  cost[37] = 840000;
  cost[38] = 860000;
  cost[39] = 900000;
  cost[40] = 1000000; /* level 400, 1G */
  cost[41] = 1000000;

  if (level > 400) {
//    tell_object(this_player(), "You are at the maximum level. (adding guild level)\n");
// this is the max cost
    return 1000000000;
  }
  exp_cost = cost[level/10] + (cost[level/10+1] - cost[level/10]) * (level - (level/10*10)) /10;
  exp_cost = exp_cost * BASE_LEVEL_COST;
  
  //Bonus for 2nd rebirth --Rag
  //if(this_player()->query_rebirth() > 1) exp_cost = exp_cost*4/5;
  //Bonus away --Rag & C 4.5.2004
  return exp_cost;
} 

