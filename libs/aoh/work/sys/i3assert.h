//
// Wunderland Mudlib
//
// sys/daemon/i3assert.h  --  Paket type assertions
//
// $Log: i3assert.h,v $
// Revision 1.3  2003/06/12 08:54:27  Fiona
// changed ASSERT_USER_REPLY to fit ucache-update
//
// Revision 1.2  2002/08/06 09:54:39  Fiona
// auth-mud-req changed for lima libs
//

#ifndef __I_3_ASSERT__
#define __I_3_ASSERT__

#include <driver/lpctypes.h>

#define ASSERT_FINGER_REQ ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        0                  }), \
  ({ "F_USER",        T_STRING           }) })

#define ASSERT_FINGER_REPLY ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING           }), \
  ({ "F_VISNAME",     T_STRING, 0        }), \
  ({ "F_TITLE",       T_STRING, 0        }), \
  ({ "F_REALNAME",    T_STRING, 0        }), \
  ({ "F_EMAIL",       T_STRING, 0        }), \
  ({ "F_LOGOUT",      T_STRING, 0        }), \
  ({ "F_IDLE",        T_NUMBER           }), \
  ({ "F_IP_NAME",     T_STRING, 0        }), \
  ({ "F_LEVEL",       T_STRING, 0        }), \
  ({ "F_EXTRA",       T_STRING, 0        }) })

#define ASSERT_LOCATE_REQ ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         0                  }), \
  ({ "D_USER",        0                  }), \
  ({ "L_REQ_USER",    T_STRING           }) })

#define ASSERT_LOCATE_REPLY ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING           }), \
  ({ "L_MUDNAME",     T_STRING           }), \
  ({ "L_VISNAME",     T_STRING           }), \
  ({ "L_IDLE",        T_NUMBER           }), \
  ({ "L_STATUS",      T_STRING, 0        }) })

#define ASSERT_AUTH ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0,        T_STRING }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        0                  }) })
// Lima seems to include O_USER although it is not allowed

#define ASSERT_AUTH_REP ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        0                  }), \
  ({ "A_KEY",         T_NUMBER           }) })

#define ASSERT_TELL ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING           }), \
  ({ "T_O_VISNAME",   T_STRING           }), \
  ({ "T_MESS",        T_STRING           }) })

#define ASSERT_EMOTETO ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING           }), \
  ({ "E_O_VISNAME",   T_STRING           }), \
  ({ "E_MESS",        T_STRING           }) })

#define ASSERT_ERROR ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING, 0        }), \
  ({ "ERR_TYPE",      T_STRING           }), \
  ({ "ERR_DESCR",     T_STRING           }), \
  ({ "ERR_DATA",      T_POINTER, 0       }) })
// array ERR_DATA itself checked later

#define ASSERT_CHANLIST ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING, 0        }), \
  ({ "D_USER",        0                  }), \
  ({ "CLST_ID",       T_NUMBER           }), \
  ({ "CLST_LST",      T_MAPPING          }) })
// no checking of list CLST_LST itself is done
// router bug: D_MUD is NULL if packet is not reply to startup-req

#define ASSERT_CHAN_MSG ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         0                  }), \
  ({ "D_USER",        0                  }), \
  ({ "C_CHANNEL",     T_STRING           }), \
  ({ "C_VISNAME",     T_STRING           }), \
  ({ "C_MESSAGE",     T_STRING           }) })

#define ASSERT_CHAN_EMOTE ASSERT_CHAN_MSG

#define ASSERT_CHAN_TEMOTE ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         0                  }), \
  ({ "D_USER",        0                  }), \
  ({ "C_CHANNEL",     T_STRING           }), \
  ({ "CT_T_MUD",      T_STRING           }), \
  ({ "CT_T_USER",     T_STRING           }), \
  ({ "CT_MESS",       T_STRING           }), \
  ({ "CT_MESS_T",     T_STRING           }), \
  ({ "CT_O_VISNAME",  T_STRING           }), \
  ({ "CT_T_VISNAME",  T_STRING           }) })

