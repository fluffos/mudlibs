#define DEALER            CASINO + "npcs/odell"

#define MAX_PLAYERS       5
#define MIN_PLAYERS       1

#define DEALER_HITS_ON    16

#define BJ_PAYOFF         1.5
#define CARD_STAND_5      2
#define CARD_STAND_6      4
#define CARD_STAND_7      8
#define CARD_STAND_8      16
#define CARD_STAND_9      32
#define CARD_STAND_10     64
#define CARD_STAND_11     128

#define X_CARD_STAND      ({ CARD_STAND_5, CARD_STAND_6, CARD_STAND_7, \
                             CARD_STAND_8, CARD_STAND_9, CARD_STAND_10, \
                             CARD_STAND_11 })
#define STAND(xxx)        X_CARD_STAND[xxx - 5]

#define ANTE              0
#define DEAL              1
#define PLAY              2
