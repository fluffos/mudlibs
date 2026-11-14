
#define T_TYPE_X 0
#define T_TYPE_Q 1
#define T_TYPE_L 2
#define T_TYPE_D 3
#define T_TYPE_I 4
#define T_TYPE_S 5

#define Q_TILES ({T_TYPE_D, T_TYPE_Q, T_TYPE_D, T_TYPE_Q, T_TYPE_L, T_TYPE_L, T_TYPE_Q, T_TYPE_I, T_TYPE_D, T_TYPE_S, T_TYPE_L, T_TYPE_D, T_TYPE_Q})
#define Q_INDICES ({ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096 })

#define MAX_TILE_TYPES 5

#define TILES ({ ({ ({"...", "...", "...", "..."}), ({"...", "...", "...", "..."}), ({"...", "...", "...", "..."}), ({"...", "...", "...", "..."}) }), \
                 ({ ({"##", "##"}), ({"##", "##"}), ({"##", "##"}), ({"##", "##"}) }), \
                 ({ ({"###", "#  "}), ({"# ", "# ", "##"}), ({"  #", "###"}), ({"##", " #", " #"}) }), \
                 ({ ({"###", "  #"}), ({"##", "# ", "# "}), ({"#  ", "###"}), ({" #", " #", "##"}) }), \
                 ({ ({"####"}),  ({"#", "#", "#", "#"}),  ({"####"}),  ({"#", "#", "#", "#"}) }), \
                 ({ ({" ##", "## "}),  ({"# ", "##", " #"}),  ({" ##", "## "}),  ({"# ", "##", " #"}) }) })

#define C_STD 1
#define C_STREET 2
#define C_BUILDING 4
#define C_MEADOW 8
#define C_PARK 16