#define ASSERT_WHO_REPLY ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING           }), \
  ({ "CHANNEL",       T_STRING           }), \
  ({ "CWHO",          T_POINTER          }) })
// array CWHO itself checked later

#define ASSERT_WHO_REQ ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        0                  }), \
  ({ "CHANNEL",       T_STRING           }) })

#define ASSERT_WHOLIST_QUERY ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        T_STRING           }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        0                  }) })

#define ASSERT_WHOLIST ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0 }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        T_STRING           }), \
  ({ "W_DATA",        T_POINTER           }) })

#define ASSERT_WHOLIST_CONTENT ({ \
  ({ "W_VISNAME",     T_STRING           }), \
  ({ "W_IDLE",        T_NUMBER, T_STRING }), \
  ({ "W_EXTRA",       T_STRING           }) })
// String is not really allowed in W_IDLE ...

#define ASSERT_USER_REQ ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING           }), \
  ({ "D_USER",        0                  }), \
  ({ "CU_REQ_USER",   T_STRING           }) })

#define ASSERT_USER_REPLY ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING, 0        }), \
  ({ "D_USER",        0                  }), \
  ({ "CU_REQ_USER",   T_STRING           }), \
  ({ "CU_VISNAME",    T_STRING           }), \
  ({ "CU_GENDER",     T_NUMBER           }) })
// D_MUD is 0 at ucache-update

#define ASSERT_MUDLIST ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "HOPS",          T_NUMBER           }), \
  ({ "O_MUD",         T_STRING           }), \
  ({ "O_USER",        0                  }), \
  ({ "D_MUD",         T_STRING, 0        }), \
  ({ "D_USER",        0                  }), \
  ({ "ML_MUDLIST_ID", T_NUMBER           }), \
  ({ "ML_INFO",       T_MAPPING          }) })

#define ASSERT_MUDLIST_ENTRY ({ \
  ({ "MLI_DOWNTIME",  T_NUMBER           }), \
  ({ "MLI_IP_ADDR",   T_STRING           }), \
  ({ "MLI_PORT_PL",   T_NUMBER           }), \
  ({ "MLI_PORT_TCP",  T_NUMBER           }), \
  ({ "MLI_PORT_UDP",  T_NUMBER           }), \
  ({ "MLI_MUDLIB",    T_STRING           }), \
  ({ "MLI_BASELIB",   T_STRING           }), \
  ({ "MLI_DRIVER",    T_STRING           }), \
  ({ "MLI_MUD_TYPE",  T_STRING           }), \
  ({ "MLI_STATE",     T_STRING           }), \
  ({ "MLI_EMAIL",     T_STRING           }), \
  ({ "MLI_SERVICES",  T_MAPPING          }), \
  ({ "MLI_OTHER",     T_MAPPING, 0       }) })

#define ASSERT_MAIL ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "MAIL_ID",       T_NUMBER           }), \
  ({ "MAIL_O_USER",   T_STRING           }), \
  ({ "MAIL_TO",       T_MAPPING          }), \
  ({ "MAIL_CC",       T_MAPPING          }), \
  ({ "MAIL_BCC",      T_POINTER          }), \
  ({ "MAIL_TIME",     T_NUMBER           }), \
  ({ "MAIL_SUBJECT",  T_STRING           }), \
  ({ "MAIL_CONTENT",  T_STRING           }), })

#define ASSERT_MAIL_ACK ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "MAIL_ACK",      T_MAPPING          }) })

#define ASSERT_OOB_BEGIN ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "OOB_O_MUD",     T_STRING           }), \
  ({ "OOB_TYPE",      T_NUMBER           }), \
  ({ "OOB_KEY",       T_NUMBER           }) })

#define ASSERT_OOB_END ({ \
  ({ "SERVICE",       T_STRING           }), \
  ({ "OOB_O_MUD",     T_STRING           }) })

#endif
