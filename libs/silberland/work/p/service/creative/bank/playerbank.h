//
// spielerbank.h
// defines for return values
/*
 * $Id$
 *
 * $Log$
 *
 */

#define BANK_SUCCESS 1
#define BANK_FAILURE 0
#define BANK_NO_ACCOUNT -1
#define BANK_LIMIT_REACHED -2
#define BANK_NO_CREDIT -3
#define BANK_ALREADY_ACCOUNT -4
#define BANK_ACCOUNT_NOT_EMPTY -5

#define BANK_AMOUNT "amount"
#define BANK_TYPE "type"
#define BANK_STATUS "status"
#define BANK_ACCESS "access"

#define BANK_ACCOUNT ([ BANK_AMOUNT :0, \
                   BANK_TYPE   :0, \
                   BANK_STATUS :0, \
                   BANK_ACCESS :0 \
                ])

#define BANK_SAVE_FILE "save_file"
#define BANK_FEE "bank_fee"
#define BANK_RATE_OF_INTEREST "bank_rate_of_interest"
#define BANK_CREDIT_RATE "bank_credit_rate"
#define BANK_CREDIT_LIMIT "bank_credit_limit"
#define BANK_MAX_AMOUNT "bank_max_amount"
#define BANK_MAX_CASH "bank_max_cash"
#define BANK_MIN_CASH "bank_min_cash"
#define BANK_ALLOWED_OBS "bank_allowed_obs"

