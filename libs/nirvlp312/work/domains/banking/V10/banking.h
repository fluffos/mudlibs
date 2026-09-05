/*
 * General macros for Banking are stored here.
 * This file should be stored in /sys/banking.h or be included by this.
 */

#ifndef _banking_h_
#define _banking_h_

#include <kernel.h>

/* This returns an array with the real_names of all members of Banking. */
#define BANKING_MEMBERS SECURITY->query_domain_members("banking")

/* This returns an array with the real_names of all lords of Banking. */
#define BANKING_LORDS SECUIRTY->query_domain_lords("banking")

/* This is the basic path to the banking files. */
#define BANKING "domains/banking/V10/"

#define BANKING_LOGFILE "/"BANKING"log"
#define BANKING_LOG(x) unguarded(1,#'write_file,({ BANKING_LOGFILE, \
                                                   ctime()+": "+x+"\n" }))

/* These are the standard objects */
#define BANKINGWORKROOM BANKING"workroom"
#define BANKINGCASTLE BANKING"castle"
#define BANKINGDAEMON BANKING"daemon"

/* These are for shops & co. */
#define VALUESERVER BANKING"valueserver"
#define VALUESERVER_SAVEFILE "/"BANKING"save/valueserver"
#define SHOPINTERFACE BANKING"shopinterface"
#define SHOPINTERFACE_H "/"BANKING"shopinterface.h"

/* This is for wares which want to have an explicit valueserver key */
#define P_VALUESERVER_KEY "valueserver_key"

/* These are for banks & co. */
#define BANKSERVER_BANKING"bankserver"
#define BANKSERVER_SAVEFILE "/"BANKING"save/bankserver"
#define BANKING_ACCOUNT_FILE(x) ("/"BANKING"save/accounts/"+(x)[0..0]+"/"+(x))
#define BANKINTERFACE BANKING"bankinterface"

/* These are for statistic & co. */
#define BANKINGSTATISTIC BANKING"statisticserver"
#define BANKINGSTATISTIC_SAVEFILE "/"BANKING"save/statisticserver"
#define BANKINGSTATISTIC_ARCHIVE BANKING"statistic_archive"
#define BANKINGSTATISTIC_ARCHIVE_SAVEFILE "/"BANKING"save/statistic_archive"

/* These are for manufactories & co. */
#define MANUFACTORY BANKING"manufactory"
#define MANUFACTORY_MACROS "/"BANKING"manufactory.h"

/* These are for the bandits */
#define ROBBERPATH BANKING"robbers/"
#define ROBCONTROL ROBBERPATH"robcontrol"
#define ROBBER_LURKER ROBBERPATH"lurker"
#define ROBBER_BUSH ROBBERPATH"bush"
#define ROBBER_BUSHROOM ROBBERPATH"bushroom"
#define ROBBER_SECRET ROBBERPATH"secret"
#define ROBBER_LEADER ROBBERPATH"leader"
#define ROBBER_BANDIT ROBBERPATH"bandit"
#define ROBBER_LETTER ROBBERPATH"letter"
#define ROBCONTROL_SAVEFILE "/"BANKING"save/robcontrol"

/* These are for string limits and so on */
#include "/"BANKING"limits.h"

/* These are for the bank interface */
#include "/"BANKING"possibilities.h"

#define INFLATION 1.03          /* 5% lowering of the price, each sold item */
#define TRADING_DECAY 0.10      /* 10% per week */
#define TRANSACTION_DECAY 0.50  /* 50% per week */

#endif
