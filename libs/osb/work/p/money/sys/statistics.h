/*
** Finance-Statistics
** Header-File
** Author: Thragor@Nightfall, 23oct96
** Update: Thragor@Nightfall, 30oct96
*/

#ifndef _F_STAT_H_

#define _F_STAT_H_

#define S_NUMBER_TESTS 0
#define S_RESULTS 1
#define S_SIZE 2

#define AV_NUMBER 0
#define AV_PRICE 1
#define AV_MAX 2
#define AV_MAX_FILE 3
#define AV_MIN 4
#define AV_MIN_FILE 5
#define AV_SIZE 6

#define AV_EMPTY (m_allocate(0,AV_SIZE))

#define EMPTY (m_allocate(0,S_SIZE))

#define LOG_FILE "/log/finance/STATISTICS"
#define REPORT_FILE "/log/finance/statistics"

// Kinds

#define K_ARMOUR "armour"
#define K_WEAPON "weapon"

// ARMOUR

#define COST_PER_AC "CostPerAC"
#define MAX_COST_PER_AC "MaxCostPerAC"
#define MAX_COST_PER_AC_FILE "MaxCostPerACFile"
#define MIN_COST_PER_AC "MinCostPerAC"
#define MIN_COST_PER_AC_FILE "MinCostPerACFile"
#define AC_AVARAGE_PRICE "ACAvaragePrice"

// WEAPON

#define COST_PER_WC "CostPerWC"
#define MAX_COST_PER_WC "MaxCostPerWC"
#define MAX_COST_PER_WC_FILE "MaxCostPerWCFile"
#define MIN_COST_PER_WC "MinCostPerWC"
#define MIN_COST_PER_WC_FILE "MinCostPerWCFile"
#define WC_AVARAGE_PRICE "WCAvaragePrice"

#endif
